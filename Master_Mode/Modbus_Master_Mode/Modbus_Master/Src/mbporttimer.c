/*
 * MODBUS Library: ARM STM32 Port (FWLIB 2.0x)
 * Copyright (c) Christian Walter <cwalter@embedded-solutions.at>
 * All rights reserved.
 *
 * ARM STM32 Port by Niels Andersen, Elcanic A/S <niels.andersen.elcanic@gmail.com>
 *
 * $Id: mbporttimer.c,v 1.2 2009-01-01 23:37:55 cwalter Exp $
 */
#include "main.h"
#if (Modbus_Mode==MODBUS_MASTER)
/* ----------------------- System includes ----------------------------------*/
#include <H1DR1_Master.h>
#include <stdlib.h>

/* ----------------------- Platform includes --------------------------------*/
#include "mbport.h"
#include "mbtypes.h"
#include "mbportlayer.h"
#include "mbframe.h"
#include "mbutils.h"
#include "timers.h"

/* ----------------------- Defines ------------------------------------------*/
#define MBP_DEBUG_TIMER_PERFORMANCE     ( 0 )

#define MAX_TIMER_HDLS                  ( 5 )
#define IDX_INVALID                     ( 255 )
#define EV_NONE                         ( 0 )

#define TIMER_TIMEOUT_INVALID           ( 65535U )

#define RESET_HDL( x ) do { \
    ( x )->ubIdx = IDX_INVALID; \
	( x )->usNTimeOutMS = 0; \
	( x )->usNTimeLeft = TIMER_TIMEOUT_INVALID; \
    ( x )->xMBMHdl = MB_HDL_INVALID; \
    ( x )->pbMBPTimerExpiredFN = NULL; \
} while( 0 );

/* ----------------------- Type definitions ---------------------------------*/
typedef struct
{
    UBYTE           ubIdx;
    USHORT          usNTimeOutMS;
    USHORT          usNTimeLeft;
    xMBHandle       xMBMHdl;
    pbMBPTimerExpiredCB pbMBPTimerExpiredFN;
} xTimerInternalHandle;

/* ----------------------- Static variables ---------------------------------*/
STATIC xTimerInternalHandle arxTimerHdls[MAX_TIMER_HDLS];
STATIC BOOL     bIsInitalized = FALSE;

/* ----------------------- Static functions ---------------------------------*/
//void            prvvMBPTimerISR( void );
//extern void MX_TIM16_Init(void);
//extern TIM_HandleTypeDef htim16;
TimerHandle_t xTimer = NULL;
static void HandleTimer(TimerHandle_t xTimer);

/* ----------------------- Start implementation -----------------------------*/

eMBErrorCode
eMBPTimerInit( xMBPTimerHandle * xTimerHdl, USHORT usTimeOut1ms,
               pbMBPTimerExpiredCB pbMBPTimerExpiredFN, xMBHandle xHdl )
{
    eMBErrorCode    eStatus = MB_EPORTERR;
    UBYTE           ubIdx;


    MBP_ENTER_CRITICAL_SECTION(  );
    if( ( NULL != xTimerHdl ) && ( NULL != pbMBPTimerExpiredFN ) && ( MB_HDL_INVALID != xHdl ) )
    {
        if( !bIsInitalized )
        {
            /* Initialize a hardware timer for 1 millisecond. */
						//MX_TIM16_Init();
						xTimer = xTimerCreate( "MB1msTimer", pdMS_TO_TICKS(1), pdTRUE, ( void * ) TIMERID_MB_TIMER, HandleTimer );

            for( ubIdx = 0; ubIdx < MB_UTILS_NARRSIZE( arxTimerHdls ); ubIdx++ )
            {
                RESET_HDL( &arxTimerHdls[ubIdx] );
            }

            bIsInitalized = TRUE;

        }
        for( ubIdx = 0; ubIdx < MB_UTILS_NARRSIZE( arxTimerHdls ); ubIdx++ )
        {
            if( IDX_INVALID == arxTimerHdls[ubIdx].ubIdx )
            {
                break;
            }
        }
        if( MAX_TIMER_HDLS != ubIdx )
        {
            arxTimerHdls[ubIdx].ubIdx = ubIdx;
            arxTimerHdls[ubIdx].usNTimeOutMS = usTimeOut1ms;
            arxTimerHdls[ubIdx].usNTimeLeft = TIMER_TIMEOUT_INVALID;
            arxTimerHdls[ubIdx].xMBMHdl = xHdl;
            arxTimerHdls[ubIdx].pbMBPTimerExpiredFN = pbMBPTimerExpiredFN;

            *xTimerHdl = &arxTimerHdls[ubIdx];

            eStatus = MB_ENOERR;
        }
        else
        {
            eStatus = MB_ENORES;
        }
    }
    else
    {
        eStatus = MB_EINVAL;
    }
    MBP_EXIT_CRITICAL_SECTION(  );
    return eStatus;
}

void
vMBPTimerClose( xMBPTimerHandle xTimerHdl )
{
    xTimerInternalHandle *pxTimerIntHdl = xTimerHdl;

    if( MB_IS_VALID_HDL( pxTimerIntHdl, arxTimerHdls ) )
    {
        RESET_HDL( pxTimerIntHdl );
    }
}

eMBErrorCode
eMBPTimerSetTimeout( xMBPTimerHandle xTimerHdl, USHORT usTimeOut1ms )
{
    eMBErrorCode    eStatus = MB_EINVAL;
    xTimerInternalHandle *pxTimerIntHdl = xTimerHdl;

    MBP_ENTER_CRITICAL_SECTION(  );
    if( MB_IS_VALID_HDL( pxTimerIntHdl, arxTimerHdls ) &&
        ( usTimeOut1ms > 0 ) && ( usTimeOut1ms != TIMER_TIMEOUT_INVALID ) )
    {

        pxTimerIntHdl->usNTimeOutMS = usTimeOut1ms;
        eStatus = MB_ENOERR;
    }
    MBP_EXIT_CRITICAL_SECTION(  );
    return eStatus;
}

eMBErrorCode
eMBPTimerStart( xMBPTimerHandle xTimerHdl )
{
    eMBErrorCode    eStatus = MB_EINVAL;
    xTimerInternalHandle *pxTimerIntHdl = xTimerHdl;

    MBP_ENTER_CRITICAL_SECTION(  );
    if( MB_IS_VALID_HDL( pxTimerIntHdl, arxTimerHdls ) )
    {
				xTimerStart( xTimer, portMAX_DELAY );
        pxTimerIntHdl->usNTimeLeft = pxTimerIntHdl->usNTimeOutMS;
        eStatus = MB_ENOERR;
    }
    MBP_EXIT_CRITICAL_SECTION(  );
    return eStatus;
}

eMBErrorCode
eMBPTimerStop( xMBPTimerHandle xTimerHdl )
{
    eMBErrorCode    eStatus = MB_EINVAL;
    xTimerInternalHandle *pxTimerIntHdl = xTimerHdl;

    MBP_ENTER_CRITICAL_SECTION(  );
    if( MB_IS_VALID_HDL( pxTimerIntHdl, arxTimerHdls ) )
    {
				xTimerStop( xTimer, portMAX_DELAY );
        pxTimerIntHdl->usNTimeLeft = TIMER_TIMEOUT_INVALID;
        eStatus = MB_ENOERR;
    }
    MBP_EXIT_CRITICAL_SECTION(  );
    return eStatus;
}

/*timer callback function
*/
static void HandleTimer(TimerHandle_t xTimer)
{
		UBYTE           ubIdx;
	uint32_t Timer_ID = 0;

#if MBP_DEBUG_TIMER_PERFORMANCE == 1
    STATIC BOOL     bLastState = FALSE;
#endif
  /* Get Timer ID */
  Timer_ID = ( uint32_t ) pvTimerGetTimerID( xTimer );
  if (TIMERID_MB_TIMER == Timer_ID)
  {
#if MBP_DEBUG_TIMER_PERFORMANCE == 1
        vMBPSetDebugPin( MBP_DEBUGPIN_0, bLastState );
        bLastState = !bLastState;
#endif
        for( ubIdx = 0; ubIdx < MB_UTILS_NARRSIZE( arxTimerHdls ); ubIdx++ )
        {
            if( ( IDX_INVALID != arxTimerHdls[ubIdx].ubIdx ) &&
                ( TIMER_TIMEOUT_INVALID != arxTimerHdls[ubIdx].usNTimeLeft ) )
            {
                arxTimerHdls[ubIdx].usNTimeLeft--;
                if( 0 == arxTimerHdls[ubIdx].usNTimeLeft )
                {
                    arxTimerHdls[ubIdx].usNTimeLeft = TIMER_TIMEOUT_INVALID;
                    ( void )arxTimerHdls[ubIdx].pbMBPTimerExpiredFN( arxTimerHdls[ubIdx].xMBMHdl );
                }
            }
        }
  }
}

///*
// * Create an ISR which is called whenever the timer has expired. This function
// * handles all modbus slave timers.
// */
//void
//vMBPTimerISR( void )
//{
//    UBYTE           ubIdx;

//#if MBP_DEBUG_TIMER_PERFORMANCE == 1
//    STATIC BOOL     bLastState = FALSE;
//#endif

//#if MBP_DEBUG_TIMER_PERFORMANCE == 1
//        vMBPSetDebugPin( MBP_DEBUGPIN_0, bLastState );
//        bLastState = !bLastState;
//#endif
//        for( ubIdx = 0; ubIdx < MB_UTILS_NARRSIZE( arxTimerHdls ); ubIdx++ )
//        {
//            if( ( IDX_INVALID != arxTimerHdls[ubIdx].ubIdx ) &&
//                ( TIMER_TIMEOUT_INVALID != arxTimerHdls[ubIdx].usNTimeLeft ) )
//            {
//                arxTimerHdls[ubIdx].usNTimeLeft--;
//                if( 0 == arxTimerHdls[ubIdx].usNTimeLeft )
//                {
//                    arxTimerHdls[ubIdx].usNTimeLeft = TIMER_TIMEOUT_INVALID;
//                    ( void )arxTimerHdls[ubIdx].pbMBPTimerExpiredFN( arxTimerHdls[ubIdx].xMBMHdl );
//                }
//            }
//        }
//        /* Clear interrupt flag */
//				CLEAR_BIT((&htim16)->Instance->SR, TIM_IT_UPDATE);
//
//}
#endif
/************************ (C) MODIFIED BY HEXABITZ *****END OF FILE****/

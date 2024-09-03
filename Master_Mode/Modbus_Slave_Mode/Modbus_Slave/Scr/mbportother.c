/*
 * MODBUS Library: ARM STM32 Port (FWLIB 2.0x)
 * Copyright (c) Christian Walter <cwalter@embedded-solutions.at>
 * All rights reserved.
 *
 * ARM STM32 Port by Niels Andersen, Elcanic A/S <niels.andersen.elcanic@gmail.com>
 *
 * $Id: mbportother.c,v 1.1 2008-12-21 13:50:51 cwalter Exp $
 */

/* ----------------------- System includes ----------------------------------*/
#include "main.h"
#if (Modbus_Mode==MODBUS_SLAVE)

#include <stdlib.h>

/* ----------------------- Platform includes --------------------------------*/
#include "mbport.h"
#include "mbtypes_Slave.h"
#include "mbframe_Slave.h"
#include "mbutils_Slave.h"

/* ----------------------- Modbus includes ----------------------------------*/

/* ----------------------- Defines ------------------------------------------*/
#define PORT_INTERRUPT_PRIORITY_MAX     ( 1 )

/* ----------------------- Type definitions ---------------------------------*/

/* ----------------------- Static variables ---------------------------------*/

static UBYTE    ubNesting = 0;

/* ----------------------- Static functions ---------------------------------*/

/* ----------------------- Start implementation -----------------------------*/

void
assert_failed( uint8_t * file, uint32_t line )
{
    ( void )file;
    ( void )line;
    vMBPAssert(  );
}

void
vMBPAssert( void )
{
    volatile BOOL   bBreakOut = FALSE;

    vMBPEnterCritical(  );
    while( !bBreakOut );
}

void
vMBPEnterCritical( void )
{
	portENTER_CRITICAL(  );
	
}

void
vMBPExitCritical( void )
{
	portEXIT_CRITICAL(  );
 
}

BOOL
bMBPIsWithinException( void )
{
    BOOL bIsWithinException = FALSE;
    unsigned long   ulCPSR;
#if defined( __ICCARM__ ) && ( __ICCARM__ == 1 )
    ulCPSR = __get_CPSR(  );
#endif
    if( ( ulCPSR & ( 0x80 | 0x40 ) ) > 0 )
    {
        bIsWithinException = TRUE;
    }
    return bIsWithinException;
}

/************************ (C) MODIFIED BY HEXABITZ *****END OF FILE****/
#endif

/* 
 * MODBUS Slave Library: A portable MODBUS slave for MODBUS ASCII/RTU/TCP.
 * Copyright (c) 2008 Christian Walter <cwalter@embedded-solutions.at>
 * All rights reserved.
 *
 * $Id$
 */
#include "main.h"
#if (Modbus_Mode==MODBUS_SLAVE)
/* ----------------------- System includes ----------------------------------*/
#include <stdlib.h>
#include <string.h>

/* ----------------------- Platform includes --------------------------------*/
#include "mbport.h"

/* ----------------------- Modbus includes ----------------------------------*/
#include "mbs_Slave.h"
#include "mbutils_Slave.h"
#include "mbportlayer_Slave.h"
#include "mbsiframe_Slave.h"
#include "mbsi_Slave.h"
#include "mbsfunctions_Slave.h"
#if MBS_UDP_ENABLED == 1
#include "udp/mbsudp.h"
#endif
#if MBS_TCP_ENABLED == 1
#include "tcp/mbstcp.h"
#endif
#if MBS_RTU_ENABLED == 1
#include "mbsrtu_Slave.h"
#endif
#if MBS_ASCII_ENABLED == 1
#include "mbsascii_Slave.h"
#endif

/* ----------------------- Defines ------------------------------------------*/
#define IDX_INVALID                 ( 255 )

/*! \brief Calculate the required number of internal states required from
 *  the number of enabled serial and TCP instances.
 * \ingroup mbs_internal
 * \internal
 */
#define MBS_MAX_HANDLES     ( \
    ( ( ( ( BOOL )MBS_ASCII_ENABLED ) ? /*lint -e(506) */1 : 0 ) * MBS_SERIAL_ASCII_MAX_INSTANCES ) + \
    ( ( ( ( BOOL )MBS_RTU_ENABLED ) ? /*lint -e(506) */1 : 0 ) * MBS_SERIAL_RTU_MAX_INSTANCES ) + \
    ( ( ( ( BOOL )MBS_TCP_ENABLED ) ? /*lint -e(506) */1 : 0 ) * MBS_TCP_MAX_INSTANCES ) + \
    ( MBS_TEST_INSTANCES ) )

/* ----------------------- Type definitions ---------------------------------*/

/* ----------------------- Static functions ---------------------------------*/
STATIC void     vMBSResetHdl( xMBSInternalHandle * pxIntHdl );

/* ----------------------- Static variables ---------------------------------*/
STATIC BOOL     bIsInitalized = FALSE;
STATIC xMBSInternalHandle xMBSInternalHdl[MBS_MAX_HANDLES];

/* *INDENT-OFF* */
STATIC const struct
{
    const UBYTE     ubFunctionCode;
    const peMBSStandardFunctionCB peFunctionCB;
} arxMBSDefaultHandlers[] =
{
#if MBS_FUNC_READ_INPUT_REGISTERS_ENABLED != 0
    { MBS_FUNCCODE_READ_INPUT_REGISTERS, eMBSFuncReadInputRegister },
#endif
#if MBS_FUNC_READ_HOLDING_REGISTERS_ENABLED != 0
    { MBS_FUNCCODE_READ_HOLDING_REGISTERS, eMBSFuncReadHoldingRegister },
#endif
#if MBS_FUNC_WRITE_SINGLE_REGISTER_ENABLED != 0 
    { MBS_FUNCCODE_WRITE_SINGLE_REGISTER, eMBSFuncWriteSingleRegister },
#endif
#if MBS_FUNC_WRITE_MULTIPLE_REGISTERS_ENABLED != 0
    { MBS_FUNCCODE_WRITE_MULTIPLE_REGISTERS, eMBSFuncWriteMultipleHoldingRegister },
#endif
#if MBS_FUNC_READ_FILE_RECORD_ENABLED != 0
    { MBS_FUNCCODE_READ_FILE_RECORD, eMBSFuncReadFileRecord },
#endif
#if MBS_FUNC_WRITE_FILE_RECORD_ENABLED != 0
    { MBS_FUNCCODE_WRITE_FILE_RECORD, eMBSFuncWriteFileRecord },
#endif
#if MBS_FUNC_READWRITE_MULTIPLE_REGISTERS_ENABLED != 0
    { MBS_FUNCCODE_READWRITE_MULTIPLE_REGISTERS, eMBSFuncReadWriteMultipleHoldingRegister },
#endif
#if MBS_FUNC_MASK_WRITE_REGISTER_ENABLED != 0
    { MBS_FUNCCODE_MASKWRITE_REGISTERS, eMBSFuncMaskWriteRegister },
#endif
#if MBS_FUNC_READ_DISCRETE_ENABLED != 0
    { MBS_FUNC_READ_DISCRETE_INPUTS, eMBSFuncReadDiscreteInputs },
#endif
#if MBS_FUNC_READ_COILS_ENABLED != 0
    { MBS_FUNC_READ_COILS, eMBSFuncReadCoils },
#endif 
#if MBS_FUNC_WRITE_SINGLE_COIL_ENABLED != 0
    { MBS_FUNC_WRITE_SINGLE_COIL, eMBSFuncWriteSingleCoil }, 
#endif
#if MBS_FUNC_WRITE_MULTIPLE_COILS_ENABLED != 0 
    { MBS_FUNC_WRITE_MULTIPLE_COILS, eMBSFuncWriteMultipleCoils },
#endif
};

#if ( MBS_ENABLE_SER_DIAG == 1 ) || ( MBS_FUNC_REPORT_SLAVE_ID_ENABLED == 1 ) || ( MBS_FUNC_READ_EXCEPTION_STATUS_ENABLED == 1 )
STATIC const struct
{
    const UBYTE     ubFunctionCode;
    const peMBSStandardFunctionCB peFunctionCB;
} arxMBSSerOnlyDefaultHandlers[] =
{
#if MBS_FUNC_REPORT_SLAVE_ID_ENABLED != 0 
    { MBS_FUNC_REPORT_SLAVE_ID, eMBSFuncReportSlaveID },
#endif
#if MBS_FUNC_READ_EXCEPTION_STATUS_ENABLED != 0
    { MBS_FUNC_READ_EXCEPTION_STATUS, eMBSFuncReadExceptionStatus },
#endif
#if MBS_ENABLE_SER_DIAG != 0
    { MBS_FUNC_GET_COMM_EVENT_COUNTER, eMBSFuncGetCommEventCounter },
    { MBS_FUNC_GET_COMM_EVENT_LOG, eMBSFuncGetCommEventLog },
    { MBS_FUNC_READ_DEVICE_IDENTIFICATION, eMBSFuncReadDeviceIdentification },
    { MBS_FUNC_DIAGNOSTICS, eMBSFuncDiagnostics },
#endif
};
#endif
/* *INDENT-ON* */

/* ----------------------- Static functions ---------------------------------*/
#if MBS_TEST_INSTANCES == 0
STATIC xMBSInternalHandle *pxMBSGetNewHdl( void );
STATIC eMBErrorCode eMBSReleaseHdl( xMBSInternalHandle * pxIntHdl );
#endif

#if MBP_ADVA_STARTUP_SHUTDOWN_ENABLED == 1
STATIC UBYTE    ubMBSCountInstances( void );
#endif

/* ----------------------- Start implementation -----------------------------*/

BOOL
bMBSIsHdlValid( const xMBSInternalHandle * pxIntHdl )
{
    return MB_IS_VALID_HDL( pxIntHdl, xMBSInternalHdl ) ? TRUE : FALSE;
}

STATIC void
vMBSResetHdl( xMBSInternalHandle * pxIntHdl )
{
    UBYTE           ubIdx;

    pxIntHdl->eSlaveState = MBS_STATE_NONE;
    pxIntHdl->xFrameEventHdl = MBP_EVENTHDL_INVALID;
    pxIntHdl->xFrameHdl = MBS_FRAME_HANDLE_INVALID;
    pxIntHdl->ubSlaveAddress = MB_SER_SLAVE_ADDR_MIN;
    pxIntHdl->bIsSerialDevice = FALSE;
    pxIntHdl->ubIdx = IDX_INVALID;
    pxIntHdl->pubFrameMBPDUBuffer = NULL;
    pxIntHdl->usFrameMBPDULength = 0;
    pxIntHdl->pFrameSendFN = NULL;
    pxIntHdl->pFrameRecvFN = NULL;
    pxIntHdl->pFrameCloseFN = NULL;
    pxIntHdl->xMBSRegCB.peMBSRegInputCB = NULL;
    pxIntHdl->xMBSRegCB.peMBSRegHoldingCB = NULL;
    pxIntHdl->xMBSRegCB.peMBSDiscInputCB = NULL;
    pxIntHdl->xMBSRegCB.peMBSCoilsCB = NULL;
#if MBS_REGISTER_CB_NEEDS_INT_HANDLE
    pxIntHdl->xMBSRegCB.pxIntHdl = pxIntHdl;
#endif
#if MBS_ENABLE_SER_DIAG
    pxIntHdl->arubEventLogCurPos = 0;
    MBP_MEMSET( pxIntHdl->arubEventLog, 0, sizeof( pxIntHdl->arubEventLog ) );
#endif
#if MBS_FUNC_REPORT_SLAVE_ID_ENABLED == 1
    pxIntHdl->xMBSRegCB.peMBSSerDiagCB = NULL;
#endif
#if MBS_CALLBACK_ENABLE_CONTEXT == 1
    pxIntHdl->xMBSRegCB.pvCtx = NULL;
#endif
#if MBS_NCUSTOM_FUNCTION_HANDLERS > 0
    for( ubIdx = 0; ubIdx < MBS_NCUSTOM_FUNCTION_HANDLERS; ubIdx++ )
    {
        pxIntHdl->arxMBCustomHandlers[ubIdx].peMBSFunctionCB = NULL;
        pxIntHdl->arxMBCustomHandlers[ubIdx].ubFunctionCode = MBS_FUNCCODE_NONE;
    }
#else
    ( void )ubIdx;
#endif

#if MBS_ENABLE_STATISTICS_INTERFACE == 1
    MBP_MEMSET( &( pxIntHdl->xFrameStat ), 0, sizeof( pxIntHdl->xFrameStat ) );
#endif
#if MBS_ENABLE_PROT_ANALYZER_INTERFACE == 1
    pxIntHdl->pvMBAnalyzerCallbackFN = NULL;
#endif
#if ( MBS_TRACK_SLAVEADDRESS == 1 ) || ( MBS_ENABLE_GATEWAY_MODE == 1 )
    pxIntHdl->ubRequestAddress = MBS_ANY_ADDR;
#endif
#if MBS_ENABLE_GATEWAY_MODE == 1
    pxIntHdl->peGatewayCB = NULL;
    pxIntHdl->bGatewayMode = FALSE;
#endif
}

#if MBS_TEST_INSTANCES == 0
STATIC
#endif
    xMBSInternalHandle * pxMBSGetNewHdl( void )
{
    eMBErrorCode    eStatus = MB_ENORES, eStatus2;
    xMBSInternalHandle *pxIntHdl = NULL;
    UBYTE           ubIdx;

    MBP_ENTER_CRITICAL_SECTION(  );
    if( !bIsInitalized )
    {
        for( ubIdx = 0; ubIdx < ( UBYTE ) MB_UTILS_NARRSIZE( xMBSInternalHdl ); ubIdx++ )
        {
            vMBSResetHdl( &xMBSInternalHdl[ubIdx] );
        }
        bIsInitalized = TRUE;
    }
    for( ubIdx = 0; ubIdx < ( UBYTE ) MB_UTILS_NARRSIZE( xMBSInternalHdl ); ubIdx++ )
    {
        if( IDX_INVALID == xMBSInternalHdl[ubIdx].ubIdx )
        {
            pxIntHdl = &xMBSInternalHdl[ubIdx];
            pxIntHdl->ubIdx = ubIdx;
            if( MB_ENOERR != ( eStatus2 = eMBPEventCreate( &( pxIntHdl->xFrameEventHdl ) ) ) )
            {
                eStatus = eStatus2;
            }
            else
            {
                eStatus = MB_ENOERR;
            }
            break;
        }
    }
    if( MB_ENOERR != eStatus )
    {
        if( NULL != pxIntHdl )
        {
            eStatus2 = eMBSReleaseHdl( pxIntHdl );
            MBP_ASSERT( MB_ENOERR == eStatus2 );
        }
    }
    MBP_EXIT_CRITICAL_SECTION(  );
    return MB_ENOERR == eStatus ? pxIntHdl : NULL;
}

#if MBS_TEST_INSTANCES == 0
STATIC
#endif
    eMBErrorCode
eMBSReleaseHdl( xMBSInternalHandle * pxIntHdl )
{
    eMBErrorCode    eStatus = MB_EINVAL;

    MBP_ENTER_CRITICAL_SECTION(  );
    if( MB_IS_VALID_HDL( pxIntHdl, xMBSInternalHdl ) )
    {
        if( NULL != pxIntHdl->pFrameCloseFN )
        {
            if( MB_ENOERR != ( eStatus = pxIntHdl->pFrameCloseFN( pxIntHdl ) ) )
            {
                /* We must not free the event handle since we could
                 * not close the frame instance.
                 */
            }
            else
            {
                if( MBP_EVENTHDL_INVALID != pxIntHdl->xFrameEventHdl )
                {
                    vMBPEventDelete( pxIntHdl->xFrameEventHdl );
                }
                vMBSResetHdl( pxIntHdl );
                eStatus = MB_ENOERR;
            }
        }
        /* If no frame handle has been attached we can only do a
         * partial cleanup.
         */
        else
        {
            if( MBP_EVENTHDL_INVALID != pxIntHdl->xFrameEventHdl )
            {
                vMBPEventDelete( pxIntHdl->xFrameEventHdl );
            }
            vMBSResetHdl( pxIntHdl );
            eStatus = MB_ENOERR;
        }
    }
    MBP_EXIT_CRITICAL_SECTION(  );

    return eStatus;
}

eMBErrorCode
eMBSClose( xMBSHandle xHdl )
{
    eMBErrorCode    eStatus = MB_EINVAL;
    xMBSInternalHandle *pxIntHdl = xHdl;

#if MBP_ADVA_STARTUP_SHUTDOWN_ENABLED == 1
    MBP_ENTER_CRITICAL_INIT(  );
#endif
    if( MB_IS_VALID_HDL( pxIntHdl, xMBSInternalHdl ) )
    {
        MBP_ENTER_CRITICAL_SECTION(  );
        eStatus = eMBSReleaseHdl( pxIntHdl );
        MBP_EXIT_CRITICAL_SECTION(  );
    }
#if MBP_ADVA_STARTUP_SHUTDOWN_ENABLED == 1
    if( 0 == ubMBSCountInstances(  ) )
    {
        vMBPLibraryUnload(  );
    }
    MBP_EXIT_CRITICAL_INIT(  );
#endif
    return eStatus;
}

eMBErrorCode
eMBSRegisterInputCB( xMBSHandle xHdl, peMBSRegisterInputCB peRegInputCB )
{
    eMBErrorCode    eStatus = MB_EINVAL;
    xMBSInternalHandle *pxIntHdl = xHdl;

    if( MB_IS_VALID_HDL( pxIntHdl, xMBSInternalHdl ) )
    {
        pxIntHdl->xMBSRegCB.peMBSRegInputCB = peRegInputCB;
        eStatus = MB_ENOERR;
    }
    return eStatus;
}

eMBErrorCode
eMBSRegisterHoldingCB( xMBSHandle xHdl, peMBSRegisterHoldingCB peRegHoldingCB )
{
    eMBErrorCode    eStatus = MB_EINVAL;
    xMBSInternalHandle *pxIntHdl = xHdl;

    if( MB_IS_VALID_HDL( pxIntHdl, xMBSInternalHdl ) )
    {
        pxIntHdl->xMBSRegCB.peMBSRegHoldingCB = peRegHoldingCB;
        eStatus = MB_ENOERR;
    }
    return eStatus;
}

eMBErrorCode
eMBSRegisterFileRecordCB( xMBSHandle xHdl, peMBSFileRecordCB peFileRecordCB )
{
    eMBErrorCode    eStatus = MB_EINVAL;
    xMBSInternalHandle *pxIntHdl = xHdl;

    if( MB_IS_VALID_HDL( pxIntHdl, xMBSInternalHdl ) )
    {
        pxIntHdl->xMBSRegCB.peMBSFileRecordCB = peFileRecordCB;
        eStatus = MB_ENOERR;
    }
    return eStatus;
}

eMBErrorCode
eMBSRegisterDiscreteCB( xMBSHandle xHdl, peMBSDiscreteInputCB peMBSDiscInputCB )
{
    eMBErrorCode    eStatus = MB_EINVAL;
    xMBSInternalHandle *pxIntHdl = xHdl;

    if( MB_IS_VALID_HDL( pxIntHdl, xMBSInternalHdl ) )
    {
        pxIntHdl->xMBSRegCB.peMBSDiscInputCB = peMBSDiscInputCB;
        eStatus = MB_ENOERR;
    }
    return eStatus;
}

eMBErrorCode
eMBSRegisterCoilCB( xMBSHandle xHdl, peMBSCoilCB peMBSCoilsCB )
{
    eMBErrorCode    eStatus = MB_EINVAL;
    xMBSInternalHandle *pxIntHdl = xHdl;

    if( MB_IS_VALID_HDL( pxIntHdl, xMBSInternalHdl ) )
    {
        pxIntHdl->xMBSRegCB.peMBSCoilsCB = peMBSCoilsCB;
        eStatus = MB_ENOERR;
    }
    return eStatus;
}

eMBErrorCode
eMBSRegisterFunctionCB( xMBSHandle xHdl, UBYTE ubFuncIdx, peMBSCustomFunctionCB peFuncCB )
{
#if MBS_NCUSTOM_FUNCTION_HANDLERS > 0
    UBYTE           ubIdx;
#endif
    eMBErrorCode    eStatus = MB_EINVAL;
    xMBSInternalHandle *pxIntHdl = xHdl;

    if( MB_IS_VALID_HDL( pxIntHdl, xMBSInternalHdl ) )
    {
        /* remove can not fail. */
        eStatus = peFuncCB == NULL ? MB_ENOERR : MB_ENORES;
#if MBS_NCUSTOM_FUNCTION_HANDLERS > 0
        for( ubIdx = 0; ubIdx < MBS_NCUSTOM_FUNCTION_HANDLERS; ubIdx++ )
        {
            if( ( ubFuncIdx == pxIntHdl->arxMBCustomHandlers[ubIdx].ubFunctionCode ) ||
                ( MBS_FUNCCODE_NONE == pxIntHdl->arxMBCustomHandlers[ubIdx].ubFunctionCode ) )
            {
                if( NULL != peFuncCB )
                {
                    pxIntHdl->arxMBCustomHandlers[ubIdx].ubFunctionCode = ubFuncIdx;
                    pxIntHdl->arxMBCustomHandlers[ubIdx].peMBSFunctionCB = peFuncCB;
                }
                else
                {
                    pxIntHdl->arxMBCustomHandlers[ubIdx].ubFunctionCode = MBS_FUNCCODE_NONE;
                    pxIntHdl->arxMBCustomHandlers[ubIdx].peMBSFunctionCB = NULL;
                }
                eStatus = MB_ENOERR;
                break;
            }
        }
#endif
    }
    return eStatus;
}

eMBErrorCode
eMBSPoll( xMBSHandle xHdl )
{
    eMBErrorCode    eStatus = MB_ENOERR, eStatus2;
    eMBException    eEXResponse;
    xMBSInternalHandle *pxIntHdl = xHdl;
    xMBPEventType   eEvent;
    UBYTE           ubSlaveAddress;
    UBYTE           ubIdx;
    UBYTE           ubFunctionCode;
    BOOL            bIsBroadcast = FALSE;

    if( MB_IS_VALID_HDL( pxIntHdl, xMBSInternalHdl ) )
    {
#if MBS_POLL_SINGLE_CYCLE == 1
        do
        {
#endif
            switch ( pxIntHdl->eSlaveState )
            {
            case MBS_STATE_NONE:
                /* Note: Check if we still need the RTU startup code. */
                pxIntHdl->eSlaveState = MBS_STATE_WAITING;
                break;

            case MBS_STATE_WAITING:
                /* Wait for new MODBUS requests from a master. */
                if( bMBPEventGet( pxIntHdl->xFrameEventHdl, &eEvent ) )
                {
                    switch ( ( eMBSEvent ) eEvent )
                    {
                    case MBS_EV_RECEIVED:
                        MBP_ASSERT( NULL != pxIntHdl->pFrameRecvFN );
                        eStatus2 = pxIntHdl->pFrameRecvFN( pxIntHdl, &ubSlaveAddress, &( pxIntHdl->usFrameMBPDULength ) );
#if MBS_ENABLE_SER_DIAG
                        if( pxIntHdl->bIsSerialDevice )
                        {
                            /* Build event log entry. The event log entry is a bitwise combination
                             * of different events. Note that we have no method to tell here if
                             * there was an overrun condition because there is no portable way
                             * to get this information from the porting layer.
                             */
                            pxIntHdl->arubEventLog[pxIntHdl->arubEventLogCurPos] = MB_SER_RECEIVE_EVENT_BUILD( MB_SER_RECEIVE_EVENT_NONE );
                            if( MB_ENOERR == eStatus2 )
                            {
                                if( MB_SER_BROADCAST_ADDR == ubSlaveAddress )
                                {
                                    pxIntHdl->arubEventLog[pxIntHdl->arubEventLogCurPos] |= ( UBYTE ) MB_SER_RECEIVE_EVENT_BROADCAST_RECEIVED;
                                }
                            }
                            else
                            {
                                pxIntHdl->arubEventLog[pxIntHdl->arubEventLogCurPos] |= ( UBYTE ) MB_SER_RECEIVE_EVENT_COMMUNICATION_ERROR;
                            }
                            MB_UTILS_RINGBUFFER_INCREMENT( pxIntHdl->arubEventLogCurPos, pxIntHdl->arubEventLog );
                        }
#endif
                        switch ( eStatus2 )
                        {
                            /* We have received a frame and it has passed the CRC16
                             * check. Now decided if we want to handle the frame.
                             */
                        case MB_ENOERR:
#if ( MBS_TRACK_SLAVEADDRESS == 1 ) || ( MBS_ENABLE_GATEWAY_MODE == 1 )
                            pxIntHdl->ubRequestAddress = ubSlaveAddress;
#endif
                            /* MBS_ANY_ADDR (0xFF) is used in TCP mode for addressing 
                             * the slave. In serial mode we check if the frame is for 
                             * us.
                             */
                            if( ubSlaveAddress == pxIntHdl->ubSlaveAddress )
                            {
                                pxIntHdl->eSlaveState = MBS_STATE_EXECUTE;
                            }
#if MBS_ENABLE_GATEWAY_MODE == 1
                            /* In gateway mode (TCP) process all frames */
                            else if( pxIntHdl->bGatewayMode )
                            {
                                if( MB_SER_BROADCAST_ADDR == ubSlaveAddress )
                                {
                                    pxIntHdl->eSlaveState = MBS_STATE_GATEWAY_BROADCAST;
                                }
                                else
                                {
                                    pxIntHdl->eSlaveState = MBS_STATE_GATEWAY;
                                }
                            }
#endif
                            else if( MB_SER_BROADCAST_ADDR == ubSlaveAddress )
                            {
                                pxIntHdl->eSlaveState = MBS_STATE_EXECUTE_BROADCAST;
                            }
                            else
                            {
                                /* Do a dummy transmission to reenable the receiver. */
                                if( MB_ENOERR != pxIntHdl->pFrameSendFN( pxIntHdl, 0 ) )
                                {
                                    pxIntHdl->eSlaveState = MBS_STATE_ERROR;
                                }
                            }
                            break;

                            /* This frame was garbage. Do nothing. */
                        case MB_EIO:
                            /* Do a dummy transmission to reenable the receiver. */
                            if( MB_ENOERR != pxIntHdl->pFrameSendFN( pxIntHdl, 0 ) )
                            {
                                pxIntHdl->eSlaveState = MBS_STATE_ERROR;
                            }
                            /* Simply ignore this frame. No need to signal an error
                             * to the caller. 
                             */
                            break;

                        case MB_EPORTERR:
                        default:
                            /* Transistion to error state. */
                            pxIntHdl->eSlaveState = MBS_STATE_ERROR;
                            break;

                        }
                        break;

                        /* The porting layer has detected an error during runtime.
                         * For example a PPP link was shut down and the stack needs
                         * to be restarted.
                         */
                    case MBS_EV_ERROR:
                        pxIntHdl->eSlaveState = MBS_STATE_ERROR;
                        break;

                        /* Ignore all other events */
                    default:
                        eStatus = MB_ENOERR;
                        break;
                    }
                }
                break;

                /* Fallthrough to next case which takes care of handling the
                 * function.
                 */
            case MBS_STATE_EXECUTE_BROADCAST:
                bIsBroadcast = TRUE;
                /*lint -fallthrough */
            case MBS_STATE_EXECUTE:
#if MBS_ENABLE_STATISTICS_INTERFACE == 1
                pxIntHdl->xFrameStat.ulNPacketsReceivedSelf += ( ULONG ) 1;
#endif
                /* The default is that we assume that no such function is
                 * available.
                 */
                eEXResponse = MB_PDU_EX_ILLEGAL_FUNCTION;
                MBP_ASSERT( NULL != pxIntHdl->pubFrameMBPDUBuffer );
                ubFunctionCode = pxIntHdl->pubFrameMBPDUBuffer[MB_PDU_FUNC_OFF];
#if MBS_NCUSTOM_FUNCTION_HANDLERS > 0
                for( ubIdx = 0; ubIdx < MBS_NCUSTOM_FUNCTION_HANDLERS; ubIdx++ )
                {
                    if( ( MBS_FUNCCODE_NONE != pxIntHdl->arxMBCustomHandlers[ubIdx].ubFunctionCode ) &&
                        ( ubFunctionCode == pxIntHdl->arxMBCustomHandlers[ubIdx].ubFunctionCode ) )
                    {
                        MBP_ASSERT( NULL != pxIntHdl->arxMBCustomHandlers[ubIdx].peMBSFunctionCB );
#if MBS_CALLBACK_ENABLE_CONTEXT == 1
                        eEXResponse =
                            pxIntHdl->arxMBCustomHandlers[ubIdx].peMBSFunctionCB( pxIntHdl->xMBSRegCB.pvCtx,
                                                                                  pxIntHdl->pubFrameMBPDUBuffer, &( pxIntHdl->usFrameMBPDULength ) );

#else
                        eEXResponse = pxIntHdl->arxMBCustomHandlers[ubIdx].peMBSFunctionCB( pxIntHdl->pubFrameMBPDUBuffer, &( pxIntHdl->usFrameMBPDULength ) );
#endif
                        break;
                    }
                }
#endif
                /* Check if frame has not already been handled by the custom
                 * function handlers.
                 */
                if( MB_PDU_EX_ILLEGAL_FUNCTION == eEXResponse )
                {
                    for( ubIdx = 0; ubIdx < ( UBYTE ) MB_UTILS_NARRSIZE( arxMBSDefaultHandlers ); ubIdx++ )
                    {
                        if( ubFunctionCode == arxMBSDefaultHandlers[ubIdx].ubFunctionCode )
                        {
                            MBP_ASSERT( NULL != arxMBSDefaultHandlers[ubIdx].peFunctionCB );
                            eEXResponse =
                                arxMBSDefaultHandlers[ubIdx].peFunctionCB( pxIntHdl->pubFrameMBPDUBuffer,
                                                                           &( pxIntHdl->usFrameMBPDULength ), &( pxIntHdl->xMBSRegCB ) );
                            break;
                        }
                    }
#if ( MBS_ENABLE_SER_DIAG == 1 ) || ( MBS_FUNC_REPORT_SLAVE_ID_ENABLED == 1 )
                    if( pxIntHdl->bIsSerialDevice )
                    {
                        for( ubIdx = 0; ubIdx < ( UBYTE ) MB_UTILS_NARRSIZE( arxMBSSerOnlyDefaultHandlers ); ubIdx++ )
                        {
                            if( ubFunctionCode == arxMBSSerOnlyDefaultHandlers[ubIdx].ubFunctionCode )
                            {
                                MBP_ASSERT( NULL != arxMBSSerOnlyDefaultHandlers[ubIdx].peFunctionCB );
                                eEXResponse =
                                    arxMBSSerOnlyDefaultHandlers[ubIdx].peFunctionCB( pxIntHdl->pubFrameMBPDUBuffer,
                                                                                      &( pxIntHdl->usFrameMBPDULength ), &( pxIntHdl->xMBSRegCB ) );
                                break;
                            }
                        }
                    }
#endif
                }

#if ( MBS_TRACK_SLAVEADDRESS == 1 ) || ( MBS_ENABLE_GATEWAY_MODE == 1 )
                /* Reset current request address to invalid address for request. */
                pxIntHdl->ubRequestAddress = MBS_ANY_ADDR;
#endif

#if MBS_ENABLE_SER_DIAG == 1
                if( pxIntHdl->bIsSerialDevice )
                {
                    /* Do not increment for fetch event counter commands or exceptions */
                    if( !( ( ubFunctionCode == MBS_FUNC_GET_COMM_EVENT_COUNTER ) ||
                           ( ubFunctionCode == MBS_FUNC_GET_COMM_EVENT_LOG ) ) && ( MB_PDU_EX_NONE == eEXResponse ) )
                    {
                        pxIntHdl->xFrameStat.usEventCount++;
                    }
                    /* Prepare event log. Note that MODBUS standard is unclear if we
                     * want to log in case this is a broadcast message. We assume yes. 
                     */
                    pxIntHdl->arubEventLog[pxIntHdl->arubEventLogCurPos] = MB_SER_SEND_EVENT_BUILD( MB_SER_SEND_EVENT_NONE );
                    switch ( eEXResponse )
                    {
                    case MB_PDU_EX_ILLEGAL_FUNCTION:
                    case MB_PDU_EX_ILLEGAL_DATA_ADDRESS:
                    case MB_PDU_EX_ILLEGAL_DATA_VALUE:
                        pxIntHdl->arubEventLog[pxIntHdl->arubEventLogCurPos] |= ( UBYTE ) MB_SER_SEND_EVENT_READ_EXCEPTION;
                        break;
                    case MB_PDU_EX_SLAVE_DEVICE_FAILURE:
                        pxIntHdl->arubEventLog[pxIntHdl->arubEventLogCurPos] |= ( UBYTE ) MB_SER_SEND_EVENT_SLAVE_ABORT_EXCEPTION;
                        break;
                    case MB_PDU_EX_NOT_ACKNOWLEDGE:
                        pxIntHdl->arubEventLog[pxIntHdl->arubEventLogCurPos] |= ( UBYTE ) MB_SER_SEND_EVENT_NAK_EXCEPTION;
                        break;
                    case MB_PDU_EX_SLAVE_BUSY:
                        pxIntHdl->arubEventLog[pxIntHdl->arubEventLogCurPos] |= ( UBYTE ) MB_SER_SEND_EVENT_BUSY_EXCEPTION;
                        break;
                    default:
                        break;
                    }
                    MB_UTILS_RINGBUFFER_INCREMENT( pxIntHdl->arubEventLogCurPos, pxIntHdl->arubEventLog );
                }
#endif
                if( !bIsBroadcast )
                {
                    /* In case of an exception we must build an exception frame. */
                    if( MB_PDU_EX_NONE != eEXResponse )
                    {
                        pxIntHdl->usFrameMBPDULength = 0;
                        pxIntHdl->pubFrameMBPDUBuffer[pxIntHdl->usFrameMBPDULength] = ( UBYTE ) ( ubFunctionCode | 0x80 );
                        pxIntHdl->usFrameMBPDULength++;
                        pxIntHdl->pubFrameMBPDUBuffer[pxIntHdl->usFrameMBPDULength] = ( UBYTE ) eEXResponse;
                        pxIntHdl->usFrameMBPDULength++;
                    }
                    pxIntHdl->eSlaveState = MBS_STATE_SEND;
                }
                else
                {
                    /* Reenable receiver after broadcast. */
                    if( MB_ENOERR != pxIntHdl->pFrameSendFN( pxIntHdl, 0 ) )
                    {
                        pxIntHdl->eSlaveState = MBS_STATE_ERROR;
                    }
                    else
                    {
                        pxIntHdl->eSlaveState = MBS_STATE_WAITING;
                    }
                }
                break;

#if MBS_ENABLE_GATEWAY_MODE == 1
            case MBS_STATE_GATEWAY_BROADCAST:
                bIsBroadcast = TRUE;
                /*lint -fallthrough */
            case MBS_STATE_GATEWAY:
#if MBS_ENABLE_STATISTICS_INTERFACE == 1
                pxIntHdl->xFrameStat.ulNPacketsReceivedSelf += 1;
#endif
                ubFunctionCode = pxIntHdl->pubFrameMBPDUBuffer[MB_PDU_FUNC_OFF];

#if defined( MBS_ENABLE_DEBUG_FACILITY ) && ( MBS_ENABLE_DEBUG_FACILITY == 1 )
                if( bMBPPortLogIsEnabled( MB_LOG_DEBUG, MB_LOG_CORE ) )
                {
                    vMBPPortLog( MB_LOG_DEBUG, MB_LOG_CORE,
                                 "[IDX=" MBP_FORMAT_USHORT "] gateway invoked from MODBUS request for" " slave="
                                 MBP_FORMAT_USHORT " (function=" MBP_FORMAT_USHORT ", length=" MBP_FORMAT_USHORT ")",
                                 ( USHORT ) pxIntHdl->ubIdx, ( USHORT ) pxIntHdl->ubRequestAddress, ( USHORT ) ubFunctionCode, pxIntHdl->usFrameMBPDULength );
                }
#endif

                eEXResponse = MB_PDU_EX_GATEWAY_PATH_UNAVAILABLE;
                if( NULL != pxIntHdl->peGatewayCB )
                {
                    eEXResponse = pxIntHdl->peGatewayCB( pxIntHdl->ubRequestAddress, pxIntHdl->pubFrameMBPDUBuffer, &( pxIntHdl->usFrameMBPDULength ) );
                }

                if( !bIsBroadcast )
                {
                    /* In case of an exception we must build an exception frame. */
                    if( MB_PDU_EX_NONE != eEXResponse )
                    {
                        pxIntHdl->usFrameMBPDULength = 0;
                        pxIntHdl->pubFrameMBPDUBuffer[pxIntHdl->usFrameMBPDULength] = ( UBYTE ) ( ubFunctionCode | 0x80 );
                        pxIntHdl->usFrameMBPDULength++;
                        pxIntHdl->pubFrameMBPDUBuffer[pxIntHdl->usFrameMBPDULength] = ( UBYTE ) eEXResponse;
                        pxIntHdl->usFrameMBPDULength++;
                    }
                    pxIntHdl->eSlaveState = MBS_STATE_SEND;
                }
                else
                {
                    /* Reenable receiver after broadcast. */
                    if( MB_ENOERR != pxIntHdl->pFrameSendFN( pxIntHdl, 0 ) )
                    {
                        pxIntHdl->eSlaveState = MBS_STATE_ERROR;
                    }
                    else
                    {
                        pxIntHdl->eSlaveState = MBS_STATE_WAITING;
                    }
                }
                break;
#endif

            case MBS_STATE_SEND:
                MBP_ASSERT( NULL != pxIntHdl->pFrameSendFN );
#if MBS_ENABLE_STATISTICS_INTERFACE == 1
                if( MB_PDU_FUNC_ISEXCEPTION( pxIntHdl->pubFrameMBPDUBuffer[0] ) )
                {
                    pxIntHdl->xFrameStat.ulNExceptionCount += ( ULONG ) 1;
                    if( ( UBYTE ) MB_PDU_EX_NOT_ACKNOWLEDGE == pxIntHdl->pubFrameMBPDUBuffer[0] )
                    {
                        pxIntHdl->xFrameStat.ulNNACKExceptionCount += ( ULONG ) 1;
                    }
                    if( ( UBYTE ) MB_PDU_EX_SLAVE_BUSY == pxIntHdl->pubFrameMBPDUBuffer[0] )
                    {
                        pxIntHdl->xFrameStat.ulNBusyExceptionCount += ( ULONG ) 1;
                    }
                }
#endif
                eStatus2 = pxIntHdl->pFrameSendFN( pxIntHdl, pxIntHdl->usFrameMBPDULength );
                switch ( eStatus2 )
                {
                case MB_ENOERR:
                    pxIntHdl->eSlaveState = MBS_STATE_WAITING;
                    break;

                case MB_EIO:
                    pxIntHdl->eSlaveState = MBS_STATE_WAITING;
                    break;

                case MB_EPORTERR:
                default:
                    pxIntHdl->eSlaveState = MBS_STATE_ERROR;
                    break;
                }
                break;

                /* The stack is broken and needs to be restarted. */
            case MBS_STATE_ERROR:
                eStatus = MB_EILLSTATE;
                break;
            }
#if MBS_POLL_SINGLE_CYCLE == 1
        }
        while( ( pxIntHdl->eSlaveState != MBS_STATE_ERROR ) && ( pxIntHdl->eSlaveState != MBS_STATE_WAITING ) );
#endif
    }
    else
    {
        eStatus = MB_EINVAL;
    }
    return eStatus;
}



#if MBS_ASCII_ENABLED == 1 || MBS_RTU_ENABLED == 1

#if MBS_CALLBACK_ENABLE_CONTEXT == 1
eMBErrorCode
eMBSSerialInit( xMBSHandle * pxHdl, eMBSerialMode eMode, UBYTE ubSlaveAddress, UBYTE ubPort, ULONG ulBaudRate, eMBSerialParity eParity, void *pvCtx )
#else
eMBErrorCode
eMBSSerialInit( xMBSHandle * pxHdl, eMBSerialMode eMode, UBYTE ubSlaveAddress, UBYTE ubPort, ULONG ulBaudRate, eMBSerialParity eParity )
#endif
{
    eMBErrorCode    eStatus;
    UCHAR           ucStopBits;
    ucStopBits = MB_PAR_NONE == eParity ? ( UCHAR ) 2 : ( UCHAR ) 1;
#if MBS_CALLBACK_ENABLE_CONTEXT == 1
    eStatus = eMBSSerialInitExt( pxHdl, eMode, ubSlaveAddress, ubPort, ulBaudRate, eParity, ucStopBits, pvCtx );
#else
    eStatus = eMBSSerialInitExt( pxHdl, eMode, ubSlaveAddress, ubPort, ulBaudRate, eParity, ucStopBits );
#endif
    return eStatus;
}

#if MBS_CALLBACK_ENABLE_CONTEXT == 1
eMBErrorCode
eMBSSerialInitExt( xMBSHandle * pxHdl, eMBSerialMode eMode, UBYTE ubSlaveAddress,
                   UBYTE ubPort, ULONG ulBaudRate, eMBSerialParity eParity, UCHAR ucStopBits, void *pvCtx )
#else
eMBErrorCode
eMBSSerialInitExt( xMBSHandle * pxHdl, eMBSerialMode eMode, UBYTE ubSlaveAddress, UBYTE ubPort, ULONG ulBaudRate, eMBSerialParity eParity, UCHAR ucStopBits )
#endif
{
    xMBSInternalHandle *pxMBSNewIntHdl;
    eMBErrorCode    eStatus = MB_EINVAL, eStatus2;

#if MBP_ADVA_STARTUP_SHUTDOWN_ENABLED == 1
    MBP_ENTER_CRITICAL_INIT(  );
    if( 0 == ubMBSCountInstances(  ) )
    {
        vMBPLibraryLoad(  );
    }
#endif
    if( NULL != pxHdl )
    {
        if( NULL == ( pxMBSNewIntHdl = pxMBSGetNewHdl(  ) ) )
        {
            eStatus = MB_ENORES;
        }
#if MBS_IS_EVALUATION_BUILD == 1	
		else if( ulBaudRate != 38400 )
		{
			eStatus = MB_EINVAL;
		}
#endif			
        else
        {

            switch ( eMode )
            {
#if MBS_ASCII_ENABLED == 1
            case MB_ASCII:
                eStatus = eMBSSerialASCIIInit( pxMBSNewIntHdl, ubPort, ulBaudRate, eParity, ucStopBits );
                break;
#endif

#if MBS_RTU_ENABLED == 1
            case MB_RTU:
                eStatus = eMBSSerialRTUInit( pxMBSNewIntHdl, ubPort, ulBaudRate, eParity, ucStopBits );
                break;
#endif

            default:
                eStatus = MB_EINVAL;
                break;
            }			
        }

        if( eStatus != MB_ENOERR )
        {
            if( NULL != pxMBSNewIntHdl )
            {
                if( MB_ENOERR != ( eStatus2 = eMBSReleaseHdl( pxMBSNewIntHdl ) ) )
                {
                    eStatus = eStatus2;
                }
            }
            *pxHdl = NULL;
        }
        else
        {
            /*lint -e(613) */ pxMBSNewIntHdl->ubSlaveAddress = ubSlaveAddress;
            /*lint -e(613) */ pxMBSNewIntHdl->bIsSerialDevice = TRUE;
#if MBS_CALLBACK_ENABLE_CONTEXT == 1
            /*lint -e(613) */ pxMBSNewIntHdl->xMBSRegCB.pvCtx = pvCtx;
#endif
            *pxHdl = pxMBSNewIntHdl;
        }
    }

#if MBP_ADVA_STARTUP_SHUTDOWN_ENABLED == 1
    /* If the startup failed we have to cleanup. */
    if( 0 == ubMBSCountInstances(  ) )
    {
        vMBPLibraryUnload(  );
    }
    MBP_EXIT_CRITICAL_INIT(  );
#endif
    return eStatus;
}
#endif

#if MBP_ADVA_STARTUP_SHUTDOWN_ENABLED == 1
STATIC          UBYTE
ubMBSCountInstances( void )
{
    UBYTE           ubIdx;
    UBYTE           ubNInstances = 0;

    if( bIsInitalized )
    {
        for( ubIdx = 0; ubIdx < MB_UTILS_NARRSIZE( xMBSInternalHdl ); ubIdx++ )
        {
            if( IDX_INVALID != xMBSInternalHdl[ubIdx].ubIdx )
            {
                ubNInstances++;
            }
        }
    }
    return ubNInstances;
}
#endif

#if MBS_TCP_ENABLED == 1
#if MBS_CALLBACK_ENABLE_CONTEXT == 1
eMBErrorCode
eMBSTCPInit( xMBSHandle * pxHdl, CHAR * pcBindAddress, USHORT usTCPPort, void *pvCtx )
#else
eMBErrorCode
eMBSTCPInit( xMBSHandle * pxHdl, CHAR * pcBindAddress, USHORT usTCPPort )
#endif
{
    xMBSInternalHandle *pxMBSNewIntHdl;
    eMBErrorCode    eStatus = MB_EINVAL, eStatus2;

#if MBP_ADVA_STARTUP_SHUTDOWN_ENABLED == 1
    MBP_ENTER_CRITICAL_INIT(  );
    if( 0 == ubMBSCountInstances(  ) )
    {
        vMBPLibraryLoad(  );
    }
#endif

    if( NULL != pxHdl )
    {
        if( NULL == ( pxMBSNewIntHdl = pxMBSGetNewHdl(  ) ) )
        {
            eStatus = MB_ENORES;
        }
        else
        {
            eStatus = eMBSTCPIntInit( pxMBSNewIntHdl, pcBindAddress, usTCPPort );
        }
        if( eStatus != MB_ENOERR )
        {
            if( NULL != pxMBSNewIntHdl )
            {
                if( MB_ENOERR != ( eStatus2 = eMBSReleaseHdl( pxMBSNewIntHdl ) ) )
                {
                    eStatus = eStatus2;
                }
            }
            *pxHdl = NULL;
        }
        else
        {
            /*lint -e(613) */ pxMBSNewIntHdl->ubSlaveAddress = MBS_ANY_ADDR;
#if MBS_CALLBACK_ENABLE_CONTEXT == 1
            /*lint -e(613) */ pxMBSNewIntHdl->xMBSRegCB.pvCtx = pvCtx;
#endif
            *pxHdl = pxMBSNewIntHdl;
        }
    }

#if MBP_ADVA_STARTUP_SHUTDOWN_ENABLED == 1
    /* If the startup failed we have to cleanup. */
    if( 0 == ubMBSCountInstances(  ) )
    {
        vMBPLibraryUnload(  );
    }
    MBP_EXIT_CRITICAL_INIT(  );
#endif
    return eStatus;
}
#endif

#if MBS_UDP_ENABLED == 1
#if MBS_CALLBACK_ENABLE_CONTEXT == 1
eMBErrorCode
eMBSUDPInit( xMBSHandle * pxHdl, CHAR * pcBindAddress, USHORT usUDPPort, void *pvCtx )
#else
eMBErrorCode
eMBSUDPInit( xMBSHandle * pxHdl, CHAR * pcBindAddress, USHORT usUDPPort )
#endif
{
    xMBSInternalHandle *pxMBSNewIntHdl;
    eMBErrorCode    eStatus = MB_EINVAL, eStatus2;

#if MBP_ADVA_STARTUP_SHUTDOWN_ENABLED == 1
    MBP_ENTER_CRITICAL_INIT(  );
    if( 0 == ubMBSCountInstances(  ) )
    {
        vMBPLibraryLoad(  );
    }
#endif

    if( NULL != pxHdl )
    {
        if( NULL == ( pxMBSNewIntHdl = pxMBSGetNewHdl(  ) ) )
        {
            eStatus = MB_ENORES;
        }
        else
        {
            eStatus = eMBSUDPIntInit( pxMBSNewIntHdl, pcBindAddress, usUDPPort );
        }
        if( eStatus != MB_ENOERR )
        {
            if( NULL != pxMBSNewIntHdl )
            {
                if( MB_ENOERR != ( eStatus2 = eMBSReleaseHdl( pxMBSNewIntHdl ) ) )
                {
                    eStatus = eStatus2;
                }
            }
            *pxHdl = NULL;
        }
        else
        {
            pxMBSNewIntHdl->ubSlaveAddress = MBS_ANY_ADDR;
#if MBS_CALLBACK_ENABLE_CONTEXT == 1
            pxMBSNewIntHdl->xMBSRegCB.pvCtx = pvCtx;
#endif
            *pxHdl = pxMBSNewIntHdl;
        }
    }

#if MBP_ADVA_STARTUP_SHUTDOWN_ENABLED == 1
    /* If the startup failed we have to cleanup. */
    if( 0 == ubMBSCountInstances(  ) )
    {
        vMBPLibraryUnload(  );
    }
    MBP_EXIT_CRITICAL_INIT(  );
#endif
    return eStatus;
}
#endif

#if MBS_ENABLE_STATISTICS_INTERFACE == 1
eMBErrorCode
eMBSGetStatistics( xMBSHandle xHdl, xMBStat * pxMBSCurrentStat )
{
    eMBErrorCode    eStatus = MB_EINVAL;
    xMBSInternalHandle *pxIntHdl = xHdl;

    if( ( NULL != pxMBSCurrentStat ) && MB_IS_VALID_HDL( pxIntHdl, xMBSInternalHdl ) )
    {
        MBP_ENTER_CRITICAL_SECTION(  );
        memcpy( pxMBSCurrentStat, &( pxIntHdl->xFrameStat ), sizeof( pxIntHdl->xFrameStat ) );
        MBP_EXIT_CRITICAL_SECTION(  );
        eStatus = MB_ENOERR;
    }
    return eStatus;
}

eMBErrorCode
eMBSResetStatistics( xMBSHandle xHdl )
{
    eMBErrorCode    eStatus = MB_EINVAL;
    xMBSInternalHandle *pxIntHdl = xHdl;

    if( MB_IS_VALID_HDL( pxIntHdl, xMBSInternalHdl ) )
    {
        MBP_ENTER_CRITICAL_SECTION(  );
        MBP_MEMSET( &( pxIntHdl->xFrameStat ), 0, sizeof( pxIntHdl->xFrameStat ) );
        MBP_EXIT_CRITICAL_SECTION(  );
        eStatus = MB_ENOERR;
    }
    return eStatus;
}
#endif

#if MBS_ENABLE_PROT_ANALYZER_INTERFACE == 1
eMBErrorCode
eMBSRegisterProtAnalyzer( xMBSHandle xHdl, void *pvCtxArg, pvMBAnalyzerCallbackCB pvMBAnalyzerCallbackFN )
{
    eMBErrorCode    eStatus = MB_EINVAL;
    xMBSInternalHandle *pxIntHdl = xHdl;

    if( MB_IS_VALID_HDL( pxIntHdl, xMBSInternalHdl ) )
    {
        MBP_ENTER_CRITICAL_SECTION(  );
        pxIntHdl->pvMBAnalyzerCallbackFN = pvMBAnalyzerCallbackFN;
        pxIntHdl->pvCtx = pvCtxArg;
        MBP_EXIT_CRITICAL_SECTION(  );
        eStatus = MB_ENOERR;
    }
    return eStatus;
}
#endif

#if MBS_TRACK_SLAVEADDRESS == 1
eMBErrorCode
eMBSGetRequestSlaveAddress( xMBSHandle xHdl, UBYTE * pubAddress )
{
    eMBErrorCode    eStatus = MB_EINVAL;
    xMBSInternalHandle *pxIntHdl = xHdl;

    if( MB_IS_VALID_HDL( pxIntHdl, xMBSInternalHdl ) )
    {
        MBP_ENTER_CRITICAL_SECTION(  );
        *pubAddress = pxIntHdl->ubRequestAddress;
        eStatus = MB_ENOERR;
        MBP_EXIT_CRITICAL_SECTION(  );
    }
    return eStatus;
}
#endif
#endif
#if MBS_ENABLE_GATEWAY_MODE == 1
eMBErrorCode
eMBSTCPSetGatewayMode( xMBSHandle xHdl, BOOL bEnable )
{
    eMBErrorCode    eStatus = MB_EINVAL;
    xMBSInternalHandle *pxIntHdl = xHdl;

    if( MB_IS_VALID_HDL( pxIntHdl, xMBSInternalHdl ) )
    {
        MBP_ENTER_CRITICAL_SECTION(  );
        pxIntHdl->bGatewayMode = bEnable;
        eStatus = MB_ENOERR;
        MBP_EXIT_CRITICAL_SECTION(  );
    }
    return eStatus;
}

eMBErrorCode
eMBSRegisterGatewayCB( xMBSHandle xHdl, peMBSGatewayCB peGatewayCB )
{
    eMBErrorCode    eStatus = MB_EINVAL;
    xMBSInternalHandle *pxIntHdl = xHdl;

    if( MB_IS_VALID_HDL( pxIntHdl, xMBSInternalHdl ) )
    {
        MBP_ENTER_CRITICAL_SECTION(  );
        pxIntHdl->peGatewayCB = peGatewayCB;
        eStatus = MB_ENOERR;
        MBP_EXIT_CRITICAL_SECTION(  );
    }
    return eStatus;
}

#endif

#if ( MBS_FUNC_REPORT_SLAVE_ID_ENABLED == 1 ) || ( MBS_ENABLE_SER_DIAG == 1 )
eMBErrorCode
eMBSRegisterSerialDiagCB( xMBSHandle xHdl, peMBSSerialDiagCB peMBSSerDiagCB )
{
    eMBErrorCode    eStatus = MB_EINVAL;
    xMBSInternalHandle *pxIntHdl = xHdl;

    if( MB_IS_VALID_HDL( pxIntHdl, xMBSInternalHdl ) )
    {
        MBP_ENTER_CRITICAL_SECTION(  );
        pxIntHdl->xMBSRegCB.peMBSSerDiagCB = peMBSSerDiagCB;
        eStatus = MB_ENOERR;
        MBP_EXIT_CRITICAL_SECTION(  );
    }
    return eStatus;
}
#endif

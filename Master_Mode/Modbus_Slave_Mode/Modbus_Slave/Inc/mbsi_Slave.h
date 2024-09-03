/*
 * MODBUS Slave Library: A portable MODBUS slave for MODBUS ASCII/RTU/TCP.
 * Copyright (c) 2008-2011 Christian Walter <cwalter@embedded-solutions.at>
 * All rights reserved.
 *
 * $Id$
 */

#ifndef _MBSI_SLAVE_H
#define _MBSI_SLAVE_H
#include "main.h"
#if (Modbus_Mode==MODBUS_SLAVE)
#ifdef __cplusplus
PR_BEGIN_EXTERN_C
#endif
/*!
 * \if INTERNAL_DOCS
 * \addtogroup mbs_int
 * @{
 * \endif
 */

//#include "internal/mbsiframe.h"
//#include "mbport.h"
//#include "mbs.h"
/* ----------------------- Defines ------------------------------------------*/

#ifndef MBS_TEST_INSTANCES
#define MBS_TEST_INSTANCES          ( 0 )
#endif

/* ----------------------- Type definitions ---------------------------------*/

/*! \brief Internal states of a MODBUS slave stack.
 * \internal
 */
    typedef enum
{
    MBS_STATE_NONE,             /*!< Dummy state. */
    MBS_STATE_WAITING,          /*!< Waiting for an event. */
    MBS_STATE_EXECUTE,          /*!< Processing a frame. */
    MBS_STATE_EXECUTE_BROADCAST,        /*!< Processing a broadcast frame. */
#if MBS_ENABLE_GATEWAY_MODE == 1
    MBS_STATE_GATEWAY,          /*!< Gateway mode. */
    MBS_STATE_GATEWAY_BROADCAST,        /*!< Gateway mode. */
#endif
    MBS_STATE_SEND,             /*!< Send a frame. */
    MBS_STATE_ERROR             /*!< Stack is in error state. */
} eMBSSlaveState;

/*! \brief Holds a MODBUS function code together with a function handler
 *   provided by the user.
 */
typedef struct
{
/* *INDENT-OFF* */
    UBYTE           ubFunctionCode;     /*!< MODBUS function code. */
    /*!\brief Function handler. */
    peMBSCustomFunctionCB peMBSFunctionCB;
/* *INDENT-ON* */
} xMBCustomFunctionHandler;

/*! \brief Data type which holds pointer to function providing the actual
 *   register values for the stack.
 */
#if MBS_REGISTER_CB_NEEDS_INT_HANDLE == 1
struct xMBSInternalHandle_tag;
#endif
typedef struct
{
/* *INDENT-OFF* */
    /*! \brief For input registers. */
    peMBSRegisterInputCB peMBSRegInputCB;
    /*! \brief For holding registers. */
    peMBSRegisterHoldingCB peMBSRegHoldingCB;
    /*! \brief For holding registers. */
    peMBSFileRecordCB peMBSFileRecordCB;
    /*! \brief For discrete registers. */
    peMBSDiscreteInputCB peMBSDiscInputCB;
    /*! \brief For coil register. */
    peMBSCoilCB peMBSCoilsCB;
    /*! \brief For file records. */
    peMBSFileRecordCB peMBSFileCB;
#if ( MBS_FUNC_REPORT_SLAVE_ID_ENABLED == 1 ) || ( MBS_ENABLE_SER_DIAG == 1 )
    /*! \brief For serial diagnosis. */
    peMBSSerialDiagCB peMBSSerDiagCB;
#endif
#if MBS_CALLBACK_ENABLE_CONTEXT == 1
    void *pvCtx;
#endif
#if MBS_REGISTER_CB_NEEDS_INT_HANDLE == 1
    struct xMBSInternalHandle_tag *pxIntHdl;
#endif
/* *INDENT-ON* */
} xMBSRegisterCB;

/*! \brief Every MODBUS slave instance has a handle which contains pointer
 *  to functions and a buffer for assembling MODBUS frames.
 * \internal
 */
typedef struct xMBSInternalHandle_tag
{
/* *INDENT-OFF* */
    UBYTE           ubSlaveAddress;     /*!< Slave address of this MODBUS stack. */
    UBYTE           ubIdx;              /*!< Internal index. */
    USHORT          usFrameMBPDULength; /*!< The size of the frame. */
    eMBSSlaveState  eSlaveState;        /*!< Current state of the MODBUS stack. */
    BOOL            bIsSerialDevice;    /*!< TRUE if either ASCII or RTU. */
#if MBS_ASCII_BACKOF_TIME_MS > 0
    /*! \brief Backoff timer for MODBUS ASCII. */
    xMBPTimerHandle xBackoffTimerHdl;
#endif

    /*! \brief Receives MBS_EV_SENT, MBS_EV_TIMEOUT and MBS_EV_RECEIVED events. */
    xMBPEventHandle xFrameEventHdl;
    /*! \brief Private data for the ASCII/RTU or TCP implementations. */
    xMBSFrameHandle xFrameHdl;
    /*! \brief Buffer used to assemble MODBUS frames. */
    UBYTE *pubFrameMBPDUBuffer;
    /*! \brief Pointer for a function used to transmit MODBUS frames. */
    peMBSFrameSend pFrameSendFN;
    /*! \brief Pointer to a function used to receive MODBUS frames. */
    peMBSFrameReceive pFrameRecvFN;
    /*! \brief Pointer to a function used for shutdown. */
    peMBSFrameClose pFrameCloseFN;
    /*! \brief Register callbacks. */
    xMBSRegisterCB xMBSRegCB;
#if MBS_NCUSTOM_FUNCTION_HANDLERS > 0
    /*! \brief Custom function handlers. */
    xMBCustomFunctionHandler arxMBCustomHandlers[MBS_NCUSTOM_FUNCTION_HANDLERS];
#endif
#if MBS_ENABLE_STATISTICS_INTERFACE == 1
    xMBStat         xFrameStat;         /*!< Statistic information. */
#endif
#if MBS_ENABLE_PROT_ANALYZER_INTERFACE == 1
    pvMBAnalyzerCallbackCB pvMBAnalyzerCallbackFN;  /*!< Protocol analyzer. */
    void *pvCtx;
#endif
#if ( MBS_TRACK_SLAVEADDRESS == 1 ) || ( MBS_ENABLE_GATEWAY_MODE == 1 )
    UBYTE           ubRequestAddress;   /*!< Slave address for current request */    
#endif
#if MBS_ENABLE_GATEWAY_MODE == 1
    BOOL            bGatewayMode;       /*!< Gateway mode on/off */
    peMBSGatewayCB peGatewayCB;  /*!< Gateway callback function */
#endif    
#if MBS_ENABLE_SER_DIAG == 1
    UBYTE           arubEventLog[64];
    UBYTE           arubEventLogCurPos;
#endif
/* *INDENT-ON* */
} xMBSInternalHandle;

/*! \brief The events which are used by the main state machine.
 * \internal
 */
typedef enum
{
    MBS_EV_NONE,                /*!< Dummy event. */
    MBS_EV_RECEIVED,            /*!< Receiver event. */
    MBS_EV_ERROR,               /*!< Internal error (sender or receiver). */
    MBS_EV_TIMEOUT              /*!< Timeout expired. */
} eMBSEvent;

/* ----------------------- Function prototypes ------------------------------*/
#if MBS_TEST_INSTANCES != 0
xMBSInternalHandle *pxMBSGetNewHdl( void );
eMBErrorCode    eMBSReleaseHdl( xMBSInternalHandle * pxIntHdl );
#endif

/*! \brief Checks if a handle is valid.
 * \internal
 *
 * \param pxIntHdl A pointer to a handle.
 * \return \c TRUE if this is a valid handle which was allocated by the stack.
 */
BOOL            bMBSIsHdlValid( const xMBSInternalHandle * pxIntHdl );

/*!
 * \if INTERNAL_DOCS
 * @}
 * \endif
 */

#ifdef __cplusplus
PR_END_EXTERN_C
#endif
#endif
#endif

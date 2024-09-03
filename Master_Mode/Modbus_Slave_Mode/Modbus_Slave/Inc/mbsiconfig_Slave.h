/* 
 * MODBUS Slave Library: A portable MODBUS slave for MODBUS ASCII/RTU/TCP.
 * Copyright (c) 2008 Christian Walter <cwalter@embedded-solutions.at>
 * All rights reserved.
 *
 * $Id$
 */

#ifndef _MBS_CONFIG_DEFAULTS_SLAVE_H
#define _MBS_CONFIG_DEFAULTS_SLAVE_H
#include "main.h"
#if (Modbus_Mode==MODBUS_SLAVE)
/* ----------------------- Defines ------------------------------------------*/
/*! \addtogroup mbs_cfg
 *  @{
 */

/*! \brief If MODBUS ASCII support is enabled. */
#ifndef MBS_ASCII_ENABLED
#define MBS_ASCII_ENABLED                       ( 1 )
#endif

/*! \brief If MODBUS RTU support is enabled. */
#ifndef MBS_RTU_ENABLED
#define MBS_RTU_ENABLED                         ( 1 )
#endif

/*! \brief If MODBUS TCP support is enabled. */
#ifndef MBS_TCP_ENABLED
#define MBS_TCP_ENABLED                         ( 0 )
#endif

/*! \brief If MODBUS TCP support is enabled. */
#ifndef MBS_UDP_ENABLED
#define MBS_UDP_ENABLED                         ( 0 )
#endif

/*! \brief Number of serial RTU instances supported. */
#ifndef MBS_SERIAL_RTU_MAX_INSTANCES
#define MBS_SERIAL_RTU_MAX_INSTANCES            ( 2 )
#endif

/*! \brief Number of serial ASCII instances supported. */
#ifndef MBS_SERIAL_ASCII_MAX_INSTANCES
#define MBS_SERIAL_ASCII_MAX_INSTANCES          ( 2 )
#endif

/*! \brief Choose the API of the serial read/write callbacks. There are
 *   two different versions.
 *
 * - API V1: This API uses the callback types 
 *    pbMBPSerialTransmitterEmptyAPIV1CB  and pvMBPSerialReceiverAPIV1CB.
 *    These type of callback are preferred because they can be used to 
 *    implement the strict timeouts for MODBUS RTU. The drawback is that
 *    they can not be implemented on every platform (Windows, Linux, ...).
 *
 * - API V2: This API uses the callback types
 *    pbMBPSerialTransmitterEmptyAPIV2CB  and pvMBPSerialReceiverAPIV2CB.
 *    Instead of single bytes this API can transfer multiple bytes at
 *    the same time. Using this API makes it impossible to implement the
 *    strict MODBUS timeouts but they have a better performance on 
 *    some platforms and the porting layer is easier to implement.
 */
#ifndef MBS_SERIAL_API_VERSION
#define MBS_SERIAL_API_VERSION                  ( 1 )
#endif

/*! \brief Serial timeout for RTU frame reception if the serial API
 *   version 2 is used.
 *
 * Most operating systems using the API version 2 do not support very tight
 * timeouts. Therefore we do not use the t3.5 timers in MODBUS RTU but use
 * a higher timeout. The best value depend on the operating system and
 * its realtime characteristics as well as the serial driver interface.
 */
#ifndef MBS_SERIAL_APIV2_RTU_TIMEOUT_MS
#define MBS_SERIAL_APIV2_RTU_TIMEOUT_MS         ( 20 )
#endif

/*! \brief Normally a frame is processed within the frame receive callback. This
 *   function allows processing non local frames within the timer callback.
 *
 * Normally frames are processed within the RTU callbacks. This can be problematic
 * in case of RTU because it implies that the slave must handle all frames, even not
 * then ones sent to itself. This function checks in the callback if the request is
 * either a broadcast or for the slave. If not it drops it silently.
 */
#ifndef MBS_SERIAL_DROPFRAME_TIMEOUT_CB         
#define MBS_SERIAL_DROPFRAME_TIMEOUT_CB         ( 0 )
#endif

#if MBS_SERIAL_DROPFRAME_TIMEOUT_CB == 1
#define MBS_RTU_NEEDS_INTHDL                    ( 1 )
#endif

/*! \brief Makes the MODBUS handle available internal within the frame handlers
 */
#ifndef MBS_RTU_NEEDS_INTHDL
#define MBS_RTU_NEEDS_INTHDL                    ( 1 )
#endif

/*! \brief Serial timeout for RTU frame reception computed dynamically
 *   on the baudrate. Only usef in V2 serial API.
 *
 * This function should return the timeout to use for end of frame
 * transmission. You should set this to match the internal buffer size
 * of your serial device. For example if you can buffer 32 bytes and
 * the speed is 9600 you would return approx. 11/9600 * 32 + 5ms
 * where the 5ms is an additional safety margin and 11/9600 is for
 * 8 databits, 1 stopbit and parity.
 */
#ifndef MBS_SERIAL_APIV2_RTU_DYNAMIC_TIMEOUT_MS
#define MBS_SERIAL_APIV2_RTU_DYNAMIC_TIMEOUT_MS( ulBaudRate ) ( MBS_SERIAL_APIV2_RTU_TIMEOUT_MS )
#endif

/*! \brief Number of TCP instances supported. */
#ifndef MBS_TCP_MAX_INSTANCES
#define MBS_TCP_MAX_INSTANCES                   ( 1 )
#endif

/*! \brief Number of TCP instances supported. */
#ifndef MBS_UDP_MAX_INSTANCES
#define MBS_UDP_MAX_INSTANCES                   ( 1 )
#endif

/*! \brief Number of TCP clients allowed. */
#ifndef MBS_TCP_MAX_CLIENTS
#define MBS_TCP_MAX_CLIENTS                     ( 2 )
#endif

/*! \brief The character timeout value for Modbus ASCII.
 *
 * The character timeout value is not fixed for Modbus ASCII and is therefore
 * a configuration option. It should be set to the maximum expected delay
 * time of the network.
 */
#ifndef MBS_ASCII_TIMEOUT_SEC
#define MBS_ASCII_TIMEOUT_SEC                   ( 1 )
#endif

/*! \brief Backof time milliseconds for MODBUS SERIAL to introduce an 
 *   additional delay after the frame has been received and before the reply
 *   is sent.
 *
 * \warning Don't change the default unless you now exactly what you are doing.
 * \note If a MODBUS slave has sent a respond the MASTER stack waits this
 *  configured time. This can be necessary because otherwise the MASTER could
 *  send a new query (depends on the application) but the slave is still not
 *  ready (For example it needs some time to switch its RS485 transceiver from
 *  write to read).
 */
#ifndef MBS_ASCII_BACKOF_TIME_MS
#if MBS_ASCII_ENABLED == 1
#define MBS_ASCII_BACKOF_TIME_MS                ( 5 )
#else
#define MBS_ASCII_BACKOF_TIME_MS                ( 5 )
#endif
#endif

/*! \brief If the API should check arguments for errors. 
 *
 * This has a small performance impact and one might not use this on very
 * small systems.
 */
#ifndef MBS_ENABLE_FULL_API_CHECKS
#define MBS_ENABLE_FULL_API_CHECKS                  ( 1 )
#endif

/*! \brief Number of custom function handlers which are supported.
 */
#ifndef MBS_NCUSTOM_FUNCTION_HANDLERS
#define MBS_NCUSTOM_FUNCTION_HANDLERS               ( 2 )
#endif

/*! \brief If the <em>Read Input Registers</em> function should be enabled. */
#ifndef MBS_FUNC_READ_INPUT_REGISTERS_ENABLED
#define MBS_FUNC_READ_INPUT_REGISTERS_ENABLED       ( 1 )
#endif

/*!brief If the <em>Read Holding Registers</em> function should be enabled. */
#ifndef MBS_FUNC_READ_HOLDING_REGISTERS_ENABLED
#define MBS_FUNC_READ_HOLDING_REGISTERS_ENABLED     ( 1 )
#endif

/*! \brief If the <em>Write Single Register</em> function should be enabled. */
#ifndef MBS_FUNC_WRITE_SINGLE_REGISTER_ENABLED
#define MBS_FUNC_WRITE_SINGLE_REGISTER_ENABLED      ( 1 )
#endif

/*! \brief If the <em>Read Input Registers</em> function should be enabled. */
#ifndef MBS_FUNC_WRITE_MULTIPLE_REGISTERS_ENABLED
#define MBS_FUNC_WRITE_MULTIPLE_REGISTERS_ENABLED   ( 1 )
#endif

/*! \brief If the <em>Read File Record</em> function should be enabled. */
#ifndef MBS_FUNC_READ_FILE_RECORD_ENABLED
#define MBS_FUNC_READ_FILE_RECORD_ENABLED   ( 1 )
#endif

/*! \brief If the <em>Write File Record</em> function should be enabled. */
#ifndef MBS_FUNC_WRITE_FILE_RECORD_ENABLED
#define MBS_FUNC_WRITE_FILE_RECORD_ENABLED   ( 1 )
#endif

/*! \brief If the <em>Read/Write Multiple Registers</em> function should be
 *   enabled.
 */
#ifndef MBS_FUNC_MASK_WRITE_REGISTER_ENABLED
#define MBS_FUNC_MASK_WRITE_REGISTER_ENABLED        ( 1 )
#endif

/*! \brief If the <em>Mask Write Registers</em> function should be
 *   enabled.
 */
#ifndef MBS_FUNC_READWRITE_MULTIPLE_REGISTERS_ENABLED
#define MBS_FUNC_READWRITE_MULTIPLE_REGISTERS_ENABLED ( 1 )
#endif

/*! \brief If the <em>Read Discrete</em> function should be enabled. */
#ifndef MBS_FUNC_READ_DISCRETE_ENABLED
#define MBS_FUNC_READ_DISCRETE_ENABLED              ( 1 )
#endif

/*! \brief If the <em>Read Coils</em> function should be enabled. */
#ifndef MBS_FUNC_READ_COILS_ENABLED
#define MBS_FUNC_READ_COILS_ENABLED                 ( 1 )
#endif

/*! \brief If the <em>Write Single Coil</em> function should be enabled. */
#ifndef MBS_FUNC_WRITE_SINGLE_COIL_ENABLED
#define MBS_FUNC_WRITE_SINGLE_COIL_ENABLED          ( 1 )
#endif

/*! \brief If the <em>Write Multiple Coils</em> function should be enabled. */
#ifndef MBS_FUNC_WRITE_MULTIPLE_COILS_ENABLED
#define MBS_FUNC_WRITE_MULTIPLE_COILS_ENABLED       ( 1 )
#endif

/*! \brief If the <em>Report Slave ID</em> function should be enabled. */
#ifndef MBS_FUNC_REPORT_SLAVE_ID_ENABLED
#define MBS_FUNC_REPORT_SLAVE_ID_ENABLED            ( 0 )
#endif

#ifndef MBS_FUNC_READ_EXCEPTION_STATUS_ENABLED
#define MBS_FUNC_READ_EXCEPTION_STATUS_ENABLED      ( 0 )
#endif

/*! \brief If the RTU layer should wait some time before enabling
 *    the receiver.
 *
 * This function is most useful for toggling the driver enable lines
 * of RS485 transceivers if there is no support in the UART for doing
 * this.
 */
#ifndef MBS_RTU_WAITAFTERSEND_ENABLED
#define MBS_RTU_WAITAFTERSEND_ENABLED               ( 0 )
#endif

/*! \brief If the ASCII layer should wait some time before
 *     enabling the receiver.
 *
 * This function is most useful for toggling the driver enable lines
 * of RS485 transceivers if there is no support in the UART for doing
 * this.
 */
#ifndef MBS_ASCII_WAITAFTERSEND_ENABLED
#define MBS_ASCII_WAITAFTERSEND_ENABLED             ( 0 )
#endif

/*! \brief Enable statistics interface
 */
#ifndef MBS_ENABLE_STATISTICS_INTERFACE
#define MBS_ENABLE_STATISTICS_INTERFACE             ( 0 )
#endif

/*! \brief Enable protocol analyzer
 */
#ifndef MBS_ENABLE_PROT_ANALYZER_INTERFACE
#define MBS_ENABLE_PROT_ANALYZER_INTERFACE          ( 0 )
#endif

/*! \brief Enable serial diagnosis functions
 */
#ifndef MBS_ENABLE_SER_DIAG
#define MBS_ENABLE_SER_DIAG                         ( 0 )
#endif

#if MBS_FUNC_READ_EXCEPTION_STATUS_ENABLED
#ifndef MBS_EXCEPTION_STATUS_BIT0_COIL
#define MBS_EXCEPTION_STATUS_BIT0_COIL              ( 0 )
#endif
#ifndef MBS_EXCEPTION_STATUS_BIT1_COIL
#define MBS_EXCEPTION_STATUS_BIT1_COIL              ( 1 )
#endif
#ifndef MBS_EXCEPTION_STATUS_BIT2_COIL
#define MBS_EXCEPTION_STATUS_BIT2_COIL              ( 2 )
#endif
#ifndef MBS_EXCEPTION_STATUS_BIT3_COIL
#define MBS_EXCEPTION_STATUS_BIT3_COIL              ( 3 )
#endif
#ifndef MBS_EXCEPTION_STATUS_BIT4_COIL
#define MBS_EXCEPTION_STATUS_BIT4_COIL              ( 4 )
#endif
#ifndef MBS_EXCEPTION_STATUS_BIT5_COIL
#define MBS_EXCEPTION_STATUS_BIT5_COIL              ( 5 )
#endif
#ifndef MBS_EXCEPTION_STATUS_BIT6_COIL
#define MBS_EXCEPTION_STATUS_BIT6_COIL              ( 6 )
#endif
#ifndef MBS_EXCEPTION_STATUS_BIT7_COIL
#define MBS_EXCEPTION_STATUS_BIT7_COIL              ( 7 )
#endif
#endif

#if MBS_ENABLE_SER_DIAG
#if !defined( MBS_ENABLE_STATISTICS_INTERFACE ) || ( MBS_ENABLE_STATISTICS_INTERFACE == 0 )
#error Serial diagnosis functions need statistics support.
#endif
#define MBS_REGISTER_CB_NEEDS_INT_HANDLE            ( 1 )
#else
#ifndef MBS_REGISTER_CB_NEEDS_INT_HANDLE
/*! \brief If the MODBUS stack handle is passed to lower layers 
 *
 * \internal
 */
#define MBS_REGISTER_CB_NEEDS_INT_HANDLE			( 0 )
#endif
#endif

/*! \brief If the MODBUS handle should be passed to the callback
 *    functions.
 */
#ifndef MBS_CALLBACK_ENABLE_CONTEXT
#define MBS_CALLBACK_ENABLE_CONTEXT                 ( 0 )
#endif

/*! \brief If we want advanced startup/shutdown locking.
 *
 * Advanced startup/shutdown locking might be necessary if the MODBUS
 * stack should be embedded as a DLL and the porting layers needs
 * specials hooks for startup, i.e. when the first instance is created
 * and when the last instance is shut down.
 * If for the first time an MODBUS serial or TCP init function is called
 * the stack calls vMBPLibraryLoad(  ). If the stack is shutdown
 * the function calls vMBPLibraryUnload( ). Because the init and the
 * close functions could be mixed due to threading a second locking
 * primitive MBP_ENTER_CRTICIAL_INIT and MBP_EXIT_CRITICAL_INIT have
 * to be provided. They default to empty macros but should be defined.
 * for safe startup/shutdown behaviour is this can not be enforced by
 * the application.
 */
#ifndef MBP_ADVA_STARTUP_SHUTDOWN_ENABLED
#define MBP_ADVA_STARTUP_SHUTDOWN_ENABLED       ( 0 )
#endif

/*! \brief If debugging code should be built into the MODBUS stack.
 */
#ifndef MBS_ENABLE_DEBUG_FACILITY
#define MBS_ENABLE_DEBUG_FACILITY               ( 0 )
#endif

/*! \brief The timeout to wait when wait after send timeouts are used in RTU
 *   transmission mode.
 *
 * This macro should be defined if the default wait after send timeouts
 * are not useful. It is only used when either MBS_RTU_WAITAFTERSEND_ENABLED is
 * defined.
 */
#ifndef MBS_SERIAL_RTU_DYNAMIC_WAITAFTERSEND_TIMEOUT_MS
#define MBS_SERIAL_RTU_DYNAMIC_WAITAFTERSEND_TIMEOUT_MS( ulBaudRate ) \
	MB_INTDIV_CEIL( 1000UL * 11UL, ulBaudRate )
#endif

/*! \brief The timeout to wait when wait after send timeouts are used in ASCII
 *   transmission mode.
 *
 * This macro should be defined if the default wait after send timeouts
 * are not useful. It is only used when either MBS_ASCII_WAITAFTERSEND_ENABLED is
 * defined.
 */
#ifndef MBS_SERIAL_ASCII_DYNAMIC_WAITAFTERSEND_TIMEOUT_MS
#define MBS_SERIAL_ASCII_DYNAMIC_WAITAFTERSEND_TIMEOUT_MS( ulBaudRate ) \
	MB_INTDIV_CEIL( 1000UL * 10UL, ulBaudRate )
#endif

/*! \brief If the slave ID of a request should be tracked.
 *
 * If enabled this macro allows the register callback functions to get
 * the slave address for this MODBUS request.
 */
#ifndef MBS_TRACK_SLAVEADDRESS
#define MBS_TRACK_SLAVEADDRESS                  ( 0 )
#endif

/*! \brief If the MODBUS slave should support gateway mode
 *
 * If enabled the MODBUS slave processes all slave requests. This can
 * be used to implement request forwarding to other devices.
 */
#ifndef MBS_ENABLE_GATEWAY_MODE
#define MBS_ENABLE_GATEWAY_MODE                 ( 0 )
#endif

/*! \brief If enabled eMBSPoll internally executes any required poll
 *   cycles to fully process a pending frame.
 *
 * This macro should be enabled if eMBSPoll is not called often enough.
 * It makes sure that a frame is fully processed, i.e. parsed, callbacks
 * executed and response sent.
 */
#ifndef MBS_POLL_SINGLE_CYCLE
#define MBS_POLL_SINGLE_CYCLE                   ( 1 )
#endif

/*! \brief Ignore MBAP unit ID field in TCP slave
 */
#ifndef MBS_TCP_IGNORE_UNIT_ID
#define MBS_TCP_IGNORE_UNIT_ID                  ( 0 )
#endif

/*! \brief If this is an evaluation build
 */
#ifndef MBS_IS_EVALUATION_BUILD
#define MBS_IS_EVALUATION_BUILD                 ( 0 )
#endif

/* ----------------------- Type definitions ---------------------------------*/

/* ----------------------- Function prototypes ------------------------------*/

/*! @} */
#endif
#endif

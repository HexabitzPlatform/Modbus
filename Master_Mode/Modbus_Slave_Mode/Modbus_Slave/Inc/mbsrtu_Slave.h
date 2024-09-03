/* 
 * MODBUS Slave Library: A portable MODBUS slave for MODBUS ASCII/RTU/TCP.
 * Copyright (c) 2007 Christian Walter <wolti@sil.at>
 * All rights reserved.
 *
 * $Id$
 */

#ifdef __cplusplus
PR_BEGIN_EXTERN_C
#endif
#include "main.h"
#if (Modbus_Mode==MODBUS_SLAVE)
#if MBS_RTU_ENABLED == 1

/*! 
 * \if INTERNAL_DOCS
 * \addtogroup mbs_rtu_int
 * @{
 * \endif
 */

/* ----------------------- Defines ------------------------------------------*/

/* ----------------------- Type definitions ---------------------------------*/

/* ----------------------- Function prototypes ------------------------------*/
/*! \brief Configure a MODBUS slave RTU instances.
 * \internal
 *
 * \param pxIntHdl An internal handle.
 * \param ubPort The port. This value is passed through to the porting layer.
 * \param ulBaudRate Baudrate.
 * \param eParity Parity.
 * \param ucStopBits Number of stop bits.
 *
 * \return eMBErrorCode::MB_ENOERR if a new instance has been created. In 
 *   this case the members pxFrameHdl, pFrameSendFN, pFrameRecvFN,
 *   pFrameCloseFN and pFrameManagementFN in the handle are updated to point 
 *   to this RTU instance. In case of an invalid handle or baudrate it returns
 *   eMBErrorCode::MB_EINVAL. In case of a porting layer error it returns
 *   eMBErrorCode::MB_EPORTERR.
 */
eMBErrorCode
eMBSSerialRTUInit( xMBSInternalHandle * pxIntHdl, UBYTE ubPort, ULONG ulBaudRate, eMBSerialParity eParity, UCHAR ucStopBits );

/*!
 * \if INTERNAL_DOCS
 * @}
 * \endif
 */

#endif

#ifdef __cplusplus
PR_END_EXTERN_C
#endif
#endif

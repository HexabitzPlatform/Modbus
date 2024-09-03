/* 
 * MODBUS Library: A portable MODBUS master for MODBUS ASCII/RTU/TCP.
 * Copyright (c) 2008 Christian Walter <cwalter@embedded-solutions.at>
 * All rights reserved.
 *
 * $Id$
 */


#ifndef _MBS_CRC_SLAVE_H
#define _MBS_CRC_SLAVE_H
#include "main.h"
#if (Modbus_Mode==MODBUS_SLAVE)
#ifdef __cplusplus
PR_BEGIN_EXTERN_C
#endif

/*! 
 * \if INTERNAL_DOCS
 * \addtogroup mbs_rtu_int
 * @{
 * \endif
 */

/* ----------------------- Defines ------------------------------------------*/

/* ----------------------- Type definitions ---------------------------------*/

/* ----------------------- Function prototypes ------------------------------*/

/*! \brief Calculates the CRC16 checksum of a frame of length usLen and
 *   returns it.
 * \internal
 *
 * \param pucFrame A pointer to a frame of length \c usLen.
 * \param usLen Size of the frame to check.
 * \return the CRC16 checksum for this frame.
 */
USHORT usMBSCRC16( const UBYTE * pucFrame, USHORT usLen );

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

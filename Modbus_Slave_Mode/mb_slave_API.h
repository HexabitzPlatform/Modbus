/*
 * mb_slave_API.h
 *
 *  Created on: Sep 2, 2024
 *      Author: MAHMOOD_REDA
 */

#ifndef MB_SLAVE_API_H_
#define MB_SLAVE_API_H_

eMBErrorCode MbSlaveMode(eMBMode eMode, UCHAR Slave_Address, UCHAR Port,ULONG Baud_Rate, eMBParity Parity) ;
void Write (USHORT *Buffer,uint8_t startAdd,uint8_t endAdd);
void Read (USHORT *Buffer, uint8_t startAdd, uint8_t endAdd);
void MX_NVIC_Init(void);
#endif /* MB_SLAVE_API_H_ */

/*
 * mb_slave_API.h
 *
 *  Created on: Sep 2, 2024
 *      Author: MAHMOOD_REDA
 */

#ifndef MB_SLAVE_API_H_
#define MB_SLAVE_API_H_

eMBErrorCode MbSlaveMode(eMBMode eMode, UCHAR Slave_Address, UCHAR Port,ULONG Baud_Rate, eMBParity Parity) ;
void WriteToModbusBuffer(USHORT *Buffer, uint16_t RegAdd, uint16_t NofReg);
void ReadFromModbusBuffer(USHORT *Buffer, uint16_t RegAdd, uint16_t NofReg);

#endif /* MB_SLAVE_API_H_ */

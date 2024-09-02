/*
 * mb_slave_API.c
 *
 *  Created on: Sep 2, 2024
 *      Author: MAHMOOD_REDA
 */

/* ----------------------- System includes ----------------------------------*/
#include "stdlib.h"
#include "string.h"

/* ----------------------- Platform includes --------------------------------*/
#include "port.h"

/* ----------------------- Modbus includes ----------------------------------*/
#include "mb.h"
#include "mbconfig.h"
#include "mbframe.h"
#include "mbproto.h"
#include "mbfunc.h"
#include "mbtask.h"



extern USHORT   usRegHoldingBuf[REG_HOLDING_NREGS];

eMBErrorCode MbSlaveMode(eMBMode eMode, UCHAR Slave_Address, UCHAR Port,ULONG Baud_Rate, eMBParity Parity) {

	eMBErrorCode eStatus = eMBInit(eMode, Slave_Address, Port, Baud_Rate,Parity);
	eStatus = eMBEnable();
}

void Write(USHORT *Buffer, uint8_t startAdd, uint8_t endAdd) {
	int Index = 0;
	while (startAdd < endAdd) {
		usRegHoldingBuf[Index] = *Buffer++;
		endAdd--;
		Index++;
	}

}


void Read (USHORT *Buffer, uint8_t startAdd, uint8_t endAdd) {
	int Index = 0;
	while (startAdd < endAdd) {
		*Buffer++ = usRegHoldingBuf[Index];
		endAdd--;
		Index++;
	}

}

 void MX_NVIC_Init(void)
 {

	/* DMA1_Channel1_IRQn interrupt configuration */
	NVIC_SetPriority(DMA1_Channel1_IRQn, 1);
	NVIC_EnableIRQ(DMA1_Channel1_IRQn);
	/* TIM14_IRQn interrupt configuration */
	NVIC_SetPriority(TIM14_IRQn, 2);
	NVIC_EnableIRQ(TIM14_IRQn);
	/* USART1_IRQn interrupt configuration */
	NVIC_SetPriority(USART1_IRQn, 3);
	NVIC_EnableIRQ(USART1_IRQn);
	/* TIM16_IRQn interrupt configuration */
	NVIC_SetPriority(TIM16_IRQn, 2);
	NVIC_EnableIRQ(TIM16_IRQn);

}

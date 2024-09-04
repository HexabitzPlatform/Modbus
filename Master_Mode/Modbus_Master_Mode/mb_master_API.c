/*
 * mb_master_API.c
 *
 *  Created on: Sep 4, 2024
 *      Author: MAHMOOD_REDA
 */


/*
    Copyright (C) 2017-2020 Hexabitz
    All rights reserved

    File Name     : Modbus.c
    Description   : Source code for Modbus module.
										RS-485 Serial Transceiver (MAX14840EASA+)

		Required MCU resources :

			>> USARTs 2,3,4,5,6 for module ports.
			>> USART 1 for MAX14840EASA+.
			>> PA12 for RE/DE (receiver output enable).
			>> TIM16 for MB port.

*/
#include "main.h"

/* Includes ------------------------------------------------------------------*/

#include "task.h"
#include "mbm.h"
#include "main.h"
#include "mb_master_API.h"

/* Private variables ---------------------------------------------------------*/
/* exported peripherals handles */
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;
extern UART_HandleTypeDef huart4;
extern UART_HandleTypeDef huart5;
extern UART_HandleTypeDef huart6;
extern CRC_HandleTypeDef hcrc;


xMBMHandle xMBMaster;

USHORT DataRcv[200];

uint8_t mbTriggerFlag=0;
uint8_t Hour;
uint8_t Minute;
uint8_t Second;
uint8_t wmTimeOut;
uint16_t msCounter;
uint16_t TMOUT_Counter;
struct rxMessaging_TypeDef rxMessaging;

TimerHandle_t zTimer = NULL;
TimerHandle_t sTimer = NULL;

osThreadId MessagingTaskHandle;



//uint8_t RcvMessage[NumOfPorts][RcvMessageMaxSize];

/* Private function prototypes -----------------------------------------------*/
void MessagingTask(void const * argument);
static void RTC_HandleTimer(TimerHandle_t zTimer);
static void TMOUT_HandleTimer(TimerHandle_t sTimer);
void SystemClock_Config(void);
void prvvMBPUSART1_RXNE_ISR( void );
/* -----------------------------------------------------------------------
	|												 Private Functions	 														|
   -----------------------------------------------------------------------
*/

/* --- Modbus module initialization.
*/
void Modbus_task_Init(void)
{

	/* Definition and creation of software timers */
	zTimer = xTimerCreate( "RTC_Timer", pdMS_TO_TICKS(1), pdTRUE, ( void * ) TIMERID_RTC_TIMER, RTC_HandleTimer );
	xTimerStart( zTimer, portMAX_DELAY );

	sTimer = xTimerCreate( "TimeOut_Timer", pdMS_TO_TICKS(1), pdTRUE, ( void * ) TIMERID_TMOUT_TIMER, TMOUT_HandleTimer );
	xTimerStart( sTimer, portMAX_DELAY );

	osThreadDef(defaultTask, MessagingTask, osPriorityNormal, 0, 8*128);
	MessagingTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

	/* Initializing DMA recieve */
//	HAL_UART_Receive_DMA(P1uart, &RcvMessage[0][0], RcvMessageMaxSize);


}

void MessagingTask(void const * argument)
{

	vTaskDelete(NULL);
}

Module_Status SetupModbusRTU(uint32_t BaudRate, uint32_t ParityBit)
{
	Module_Status Status;
	ULONG Pbit = (ULONG) ParityBit;
	ULONG ulBaudRate = (ULONG) BaudRate;
	  HAL_NVIC_DisableIRQ(DMA1_Ch2_3_DMA2_Ch1_2_IRQn);
	  HAL_NVIC_DisableIRQ(DMA1_Ch4_7_DMA2_Ch3_5_IRQn);
	/* Initialize Modbus port as RTU */
	if ( MB_ENOERR != eMBMSerialInit( &xMBMaster,  MB_RTU, 1, ulBaudRate, Pbit ) ) {
		Status = Modbus_ERROR;}
	else
		Status = Modbus_OK;
	  HAL_NVIC_EnableIRQ(DMA1_Ch4_7_DMA2_Ch3_5_IRQn);
	  HAL_NVIC_EnableIRQ(DMA1_Ch2_3_DMA2_Ch1_2_IRQn);
 return Status;
}

/*-----------------------------------------------------------*/

/* --- setup the Modbus mode as ASCII
*/
Module_Status SetupModbusASCII(uint32_t BaudRate, uint32_t ParityBit)
{
	Module_Status Status;
	ULONG Pbit = (ULONG) ParityBit;
	ULONG ulBaudRate = (ULONG) BaudRate;
	  HAL_NVIC_DisableIRQ(DMA1_Ch2_3_DMA2_Ch1_2_IRQn);
	  HAL_NVIC_DisableIRQ(DMA1_Ch4_7_DMA2_Ch3_5_IRQn);
	/* Initialize Modbus port as ASCII */
	if ( MB_ENOERR != eMBMSerialInit( &xMBMaster,  MB_ASCII, 1, ulBaudRate, Pbit ) ) {
		Status = Modbus_ERROR;}
	else
		Status = Modbus_OK;
	  HAL_NVIC_EnableIRQ(DMA1_Ch4_7_DMA2_Ch3_5_IRQn);
	  HAL_NVIC_EnableIRQ(DMA1_Ch2_3_DMA2_Ch1_2_IRQn);
	return Status;
}

/*-----------------------------------------------------------*/

/* --- read data from a slave on Modbus port FC: 0x03
*/
Module_Status ReadModbusRegister(uint8_t SlaveAdd, uint32_t RegAdd, uint8_t NofReg, unsigned short * DataBuffer )
{
	Module_Status Status;
	unsigned short *Buffer=DataBuffer;

	  HAL_NVIC_DisableIRQ(DMA1_Ch2_3_DMA2_Ch1_2_IRQn);
	  HAL_NVIC_DisableIRQ(DMA1_Ch4_7_DMA2_Ch3_5_IRQn);
	if (MB_ENOERR != eMBMReadHoldingRegisters(xMBMaster, SlaveAdd, RegAdd, NofReg, Buffer)) {
		Status = Modbus_ERROR;}
	else {
		Status = Modbus_OK;
	}
	  HAL_NVIC_EnableIRQ(DMA1_Ch4_7_DMA2_Ch3_5_IRQn);
	  HAL_NVIC_EnableIRQ(DMA1_Ch2_3_DMA2_Ch1_2_IRQn);

	return Status;
}

/*-----------------------------------------------------------*/

/* --- write data to a slave on Modbus port FC: 0x06
*/
Module_Status WriteModbusRegister(uint8_t SlaveAdd, uint32_t RegAdd, uint32_t Data)
{
	Module_Status Status;
	  HAL_NVIC_DisableIRQ(DMA1_Ch2_3_DMA2_Ch1_2_IRQn);
	  HAL_NVIC_DisableIRQ(DMA1_Ch4_7_DMA2_Ch3_5_IRQn);
	if (MB_ENOERR != eMBMWriteSingleRegister(xMBMaster, SlaveAdd, RegAdd, Data)) {
		Status = Modbus_ERROR;}
	else {
		Status = Modbus_OK;
	}
	  HAL_NVIC_EnableIRQ(DMA1_Ch4_7_DMA2_Ch3_5_IRQn);
	  HAL_NVIC_EnableIRQ(DMA1_Ch2_3_DMA2_Ch1_2_IRQn);
	return Status;
}
/*-----------------------------------------------------------*/

/* --- write N data bytes to a slave on Modbus port FC: 0x10
*/
Module_Status WriteModbusMultiRegisters(uint8_t SlaveAdd, uint32_t RegAdd, uint8_t NofReg, uint16_t *Data)
{
	Module_Status Status;
	USHORT *InBuffer = (USHORT *)Data;
	  HAL_NVIC_DisableIRQ(DMA1_Ch2_3_DMA2_Ch1_2_IRQn);
	  HAL_NVIC_DisableIRQ(DMA1_Ch4_7_DMA2_Ch3_5_IRQn);
	if (MB_ENOERR != eMBMWriteMultipleRegisters(xMBMaster, SlaveAdd, RegAdd, NofReg, InBuffer)) {
		Status = Modbus_ERROR;}
	else {
		Status = Modbus_OK;
	}
	  HAL_NVIC_EnableIRQ(DMA1_Ch4_7_DMA2_Ch3_5_IRQn);
	  HAL_NVIC_EnableIRQ(DMA1_Ch2_3_DMA2_Ch1_2_IRQn);
	return Status;
}

/*-----------------------------------------------------------*/

/* --- set timeout to a slave on Modbus port
*/
Module_Status SetTimeOut(uint16_t MiliSeconds)
{
	Module_Status Status;
	USHORT timeout = (USHORT) MiliSeconds;
	  HAL_NVIC_DisableIRQ(DMA1_Ch2_3_DMA2_Ch1_2_IRQn);
	  HAL_NVIC_DisableIRQ(DMA1_Ch4_7_DMA2_Ch3_5_IRQn);
	if (MB_ENOERR != eMBMSetSlaveTimeout( xMBMaster, timeout )) {
		Status = Modbus_ERROR;}
	else
		Status = Modbus_OK;
	  HAL_NVIC_EnableIRQ(DMA1_Ch4_7_DMA2_Ch3_5_IRQn);
	  HAL_NVIC_EnableIRQ(DMA1_Ch2_3_DMA2_Ch1_2_IRQn);
	return Status;
}

/*-----------------------------------------------------------*/


/* --- TimeOut software timer*/

static void TMOUT_HandleTimer(TimerHandle_t sTimer)
{
	uint32_t Timer_ID = 0;

	Timer_ID = ( uint32_t ) pvTimerGetTimerID( sTimer );
  if (TIMERID_TMOUT_TIMER == Timer_ID)
  {
		TMOUT_Counter++;
		if (TMOUT_Counter==1000){
			wmTimeOut++;
			TMOUT_Counter=0;
		}
	}
}

/*-----------------------------------------------------------*/

/* --- RTC software timer*/

static void RTC_HandleTimer(TimerHandle_t zTimer)
{
	uint32_t Timer_ID = 0;

	Timer_ID = ( uint32_t ) pvTimerGetTimerID( zTimer );
  if (TIMERID_RTC_TIMER == Timer_ID)
  {
		msCounter++;
		if (msCounter==1000)
		{
			Second++;
			msCounter=0;
		}
		if (Second==60)
		{
			Second=0;
			Minute++;
		}
		if (Minute==60)
		{
			Minute=0;
			Hour++;
		}
		if (Hour==24)
		{
			Hour=0;
		}
	}
}


void SetRTC(uint8_t hour, uint8_t min, uint8_t sec)
{

	Hour = hour;
	Minute = min;
	Second = sec;
}
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {

		rxMessaging.Flag = 1;

	if (huart == P_RS485uart) {
		prvvMBPUSART1_RXNE_ISR(); /* Call Modbus protocol port ISR */
	}

	/* NOTE : This function should not be modified, when the callback is needed,
	 the HAL_UART_RxCpltCallback can be implemented in the user file.
	 */
}

/************************ (C) COPYRIGHT HEXABITZ *****END OF FILE****/

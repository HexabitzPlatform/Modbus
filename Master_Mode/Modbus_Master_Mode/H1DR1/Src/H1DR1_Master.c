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
#if (Modbus_Mode==MODBUS_MASTER)
/* Includes ------------------------------------------------------------------*/
#include <H1DR1_Master.h>
#include "task.h"
#include "mbm.h"
#include "main.h"
#include "Modbus_Master_Mode.h"

/* Private variables ---------------------------------------------------------*/
/* exported peripherals handles */
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;
extern UART_HandleTypeDef huart4;
extern UART_HandleTypeDef huart5;
extern UART_HandleTypeDef huart6;
extern CRC_HandleTypeDef hcrc;

/* Modbus global variables */
xMBMHandle xMBMaster;
uint8_t Src_port;
uint32_t Br_baud_rate;
uint32_t Parity_bit;

USHORT DataRcv[200];

uint8_t mbTriggerFlag=0;
uint8_t Hour;
uint8_t Minute;
uint8_t Second;
uint8_t wmTimeOut;
uint16_t msCounter;
uint16_t TMOUT_Counter;
struct rxMessaging_TypeDef rxMessaging;

/* defining freertos timers and task handles */
TimerHandle_t zTimer = NULL;
TimerHandle_t sTimer = NULL;
//osThreadId backgroundTaskHandle;
osThreadId MessagingTaskHandle;

/* meters structure and matrix definition */
uint16_t MeterCFG[MB_MAX_DEVICES][METER_MB_PARAMS]={0};
struct Meter_TypeDef SPZMeter;
struct Meter_TypeDef *SPZMeterHandle;
struct Meter_TypeDef DeltaMeter;
struct Meter_TypeDef *DeltaMeterHandle;

uint8_t RcvMessage[NumOfPorts][RcvMessageMaxSize];

/* Private function prototypes -----------------------------------------------*/	 
void MessagingTask(void const * argument);
static void RTC_HandleTimer(TimerHandle_t zTimer);
static void TMOUT_HandleTimer(TimerHandle_t sTimer);
void SystemClock_Config(void);
/* -----------------------------------------------------------------------
	|												 Private Functions	 														|
   ----------------------------------------------------------------------- 
*/

/**
  * @brief System Clock Configuration
  * @retval None
  */
//void SystemClock_Config(void)
//{
//  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
//  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
//  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};
//
//  /** Initializes the CPU, AHB and APB busses clocks
//  */
//  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
//  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
//  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
//  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
//  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL4;
//  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
//  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
//  {
//    Error_Handler();
//  }
//  /** Initializes the CPU, AHB and APB busses clocks
//  */
//  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
//                              |RCC_CLOCKTYPE_PCLK1;
//  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
//  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV2;
//  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
//
//  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
//  {
//    Error_Handler();
//  }
//  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART3|RCC_PERIPHCLK_USART1
//                              |RCC_PERIPHCLK_USART2;
//  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK1;
//  PeriphClkInit.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
//  PeriphClkInit.Usart3ClockSelection = RCC_USART3CLKSOURCE_PCLK1;
//  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
//  {
//    Error_Handler();
//  }
//}

/* --- Modbus module initialization.
*/
void Module_Init(void)
{
	
	/* System Clock Configuration */
	SystemClock_Config();

/* Peripherals Init */
	MX_GPIO_Init();
	MX_DMA_Init();
	MX_CRC_Init();

	/* Array ports */
	MX_USART1_UART_Init();
	MX_USART2_UART_Init();
	MX_USART3_UART_Init();
	MX_USART4_UART_Init();
	MX_USART5_UART_Init();
	MX_USART6_UART_Init();
	
	/* RS485 port */
//	RS485_DE_RE_Init();
	RS485_RECEIVER_EN();
	
	/* Definition and creation of software timers */
	zTimer = xTimerCreate( "RTC_Timer", pdMS_TO_TICKS(1), pdTRUE, ( void * ) TIMERID_RTC_TIMER, RTC_HandleTimer );	
	xTimerStart( zTimer, portMAX_DELAY );
	
	sTimer = xTimerCreate( "TimeOut_Timer", pdMS_TO_TICKS(1), pdTRUE, ( void * ) TIMERID_TMOUT_TIMER, TMOUT_HandleTimer );	
	xTimerStart( sTimer, portMAX_DELAY );

	osThreadDef(defaultTask, MessagingTask, osPriorityNormal, 0, 8*128);
	MessagingTaskHandle = osThreadCreate(osThread(defaultTask), NULL);
	
	/* Initializing DMA recieve */ 
	HAL_UART_Receive_DMA(P1uart, &RcvMessage[0][0], RcvMessageMaxSize);
	HAL_UART_Receive_DMA(P2uart, &RcvMessage[1][0], RcvMessageMaxSize);
	HAL_UART_Receive_DMA(P3uart, &RcvMessage[2][0], RcvMessageMaxSize);
	HAL_UART_Receive_DMA(P4uart, &RcvMessage[3][0], RcvMessageMaxSize);
	HAL_UART_Receive_DMA(P5uart, &RcvMessage[4][0], RcvMessageMaxSize);
	
	SPZMeterHandle=&SPZMeter;
	strcpy( SPZMeter.Model, "SPZ");
	SPZMeter.SerialNumber=9188326;
	SPZMeter.ID=1;
	SPZMeter.NoReg=80;
	SPZMeter.FstRegAddress=0x00;
	SPZMeter.LastRegAddress=0x4F;
	SPZMeter.Status=0;
	
	DeltaMeterHandle=&DeltaMeter;
	strcpy( DeltaMeter.Model, "Delta");
	DeltaMeter.SerialNumber=9188326;
	DeltaMeter.ID=2;
	DeltaMeter.NoReg=140;
	DeltaMeter.FstRegAddress=0x100;
	DeltaMeter.LastRegAddress=0x18B;
	DeltaMeter.Status=0;
	
}

/*-----------------------------------------------------------*/

/* --- Get the port for a given UART. 
*/
uint8_t GetPort(UART_HandleTypeDef *huart)
{
	if (huart->Instance == USART4)
			return 1;
	else if (huart->Instance == USART2)
			return 2;
	else if (huart->Instance == USART6)
			return 3;
	else if (huart->Instance == USART3)
			return 4;
	else if (huart->Instance == USART5)
			return 5;
	else if (huart->Instance == USART1)
			return 6;
		
	return 0;
}

/*-----------------------------------------------------------*/

/* --- Get the UART handle for a given port. 
*/
UART_HandleTypeDef* GetUART(uint8_t Port)
{
	if (1 == Port)
			return &huart4; 
	else if (2 == Port)
			return &huart2;
	else if (3 == Port)
			return &huart6; 
	else if (4 == Port)
			return &huart3;
	else if (5 == Port)
			return &huart5;
	else if (6 == Port)
			return &huart1;
		
	return NULL;
}

/*-----------------------------------------------------------*/

/* --- setup the Modbus mode as RTU
*/
void MessagingTask(void const * argument)
{
	for(;;)
	{
		if (1==rxMessaging.Flag)
		{
			MasterMessagingParser(rxMessaging.Port);
			rxMessaging.Flag=0;
			taskYIELD();
		}
		else
			taskYIELD();
	}

	vTaskDelete(NULL);
}

/* -----------------------------------------------------------------------
	|																APIs	 																 	|
   ----------------------------------------------------------------------- */

/* --- setup the Modbus mode as RTU
*/
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

/* --- get meter struct handle 
*/
struct Meter_TypeDef* GetMeterHandle(uint8_t ID)
{
	if (ID == DeltaMeter.ID)
		return DeltaMeterHandle;
	else if (ID == SPZMeter.ID)
		return SPZMeterHandle;
	
	return 0;
}

/*-----------------------------------------------------------*/

/* --- Modbus main service routine
*/
//Module_Status ModbuserviceRoutine(uint8_t mbMeterID)
//{
//	Module_Status Status;
//	struct Meter_TypeDef* MeterHandle;
//	uint16_t regAddress;
//
//	Status=Modbus_ERROR;
//	wmTimeOut=0;
//	MeterHandle=GetMeterHandle(mbMeterID);
//
//	for(regAddress=MeterHandle->FstRegAddress ; regAddress<=MeterHandle->LastRegAddress ; regAddress++)
//		{
//			Status=Modbus_ERROR;
//
//			while(Status==Modbus_ERROR)
//				{
//					if (ReadModbusRegister(mbMeterID, regAddress, 1, &DataRcv[(regAddress-MeterHandle->FstRegAddress)+4]) ==  Modbus_OK){
//					Status=Modbus_OK;
//					_IND_TOGGLE();
//					}
//				MeterHandle->Status=1;
//				if (wmTimeOut>=20){
//					MeterHandle->Status=0;
//					wmTimeOut=0;
//					goto here;
//				}
//			}
//		}
//		here:
//		_IND_OFF();
//		/* meter ID and status */
//		DataRcv[0]=(MeterHandle->Status<<8) || mbMeterID;
//		DataRcv[1]=(Minute<<8) || Hour;
//		SendMessage(P_BRIDGING, CODE_Modbus_PACKET, 0, (uint8_t *) DataRcv, 4+((MeterHandle->NoReg)*2));
//		HAL_Delay(200);
//		memset(DataRcv,0,400);
//
//	return Status;
//}
/*-----------------------------------------------------------*/
 /* Master Slave Service routine */
Module_Status SlaveServiceRoutine(uint8_t SlaveAdd , uint32_t RegAdd , uint8_t NofReg)
{
	Module_Status Status;
	Status=Modbus_ERROR;

	uint32_t   usRegStart = RegAdd;
	uint32_t   usRegEnd = RegAdd + NofReg - 1;
  uint8_t    index =0;

	for(; usRegStart <= usRegEnd; usRegStart++)
		{
			Status=Modbus_ERROR;

			while(Status==Modbus_ERROR)
				{
//				ReadModbusRegister(SlaveAdd, usRegStart, 1, &DataRcv[index]) ==  Modbus_OK;
//				Status=Modbus_OK;
				if (ReadModbusRegister(SlaveAdd, usRegStart, 1, &DataRcv[index]) ==  Modbus_OK)
						{

							_IND_TOGGLE();
					  }

					}
					index ++;
		}
				index =0;
	return Status;

}
/*-----------------------------------------------------------*/
/* --- send data packet from port
*/

Module_Status SendMessage(uint16_t Port, uint16_t mCode, uint8_t dst, uint8_t *pData, uint16_t size)
{
	Module_Status Status;
	UART_HandleTypeDef* handle;
	uint16_t length;
	uint8_t crc8;
	uint8_t MessagePacket[300]={0};

	/* check port */
	if (0<Port && 6>Port)
	{
		/* get the handle of the port to transmit from */
		handle=GetUART(Port);

		/* Configuring packet's header */
		/* packet delimiter */
		MessagePacket[0]='H';
		MessagePacket[1]='Z';

		if (87==mCode)
		{
			/* Calculating packet length */
			length=size+9;                          /*not including H & Z delimiters, the length bytes and the CRC byte.*/
			memcpy(&MessagePacket[2], &length, 2);
			/* destination module */
			MessagePacket[4]=dst;
			/* source module */
			MessagePacket[5]=MyID;
			/* options byte */
			MessagePacket[6]=Options;
			/* message code */
			MessagePacket[7]=mCode;

			/* Copying data payload */
			memcpy(&MessagePacket[8],pData,size);
		}
		else
		{
			/* Calculating packet length */
			length=size+8;                          /*not including H & Z delimiters, the length bytes and the CRC byte.*/
			MessagePacket[2]=length;
			/* destination module */
		  MessagePacket[3]=dst;
			/* source module */
		  MessagePacket[4]=MyID;
		  /* options byte */
		  MessagePacket[5]=Options;
		  /* message code */
		  MessagePacket[6]=mCode;
			/* Copying data payload */
			memcpy(&MessagePacket[7],pData,size);
		}

		/* Calculating CRC8 for the packet */
		crc8 = HAL_CRC_Calculate(&hcrc, (uint32_t *)&MessagePacket, (length-1)/4);
		if ((length-1)%4 !=0){
			crc8 = HAL_CRC_Accumulate(&hcrc, (uint32_t *)&MessagePacket[((length-1)/4)*4], 1);
		}
		MessagePacket[length-1]=crc8;

		/* Send data packet via DMA */
		HAL_UART_Transmit_DMA(handle, MessagePacket,length);    /* in case length doesn't include delimeter and CRC should be added to 5*/

		/* wait to finish transmitting packet */
		HAL_Delay(100);

		/* Reinitializing DMA */
		HAL_UART_DeInit(handle);
		HAL_UART_Init(handle);
		HAL_UART_Receive_DMA(handle, &RcvMessage[Port-1][0], RcvMessageMaxSize);

		Status = Modbus_OK;
	}
	else
		Status = Modbus_ERR_WrongParams;

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

///*-----------------------------------------------------------*/
//
///* --- setting RTC
//*/
void SetRTC(uint8_t hour, uint8_t min, uint8_t sec)
{

	Hour = hour;
	Minute = min;
	Second = sec;
}
#endif
/************************ (C) COPYRIGHT HEXABITZ *****END OF FILE****/

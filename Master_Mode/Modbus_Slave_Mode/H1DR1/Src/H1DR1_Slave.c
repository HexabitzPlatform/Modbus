/*
    Copyright (C) 2017-2021 Hexabitz
    All rights reserved

    File Name     : Modmus.c
    Description   : Source code for Modbus slave module.
										RS-485 Serial Transceiver (MAX14840EASA+)
		
		Required MCU resources : 
		
			>> USARTs 2,3,4,5,6 for module ports.
			>> USART 1 for MAX14840EASA+.
			>> PA12 for RE/DE (receiver output enable).
			>> TIM2 for counting external pulses from water meter.
			
*/
	
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#if (Modbus_Mode==MODBUS_SLAVE)
#include "H1DR1_Slave.h"
#include <string.h>
#include "mbs_Slave.h"

/* Private variables ---------------------------------------------------------*/
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;
extern UART_HandleTypeDef huart4;
extern UART_HandleTypeDef huart5;
extern UART_HandleTypeDef huart6;
extern TIM_HandleTypeDef htim2;
extern CRC_HandleTypeDef hcrc;

TimerHandle_t zTimer = NULL;

uint8_t Second;
uint8_t Minute;
uint8_t Hour;

extern xMBSHandle xModmus;
uint8_t Src_port;
uint32_t Br_baud_rate;
uint32_t Parity_bit;
uint8_t Slave_add;
uint16_t Reg_address;
uint16_t Nu_regiters;
unsigned short ReadBuffer[253]={0};
unsigned short WriteBuffer;

uint8_t RcvMessage[NumOfPorts][RcvMessageMaxSize];
 unsigned short usRegHoldingValue[NUMBER_OF_REGISTERS];
//float x = 822.5;
float x = 257.9;

/* Private function prototypes -----------------------------------------------*/	 
static void RTC_HandleTimer(TimerHandle_t zTimer);

uint32_t c ;
float g ;
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

/* --- EMS module initialization. 
*/
void Module_Init(void)
{

	/* System Clock Configuration */
	SystemClock_Config();

	/* Peripherals Init */
	MX_GPIO_Init();
	MX_DMA_Init();
	MX_CRC_Init();

//  MX_TIM2_Init();
//	HAL_TIM_Base_Start(&htim2);
	
	/* Array ports */
	MX_USART1_UART_Init();
	MX_USART2_UART_Init();
	MX_USART3_UART_Init();
	MX_USART4_UART_Init();
	MX_USART5_UART_Init();
	MX_USART6_UART_Init();
	
//	/* RS485 port */
//	RS485_DE_RE_Init();
//	RS485_RECEIVER_EN();
	
	/* Definition and creation of software timers */
	zTimer = xTimerCreate( "Measuremet_Timer", pdMS_TO_TICKS(1000), pdTRUE, ( void * ) TIMERID_RTC_TIMER, RTC_HandleTimer );	
	xTimerStart( zTimer, portMAX_DELAY );

	/* Initializing DMA recieve */ 
	HAL_UART_Receive_DMA(P1uart, &RcvMessage[0][0], RcvMessageMaxSize);
	HAL_UART_Receive_DMA(P2uart, &RcvMessage[1][0], RcvMessageMaxSize);
	HAL_UART_Receive_DMA(P3uart, &RcvMessage[2][0], RcvMessageMaxSize);
	HAL_UART_Receive_DMA(P4uart, &RcvMessage[3][0], RcvMessageMaxSize);
	HAL_UART_Receive_DMA(P5uart, &RcvMessage[4][0], RcvMessageMaxSize);


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



/* -----------------------------------------------------------------------
	|																APIs	 																 	|
   ----------------------------------------------------------------------- */

/* --- Sample time for meter measurement software timer
*/
static void RTC_HandleTimer(TimerHandle_t zTimer)
{
	uint32_t Timer_ID = 0;
	
	Timer_ID = ( uint32_t ) pvTimerGetTimerID( zTimer );
  if (TIMERID_RTC_TIMER == Timer_ID)
  {
		Second++;
		if(Second==60){
			Second=0;
			Minute++;
		}
		
		if(Minute==60){
		Minute=0;
		Hour++;
		}

	}
}

/*-----------------------------------------------------------*/

/* --- send data packet from port
*/


/*-----------------------------------------------------------*/


/************************ (C) COPYRIGHT HEXABITZ *****END OF FILE****/
#endif

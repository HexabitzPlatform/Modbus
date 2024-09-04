/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f0xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f0xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
extern void     prvvMBPUSART1_TC_ISR( void );
extern void     prvvMBPUSART1_RXNE_ISR( void );

void vApplicationStackOverflowHook( TaskHandle_t xTask, char *pcTaskName );

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern DMA_HandleTypeDef hdma_usart1_rx;
extern DMA_HandleTypeDef hdma_usart1_tx;
//extern DMA_HandleTypeDef hdma_usart2_rx;
//extern DMA_HandleTypeDef hdma_usart2_tx;
//extern DMA_HandleTypeDef hdma_usart3_rx;
//extern DMA_HandleTypeDef hdma_usart3_tx;
//extern DMA_HandleTypeDef hdma_usart4_rx;
//extern DMA_HandleTypeDef hdma_usart4_tx;
//extern DMA_HandleTypeDef hdma_usart5_rx;
//extern DMA_HandleTypeDef hdma_usart5_tx;
//extern DMA_HandleTypeDef hdma_usart6_rx;
//extern DMA_HandleTypeDef hdma_usart6_tx;
extern UART_HandleTypeDef huart1;
//extern UART_HandleTypeDef huart2;
//extern UART_HandleTypeDef huart3;
//extern UART_HandleTypeDef huart4;
//extern UART_HandleTypeDef huart5;
//extern UART_HandleTypeDef huart6;
extern TIM_HandleTypeDef htim16;

/* USER CODE BEGIN EV */
extern struct rxMessaging_TypeDef rxMessaging;
/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M0 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */

  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/******************************************************************************/
/* STM32F0xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f0xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles PVD and VDDIO2 supply comparator interrupts through EXTI lines 16 and 31.
  */
void PVD_VDDIO2_IRQHandler(void)
{
  /* USER CODE BEGIN PVD_VDDIO2_IRQn 0 */

  /* USER CODE END PVD_VDDIO2_IRQn 0 */
  HAL_PWR_PVD_IRQHandler();
  HAL_PWREx_Vddio2Monitor_IRQHandler();
  /* USER CODE BEGIN PVD_VDDIO2_IRQn 1 */

  /* USER CODE END PVD_VDDIO2_IRQn 1 */
}

/**
  * @brief This function handles Flash global interrupt.
  */
void FLASH_IRQHandler(void)
{
  /* USER CODE BEGIN FLASH_IRQn 0 */

  /* USER CODE END FLASH_IRQn 0 */
  HAL_FLASH_IRQHandler();
  /* USER CODE BEGIN FLASH_IRQn 1 */

  /* USER CODE END FLASH_IRQn 1 */
}

/**
  * @brief This function handles RCC and CRS global interrupts.
  */
void RCC_CRS_IRQHandler(void)
{
  /* USER CODE BEGIN RCC_CRS_IRQn 0 */

  /* USER CODE END RCC_CRS_IRQn 0 */
  /* USER CODE BEGIN RCC_CRS_IRQn 1 */

  /* USER CODE END RCC_CRS_IRQn 1 */
}

/**
  * @brief This function handles DMA1 channel 1 interrupt.
  */
void DMA1_Ch1_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Ch1_IRQn 0 */
//
  /* USER CODE END DMA1_Ch1_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_usart1_rx);
  /* USER CODE BEGIN DMA1_Ch1_IRQn 1 */
//
  /* USER CODE END DMA1_Ch1_IRQn 1 */
}

/**
  * @brief This function handles DMA1 channel 2 to 3 and DMA2 channel 1 to 2 interrupts.
  */
void DMA1_Ch2_3_DMA2_Ch1_2_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Ch2_3_DMA2_Ch1_2_IRQn 0 */

  /* USER CODE END DMA1_Ch2_3_DMA2_Ch1_2_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_usart1_tx);
//  HAL_DMA_IRQHandler(&hdma_usart2_rx);
//  HAL_DMA_IRQHandler(&hdma_usart4_tx);
//  HAL_DMA_IRQHandler(&hdma_usart5_rx);
  /* USER CODE BEGIN DMA1_Ch2_3_DMA2_Ch1_2_IRQn 1 */

  /* USER CODE END DMA1_Ch2_3_DMA2_Ch1_2_IRQn 1 */
}

/**
  * @brief This function handles DMA1 channel 4 to 7 and DMA2 channel 3 to 5 interrupts.
  */
//void DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler(void)
//{
//  /* USER CODE BEGIN DMA1_Ch4_7_DMA2_Ch3_5_IRQn 0 */
//
//  /* USER CODE END DMA1_Ch4_7_DMA2_Ch3_5_IRQn 0 */
//  HAL_DMA_IRQHandler(&hdma_usart2_tx);
//  HAL_DMA_IRQHandler(&hdma_usart3_rx);
//  HAL_DMA_IRQHandler(&hdma_usart4_rx);
//  HAL_DMA_IRQHandler(&hdma_usart3_tx);
//  HAL_DMA_IRQHandler(&hdma_usart6_rx);
//  HAL_DMA_IRQHandler(&hdma_usart5_tx);
//  HAL_DMA_IRQHandler(&hdma_usart6_tx);
//  /* USER CODE BEGIN DMA1_Ch4_7_DMA2_Ch3_5_IRQn 1 */
//
//  /* USER CODE END DMA1_Ch4_7_DMA2_Ch3_5_IRQn 1 */
//}

/**
  * @brief This function handles TIM16 global interrupt.
  */
void TIM16_IRQHandler(void)
{
  /* USER CODE BEGIN TIM16_IRQn 0 */

  /* USER CODE END TIM16_IRQn 0 */
  HAL_TIM_IRQHandler(&htim16);
  /* USER CODE BEGIN TIM16_IRQn 1 */

  /* USER CODE END TIM16_IRQn 1 */
}

/**
  * @brief This function handles USART1 global interrupt / USART1 wake-up interrupt through EXTI line 25.
  */
void USART1_IRQHandler(void)
{
  /* USER CODE BEGIN USART1_IRQn 0 */
	portBASE_TYPE xHigherPriorityTaskWoken = pdFALSE;
  /* USER CODE END USART1_IRQn 0 */
  HAL_UART_IRQHandler(&huart1);
  /* USER CODE BEGIN USART1_IRQn 1 */
	portEND_SWITCHING_ISR( xHigherPriorityTaskWoken );
  /* USER CODE END USART1_IRQn 1 */
}

/**
  * @brief This function handles USART2 global interrupt / USART2 wake-up interrupt through EXTI line 26.
  */
//void USART2_IRQHandler(void)
//{
//  /* USER CODE BEGIN USART2_IRQn 0 */
//
//  /* USER CODE END USART2_IRQn 0 */
//  HAL_UART_IRQHandler(&huart2);
//  /* USER CODE BEGIN USART2_IRQn 1 */
//
//  /* USER CODE END USART2_IRQn 1 */
//}

/**
  * @brief This function handles USART3 to USART8 global interrupts / USART3 wake-up interrupt through EXTI line 28.
  */
//void USART3_8_IRQHandler(void)
//{
//  /* USER CODE BEGIN USART3_8_IRQn 0 */
//
//  /* USER CODE END USART3_8_IRQn 0 */
//  HAL_UART_IRQHandler(&huart3);
//  HAL_UART_IRQHandler(&huart4);
//  HAL_UART_IRQHandler(&huart5);
//  HAL_UART_IRQHandler(&huart6);
//  /* USER CODE BEGIN USART3_8_IRQn 1 */
//
//  /* USER CODE END USART3_8_IRQn 1 */
//}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

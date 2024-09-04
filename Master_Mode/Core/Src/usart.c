/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    usart.c
  * @brief   This file provides code for the configuration
  *          of the USART instances.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "usart.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

UART_HandleTypeDef huart1;
//UART_HandleTypeDef huart2;
//UART_HandleTypeDef huart3;
//UART_HandleTypeDef huart4;
//UART_HandleTypeDef huart5;
//UART_HandleTypeDef huart6;
DMA_HandleTypeDef hdma_usart1_rx;
DMA_HandleTypeDef hdma_usart1_tx;
//DMA_HandleTypeDef hdma_usart2_rx;
//DMA_HandleTypeDef hdma_usart2_tx;
//DMA_HandleTypeDef hdma_usart3_rx;
//DMA_HandleTypeDef hdma_usart3_tx;
//DMA_HandleTypeDef hdma_usart4_rx;
//DMA_HandleTypeDef hdma_usart4_tx;
//DMA_HandleTypeDef hdma_usart5_rx;
//DMA_HandleTypeDef hdma_usart5_tx;
//DMA_HandleTypeDef hdma_usart6_rx;
//DMA_HandleTypeDef hdma_usart6_tx;

/* USART1 init function */

void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_RXOVERRUNDISABLE_INIT;
  huart1.AdvancedInit.OverrunDisable = UART_ADVFEATURE_OVERRUN_DISABLE;
  if (HAL_RS485Ex_Init(&huart1, UART_DE_POLARITY_HIGH, 0, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */


  /* USER CODE END USART1_Init 2 */

}
///* USART2 init function */
//
//void MX_USART2_UART_Init(void)
//{
//
//  /* USER CODE BEGIN USART2_Init 0 */
//
//  /* USER CODE END USART2_Init 0 */
//
//  /* USER CODE BEGIN USART2_Init 1 */
//
//  /* USER CODE END USART2_Init 1 */
//  huart2.Instance = USART2;
//  huart2.Init.BaudRate = 921600;
//  huart2.Init.WordLength = UART_WORDLENGTH_8B;
//  huart2.Init.StopBits = UART_STOPBITS_1;
//  huart2.Init.Parity = UART_PARITY_NONE;
//  huart2.Init.Mode = UART_MODE_TX_RX;
//  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
//  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
//  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
//  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_RXOVERRUNDISABLE_INIT;
//  huart2.AdvancedInit.OverrunDisable = UART_ADVFEATURE_OVERRUN_DISABLE;
//  if (HAL_UART_Init(&huart2) != HAL_OK)
//  {
//    Error_Handler();
//  }
//  /* USER CODE BEGIN USART2_Init 2 */
//
//  /* USER CODE END USART2_Init 2 */
//
//}
///* USART3 init function */
//
//void MX_USART3_UART_Init(void)
//{
//
//  /* USER CODE BEGIN USART3_Init 0 */
//
//  /* USER CODE END USART3_Init 0 */
//
//  /* USER CODE BEGIN USART3_Init 1 */
//
//  /* USER CODE END USART3_Init 1 */
//  huart3.Instance = USART3;
//  huart3.Init.BaudRate = 921600;
//  huart3.Init.WordLength = UART_WORDLENGTH_8B;
//  huart3.Init.StopBits = UART_STOPBITS_1;
//  huart3.Init.Parity = UART_PARITY_NONE;
//  huart3.Init.Mode = UART_MODE_TX_RX;
//  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
//  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
//  huart3.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
//  huart3.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_RXOVERRUNDISABLE_INIT;
//  huart3.AdvancedInit.OverrunDisable = UART_ADVFEATURE_OVERRUN_DISABLE;
//  if (HAL_UART_Init(&huart3) != HAL_OK)
//  {
//    Error_Handler();
//  }
//  /* USER CODE BEGIN USART3_Init 2 */
//
//  /* USER CODE END USART3_Init 2 */
//
//}
///* USART4 init function */
//
//void MX_USART4_UART_Init(void)
//{
//
//  /* USER CODE BEGIN USART4_Init 0 */
//
//  /* USER CODE END USART4_Init 0 */
//
//  /* USER CODE BEGIN USART4_Init 1 */
//
//  /* USER CODE END USART4_Init 1 */
//  huart4.Instance = USART4;
//  huart4.Init.BaudRate = 921600;
//  huart4.Init.WordLength = UART_WORDLENGTH_8B;
//  huart4.Init.StopBits = UART_STOPBITS_1;
//  huart4.Init.Parity = UART_PARITY_NONE;
//  huart4.Init.Mode = UART_MODE_TX_RX;
//  huart4.Init.HwFlowCtl = UART_HWCONTROL_NONE;
//  huart4.Init.OverSampling = UART_OVERSAMPLING_16;
//  huart4.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
//  huart4.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_RXOVERRUNDISABLE_INIT;
//  huart4.AdvancedInit.OverrunDisable = UART_ADVFEATURE_OVERRUN_DISABLE;
//  if (HAL_UART_Init(&huart4) != HAL_OK)
//  {
//    Error_Handler();
//  }
//  /* USER CODE BEGIN USART4_Init 2 */
//
//  /* USER CODE END USART4_Init 2 */
//
//}
///* USART5 init function */
//
//void MX_USART5_UART_Init(void)
//{
//
//  /* USER CODE BEGIN USART5_Init 0 */
//
//  /* USER CODE END USART5_Init 0 */
//
//  /* USER CODE BEGIN USART5_Init 1 */
//
//  /* USER CODE END USART5_Init 1 */
//  huart5.Instance = USART5;
//  huart5.Init.BaudRate = 921600;
//  huart5.Init.WordLength = UART_WORDLENGTH_8B;
//  huart5.Init.StopBits = UART_STOPBITS_1;
//  huart5.Init.Parity = UART_PARITY_NONE;
//  huart5.Init.Mode = UART_MODE_TX_RX;
//  huart5.Init.HwFlowCtl = UART_HWCONTROL_NONE;
//  huart5.Init.OverSampling = UART_OVERSAMPLING_16;
//  huart5.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
//  huart5.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_RXOVERRUNDISABLE_INIT;
//  huart5.AdvancedInit.OverrunDisable = UART_ADVFEATURE_OVERRUN_DISABLE;
//  if (HAL_UART_Init(&huart5) != HAL_OK)
//  {
//    Error_Handler();
//  }
//  /* USER CODE BEGIN USART5_Init 2 */
//
//  /* USER CODE END USART5_Init 2 */
//
//}
///* USART6 init function */
//
//void MX_USART6_UART_Init(void)
//{
//
//  /* USER CODE BEGIN USART6_Init 0 */
//
//  /* USER CODE END USART6_Init 0 */
//
//  /* USER CODE BEGIN USART6_Init 1 */
//
//  /* USER CODE END USART6_Init 1 */
//  huart6.Instance = USART6;
//  huart6.Init.BaudRate = 921600;
//  huart6.Init.WordLength = UART_WORDLENGTH_8B;
//  huart6.Init.StopBits = UART_STOPBITS_1;
//  huart6.Init.Parity = UART_PARITY_NONE;
//  huart6.Init.Mode = UART_MODE_TX_RX;
//  huart6.Init.HwFlowCtl = UART_HWCONTROL_NONE;
//  huart6.Init.OverSampling = UART_OVERSAMPLING_16;
//  huart6.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
//  huart6.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_RXOVERRUNDISABLE_INIT;
//  huart6.AdvancedInit.OverrunDisable = UART_ADVFEATURE_OVERRUN_DISABLE;
//  if (HAL_UART_Init(&huart6) != HAL_OK)
//  {
//    Error_Handler();
//  }
//  /* USER CODE BEGIN USART6_Init 2 */
//
//  /* USER CODE END USART6_Init 2 */
//
//}

void HAL_UART_MspInit(UART_HandleTypeDef* uartHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspInit 0 */

  /* USER CODE END USART1_MspInit 0 */
    /* USART1 clock enable */
    __HAL_RCC_USART1_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**USART1 GPIO Configuration
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX
    PA12     ------> USART1_DE
    */
    GPIO_InitStruct.Pin = GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_12;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF1_USART1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* USART1 DMA Init */
    /* USART1_RX Init */
    hdma_usart1_rx.Instance = DMA1_Channel1;
    hdma_usart1_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
    hdma_usart1_rx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_usart1_rx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_usart1_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_WORD;
    hdma_usart1_rx.Init.MemDataAlignment = DMA_MDATAALIGN_WORD;
    hdma_usart1_rx.Init.Mode = DMA_CIRCULAR;
    hdma_usart1_rx.Init.Priority = DMA_PRIORITY_LOW;
    if (HAL_DMA_Init(&hdma_usart1_rx) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_DMA1_REMAP(HAL_DMA1_CH1_USART1_RX);

    __HAL_LINKDMA(uartHandle,hdmarx,hdma_usart1_rx);

    /* USART1_TX Init */
    hdma_usart1_tx.Instance = DMA1_Channel2;
    hdma_usart1_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
    hdma_usart1_tx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_usart1_tx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_usart1_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_WORD;
    hdma_usart1_tx.Init.MemDataAlignment = DMA_MDATAALIGN_WORD;
    hdma_usart1_tx.Init.Mode = DMA_CIRCULAR;
    hdma_usart1_tx.Init.Priority = DMA_PRIORITY_LOW;
    if (HAL_DMA_Init(&hdma_usart1_tx) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_DMA1_REMAP(HAL_DMA1_CH2_USART1_TX);

    __HAL_LINKDMA(uartHandle,hdmatx,hdma_usart1_tx);

    /* USART1 interrupt Init */
    HAL_NVIC_SetPriority(USART1_IRQn, 3, 0);
    HAL_NVIC_EnableIRQ(USART1_IRQn);
  /* USER CODE BEGIN USART1_MspInit 1 */

  /* USER CODE END USART1_MspInit 1 */
  }
//  else if(uartHandle->Instance==USART2)
//  {
//  /* USER CODE BEGIN USART2_MspInit 0 */
//
//  /* USER CODE END USART2_MspInit 0 */
//    /* USART2 clock enable */
//    __HAL_RCC_USART2_CLK_ENABLE();
//
//    __HAL_RCC_GPIOA_CLK_ENABLE();
//    /**USART2 GPIO Configuration
//    PA2     ------> USART2_TX
//    PA3     ------> USART2_RX
//    */
//    GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3;
//    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
//    GPIO_InitStruct.Pull = GPIO_NOPULL;
//    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
//    GPIO_InitStruct.Alternate = GPIO_AF1_USART2;
//    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
//
//    /* USART2 DMA Init */
//    /* USART2_RX Init */
//    hdma_usart2_rx.Instance = DMA1_Channel3;
//    hdma_usart2_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
//    hdma_usart2_rx.Init.PeriphInc = DMA_PINC_DISABLE;
//    hdma_usart2_rx.Init.MemInc = DMA_MINC_ENABLE;
//    hdma_usart2_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
//    hdma_usart2_rx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
//    hdma_usart2_rx.Init.Mode = DMA_NORMAL;
//    hdma_usart2_rx.Init.Priority = DMA_PRIORITY_LOW;
//    if (HAL_DMA_Init(&hdma_usart2_rx) != HAL_OK)
//    {
//      Error_Handler();
//    }
//
//    __HAL_DMA1_REMAP(HAL_DMA1_CH3_USART2_RX);
//
//    __HAL_LINKDMA(uartHandle,hdmarx,hdma_usart2_rx);
//
//    /* USART2_TX Init */
//    hdma_usart2_tx.Instance = DMA1_Channel4;
//    hdma_usart2_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
//    hdma_usart2_tx.Init.PeriphInc = DMA_PINC_DISABLE;
//    hdma_usart2_tx.Init.MemInc = DMA_MINC_ENABLE;
//    hdma_usart2_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
//    hdma_usart2_tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
//    hdma_usart2_tx.Init.Mode = DMA_NORMAL;
//    hdma_usart2_tx.Init.Priority = DMA_PRIORITY_LOW;
//    if (HAL_DMA_Init(&hdma_usart2_tx) != HAL_OK)
//    {
//      Error_Handler();
//    }
//
//    __HAL_DMA1_REMAP(HAL_DMA1_CH4_USART2_TX);
//
//    __HAL_LINKDMA(uartHandle,hdmatx,hdma_usart2_tx);
//
//    /* USART2 interrupt Init */
//    HAL_NVIC_SetPriority(USART2_IRQn, 3, 0);
//    HAL_NVIC_EnableIRQ(USART2_IRQn);
//  /* USER CODE BEGIN USART2_MspInit 1 */
//
//  /* USER CODE END USART2_MspInit 1 */
//  }
//  else if(uartHandle->Instance==USART3)
//  {
//  /* USER CODE BEGIN USART3_MspInit 0 */
//
//  /* USER CODE END USART3_MspInit 0 */
//    /* USART3 clock enable */
//    __HAL_RCC_USART3_CLK_ENABLE();
//
//    __HAL_RCC_GPIOB_CLK_ENABLE();
//    /**USART3 GPIO Configuration
//    PB10     ------> USART3_TX
//    PB11     ------> USART3_RX
//    */
//    GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_11;
//    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
//    GPIO_InitStruct.Pull = GPIO_NOPULL;
//    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
//    GPIO_InitStruct.Alternate = GPIO_AF4_USART3;
//    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
//
//    /* USART3 DMA Init */
//    /* USART3_RX Init */
//    hdma_usart3_rx.Instance = DMA1_Channel5;
//    hdma_usart3_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
//    hdma_usart3_rx.Init.PeriphInc = DMA_PINC_DISABLE;
//    hdma_usart3_rx.Init.MemInc = DMA_MINC_ENABLE;
//    hdma_usart3_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
//    hdma_usart3_rx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
//    hdma_usart3_rx.Init.Mode = DMA_NORMAL;
//    hdma_usart3_rx.Init.Priority = DMA_PRIORITY_LOW;
//    if (HAL_DMA_Init(&hdma_usart3_rx) != HAL_OK)
//    {
//      Error_Handler();
//    }
//
//    __HAL_DMA1_REMAP(HAL_DMA1_CH5_USART3_RX);
//
//    __HAL_LINKDMA(uartHandle,hdmarx,hdma_usart3_rx);
//
//    /* USART3_TX Init */
//    hdma_usart3_tx.Instance = DMA1_Channel7;
//    hdma_usart3_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
//    hdma_usart3_tx.Init.PeriphInc = DMA_PINC_DISABLE;
//    hdma_usart3_tx.Init.MemInc = DMA_MINC_ENABLE;
//    hdma_usart3_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
//    hdma_usart3_tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
//    hdma_usart3_tx.Init.Mode = DMA_NORMAL;
//    hdma_usart3_tx.Init.Priority = DMA_PRIORITY_LOW;
//    if (HAL_DMA_Init(&hdma_usart3_tx) != HAL_OK)
//    {
//      Error_Handler();
//    }
//
//    __HAL_DMA1_REMAP(HAL_DMA1_CH7_USART3_TX);
//
//    __HAL_LINKDMA(uartHandle,hdmatx,hdma_usart3_tx);
//
//    /* USART3 interrupt Init */
//    HAL_NVIC_SetPriority(USART3_8_IRQn, 3, 0);
//    HAL_NVIC_EnableIRQ(USART3_8_IRQn);
//  /* USER CODE BEGIN USART3_MspInit 1 */
//
//  /* USER CODE END USART3_MspInit 1 */
//  }
//  else if(uartHandle->Instance==USART4)
//  {
//  /* USER CODE BEGIN USART4_MspInit 0 */
//
//  /* USER CODE END USART4_MspInit 0 */
//    /* USART4 clock enable */
//    __HAL_RCC_USART4_CLK_ENABLE();
//
//    __HAL_RCC_GPIOA_CLK_ENABLE();
//    /**USART4 GPIO Configuration
//    PA0     ------> USART4_TX
//    PA1     ------> USART4_RX
//    */
//    GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1;
//    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
//    GPIO_InitStruct.Pull = GPIO_NOPULL;
//    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
//    GPIO_InitStruct.Alternate = GPIO_AF4_USART4;
//    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
//
//    /* USART4 DMA Init */
//    /* USART4_RX Init */
//    hdma_usart4_rx.Instance = DMA1_Channel6;
//    hdma_usart4_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
//    hdma_usart4_rx.Init.PeriphInc = DMA_PINC_DISABLE;
//    hdma_usart4_rx.Init.MemInc = DMA_MINC_ENABLE;
//    hdma_usart4_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
//    hdma_usart4_rx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
//    hdma_usart4_rx.Init.Mode = DMA_NORMAL;
//    hdma_usart4_rx.Init.Priority = DMA_PRIORITY_LOW;
//    if (HAL_DMA_Init(&hdma_usart4_rx) != HAL_OK)
//    {
//      Error_Handler();
//    }
//
//    __HAL_DMA1_REMAP(HAL_DMA1_CH6_USART4_RX);
//
//    __HAL_LINKDMA(uartHandle,hdmarx,hdma_usart4_rx);
//
//    /* USART4_TX Init */
//    hdma_usart4_tx.Instance = DMA2_Channel1;
//    hdma_usart4_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
//    hdma_usart4_tx.Init.PeriphInc = DMA_PINC_DISABLE;
//    hdma_usart4_tx.Init.MemInc = DMA_MINC_ENABLE;
//    hdma_usart4_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
//    hdma_usart4_tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
//    hdma_usart4_tx.Init.Mode = DMA_NORMAL;
//    hdma_usart4_tx.Init.Priority = DMA_PRIORITY_LOW;
//    if (HAL_DMA_Init(&hdma_usart4_tx) != HAL_OK)
//    {
//      Error_Handler();
//    }
//
//    __HAL_DMA2_REMAP(HAL_DMA2_CH1_USART4_TX);
//
//    __HAL_LINKDMA(uartHandle,hdmatx,hdma_usart4_tx);
//
//    /* USART4 interrupt Init */
//    HAL_NVIC_SetPriority(USART3_8_IRQn, 3, 0);
//    HAL_NVIC_EnableIRQ(USART3_8_IRQn);
//  /* USER CODE BEGIN USART4_MspInit 1 */
//
//  /* USER CODE END USART4_MspInit 1 */
//  }
//  else if(uartHandle->Instance==USART5)
//  {
//  /* USER CODE BEGIN USART5_MspInit 0 */
//
//  /* USER CODE END USART5_MspInit 0 */
//    /* USART5 clock enable */
//    __HAL_RCC_USART5_CLK_ENABLE();
//
//    __HAL_RCC_GPIOB_CLK_ENABLE();
//    /**USART5 GPIO Configuration
//    PB3     ------> USART5_TX
//    PB4     ------> USART5_RX
//    */
//    GPIO_InitStruct.Pin = GPIO_PIN_3|GPIO_PIN_4;
//    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
//    GPIO_InitStruct.Pull = GPIO_NOPULL;
//    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
//    GPIO_InitStruct.Alternate = GPIO_AF4_USART5;
//    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
//
//    /* USART5 DMA Init */
//    /* USART5_RX Init */
//    hdma_usart5_rx.Instance = DMA2_Channel2;
//    hdma_usart5_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
//    hdma_usart5_rx.Init.PeriphInc = DMA_PINC_DISABLE;
//    hdma_usart5_rx.Init.MemInc = DMA_MINC_ENABLE;
//    hdma_usart5_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
//    hdma_usart5_rx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
//    hdma_usart5_rx.Init.Mode = DMA_NORMAL;
//    hdma_usart5_rx.Init.Priority = DMA_PRIORITY_LOW;
//    if (HAL_DMA_Init(&hdma_usart5_rx) != HAL_OK)
//    {
//      Error_Handler();
//    }
//
//    __HAL_DMA2_REMAP(HAL_DMA2_CH2_USART5_RX);
//
//    __HAL_LINKDMA(uartHandle,hdmarx,hdma_usart5_rx);
//
//    /* USART5_TX Init */
//    hdma_usart5_tx.Instance = DMA2_Channel4;
//    hdma_usart5_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
//    hdma_usart5_tx.Init.PeriphInc = DMA_PINC_DISABLE;
//    hdma_usart5_tx.Init.MemInc = DMA_MINC_ENABLE;
//    hdma_usart5_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
//    hdma_usart5_tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
//    hdma_usart5_tx.Init.Mode = DMA_NORMAL;
//    hdma_usart5_tx.Init.Priority = DMA_PRIORITY_LOW;
//    if (HAL_DMA_Init(&hdma_usart5_tx) != HAL_OK)
//    {
//      Error_Handler();
//    }
//
//    __HAL_DMA2_REMAP(HAL_DMA2_CH4_USART5_TX);
//
//    __HAL_LINKDMA(uartHandle,hdmatx,hdma_usart5_tx);
//
//    /* USART5 interrupt Init */
//    HAL_NVIC_SetPriority(USART3_8_IRQn, 3, 0);
//    HAL_NVIC_EnableIRQ(USART3_8_IRQn);
//  /* USER CODE BEGIN USART5_MspInit 1 */
//
//  /* USER CODE END USART5_MspInit 1 */
//  }
//  else if(uartHandle->Instance==USART6)
//  {
//  /* USER CODE BEGIN USART6_MspInit 0 */
//
//  /* USER CODE END USART6_MspInit 0 */
//    /* USART6 clock enable */
//    __HAL_RCC_USART6_CLK_ENABLE();
//
//    __HAL_RCC_GPIOA_CLK_ENABLE();
//    /**USART6 GPIO Configuration
//    PA4     ------> USART6_TX
//    PA5     ------> USART6_RX
//    */
//    GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_5;
//    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
//    GPIO_InitStruct.Pull = GPIO_NOPULL;
//    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
//    GPIO_InitStruct.Alternate = GPIO_AF5_USART6;
//    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
//
//    /* USART6 DMA Init */
//    /* USART6_RX Init */
//    hdma_usart6_rx.Instance = DMA2_Channel3;
//    hdma_usart6_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
//    hdma_usart6_rx.Init.PeriphInc = DMA_PINC_DISABLE;
//    hdma_usart6_rx.Init.MemInc = DMA_MINC_ENABLE;
//    hdma_usart6_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
//    hdma_usart6_rx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
//    hdma_usart6_rx.Init.Mode = DMA_NORMAL;
//    hdma_usart6_rx.Init.Priority = DMA_PRIORITY_LOW;
//    if (HAL_DMA_Init(&hdma_usart6_rx) != HAL_OK)
//    {
//      Error_Handler();
//    }
//
//    __HAL_DMA2_REMAP(HAL_DMA2_CH3_USART6_RX);
//
//    __HAL_LINKDMA(uartHandle,hdmarx,hdma_usart6_rx);
//
//    /* USART6_TX Init */
//    hdma_usart6_tx.Instance = DMA2_Channel5;
//    hdma_usart6_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
//    hdma_usart6_tx.Init.PeriphInc = DMA_PINC_DISABLE;
//    hdma_usart6_tx.Init.MemInc = DMA_MINC_ENABLE;
//    hdma_usart6_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
//    hdma_usart6_tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
//    hdma_usart6_tx.Init.Mode = DMA_NORMAL;
//    hdma_usart6_tx.Init.Priority = DMA_PRIORITY_LOW;
//    if (HAL_DMA_Init(&hdma_usart6_tx) != HAL_OK)
//    {
//      Error_Handler();
//    }

//    __HAL_DMA2_REMAP(HAL_DMA2_CH5_USART6_TX);
//
//    __HAL_LINKDMA(uartHandle,hdmatx,hdma_usart6_tx);
//
//    /* USART6 interrupt Init */
//    HAL_NVIC_SetPriority(USART3_8_IRQn, 3, 0);
//    HAL_NVIC_EnableIRQ(USART3_8_IRQn);
  /* USER CODE BEGIN USART6_MspInit 1 */

  /* USER CODE END USART6_MspInit 1 */
  }


void HAL_UART_MspDeInit(UART_HandleTypeDef* uartHandle)
{

  if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspDeInit 0 */

  /* USER CODE END USART1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART1_CLK_DISABLE();

    /**USART1 GPIO Configuration
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX
    PA12     ------> USART1_DE
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_12);

    /* USART1 DMA DeInit */
    HAL_DMA_DeInit(uartHandle->hdmarx);
    HAL_DMA_DeInit(uartHandle->hdmatx);

    /* USART1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART1_IRQn);
  /* USER CODE BEGIN USART1_MspDeInit 1 */

  /* USER CODE END USART1_MspDeInit 1 */
  }
//  else if(uartHandle->Instance==USART2)
//  {
//  /* USER CODE BEGIN USART2_MspDeInit 0 */
//
//  /* USER CODE END USART2_MspDeInit 0 */
//    /* Peripheral clock disable */
//    __HAL_RCC_USART2_CLK_DISABLE();
//
//    /**USART2 GPIO Configuration
//    PA2     ------> USART2_TX
//    PA3     ------> USART2_RX
//    */
//    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_2|GPIO_PIN_3);
//
//    /* USART2 DMA DeInit */
//    HAL_DMA_DeInit(uartHandle->hdmarx);
//    HAL_DMA_DeInit(uartHandle->hdmatx);
//
//    /* USART2 interrupt Deinit */
//    HAL_NVIC_DisableIRQ(USART2_IRQn);
//  /* USER CODE BEGIN USART2_MspDeInit 1 */
//
//  /* USER CODE END USART2_MspDeInit 1 */
//  }
//  else if(uartHandle->Instance==USART3)
//  {
//  /* USER CODE BEGIN USART3_MspDeInit 0 */
//
//  /* USER CODE END USART3_MspDeInit 0 */
//    /* Peripheral clock disable */
//    __HAL_RCC_USART3_CLK_DISABLE();
//
//    /**USART3 GPIO Configuration
//    PB10     ------> USART3_TX
//    PB11     ------> USART3_RX
//    */
//    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_10|GPIO_PIN_11);
//
//    /* USART3 DMA DeInit */
//    HAL_DMA_DeInit(uartHandle->hdmarx);
//    HAL_DMA_DeInit(uartHandle->hdmatx);
//
//    /* USART3 interrupt Deinit */
//  /* USER CODE BEGIN USART3:USART3_8_IRQn disable */
//    /**
//    * Uncomment the line below to disable the "USART3_8_IRQn" interrupt
//    * Be aware, disabling shared interrupt may affect other IPs
//    */
//    /* HAL_NVIC_DisableIRQ(USART3_8_IRQn); */
//  /* USER CODE END USART3:USART3_8_IRQn disable */
//
//  /* USER CODE BEGIN USART3_MspDeInit 1 */
//
//  /* USER CODE END USART3_MspDeInit 1 */
//  }
//  else if(uartHandle->Instance==USART4)
//  {
//  /* USER CODE BEGIN USART4_MspDeInit 0 */
//
//  /* USER CODE END USART4_MspDeInit 0 */
//    /* Peripheral clock disable */
//    __HAL_RCC_USART4_CLK_DISABLE();
//
//    /**USART4 GPIO Configuration
//    PA0     ------> USART4_TX
//    PA1     ------> USART4_RX
//    */
//    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_0|GPIO_PIN_1);
//
//    /* USART4 DMA DeInit */
//    HAL_DMA_DeInit(uartHandle->hdmarx);
//    HAL_DMA_DeInit(uartHandle->hdmatx);
//
//    /* USART4 interrupt Deinit */
//  /* USER CODE BEGIN USART4:USART3_8_IRQn disable */
//    /**
//    * Uncomment the line below to disable the "USART3_8_IRQn" interrupt
//    * Be aware, disabling shared interrupt may affect other IPs
//    */
//    /* HAL_NVIC_DisableIRQ(USART3_8_IRQn); */
//  /* USER CODE END USART4:USART3_8_IRQn disable */
//
//  /* USER CODE BEGIN USART4_MspDeInit 1 */
//
//  /* USER CODE END USART4_MspDeInit 1 */
//  }
//  else if(uartHandle->Instance==USART5)
//  {
//  /* USER CODE BEGIN USART5_MspDeInit 0 */
//
//  /* USER CODE END USART5_MspDeInit 0 */
//    /* Peripheral clock disable */
//    __HAL_RCC_USART5_CLK_DISABLE();
//
//    /**USART5 GPIO Configuration
//    PB3     ------> USART5_TX
//    PB4     ------> USART5_RX
//    */
//    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_3|GPIO_PIN_4);
//
//    /* USART5 DMA DeInit */
//    HAL_DMA_DeInit(uartHandle->hdmarx);
//    HAL_DMA_DeInit(uartHandle->hdmatx);
//
//    /* USART5 interrupt Deinit */
//  /* USER CODE BEGIN USART5:USART3_8_IRQn disable */
//    /**
//    * Uncomment the line below to disable the "USART3_8_IRQn" interrupt
//    * Be aware, disabling shared interrupt may affect other IPs
//    */
//    /* HAL_NVIC_DisableIRQ(USART3_8_IRQn); */
//  /* USER CODE END USART5:USART3_8_IRQn disable */
//
//  /* USER CODE BEGIN USART5_MspDeInit 1 */
//
//  /* USER CODE END USART5_MspDeInit 1 */
//  }
//  else if(uartHandle->Instance==USART6)
//  {
//  /* USER CODE BEGIN USART6_MspDeInit 0 */
//
//  /* USER CODE END USART6_MspDeInit 0 */
//    /* Peripheral clock disable */
//    __HAL_RCC_USART6_CLK_DISABLE();
//
//    /**USART6 GPIO Configuration
//    PA4     ------> USART6_TX
//    PA5     ------> USART6_RX
//    */
//    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_4|GPIO_PIN_5);
//
//    /* USART6 DMA DeInit */
//    HAL_DMA_DeInit(uartHandle->hdmarx);
//    HAL_DMA_DeInit(uartHandle->hdmatx);

    /* USART6 interrupt Deinit */
  /* USER CODE BEGIN USART6:USART3_8_IRQn disable */
    /**
    * Uncomment the line below to disable the "USART3_8_IRQn" interrupt
    * Be aware, disabling shared interrupt may affect other IPs
    */
    /* HAL_NVIC_DisableIRQ(USART3_8_IRQn); */
  /* USER CODE END USART6:USART3_8_IRQn disable */

  /* USER CODE BEGIN USART6_MspDeInit 1 */

  /* USER CODE END USART6_MspDeInit 1 */
  }


/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

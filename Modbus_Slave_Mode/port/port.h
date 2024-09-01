/**
  ******************************************************************************
  * @file    port.h
  * @author  Motor Control Team, ST Microelectronics
  * @brief   FreeModbus Libary interface porting for STM32.
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics International N.V.
  * All rights reserved.</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice,
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other
  *    contributors to this software may be used to endorse or promote products
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under
  *    this license is void and will automatically terminate your rights under
  *    this license.
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

#ifndef __PORT_H
#define __PORT_H

/* Includes ------------------------------------------------------------------*/
#include <assert.h>


#include "main.h"
#define bool	_Bool
#define true	1
#define false	0
/* Exported types ------------------------------------------------------------*/
typedef bool BOOL;
typedef uint8_t UCHAR;
typedef int8_t CHAR;
typedef uint16_t USHORT;
typedef int16_t SHORT;
typedef uint32_t ULONG;
typedef int32_t LONG;

/* Exported macro ------------------------------------------------------------*/
#define ENTER_CRITICAL_SECTION() ( __disable_irq())      
#define EXIT_CRITICAL_SECTION() ( __enable_irq())    

#define RS485_DE_Pin GPIO_PIN_12
#define RS485_DE_GPIO_Port GPIOA

#define TRUE true
#define FALSE false

#define TIM_TIMEOUT TIM14
#define SERIAL_PORT USART1

#endif /* __PORT_H */

/************************ (C) COPYRIGHT 2019 STMicroelectronics *****END OF FILE****/

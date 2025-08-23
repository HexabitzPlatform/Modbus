/*
 * Port.h
 *
 *  Created on: Aug 23, 2025
 *      Author: MAHMOOD_REDA
 */

#ifndef INC_PORT_H_
#define INC_PORT_H_

#ifndef __PORT_H
#define __PORT_H

#include "main.h"
#include "usart.h"   // contains huart1..huart6

/* ============================================================
 ==============  CONFIGURATION SECTION  =====================
 Select which UART to use by enabling only one
 ============================================================ */
/* ----------------------- Defines ------------------------------------------*/
#define IDX_INVALID             ( 255 )
#define UART_BAUDRATE_MIN       ( 2400 )
#define UART_BAUDRATE_MAX       ( 115200 )
#define MBM_SER_PDU_SIZE_MAX    ( 256 )
#define UART_ENABLED            ( 1 )
#define UART_IDX                ( 0 )
#define NUARTS                  ( 1 )


/* ----------------------- Defines (Internal - Don't change) ----------------*/
#define HDL_RESET( x ) do { \
    ( x )->ubIdx = IDX_INVALID; \
    ( x )->pbMBMTransmitterEmptyFN = NULL; \
    ( x )->pvMBMReceiveFN = NULL; \
    ( x )->xMBMHdl = MB_HDL_INVALID; \
} while( 0 );

/* ============================================================
 ==============  UART SELECTION MACROS  =====================
 ============================================================ */

#define MB_UART_HANDLE      huart3
#define MB_UART_INSTANCE    USART3
#define MB_UART_INIT_FN()   MX_USART3_UART_Init()

/* ============================================================
 ==============  RS485 DIRECTION CONTROL  ===================
 Adjust pin according to your hardware
 ============================================================ */

#define MB_RS485_DE_PORT    GPIOA
#define MB_RS485_DE_PIN     GPIO_PIN_15

#define RS485_TX_ENABLE()   HAL_GPIO_WritePin(MB_RS485_DE_PORT, MB_RS485_DE_PIN, GPIO_PIN_SET)
#define RS485_TX_DISABLE()  HAL_GPIO_WritePin(MB_RS485_DE_PORT, MB_RS485_DE_PIN, GPIO_PIN_RESET)

#endif /* __PORT_H */

#endif /* INC_PORT_H_ */

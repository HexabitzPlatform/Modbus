/*
    Copyright (C) 2017-2020 Hexabitz
    All rights reserved
		
    File Name     : Modbus.h
    Description   : Header file for Modbus module.
										RS-485 Serial Transceiver (MAX14840EASA+)
*/
	
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __H1DR1_MASTER_H
#define __H1DR1_MASTER_H
#include "main.h"
#if (Modbus_Mode==MODBUS_MASTER)
#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"	
#include <string.h>
#include <stdio.h>
#include "cmsis_os.h"
#include "mbm.h"
	
/* Exported definitions -------------------------------------------------------*/
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;
extern UART_HandleTypeDef huart4;
extern UART_HandleTypeDef huart5;
extern UART_HandleTypeDef huart6;
extern CRC_HandleTypeDef hcrc;



#define	CODE_PORT_FORWARD       35
#define CODE_READ_REMOTE_ModBus_RESPONSE  36
#define CODE_MB_STIMEOUT        80
#define CODE_MB_WRITE           81
#define CODE_MB_READ            82
#define CODE_EMS_INSVAL         83
#define CODE_EMS_SETRTC         84
#define CODE_EMS_CFG            85
#define CODE_EMS_TRIGGER        86
#define CODE_EMS_PACKET         87

#define BAUD_RATE                9600
#define TIMERID_MB_TIMER         0xFF
#define TIMERID_RTC_TIMER        0xFE
#define TIMERID_TMOUT_TIMER      0xFD
#define MyID                     1
#define USB_Module               2
#define Options                  0x00
#define RcvMessageMaxSize        20
#define MeterLastID              2
#define MB_MAX_DEVICES           32
#define METER_MB_PARAMS          3

/* Port-related definitions */
#define	NumOfPorts			5             /* to remove P6 from BOS ports */
#define P_PROG 				P2						/* ST factory bootloader UART */

/* Define available ports */
#define P1
#define P2
#define P3
#define P4
#define P5
#define P6

/* Define available USARTs */
#define _Usart1 1   
#define _Usart2 1
#define _Usart3 1
#define _Usart4 1
#define _Usart5 1
#define _Usart6	1

/* Port-UART mapping */
#define P1uart 				&huart4
#define P2uart 				&huart2
#define P3uart 				&huart6
#define P4uart 				&huart3
#define P5uart 				&huart5
#define P6uart 				&huart1
#define P_RS485uart 		P6uart

/* Port Definitions */
#define	USART1_TX_PIN		GPIO_PIN_9
#define	USART1_RX_PIN		GPIO_PIN_10
#define	USART1_TX_PORT		GPIOA
#define	USART1_RX_PORT		GPIOA
#define	USART1_AF			GPIO_AF1_USART1

#define	USART2_TX_PIN		GPIO_PIN_2
#define	USART2_RX_PIN		GPIO_PIN_3
#define	USART2_TX_PORT		GPIOA
#define	USART2_RX_PORT		GPIOA
#define	USART2_AF			GPIO_AF1_USART2

#define	USART3_TX_PIN		GPIO_PIN_10
#define	USART3_RX_PIN		GPIO_PIN_11
#define	USART3_TX_PORT		GPIOB
#define	USART3_RX_PORT		GPIOB
#define	USART3_AF			GPIO_AF4_USART3

#define	USART4_TX_PIN		GPIO_PIN_0
#define	USART4_RX_PIN		GPIO_PIN_1
#define	USART4_TX_PORT	    GPIOA
#define	USART4_RX_PORT		GPIOA
#define	USART4_AF			GPIO_AF4_USART4

#define	USART5_TX_PIN		GPIO_PIN_3
#define	USART5_RX_PIN		GPIO_PIN_4
#define	USART5_TX_PORT	    GPIOB
#define	USART5_RX_PORT  	GPIOB
#define	USART5_AF			GPIO_AF4_USART5

#define	USART6_TX_PIN		GPIO_PIN_4
#define	USART6_RX_PIN		GPIO_PIN_5
#define	USART6_TX_PORT  	GPIOA
#define	USART6_RX_PORT  	GPIOA
#define	USART6_AF			GPIO_AF5_USART6

/* Module-specific Definitions */

#define _P_RS485 		  _P6
#define P_RS485 	  		P6
#define P_BRIDGING 			3
#define	RS485_RE_DE_PIN		GPIO_PIN_12
#define	RS485_RE_DE_PORT	GPIOA
// \RE_DE = 0 Enable receiver output
#define	RS485_RECEIVER_EN()			HAL_GPIO_WritePin(RS485_RE_DE_PORT, RS485_RE_DE_PIN, GPIO_PIN_RESET)
// \RE_DE = 1 Disable receiver output
#define	RS485_RECEIVER_DIS()		HAL_GPIO_WritePin(RS485_RE_DE_PORT, RS485_RE_DE_PIN, GPIO_PIN_SET)

/* Modbus EEPROM variables addresses - Module Addressing Space 500 - 599 */
#define _EE_Modbus_CFG_MATRIX			500

/* Modbus_Status Type Definition */
typedef enum 
{
  Modbus_OK = 0,
	Modbus_ERR_UnknownMessage = 1,
	Modbus_ERR_WrongParams,
	Modbus_ERROR = 255
} Module_Status;

/* Define state enum */
enum Module_Mode{IDLE = 0x00, BRIDGE, RTU, ASCII};
enum MB_Parity{MB_PARITY_O, MB_PARITY_E, MB_PARITY_N};
enum MB_DataBits{MB_DATABITS_7, MB_DATABITS_8, MB_DATABITS_9};
enum MB_StopBit{MB_STOPBIT_1 = 0x01, MB_STOPBIT_2};

/* Define module global variables*/
struct Meter_TypeDef
{
	char Model[10];
	uint32_t SerialNumber;
	uint8_t ID;
	uint8_t Status;
	uint16_t NoReg;
	uint16_t FstRegAddress;
	uint16_t LastRegAddress;
};

struct rxMessaging_TypeDef
{
	uint8_t Flag;
	uint8_t Port;
};

/* Indicator LED */
#define _IND_LED_PORT		GPIOB
#define _IND_LED_PIN		GPIO_PIN_14
#define _IND_ON()       HAL_GPIO_WritePin(_IND_LED_PORT, _IND_LED_PIN, GPIO_PIN_SET)
#define _IND_OFF()      HAL_GPIO_WritePin(_IND_LED_PORT, _IND_LED_PIN, GPIO_PIN_RESET)
#define _IND_TOGGLE()   HAL_GPIO_TogglePin(_IND_LED_PORT, _IND_LED_PIN)

/* Module Init prototype */
void Module_Init (void);

/* Define UART Init prototypes */
Module_Status MB_PORT_Init(uint16_t BaudRate, uint32_t DataBitsN, uint32_t ParityBit, uint32_t StopBitN);
void MX_USART1_UART_Init(void);
void MX_USART2_UART_Init(void);
void MX_USART3_UART_Init(void);
void MX_USART4_UART_Init(void);
void MX_USART5_UART_Init(void);
void MX_USART6_UART_Init(void);

/* Define CRC and DMA Init prototypes */
void MX_DMA_Init(void);
void MX_CRC_Init(void);

/* Define TIM16 Init prototypes */
void MX_TIM16_Init(void);

/* Define GPIO Init prototypes */
void MX_GPIO_Init(void);
void RS485_DE_RE_Init(void);
void IND_LED_Init(void);







/* -----------------------------------------------------------------------
	|																APIs	 	|
   ----------------------------------------------------------------------- 
*/
uint8_t GetPort(UART_HandleTypeDef *huart);
UART_HandleTypeDef* GetUART(uint8_t Port);
Module_Status SetupModbusRTU(uint32_t BaudRate, uint32_t ParityBit);
Module_Status SetupModbusASCII(uint32_t BaudRate, uint32_t ParityBit);
Module_Status ReadModbusRegister(uint8_t SlaveAdd, uint32_t RegAdd, uint8_t NofReg, unsigned short * DataBuffer);
Module_Status WriteModbusRegister(uint8_t SlaveAdd, uint32_t RegAdd, uint32_t Data);
Module_Status WriteModbusMultiRegisters(uint8_t SlaveAdd, uint32_t RegAdd, uint8_t NofReg, uint16_t *Data);
Module_Status SetTimeOut(uint16_t MiliSeconds);

Module_Status ModbuserviceRoutine(uint8_t mbMeterID);
//Module_Status ModbusHardwareConfiguration(uint8_t *pData);
//Module_Status SaveConfigsToEEPROM(uint8_t *pData);
//Module_Status LoadConfigsFromEEPROM(uint8_t *pData);
void SetRTC(uint8_t hour, uint8_t min, uint8_t sec);


//Module_Status SlaveServiceRoutine(uint8_t SlaveAdd , uint32_t RegAdd , uint8_t NofReg);
/* -----------------------------------------------------------------------
	|															Commands																 	|
   ----------------------------------------------------------------------- 
*/

#endif /* __Modbus_H */
#endif
/************************ (C) COPYRIGHT HEXABITZ *****END OF FILE****/

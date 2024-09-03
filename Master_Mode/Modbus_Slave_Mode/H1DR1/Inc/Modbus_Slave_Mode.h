

#ifndef _MODBUS_SLAVE_MODE_H
#define _MODBUS_SLAVE_MODE_H

#include "main.h"
#if (Modbus_Mode==MODBUS_SLAVE)

#include <eeprom.h>
#include "cmsis_os.h"
#include "mbs_Slave.h"
#include "mbutils_Slave.h"
#include "mbtypes_Slave.h"
#include "mbport.h"
#include "H1DR1_Slave.h"
#include "stm32f0xx_hal.h"


/*****************************************************************/
//osThreadId defaultTaskHandle;
extern TIM_HandleTypeDef htim2;

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void StartDefaultTask(void const * argument);




extern void     prvvMBPUSART1_TC_ISR( void );
extern void     prvvMBPUSART1_RXNE_ISR( void );
void vApplicationStackOverflowHook( TaskHandle_t xTask, char *pcTaskName );
extern struct rxMessaging_TypeDef rxMessaging;

extern void     prvvMBPUSART1_RXNE_ISR( void );
void vApplicationStackOverflowHook( TaskHandle_t xTask, char *pcTaskName );
extern struct rxMessaging_TypeDef rxMessaging;
extern uint8_t RcvMessage[NumOfPorts][RcvMessageMaxSize];
extern unsigned short usRegHoldingValue[NUMBER_OF_REGISTERS];
extern uint8_t DataBuff[25];
extern xMBSHandle xModmus;
extern eMBErrorCode    eStatus;
void SlaveLoop ();
void ModbusSlaveModeInit();

#endif
#endif

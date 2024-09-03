
#ifndef _MODBUS_MASTER_MODE_H
#define _MODBUS_MASTER_MODE_H


#include "main.h"
#include "Messaging_Master.h"
#include "H1DR1_Master.h"

#include "main.h"
#include "mbtypes.h"
#include "mbport.h"
#include "eeprom.h"
#include "Messaging_Master.h"

extern uint8_t mbTriggerFlag;
extern uint8_t Hour;
extern uint8_t Minute;
extern uint8_t Second;
extern uint8_t wmTimeOut;
extern Module_Status eStatus;

extern void     prvvMBPUSART1_TC_ISR( void );
extern void     prvvMBPUSART1_RXNE_ISR( void );
void vApplicationStackOverflowHook( TaskHandle_t xTask, char *pcTaskName );
extern struct rxMessaging_TypeDef rxMessaging;


#endif



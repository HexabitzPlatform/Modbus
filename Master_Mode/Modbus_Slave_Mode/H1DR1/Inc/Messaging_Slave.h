

#ifndef _MESSAGING_SLAVE_H
#define _MESSAGING_SLAVE_H

#include "main.h"
#if (Modbus_Mode==MODBUS_SLAVE)
#include "H1DR1_Slave.h"

#define	CODE_READ_REMOTE  						  30
#define	CODE_READ_REMOTE_RESPONSE  			      31
#define	CODE_WRITE_REMOTE  						  32
#define	CODE_WRITE_REMOTE_RESPONSE  	        	33
#define	CODE_WRITE_REMOTE_FORCE					34

extern uint16_t ReadVar[25];
extern uint32_t remoteVar[9];

Module_Status SendMessage(uint16_t Port, uint16_t mCode, uint8_t dst, uint8_t *pData, uint16_t size);
Module_Status SlaveMessagingParser(uint8_t Port);
Module_Status Module_MessagingProcessing(uint8_t Port,uint16_t code,  uint8_t *pData);




#endif
#endif

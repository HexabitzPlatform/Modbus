

#ifndef _MESSAGING_MASTER_H
#define _MESSAGING_MASTER_H

#include "main.h"
#include "Modbus_Master_Mode.h"
#include "H1DR1_Master.h"
/* -----------------------------------------------------------------------
	|														Message Codes	 														 	|
   -----------------------------------------------------------------------
*/
#define	CODE_PORT_FORWARD       35
#define CODE_MB_STIMEOUT        80
#define CODE_MB_WRITE           81
#define CODE_MB_READ            82
#define CODE_Modbus_INSVAL      83
//#define CODE_Modbus_SETRTC      84
//#define CODE_Modbus_CFG         85
//#define CODE_Modbus_TRIGGER     86
//#define CODE_Modbus_PACKET      87

#define CODE_H1DR1_MODE                       84
#define CODE_H1DR1_READ                       85
#define CODE_H1DR1_WRITE                      86
#define CODE_H1DR1_MULTIWRITE                 87
#define CODE_H1DR1_STIMEOUT                   88
#define	CODE_READ_REMOTE  					  30
#define	CODE_READ_REMOTE_RESPONSE  			  31
#define	CODE_WRITE_REMOTE  				      32



extern uint16_t ReadVar[25];
extern uint32_t remoteVar[9];


extern uint8_t RcvMessage[NumOfPorts][RcvMessageMaxSize];
extern unsigned short ReadBuffer[25];
Module_Status SendMessage(uint16_t Port, uint16_t mCode, uint8_t dst, uint8_t *pData, uint16_t size);
Module_Status MasterMessagingParser(uint8_t Port);
Module_Status Module_MessagingProcessing(uint16_t code,  uint8_t *pData);
 void CheckTheFlag() ;

#endif


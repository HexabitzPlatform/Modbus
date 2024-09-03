#include "main.h"
#include "Modbus_Master_Mode.h"
#include "Messaging_Master.h"
uint16_t LastRegAdd=0;
uint8_t MeterID=0;
uint8_t MeterStatus=0;
uint8_t flag1=0 ;
uint8_t flag2=0 ;
//extern USHORT DataRcv[200];
uint16_t Address;
uint16_t RegAdd;
//Module_Status eStatus2;
int f ;
int *WaterValue;
float WaterMeter = 0.0f;

int *RatioValue;
float WaterMeterRatio = 0.0001f;

uint16_t word_LSB=0, word_MSB=0;
uint32_t temp32=0;
uint8_t counter=0;

Module_Status s=0 ;
uint16_t  n[5] ;
Module_Status eStatus;

void MasterLoop ()
{
	if(1==flag1)
	{CheckTheFlag();}

}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	f++;
	uint8_t port ;
  /* Prevent unused argument(s) compilation warning */
	rxMessaging.Port=GetPort(huart);
	if (0<rxMessaging.Port && 6>rxMessaging.Port)
	{
		rxMessaging.Flag=1;
	}


	if(huart == P1uart)
	{
		port=1;
		MasterMessagingParser(port);
	}
	else if (huart == P2uart)
	{
		port=2;
		MasterMessagingParser(port);
	}
	else if (huart == P3uart)
	{
		port=3;
		MasterMessagingParser(port);
	}
	else if (huart == P4uart)
	{
		port=4;
		MasterMessagingParser(port);
	}
	else if (huart == P5uart)
	{
		port=5;
		MasterMessagingParser(port);
	}
	else
		if (huart == P_RS485uart)
	{
		prvvMBPUSART1_RXNE_ISR();          /* Call Modbus protocol port ISR */
	}

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_UART_RxCpltCallback can be implemented in the user file.
   */
}


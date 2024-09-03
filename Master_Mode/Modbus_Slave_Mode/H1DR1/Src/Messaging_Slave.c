











#include "main.h"


#if (Modbus_Mode==MODBUS_SLAVE)
#include"Messaging_Slave.h"
#include "H1DR1_Slave.h"
#include <string.h>
#include "mbs_Slave.h"

extern uint8_t RcvMessage[NumOfPorts][RcvMessageMaxSize];
extern unsigned short usRegHoldingValue[NUMBER_OF_REGISTERS];
extern CRC_HandleTypeDef hcrc;

uint16_t ReadVar[25]={0};
uint32_t remoteVar[9]= {0};

Module_Status SendMessage(uint16_t Port, uint16_t mCode, uint8_t dst, uint8_t *pData, uint16_t size)
{
	Module_Status Status;
	UART_HandleTypeDef* handle;
	uint16_t length =0;
	uint8_t crc8=0;
	uint8_t MessagePacket[45]={0};

	/* check port */
	if (0<Port && 6>Port)
	{
		/* get the handle of the port to transmit from */
		handle=GetUART(Port);

		/* Configuring packet's header */
		/* packet delimiter */
		MessagePacket[0]='H';
		MessagePacket[1]='Z';

		if (CODE_EMS_PACKET==mCode)
		{
			/* Calculating packet length */
			length=size+9;                          /*not including H & Z delimiters, the length bytes and the CRC byte.*/
			memcpy(&MessagePacket[2], &length, 2);
			/* destination module */
			MessagePacket[4]=dst;
			/* source module */
			MessagePacket[5]=MyID;
			/* options byte */
			MessagePacket[6]=Options;
			/* message code */
			MessagePacket[7]=mCode;

			/* Copying data payload */
			memcpy(&MessagePacket[8],pData,size);
		}
		else
		{
			/* Calculating packet length */
			length=size+4;                          /*not including H & Z delimiters, the length bytes and the CRC byte.*/
			MessagePacket[2]=length;
			/* destination module */
		  MessagePacket[3]=dst;
			/* source module */
		  MessagePacket[4]=MyID;
		  /* options byte */
		  MessagePacket[5]=Options;
		  /* message code */
		  MessagePacket[6]=mCode;
			/* Copying data payload */
			memcpy(&MessagePacket[7],pData,size);
		}

		/* Calculating CRC8 for the packet */
		crc8 = HAL_CRC_Calculate(&hcrc, (uint32_t *)&MessagePacket, (length+3)/4);
		if ((length-1)%4 !=0){
			crc8 = HAL_CRC_Accumulate(&hcrc, (uint32_t *)&MessagePacket[((length+3)/4)*4], 1);
		}
		MessagePacket[length+3]=crc8;

		/* Send data packet via DMA */
		HAL_UART_Transmit(handle, MessagePacket, length+4 , 100);    /* in case length doesn't include delimeter and CRC should be added to 5*/

		/* wait to finish transmitting packet */
		//HAL_Delay(100);

		/* Reinitializing DMA */
		HAL_UART_DeInit(handle);
		HAL_UART_Init(handle);
		HAL_UART_Receive_DMA(handle, &RcvMessage[Port-1][0], RcvMessageMaxSize);

		Status = Modmus_OK;
	}
	else
		Status = Modmus_ERR_WrongParams;

	return Status;
}

/*-----------------------------------------------------------*/

/* --- send data packet from port
*/
Module_Status SlaveMessagingParser(uint8_t Port)
{
	Module_Status Status;
	UART_HandleTypeDef* Handle;
	uint8_t packetLength=0;
	uint8_t CRC8=0;
	uint16_t code=0;
	uint8_t data[36]={0};
	uint8_t CRC_Buffer[RcvMessageMaxSize]={0};
	UNUSED(packetLength);
	UNUSED(CRC8);
	Handle=GetUART(Port);

	/* Parsing message */
	if (RcvMessage[Port-1][0]=='H' && RcvMessage[Port-1][1]=='Z')
	{
		/* Get packet length */
		packetLength=RcvMessage[Port-1][2];
		memcpy(CRC_Buffer, &RcvMessage[Port-1][0], RcvMessageMaxSize-1);

		/* Calculating CRC8 for the packet */
		CRC8 = HAL_CRC_Calculate(&hcrc, (uint32_t *)&CRC_Buffer, (RcvMessageMaxSize-1)/4);
		if ((RcvMessageMaxSize-1)%4 !=0){
			CRC8 = HAL_CRC_Accumulate(&hcrc, (uint32_t *)&CRC_Buffer[((RcvMessageMaxSize-1)/4)*4], 1);
		}
//	RcvMessage[Port-1][RcvMessageMaxSize-1];
		/* Check CRC value */
//		if (CRC8 == RcvMessage[Port-1][RcvMessageMaxSize-1])
//		{
//			/* message code */
			code=RcvMessage[Port-1][6];  //( (uint16_t) RcvMessage[Port-1][6] << 8 )

			memcpy(data,&RcvMessage[Port-1][7],RcvMessageMaxSize-8);
			Module_MessagingProcessing(Port ,code, data);
			Status = Modmus_OK;
//		}
//		else
//			Status = Modmus_ERROR;
	}
	else
		Status = Modmus_ERROR;

	/* clear RcvMessage	*/
	memset(&RcvMessage[Port-1][0],0,RcvMessageMaxSize);

	/* re-initializing DMA of receiving port */
	HAL_UART_DeInit(Handle);
	HAL_UART_Init(Handle);
	HAL_UART_Receive_DMA(Handle, &RcvMessage[Port-1][0], RcvMessageMaxSize);

	return Status;
}

/*-----------------------------------------------------------*/

/* --- message processing.
*/
Module_Status Module_MessagingProcessing(uint8_t Port ,uint16_t code,  uint8_t *pData)
{
	Module_Status result = Modmus_OK;
	uint8_t messageParams[36];
	uint8_t rank;

	switch (code)
	{

		case (CODE_READ_REMOTE):



		  messageParams[0] = rank;
			switch(rank)
			{

				case 0 :


						memcpy(&messageParams[1],&ReadVar[0],sizeof (ReadVar[4]) ); // First var
						memcpy(&messageParams[3],&ReadVar[5],sizeof (ReadVar[5]) );

						//					memcpy(&uint32_t uint32_number ,&messageParams[ 4 byte ],	sizeof (uint32_number)) ;
						//					memcpy(&float float_number ,&uint32_number,sizeof (float_number));

						memcpy(&messageParams[5],&ReadVar[6],sizeof (ReadVar[6]) );// Second var
						memcpy(&messageParams[7],&ReadVar[7],sizeof (ReadVar[7]) );


						memcpy(&messageParams[9],&ReadVar[8],sizeof (ReadVar[8]) );// Third var
						memcpy(&messageParams[11],&ReadVar[9],sizeof (ReadVar[9]) );


						break;


						case 1 :
						/***********************************/
						memcpy(&messageParams[1],&ReadVar[10],sizeof (ReadVar[10]) ); // Fourth var
						memcpy(&messageParams[3],&ReadVar[11],sizeof (ReadVar[11]) );


						memcpy(&messageParams[5],&ReadVar[12],sizeof (ReadVar[12]) );// Fifth var
						memcpy(&messageParams[7],&ReadVar[13],sizeof (ReadVar[13]) );


						memcpy(&messageParams[9],&ReadVar[14],sizeof (ReadVar[14]) );// Sixth var
						memcpy(&messageParams[11],&ReadVar[15],sizeof (ReadVar[15]) );

						break;



						case 2 :
						/***********************************/
						memcpy(&messageParams[1],&ReadVar[16],sizeof (ReadVar[16]) ); // Seventh var
						memcpy(&messageParams[3],&ReadVar[17],sizeof (ReadVar[17]) );


						memcpy(&messageParams[5],&ReadVar[18],sizeof (ReadVar[18]) );// Eighth var
						memcpy(&messageParams[7],&ReadVar[19],sizeof (ReadVar[19]) );


						memcpy(&messageParams[9],&ReadVar[20],sizeof (ReadVar[20]) );// Ninth var
						memcpy(&messageParams[11],&ReadVar[21],sizeof (ReadVar[21]) );



					  break;

		}

//			  SendMessage(Port , CODE_READ_REMOTE_ModBus_RESPONSE ,2 , messageParams ,13);
		  SendMessage(RcvMessage[2][8] , CODE_READ_REMOTE_ModBus_RESPONSE ,2 , messageParams ,13);
		break;

		case (CODE_WRITE_REMOTE):
			    rank = pData[0];

		   switch( rank)
		     {
					case 0 :

						                remoteVar[0] = ((uint32_t)pData[1]<<0) + ((uint32_t)pData[2]<<8) + ((uint32_t)pData[3]<<16) + ((uint32_t)pData[4]<<24);  // First Var
//										float float_number;
//										memcpy(& float_number , &remoteVar[0] , sizeof (float_number));
//	                     				memcpy(&float float_number , &remoteVar, sizeof (float_number));
										remoteVar[1] = ((uint32_t)pData[5]<<0) + ((uint32_t)pData[6]<<8) + ((uint32_t)pData[7]<<16) + ((uint32_t)pData[8]<<24);  // Second Var

										remoteVar[2] = ((uint32_t)pData[9]<<0) + ((uint32_t)pData[10]<<8) + ((uint32_t)pData[11]<<16) + ((uint32_t)pData[12]<<24);  // Third Var
										  break;

										case 1 :
										remoteVar[3] = ((uint32_t)pData[1]<<0) + ((uint32_t)pData[2]<<8) + ((uint32_t)pData[3]<<16) + ((uint32_t)pData[4]<<24);  // Fourth Var

										remoteVar[4] = ((uint32_t)pData[5]<<0) + ((uint32_t)pData[6]<<8) + ((uint32_t)pData[7]<<16) + ((uint32_t)pData[8]<<24);  // Fifth Var

										remoteVar[5] = ((uint32_t)pData[9]<<0) + ((uint32_t)pData[10]<<8) + ((uint32_t)pData[11]<<16) + ((uint32_t)pData[12]<<24);  // Sixth Var
											break;

										case 2 :
										remoteVar[6] = ((uint32_t)pData[1]<<0) + ((uint32_t)pData[2]<<8) + ((uint32_t)pData[3]<<16) + ((uint32_t)pData[4]<<24);  // Seventh Var

										remoteVar[7] = ((uint32_t)pData[5]<<0) + ((uint32_t)pData[6]<<8) + ((uint32_t)pData[7]<<16) + ((uint32_t)pData[8]<<24);  // Eighth Var

										remoteVar[8] = ((uint32_t)pData[9]<<0) + ((uint32_t)pData[10]<<8) + ((uint32_t)pData[11]<<16) + ((uint32_t)pData[12]<<24);  // Ninth Var
											break;
				  }
 break;

		default:
			result = Modmus_ERR_UnknownMessage;
			break;
	}

	return result;
}

#endif

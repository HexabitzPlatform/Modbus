

#include "main.h"




#include <H1DR1_Master.h>
#include "task.h"
#include "mbm.h"
#include "main.h"
#include "Messaging_Master.h"
/* --- send data packet from port*/


uint8_t Slave_add;
uint16_t Reg_address;
uint16_t Nu_regiters;
uint16_t TimeOut;
unsigned short ReadBuffer[25]={0};
uint8_t messageParams[36];
uint32_t Write;
uint16_t WriteBuffer [9]={0};
int Port;
uint8_t rank;
uint16_t ReadVar[25]={0};
uint32_t remoteVar[9]={0};


Module_Status MasterMessagingParser(uint8_t Port)
{
	Module_Status Status;
	UART_HandleTypeDef* Handle;
	uint8_t packetLength=0;
	uint8_t CRC8=0;
	uint16_t code=0;
	uint8_t data[12]={0};
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

		/* Check CRC value */
//		if (CRC8 == RcvMessage[Port-1][RcvMessageMaxSize-1])
//		{
			/* message code */
			code=RcvMessage[Port-1][6];  //( (uint16_t) RcvMessage[Port-1][6] << 8 )

			memcpy(data,&RcvMessage[Port-1][7],RcvMessageMaxSize-8);
			Module_MessagingProcessing(code, data);
			Status = Modbus_OK;
//		}
//		else
//			Status = Modbus_ERROR;
	}
	else
		Status = Modbus_ERROR;

	/* clear RcvMessage	*/
	memset(&RcvMessage[Port-1][0],0,RcvMessageMaxSize);

	/* re-initializing DMA of receiving port */
	HAL_UART_DeInit(Handle);
	HAL_UART_Init(Handle);
	HAL_UART_Receive_DMA(Handle, &RcvMessage[Port-1][0], RcvMessageMaxSize);

	return Status;
}

/*-----------------------------------------------------------*/

/* --- Modbus message processing.
*/


Module_Status Module_MessagingProcessing(uint16_t code,  uint8_t *pData)
{


	Module_Status result = Modbus_OK;



	switch (code)
	{



	break;
		case CODE_H1DR1_READ:

			flag1=1;
			flag2=1;
			Slave_add = pData[1];
			Reg_address = ( (uint16_t) pData[3] << 8 ) + pData[2];
			Nu_regiters = ( (uint16_t) pData[5] << 8 ) + pData[4];
			Port = pData[6];

		break;

		case CODE_H1DR1_WRITE:

			flag1=1;
			flag2=2;
			Slave_add = pData[1];
			Reg_address = ( (uint16_t) pData[3] << 8 ) + pData[2];
			Write = pData[4] | pData[5]<<8 |pData[6] << 16 | pData[7] <<24   ;


		 break;

		case CODE_H1DR1_MULTIWRITE:
			flag1=1;
			flag2=3;
			Slave_add = pData[1];
			Reg_address = ( (uint16_t) pData[3] << 8 ) + pData[2];
			Nu_regiters = ( (uint16_t) pData[5] << 8 ) + pData[4];
			memcpy(&WriteBuffer[0],&pData[6] ,sizeof (WriteBuffer[0])); // pData[6]  +pData[7]
			memcpy(&WriteBuffer[1],&pData[8] ,sizeof (WriteBuffer[0])); // pData[8]  +pData[9]
			memcpy(&WriteBuffer[2],&pData[10],sizeof (WriteBuffer[0])); // pData[10] +pData[11]
			memcpy(&WriteBuffer[3],&pData[12],sizeof (WriteBuffer[0])); // pData[12] +pData[13]
			memcpy(&WriteBuffer[4],&pData[14],sizeof (WriteBuffer[0])); // pData[14] +pData[15]
			memcpy(&WriteBuffer[5],&pData[16],sizeof (WriteBuffer[0])); // pData[16] +pData[17]
			memcpy(&WriteBuffer[6],&pData[18],sizeof (WriteBuffer[0])); // pData[18] +pData[19]
			memcpy(&WriteBuffer[7],&pData[20],sizeof (WriteBuffer[0])); // pData[20] +pData[21]
			memcpy(&WriteBuffer[8],&pData[22],sizeof (WriteBuffer[0])); // pData[22] +pData[23]




		 break;

		case CODE_H1DR1_STIMEOUT:
			flag1=1;
			flag2=4;
			TimeOut = ( (uint16_t) pData[2] << 8 ) + pData[1];


		 break;



		case CODE_READ_REMOTE:


				flag1=1;
				flag2=5;
				rank=RcvMessage[2][7];
				Port=RcvMessage[2][8];

	case CODE_WRITE_REMOTE:
		    rank = pData[0];

	   switch( rank)
	     {
				case 0 :
				remoteVar[0] = ((uint32_t)pData[1]<<0) + ((uint32_t)pData[2]<<8) + ((uint32_t)pData[3]<<16) + ((uint32_t)pData[4]<<24);  // First Var
//										float float_number;
//				memcpy(& float_number , &remoteVar[0] , sizeof (float_number));
//					memcpy(&float float_number , &remoteVar, sizeof (float_number));
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
				result = Modbus_ERR_UnknownMessage;
				break;
}
				code=0;
				return result;


}
void CheckTheFlag()
			  {
	Module_Status status;
				  switch (flag2) {
							case 1:

							    do
							    {
							    	status =ReadModbusRegister(6, 0x200, 10, &ReadBuffer[0]);
							    }
							    while( status != Modbus_OK );
					        	memcpy(&messageParams[1],&ReadBuffer[4],sizeof (ReadBuffer[4]) ); // First var
								memcpy(&messageParams[3],&ReadBuffer[5],sizeof (ReadBuffer[5]) );

				//					memcpy(&uint32_t uint32_number ,&messageParams[ 4 byte ],	sizeof (uint32_number)) ;
				//					memcpy(&float float_number ,&uint32_number,sizeof (float_number));

								memcpy(&messageParams[5],&ReadBuffer[6],sizeof (ReadBuffer[6]) );// Second var
								memcpy(&messageParams[7],&ReadBuffer[7],sizeof (ReadBuffer[7]) );


				                memcpy(&messageParams[9],&ReadBuffer[8],sizeof (ReadBuffer[8]) );// Third var
								memcpy(&messageParams[11],&ReadBuffer[9],sizeof (ReadBuffer[9]) );

								memcpy(&messageParams[13],&ReadBuffer[6],sizeof (ReadBuffer[6]) );// Second var
								memcpy(&messageParams[15],&ReadBuffer[7],sizeof (ReadBuffer[7]) );

				                memcpy(&messageParams[17],&ReadBuffer[8],sizeof (ReadBuffer[8]) );// Third var

				                do
				                { status=SendMessage(Port , CODE_READ_REMOTE_ModBus_RESPONSE ,2 , messageParams ,19);}
											    while( status != Modbus_OK );
									flag1=0;
									flag2=0;

								break;
							case 2:
								do
								{
									 status=WriteModbusRegister(Slave_add, Reg_address, WriteBuffer);
								}
								while( status != Modbus_OK );
									flag1=0;
									flag2=0;
								break;
							case 3:
								do
								{
									 status=WriteModbusMultiRegisters(Slave_add, Reg_address, Nu_regiters, WriteBuffer);
								}
								while( status != Modbus_OK );
										flag1=0;
										flag2=0;

								break;
							case 4:


					 status=SetTimeOut(TimeOut);

					break;

							case 5 :

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
								do
								{
									 status=SendMessage(Port , CODE_READ_REMOTE_ModBus_RESPONSE ,2 , messageParams ,13);
						     	}
								while( status != Modbus_OK );
								flag1=0;
								flag2=0;
					break;
							default:

								break;
						}

			  }

/*-----------------------------------------------------------*/

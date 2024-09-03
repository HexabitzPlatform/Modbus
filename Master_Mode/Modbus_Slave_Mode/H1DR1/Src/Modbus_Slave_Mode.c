
#include "main.h"
#if (Modbus_Mode==MODBUS_SLAVE)
#include "Modbus_Slave_Mode.h"
#include <string.h>
xMBSHandle xModmus;
eMBErrorCode    eStatus;
extern uint8_t Second;
float PresentValue;
int *WaterValue;
float WaterMeter = 0.0f;
int *RatioValue;
float WaterMeterRatio = 0.0001f;
uint8_t messageParams1[13];
float e = 545.5;
int n ;
uint8_t DataBuff[25]={1,2,3,4,5,6,8};
uint16_t word_LSB=0, word_MSB=0;
uint32_t temp32=0;
uint8_t counter=0;
static eMBException eMyRegHoldingCB( UBYTE * pubRegBuffer, USHORT usAddress, USHORT usNRegs, eMBSRegisterMode eRegMode );

void ModbusSlaveModeInit()
{
	/* USER CODE BEGIN 5 */
		_IND_ON();
		HAL_Delay(500);
		_IND_OFF();
		/* initialize MB port */

		usRegHoldingValue[0] = SLAVE_ADDRESS;
		usRegHoldingValue[1] = WATERMETRE_NAME;
		usRegHoldingValue[2] = (USHORT) (METRE_SERIAL_NUMBER >> 16);
		usRegHoldingValue[3] = (USHORT) METRE_SERIAL_NUMBER;


}

void SlaveLoop ()
{


	/* Poll the communication stack */
	eMBSPoll( xModmus );

	if( MB_ENOERR != ( eStatus = eMBSRegisterHoldingCB( xModmus, eMyRegHoldingCB ) ) )
	{
	( void )eMBSClose( xModmus );
	}

}
eMBException
eMyRegHoldingCB( UBYTE * pubRegBuffer, USHORT usAddress, USHORT usNRegs, eMBSRegisterMode eRegMode )
{

    eMBException    eException = MB_PDU_EX_ILLEGAL_DATA_ADDRESS;
    STATIC const ULONG usRegsMappedAt = 0x0200;
    ULONG           usRegStart = usAddress;
    ULONG           usRegEnd = usAddress + usNRegs - 1;
    USHORT          usIndex;
    USHORT          usIndexEnd;

    if( ( usNRegs > 0 ) && ( usRegStart >= usRegsMappedAt )
        && ( usRegEnd <= ( usRegsMappedAt + MB_UTILS_NARRSIZE( usRegHoldingValue ) ) ) )
    {
        usIndex = ( USHORT ) ( usRegStart - usRegsMappedAt );
        usIndexEnd = ( USHORT ) ( usRegEnd - usRegsMappedAt );
        switch ( eRegMode )
        {
        case MBS_REGISTER_WRITE:
//         	_IND_TOGGLE();

							if (usAddress==0x0205)
								{

							usRegHoldingValue[4] = ( USHORT ) * pubRegBuffer++ << 8;
							usRegHoldingValue[4] |= ( USHORT ) * pubRegBuffer++;

							HAL_Delay(500);
							usRegHoldingValue[5] = ( USHORT ) * pubRegBuffer++ << 8;
							usRegHoldingValue[5] |= ( USHORT ) * pubRegBuffer++;          // First var

							usRegHoldingValue[6] = ( USHORT ) * pubRegBuffer++ << 8;
							usRegHoldingValue[6] |= ( USHORT ) * pubRegBuffer++;
							usRegHoldingValue[7] = ( USHORT ) * pubRegBuffer++ << 8;
							usRegHoldingValue[7] |= ( USHORT ) * pubRegBuffer++;          // Second var

							usRegHoldingValue[8] = ( USHORT ) * pubRegBuffer++ << 8;
							usRegHoldingValue[8] |= ( USHORT ) * pubRegBuffer++;
							usRegHoldingValue[9] = ( USHORT ) * pubRegBuffer++ << 8;
							usRegHoldingValue[9] |= ( USHORT ) * pubRegBuffer++;          // Third var


							usRegHoldingValue[10] = ( USHORT ) * pubRegBuffer++ << 8;
							usRegHoldingValue[10] |= ( USHORT ) * pubRegBuffer++;
							usRegHoldingValue[11] = ( USHORT ) * pubRegBuffer++ << 8;
							usRegHoldingValue[11] |= ( USHORT ) * pubRegBuffer++;         // Fourth var

							usRegHoldingValue[12] = ( USHORT ) * pubRegBuffer++ << 8;
							usRegHoldingValue[12] |= ( USHORT ) * pubRegBuffer++;
							usRegHoldingValue[13] = ( USHORT ) * pubRegBuffer++ << 8;
							usRegHoldingValue[13] |= ( USHORT ) * pubRegBuffer++;         // Fifth var

							usRegHoldingValue[14] = ( USHORT ) * pubRegBuffer++ << 8;
							usRegHoldingValue[14] |= ( USHORT ) * pubRegBuffer++;
							usRegHoldingValue[15] = ( USHORT ) * pubRegBuffer++ << 8;
							usRegHoldingValue[15] |= ( USHORT ) * pubRegBuffer++;         // Sixth var

							usRegHoldingValue[16] = ( USHORT ) * pubRegBuffer++ << 8;
							usRegHoldingValue[16] |= ( USHORT ) * pubRegBuffer++;
							usRegHoldingValue[17] = ( USHORT ) * pubRegBuffer++ << 8;
							usRegHoldingValue[17] |= ( USHORT ) * pubRegBuffer++;         // Seventh var

							usRegHoldingValue[18] = ( USHORT ) * pubRegBuffer++ << 8;
							usRegHoldingValue[18] |= ( USHORT ) * pubRegBuffer++;
							usRegHoldingValue[19] = ( USHORT ) * pubRegBuffer++ << 8;
							usRegHoldingValue[19] |= ( USHORT ) * pubRegBuffer++;         // Eighth var

							usRegHoldingValue[20] = ( USHORT ) * pubRegBuffer++ << 8;
							usRegHoldingValue[20] |= ( USHORT ) * pubRegBuffer++;
							usRegHoldingValue[21] = ( USHORT ) * pubRegBuffer++ << 8;
							usRegHoldingValue[21] |= ( USHORT ) * pubRegBuffer++;         // Ninth var
//
														_IND_ON();
														HAL_Delay(1000);
														_IND_OFF();
														HAL_Delay(100);


										eException = MB_PDU_EX_NONE;
							  }
							else
								eException = MB_PDU_EX_ILLEGAL_DATA_ADDRESS;
            break;

        default:
        case MBS_REGISTER_READ:
// 	_IND_TOGGLE();
            for( ; usIndex <= usIndexEnd; usIndex++ )
            {


                *pubRegBuffer++ = ( UBYTE ) ( usRegHoldingValue[usIndex] >> 8 );
                *pubRegBuffer++ = ( UBYTE ) ( usRegHoldingValue[usIndex] & 0xFF );

				usRegHoldingValue[4]  =DataBuff[0] ;
				usRegHoldingValue[5]  =DataBuff[1] ;
				usRegHoldingValue[6]  =DataBuff[2] ;
				usRegHoldingValue[7]  =DataBuff[3] ;
				usRegHoldingValue[8]  =DataBuff[4] ;
				usRegHoldingValue[9]  =DataBuff[5] ;
				usRegHoldingValue[10] =DataBuff[6] ;
				usRegHoldingValue[11] =DataBuff[7] ;
				usRegHoldingValue[12] =DataBuff[8] ;
				usRegHoldingValue[13] =DataBuff[9] ;
				usRegHoldingValue[14] =DataBuff[10];
				usRegHoldingValue[15] =DataBuff[11];
				usRegHoldingValue[16] =DataBuff[12];
				usRegHoldingValue[17] =DataBuff[13];
				usRegHoldingValue[18] =DataBuff[14];
				usRegHoldingValue[19] =DataBuff[15];
				usRegHoldingValue[20] =DataBuff[16];
				usRegHoldingValue[21] =DataBuff[17];
				usRegHoldingValue[22] =DataBuff[18];
				usRegHoldingValue[23] =DataBuff[19];
				usRegHoldingValue[24] =DataBuff[20];
				usRegHoldingValue[25] =DataBuff[21];
				usRegHoldingValue[26] =DataBuff[22];
				usRegHoldingValue[27] =DataBuff[23];
				_IND_ON();
				HAL_Delay(100);
				_IND_OFF();
				HAL_Delay(100);
				_IND_ON();
				HAL_Delay(100);
				_IND_OFF();

							  eException = MB_PDU_EX_NONE;
            }
            break;
        }
    }

    return eException;
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
	uint8_t port;
	if(huart == P1uart)
	{
		port=1;
		SlaveMessagingParser(port);
	}
	else if (huart == P2uart)
	{
		port=2;
		SlaveMessagingParser(port);
	}
	else if (huart == P3uart)
	{
		port=3;
		SlaveMessagingParser(port);
	}
	else if (huart == P4uart)
	{
		port=4;
		SlaveMessagingParser(port);
	}
	else if (huart == P5uart)
	{
		//port=5;
		memcpy(&DataBuff[0], &RcvMessage[4][1], 24);
		memset(&RcvMessage[4][0],0,RcvMessageMaxSize);
	//	HAL_UART_DeInit(P5uart);
	 // HAL_UART_Init(P5uart);
    HAL_UART_Receive_DMA(P5uart, &RcvMessage[4][0], RcvMessageMaxSize);
	  _IND_TOGGLE();
		//SlaveMessagingParser(port);
	}
	if (huart == P_RS485uart)
	{
		prvvMBPUSART1_RXNE_ISR();              // Call Modbus protocol port ISR
	}

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_UART_RxCpltCallback can be implemented in the user file.
   */
}
#endif

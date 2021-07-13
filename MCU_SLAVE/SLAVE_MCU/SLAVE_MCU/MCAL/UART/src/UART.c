/*
 * UART.c
 *
 * Created: 6/24/2021 8:29:10 PM
 *  Author: EslamFayad
 */ 
#include "UART_Private.h"
#include "UART.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/******************************************************************************
* \Syntax          : void UART_Init(u16 baudRate)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : baudRate - Baudrate corresponding value
* \Return value:   : None
*******************************************************************************/
void UART_Init(uint_16 baudRate)
{
	/* Set baud rate */
	UART_UBRRH_REG = (uint_8)(baudRate>>8);
	UART_UBRRL_REG = (uint_8)baudRate;
	/* Enable receiver and transmitter */
	SET_BIT(UART_UCSRB_REG,RXEN_BIT_NO);  /* Enable Receiver*/
	SET_BIT(UART_UCSRB_REG,TXEN_BIT_NO);  /* Enable Transmitter */
	/* Set frame format: 8data, 1stop bit, Even Parity */
	UART_UCSRC_REG |= (1 << URSEL_BIT_NO)|UART_8_BIT_DATA | UART_NONE_PARITY;
}
/******************************************************************************
* \Syntax          : void Uart_TransmitChr(u8 data)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : data - data byte to transmit
* \Return value:   : None
*******************************************************************************/
void UART_Send(uint_8 data)
{
	/* Wait for empty transmit buffer */
	while (!(GET_BIT(UART_UCSRA_REG,UDRE_BIT_NO)))
			;
	/* Put data into buffer, sends the data */
	UART_UDR_REG = data;
}
/******************************************************************************
* \Syntax          : void Uart_TransmitStr(u8 data)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : data - data byte to transmit
* \Return value:   : None
*******************************************************************************/
void UART_SendStr(uint_8 *str)
{
	/* Wait for empty transmit buffer */
	while (*str != '\0')
	{
		UART_Send(*str);
		str++;
	}
}
/******************************************************************************
* \Syntax          : u8 Uart_ReceiveChr(void)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : Nonr
* \Return value:   : data byte received
*******************************************************************************/
uint_8 UART_Read(void)
{
	while(!(UART_UCSRA_REG) & (1<<RXC_BIT_NO));
	return UART_UDR_REG;
	
	/* Wait for data to be received */
	//while (!(GET_BIT(UART_UCSRA_REG,RXC_BIT_NO)))
			
	/* Get and return received data from buffer */
	//return UART_UDR_REG;
}

/**********************************************************************************************************************
 *  END OF FILE: Uart.c
 *********************************************************************************************************************/
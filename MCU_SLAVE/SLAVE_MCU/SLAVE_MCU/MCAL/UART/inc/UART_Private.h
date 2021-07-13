/*
 * UART_Private.h
 *
 * Created: 6/12/2021 1:02:57 PM
 *  Author: EslamFayad
 */ 


#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#define		UART_UDR_REG					*((volatile uint_8*)0x2C)
#define		UART_UCSRA_REG					*((volatile uint_8*)0x2B)
#define		UART_UCSRB_REG					*((volatile uint_8*)0x2A)
#define		UART_UCSRC_REG					*((volatile uint_8*)0x40)
#define		UART_UBRRL_REG					*((volatile uint_8*)0x29)
#define		UART_UBRRH_REG					*((volatile uint_8*)0x40)

#define RXEN_BIT_NO						(4)
#define TXEN_BIT_NO						(3)
#define URSEL_BIT_NO					(7)
#define USBS_BIT_NO						(3)
#define UCSZ0_BIT_NO					(1)
#define UPM0_BIT_NO						(4)
#define UPM1_BIT_NO						(5)
#define UDRE_BIT_NO						(5)
#define RXC_BIT_NO						(7)



#endif /* UART_PRIVATE_H_ */
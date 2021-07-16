/*
 * main.c
 *
 * Created: 7/9/2021 4:10:52 PM
 *  Author: EslamFayad
 */ 
#define F_CPU 16000000UL
#include  <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_INTERFACE.h"
#include "UART.h"
#include "SPI.h"
#include "LCD_interface.h"
#include "Led_Interface.h"
#include <avr/interrupt.h>


int main(void)
{
	uint_8 ON[]="LED_ON";
	uint_8 OFF[]="LED_OFF";
	uint_8 i =0;
	uint_8 name[]="MASTER MCU";
	uint_8 Command= 0;
	UART_Init(UART_BAUDRATE_9600);
	Spi_MasterInit();
	//Led_Init();
   // LCD_Init_4bit();
	//LCD_WRITE_STRING_4bit(name);
	//_delay_ms(100);
	//DIO_SetPinValue(DIO_PORTC);
	//UART_Send(x);
	//UART_SendStr(OK[1]);
    while(1)
    {
		Command = UART_Read();    //read from uart and save it to variable
	     _delay_ms(100);
		Spi_MasterWrite(Command);
		_delay_ms(100);
	
		
		
		
		
		
        //TODO:: Please write your application code 
    }
}
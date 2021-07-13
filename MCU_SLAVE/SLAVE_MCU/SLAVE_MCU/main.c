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
	uint_8 i =0;
	uint_8 name[]="   SMART HOME";
	uint_8 name2[]="ENG ESLAM FAYAD";
	uint_8 ON1[]="LED 1 ON";
	uint_8 ON2[]="LED 2 ON";
	uint_8 ON3[]="LED 3 ON";
	uint_8 OFF1[]="LED 1 OFF";
	uint_8 OFF2[]="LED 2 OFF";
	uint_8 OFF3[]="LED 3 OFF";
	uint_8 Command= 0;

	Spi_SlaveInit();
	Led_Init();
    LCD_Init_4bit();
	LCD_WRITE_STRING_4bit(name);
	LCD_SendStringRowCol(1,1,name2);
	_delay_ms(100);

    while(1)
    {
		Command = Spi_SlaveRead();  //read from uart and save it to variable
		//Command= '5';  //tHIS LINE ONLY FOR TESTING THE BELOW CASE STATMENT BEFORE READING FROM SPI 
		switch (Command)
		{
			case '1': Led_ON(LED0);   UART_SendStr(ON1); LCD_ClearScreen_4bit(); LCD_WRITE_STRING_4bit(ON1) ; _delay_ms(100);  break;   /* Turn ON LED */
			
									//UART_SendStr(ON);   AND WRITE ON THE LCD  /* send status of LED i.e. LED ON */
			
			case '2': Led_OFF(LED0);  UART_SendStr(OFF1); LCD_ClearScreen_4bit(); LCD_WRITE_STRING_4bit(OFF1) ; _delay_ms(100);  break;
			
			
			case '3': Led_ON(LED1);   UART_SendStr(ON2);  LCD_ClearScreen_4bit(); LCD_WRITE_STRING_4bit(ON2) ;  _delay_ms(100);  break;   /* Turn ON LED */
									//UART_SendStr(ON);  AND WRITE ON THE LCD  /* send status of LED i.e. LED ON */
			
			case '4': Led_OFF(LED1);  UART_SendStr(OFF2);  LCD_ClearScreen_4bit(); LCD_WRITE_STRING_4bit(OFF2) ; _delay_ms(100); break;
			
			
			case '5': Led_ON(LED2);   UART_SendStr(ON3);  LCD_ClearScreen_4bit(); LCD_WRITE_STRING_4bit(ON3) ;   _delay_ms(100);  break;   /* Turn ON LED */
			
									//UART_SendStr(ON);   AND WRITE ON THE LCD /* send status of LED i.e. LED ON */
			case '6': Led_OFF(LED2);  UART_SendStr(OFF3);  LCD_ClearScreen_4bit(); LCD_WRITE_STRING_4bit(OFF3) ;  _delay_ms(100);  break;
			
		}
		
		
		
        //TODO:: Please write your application code 
    }
}
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
#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"

static const uint_8 *pcTextForTask1 = "\x1B[32m Task 1 is running\r\n";
static const uint_8 *pcTextForTask2 = "\x1B[33m Task 2 is running\t\n";
uint_8 Command= 0;

void Task_1(void *pvParameters)
{
	uint_8 *taskstr = (uint_8*)pvParameters;
	while(1)
	{
		Command = UART_Read();    //read from uart and save it to variable
		vTaskDelay(100);
	}
}

void Task_2(void *pvParameters)
{
	uint_8 *taskstr = (uint_8*)pvParameters;
	while(1)
	{
		Spi_MasterWrite(Command);
		vTaskDelay(100);
	}
}

/*void Task_3(void *pvParameters)
{
	uint_8 *taskstr = (uint_8*)pvParameters;
	while(1)
	{
		Dio_FlipChannel(DIO_PORTC,2);
		vTaskDelay(100);
	}
}
*/
int main(void)
{
	uint_8 ON[]="LED_ON";
	uint_8 OFF[]="LED_OFF";
	//uint_8 i =0;
	uint_8 name[]="MASTER MCU";

	UART_Init(UART_BAUDRATE_9600);
	Spi_MasterInit();
	Led_Init();
    LCD_Init_4bit();
	LCD_WRITE_STRING_4bit(name);
	_delay_ms(100);
	TaskHandle_t xHandle = NULL;
	LCD_WRITE_STRING_4bit ("Hello...! RTOS is Running");
	xTaskCreate(Task_1,"Task 1",100,(uint_8*)pcTextForTask1, 1, NULL);
	xTaskCreate(Task_2, "Task 2",100, (uint_8*)pcTextForTask2, 2, NULL);
	//xTaskCreate(Task_3, "Task 3",100, (uint_8*)pcTextForTask2, 3, NULL);
	 vTaskStartScheduler();
    while(1)
    {




	
		
		
		
		
		
        //TODO:: Please write your application code 
    }
}

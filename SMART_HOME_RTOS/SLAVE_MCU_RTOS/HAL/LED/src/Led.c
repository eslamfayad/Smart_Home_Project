/*********************************
 * Led.c
 *
 *  Created on: Apr 30, 2021
 *  Author: Eng_Fawzi
 **********************************/

#include "Led_Interface.h"

void Led_Init(void)
{
	DIO_SetPinDirection(LED0_PORT, LED0_CHANNEL, OUTPUT);
	DIO_SetPinDirection(LED1_PORT, LED1_CHANNEL, OUTPUT);
	DIO_SetPinDirection(LED2_PORT, LED2_CHANNEL, OUTPUT);
}
void Led_ON(Led_ID led)
{
	switch (led)
	{
	case LED0:
#if (LED0_CONNECTION == FORWARD)
		DIO_SetPinValue(LED0_PORT,LED0_CHANNEL,HIGH);
#elif (LED0_CONNECTION == REVERSE)
		DIO_SetPinValue(LED0_PORT,LED0_CHANNEL,LOW);
#endif
		break;
	case LED1:
#if (LED1_CONNECTION == FORWARD)
		DIO_SetPinValue(LED1_PORT,LED1_CHANNEL,HIGH);
#elif (LED1_CONNECTION == REVERSE)
		DIO_SetPinValue(LED1_PORT,LED1_CHANNEL,LOW);
#endif
		break;
	case LED2:
#if (LED2_CONNECTION == FORWARD)
		DIO_SetPinValue(LED2_PORT,LED2_CHANNEL,HIGH);
#elif (LED2_CONNECTION == REVERSE)
		DIO_SetPinValue(LED2_PORT,LED2_CHANNEL,LOW);
#endif
		break;
	}
}
void Led_OFF(Led_ID led)
{
	switch (led)
	{
	case LED0:
#if (LED0_CONNECTION == FORWARD)
		DIO_SetPinValue(LED0_PORT,LED0_CHANNEL,LOW);
#elif (LED0_CONNECTION == REVERSE)
		DIO_SetPinValue(LED0_PORT,LED0_CHANNEL,HIGH);
#endif

		break;
	case LED1:
#if (LED1_CONNECTION == FORWARD)
		DIO_SetPinValue(LED1_PORT,LED1_CHANNEL,LOW);
#elif (LED1_CONNECTION == REVERSE)
		DIO_SetPinValue(LED1_PORT,LED1_CHANNEL,HIGH);
#endif
		break;
	case LED2:
#if (LED2_CONNECTION == FORWARD)
		DIO_SetPinValue(LED2_PORT,LED2_CHANNEL,LOW);
#elif (LED2_CONNECTION == REVERSE)
		DIO_SetPinValue(LED2_PORT,LED2_CHANNEL,HIGH);
#endif
		break;
	}
}
void Led_Toggle(Led_ID led)
{
	switch (led)
	{
	case LED0:
		Dio_FlipChannel(LED0_PORT,LED0_CHANNEL);
		break;
	case LED1:
		Dio_FlipChannel(LED1_PORT,LED1_CHANNEL);
		break;
	case LED2:
		Dio_FlipChannel(LED2_PORT,LED2_CHANNEL);
		break;
	}
}

/*
* Receiver_Kit.c
*
* Created: 9/30/2020 2:44:45 PM
*  Author: mnaguib
*/

#include <avr/io.h>
#include "board.h"
#include "spi.h"

int main(void)
{
	SPI_Init(MODE_SLAVE);
	BLUE_led_Init();
	RED_led_Init();
	INT8U DevName="None";
	INT8U Command[10];
	INT8U i=0;
	INT8U* Blue_ON="blue1";
	INT8U* Blue_OFF="blue0";
	INT8U* RED_ON="red1";
	INT8U* Red_OFF="red0";
	
	while(1)
	{
		for(i=0;Command[i]!=0;i++)
		{
			SPI_Tranceive(Command[i]);
		}
		if(!strcmp(Blue_ON,Command))
		{
			BLUE_led_On();
		}
		else if(!strcmp(Blue_OFF,Command))
		{
			BLUE_led_Off();
		}
		else if(!strcmp(RED_ON,Command))
		{
			RED_led_On();
		}
		else if(!strcmp(Red_OFF,Command))
		{
			RED_led_On();
		}
		
	}
	
}

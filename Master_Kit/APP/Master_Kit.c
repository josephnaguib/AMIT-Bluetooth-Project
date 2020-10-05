/*
 * AMIT_Grad_Project.c
 *
 * Created: 9/22/2020 6:56:01 PM
 *  Author: mnaguib
 */ 


#include <avr/io.h>
#include "Bluetooth.h"
#include "spi.h"
int main(void)
{
	Bluetooth_Init();
	SPI_Init(MODE_MASTER);
	INT8U DevName="None";
	INT8U Command[10];
	INT8U i=0;
	Bluetooth_Connect(Slave,DevName);
    while(1)
    {
        if(Bluetooth_Recieve(Command)){
			for(i=0;Command[i]!=0;i++)
			{
			SPI_Tranceive(Command[i]);	
			}
		
		}
    }
}
/*
 * Bluetooth.c
 *
 * Created: 9/22/2020 7:40:45 PM
 *  Author: mnaguib
 */ 

#include "Bluetooth.h"


void Bluetooth_Init()
{
	UART_Init(38400);
	UART_SendStr("AT+UART=115200?1,0,\r\n");
	UART_Init(115200);
	UART_SendStr("AT+ROLE=0\r\n");
}

void Bluetooth_Connect(Connect_Mode Cmode,INT8U* DevAddr)
{
	if(!Cmode)
	{
		UART_SendStr("AT+ROLE=0\r\n");
	}
	else
	{
		UART_SendStr("AT+ROLE=1\r\n");
		INT8U* prefix="AT+FSAD=";
		INT8U* addr=strcat(prefix,DevAddr);
		INT8U* postfix="\r\n";
		INT8U* str=strcat(addr,postfix);
		UART_SendStr(str);
	}
}

Bool Bluetooth_Recieve(INT8U *pu8Data)
{
	return UART_ReceiveByte_Unblock( *pu8Data);
}
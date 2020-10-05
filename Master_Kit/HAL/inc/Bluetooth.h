/*
 * Bluetooth.h
 *
 * Created: 9/22/2020 7:40:30 PM
 *  Author: mnaguib
 */ 


#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_

#include "data_types.h"
#include "bit_math.h"
#include "uart.h"

typedef enum Connmode{
	Slave=0,Master
	}Connect_Mode;
	
void Bluetooth_Init();
void Bluetooth_Connect(Connect_Mode Cmode,INT8U* DevAddr);
Bool Bluetooth_Recieve(INT8U *pu8Data);


#endif /* BLUETOOTH_H_ */
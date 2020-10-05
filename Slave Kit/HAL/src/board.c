/*
* board.c
*
* Created: 5/20/2020 12:53:33 PM
*  Author: mnaguib
*/
#include "board.h"

void BLUE_led_Init(void){
	setBit(LED_DDR,BLUE_LED);
	BLUE_led_Off();
}

void RED_led_Init(void){
	setBit(LED_DDR,RED_LED);
	RED_led_Off();
}
void BLUE_led_On(void){
	setBit(LED_Port,BLUE_LED);
}
void RED_led_On(void){
	setBit(LED_Port,RED_LED);
}
void RED_led_Off(void){
	clearBit(LED_Port,RED_LED);
}
void BLUE_led_Off(void){
	clearBit(LED_Port,BLUE_LED);
}

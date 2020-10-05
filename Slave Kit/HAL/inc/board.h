/*
* board.h
*
* Created: 5/20/2020 12:53:20 PM
*  Author: mnaguib
*/


#ifndef BOARD_H_
#define BOARD_H_

/*
Single led :PB4
8-Leds     :PA0-7 -> Enable latch PF1(Active High)
Buttons    :PD0-1->(Active Low)
Buuzer     :PE7 ->(Active High)
*/
#define  F_CPU 8000000UL
#include "avr/io.h"
#include "data_types.h"
#include "bit_math.h"
#include "util/delay.h"

#define LED_Port PORTD
#define LED_DDR  DDRD
#define BLUE_LED  PD5
#define RED_LED   PD6

void BLUE_led_Init(void);
void RED_led_Init(void);
void BLUE_led_On(void);
void RED_led_On(void);
void BLUE_led_Off(void);
void RED_led_Off(void);



#endif /* BOARD_H_ */
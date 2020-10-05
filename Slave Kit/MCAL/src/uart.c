/*
* uart.c
*
* Created: 6/3/2020 2:34:00 PM
*  Author: mnaguib
*/
#include "uart.h"


/*volatile Queue UART0_Data;
CreateQueue(&UART0_Data);
volatile Queue UART1_Data;
CreateQueue(&UART1_Data);*/

void UART_Init(INT32U u32Baud){
	INT16U ubrr=0;
	ubrr=51;
	//ubrr=((8000000UL)/(16*u32Baud))-1;
	
	/* Set baud rate */
	UBRRH = (INT8U)(ubrr>>8);
	UBRRL = (INT8U)ubrr;
	/* Enable receiver and transmitter */
	UCSRB = (1<<RXEN)|(1<<TXEN);
	/* Set frame format: 8data, 2stop bit */
	UCSRC = (3<<UCSZ0);
	

}

void UART_SendByte( INT8U u8Data){
	
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) )
	;
	/* Put data into buffer, sends the data */
	UDR = u8Data;
	
	
}
void UART_SendStr(INT8U *pu8Data){
	int i;
	for(i=0;pu8Data[i]!='\0';i++){
		UART_SendByte(pu8Data[i]);
	}
}

INT8U UART_ReceiveByte(){
	INT8U u8Data	=0;
	
	/* Wait for empty transmit buffer */
	while ( !(UCSRA & (1<<RXC)) )
	;
	/* Put data into buffer, sends the data */
	u8Data=UDR;
	
	
	return u8Data;
}

Bool UART_ReceiveByte_Unblock( INT8U *pu8Data){
	Bool result=FALSE;
	
	if((UCSRA & (1<<RXC)) )
	{
		result=TRUE;
		(*pu8Data)=UDR;
	}
	
	
	return result;
}

/*ISR(USART0_RX_vect_num){
	while ( !(UCSR0A & (1<<RXC0)) )
	;
	/* Put data into buffer, sends the data */
	/*append (UDR0,&UART0_Data);
}
ISR(USART1_RX_vect_num){
	while ( !(UCSR1A & (1<<RXC1)) )
	;
	/* Put data into buffer, sends the data */
	/*append (UDR1,&UART1_Data);
}*/

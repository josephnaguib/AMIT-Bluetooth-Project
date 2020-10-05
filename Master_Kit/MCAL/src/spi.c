/*
* spi.c
*
* Created: 6/7/2020 10:30:51 AM
*  Author: mnaguib
*/
#include "spi.h"

void SPI_Init(SPI_Mode spimode){
	switch(spimode){
		case MODE_MASTER:
		/*OUTPUT PINS*/
		setBit(SPI_DDR,SPI_MOSI);
		setBit(SPI_DDR,SPI_SCK);
		setBit(SPI_DDR,SPI_SS);
		/*unselect slave*/
		setBit(SPI_PORT,SPI_SS);
		/*INPUT PINS*/
		clearBit(SPI_DDR,SPI_MISO);
		/*MASTER MODE Select*/
		setBit(SPCR,MSTR);
		break;
		case MODE_SLAVE:
		/*OUTPUT PINS*/
		setBit(SPI_DDR,SPI_MISO);
		/*INPUT PINS*/
		clearBit(SPI_DDR,SPI_MOSI);
		clearBit(SPI_DDR,SPI_SCK);
		clearBit(SPI_DDR,SPI_SS);
		/*SLAVE MODE Select*/
		clearBit(SPCR,MSTR);
		break;
	}
	/*Enable SPI*/
	setBit(SPCR,SPE);
}
INT8U SPI_Tranceive(INT8U u8Data){
	/*UPLOAD DR*/
	SPDR=u8Data;/*Shift Started*/
	/*WAIT FOR SHIFT COMPLETE FLAG*/
	while(!(SPSR&(1<<SPIF)));
	/*RETURN DR*/
	return SPDR;
}
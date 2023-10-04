#include "STD_types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#include "SPI_private.h"
#include "SPI_interface.h"

void SPI_voidInitialize(u8 Copy_u8ModeSelect){
	
	ClrBit(SPCR,PIN7);
	SetBit(SPCR,PIN6);
	ClrBit(SPCR,PIN5);
	
	switch(Copy_u8ModeSelect){
		case MASTER:
			SetBit(SPCR,PIN4);
			break;
		case SLAVE:
			ClrBit(SPCR,PIN4);
			break;
	}
	
	ClrBit(SPCR,PIN3);
	ClrBit(SPCR,PIN2);
	
	ClrBit(SPCR,PIN1);
	SetBit(SPCR,PIN0);
	SetBit(SPSR,PIN0);
}

u8 SPI_u8TransCiver(u8 Copu_u8Data){
	
	SPDR=Copu_u8Data;
	while(GetBit(SPSR,PIN7)==0);
	return SPDR;
}
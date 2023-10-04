/*
 * main.c
 *
 *  Created on: Aug 25, 2022
 *      Author: mostafa
 */

#include "STD_types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#include "SPI_interface.h"
#include "GIE_interface.h"
#include "TIMER0_interface.h"

void func(){
	DIO_voidTogglePinValue(PORTC,PIN0);
}

int main(){

	u8 data;

	SPI_voidInitialize(SLAVE);
	TIMER0_voidInitialize();

	DIO_voidSetPinDirection(PORTB,PIN4,PIN_INPUT);
	DIO_voidSetPinDirection(PORTB,PIN5,PIN_INPUT);
	DIO_voidSetPinDirection(PORTB,PIN6,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTB,PIN7,PIN_INPUT);

	DIO_voidSetPinDirection(PORTC,PIN0,PIN_OUTPUT);
	DIO_voidSetPinValue(PORTC,PIN0,PIN_LOW);

	TIMER0_NORMAL_SetCallBack(func);
	TIMER0_voidSetTimer(1000);

	while(1){
		data=SPI_u8TransCiver(0);
		if(data=='T'){
			GIE_voidEnable();
		}
	}

	return 0;
}

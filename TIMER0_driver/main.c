/*
 * main.c
 *
 *  Created on: Aug 21, 2022
 *      Author: mostafa
 */

#include "STD_types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#include "GIE_interface.h"
#include "TIMER0_interface.h"

void func(void){
	DIO_voidTogglePinValue(PORTA,PIN0);
}

int main(){

	DIO_voidSetPinDirection(PORTA,PIN0,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTB,PIN3,PIN_OUTPUT);
	DIO_voidSetPinValue(PORTA,PIN0,PIN_HIGH);

	GIE_voidEnable();

	TIMER0_voidInitialize();
	//TIMER0_voidSetOCR0(127);

	TIMER0_voidSetTimer(100);

	TIMER0_NORMAL_SetCallBack(func);

	while(1);

	return 0;
}

/*
 * main.c
 *
 *  Created on: Aug 22, 2022
 *      Author: mostafa
 */

#include "STD_types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#include "GIE_interface.h"
#include "TIMER2_interface.h"

void func(void){
	DIO_voidTogglePinValue(PORTA,PIN0);
}

int main(){

	DIO_voidSetPinDirection(PORTD,PIN7,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTA,PIN0,PIN_OUTPUT);
	DIO_voidSetPinValue(PORTA,PIN0,PIN_HIGH);

	GIE_voidEnable();

	TIMER2_voidInitialize();
	TIMER2_voidSetOCR2(255);
	TIMER2_voidSetTimer(1000);
	TIMER2_CTC_SetCallBack(func);

	while(1);

	return 0;
}

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
#include "TIMER1_interface.h"

void func(){
	DIO_voidTogglePinValue(PORTA,PIN0);
}

int main(){

	GIE_voidEnable();
	TIMER1_voidInitialize();

	DIO_voidSetPinDirection(PORTD,PIN5,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTA,PIN0,PIN_OUTPUT);
	DIO_voidSetPinValue(PORTA,PIN0,PIN_HIGH);

	//TIMER1_voidSetTimer(100);
	//TIMER1_CTCA_SetCallBack(func);
	TIMER1_voidSetICR1(Set_Freq_50Hz);
	TIMER1_voidSetOCR1(999);
	while(1){

	}

	return 0;
}

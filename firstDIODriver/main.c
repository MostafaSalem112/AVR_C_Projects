/*
 * main.c
 *
 *  Created on: Aug 11, 2022
 *      Author: mostafa
 */
#include "STD_types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#include "avr/delay.h"

int main(){
	DIO_voidSetPinDirection(PORTA,PIN0,PIN_INPUT);
	DIO_voidSetPinDirection(PORTA,PIN1,PIN_OUTPUT);
	DIO_voidSetPinValue(PORTA,PIN1,PIN_HIGH);

	while(1){
		if(!DIO_u8GetPinValue(PORTA,PIN0)){
			DIO_voidTogglePinValue(PORTA,PIN1);
			_delay_ms(100);
		}
	}

	return 0;
}

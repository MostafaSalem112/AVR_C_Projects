/*
 * main.c
 *
 *  Created on: Aug 17, 2022
 *      Author: mostafa
 */

#include "STD_types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#include "avr/delay.h"

int main(){

	DIO_voidSetPinDirection(PORTD,PIN0,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTD,PIN1,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTD,PIN2,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTD,PIN3,PIN_OUTPUT);

	while(1){
		DIO_voidSetPinValue(PORTD,PIN0,PIN_HIGH);
		DIO_voidSetPinValue(PORTD,PIN1,PIN_LOW);
		DIO_voidSetPinValue(PORTD,PIN2,PIN_LOW);
		DIO_voidSetPinValue(PORTD,PIN3,PIN_LOW);
		_delay_ms(1000);

		DIO_voidSetPinValue(PORTD,PIN0,PIN_LOW);
		DIO_voidSetPinValue(PORTD,PIN1,PIN_HIGH);
		DIO_voidSetPinValue(PORTD,PIN2,PIN_LOW);
		DIO_voidSetPinValue(PORTD,PIN3,PIN_LOW);
		_delay_ms(1000);

		DIO_voidSetPinValue(PORTD,PIN0,PIN_LOW);
		DIO_voidSetPinValue(PORTD,PIN1,PIN_LOW);
		DIO_voidSetPinValue(PORTD,PIN2,PIN_HIGH);
		DIO_voidSetPinValue(PORTD,PIN3,PIN_LOW);
		_delay_ms(1000);

		DIO_voidSetPinValue(PORTD,PIN0,PIN_LOW);
		DIO_voidSetPinValue(PORTD,PIN1,PIN_LOW);
		DIO_voidSetPinValue(PORTD,PIN2,PIN_LOW);
		DIO_voidSetPinValue(PORTD,PIN3,PIN_HIGH);
		_delay_ms(1000);
	}

	return 0;
}

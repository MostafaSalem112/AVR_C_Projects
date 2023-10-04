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
#include "EXTI_interface.h"


void func1(){

	u8 data;
	DIO_voidSetPinValue(PORTB,PIN0,PIN_LOW);
	data=SPI_u8TransCiver('T');
	DIO_voidSetPinValue(PORTB,PIN0,PIN_HIGH);
}

void func2(){
	u8 data;
	DIO_voidSetPinValue(PORTB,PIN1,PIN_LOW);
	data=SPI_u8TransCiver('a');
	DIO_voidSetPinValue(PORTB,PIN1,PIN_HIGH);
}

int main(){

	GIE_voidEnable();
	EXTI_voidInitialize(EXTI0,FALLING_EDGE);
	EXTI_voidInitialize(EXTI1,FALLING_EDGE);
	SPI_voidInitialize(MASTER);

	DIO_voidSetPinDirection(PORTB,PIN4,PIN_INPUT);
	DIO_voidSetPinDirection(PORTB,PIN5,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTB,PIN6,PIN_INPUT);
	DIO_voidSetPinDirection(PORTB,PIN7,PIN_OUTPUT);

	DIO_voidSetPinDirection(PORTB,PIN0,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTB,PIN1,PIN_OUTPUT);
	DIO_voidSetPinValue(PORTB,PIN0,PIN_HIGH);
	DIO_voidSetPinValue(PORTB,PIN1,PIN_HIGH);

	DIO_voidSetPinDirection(PORTD,PIN2,PIN_INPUT);
	DIO_voidSetPinDirection(PORTD,PIN3,PIN_INPUT);
	DIO_voidSetPinValue(PORTD,PIN2,PIN_HIGH);
	DIO_voidSetPinValue(PORTD,PIN3,PIN_HIGH);

	EXTI0_SetCallBack(func1);
	EXTI1_SetCallBack(func2);

	while(1);

	return 0;
}

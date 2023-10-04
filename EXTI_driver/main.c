/*
 * main.c
 *
 *  Created on: Aug 17, 2022
 *      Author: mostafa
 */

#include "STD_types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#include "GIE_interface.h"
#include "EXTI_interface.h"

void func(void){
	DIO_voidSetPinDirection(PORTA,PIN0,PIN_OUTPUT);
	DIO_voidSetPinValue(PORTA,PIN0,PIN_HIGH);
}

int main(){

	GIE_voidEnable();
	EXTI_voidInitialize(EXTI0,FALLING_EDGE);

	EXTI0_SetCallBack(func);

	while(1);
}

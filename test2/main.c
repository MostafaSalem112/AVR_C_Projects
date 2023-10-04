/*
 * main.c
 *
 *  Created on: Aug 11, 2022
 *      Author: mostafa
 */
#include "STD_types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "DCMOTOR_interface.h"
#include "EXTI_interface.h"
#include "GIE_interface.h"
#include "TIMER0_interface.h"
#include "TIMER1_interface.h"

u8 f=0;

void func1(void){
	if(!f){
		DCMOTOR_voidSetDirection(RIGHT);
		f=1;
	}
	else{
		DCMOTOR_voidSetDirection(LEFT);
		f=0;
	}
}

void func2(void){
	DIO_voidTogglePinValue(PORTA,PIN2);
}

int main(){
	u16 reading;

	GIE_voidEnable();
	EXTI_voidInitialize(EXTI0,FALLING_EDGE);
	DCMOTOR_voidInitialize();
	TIMER0_voidInitialize();
	ADC_voidInitialize(ADC7);

	DIO_voidSetPinDirection(PORTA,PIN2,PIN_OUTPUT);
	DIO_voidSetPinValue(PORTA,PIN2,PIN_HIGH);
	DIO_voidSetPinDirection(PORTD,PIN2,PIN_INPUT);
	DIO_voidSetPinValue(PORTD,PIN2,PIN_HIGH);
	DIO_voidSetPinDirection(PORTD,PIN5,PIN_OUTPUT);

	TIMER0_voidSetTimer(1000);

	EXTI0_SetCallBack(func1);
	TIMER0_NORMAL_SetCallBack(func2);

	while(1){
		reading=ADC_voidStartConversion();
		TIMER1_voidSetOCR1(reading);
	}

}

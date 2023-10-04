/*
 * main.c
 *
 *  Created on: Aug 23, 2022
 *      Author: mostafa
 */

#include "STD_types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#include "GIE_interface.h"
#include "EXTI_interface.h"
#include "TIMER0_interface.h"
#include "TIMER0_private.h"
#include "TIMER1_interface.h"
#include "LCD_interface.h"

static u8 flag=0,counter=0;
static u32 Ton,Toff;

void func1(void){

	if(flag==0){
		TCNT0=0;
		EXTI_voidInitialize(EXTI0,FALLING_EDGE);
		flag=1;
	}
	else if(flag==1){
		Ton=TCNT0+counter*MAX_8BIT_REG;
		TCNT0=0;
		counter=0;
		EXTI_voidInitialize(EXTI0,RISING_EDGE);
		flag=2;
	}
	else if(flag==2){
		Toff=TCNT0+counter*MAX_8BIT_REG;
		TCNT0=0;
		counter=0;
		flag=3;
	}
}

void func2(void){
	counter++;
}


int main(){

	GIE_voidEnable();
	EXTI_voidInitialize(EXTI0,RISING_EDGE);
	TIMER0_voidInitialize();
	TIMER1_voidInitialize();
	LCD_voidIntialize();

	DIO_voidSetPinDirection(PORTD,PIN2,PIN_INPUT);
	DIO_voidSetPinDirection(PORTD,PIN5,PIN_OUTPUT);

	TIMER1_voidSetICR1(Set_Freq_50Hz);
	TIMER1_voidSetOCR1(15000);

	EXTI0_SetCallBack(func1);
	TIMER0_NORMAL_SetCallBack(func2);

	while(1){

		if(flag==3){
			LCD_voidGoToXY(0,0);
			LCD_voidWriteNumber((Ton*100)/(Ton+Toff));
			LCD_voidWriteString("                      ");
			LCD_voidGoToXY(1,0);
			LCD_voidWriteNumber(1000000/(Ton+Toff));
			LCD_voidWriteString("                      ");
			flag=0;
		}
	}

	return 0;
}

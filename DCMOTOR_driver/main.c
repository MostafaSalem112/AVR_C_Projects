/*
 * main.c
 *
 *  Created on: Aug 16, 2022
 *      Author: mostafa
 */

#include "STD_types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#include "DCMOTOR_config.h"
#include "DCMOTOR_interface.h"
#include "LCD_interface.h"
#include "LCD_config.h"

int main(){
	DIO_voidSetPinDirection(PORTD,PIN3,PIN_INPUT);
	DIO_voidSetPinDirection(PORTD,PIN4,PIN_INPUT);
	DIO_voidSetPinDirection(PORTD,PIN5,PIN_INPUT);
	DIO_voidSetPinDirection(PORTD,PIN6,PIN_INPUT);
	DIO_voidSetPinDirection(PORTD,PIN7,PIN_OUTPUT);

	DIO_voidSetPinValue(PORTD,PIN3,PIN_HIGH);
	DIO_voidSetPinValue(PORTD,PIN4,PIN_HIGH);
	DIO_voidSetPinValue(PORTD,PIN5,PIN_HIGH);
	DIO_voidSetPinValue(PORTD,PIN6,PIN_HIGH);

	DCMOTOR_voidInitialize();
	LCD_voidIntialize();

	while(1){
		LCD_voidGoToXY(0,0);
		if(!DIO_u8GetPinValue(PORTD,PIN3)){
			DCMOTOR_voidSetDirection(RIGHT);
			LCD_voidWriteString("Right");
		}
		else if(!DIO_u8GetPinValue(PORTD,PIN4)){
			DCMOTOR_voidSetDirection(LEFT);
			LCD_voidWriteString("Left ");
		}
		else if(!DIO_u8GetPinValue(PORTD,PIN5)){
			DCMOTOR_voidSetDirection(STOP);
			LCD_voidWriteString("Stop ");
		}

		if(!DIO_u8GetPinValue(PORTD,PIN6)){
			DIO_voidSetPinValue(PORTD,PIN7,PIN_HIGH);
		}
		else{
			DIO_voidSetPinValue(PORTD,PIN7,PIN_LOW);
		}
	}
}

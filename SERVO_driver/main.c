/*
 * main.c
 *
 *  Created on: Aug 22, 2022
 *      Author: mostafa
 */

#include "STD_types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#include "SERVO_interface.h"
#include "ADC_interface.h"

int main(){
	u16 reading;
	u8 angle;
	f32 slop;

	DIO_voidSetPinDirection(PORTD,PIN5,PIN_OUTPUT);

	ADC_voidInitialize(ADC0);
	slop=60.0/341;

	while(1){
		reading=ADC_voidStartConversion();
		angle=slop*reading;
		SERVO_voidSetAngle(angle);
	}

	return 0;
}

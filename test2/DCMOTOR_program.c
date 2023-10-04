#include "STD_types.h"
#include "Bit_Math.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "DCMOTOR_config.h"
#include "DCMOTOR_interface.h"


void DCMOTOR_voidInitialize(){
	DIO_voidSetPinDirection(DCMOTOR_PORT,DCMOTOR_CONTROL_0,PIN_OUTPUT);
	DIO_voidSetPinDirection(DCMOTOR_PORT,DCMOTOR_CONTROL_1,PIN_OUTPUT);
}

void DCMOTOR_voidSetDirection(u8 Copy_u8Dirction){
	switch(Copy_u8Dirction){
		case STOP:
			DIO_voidSetPinValue(DCMOTOR_PORT,DCMOTOR_CONTROL_0,PIN_LOW);
			DIO_voidSetPinValue(DCMOTOR_PORT,DCMOTOR_CONTROL_1,PIN_LOW);
			break;
		case RIGHT:
			DIO_voidSetPinValue(DCMOTOR_PORT,DCMOTOR_CONTROL_0,PIN_HIGH);
			DIO_voidSetPinValue(DCMOTOR_PORT,DCMOTOR_CONTROL_1,PIN_LOW);	
			break;
		case LEFT:
			DIO_voidSetPinValue(DCMOTOR_PORT,DCMOTOR_CONTROL_0,PIN_LOW);
			DIO_voidSetPinValue(DCMOTOR_PORT,DCMOTOR_CONTROL_1,PIN_HIGH);
			break;
	}
}
#include "STD_types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#include "KeyPad_interface.h"
#include "KeyPad_config.h"
#include "avr/delay.h"


void KeyPad_voidInitialize(){

	DIO_voidSetPortDirection(KeyPad_PORT,HALF_IN_OUT);
	DIO_voidSetPortValue(KeyPad_PORT,PORT_OUTPUT);
}

u8 KeyPad_u8GetPressedKey(){
	u8 key_values[4][4]={{7,8,9,10},
						{4,5,6,11},
						{1,2,3,12},
						{13,0,14,15}
						};
	u8 pressed_key=PORT_HIGH;
	u8 chech_Pressed=PIN_HIGH;
	
	for(u8 col=COL_START;col<COL_END;col++){
		DIO_voidSetPinValue(KeyPad_PORT,col,PIN_LOW);
		for(u8 row=ROW_START;row<ROW_END;row++){
			chech_Pressed=DIO_u8GetPinValue(KeyPad_PORT,row);
			if(chech_Pressed==PIN_LOW){
				pressed_key=key_values[row-4][col];
				while(chech_Pressed==PIN_LOW){
					chech_Pressed=DIO_u8GetPinValue(KeyPad_PORT,row);
				}
				_delay_ms(50);
				return pressed_key;
			}
		}
		DIO_voidSetPinValue(KeyPad_PORT,col,PIN_HIGH);
	}
	
	return pressed_key;
}

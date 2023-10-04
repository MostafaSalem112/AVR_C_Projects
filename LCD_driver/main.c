/*
 * main.c
 *
 *  Created on: Aug 14, 2022
 *      Author: mostafa
 */

#include "STD_types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#include "LCD_config.h"
#include "LCD_interface.h"
#include "avr/delay.h"


int main(){
	u8 patern[][8]={
			{0B00000,0B00000,0B00000,0B11111,0B00101,0B00111,0B00000,0B00000},
			{0B00000,0B00000,0B01011,0B01101,0B11111,0B00000,0B00000,0B00000},
			{0B01000,0B01000,0B01011,0B01101,0B11111,0B00000,0B00000,0B00000},
			{0B00010,0B00000,0B00111,0B00101,0B11111,0B00000,0B00000,0B00000},
			{0B00000,0B00000,0B00011,0B00100,0B10010,0B10001,0B01110,0B00000}
	};
	LCD_voidIntialize();
	for(u8 j=0;j<16;j++){
		for(u8 i=0;i<5;i++){
			LCD_voidWriteSpecialCharacter(patern[i],i,0,j+4-i);
		}
		_delay_ms(100);
		LCD_voidClearDisplay();
	}

	return 0;
}

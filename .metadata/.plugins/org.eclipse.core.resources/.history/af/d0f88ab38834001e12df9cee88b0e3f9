/*
 * main.c
 *
 *  Created on: Aug 18, 2022
 *      Author: mostafa
 */
#include "STD_types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "LCD_interface.h"
#include "avr/delay.h"

int main(){

	u16 reading,temp,light;

	LCD_voidIntialize();

	LCD_voidWriteString("Welcome");
	_delay_ms(100);
	LCD_voidClearDisplay();

	while(1){
		ADC_voidInitialize(ADC0);
		ADC_voidInitialize(ADC1);

		LCD_voidGoToXY(0,0);
		reading=ADC_voidStartConversion();
		temp=(u16)(((u32)reading*5000)/(1023*10));
		LCD_voidWriteString("temp=");
		LCD_voidWriteNumber(temp);
		LCD_voidWriteString("C");
		LCD_voidWriteString("         ");

		LCD_voidGoToXY(1,0);
		reading=ADC_voidStartConversion();
		light=(u16)(((u32)reading*5000*2)/(1023));
		LCD_voidWriteString("light=");
		LCD_voidWriteNumber(light);
		LCD_voidWriteString("Lux");
		LCD_voidWriteString("          ");
	}

	return 0;
}


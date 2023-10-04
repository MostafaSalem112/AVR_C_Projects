/*
 * main.c
 *
 *  Created on: Aug 24, 2022
 *      Author: mostafa
 */

#include "STD_types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#include "UART_interface.h"
#include "LCD_interface.h"

int main(){

	u8 data;
	u8 *string;

	UART_voidInitialize();
	LCD_voidIntialize();

	UART_voidSendData('w');
	UART_voidSendData('e');
	UART_voidSendData('l');
	UART_voidSendData('c');
	UART_voidSendData('o');
	UART_voidSendData('m');
	UART_voidSendData('e');
	UART_voidSendData(' ');

	UART_voidSendString("Mostafa");

	while(1){
		string=UART_u8_ReciveString();
		LCD_voidWriteString(string);
	}

	return 0;
}

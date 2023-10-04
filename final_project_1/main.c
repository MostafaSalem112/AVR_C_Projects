/*
 * main.c
 *
 *  Created on: Sep 5, 2022
 *      Author: mostafa
 */

#include "STD_types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#include "UART_interface.h"
#include "KeyPad_interface.h"

void switches(void);
void KeyPad(u8 key);

int main(){

	u8 key = PORT_HIGH;

	UART_voidInitialize();
	KeyPad_voidInitialize();

	DIO_voidSetAllPortInput(PORTA);
	DIO_voidSetAllPortHigh(PORTA);

	while(1){

		key = KeyPad_u8GetPressedKey();
		KeyPad(key);
		switches();
	}

	return 0;
}

void switches(void){

	if(DIO_u8GetPinValue(PORTA,PIN0)==PIN_LOW){
		UART_voidSendData('a');
	}
	else{
		UART_voidSendData('b');
	}
	if(DIO_u8GetPinValue(PORTA,PIN1)==PIN_LOW){
		UART_voidSendData('c');
	}
	else{
		UART_voidSendData('d');
	}
	if(DIO_u8GetPinValue(PORTA,PIN2)==PIN_LOW){
		UART_voidSendData('e');
	}
	else{
		UART_voidSendData('f');
	}
	if(DIO_u8GetPinValue(PORTA,PIN3)==PIN_LOW){
		UART_voidSendData('g');
	}
	else{
		UART_voidSendData('h');
	}
	if(DIO_u8GetPinValue(PORTA,PIN4)==PIN_LOW){
		UART_voidSendData('i');
	}
	else{
		UART_voidSendData('j');
	}
	if(DIO_u8GetPinValue(PORTA,PIN5)==PIN_LOW){
		UART_voidSendData('k');
	}
	else{
		UART_voidSendData('l');
	}
	if(DIO_u8GetPinValue(PORTA,PIN6)==PIN_LOW){
		UART_voidSendData('m');
	}
	else{
		UART_voidSendData('n');
	}
	if(DIO_u8GetPinValue(PORTA,PIN7)==PIN_LOW){
		UART_voidSendData('o');
	}
	else{
		UART_voidSendData('p');
	}
}

void KeyPad(u8 key){

	if(key!=PORT_HIGH){

		if(key==10){
			UART_voidSendData('/');
		}
		else if(key==11){
			UART_voidSendData('*');
		}
		else if(key==12){
			UART_voidSendData('-');
		}
		else if(key==15){
			UART_voidSendData('+');
		}
		else if(key==14){
			UART_voidSendData('=');
		}
		else if(key==13){
			UART_voidSendData('z');
		}
		else{
			UART_voidSendData(key+48);
		}
	}
}

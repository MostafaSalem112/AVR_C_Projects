/*
 * main.c
 *
 *  Created on: Aug 26, 2022
 *      Author: mostafa
 */

#include "STD_types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#include "SPI_interface.h"
#include "UART_interface.h"

int main(){

	u8 data;

	SPI_voidInitialize(SLAVE);
	UART_voidInitialize();

	DIO_voidSetPinDirection(PORTB,PIN4,PIN_INPUT);
	DIO_voidSetPinDirection(PORTB,PIN5,PIN_INPUT);
	DIO_voidSetPinDirection(PORTB,PIN6,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTB,PIN7,PIN_INPUT);

	while(1){
		data=SPI_u8TransCiver(0);
		UART_voidSendData(data);
	}

	return 0;
}

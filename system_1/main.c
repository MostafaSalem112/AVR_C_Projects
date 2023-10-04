/*
 * main.c
 *
 *  Created on: Aug 29, 2022
 *      Author: mostafa
 */

#include "STD_types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#include "UART_interface.h"
#include "ADC_interface.h"

int main(){

	u16 reading=0;
	u16 temp;

	ADC_voidInitialize(ADC0);
	UART_voidInitialize();

	while(1){
		if(reading!=ADC_voidStartConversion()){
			reading=ADC_voidStartConversion();
			temp=(u16)(((u32)reading*5000)/(1023*10));
			UART_voidSendNumber(temp);
			UART_voidSendString("C     ");
		}
	}

	return 0;
}

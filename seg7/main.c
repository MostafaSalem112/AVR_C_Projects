/*
 * main.c
 *
 *  Created on: Aug 11, 2022
 *      Author: mostafa
 */

#include "avr/io.h"
#include "avr/delay.h"

int main(){
	char arr[10]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};
	DDRA=0b01111111;
	for(int i=0;i<10;i++){
		PORTA=arr[i];
		_delay_ms(1000);
	}

	return 1;
}

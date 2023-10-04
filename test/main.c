/*
 * main.c
 *
 *  Created on: Aug 11, 2022
 *      Author: mostafa
 */


#include "avr/io.h"
#include "avr/delay.h"

int main(){
	DDRA=0b00000011;

	while(1){
		PORTA=0b00000011;
		_delay_ms(200);
		PORTA=0b00000000;
		_delay_ms(200);
	}
}

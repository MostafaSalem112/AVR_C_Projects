/*
 * main.c
 *
 *  Created on: Aug 10, 2022
 *      Author: mostafa
 */

#include "avr/io.h"
#include "avr/delay.h"

int main(){
	DDRA=0b11111111;

	while(1){
		PORTA=0b00000000;
		_delay_ms(200);
		PORTA=0b10000001;
		_delay_ms(200);
		PORTA=0b01000010;
		_delay_ms(200);
		PORTA=0b00100100;
		_delay_ms(200);
		PORTA=0b00011000;
		_delay_ms(200);
		PORTA=0b00100100;
		_delay_ms(200);
		PORTA=0b01000010;
		_delay_ms(200);
		PORTA=0b10000001;
		_delay_ms(200);

		PORTA=0b00000000;
		_delay_ms(200);
		PORTA=0b10000000;
		_delay_ms(200);
		for(int i=0;i<7;i++){
			PORTA=(PORTA>>1);
			PORTA=PORTA|(1<<7);
			_delay_ms(200);
		}

		PORTA=0b00000000;
		_delay_ms(200);
		PORTA=0b00000001;
		_delay_ms(200);
		for(int i=0;i<7;i++){
			PORTA=(PORTA<<1);
			PORTA=PORTA|1;
			_delay_ms(200);
		}
	}

	return 0;
}

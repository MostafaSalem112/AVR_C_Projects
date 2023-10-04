/*
 * main.c
 *
 *  Created on: Aug 11, 2022
 *      Author: mostafa
 */
#include "STD_types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#include "SevSeg_interface.h"
#include "avr/delay.h"


int main(){

	u8 arr[16]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,A,B,C,D,E,F};

	SevSeg_voidIntialize();

	for(u8 i=0;i<16;i++){

		SevSeg_voidDisplayNumber(arr[i]);
		_delay_ms(500);
	}

	return 0;
}


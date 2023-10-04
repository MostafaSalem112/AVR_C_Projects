/*
 * main.c
 *
 *  Created on: Aug 15, 2022
 *      Author: mostafa
 */

#include "STD_types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_config.h"
#include "KeyPad_interface.h"
#include "KeyPad_config.h"

int main(){
	u8 key;
	u8 op,num1,num2;
	u8 flag=0;

	LCD_voidIntialize();
	KeyPad_voidInitialize();

	while(1){
		key=KeyPad_u8GetPressedKey();
		if(key!=PORT_HIGH){
			if(key==10){
				LCD_voidWriteData('/');
				op=key;
			}
			else if(key==11){
				LCD_voidWriteData('*');
				op=key;
			}
			else if(key==12){
				LCD_voidWriteData('-');
				op=key;
			}
			else if(key==15){
				LCD_voidWriteData('+');
				op=key;
			}
			else if(key==14){
				LCD_voidWriteData('=');
				switch(op){
					case 10: LCD_voidWriteNumber(num1/num2);break;
					case 11: LCD_voidWriteNumber(num1*num2);break;
					case 12: LCD_voidWriteNumber(num1-num2);break;
					case 15: LCD_voidWriteNumber(num1+num2);break;
				}
			}
			else if(key==13){
				LCD_voidClearDisplay();
			}
			else{
				LCD_voidWriteNumber(key);
				if(!flag){
					num1=key;
					flag=1;
				}
				else{
					num2=key;
					flag=0;
				}
			}
		}
	}

	return 0;
}


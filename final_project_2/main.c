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
#include "ADC_interface.h"
#include "TIMER2_interface.h"
#include "LCD_interface.h"
#include "SERVO_interface.h"
#include "avr/delay.h"

void LEDs_AND_FANs(u8 UART_DATA);
void FANs_SPEED(u16 temp);
void STERRT_LAMP(u16 light);
void DOOR_LOCK();
u16 GET_TEMP();
u16 GET_LIGHT();
void DISPLAY_DATA(u16 temp,u16 light);

u8 password[20]="123";
u8 password_size=3;

int main(){

	u8 UART_DATA;
	u16 temp,light;

	UART_voidInitialize();
	TIMER2_voidInitialize();
	LCD_voidIntialize();

	DIO_voidSetAllPortOutput(PORTB);
	DIO_voidSetPinDirection(PORTD,PIN5,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTD,PIN6,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTD,PIN7,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTA,PIN0,PIN_INPUT);
	DIO_voidSetPinDirection(PORTA,PIN1,PIN_INPUT);
	DIO_voidSetPinDirection(PORTA,PIN2,PIN_OUTPUT);
	DIO_voidSetPinValue(PORTA,PIN2,PIN_LOW);

	DOOR_LOCK();

	while(1){

		UART_DATA=UART_u8ReciveData();
		LEDs_AND_FANs(UART_DATA);

		temp=GET_TEMP();
		light=GET_LIGHT();

		DISPLAY_DATA(temp,light);
		FANs_SPEED(temp);
		STERRT_LAMP(light);
	}

	return 0;
}

void LEDs_AND_FANs(u8 UART_DATA){

	if(UART_DATA=='a'){
		DIO_voidSetPinValue(PORTB,PIN0,PIN_HIGH);
	}
	else if(UART_DATA=='b'){
		DIO_voidSetPinValue(PORTB,PIN0,PIN_LOW);
	}
	else if(UART_DATA=='c'){
		DIO_voidSetPinValue(PORTB,PIN1,PIN_HIGH);
	}
	else if(UART_DATA=='d'){
		DIO_voidSetPinValue(PORTB,PIN1,PIN_LOW);
	}
	else if(UART_DATA=='e'){
		DIO_voidSetPinValue(PORTB,PIN2,PIN_HIGH);
	}
	else if(UART_DATA=='f'){
		DIO_voidSetPinValue(PORTB,PIN2,PIN_LOW);
	}
	else if(UART_DATA=='g'){
		DIO_voidSetPinValue(PORTB,PIN3,PIN_HIGH);
	}
	else if(UART_DATA=='h'){
		DIO_voidSetPinValue(PORTB,PIN3,PIN_LOW);
	}
	else if(UART_DATA=='i'){
		DIO_voidSetPinValue(PORTB,PIN4,PIN_HIGH);
	}
	else if(UART_DATA=='j'){
		DIO_voidSetPinValue(PORTB,PIN4,PIN_LOW);
	}
	else if(UART_DATA=='k'){
		DIO_voidSetPinValue(PORTB,PIN5,PIN_HIGH);
	}
	else if(UART_DATA=='l'){
		DIO_voidSetPinValue(PORTB,PIN5,PIN_LOW);
	}
	else if(UART_DATA=='m'){
		DIO_voidSetPinValue(PORTB,PIN6,PIN_HIGH);
	}
	else if(UART_DATA=='n'){
		DIO_voidSetPinValue(PORTB,PIN6,PIN_LOW);
	}
	else if(UART_DATA=='o'){
		DIO_voidSetPinValue(PORTB,PIN7,PIN_HIGH);
	}
	else if(UART_DATA=='p'){
		DIO_voidSetPinValue(PORTB,PIN7,PIN_LOW);
	}
}

void FANs_SPEED(u16 temp){

	u8 OCR;

	if(temp<=10){
		DIO_voidSetPinValue(PORTB,PIN4,PIN_LOW);
		DIO_voidSetPinValue(PORTB,PIN5,PIN_LOW);
		DIO_voidSetPinValue(PORTB,PIN6,PIN_LOW);
		DIO_voidSetPinValue(PORTB,PIN7,PIN_LOW);
		OCR=0;
	}
	else if(temp>10 && temp<=20){
		OCR=25;
	}
	else if(temp>20 && temp<=35){
		OCR=180;
	}
	else if(temp>35){
		OCR=255;
	}

	TIMER2_voidSetOCR2(OCR);
}

void STERRT_LAMP(u16 light){

	if(light<1000){
		DIO_voidSetPinValue(PORTD,PIN6,PIN_HIGH);
	}
	else{
		DIO_voidSetPinValue(PORTD,PIN6,PIN_LOW);
	}
}

void DOOR_LOCK(){

	u8 input[20];
	u8 i=0,j,UART_DATA,count=0;

	LCD_voidWriteString("ENTER PASSWORD!");
	LCD_voidGoToXY(1,0);

	while(1){
		STERRT_LAMP(GET_LIGHT());
		UART_DATA=UART_u8ReciveData();
		if(UART_DATA=='='){
			for(j=0;j<i;j++){
				if((input[j]!=password[j]) || (i!=password_size)){
					LCD_voidClearDisplay();
					LCD_voidGoToXY(0,0);
					LCD_voidWriteString("WRONG PASSWORD..");
					_delay_ms(100);

					LCD_voidClearDisplay();
					LCD_voidGoToXY(0,0);
					LCD_voidWriteString("ENTER PASSWORD");
					LCD_voidGoToXY(1,0);

					count++;
					if(count>=3){
						DIO_voidSetPinValue(PORTA,PIN2,PIN_HIGH);
					}

					break;
				}
			}
			if(i==0 && password_size!=0){
				LCD_voidClearDisplay();
				LCD_voidGoToXY(0,0);
				LCD_voidWriteString("WRONG PASSWORD..");
				_delay_ms(100);

				LCD_voidClearDisplay();
				LCD_voidGoToXY(0,0);
				LCD_voidWriteString("ENTER PASSWORD");
				LCD_voidGoToXY(1,0);

				count++;
				if(count>=3){
					DIO_voidSetPinValue(PORTA,PIN2,PIN_HIGH);
				}
			}
			else if(j==i){
				LCD_voidClearDisplay();
				LCD_voidGoToXY(0,0);
				LCD_voidWriteString("WELCOME..");

				LCD_voidGoToXY(1,0);
				LCD_voidWriteString("OPENNING DOOR..");
				SERVO_voidSetAngle(180);

				DIO_voidSetPinValue(PORTA,PIN2,PIN_LOW);

				_delay_ms(100);
				break;
			}
			else{
				i=0;
			}
		}
		else if(UART_DATA=='z'){
			LCD_voidClearDisplay();
			LCD_voidGoToXY(0,0);
			LCD_voidWriteString("ENTER PASSWORD");
			LCD_voidGoToXY(1,0);
			i=0;
		}
		else if((UART_DATA>='0' && UART_DATA<='9') || (UART_DATA>='*' && UART_DATA<='/') || (UART_DATA=='=')){
			input[i]=UART_DATA;
			i++;
			LCD_voidWriteData(UART_DATA);
		}
	}
}

u16 GET_TEMP(){

	u16 reading,temp;

	ADC_voidInitialize(ADC0);
	reading=ADC_voidStartConversion();
	temp=(u16)(((u32)reading*5000)/(1023*10));

	return temp;
}

u16 GET_LIGHT(){

	u16 reading,light;

	ADC_voidInitialize(ADC1);
	reading=ADC_voidStartConversion();
	light=(u16)(((u32)reading*5000*2)/1023);

	return light;
}

void DISPLAY_DATA(u16 temp,u16 light){

	LCD_voidGoToXY(0,0);
	LCD_voidWriteString("TEMP=");
	LCD_voidWriteNumber(temp);
	LCD_voidWriteString("C              ");

	LCD_voidGoToXY(1,0);
	LCD_voidWriteString("LIGHT=");
	LCD_voidWriteNumber(light);
	LCD_voidWriteString("LUX              ");
}

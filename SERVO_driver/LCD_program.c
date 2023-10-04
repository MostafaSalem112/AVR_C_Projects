#include "STD_types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#include "LCD_config.h"
#include "LCD_interface.h"
#include "avr/delay.h"


void LCD_voidIntialize(){
	
	DIO_voidSetAllPortOutput(LCD_DATA_PORT);
	
	DIO_voidSetPinDirection(LCD_CONTROL_PORT,RS,PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT,RW,PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT,EN,PIN_OUTPUT);
	
	_delay_ms(30);
	LCD_voidWriteCommand(FUN_SET_COMMAND);
	_delay_ms(2);
	LCD_voidWriteCommand(DISPLAY_CONTROL_COMMAND);
	_delay_ms(2);
	LCD_voidWriteCommand(CLEAR_COMMAND);
	
}

void LCD_voidWriteCommand(u8 Copy_u8Command){

	DIO_voidSetPinValue(LCD_CONTROL_PORT,RS,PIN_LOW);
	DIO_voidSetPinValue(LCD_CONTROL_PORT,RW,PIN_LOW);
	
	DIO_voidSetPortValue(LCD_DATA_PORT,Copy_u8Command);
	
	DIO_voidSetPinValue(LCD_CONTROL_PORT,EN,PIN_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CONTROL_PORT,EN,PIN_LOW);
}

void LCD_voidWriteData(u8 Copy_u8Data){

	DIO_voidSetPinValue(LCD_CONTROL_PORT,RS,PIN_HIGH);
	DIO_voidSetPinValue(LCD_CONTROL_PORT,RW,PIN_LOW);
	
	DIO_voidSetPortValue(LCD_DATA_PORT,Copy_u8Data);
	
	DIO_voidSetPinValue(LCD_CONTROL_PORT,EN,PIN_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CONTROL_PORT,EN,PIN_LOW);
}

void LCD_voidGoToXY(u8 Copy_u8X,u8 Copy_u8Y){
	switch(Copy_u8X){
		case LINE0:
			LCD_voidWriteCommand(LINE0_ADDRESS+Copy_u8Y);
			break;
		case LINE1:
			LCD_voidWriteCommand(LINE1_ADDRESS+Copy_u8Y);
	}
}


void LCD_voidWriteString(u8 *Copy_u8String){
	u8 i=0;
	while(Copy_u8String[i]!='\0'){
		LCD_voidWriteData(Copy_u8String[i]);
		i++;
	}
}

void LCD_voidWriteNumber(u32 Copy_u32Number){
	u8 arr[MAX_INT_DIGITS];
	u8 i=0;
	if(Copy_u32Number==0){
		LCD_voidWriteData(ZERO_ASCII);
	}
	else{
		while(Copy_u32Number>0){
			arr[i]=Copy_u32Number%10;
			Copy_u32Number/=10;
			i++;
		}
		for(u8 j=i;j>0;j--){
			LCD_voidWriteData(arr[j-1]+ZERO_ASCII);
		}		
	}
}

void LCD_voidWriteSpecialCharacter(u8 *patern,u8 Copy_u32Char,u8 Copy_u8X,u8 Copy_u8Y){
	LCD_voidWriteCommand(CGRAM_ADDRESS+Copy_u32Char*NO_BLOCK_BYTES);
	for(u8 i=0;i<NO_BLOCK_BYTES;i++){
		LCD_voidWriteData(patern[i]);
	}
	LCD_voidGoToXY(Copy_u8X,Copy_u8Y);
	LCD_voidWriteData(Copy_u32Char);
}

void LCD_voidClearDisplay(){
	LCD_voidWriteCommand(CLEAR_COMMAND);
}
#include "STD_types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#include "UART_private.h"
#include "UART_interface.h"

u8 TEMP;

void UART_voidInitialize(){
	
	SetBit(UCSRB,PIN4);
	SetBit(UCSRB,PIN3);
	
	SetBit(TEMP,PIN7);
	ClrBit(TEMP,PIN6);
	ClrBit(TEMP,PIN5);
	ClrBit(TEMP,PIN4);
	ClrBit(TEMP,PIN3);
	SetBit(TEMP,PIN2);
	SetBit(TEMP,PIN1);
	
	UCSRC=TEMP;
	
	UBRRH=0;
	UBRRL=51;
}

void UART_voidSendData(u8 Copy_u8Data){
	UDR=Copy_u8Data;
	while((GetBit(UCSRA,PIN6))==0);
	SetBit(UCSRA,PIN6);
}

u8 UART_u8ReciveData(){
	while((GetBit(UCSRA,PIN7))==0);
	return UDR;
}

void UART_voidSendString(u8 *Copy_u8String){
	u8 i=0;
	while(Copy_u8String[i]!='\0'){
		UDR=Copy_u8String[i];
		while((GetBit(UCSRA,PIN6))==0);
		SetBit(UCSRA,PIN6);
		i++;
	}
}

u8 *UART_u8_ReciveString(){
	static u8 string[20];
	u8 i=0;
	do{
		string[i]=UART_u8ReciveData();
		i++;
	}while(string[i-1]!='!');
	string[i-1]='\0';
	return string;
}

void UART_voidSendNumber(u32 Copy_u32Number){
	u8 arr[MAX_INT_DIGITS];
	u8 i=0;
	if(Copy_u32Number==0){
		UART_voidSendData(ZERO_ASCII);
	}
	else{
		while(Copy_u32Number>0){
			arr[i]=Copy_u32Number%10;
			Copy_u32Number/=10;
			i++;
		}
		for(u8 j=i;j>0;j--){
			UART_voidSendData(arr[j-1]+ZERO_ASCII);
		}		
	}
}
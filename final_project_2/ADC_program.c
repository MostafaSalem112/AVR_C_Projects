#include "STD_types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#include "ADC_private.h"
#include "ADC_interface.h"

void ADC_voidInitialize(u8 Copy_u8ADC_Channel){
	ClrBit(ADMUX,PIN7);
	SetBit(ADMUX,PIN6);
	ClrBit(ADMUX,PIN5);
	
	switch(Copy_u8ADC_Channel){
		case ADC0:
			ClrBit(ADMUX,PIN4);
			ClrBit(ADMUX,PIN3);
			ClrBit(ADMUX,PIN2);
			ClrBit(ADMUX,PIN1);
			ClrBit(ADMUX,PIN0);
			break;
		case ADC1:
			ClrBit(ADMUX,PIN4);
			ClrBit(ADMUX,PIN3);
			ClrBit(ADMUX,PIN2);
			ClrBit(ADMUX,PIN1);
			SetBit(ADMUX,PIN0);
			break;
		case ADC2:
			ClrBit(ADMUX,PIN4);
			ClrBit(ADMUX,PIN3);
			ClrBit(ADMUX,PIN2);
			SetBit(ADMUX,PIN1);
			ClrBit(ADMUX,PIN0);
			break;
		case ADC3:
			ClrBit(ADMUX,PIN4);
			ClrBit(ADMUX,PIN3);
			ClrBit(ADMUX,PIN2);
			SetBit(ADMUX,PIN1);
			SetBit(ADMUX,PIN0);
			break;
		case ADC4:
			ClrBit(ADMUX,PIN4);
			ClrBit(ADMUX,PIN3);
			SetBit(ADMUX,PIN2);
			ClrBit(ADMUX,PIN1);
			ClrBit(ADMUX,PIN0);
			break;
		case ADC5:
			ClrBit(ADMUX,PIN4);
			ClrBit(ADMUX,PIN3);
			SetBit(ADMUX,PIN2);
			ClrBit(ADMUX,PIN1);
			SetBit(ADMUX,PIN0);
			break;
		case ADC6:
			ClrBit(ADMUX,PIN4);
			ClrBit(ADMUX,PIN3);
			SetBit(ADMUX,PIN2);
			SetBit(ADMUX,PIN1);
			ClrBit(ADMUX,PIN0);
			break;
		case ADC7:
			ClrBit(ADMUX,PIN4);
			ClrBit(ADMUX,PIN3);
			SetBit(ADMUX,PIN2);
			SetBit(ADMUX,PIN1);
			SetBit(ADMUX,PIN0);
			break;
	}
	
	ClrBit(ADCSRA,PIN0);
	SetBit(ADCSRA,PIN1);
	SetBit(ADCSRA,PIN2);

	SetBit(ADCSRA,PIN7);
	SetBit(ADCSRA,PIN6);
	while((GetBit(ADCSRA,PIN4))==0);
}

u16 ADC_voidStartConversion(){

	SetBit(ADCSRA,PIN6);
	while((GetBit(ADCSRA,PIN4))==0);

	return ADC;
}

#ifndef _ADC_INTERFACE_H
#define _ADC_INTERFACE_H

#define ADC0 0
#define ADC1 1
#define ADC2 2
#define ADC3 3
#define ADC4 4
#define ADC5 5
#define ADC6 6
#define ADC7 7

//################# prototypes ########################

void ADC_voidInitialize(u8 Copy_u8ADC_Channel);
u16 ADC_voidStartConversion();

#endif
#ifndef _ADC_PRIVATE_H
#define _ADC_PRIVATE_H

#define ADMUX *((volatile u8 *)0x27)
#define ADCSRA *((volatile u8 *)0x26)
#define ADCL *((volatile u8 *)0x24)
#define ADCH *((volatile u8 *)0x25)
#define ADC *((volatile u16 *)0x24)

#endif
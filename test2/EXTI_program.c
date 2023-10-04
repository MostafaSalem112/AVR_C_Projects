#include "STD_types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#include "EXTI_private.h"
#include "EXTI_interface.h"

void (*EXTI0_GPfun)(void)=NULL;
void (*EXTI1_GPfun)(void)=NULL;
void (*EXTI2_GPfun)(void)=NULL;

void EXTI_voidInitialize(u8 Copy_u8INR_Num,u8 Copy_SenseCase){
	
	switch(Copy_u8INR_Num){
		case EXTI0:
			SetBit(GICR,PIN6);
			switch(Copy_SenseCase){
				case RISING_EDGE:
					SetBit(MCUCR,PIN0);
					SetBit(MCUCR,PIN1);
					break;
				case FALLING_EDGE:
					ClrBit(MCUCR,PIN0);
					SetBit(MCUCR,PIN1);
					break;
			}
			break;
		case EXTI1:
			SetBit(GICR,PIN7);
			switch(Copy_SenseCase){
				case RISING_EDGE:
					SetBit(MCUCR,PIN2);
					SetBit(MCUCR,PIN3);
					break;
				case FALLING_EDGE:
					ClrBit(MCUCR,PIN2);
					SetBit(MCUCR,PIN3);
					break;
			}
			break;
		case EXTI2:
			SetBit(GICR,PIN5);
			switch(Copy_SenseCase){
				case RISING_EDGE:
					SetBit(MCUCSR,PIN6);
					break;
				case FALLING_EDGE:
					ClrBit(MCUCSR,PIN6);
					break;
			}
			break;
	}
}

void EXTI0_SetCallBack(void(*ptr)(void)){
	EXTI0_GPfun=ptr;
}

void EXTI1_SetCallBack(void(*ptr)(void)){
	EXTI1_GPfun=ptr;
}

void EXTI2_SetCallBack(void(*ptr)(void)){
	EXTI2_GPfun=ptr;
}

void __vector_1()__attribute__((signal));   // EXTI0
void __vector_1(){
	
	if(EXTI0_GPfun!=NULL){
		EXTI0_GPfun();
	}
}

void __vector_2()__attribute__((signal));   // EXTI1
void __vector_2(){
	
	if(EXTI1_GPfun!=NULL){
		EXTI1_GPfun();
	}
}

void __vector_3()__attribute__((signal));   // EXTI2
void __vector_3(){
	
	if(EXTI2_GPfun!=NULL){
		EXTI2_GPfun();
	}
}


#ifndef _EXTI_INTERFACE_H
#define _EXTI_INTERFACE_H

#define EXTI0 0
#define EXTI1 1
#define EXTI2 2

#define RISING_EDGE 0
#define FALLING_EDGE 1

//################# prototypes ########################

void EXTI_voidInitialize(u8 Copy_u8INR_Num,u8 Copy_SenseCase);
void EXTI0_SetCallBack(void(*ptr)(void));
void EXTI1_SetCallBack(void(*ptr)(void));
void EXTI2_SetCallBack(void(*ptr)(void));

#endif
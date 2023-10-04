#ifndef _TIMER2_INTERFACE_H
#define _TIMER2_INTERFACE_H

/************ Waveform Generation Mode *********/
#define NORMAL 0
#define PWM_Phase_Correct 1
#define CTC 2
#define Fast_PWM 3

/************ Compare Output Mode *********/
#define OC2_Disconnected 0
#define Toggle_OC2 1
#define Clear_OC2 2
#define Set_OC2 3
#define Clear_Match_Set_Bottom 4
#define Set_Match_Clear_Bottom 5
#define Clear_Up_Set_Down 6
#define Set_Up_Clear_Down 7

/************ Clock Select, PRESCALER *********/
#define No_Prescaler 0
#define clk_8 1
#define clk_64 2
#define clk_256 3
#define clk_1024 4

/**********************************************/
#define CPU_FREQUENCY 8000000
#define MICRO_IN_SEC 1000000
#define MICRO_IN_MILLI 1000
#define MAX_8BIT_REG 256


//################# prototypes ########################

void TIMER2_voidInitialize();
void TIMER2_voidPreLoad(u8 Copy_u8Value);
void TIMER2_voidSetOCR2(u8 Copy_u8Value);
void TIMER2_voidSetTimer(u32 Copy_u32TimeMS);
void TIMER2_NORMAL_SetCallBack(void(*ptr)(void));
void TIMER2_CTC_SetCallBack(void(*ptr)(void));
#endif
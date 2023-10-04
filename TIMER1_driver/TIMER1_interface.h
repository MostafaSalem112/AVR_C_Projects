#ifndef _TIMER1_INTERFACE_H
#define _TIMER1_INTERFACE_H

#define RISING_EDGE 0
#define FALLING_EDGE 1

#define Set_Freq_50Hz 20000
#define CPU_FREQUENCY 8000000
#define MICRO_IN_SEC 1000000
#define MICRO_IN_MILLI 1000
#define MAX_16BIT_REG 0xffff

/************** select OUTPUT_PIN A/B *********************/
#define TIMER1A 0
#define TIMER1B 1

/************ Clock Select, PRESCALER *********/
#define No_Prescaler 0
#define clk_8 1
#define clk_64 2
#define clk_256 3
#define clk_1024 4

/************ Waveform Generation Mode *********/
#define NORMAL 0
#define PWM_Phase_Correct_8bit 1
#define PWM_Phase_Correct_9bit 2
#define PWM_Phase_Correct_10bit 3
#define CTC_OCR1A 4
#define Fast_PWM_8bit 5
#define Fast_PWM_9bit 6
#define Fast_PWM_10bit 7
#define PWM_Phase_Freq_Correct_ICR1 8
#define PWM_Phase_Freq_Correct_OCR1A 9
#define PWM_Phase_Correct_ICR1 10
#define PWM_Phase_Correct_OCR1A 11
#define CTC_ICR1 12
#define Fast_PWM_ICR1 13
#define Fast_PWM_OCR1A 14

/************ Compare Output Mode *********/
#define OC1_Disconnected 0
#define Toggle_OC1 1
#define Clear_OC1 2
#define Set_OC1 3
#define Toggle_OC1A_Match 4
#define Clear_Match_Set_Bottom 5
#define Set_Match_Clear_Bottom 6
#define Clear_Up_Set_Down 7
#define Set_Up_Clear_Down 8

//################# prototypes ########################
void TIMER1_voidInitialize();
void TIMER1_voidEnableICU();
void TIMER1_voidICUEdge(u8 Copy_u8ICUEdge);
void TIMER1_voidSetOCR1(u16 Copy_u16Value);
void TIMER1_voidSetICR1(u16 Copy_u16Value);
u16 TIMER1_u16GetICR1();
void TIMER1_voidPreLoad(u16 Copy_u16Value);
void TIMER1_voidSetTimer(u32 Copy_u32TimeMS);
void TIMER1_ICU_SetCallBack(void(*ptr)(void));
void TIMER1_CTCA_SetCallBack(void(*ptr)(void));
void TIMER1_CTCB_SetCallBack(void(*ptr)(void));
void TIMER1_NORMAL_SetCallBack(void(*ptr)(void));

#endif
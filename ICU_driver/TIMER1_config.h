#ifndef _TIMER1_CONFIG_H
#define _TIMER1_CONFIG_H

/************** select OUTPUT_PIN A/B *********************/
// TIMER1A
// TIMER1B
/**********************************************************/
#define TIMER_SELECT TIMER1A
/**********************************************************/

/************ Clock Select, PRESCALER *********/
// No_Prescaler
// clk_8
// clk_64
// clk_256
// clk_1024
/***********************************************/
#define Clock_Select clk_8
/***********************************************/

/************ Waveform Generation Mode *********/
// NORMAL
// PWM_Phase_Correct_8bit
// PWM_Phase_Correct_9bit
// PWM_Phase_Correct_10bit
// CTC_OCR1A
// Fast_PWM_8bit
// Fast_PWM_9bit
// Fast_PWM_10bit
// PWM_Phase_Freq_Correct_ICR1
// PWM_Phase_Freq_Correct_OCR1A
// PWM_Phase_Correct_ICR1
// PWM_Phase_Correct_OCR1A
// CTC_ICR1
// Fast_PWM_ICR1
// Fast_PWM_OCR1A
/***********************************************/
#define Waveform_MODE NORMAL
/***********************************************/

/************ Compare Output Mode, non-PWM Mode *********/
// OC1_Disconnected
// Toggle_OC1
// Clear_OC1
// Set_OC1
/***********************************************/

/************ Compare Output Mode, Fast PWM Mode *********/
// OC1_Disconnected
// Toggle_OC1A_Match       ==> TIMER1A ONLY
// Clear_Match_Set_Bottom
// Set_Match_Clear_Bottom
/***********************************************/

/************ Compare Output Mode, Phase Correct and Phase and Frequency Correct PWM *********/
// OC1_Disconnected
// Toggle_OC1A_Match       ==> TIMER1A ONLY
// Clear_Up_Set_Down
// Set_Up_Clear_Down
/***********************************************/
#define Compare_Output_Mode OC1_Disconnected
/***********************************************/

#endif
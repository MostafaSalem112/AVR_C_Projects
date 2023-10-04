#ifndef _TIMER2_CONFIG_H
#define _TIMER2_CONFIG_H

/************ Waveform Generation Mode *********/
// NORMAL
// PWM_Phase_Correct
// CTC
// Fast_PWM
/***********************************************/
#define Waveform_MODE NORMAL
/***********************************************/

/************ Compare Output Mode, non-PWM Mode *********/
// OC2_Disconnected
// Toggle_OC2
// Clear_OC2
// Set_OC2
/***********************************************/

/************ Compare Output Mode, Fast PWM Mode *********/
// OC2_Disconnected
// Clear_Match_Set_Bottom
// Set_Match_Clear_Bottom
/***********************************************/

/************ Compare Output Mode, Phase Correct PWM Mode *********/
// OC2_Disconnected
// Clear_Up_Set_Down
// Set_Up_Clear_Down
/***********************************************/
#define Compare_Output_Mode Toggle_OC0
/***********************************************/

/************ Clock Select, PRESCALER *********/
// No_Prescaler
// clk_8
// clk_64
// clk_256
// clk_1024
/***********************************************/
#define Clock_Select clk_8
/***********************************************/

#endif
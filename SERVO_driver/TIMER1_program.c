#include "STD_types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#include "TIMER1_private.h"
#include "TIMER1_interface.h"
#include "TIMER1_config.h"

void (*TIMER1_NORMAL_GPfun)(void)=NULL;
void (*TIMER1_CTCA_GPfun)(void)=NULL;
void (*TIMER1_CTCB_GPfun)(void)=NULL;
void (*TIMER1_ICU_GPfun)(void)=NULL;

u32 TIMER,PreLoad,PreScaler;

void TIMER1_voidInitialize(){

/************ Clock Select, PRESCALER *********/
#if Clock_Select == No_Prescaler
	SetBit(TCCR1B,PIN0);
	ClrBit(TCCR1B,PIN1);
	ClrBit(TCCR1B,PIN2);
	PreScaler=1;
#elif Clock_Select == clk_8
	ClrBit(TCCR1B,PIN0);
	SetBit(TCCR1B,PIN1);
	ClrBit(TCCR1B,PIN2);
	PreScaler=8;
#elif Clock_Select == clk_64
	SetBit(TCCR1B,PIN0);
	SetBit(TCCR1B,PIN1);
	ClrBit(TCCR1B,PIN2);
	PreScaler=64;
#elif Clock_Select == clk_256
	ClrBit(TCCR1B,PIN0);
	ClrBit(TCCR1B,PIN1);
	SetBit(TCCR1B,PIN2);
	PreScaler=256;
#elif Clock_Select == clk_1024
	SetBit(TCCR1B,PIN0);
	ClrBit(TCCR1B,PIN1);
	SetBit(TCCR1B,PIN2);
	PreScaler=1024;
#endif

/************ Compare Output Mode *********/
#if TIMER_SELECT == TIMER1A
	#if Compare_Output_Mode == OC1_Disconnected
		ClrBit(TCCR1A,PIN6);
		ClrBit(TCCR1A,PIN7);
	#elif (Compare_Output_Mode == Toggle_OC1)||(Compare_Output_Mode == Toggle_OC1A_Match)
		SetBit(TCCR1A,PIN6);
		ClrBit(TCCR1A,PIN7);
	#elif (Compare_Output_Mode == Clear_OC1)||(Compare_Output_Mode == Clear_Match_Set_Bottom)||(Compare_Output_Mode == Clear_Up_Set_Down)
		ClrBit(TCCR1A,PIN6);
		SetBit(TCCR1A,PIN7);
	#elif (Compare_Output_Mode == Set_OC1)||(Compare_Output_Mode == Set_Match_Clear_Bottom)||(Compare_Output_Mode == Set_Up_Clear_Down)
		SetBit(TCCR1A,PIN6);
		SetBit(TCCR1A,PIN7);
	#endif
#elif TIMER_SELECT == TIMER1B
	#if Compare_Output_Mode == OC1_Disconnected
		ClrBit(TCCR1A,PIN4);
		ClrBit(TCCR1A,PIN5);
	#elif (Compare_Output_Mode == Toggle_OC1)||(Compare_Output_Mode == Toggle_OC1A_Match)
		SetBit(TCCR1A,PIN4);
		ClrBit(TCCR1A,PIN5);
	#elif (Compare_Output_Mode == Clear_OC1)||(Compare_Output_Mode == Clear_Match_Set_Bottom)||(Compare_Output_Mode == Clear_Up_Set_Down)
		ClrBit(TCCR1A,PIN4);
		SetBit(TCCR1A,PIN5);
	#elif (Compare_Output_Mode == Set_OC1)||(Compare_Output_Mode == Set_Match_Clear_Bottom)||(Compare_Output_Mode == Set_Up_Clear_Down)
		SetBit(TCCR1A,PIN4);
		SetBit(TCCR1A,PIN5);
	#endif
#endif

/************ Waveform Generation Mode *********/
#if Waveform_MODE == NORMAL
	ClrBit(TCCR1A,PIN0);
	ClrBit(TCCR1A,PIN1);
	ClrBit(TCCR1B,PIN3);
	ClrBit(TCCR1B,PIN4);
	SetBit(TIMSK,PIN2);
#elif Waveform_MODE == PWM_Phase_Correct_8bit
	SetBit(TCCR1A,PIN0);
	ClrBit(TCCR1A,PIN1);
	ClrBit(TCCR1B,PIN3);
	ClrBit(TCCR1B,PIN4);
#elif Waveform_MODE == PWM_Phase_Correct_9bit
	ClrBit(TCCR1A,PIN0);
	SetBit(TCCR1A,PIN1);
	ClrBit(TCCR1B,PIN3);
	ClrBit(TCCR1B,PIN4);
#elif Waveform_MODE == PWM_Phase_Correct_10bit
	SetBit(TCCR1A,PIN0);
	SetBit(TCCR1A,PIN1);
	ClrBit(TCCR1B,PIN3);
	ClrBit(TCCR1B,PIN4);
#elif Waveform_MODE == CTC_OCR1A
	ClrBit(TCCR1A,PIN0);
	ClrBit(TCCR1A,PIN1);
	SetBit(TCCR1B,PIN3);
	ClrBit(TCCR1B,PIN4);
	#if TIMER_SELECT == TIMER1A
		SetBit(TIMSK,PIN4);
	#elif TIMER_SELECT == TIMER1B
		SetBit(TIMSK,PIN3);
	#endif
#elif Waveform_MODE == Fast_PWM_8bit
	SetBit(TCCR1A,PIN0);
	ClrBit(TCCR1A,PIN1);
	SetBit(TCCR1B,PIN3);
	ClrBit(TCCR1B,PIN4);
#elif Waveform_MODE == Fast_PWM_9bit
	ClrBit(TCCR1A,PIN0);
	SetBit(TCCR1A,PIN1);
	SetBit(TCCR1B,PIN3);
	ClrBit(TCCR1B,PIN4);
#elif Waveform_MODE == Fast_PWM_10bit
	SetBit(TCCR1A,PIN0);
	SetBit(TCCR1A,PIN1);
	SetBit(TCCR1B,PIN3);
	ClrBit(TCCR1B,PIN4);
#elif Waveform_MODE == PWM_Phase_Freq_Correct_ICR1
	ClrBit(TCCR1A,PIN0);
	ClrBit(TCCR1A,PIN1);
	ClrBit(TCCR1B,PIN3);
	SetBit(TCCR1B,PIN4);
#elif Waveform_MODE == PWM_Phase_Freq_Correct_OCR1A
	SetBit(TCCR1A,PIN0);
	ClrBit(TCCR1A,PIN1);
	ClrBit(TCCR1B,PIN3);
	SetBit(TCCR1B,PIN4);
#elif Waveform_MODE == PWM_Phase_Correct_ICR1
	ClrBit(TCCR1A,PIN0);
	SetBit(TCCR1A,PIN1);
	ClrBit(TCCR1B,PIN3);
	SetBit(TCCR1B,PIN4);
#elif Waveform_MODE == PWM_Phase_Correct_OCR1A
	SetBit(TCCR1A,PIN0);
	SetBit(TCCR1A,PIN1);
	ClrBit(TCCR1B,PIN3);
	SetBit(TCCR1B,PIN4);
#elif Waveform_MODE == CTC_ICR1
	ClrBit(TCCR1A,PIN0);
	ClrBit(TCCR1A,PIN1);
	SetBit(TCCR1B,PIN3);
	SetBit(TCCR1B,PIN4);
	#if TIMER_SELECT == TIMER1A
		SetBit(TIMSK,PIN4);
	#elif TIMER_SELECT == TIMER1B
		SetBit(TIMSK,PIN3);
	#endif
#elif Waveform_MODE == Fast_PWM_ICR1
	ClrBit(TCCR1A,PIN0);
	SetBit(TCCR1A,PIN1);
	SetBit(TCCR1B,PIN3);
	SetBit(TCCR1B,PIN4);
#elif Waveform_MODE == Fast_PWM_OCR1A
	SetBit(TCCR1A,PIN0);
	SetBit(TCCR1A,PIN1);
	SetBit(TCCR1B,PIN3);
	SetBit(TCCR1B,PIN4);
#endif
}

void TIMER1_voidEnableICU(){
	
	SetBit(TIMSK,PIN5);
}

void TIMER1_voidICUEdge(u8 Copy_u8ICUEdge){
	switch(Copy_u8ICUEdge){
		case RISING_EDGE:
			SetBit(TCCR1B,PIN6);
			break;
		case FALLING_EDGE:
			ClrBit(TCCR1B,PIN6);
			break;
	}
}

void TIMER1_voidSetOCR1(u16 Copy_u16Value){
	#if TIMER_SELECT == TIMER1A
		OCR1A=Copy_u16Value;
	#elif TIMER_SELECT == TIMER1B
		OCR1B=Copy_u16Value;
	#endif	
}

void TIMER1_voidSetICR1(u16 Copy_u16Value){
	
	ICR1=Copy_u16Value;
}

u16 TIMER1_u16GetICR1(){
	
	return ICR1;
}

void TIMER1_voidPreLoad(u16 Copy_u16Value){
	
	TCNT1=Copy_u16Value;
}


void TIMER1_voidSetTimer(u32 Copy_u32TimeMS){
	
	u32 MAX_NUM;
	#if Waveform_MODE == NORMAL
		MAX_NUM=MAX_16BIT_REG;
	#elif Waveform_MODE == CTC_OCR1A
		MAX_NUM=OCR1A;
	#elif Waveform_MODE == CTC_ICR1
		MAX_NUM=ICR1;
	#endif
	
	u32 TIMER_freq=CPU_FREQUENCY/PreScaler;
	f32 Tick_Time=MICRO_IN_SEC/TIMER_freq;
	u32 OverFlow_Time=Tick_Time*MAX_NUM;
	
	TIMER=(Copy_u32TimeMS*MICRO_IN_MILLI)/OverFlow_Time;
	f32 remainder=((Copy_u32TimeMS*MICRO_IN_MILLI)%OverFlow_Time)/(f32)OverFlow_Time;
	PreLoad=(1-remainder)*MAX_NUM;
	
	TIMER1_voidPreLoad(PreLoad);
}

void TIMER1_ICU_SetCallBack(void(*ptr)(void)){
	
	TIMER1_ICU_GPfun=ptr;
}

void TIMER1_CTCA_SetCallBack(void(*ptr)(void)){
	
	TIMER1_CTCA_GPfun=ptr;
}

void TIMER1_CTCB_SetCallBack(void(*ptr)(void)){
	
	TIMER1_CTCB_GPfun=ptr;
}

void TIMER1_NORMAL_SetCallBack(void(*ptr)(void)){
			
	TIMER1_NORMAL_GPfun=ptr;
}

void __vector_6()__attribute__((signal));   // TIMER1_ICU
void __vector_6(){

	if(TIMER1_ICU_GPfun!=NULL){
		TIMER1_ICU_GPfun();
	}
}

void __vector_7()__attribute__((signal));   // TIMER1_CTCA
void __vector_7(){
	
	static u32 counter=0;
	
	if(counter==TIMER+1){
		if(TIMER1_CTCA_GPfun!=NULL){
			TIMER1_CTCA_GPfun();
		}
		counter=0;
		TIMER1_voidPreLoad(PreLoad);
	}
	else{
		counter++;
	}
}

void __vector_8()__attribute__((signal));   // TIMER1_CTCB
void __vector_8(){
	
	static u32 counter=0;
	
	if(counter==TIMER+1){
		if(TIMER1_CTCB_GPfun!=NULL){
			TIMER1_CTCB_GPfun();
		}
		counter=0;
		TIMER1_voidPreLoad(PreLoad);
	}
	else{
		counter++;
	}
}

void __vector_9()__attribute__((signal));   // TIMER1_NORMAL
void __vector_9(){
	
	static u32 counter=0;
	
	if(counter==TIMER+1){
		if(TIMER1_NORMAL_GPfun!=NULL){
			TIMER1_NORMAL_GPfun();
		}
		counter=0;
		TIMER1_voidPreLoad(PreLoad);
	}
	else{
		counter++;
	}
}
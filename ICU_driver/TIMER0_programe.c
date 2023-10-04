#include "STD_types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#include "TIMER0_private.h"
#include "TIMER0_interface.h"
#include "TIMER0_config.h"

void (*TIMER0_NORMAL_GPfun)(void)=NULL;
void (*TIMER0_CTC_GPfun)(void)=NULL;

u32 TIMER,PreLoad,PreScaler;

void TIMER0_voidInitialize(){

/************ Clock Select, PRESCALER *********/	
#if Clock_Select == No_Prescaler
	SetBit(TCCR0,PIN0);
	ClrBit(TCCR0,PIN1);
	ClrBit(TCCR0,PIN2);
	PreScaler=1;
#elif Clock_Select == clk_8
	ClrBit(TCCR0,PIN0);
	SetBit(TCCR0,PIN1);
	ClrBit(TCCR0,PIN2);
	PreScaler=8;
#elif Clock_Select == clk_64
	SetBit(TCCR0,PIN0);
	SetBit(TCCR0,PIN1);
	ClrBit(TCCR0,PIN2);
	PreScaler=64;
#elif Clock_Select == clk_256
	ClrBit(TCCR0,PIN0);
	ClrBit(TCCR0,PIN1);
	SetBit(TCCR0,PIN2);
	PreScaler=256;
#elif Clock_Select == clk_1024
	SetBit(TCCR0,PIN0);
	ClrBit(TCCR0,PIN1);
	SetBit(TCCR0,PIN2);
	PreScaler=1024;
#endif

/************ Compare Output Mode *********/
#if Compare_Output_Mode == OC0_Disconnected
	ClrBit(TCCR0,PIN4);
	ClrBit(TCCR0,PIN5);
#elif Compare_Output_Mode == Toggle_OC0
	SetBit(TCCR0,PIN4);
	ClrBit(TCCR0,PIN5);
#elif (Compare_Output_Mode == Clear_OC0)||(Compare_Output_Mode == Clear_Match_Set_Bottom)||(Compare_Output_Mode == Clear_Up_Set_Down)
	ClrBit(TCCR0,PIN4);
	SetBit(TCCR0,PIN5);
#elif (Compare_Output_Mode == Set_OC0)||(Compare_Output_Mode == Set_Match_Clear_Bottom)||(Compare_Output_Mode == Set_Up_Clear_Down)
	SetBit(TCCR0,PIN4);
	SetBit(TCCR0,PIN5);
#endif

/************ Waveform Generation Mode *********/
#if Waveform_MODE == NORMAL
	ClrBit(TCCR0,PIN3);
	ClrBit(TCCR0,PIN6);
	SetBit(TIMSK,PIN0);
#elif Waveform_MODE == PWM_Phase_Correct
	ClrBit(TCCR0,PIN3);
	SetBit(TCCR0,PIN6);
#elif Waveform_MODE == CTC
	SetBit(TCCR0,PIN3);
	ClrBit(TCCR0,PIN6);
	SetBit(TIMSK,PIN1);
#elif Waveform_MODE == Fast_PWM
	SetBit(TCCR0,PIN3);
	SetBit(TCCR0,PIN6);
#endif
}

void TIMER0_voidPreLoad(u8 Copy_u8Value){
	
	TCNT0=Copy_u8Value;
}

void TIMER0_voidSetOCR0(u8 Copy_u8Value){
	
	OCR0=Copy_u8Value;
}

void TIMER0_voidSetTimer(u32 Copy_u32TimeMS){
	
	u32 MAX_NUM;
	if(Waveform_MODE == NORMAL){
		MAX_NUM=MAX_8BIT_REG;
	}
	else if(Waveform_MODE == CTC){
		MAX_NUM=OCR0;
	}
	
	u32 TIMER_freq=CPU_FREQUENCY/PreScaler;
	f32 Tick_Time=MICRO_IN_SEC/TIMER_freq;
	u32 OverFlow_Time=Tick_Time*MAX_NUM;
	
	TIMER=(Copy_u32TimeMS*MICRO_IN_MILLI)/OverFlow_Time;
	f32 remainder=((Copy_u32TimeMS*MICRO_IN_MILLI)%OverFlow_Time)/(f32)OverFlow_Time;
	PreLoad=(1-remainder)*MAX_NUM;
	
	TIMER0_voidPreLoad(PreLoad);
}

void TIMER0_NORMAL_SetCallBack(void(*ptr)(void)){
			
	TIMER0_NORMAL_GPfun=ptr;
}

void TIMER0_CTC_SetCallBack(void(*ptr)(void)){
	
	TIMER0_CTC_GPfun=ptr;
}

void __vector_10()__attribute__((signal));   // TIMER0_CTC
void __vector_10(){
	
	static u32 counter=0;
	
	if(counter==TIMER+1){
		if(TIMER0_CTC_GPfun!=NULL){
			TIMER0_CTC_GPfun();
		}
		counter=0;
		TIMER0_voidPreLoad(PreLoad);
	}
	else{
		counter++;
	}
	
}

void __vector_11()__attribute__((signal));   // TIMER0_NORMAL
void __vector_11(){
	
	static u32 counter=0;
	
	if(counter==TIMER+1){
		if(TIMER0_NORMAL_GPfun!=NULL){
			TIMER0_NORMAL_GPfun();
		}
		counter=0;
		TIMER0_voidPreLoad(PreLoad);
	}
	else{
		counter++;
	}
	
}

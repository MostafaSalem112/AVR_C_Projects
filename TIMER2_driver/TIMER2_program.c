#include "STD_types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#include "TIMER2_private.h"
#include "TIMER2_interface.h"
#include "TIMER2_config.h"

void (*TIMER2_NORMAL_GPfun)(void)=NULL;
void (*TIMER2_CTC_GPfun)(void)=NULL;

u32 TIMER,PreLoad,PreScaler;

void TIMER2_voidInitialize(){

/************ Clock Select, PRESCALER *********/	
#if Clock_Select == No_Prescaler
	SetBit(TCCR2,PIN0);
	ClrBit(TCCR2,PIN1);
	ClrBit(TCCR2,PIN2);
	PreScaler=1;
#elif Clock_Select == clk_8
	ClrBit(TCCR2,PIN0);
	SetBit(TCCR2,PIN1);
	ClrBit(TCCR2,PIN2);
	PreScaler=8;
#elif Clock_Select == clk_64
	SetBit(TCCR2,PIN0);
	SetBit(TCCR2,PIN1);
	ClrBit(TCCR2,PIN2);
	PreScaler=64;
#elif Clock_Select == clk_256
	ClrBit(TCCR2,PIN0);
	ClrBit(TCCR2,PIN1);
	SetBit(TCCR2,PIN2);
	PreScaler=256;
#elif Clock_Select == clk_1024
	SetBit(TCCR2,PIN0);
	ClrBit(TCCR2,PIN1);
	SetBit(TCCR2,PIN2);
	PreScaler=1024;
#endif

/************ Compare Output Mode *********/
#if Compare_Output_Mode == OC2_Disconnected
	ClrBit(TCCR2,PIN4);
	ClrBit(TCCR2,PIN5);
#elif Compare_Output_Mode == Toggle_OC2
	SetBit(TCCR2,PIN4);
	ClrBit(TCCR2,PIN5);
#elif (Compare_Output_Mode == Clear_OC2)||(Compare_Output_Mode == Clear_Match_Set_Bottom)||(Compare_Output_Mode == Clear_Up_Set_Down)
	ClrBit(TCCR2,PIN4);
	SetBit(TCCR2,PIN5);
#elif (Compare_Output_Mode == Set_OC2)||(Compare_Output_Mode == Set_Match_Clear_Bottom)||(Compare_Output_Mode == Set_Up_Clear_Down)
	SetBit(TCCR2,PIN4);
	SetBit(TCCR2,PIN5);
#endif

/************ Waveform Generation Mode *********/
#if Waveform_MODE == NORMAL
	ClrBit(TCCR2,PIN3);
	ClrBit(TCCR2,PIN6);
	SetBit(TIMSK,PIN6);
#elif Waveform_MODE == PWM_Phase_Correct
	ClrBit(TCCR2,PIN3);
	SetBit(TCCR2,PIN6);
#elif Waveform_MODE == CTC
	SetBit(TCCR2,PIN3);
	ClrBit(TCCR2,PIN6);
	SetBit(TIMSK,PIN7);
#elif Waveform_MODE == Fast_PWM
	SetBit(TCCR2,PIN3);
	SetBit(TCCR2,PIN6);
#endif
}

void TIMER2_voidPreLoad(u8 Copy_u8Value){
	
	TCNT2=Copy_u8Value;
}

void TIMER2_voidSetOCR2(u8 Copy_u8Value){
	
	OCR2=Copy_u8Value;
}

void TIMER2_voidSetTimer(u32 Copy_u32TimeMS){
	
	u32 MAX_NUM;
	if(Waveform_MODE == NORMAL){
		MAX_NUM=MAX_8BIT_REG;
	}
	else if(Waveform_MODE == CTC){
		MAX_NUM=OCR2;
	}
	
	u32 TIMER_freq=CPU_FREQUENCY/PreScaler;
	f32 Tick_Time=MICRO_IN_SEC/TIMER_freq;
	u32 OverFlow_Time=Tick_Time*MAX_NUM;
	
	TIMER=(Copy_u32TimeMS*MICRO_IN_MILLI)/OverFlow_Time;
	f32 remainder=((Copy_u32TimeMS*MICRO_IN_MILLI)%OverFlow_Time)/(f32)OverFlow_Time;
	PreLoad=(1-remainder)*MAX_NUM;
	
	TIMER2_voidPreLoad(PreLoad);
}

void TIMER2_NORMAL_SetCallBack(void(*ptr)(void)){
			
	TIMER2_NORMAL_GPfun=ptr;
}

void TIMER2_CTC_SetCallBack(void(*ptr)(void)){
	
	TIMER2_CTC_GPfun=ptr;
}

void __vector_4()__attribute__((signal));   // TIMER2_CTC
void __vector_4(){
	
	static u32 counter=0;
	
	if(counter==TIMER+1){
		if(TIMER2_CTC_GPfun!=NULL){
			TIMER2_CTC_GPfun();
		}
		counter=0;
		TIMER2_voidPreLoad(PreLoad);
	}
	else{
		counter++;
	}
	
}

void __vector_5()__attribute__((signal));   // TIMER2_NORMAL
void __vector_5(){
	
	static u32 counter=0;
	
	if(counter==TIMER+1){
		if(TIMER2_NORMAL_GPfun!=NULL){
			TIMER2_NORMAL_GPfun();
		}
		counter=0;
		TIMER2_voidPreLoad(PreLoad);
	}
	else{
		counter++;
	}
	
}

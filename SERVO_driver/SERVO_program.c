#include "STD_types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#include "TIMER1_interface.h"
#include "SERVO_interface.h"

void SERVO_voidSetAngle(u8 Copy_u8Angle){
	u32 timer;
	f32 slop;
	TIMER1_voidInitialize();
	TIMER1_voidSetICR1(Set_Freq_50Hz);
	
	slop=50.0/9;
	timer=slop*Copy_u8Angle+999;
	
	TIMER1_voidSetOCR1(timer);
}
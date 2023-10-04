/*
 * main.c
 *
 *  Created on: Aug 23, 2022
 *      Author: mostafa
 */

/*#include "STD_types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#include "TIMER0_interface.h"
#include "TIMER1_interface.h"
#include "GIE_interface.h"
#include "LCD_interface.h"

static u8 flag=0;
static u32 snap1=0,snap2=0,snap3=0,counter=0;
static u32 Ton,Ttotal;

void func1(void){
	if(flag==0){
		snap1=TIMER1_u16GetICR1()+counter*MAX_16BIT_REG;
		TIMER1_voidICUEdge(FALLING_EDGE);
		flag=1;
		counter=0;
	}
	else if(flag==1){
		snap2=TIMER1_u16GetICR1()+counter*MAX_16BIT_REG;
		TIMER1_voidICUEdge(RISING_EDGE);
		flag=2;
		counter=0;
	}
	else if(flag==2){
		snap3=TIMER1_u16GetICR1()+counter*MAX_16BIT_REG;
		flag=3;
		counter=0;
	}
}

void func2(void){
	counter++;
}

int main(){

	GIE_voidEnable();
	TIMER0_voidInitialize();
	TIMER1_voidInitialize();
	LCD_voidIntialize();

	DIO_voidSetPinDirection(PORTB,PIN3,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTD,PIN6,PIN_INPUT);


	TIMER1_voidICUEdge(RISING_EDGE);
	TIMER1_voidEnableICU();

	TIMER1_ICU_SetCallBack(func1);
	TIMER1_NORMAL_SetCallBack(func2);

	TIMER0_voidSetOCR0(0);

	while(1){
		if(flag==3){
			Ton=snap2-snap1;
			Ttotal=snap3;
			LCD_voidGoToXY(0,0);
			LCD_voidWriteNumber((Ton*100)/Ttotal);
			LCD_voidWriteString("                  ");
			LCD_voidGoToXY(1,0);
			LCD_voidWriteNumber(1000000/Ttotal);
			LCD_voidWriteString("                  ");
			flag=0;
		}
	}

	return 0;
}
*/
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include "LCD_interface.h"

int main ( )
{
	unsigned int a,b,c,high,period;
	char frequency[14],duty_cy[7];

	LCD_voidIntialize();
	PORTD = 0xFF;			/* Turn ON pull-up resistor */

	while(1)
	{
		TCCR1A = 0;
		TCNT1=0;
		TIFR = (1<<ICF1);  	/* Clear ICF (Input Capture flag) flag */

		TCCR1B = 0x41;  	/* Rising edge, no prescaler */
		while ((TIFR&(1<<ICF1)) == 0);
		a = ICR1;  		/* Take value of capture register */
		TIFR = (1<<ICF1);  	/* Clear ICF flag */

		TCCR1B = 0x01;  	/* Falling edge, no prescaler */
		while ((TIFR&(1<<ICF1)) == 0);
		b = ICR1;  		/* Take value of capture register */
		TIFR = (1<<ICF1);  	/* Clear ICF flag */

		TCCR1B = 0x41;  	/* Rising edge, no prescaler */
		while ((TIFR&(1<<ICF1)) == 0);
		c = ICR1;  		/* Take value of capture register */
		TIFR = (1<<ICF1);  	/* Clear ICF flag */

		TCCR1B = 0;  		/* Stop the timer */

		if(a<b && b<c)  	/* Check for valid condition,
					to avoid timer overflow reading */
		{
			high=b-a;
			period=c-a;

			long freq= F_CPU/period;/* Calculate frequency */

						/* Calculate duty cycle */
            		float duty_cycle =((float) high /(float)period)*100;
			ltoa(freq,frequency,10);

			itoa((int)duty_cycle,duty_cy,10);

			LCD_voidGoToXY(0,0);
			LCD_voidWriteString("Freq: ");
			LCD_voidWriteString(frequency);
			LCD_voidWriteString(" Hz    ");

			LCD_voidGoToXY(1,0);
			LCD_voidWriteString("Duty: ");
			LCD_voidWriteString(duty_cy);
			LCD_voidWriteString(" %      ");

		}

		else
		{
			LCD_voidClearDisplay();
			LCD_voidWriteString("OUT OF RANGE!!");
		}
		_delay_ms(50);
	}

}

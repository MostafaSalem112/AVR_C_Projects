#include "STD_types.h"
#include "Bit_Math.h"
#include "DIO_config.h"
#include "DIO_private.h"
#include "DIO_interface.h"

void DIO_voidSetPinDirection(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinDir){
	if(Copy_u8PinDir==PIN_OUTPUT){     //output
		switch(Copy_u8PortID){
			case PORTA/*Port A*/: SetBit(DDRA_REG,Copy_u8PinID);break;
			case PORTB/*Port B*/: SetBit(DDRB_REG,Copy_u8PinID);break;
			case PORTC/*Port C*/: SetBit(DDRC_REG,Copy_u8PinID);break;
			case PORTD/*Port D*/: SetBit(DDRD_REG,Copy_u8PinID);break;
		}
	}
	else if(Copy_u8PinDir==PIN_INPUT){ //input
		switch(Copy_u8PortID){
			case PORTA/*Port A*/: ClrBit(DDRA_REG,Copy_u8PinID);break;
			case PORTB/*Port B*/: ClrBit(DDRB_REG,Copy_u8PinID);break;
			case PORTC/*Port C*/: ClrBit(DDRC_REG,Copy_u8PinID);break;
			case PORTD/*Port D*/: ClrBit(DDRD_REG,Copy_u8PinID);break;
		}
	}
}

void DIO_voidSetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinValue){
	if(Copy_u8PinValue==PIN_HIGH){      //high
		switch(Copy_u8PortID){
			case PORTA/*Port A*/: SetBit(PORTA_REG,Copy_u8PinID);break;
			case PORTB/*Port B*/: SetBit(PORTB_REG,Copy_u8PinID);break;
			case PORTC/*Port C*/: SetBit(PORTC_REG,Copy_u8PinID);break;
			case PORTD/*Port D*/: SetBit(PORTD_REG,Copy_u8PinID);break;
		}
	}
	else if(Copy_u8PinValue==PIN_LOW){  //low
		switch(Copy_u8PortID){
			case PORTA/*Port A*/: ClrBit(PORTA_REG,Copy_u8PinID);break;
			case PORTB/*Port B*/: ClrBit(PORTB_REG,Copy_u8PinID);break;
			case PORTC/*Port C*/: ClrBit(PORTC_REG,Copy_u8PinID);break;
			case PORTD/*Port D*/: ClrBit(PORTD_REG,Copy_u8PinID);break;
		}
	}	
}

void DIO_voidSetPortDirection(u8 Copy_u8PortID,u8 Copy_u8PortDir){
	switch(Copy_u8PortID){
		case PORTA/*Port A*/: DDRA_REG=Copy_u8PortDir;break;
		case PORTB/*Port B*/: DDRB_REG=Copy_u8PortDir;break;
		case PORTC/*Port C*/: DDRC_REG=Copy_u8PortDir;break;
		case PORTD/*Port D*/: DDRD_REG=Copy_u8PortDir;break;
	}
}

void DIO_voidSetAllPortInput(u8 Copy_u8PortID){
	switch(Copy_u8PortID){
		case PORTA/*Port A*/: DDRA_REG=PORT_INPUT;break;
		case PORTB/*Port B*/: DDRB_REG=PORT_INPUT;break;
		case PORTC/*Port C*/: DDRC_REG=PORT_INPUT;break;
		case PORTD/*Port D*/: DDRD_REG=PORT_INPUT;break;
	}
}

void DIO_voidSetAllPortOutput(u8 Copy_u8PortID){
	switch(Copy_u8PortID){
		case PORTA/*Port A*/: DDRA_REG=PORT_OUTPUT;break;
		case PORTB/*Port B*/: DDRB_REG=PORT_OUTPUT;break;
		case PORTC/*Port C*/: DDRC_REG=PORT_OUTPUT;break;
		case PORTD/*Port D*/: DDRD_REG=PORT_OUTPUT;break;
	}
}

void DIO_voidSetPortValue(u8 Copy_u8PortID,u8 Copy_u8PortValue){
	switch(Copy_u8PortID){
		case PORTA/*Port A*/: PORTA_REG=Copy_u8PortValue;break;
		case PORTB/*Port B*/: PORTB_REG=Copy_u8PortValue;break;
		case PORTC/*Port C*/: PORTC_REG=Copy_u8PortValue;break;
		case PORTD/*Port D*/: PORTD_REG=Copy_u8PortValue;break;
	}
}

void DIO_voidSetAllPortLow(u8 Copy_u8PortID){
	switch(Copy_u8PortID){
		case PORTA/*Port A*/: PORTA_REG=PORT_LOW;break;
		case PORTB/*Port B*/: PORTB_REG=PORT_LOW;break;
		case PORTC/*Port C*/: PORTC_REG=PORT_LOW;break;
		case PORTD/*Port D*/: PORTD_REG=PORT_LOW;break;
	}
}

void DIO_voidSetAllPortHigh(u8 Copy_u8PortID){
	switch(Copy_u8PortID){
		case PORTA/*Port A*/: PORTA_REG=PORT_HIGH;break;
		case PORTB/*Port B*/: PORTB_REG=PORT_HIGH;break;
		case PORTC/*Port C*/: PORTC_REG=PORT_HIGH;break;
		case PORTD/*Port D*/: PORTD_REG=PORT_HIGH;break;
	}
}

u8 DIO_u8GetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID){
	u8 value;
	switch(Copy_u8PortID){
		case PORTA/*Port A*/: value=GetBit(PINA_REG,Copy_u8PinID);break;
		case PORTB/*Port B*/: value=GetBit(PINB_REG,Copy_u8PinID);break;
		case PORTC/*Port C*/: value=GetBit(PINC_REG,Copy_u8PinID);break;
		case PORTD/*Port D*/: value=GetBit(PIND_REG,Copy_u8PinID);break;
	}
	return value;
}

void DIO_voidTogglePinValue(u8 Copy_u8PortID,u8 Copy_u8PinID){
	switch(Copy_u8PortID){
		case PORTA/*Port A*/: TogBit(PORTA_REG,Copy_u8PinID);break;
		case PORTB/*Port B*/: TogBit(PORTB_REG,Copy_u8PinID);break;
		case PORTC/*Port C*/: TogBit(PORTC_REG,Copy_u8PinID);break;
		case PORTD/*Port D*/: TogBit(PORTD_REG,Copy_u8PinID);break;
	}
}

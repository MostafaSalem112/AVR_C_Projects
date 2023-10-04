#ifndef _DIO_INTERFACE_H
#define _DIO_INTERFACE_H


#define PORTA (0x00)
#define PORTB (0x01)
#define PORTC (0x02)
#define PORTD (0x03)

#define PIN0 (0x00)
#define PIN1 (0x01)
#define PIN2 (0x02)
#define PIN3 (0x03)
#define PIN4 (0x04)
#define PIN5 (0x05)
#define PIN6 (0x06)
#define PIN7 (0x07)

#define PIN_INPUT (0x00)
#define PIN_OUTPUT (0x01)

#define PIN_LOW (0x00)
#define PIN_HIGH (0x01)

#define PORT_INPUT (0x00)
#define PORT_OUTPUT (0xff)

#define HALF_IN_OUT (0x0f)
#define HALF_OUT_IN (0xf0)

#define PORT_LOW (0x00)
#define PORT_HIGH (0xff)

#define HALF_LOW_HIGH (0x0f)
#define HALF_HIGH_LOW (0xf0)


//============== prototype ======================

void DIO_voidSetPinDirection(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinDir);
void DIO_voidSetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinValue);
void DIO_voidSetPortDirection(u8 Copy_u8PortID,u8 Copy_u8PortDir);
void DIO_voidSetAllPortInput(u8 Copy_u8PortID);
void DIO_voidSetAllPortOutput(u8 Copy_u8PortID);
void DIO_voidSetPortValue(u8 Copy_u8PortID,u8 Copy_u8PortValue);
void DIO_voidSetAllPortLow(u8 Copy_u8PortID);
void DIO_voidSetAllPortHigh(u8 Copy_u8PortID);
u8   DIO_u8GetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID);
void DIO_voidTogglePinValue(u8 Copy_u8PortID,u8 Copy_u8PinID);

#endif

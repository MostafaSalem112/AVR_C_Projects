#ifndef _UART_PRIVATE_H
#define _UART_PRIVATE_H

#define UCSRA *((volatile u8 *)0x2b)
#define UCSRB *((volatile u8 *)0x2a)
#define UCSRC *((volatile u8 *)0x40)
#define UBRRL *((volatile u8 *)0x29)
#define UBRRH *((volatile u8 *)0x40)
#define UDR *((volatile u8 *)0x2c)
 

#endif
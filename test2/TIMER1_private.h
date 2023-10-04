#ifndef _TIMER1_PRIVATE_H
#define _TIMER1_PRIVATE_H

#define TCCR1A *((volatile u8 *)0x4f)
#define TCCR1B *((volatile u8 *)0x4e)
#define ICR1 *((volatile u16 *)0x46)
#define OCR1A *((volatile u16 *)0x4a)
#define OCR1B *((volatile u16 *)0x48)
#define TCNT1 *((volatile u16 *)0x4c)
#define TIMSK *((volatile u8 *)0x59)

#endif

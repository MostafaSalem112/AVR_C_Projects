#ifndef _LCD_INTERFACE_H
#define _LCD_INTERFACE_H


#define CLEAR_COMMAND 0b00000001
#define FUN_SET_COMMAND 0b00111000
#define DISPLAY_CONTROL_COMMAND 0b00001100

#define LINE0_ADDRESS 0x80
#define LINE1_ADDRESS 0xc0

#define LINE0 0
#define LINE1 1

#define MAX_INT_DIGITS 10

#define ZERO_ASCII 48

#define CGRAM_ADDRESS 64
#define NO_BLOCK_BYTES 8


//################# prototypes ########################

void LCD_voidIntialize();
void LCD_voidWriteCommand(unsigned char Copy_u8Command);
void LCD_voidWriteData(unsigned char Copy_u8Data);
void LCD_voidGoToXY(unsigned char Copy_u8X,unsigned char Copy_u8Y);
void LCD_voidWriteString(unsigned char *Copy_u8String);
void LCD_voidWriteNumber(unsigned long int Copy_u32Number);
void LCD_voidWriteSpecialCharacter(unsigned char *patern,unsigned char Copy_u32Char,unsigned char Copy_u8X,unsigned char Copy_u8Y);
void LCD_voidClearDisplay();

#endif

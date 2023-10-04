#include "STD_types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#include "GIE_private.h"
#include "GIE_interface.h"

void GIE_voidEnable(){

	SetBit(SREG,PIN7);
}

void GIE_voidDisable(){

	ClrBit(SREG,PIN7);
}
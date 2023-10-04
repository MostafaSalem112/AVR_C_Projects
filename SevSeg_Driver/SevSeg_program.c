#include "STD_types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#include "SevSeg_interface.h"
#include "SevSeg_config.h"

void SevSeg_voidIntialize(){
	DIO_voidSetAllPortOutput(SevSeg_PORT); //set port as outpot
}

void SevSeg_voidDisplayNumber(u8 Copy_u8Number){
	
	if(!MODE){   //common cathod
		DIO_voidSetPortValue(SevSeg_PORT,Copy_u8Number); // display outpot
	}
	else{        //common anode
		DIO_voidSetPortValue(SevSeg_PORT,~Copy_u8Number); // display outpot
	}
}

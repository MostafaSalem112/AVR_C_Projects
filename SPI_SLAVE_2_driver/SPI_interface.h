#ifndef _SPI_INTERFACE_H
#define _SPI_INTERFACE_H

#define MASTER 0
#define SLAVE 1

//################# prototypes ########################
void SPI_voidInitialize(u8 Copy_u8ModeSelect);
u8 SPI_u8TransCiver(u8 Copu_u8Data);

#endif

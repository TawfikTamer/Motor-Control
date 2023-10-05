/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    EEPROM_private.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Tawfik Tamer Ibrahim
 *  Layer  : MCAL
 *  SWC    : Internal EEPROM
 *
 */
 
#ifndef EEPROM_PRIVATE_H_
#define EEPROM_PRIVATE_H_
 
 /*   Registers    */
 
#define EEARH  *((volatile u8 *) 0X3F )
#define EEARL  *((volatile u8 *) 0X3E )
#define EEDR   *((volatile u8 *) 0X3D )
#define EECR   *((volatile u8 *) 0X3C )
 
#define SPMCR  *((volatile u8 *) 0x57 )

/*Bit definitions*/
#define EERE 0
#define EEWE 1
#define EEMWE 2
#define EERIE 3

#define SPMEN 0
 
#endif
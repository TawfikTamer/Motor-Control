/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    EEPROM_interface.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Tawfik Tamer Ibrahim
 *  Layer  : MCAL
 *  SWC    : Internal EEPROM
 *
 */
 
#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

void EEPROM_WriteByte    ( u16 Copy_u16Address , u8 Copy_u8Data );
u8   EEPROM_ReadByte     (          u16 Copy_u16Address         ); 
 
#endif
/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    EEPROM_program.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Tawfik Tamer Ibrahim
 *  Layer  : MCAL
 *  SWC    : Internal EEPROM
 *
 */
 
#include "../../LIB/std_types.h"
#include "../../LIB/common_macros.h"

#include "EEPROM_interface.h"
#include "EEPROM_private.h" 



void EEPROM_WriteByte (u16 Copy_u16Address , u8 Copy_u8Data)
{
	/* Wait until EEWE becomes zero */
	while ( BIT_IS_SET(EECR,EEWE) ); // stay in the loop until bit is clear
	
	/* Write EEPROM address to EEAR */
	EEARH = Copy_u16Address>>8;
	EEARL = Copy_u16Address;
	
	/* Write EEPROM data to EEDR */
	EEDR = Copy_u8Data;
	
	/* Set EEMWE and EEWE in EECR */
	SET_BIT(EECR,EEMWE);
	SET_BIT(EECR,EEWE);
}

/*
********************************************************************
*/

u8 EEPROM_ReadByte (u16 Copy_u16Address)
{
	/*Wait for completion of previous write*/
	while(BIT_IS_SET(EECR,EEWE) );
	while(BIT_IS_SET(SPMCR,SPMEN) );
	
	/*Put address of data to be read in register*/
	EEARH = Copy_u16Address>>8;
	EEARL = Copy_u16Address;
	
	/*Start EEPROM read by writing EEMWE*/
	SET_BIT(EECR,EERE);
	
	/*Return data from  data register*/
	return EEDR;
	
}

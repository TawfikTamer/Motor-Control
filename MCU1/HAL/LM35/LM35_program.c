/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    LM35_program.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Tawfik Tamer Ibrahim
 *  Layer  : HAL
 *  SWC    : LM35
 *
 */
#include "../../LIB/std_types.h"
#include "../../LIB/common_macros.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/ADC/ADC_interface.h"

#include "LM35_interface.h"
#include "LM35_private.h"

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function initialize the pin which connected to led as output pin
* Parameters :
            => struct has the LM35 Channel, ADC VoltageReference , ADCResolution
			=> Pointer to TEMP Variable which will return in it 
* return : Error State
*/
u8 LM35_u8GetTemp (u8 Copy_u8Channel , u8 * Copy_u8TempValue) 
{
	u8 Local_u8ErrorState = OK ;
	
	u16 Local_u16ADCResult ;
	
	ADC_GetResultSync(Copy_u8Channel , &Local_u16ADCResult);

	*Copy_u8TempValue = ((u32) Local_u16ADCResult * 256*(5/2.56) / 1023.0);
	
		
	return Local_u8ErrorState ;
}

/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    SW_program.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Tawfik tamer ibrahim
 *  Layer  : HAL
 *  SWC    : SWITCH / BUTTON
 *
 */

#include <util/delay.h>
#include "../../LIB/std_types.h"
#include "../../LIB/common_macros.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "SW_interface.h"
#include "SW_private.h"
#include "SW_config.h"


//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function initialize the pin which connected to Push Button as Pull Up Input pin
* Parameters :   => struct has the switch porn , pin , status
* return : void 
*/
void SW_Init      ( SW_Type SW_Config ){
	
	DIO_SetPinDirection( SW_Config.Port , SW_Config.Pin , DIO_PIN_INPUT );
	
	/* If Sw is Internal Pull Up */
	if( SW_Config.Pull_State == SW_Int_PULL_UP ){
		
		DIO_SetPinValue    ( SW_Config.Port , SW_Config.Pin , DIO_PIN_HIGH  );
		
		/* we could use DIO_enumConnectPullup */
	}
	
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function read Button status
* Parameters :   => struct has the switch porn , pin , status
* return : switch status
*/

u8   SW_GetPressed ( SW_Type SW_Config ){
	
	u8 LOC_u8Result = SW_NOT_PRESSED ;
	u8 LOC_u8PinVal = SW_NOT_PRESSED ;
	
	if ( (SW_Config.Pull_State == SW_Int_PULL_UP) || (SW_Config.Pull_State == SW_Ext_PULL_UP) )
	{
		DIO_GetPinValue( SW_Config.Port , SW_Config.Pin , &LOC_u8PinVal );
		
		if (LOC_u8PinVal==0)
		{
			LOC_u8Result = SW_PRESSED ;
		}
		else if (LOC_u8PinVal==1)
		{
			LOC_u8Result = SW_NOT_PRESSED ;
		}

	}
	else if (SW_Config.Pull_State == SW_Ext_PULL_DOWN)
	{
		DIO_GetPinValue( SW_Config.Port , SW_Config.Pin , &LOC_u8PinVal );
		
		if (LOC_u8PinVal==0)
		{
			LOC_u8Result = SW_NOT_PRESSED ;
		}
		else if (LOC_u8PinVal==1)
		{
			LOC_u8Result = SW_PRESSED ;
		}
	}
		
	return LOC_u8Result ;
	
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    END    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


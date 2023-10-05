/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    LED_program.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Tawfik tamer ibrahim
 *  Layer  : HAL
 *  SWC    : LED
 *
 */
 #include "../../LIB/std_types.h"
 #include "../../LIB/common_macros.h"
 
 #include "../../MCAL/DIO/DIO_interface.h"
 #include "LED_interface.h"
 
 
 //----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function initialize the pin which connected to led as output pin
* Parameters :
            => struct has the led port , pin , status
* return : void 
*/
void LED_Init( LED_Type LED_Configuration )
{

	DIO_SetPinDirection( LED_Configuration.Port , LED_Configuration.Pin , DIO_PIN_OUTPUT );

}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function set high on led pin ( led on )
* Parameters :
            => struct has the led port , pin , status
* return : void 
*/
void LED_On  ( LED_Type LED_Configuration )
{

	if( LED_Configuration.Active_State == ACTIVE_HIGH ){

		DIO_SetPinValue( LED_Configuration.Port , LED_Configuration.Pin , DIO_PIN_HIGH );

	}else if( LED_Configuration.Active_State == ACTIVE_LOW ){

		DIO_SetPinValue( LED_Configuration.Port , LED_Configuration.Pin , DIO_PIN_LOW  );

	}

}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function set low on led pin ( led off )
* Parameters :
             => struct has the led port , pin , status
* return : void 
*/
void LED_Off ( LED_Type LED_Configuration )
{

	if( LED_Configuration.Active_State == ACTIVE_HIGH ){

		DIO_SetPinValue( LED_Configuration.Port , LED_Configuration.Pin , DIO_PIN_LOW  );

	}else if( LED_Configuration.Active_State == ACTIVE_LOW ){

		DIO_SetPinValue( LED_Configuration.Port , LED_Configuration.Pin , DIO_PIN_HIGH  );

	}

}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function toggle led pin
* Parameters :
             => struct has the led port , pin , status
* return : void 
*/
void LED_Toggle      ( LED_Type LED_Configuration )
{
	DIO_TogglePinValue  ( LED_Configuration.Port , LED_Configuration.Pin );
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    END    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
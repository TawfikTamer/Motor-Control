/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    DIO_program.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : tawfik tamer ibrahim
 *  Layer  : MCAL
 *  SWC    : DIO/GPIO
 *
 */ 
 
#include "../../LIB/std_types.h"
#include "../../LIB/common_macros.h"

#include "DIO_private.h"
#include "DIO_interface.h"


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<                          IO Pins                     >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Breif : This Function set the direction of the Pin  (INPUT || OUTPUT)
 * Parameters :
  	  =>Copy_u8PORT --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  =>Copy_u8PIN  --> Pin Number [ DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ]
  	  =>Copy_u8Direction --> Pin Direction [ DIO_PIN_OUTPUT , DIO_PIN_INPUT ]
 * return : its status
 */
DIO_ErrorStatus DIO_SetPinDirection    (u8 Copy_u8PORT , u8 Copy_u8PIN , u8 Copy_u8Direction ) 
{

	DIO_ErrorStatus LOC_enumState = DIO_OK ;

	/* Make sure that the Port ID and Pin ID are in the valid range */
	if ((Copy_u8PORT <= DIO_PORTD) && (Copy_u8PIN <= DIO_PIN7))
	{
		if ( Copy_u8Direction == DIO_PIN_OUTPUT )
		{
			/* Check on the Required PORT Number */
			switch (Copy_u8PORT)
			{
			case DIO_PORTA: SET_BIT(DDRA,Copy_u8PIN); break;
			case DIO_PORTB: SET_BIT(DDRB,Copy_u8PIN); break;
			case DIO_PORTC: SET_BIT(DDRC,Copy_u8PIN); break;
			case DIO_PORTD: SET_BIT(DDRD,Copy_u8PIN); break;
			}
		}

		else if ( Copy_u8Direction == DIO_PIN_INPUT )
		{
			/* Check on the Required PORT Number */
			switch (Copy_u8PORT)
			{
			case DIO_PORTA: CLR_BIT(DDRA,Copy_u8PIN); break;
			case DIO_PORTB: CLR_BIT(DDRB,Copy_u8PIN); break;
			case DIO_PORTC: CLR_BIT(DDRC,Copy_u8PIN); break;
			case DIO_PORTD: CLR_BIT(DDRD,Copy_u8PIN); break;
			}
		}

		else
		{
			LOC_enumState = DIO_NOK ;
		}
	}

	else
	{
		LOC_enumState = DIO_NOK ;
	}

	return LOC_enumState ;

}
//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Breif : This Function set the Value of the Pin  (HIGH || LOW)
 * Parameters :
  	  =>Copy_u8PORT --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  =>Copy_u8PIN  --> Pin Number [ DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ]
  	  =>Copy_u8Value --> Pin Direction [ DIO_PIN_HIGH , DIO_PIN_LOW ]
 * return : its status
 */
DIO_ErrorStatus DIO_SetPinValue      (u8 Copy_u8PORT , u8 Copy_u8PIN , u8 Copy_u8Value ) 
{

	DIO_ErrorStatus LOC_enumState = DIO_OK ;

	/* Make sure that the Port ID and Pin ID are in the valid range */
	if ((Copy_u8PORT <= DIO_PORTD) && (Copy_u8PIN <= DIO_PIN7))
	{
		if (Copy_u8Value == DIO_PIN_HIGH)
		{
			/* Check on the Required PORT Number */
			switch (Copy_u8PORT)
			{
			case DIO_PORTA: SET_BIT(PORTA,Copy_u8PIN); break;
			case DIO_PORTB: SET_BIT(PORTB,Copy_u8PIN); break;
			case DIO_PORTC: SET_BIT(PORTC,Copy_u8PIN); break;
			case DIO_PORTD: SET_BIT(PORTD,Copy_u8PIN); break;
			}

		}

		else if (Copy_u8Value == DIO_PIN_LOW)
		{
			/* Check on the Required PORT Number */
			switch (Copy_u8PORT)
			{
			case DIO_PORTA: CLR_BIT(PORTA,Copy_u8PIN); break;
			case DIO_PORTB: CLR_BIT(PORTB,Copy_u8PIN); break;
			case DIO_PORTC: CLR_BIT(PORTC,Copy_u8PIN); break;
			case DIO_PORTD: CLR_BIT(PORTD,Copy_u8PIN); break;
			}
		}

		else
		{
			LOC_enumState = DIO_NOK ;
		}
	}

	else
	{
		LOC_enumState = DIO_NOK ;
	}

	return LOC_enumState ;

}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Breif : This Function Get the Value of the Pin
 * Parameters :
 	  =>Copy_u8PORT --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  =>Copy_u8PIN  --> Pin Number [ DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ]
  	  => *Copy_PtrData  --> pointer to recieve the pin value
 * return : its status and recieve Pin Value in pointer
 */

DIO_ErrorStatus DIO_GetPinValue          (u8 Copy_u8PORT, u8 Copy_u8PIN, u8 * Copy_PtrData   )
{

	DIO_ErrorStatus LOC_enumState = DIO_OK ;

	if ((Copy_u8PORT <= DIO_PORTD) && (Copy_u8PIN <= DIO_PIN7))
	{
		/* Check on the Required PORT Number */
		switch (Copy_u8PORT)
		{
		case DIO_PORTA: * Copy_PtrData = GET_BIT(PINA,Copy_u8PIN); break;
		case DIO_PORTB: * Copy_PtrData = GET_BIT(PINB,Copy_u8PIN); break;
		case DIO_PORTC: * Copy_PtrData = GET_BIT(PINC,Copy_u8PIN); break;
		case DIO_PORTD: * Copy_PtrData = GET_BIT(PIND,Copy_u8PIN); break;
		}
	}

	else
	{
		/* in case of error in the Pin ID or PORT ID */
		LOC_enumState = DIO_NOK ;
	}

	return LOC_enumState;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Breif : This Function Toggle the Value of the Pin
 * Parameters :
  	  =>Copy_u8PORT --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  =>Copy_u8PIN  --> Pin Number [ DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ]
 * return : its status
 */
DIO_ErrorStatus DIO_TogglePinValue  ( u8 Copy_u8PORT, u8 Copy_u8PIN )
{
	DIO_ErrorStatus LOC_enumState = DIO_OK ;

	if (Copy_u8PIN <= DIO_PIN7)
	{
		switch (Copy_u8PORT)
		{
		case DIO_PORTA : TOG_BIT(PORTA,Copy_u8PIN);
		break ;
		case DIO_PORTB : TOG_BIT(PORTB,Copy_u8PIN);
		break ;
		case DIO_PORTC : TOG_BIT(PORTC,Copy_u8PIN);
		break ;
		case DIO_PORTD : TOG_BIT(PORTD,Copy_u8PIN);
		break ;
		}

	}
	else
	{
		/* in case of error in the Pin ID or PORT ID */
		LOC_enumState = DIO_NOK ;
	}

	return LOC_enumState;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Breif : This Function connected internal pull up
 * Parameters :
  	  =>Copy_u8PORT --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  =>Copy_u8PIN  --> Pin Number [ DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ]
 	  =>Copy_u8ConnectPullup --> [DIO_PIN_HIGH , DIO_PIN_LOW ]
 * return : its status
 */
DIO_ErrorStatus DIO_ConnectPullup (u8 Copy_u8PORT ,u8 Copy_u8PIN, u8 Copy_u8ConnectPullup)
{

	DIO_ErrorStatus LOC_enumState = DIO_OK ;

	if ((Copy_u8PORT <= DIO_PORTD) && (Copy_u8PIN <= DIO_PIN7))
	{
		switch(Copy_u8PORT)
		{
		/* Connect or disconnect the pull up resistance to the given pin in port A */
		case DIO_PORTA:
			if(Copy_u8ConnectPullup==DIO_PIN_HIGH)
			{
				CLR_BIT(SFIOR,PUD);
				CLR_BIT(DDRA,Copy_u8PIN);
				SET_BIT(PORTA,Copy_u8PIN);
			}
			else
			{
				CLR_BIT(PORTA,Copy_u8PIN);
			}
			break;
			/* Connect or disconnect the pull up resistance to the given pin in port B */
		case DIO_PORTB:
			if(Copy_u8ConnectPullup==DIO_PIN_HIGH)
			{
				CLR_BIT(SFIOR,PUD);
				CLR_BIT(DDRB,Copy_u8PIN);
				SET_BIT(PORTB,Copy_u8PIN);
			}
			else
			{
				CLR_BIT(PORTB,Copy_u8PIN);
			}
			break;
			/* Connect or disconnect the pull up resistance to the given pin in port C */
		case DIO_PORTC:
			if(Copy_u8ConnectPullup==DIO_PIN_HIGH)
			{
				CLR_BIT(SFIOR,PUD);
				CLR_BIT(DDRC,Copy_u8PIN);
				SET_BIT(PORTC,Copy_u8PIN);
			}
			else
			{
				CLR_BIT(PORTC,Copy_u8PIN);
			}
			break;
			/* Connect or disconnect the pull up resistance to the given pin in port D */
		case DIO_PORTD:
			if(Copy_u8ConnectPullup==DIO_PIN_HIGH)
			{
				CLR_BIT(SFIOR,PUD);
				CLR_BIT(DDRD,Copy_u8PIN);
				SET_BIT(PORTD,Copy_u8PIN);
			}
			else
			{
				CLR_BIT(PORTD,Copy_u8PIN);
			}
			break;
		}
	}

	else
	{
		LOC_enumState = DIO_NOK ;
	}

	return LOC_enumState ;


}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<                          IO PORTS                     >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*
 * Breif : This Function Set the direction of the port (INPUT / OUTPUT)
 * Parameters :
 	  =>Copy_u8PORT --> Port Name [ DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD ]
 	  =>Copy_u8Direction  --> Port direction [ DIO_PORT_OUTPUT , DIO_PORT_INPUT ]
 * return :  its status
 */
DIO_ErrorStatus DIO_SetPortDirection   (u8 Copy_u8PORT , u8 Copy_u8Direction ) 
{

	DIO_ErrorStatus LOC_enumState = DIO_OK ;

	if ( (Copy_u8PORT <= DIO_PORTD) )
	{
		/* Check on the Required PORT Number */
		switch (Copy_u8PORT)
		{
		case     DIO_PORTA: DDRA = Copy_u8Direction; break;
		case     DIO_PORTB: DDRB = Copy_u8Direction; break;
		case     DIO_PORTC: DDRC = Copy_u8Direction; break;
		case     DIO_PORTD: DDRD = Copy_u8Direction; break;
		default: LOC_enumState =  DIO_NOK;    break;
		}	
	}
	else
	{
		LOC_enumState = DIO_NOK;
	}
	return LOC_enumState ;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Breif : This Function Set value on Port
 * Parameters :
  	  =>Copy_u8PORT --> Port Name [ DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD ]
 	  =>Copy_u8Value  --> The Value  [DIO_PORT_HIGH , DIO_PORT_LOW , Another Value]
 * return : its status
 */
DIO_ErrorStatus DIO_SetPortValue       (u8 Copy_u8PORT , u8 Copy_u8Value )
{

	DIO_ErrorStatus LOC_enumState = DIO_OK ;

	if ( (Copy_u8PORT <= DIO_PORTD) && ( (Copy_u8Value<=255) || (Copy_u8Value==DIO_PORT_LOW) || (Copy_u8Value==DIO_PORT_HIGH) ) )
	{
		/* Check on the Required PORT Number */
		switch (Copy_u8PORT)
		{
		case     DIO_PORTA: PORTA = Copy_u8Value; break;
		case     DIO_PORTB: PORTB = Copy_u8Value; break;
		case     DIO_PORTC: PORTC = Copy_u8Value; break;
		case     DIO_PORTD: PORTD = Copy_u8Value; break;
		default: LOC_enumState = DIO_NOK;       break;
		}	
	}
	else
	{
		LOC_enumState = DIO_NOK;
	}
	return LOC_enumState ;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Breif : This Function Toggle value on Port
 * Parameters :
 	  =>Copy_u8PORT --> Port Name [ DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD ]
 * return : its status
 */
DIO_ErrorStatus DIO_TogglePortValue      (u8 Copy_u8PORT                       )
{
	DIO_ErrorStatus LOC_enumState = DIO_OK ;

	if (Copy_u8PORT <= DIO_PORTD)
	{
		switch (Copy_u8PORT)
		{
		case DIO_PORTA : PORTA = ~PORTA ;
		break ;
		case DIO_PORTB : PORTB = ~PORTB ;
		break ;
		case DIO_PORTC : PORTC = ~PORTC ;
		break ;
		case DIO_PORTD : PORTD = ~PORTD ;
		break ;
		}
	}
	else
	{
		LOC_enumState = DIO_NOK;
	}
	return LOC_enumState ;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Breif : This Function GET value on Port
 * Parameters :
 	  =>Copy_u8PORT --> Port Name [ DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD ]
 	  => *Copy_PtrData  --> pointer to recieve the port value
 * return : its status and recieve Port Value in pointer
 */
DIO_ErrorStatus   DIO_GetPortValue         ( u8 Copy_u8PORT  , u8 * Copy_PtrData )
{

	DIO_ErrorStatus LOC_enumState = DIO_OK ;

	if ( (Copy_u8PORT <= DIO_PORTD))
	{
		switch (Copy_u8PORT)
		{
		case DIO_PORTA :
			*Copy_PtrData = PINA  ;
			break ;
		case DIO_PORTB :
			*Copy_PtrData = PINB  ;
			break ;
		case DIO_PORTC :
			*Copy_PtrData = PINC  ;
			break ;
		case DIO_PORTD :
			*Copy_PtrData = PIND  ;
			break ;
		default : LOC_enumState = DIO_NOK ;
		break;
		}
	}
	else
	{
		LOC_enumState = DIO_NOK;
	}

	return LOC_enumState ;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<                          IO NIBBLES                     >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
 * Breif : This Function write value on high nibbles of the Port
 * Parameters :
 	  =>Copy_u8PORT  --> Port Name [ DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD ]
 	  =>Copy_u8value --> to set its high bits on high nibble oh register
 * return : its status
 *
 *Hint1 : High Nibbles = Most Pins [4:7]
 *Hint2 : This Function take the first 4 bits from the value (#) => xxxx#### AND put it in high nobbles
 *
 */
DIO_ErrorStatus DIO_WriteHighNibbles(u8 Copy_u8PORT,u8 Copy_u8value)
{

	DIO_ErrorStatus LOC_enumState = DIO_OK ;

	if ( (Copy_u8PORT <= DIO_PORTD))
	{
		Copy_u8value = (Copy_u8value<<4) ;
		switch(Copy_u8PORT)
		{
		case DIO_PORTA :
			PORTA&=0x0f;                   // make sure the high bits = 0000
			PORTA|=Copy_u8value;			//Set only the high nibble of the port A by the given value
			break ;
		case DIO_PORTB:
			PORTB&=0x0f;                 //Set only the high nibble of the port B by the given value
			PORTB|=Copy_u8value;
			break ;
		case DIO_PORTC :
			PORTC&=0x0f;                 //Set only the high nibble of the port C by the given value
			PORTC|=Copy_u8value;
			break ;
		case DIO_PORTD:
			PORTD&=0x0f;                 //Set only the high nibble of the port D by the given value
			PORTD|=Copy_u8value;
			break ;
		default: break ;

		}
	}
	else
	{
		LOC_enumState = DIO_NOK;
	}

	return LOC_enumState ;

}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Breif : This Function write value on low nibbles of the Port
 * Parameters :
 	  =>Copy_u8PORT  --> Port Name [ DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD ]
 	  =>Copy_u8value --> to set its low bits on high nibble oh register
 * return : its status
 *
 *Hint1 : Low Nibbles = Least Pins [0:3]
 *Hint2 : This Function also take the first 4 bits from the value (#) => xxxx#### AND put it in low nobbles
 *
 */
DIO_ErrorStatus DIO_WriteLowNibbles(u8 Copy_u8PORT,u8 Copy_u8value)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK ;


	if ( (Copy_u8PORT <= DIO_PORTD))
	{
		Copy_u8value&=0x0f;
		switch(Copy_u8PORT)
		{
		case DIO_PORTA :
			PORTA &= 0xf0;                 //Set only the high nibble of the port A by the given value
			PORTA |= Copy_u8value;
			break ;
		case DIO_PORTB:
			PORTB &= 0xf0;                 //Set only the high nibble of the port B by the given value
			PORTB |= Copy_u8value;
			break ;
		case DIO_PORTC :
			PORTC &= 0xf0;                 //Set only the high nibble of the port C by the given value
			PORTC |= Copy_u8value;
			break ;
		case DIO_PORTD:
			PORTD &= 0xf0;                 //Set only the high nibble of the port D by the given value
			PORTD |= Copy_u8value;
			break ;
		default: break ;

		}


	}
	else
	{
		LOC_enumState = DIO_NOK;
	}

	return LOC_enumState ;

}



//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    END    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
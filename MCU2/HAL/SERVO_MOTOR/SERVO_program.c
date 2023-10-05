/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    SERVO_program.c   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Tawfik Tamer Ibrahim
 *  Layer  : HAL
 *  SWC    : SERVO_MOTOR
 *
 */ 
 
#include <util/delay.h>

#define F_CPU 1000000UL
 
#include "../../LIB/std_types.h"
#include "../../LIB/common_macros.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "SERVO_interface.h"
#include "SERVO_private.h" /*You have to include SERVO_private.h before SERVO_config.h*/
#include "SERVO_config.h"


void SERVO_Init (void)
{
	/* set FAST PWM */
	SET_BIT(TCCR1A , TCCR1A_WGM11);
	SET_BIT(TCCR1A , TCCR1A_COM1A1);	
	SET_BIT(TCCR1B , TCCR1B_WGM12);
	SET_BIT(TCCR1B , TCCR1B_WGM13);
	
	/* set clc/8 */
    SET_BIT(TCCR1B , TCCR1B_CS11);
	
	/* Clear OC1A on compare match */
    TCNT1 = 0;	
	
	/* set the TOP value */
	ICR1 = 2600; // fPWM	= 50Hz , Period = 20ms  
	
	/* set pin direction */
	DIO_SetPinDirection (DIO_PORTD,DIO_PIN5,DIO_PIN_OUTPUT);
	DIO_SetPinDirection (DIO_PORTB,DIO_PIN1,DIO_PIN_OUTPUT);
}

/*
*********************************************************************************************************************
*********************************************************************************************************************
*/

void SERVO_Control (u16 Copy_u8Angle)
{
switch (Copy_u8Angle)
{
	case -90 : OCR1A = 124; break;
	case -45 : OCR1A = 155; break;
	case   0 : OCR1A = 187; break;
	case  45 : OCR1A = 218; break;
	case  90 : OCR1A = 250; break;
}

}





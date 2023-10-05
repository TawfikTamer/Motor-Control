/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    DCMOTOR_programe.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Tawfik Tamer Ibrahim
 *  Layer  : HAL
 *  SWC    : DC_MOTOR
 *
 */
 
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../LIB/std_types.h"
#include "../../LIB/common_macros.h"


#include "DCMOTOR_INTERFACE.h"

u8 DCMotor_Control  (DCMotor_CONFIG * DcMotor , u8 Copy_uint8State)
{
	u8 Local_uint8ErrorState = OK ;
	
	DIO_SetPinDirection(DcMotor->Copy_uint8DcMotorPort , DcMotor->Copy_uint8DcMotorPinA , DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DcMotor->Copy_uint8DcMotorPort , DcMotor->Copy_uint8DcMotorPinB , DIO_PIN_OUTPUT);

	switch (Copy_uint8State)
	{
	case DCMOTOR_CW :
		 DIO_SetPinValue(DcMotor->Copy_uint8DcMotorPort , DcMotor->Copy_uint8DcMotorPinA , DIO_PIN_LOW) ;
		 DIO_SetPinValue(DcMotor->Copy_uint8DcMotorPort , DcMotor->Copy_uint8DcMotorPinB , DIO_PIN_HIGH) ;
		 break ;
	case DCMOTOR_CCW :
		 DIO_SetPinValue(DcMotor->Copy_uint8DcMotorPort , DcMotor->Copy_uint8DcMotorPinB , DIO_PIN_LOW) ;
		 DIO_SetPinValue(DcMotor->Copy_uint8DcMotorPort , DcMotor->Copy_uint8DcMotorPinA , DIO_PIN_HIGH) ;
		 break ;
	case DCMOTOR_STOP :
		 DIO_SetPinValue(DcMotor->Copy_uint8DcMotorPort , DcMotor->Copy_uint8DcMotorPinA , DIO_PIN_LOW) ;
		 DIO_SetPinValue(DcMotor->Copy_uint8DcMotorPort , DcMotor->Copy_uint8DcMotorPinB , DIO_PIN_LOW) ;
		 break ;
	default : Local_uint8ErrorState = NOK ;
	}

	return Local_uint8ErrorState ;
}

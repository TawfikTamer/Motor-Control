/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    DCMOTOR_interface.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Tawfik Tamer Ibrahim
 *  Layer  : HAL
 *  SWC    : DC_MOTOR
 *
 */
#ifndef DCMOTOR_INTERFACE_H_
#define DCMOTOR_INTERFACE_H_

	#define DCMOTOR_CW		0
	#define DCMOTOR_CCW		1
	#define DCMOTOR_STOP	2
	
	typedef struct 
	{
		u8 Copy_uint8DcMotorPort ;
		u8 Copy_uint8DcMotorPinA ;
		u8 Copy_uint8DcMotorPinB ;
	} DCMotor_CONFIG ;

u8 DCMotor_Control (DCMotor_CONFIG * DcMotor , u8 Copy_uint8State) ;

#endif

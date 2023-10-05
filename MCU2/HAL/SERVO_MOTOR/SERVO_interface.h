/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    SERVO_interface.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Tawfik Tamer Ibrahim
 *  Layer  : HAL
 *  SWC    : SERVO_MOTOR
 *
 */ 
 
#ifndef SERVO_INTERFACE_H_
#define SERVO_INTERFACE_H_

void  SERVO_Init        (       void       );
void  SERVO_Control     ( u16 Copy_u8Angle );   // [-90 , -45 , 0 , 45 , 90]

#endif
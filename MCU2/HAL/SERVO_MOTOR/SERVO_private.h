/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    SERVO_private.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Tawfik Tamer Ibrahim
 *  Layer  : HAL
 *  SWC    : SERVO_MOTOR
 *
 */ 
 
#ifndef SERVO_PRIVATE_H_
#define SERVO_PRIVATE_H_

#define TCCR1A			*((volatile u8*)0X4F)
#define TCCR1B			*((volatile u8*)0X4E)
#define ICR1			*((volatile u16*)0X46)
#define TCNT1 			*((volatile u16*)0X4C) 
#define OCR1A			*((volatile u16*)0X4A)

#define TCCR1A_COM1A1		7
#define TCCR1A_WGM11		1
#define TCCR1B_WGM12		3
#define TCCR1B_WGM13		4

#define TCCR1B_CS10 		0
#define TCCR1B_CS11 		1
#define TCCR1B_CS12 		2

#endif
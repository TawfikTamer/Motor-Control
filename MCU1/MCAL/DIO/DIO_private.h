/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    DIO_private.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : tawfik tamer ibrahim
 *  Layer  : MCAL
 *  SWC    : DIO/GPIO
 *
 */ 
 
 #ifndef DIO_PRIVATE_H_
 #define DIO_PRIVATE_H_
 
 /* group A registers */
 #define DDRA *((volatile u8*)0x3A)
 #define PINA *((volatile u8*)0x39)
 #define PORTA *((volatile u8*)0x3B)
 
 /* group B registers */
 #define DDRB *((volatile u8*)0x37)
 #define PINB *((volatile u8*)0x36)
 #define PORTB *((volatile u8*)0x38)
 
 /* group C registers */
 #define DDRC *((volatile u8*)0x34)
 #define PINC *((volatile u8*)0x33)
 #define PORTC *((volatile u8*)0x35)
 
 /* group D registers */
 #define DDRD *((volatile u8*)0x31)
 #define PIND *((volatile u8*)0x30)
 #define PORTD *((volatile u8*)0x32)
 
 /*PULL up*/
 #define SFIOR *((volatile u8*)0x50)
 
 #endif
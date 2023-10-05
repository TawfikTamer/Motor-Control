/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    DIO_interface.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : tawfik tamer ibrahim
 *  Layer  : MCAL
 *  SWC    : DIO/GPIO
 *
 */ 

 #ifndef DIO_INTERFACE_H_
 #define DIO_INTERFACE_H_
 
 #include "../../LIB/std_types.h"
 typedef enum                 //it should be before functions prototypes
 {
	DIO_NOK,
	DIO_OK
	
 }DIO_ErrorStatus;
 
 
 
// Port Defines
#define  DIO_PORTA  0
#define  DIO_PORTB  1
#define  DIO_PORTC  2
#define  DIO_PORTD  3


// PIN Defines
#define DIO_PIN0   0
#define DIO_PIN1   1
#define DIO_PIN2   2
#define DIO_PIN3   3
#define DIO_PIN4   4
#define DIO_PIN5   5
#define DIO_PIN6   6
#define DIO_PIN7   7


// PIN Directions
#define DIO_PIN_OUTPUT		1
#define DIO_PIN_INPUT	    0

// PIN Value Options 
#define DIO_PIN_HIGH		1
#define DIO_PIN_LOW			0

// PORT Directions
#define DIO_PORT_OUTPUT		0xFF
#define DIO_PORT_INPUT		0

// PORT Value Options 
#define DIO_PORT_HIGH 		0xFF
#define DIO_PORT_LOW  		0

 //Pull UP
#define PUD   2




// IO Pins 
DIO_ErrorStatus DIO_SetPinDirection      (u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Direction     );
DIO_ErrorStatus DIO_SetPinValue          (u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Value         );
DIO_ErrorStatus DIO_GetPinValue          (u8 Copy_u8PORT, u8 Copy_u8PIN, u8 * Copy_PtrData       );
DIO_ErrorStatus DIO_TogglePinValue       (u8 Copy_u8PORT, u8 Copy_u8PIN                          );

// Internal Pull Up
DIO_ErrorStatus DIO_ConnectPullup        (u8 Copy_u8PORT ,u8 Copy_u8PIN, u8 Copy_u8ConnectPullup );

// IO Ports 
DIO_ErrorStatus DIO_SetPortDirection     (u8 Copy_u8PORT, u8 Copy_u8Direction  );
DIO_ErrorStatus DIO_SetPortValue         (u8 Copy_u8PORT, u8 Copy_u8Value      );
DIO_ErrorStatus DIO_GetPortValue         (u8 Copy_u8PORT, u8 * Copy_PtrData    );
DIO_ErrorStatus DIO_TogglePortValue      (u8 Copy_u8PORT                       );


// IO Nibbles
DIO_ErrorStatus DIO_WriteHighNibbles (u8 Copy_u8PORT,u8 value);
DIO_ErrorStatus DIO_WriteLowNibbles  (u8 Copy_u8PORT,u8 value);



 #endif
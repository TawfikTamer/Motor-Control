/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    LED_interface.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Tawfik tamer ibrahim
 *  Layer  : HAL
 *  SWC    : LED
 *
 */
 
 #ifndef LED_INTERFACE_H_
 #define LED_INTERFACE_H_
 
 
 #define ACTIVE_HIGH   1
 #define ACTIVE_LOW    0

//make struct for every led by choice the port,pin and active state of each one
 typedef struct{
	 
	 u8 Port         ;
	 u8 Pin          ;
	 u8 Active_State ;
	 
 }LED_Type;
 
 
 void LED_Init   ( LED_Type LED_config );
 
 void LED_On     ( LED_Type LED_config );
 
 void LED_Off    ( LED_Type LED_config );
 
 void LED_Toggle ( LED_Type LED_config );
 
 #endif
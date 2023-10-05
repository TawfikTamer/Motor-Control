/*
 * MC_mcu2.c
 *
 * Created: 04/10/2023 01:03:21 ص
 * Author : TAWFIK
 */ 

/*
**********************************  #include  ***************************************
*/

#include "LIB/common_macros.h"
#include "LIB/std_types.h"

#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/ADC/ADC_interface.h"
#include "MCAL/USART/USART_interface.h"
#include "MCAL/GIE/GIE_interface.h"

#include "HAL/DC_MOTOR/DCMOTOR_interface.h"
#include "HAL/SERVO_MOTOR/SERVO_interface.h"
#include "HAL/LED/LED_interface.h"
#include "HAL/SW/SW_interface.h"
#include "HAL/CLDC/CLCD_interface.h"

/*
**********************************  #defines  ***************************************
*/
u8 Copy_u8PL = 192 ;
volatile u32 SW_Counter1 =0;

u8 OH_counter = 1; // the counter that will pull up the over heat flag

void B_TOG()
{
	SW_Counter1++ ;
	if (SW_Counter1==490)
	{
		TIMER2_SetCTC(Copy_u8PL);
		OH_counter++;
		SW_Counter1=0;
	}
}


int main(void)
{
/*
**********************************  initialize  ***************************************
*/
	
	ADC_Init();
	USART_Init();
	TIMER0_Init();
	TIMER2_Init();
	SERVO_Init();
	CLCD_Init();
	
	SW_Type SW1 = {DIO_PORTD , DIO_PIN6 , SW_Int_PULL_UP};
	SW_Init(SW1);
	
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN0,DIO_PIN_INPUT);
	
	DCMotor_CONFIG machine = {DIO_PORTB,DIO_PIN1,DIO_PIN2};
	
	LED_Type GREEN_light = {DIO_PORTA,DIO_PIN3,ACTIVE_HIGH};
	LED_Type YELLOW_light = {DIO_PORTA,DIO_PIN5,ACTIVE_HIGH};
	LED_Type RED_light = {DIO_PORTA,DIO_PIN7,ACTIVE_HIGH};
				
	
	LED_Init(GREEN_light);
	LED_Init(YELLOW_light);
	LED_Init(RED_light);
	
	
	DCMotor_Control(&machine,DCMOTOR_CCW);
/*
************************************************************************
*/	
	u8 T_state; //get the TEMP value from MCU1
	u8 POT; //get the potentiometer value
	
	CLCD_SendString((u8 *)"Motor speed:");
	
    while (1) 
    {
		ADC_GetResultSync(0,&POT);
		TIMER0_SetCTC(POT);
		
		CLCD_SetPosition(1,14);
		CLCD_SendNumber(((f64)POT)*.39216);
		CLCD_SendData(lcd_MoveCursorLeft);
		
		USART_RecevieData(&T_state);
		if(T_state <40)
		{
			LED_On(GREEN_light);
			LED_Off(RED_light);
			LED_Off(YELLOW_light);
			
			CLCD_SetPosition(2,1);
			CLCD_SendString((u8 *)"Normal");
		}
		else if(T_state >=40 && T_state <50)
		{
			LED_On(YELLOW_light);
			LED_Off(GREEN_light);
			LED_Off(RED_light);
			
			CLCD_SetPosition(2,1);
			CLCD_SendString((u8 *)"Emergency");
			CLCD_SetPosition(2,11);
			CLCD_SendData(lcd_MoveCursorLeft);
			
			OH_counter = 1;
			if(SW_GetPressed(SW1))
			{
				DCMotor_Control(&machine,DCMOTOR_STOP);
				SERVO_Control(0);
				LED_Off(YELLOW_light);
				CLCD_ClearScreen();
				CLCD_SendString((u8 *)"system stoped");
				break;
			}
		}
		else if(T_state >= 50)
		{
			LED_On(RED_light);
			LED_Off(GREEN_light);
			LED_Off(YELLOW_light);
			CLCD_SetPosition(2,9);
			CLCD_SendData(lcd_MoveCursorLeft);
			CLCD_SetPosition(2,1);
			CLCD_SendString((u8 *)"Abnormal");
			TIMER_SetCallBack(B_TOG,5);
			GIE_Enable();
			
			CLCD_SetPosition(2,11);
			CLCD_SendNumber(OH_counter);
			
			if(OH_counter == 6 || SW_GetPressed(SW1) )
			{
				USART_SendData(OH_counter);
				DCMotor_Control(&machine,DCMOTOR_STOP);
				SERVO_Control(0);
				LED_Off(RED_light);
				CLCD_ClearScreen();
				CLCD_SendString((u8 *)"system stoped");
				break;
				
			}
			
		}
    }
}


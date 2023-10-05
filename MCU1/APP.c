/*
 * MC_mcu1.c
 *
 * Created: 03/10/2023 08:49:27 م
 * Author : TAWFIK
 */ 

/*
**********************************  #include  ***************************************
*/

#include "LIB/common_macros.h"
#include "LIB/std_types.h"

#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/ADC/ADC_interface.h"
#include "MCAL/EEPROM/EEPROM_interface.h"
#include "MCAL/USART/USART_interface.h"

#include "HAL/DC_MOTOR/DCMOTOR_interface.h"
#include "HAL/LM35/LM35_interface.h"
#include "HAL/SW/SW_interface.h"
#include "HAL/CLCD/CLCD_interface.h"


/*
**********************************  #defines  ***************************************
*/
//#define F_CPU 1000000

#define state      0X01 //EEPROM address for states

#define Normal      1  
#define Emergency   2 
#define Abnormal    3  


int main(void)
{
/*
**********************************  initialize  ***************************************
*/	
	ADC_Init();
	CLCD_Init();
	USART_Init();
	TIMER0_Init();
	TIMER2_Init();
	
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN0,DIO_PIN_INPUT);
	
	DCMotor_CONFIG FAN = {DIO_PORTB,DIO_PIN1,DIO_PIN2};
	SW_Type SW1 = {DIO_PORTA , DIO_PIN3 , SW_Int_PULL_UP};
	SW_Init(SW1);
	
/*
***************************************************************************************
*/	
	
	u8 Temp ;
	u8 OverHeat;
	volatile flag = 1;
	CLCD_SendString((u8 *)"Temp = ");
	CLCD_SetPosition(1,12);
	CLCD_SendString((u8 *) "c");
	CLCD_SetPosition(2,1);
	CLCD_SendString((u8 *) "FAN :");
		
    while (flag) 
    {
		
		LM35_u8GetTemp(0,&Temp);
		USART_RecevieData(&OverHeat);
		if(Temp < 20)
		{
			CLCD_SendData(lcd_MoveCursorLeft);
			CLCD_SetPosition(2,6);
			CLCD_SendString((u8 *) "OFF");
			CLCD_SetPosition(1,8);
			CLCD_SendNumber(Temp);
			
			DCMotor_Control(&FAN , DCMOTOR_STOP);
			EEPROM_WriteByte(state,Normal);
			USART_SendData(Temp);
		}
		else if(Temp >=20 && Temp <=40)
		{
			CLCD_SetPosition(2,8);
			CLCD_SendData(lcd_MoveCursorLeft);
			CLCD_SendData(lcd_MoveCursorLeft);
			CLCD_SetPosition(2,6);
			CLCD_SendNumber(5*Temp -101);
			CLCD_SetPosition(1,8);
			CLCD_SendNumber(Temp);
			
			TIMER0_SetCTC(12*Temp -240);
			DCMotor_Control(&FAN , DCMOTOR_CW);
			EEPROM_WriteByte(state,Normal);
			USART_SendData(Temp);
		}
		else if(Temp >40 && Temp <50)
		{
			CLCD_SetPosition(2,6);
			CLCD_SendNumber(100);
			CLCD_SetPosition(1,8);
			CLCD_SendNumber(Temp);
			
			TIMER0_SetCTC(255);
			DCMotor_Control(&FAN , DCMOTOR_CW);
			EEPROM_WriteByte(state,Emergency);
			if(SW_GetPressed(SW1) || OverHeat == 6)
			{
				TIMER0_SetCTC(0);
				CLCD_ClearScreen();
				CLCD_SendString((u8 *)"system stoped");
				flag = 0;
			}
			USART_SendData(Temp);
		}
		else if(Temp >= 50)
		{
			CLCD_SetPosition(2,6);
			CLCD_SendNumber(100);
			CLCD_SetPosition(1,8);
			CLCD_SendNumber(Temp);
			
			TIMER0_SetCTC(255);
			EEPROM_WriteByte(state,Abnormal);
			if(SW_GetPressed(SW1) || OverHeat == 6)
			{
				TIMER0_SetCTC(0);
				CLCD_ClearScreen();
				CLCD_SendString((u8 *)"system stoped");
				flag = 0;
			}			
			USART_SendData(Temp);
		}
	
	
    }
}


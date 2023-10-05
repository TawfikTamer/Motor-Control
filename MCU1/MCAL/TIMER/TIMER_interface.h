/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    TIMER_interface.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Tawfik Tamer Ibrahim
 *  Layer  : MCAL
 *  SWC    : Timer
 *
 */ 
 

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_


/* Define indexes for the global pointer to func for ISR  */

	#define TIMER0_OVF_VECTOR_ID		11
	#define TIMER0_CTC_VECTOR_ID		10

	#define TIMER1_OVF_VECTOR_ID		9
	#define TIMER1_CTCB_VECTOR_ID		8
	#define TIMER1_CTCA_VECTOR_ID		7
	#define TIMER1_ICU_VECTOR_ID		6

	#define TIMER2_OVF_VECTOR_ID		5
	#define TIMER2_CTC_VECTOR_ID		4


	void TIMER0_Init(void) ;
	void TIMER0_SetPreload (u8 Copy_u8Preload) ;
	void TIMER0_SetCTC (u8 Copy_u8CTC) ;
	u8   TIMER0_GetTimerCounterValue (void) ;

	void TIMER1_Init(void) ;
	void TIMER1_SetPreload (u16 Copy_u16Preload) ;
	void TIMER1_SetCTCA (u16 Copy_u16CTCA) ;
	void TIMER1_SetCTCB (u16 Copy_u16CTCB) ;
	void TIMER1_SetICR1 (u16 Copy_u16ICR1) ;
	u16  TIMER1_GetTimerCounterValue (void) ;

	void TIMER2_Init(void) ;
	void TIMER2_SetPreload (u8 Copy_u8Preload) ;
	void TIMER2_SetCTC (u8 Copy_u8CTC) ;
	u8   TIMER2_GetTimerCounterValue (void) ;

	/*******************************/

	void TIMER_ICUInitEnable(void);
	u8   TIMER_ICUSetTriggerEdge(u8 Copy_u8Edge);
	void TIMER_ICUEnableInterrupt(void);
	void TIMER_ICUDisableInterrupt(void);
	u16  TIMER_GetICR(void);

    /*******************************/

	void TIMER_SetPWM(u16 Copy_u16CompareValue);
	u8   TIMER_GetPWMOnPeriod   (u16 * Copy_pu16OnPeriod);
	u8   TIMER_GetPWMTotalPeriod(u32 * Copy_pu32TotalPeriod);
	u8   TIMER_GetPWMDutyCycle  (u8  * Copy_pu8DutyCycle);
	
    /*******************************/
	
	void TIMER_WDTSleep(void);
	void TIMER_WDTEnable (void);
	void TIMER_WDTDisable(void);


	u8   TIMER_SetCallBack(void (*Copy_pvCallBackFunc)(void) , u8 Copy_u8VectorID) ;




#endif /* TIMER_INTERFACE_H_ */

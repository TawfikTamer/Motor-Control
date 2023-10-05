/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    USART_interface.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Tawfik Tamer Ibarhim
 *  Layer  : MCAL
 *  SWC    : USART
 *
 */
 
/*File Gard*/
#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

void USART_Init (void);

u8   USART_SendData (u8 Copy_u8Data);
 
u8   USART_RecevieData (u8 * Copy_u8ReceviedData) ;

u8   USART_SendStringSynch (const u8 * Copy_pchString);
u8   USART_SendStringAsynch (const u8 * Copy_pchString , void (* NotificationFunc)(void)) ;

u8   USART_ReceiveBufferSynch (u8 * Copy_pchString , u32 Copy_uint32BufferSize) ;
u8   USART_ReceiveBufferAsynch (u8 * Copy_pchString , u32 Copy_uint32BufferSize , void (* NotificationFunc)(void)) ;

#endif

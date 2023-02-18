/*
 * USART_Interface.h
 *
 *  Created on: Jan 26, 2023
 *      Author: user
 */

#ifndef MCAL_USART_USART_INTERFACE_H_
#define MCAL_USART_USART_INTERFACE_H_

extern uint16 Global_u16TxBuffer ;
extern uint16 Global_u16RxBuffer ;

uint8 USART_u8Init ( void ) ;
uint8 USART_u8SyncSendChar ( uint16 Copy_u16Character ) ;
uint8 USART_u8SyncReceiveChar ( uint16 * Copy_u16pCharacter ) ;
uint8 USART_u8AsyncSendChar ( void (*onCompletionRoutine) (void) ) ;
uint8 USART_u8AsyncReceiveChar ( void (*onCompletionRoutine) (void) ) ;

#endif /* MCAL_USART_USART_INTERFACE_H_ */

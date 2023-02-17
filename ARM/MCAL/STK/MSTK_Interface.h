/*
 * MSTK_Interface.h
 *
 *  Created on: Feb 7, 2023
 *      Author: Ahmed Khaled Hammad
 */

#ifndef MSTK_INTERFACE_H_
#define MSTK_INTERFACE_H_

typedef enum
{
    MSTK_DISABLE = 0,
	MSTK_ENABLE
}STK_State_t ;

typedef enum
{
    MSTK_INT_DISABLE = 0,
	MSTK_INT_ENABLE
}STK_INT_State_t ;


void MSTK_voidInit(void) ;
void MSTK_voidTimerState(STK_State_t Copy_uddtState) ;
void MSTK_voidIntStatus(STK_INT_State_t Copy_uddtIntState) ;
void _delay_ms(u32 Copy_u32Time) ;
void _delay_us(u32 Copy_u32Time) ;
u8 MSTK_u8ReadFlag(void) ;
void MSTK_voidSetCallBack(void(*PFunc)(void)) ;
#endif /* MSTK_INTERFACE_H_ */

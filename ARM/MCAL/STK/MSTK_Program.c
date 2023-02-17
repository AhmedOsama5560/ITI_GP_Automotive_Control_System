/*
 * MSTK_Program.c
 *
 *  Created on: Feb 7, 2023
 *      Author: Ahmed Khaled Hammad
 */
/********************************************************************/
/*                    Standard Types LIB                            */
/********************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"

/********************************************************************/
/*                         Peripheral Files                         */
/********************************************************************/

#include "MSTK_Private.h"
#include "MSTK_Interface.h"
#include "MSTK_Config.h"

/********************************************************************/
/*                      Function Implementation                     */
/********************************************************************/

void MSTK_voidInit(void)
{
	// Enable Systick Interrupt  - clock = AHB/8 - stop Systick
	MSTK->CTRL = 0x00000002 ;
}
void MSTK_voidTimerState(STK_State_t Copy_uddtState)
{
	if(Copy_uddtState == MSTK_ENABLE)
	{
		SET_BIT(MSTK->CTRL,0) ;
	}
	else if(Copy_uddtState == MSTK_DISABLE)
	{
		CLR_BIT(MSTK->CTRL,0) ;
	}
	else
	{
		/*Do Nothing*/
	}
}
void MSTK_voidIntStatus(STK_INT_State_t Copy_uddtIntState)
{
	if(Copy_uddtIntState == MSTK_INT_ENABLE)
	{
		SET_BIT(MSTK->CTRL,1) ;
	}
	else if(Copy_uddtIntState == MSTK_INT_DISABLE)
	{
		CLR_BIT(MSTK->CTRL,1) ;
	}
	else
	{
		/*Do Nothing*/
	}
}
//Suppose that  the Clock System AHB --> HSI = 16 MHZ , F_TIMER = AHB/8
// Tick time = 1 / 2MHz  = 0.5 micro second
// 1 ms --> 1000 micro --> 2000 ticks
void _delay_ms(u32 Copy_u32Time)
{
	//Intialize Timer
	MSTK_voidInit() ; // INT-->Enable , AHB/8 , TIMER = Stop
	// Polling
	MSTK_voidIntStatus(MSTK_INT_DISABLE) ;
	// load Reg
	MSTK->LOAD = Copy_u32Time * 2000  ;
	// VAL Reg (Reset --> Reload)
	MSTK->VAL = 0 ;
	//Enable Timer
	MSTK_voidTimerState(MSTK_ENABLE);
	// wait Flag Polling
	while(MSTK_u8ReadFlag() == 0) ;
	// Stop Timer
	MSTK_voidTimerState(MSTK_DISABLE);
}
void _delay_us(u32 Copy_u32Time)
{
	//Intialize Timer
	MSTK_voidInit() ; // INT-->Enable , AHB/8 , TIMER = Stop
	// Polling
	MSTK_voidIntStatus(MSTK_INT_DISABLE) ;
	// load Reg
	MSTK->LOAD = Copy_u32Time * 2  ;
	// VAL Reg (Reset --> Reload)
	MSTK->VAL = 0 ;
	//Enable Timer
	MSTK_voidTimerState(MSTK_ENABLE);
	// wait Flag Polling
	while(MSTK_u8ReadFlag() == 0) ;
	// Stop Timer
	MSTK_voidTimerState(MSTK_DISABLE);
}

void MSTK_voidStart(u32 Copy_u32Preload)
{
	// load Reg
	MSTK->LOAD = Copy_u32Preload  ;
	// VAL Reg (Reset --> Reload)
	MSTK->VAL = 0 ;
	//Enable Timer
	MSTK_voidTimerState(MSTK_ENABLE);
	// wait Flag Polling or Handled By interrupt
	//while(MSTK_u8ReadFlag() == 0) ;
}

u8 MSTK_u8ReadFlag(void)
{
	return (GET_BIT(MSTK->CTRL,16)) ;
}
/*
void MSTK_voidSetCallBack(void(*PFunc)(void))
{
	//TODO
}
*/

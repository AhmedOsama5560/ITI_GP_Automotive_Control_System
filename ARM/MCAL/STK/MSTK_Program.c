/*******************************************************************************************************/
/* Author            : kholoud khaled                                                                  */
/* Version           : V0.0.0                                                                          */
/* Data              : 9 Feb 2023                                                                      */
/* Description       : MSTK_Program.c --> implementations                                              */
/* Module  Features  :                                                                                 */
/*      01- MSTK_voidInit                                                                              */
/*      02- MSTK_voidStart                                                                             */
/*      03- MSTK_voidINTStatus                                                                         */
/*      04- MSTK_u8ReadFlag                                                                            */
/*      05- MSTK_VidSetCallBack                                                                        */
/*      06- MSTK_voidDelayMs                                                                           */
/*      07- MSTK_voidDelayUs                                                                           */
/*      08- MSTK_voidStopInterval                                                                      */
/*      09- MSTK_voidSetIntervalSingle                                                                 */
/*******************************************************************************************************/

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


/*******************************************************************************************************/
/*                                      00- SysTick_Handler                                            */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Enable Peripheral Clock                                                  */
/* 2- Function Input       -> Copy_uBusName ,   Copy_u8PerNum                                          */
/*   - BusName_t      : The Bus Of The Prepheral ( AHB1 , AHB2 , APB1 , APB2 ) Every One               */
/*                      Detect Which REG To Choice Pripheral From It                                   */
/*   - Copy_u8PerName :  The Order Of Prepheral On The Selected Reg                                    */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/


void ( * MSTK_CallBack ) ( void );

void SysTick_Handler(void){

	MSTK_CallBack();

}

/*******************************************************************************************************/
/*                                      01- MSTK_voidInit                                              */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Enable Peripheral Clock                                                  */
/* 2- Function Input       -> Copy_uBusName ,   Copy_u8PerNum                                          */
/*   - BusName_t      : The Bus Of The Prepheral ( AHB1 , AHB2 , APB1 , APB2 ) Every One               */
/*                      Detect Which REG To Choice Pripheral From It                                   */
/*   - Copy_u8PerName :  The Order Of Prepheral On The Selected Reg                                    */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MSTK_voidInit(void)
{
	// Enable Systick Interrupt  - clock = AHB/8 - stop Systick
	MSTK->CTRL = 0x00000002 ;
}

/*******************************************************************************************************/
/*                                      02- MSTK_voidStart                                              */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Enable Peripheral Clock                                                  */
/* 2- Function Input       -> Copy_uBusName ,   Copy_u8PerNum                                          */
/*   - BusName_t      : The Bus Of The Prepheral ( AHB1 , AHB2 , APB1 , APB2 ) Every One               */
/*                      Detect Which REG To Choice Pripheral From It                                   */
/*   - Copy_u8PerName :  The Order Of Prepheral On The Selected Reg                                    */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MSTK_voidTimerState(STK_State_t Copy_u8Status)
{
	if(Copy_u8Status == MSTK_ENABLE)
	{
		SET_BIT(MSTK->CTRL,0) ;
	}
	else if(Copy_u8Status == MSTK_DISABLE)
	{
		CLR_BIT(MSTK->CTRL,0) ;
	}
	else
	{
		/*Do Nothing*/
	}
}

void MSTK_voidStart( u32 Copy_PreloadValue)
{
	// load Reg
	MSTK->LOAD = Copy_PreloadValue  ;
	// VAL Reg (Reset --> Reload)
	MSTK->VAL = 0 ;
	//Enable Timer
	MSTK_voidTimerState(MSTK_ENABLE);
	// wait Flag Polling or Handled By interrupt
	//while(MSTK_u8ReadFlag() == 0) ;
}

/*******************************************************************************************************/
/*                                      03- MSTK_voidINTStatus                                         */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Enable Peripheral Clock                                                  */
/* 2- Function Input       -> Copy_uBusName ,   Copy_u8PerNum                                          */
/*   - BusName_t      : The Bus Of The Prepheral ( AHB1 , AHB2 , APB1 , APB2 ) Every One               */
/*                      Detect Which REG To Choice Pripheral From It                                   */
/*   - Copy_u8PerName :  The Order Of Prepheral On The Selected Reg                                    */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MSTK_voidINTStatus( u8 Copy_u8Status )
{
	if(Copy_u8Status == MSTK_INT_ENABLE)
	{
		SET_BIT(MSTK->CTRL,1) ;
	}
	else if(Copy_u8Status == MSTK_INT_DISABLE)
	{
		CLR_BIT(MSTK->CTRL,1) ;
	}
	else
	{
		/*Do Nothing*/
	}
}

/*******************************************************************************************************/
/*                                      04- MSTK_u8ReadFlag                                            */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Enable Peripheral Clock                                                  */
/* 2- Function Input       -> Copy_uBusName ,   Copy_u8PerNum                                          */
/*   - BusName_t      : The Bus Of The Prepheral ( AHB1 , AHB2 , APB1 , APB2 ) Every One               */
/*                      Detect Which REG To Choice Pripheral From It                                   */
/*   - Copy_u8PerName :  The Order Of Prepheral On The Selected Reg                                    */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/
u8 MSTK_u8ReadFlag( void )
{
	return (GET_BIT(MSTK->CTRL,16)) ;
}

/*******************************************************************************************************/
/*                                      05- MSTK_voidSetCallBack                                       */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Enable Peripheral Clock                                                  */
/* 2- Function Input       -> Copy_uBusName ,   Copy_u8PerNum                                          */
/*   - BusName_t      : The Bus Of The Prepheral ( AHB1 , AHB2 , APB1 , APB2 ) Every One               */
/*                      Detect Which REG To Choice Pripheral From It                                   */
/*   - Copy_u8PerName :  The Order Of Prepheral On The Selected Reg                                    */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/
void MSTK_voidSetCallBack( void (*PFunc)(void) )
{
	MSTK_CallBack = PFunc;
}


//Suppose that  the Clock System AHB --> HSI = 16 MHZ , F_TIMER = AHB/8
// Tick time = 1 / 2MHz  = 0.5 micro second
// 1 ms --> 1000 micro --> 2000 ticks
void MSTK_voidDelayMs(u32 Copy_u32Delay)
{
	
	// Polling
	MSTK_voidINTStatus(MSTK_INT_DISABLE) ;
	// load Reg
	MSTK->LOAD = Copy_u32Delay * 2000  ;
	// VAL Reg (Reset --> Reload)
	MSTK->VAL = 0 ;
	//Enable Timer
	MSTK_voidTimerState(MSTK_ENABLE);
	// wait Flag Polling
	while(MSTK_u8ReadFlag() == 0) ;
	// Stop Timer
	MSTK_voidTimerState(MSTK_DISABLE);
}

void MSTK_voidDelayUs(u32 Copy_u32Delay)
{

	// Polling
	MSTK_voidINTStatus(MSTK_INT_DISABLE) ;
	// load Reg
	MSTK->LOAD = Copy_u32Delay * 2  ;
	// VAL Reg (Reset --> Reload)
	MSTK->VAL = 0 ;
	//Enable Timer
	MSTK_voidTimerState(MSTK_ENABLE);
	// wait Flag Polling
	while(MSTK_u8ReadFlag() == 0) ;
	// Stop Timer
	MSTK_voidTimerState(MSTK_DISABLE);
}

/********************************************************** Start_FUNCTION  **********************************************************/
			 /*  Send Time To Clock it And What Will Call After Time Finsh   */						
		      /* Global Var Take Adress Of Function And
										After Time Out ISR Call The Global_Var Which Point To Function  
*/
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32TicksNUM , void (* PFunc)(void))
{
	/*  Load Ticks in Load Reg */
	MSTK -> LOAD = Copy_u32TicksNUM;
	/*  Set CallBack  */
	MSTK_voidSetCallBack(PFunc);
	/*  Enable For Interrput */
	MSTK_voidINTStatus(MSTK_INT_ENABLE);
	/* Start Time */
	MSTK_voidTimerState(MSTK_ENABLE);
}
/*********************************************************** END_ FUNCTION   *********************************************************/

/********************************************************** Start_FUNCTION  **********************************************************/

/*
		- Function Will Stop The Interval If It Was Periodic 
*/
void MSTK_voidStopInterval(void) 
{
	/*  Disable For Interrput */
	MSTK_voidINTStatus(MSTK_INT_DISABLE);
	       /* Stop Timer */
	    MSTK ->VAL = 0U;
		MSTK ->LOAD = 0U;
			/* Stop Time */
	MSTK_voidTimerState(MSTK_DISABLE);



	
	
}
/*********************************************************** END_ FUNCTION   *********************************************************/




/*******************************************************************************************************/
/* Author            : kholoud khaled                                                                  */
/* Version           : V0.0.0                                                                          */
/* Data              : 9 Feb 2023                                                                      */
/* Description       : MSTK_Interface.c --> implementations                                            */
/* Module  Features  :                                                                                 */
/*      01- MSTK_voidInit                                                                              */
/*      02- MSTK_voidStart                                                                             */
/*      03- MSTK_voidINTStatus                                                                         */
/*      04- MSTK_u8ReadFlag                                                                            */
/*      05- MSTK_VidSetCallBack                                                                        */
/*      06- MSTK_voidDelayMs                                                                          */
/*      07- MSTK_voidDelayUs                                                                           */
/*      08- MSTK_voidStopInterval                                                                      */
/*      09- MSTK_voidSetIntervalSingle                                                                 */
/*******************************************************************************************************/

/*******************************************************************************************************/
/*	* What i sell To Customer                                                                          */
/*		*  The Archictect Give The API	                                                               */
/*						- The Name Of Function                                                         */
/*						- What is The Input                                                            */
/*						- What Is The Output                                                           */
/*						- Macro                                                                        */
/***************** **************************************************************************************/

/*******************************************************************************************************/
/*                                   guard of file will call on time in .c                             */
/*******************************************************************************************************/

#ifndef MSTK_INTERFACE_H_
#define MSTK_INTERFACE_H_

/*******************************************************************************************************/
/*                                        Macros for Systick State                                     */
/*******************************************************************************************************/

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


/*#####################################################################################################*/
/*                                      Function Prototypes                                            */
/*#####################################################################################################*/


void MSTK_voidInit( void );

void MSTK_voidTimerState(STK_State_t Copy_u8Status);

void MSTK_voidStart( u32 Copy_PreloadValue );

void MSTK_voidINTStatus( u8 Copy_u8Status );

u8 MSTK_u8ReadFlag( void );

void MSTK_voidSetCallBack( void (*PFunc)(void) );


void MSTK_voidDelayMs(u32 Copy_u32Delay);

void MSTK_voidDelayUs(u32 Copy_u32Delay);

/*   Function To Set The Interval Period and function which called only one time*/
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32TicksNUM , void (* PFunc)(void));

void MSTK_voidStopInterval(void);
#endif /* MSTK_INTERFACE_H_ */

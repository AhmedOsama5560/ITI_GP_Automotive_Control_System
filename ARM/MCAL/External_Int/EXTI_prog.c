/*
   Author : Mahinar Ashraf
   Date   : 9-2-2023
   Version: V1
*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

#include "SYSCFG_private.h"


#define NULL 0

void (*EXTI0_CallBack)(void)= NULL;
void (*EXTI1_CallBack)(void)= NULL;

void MEXTI_vEnableLine(EXTI_LINE_t Copy_eLineNum)
{
	SET_BIT(EXTI->IMR,Copy_eLineNum);
}

void MEXTI_vDisableLine(EXTI_LINE_t Copy_eLineNum)
{
	CLR_BIT(EXTI->IMR,Copy_eLineNum);
}

void MEXTI_vEventTrigger(EXTI_LINE_t Copy_eLineNum,EXTI_TRIG_t Copy_eEventTrig)
{
	switch (Copy_eEventTrig)
	{
	
		case EXTI_FALLING   :  SET_BIT(EXTI->FTSR,Copy_eLineNum); 
                               CLR_BIT(EXTI->RTSR,Copy_eLineNum);
        break;
		case EXTI_RAISING   :  SET_BIT(EXTI->RTSR,Copy_eLineNum);
                               CLR_BIT(EXTI->FTSR,Copy_eLineNum);
        break;
		case EXTI_ON_CHANGE :  SET_BIT(EXTI->FTSR,Copy_eLineNum);
                               SET_BIT(EXTI->RTSR,Copy_eLineNum);
        break;
	}
}

void MEXTI_vSwiTrigger(EXTI_LINE_t Copy_eLineNum)
{
	SET_BIT(EXTI-> SWIER,Copy_eLineNum);
}

u8 MEXTI_vGetPending(EXTI_LINE_t Copy_eLineNum)
{
	u8 L_u8GetPending=0U;
	
	L_u8GetPending = GET_BIT(EXTI-> PR,Copy_eLineNum);
	
	
	return L_u8GetPending;
}

void MEXTI_vPortConfig(EXTI_PORT_Num Copy_ePortNum,EXTI_LINE_t Copy_eLineNum)
{
	u8 L_LineNum=Copy_eLineNum;
	if(L_LineNum<=3)
	{
	   SYSCFG->EXTICR[0]|=((Copy_ePortNum<<0)<<(4U * L_LineNum ));
	}
	else if(L_LineNum<=7)
	{
		L_LineNum-=4;
		SYSCFG->EXTICR[1]|=((Copy_ePortNum<<0)<<(4U * L_LineNum ));
	}
	else if(L_LineNum<=11)
	{
		L_LineNum-=8;
		SYSCFG->EXTICR[2]|=((Copy_ePortNum<<0)<<(4U * L_LineNum ));
	}
	else if(L_LineNum<=15)
	{
		L_LineNum-=12;
		SYSCFG->EXTICR[3]|=((Copy_ePortNum<<0)<<(4U * L_LineNum ));
	}
	else 
	{
		/*return error*/
	}
	
}

void MEXTI1_vSetCallBack(void (*Ptr1)(void))
{
	EXTI1_CallBack=Ptr1;
}
void MEXTI0_vSetCallBack(void (*Ptr0)(void))
{
	EXTI0_CallBack=Ptr0;
}

 void EXTI0_IRQHandler(void)
{
	SET_BIT(EXTI->PR,0U);// clr
	EXTI0_CallBack();
}
void EXTI1_IRQHandler(void)
{
	SET_BIT(EXTI->PR,1U);
	EXTI1_CallBack();
}


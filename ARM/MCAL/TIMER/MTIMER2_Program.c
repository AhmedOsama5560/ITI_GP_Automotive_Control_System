/*
 * Author: Sandra Ayman
 * Version: V0.0.0
 * Date: 3-1-2023
 * Description: MTIMER2_Interface.h
 */
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MTIMER2_Private.h"
#include "MTIMER2_Config.h"
#include "MTIMER2_Interface.h"

/*----------MTIM_u8TimInit Implementation----------*/
u8 MTIM_u8TimInit(TimId_t Copy_uddtTimerId)
{
	u8 Local_u8ErrorState = 0;
	if(Copy_uddtTimerId <= TIM5)
	{
		switch(Copy_uddtTimerId)
		{
		case TIM2:
			/* Enable timer counter */
			SET_BIT(MTIM2_CR1,MTIM_CEN);
			/* Set Timer Prescaler */
			MTIM2_PSC = MTIM2_PRESCALER_VALUE;
			/* Set timer auto reload value */
			MTIM2_ARR = MTIM2_AUTORELOAD_VALUE;
			break;
		case TIM3:
			/* Enable timer counter */
			SET_BIT(MTIM3_CR1,MTIM_CEN);
			/* Set Timer Prescaler */
			MTIM3_PSC = MTIM3_PRESCALER_VALUE;
			/* Set timer auto reload value */
			MTIM3_ARR = MTIM3_AUTORELOAD_VALUE;
			break;
		case TIM4:
			/* Enable timer counter */
			SET_BIT(MTIM4_CR1,MTIM_CEN);
			/* Set Timer Prescaler */
			MTIM4_PSC = MTIM4_PRESCALER_VALUE;
			/* Set timer auto reload value */
			MTIM4_ARR = MTIM4_AUTORELOAD_VALUE;
			break;
		case TIM5:
			/* Enable timer counter */
			SET_BIT(MTIM5_CR1,MTIM_CEN);
			/* Set Timer Prescaler */
			MTIM5_PSC = MTIM5_PRESCALER_VALUE;
			/* Set timer auto reload value */
			MTIM5_ARR = MTIM5_AUTORELOAD_VALUE;
			break;
		}
	}
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}

/*----------MTIM_u8UpCounterInit Implementation----------*/
u8 MTIM_u8UpCounterInit(TimId_t Copy_uddtTimerId)
{
	u8 Local_u8ErrorState = 0;
	if(Copy_uddtTimerId <= TIM5)
	{
		switch(Copy_uddtTimerId)
		{
		case TIM2:
			/* Set Counter Direction as Up Counter */
			CLR_BIT(MTIM2_CR1,MTIM_DIR);
			break;
		case TIM3:
			/* Set Counter Direction as Up Counter */
			CLR_BIT(MTIM3_CR1,MTIM_DIR);
			break;
		case TIM4:
			/* Set Counter Direction as Up Counter */
			CLR_BIT(MTIM4_CR1,MTIM_DIR);
			break;
		case TIM5:
			/* Set Counter Direction as Up Counter */
			CLR_BIT(MTIM5_CR1,MTIM_DIR);
			break;
		}
	}
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}

/*----------MTIM_u8DownCounterInit Implementation----------*/
u8 MTIM_u8DownCounterInit(TimId_t Copy_uddtTimerId)
{
	u8 Local_u8ErrorState = 0;
	if(Copy_uddtTimerId <= TIM5)
	{
		switch(Copy_uddtTimerId)
		{
		case TIM2:
			/* Set Counter Direction as Up Counter */
			SET_BIT(MTIM2_CR1,MTIM_DIR);
			break;
		case TIM3:
			/* Set Counter Direction as Up Counter */
			SET_BIT(MTIM3_CR1,MTIM_DIR);
			break;
		case TIM4:
			/* Set Counter Direction as Up Counter */
			SET_BIT(MTIM4_CR1,MTIM_DIR);
			break;
		case TIM5:
			/* Set Counter Direction as Up Counter */
			SET_BIT(MTIM5_CR1,MTIM_DIR);
			break;
		}
	}
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}

/*----------MTIM_u8UpDownCounterInit Implementation----------*/
u8 MTIM_u8UpDownCounterInit(TimId_t Copy_uddtTimerId)
{
	u8 Local_u8ErrorState = 0;
	if(Copy_uddtTimerId <= TIM5)
	{
		switch(Copy_uddtTimerId)
		{
		case TIM2:
			/* Set Counter Direction as Up and Down Counter */
			switch(MTIM2_CENTER_MODE_SELECTION)
			{
			case 0:
				CLR_BIT(MTIM2_CR1,MTIM_CMS0);
				CLR_BIT(MTIM2_CR1,MTIM_CMS1);
				break;
			case 1:
				SET_BIT(MTIM2_CR1,MTIM_CMS0);
				CLR_BIT(MTIM2_CR1,MTIM_CMS1);
				break;
			case 2:
				CLR_BIT(MTIM2_CR1,MTIM_CMS0);
				SET_BIT(MTIM2_CR1,MTIM_CMS1);
				break;
			case 3:
				SET_BIT(MTIM2_CR1,MTIM_CMS0);
				SET_BIT(MTIM2_CR1,MTIM_CMS1);
				break;
			}
			/* Enable Update Interrupt Event */
			SET_BIT(MTIM2_DIER,MTIM_UIE);
			break;
		case TIM3:
			/* Set Counter Direction as Up and Down Counter */
			switch(MTIM3_CENTER_MODE_SELECTION)
			{
			case 0:
				CLR_BIT(MTIM3_CR1,MTIM_CMS0);
				CLR_BIT(MTIM3_CR1,MTIM_CMS1);
				break;
			case 1:
				SET_BIT(MTIM3_CR1,MTIM_CMS0);
				CLR_BIT(MTIM3_CR1,MTIM_CMS1);
				break;
			case 2:
				CLR_BIT(MTIM3_CR1,MTIM_CMS0);
				SET_BIT(MTIM3_CR1,MTIM_CMS1);
				break;
			case 3:
				SET_BIT(MTIM3_CR1,MTIM_CMS0);
				SET_BIT(MTIM3_CR1,MTIM_CMS1);
				break;
			}
			/* Enable Update Interrupt Event */
			SET_BIT(MTIM3_DIER,MTIM_UIE);
			break;
		case TIM4:
			/* Set Counter Direction as Up and Down Counter */
			switch(MTIM4_CENTER_MODE_SELECTION)
			{
			case 0:
				CLR_BIT(MTIM4_CR1,MTIM_CMS0);
				CLR_BIT(MTIM4_CR1,MTIM_CMS1);
				break;
			case 1:
				SET_BIT(MTIM4_CR1,MTIM_CMS0);
				CLR_BIT(MTIM4_CR1,MTIM_CMS1);
				break;
			case 2:
				CLR_BIT(MTIM4_CR1,MTIM_CMS0);
				SET_BIT(MTIM4_CR1,MTIM_CMS1);
				break;
			case 3:
				SET_BIT(MTIM4_CR1,MTIM_CMS0);
				SET_BIT(MTIM4_CR1,MTIM_CMS1);
				break;
			}
			/* Enable Update Interrupt Event */
			SET_BIT(MTIM4_DIER,MTIM_UIE);
			break;
		case TIM5:
			/* Set Counter Direction as Up and Down Counter */
			switch(MTIM5_CENTER_MODE_SELECTION)
			{
			case 0:
				CLR_BIT(MTIM5_CR1,MTIM_CMS0);
				CLR_BIT(MTIM5_CR1,MTIM_CMS1);
				break;
			case 1:
				SET_BIT(MTIM5_CR1,MTIM_CMS0);
				CLR_BIT(MTIM5_CR1,MTIM_CMS1);
				break;
			case 2:
				CLR_BIT(MTIM5_CR1,MTIM_CMS0);
				SET_BIT(MTIM5_CR1,MTIM_CMS1);
				break;
			case 3:
				SET_BIT(MTIM5_CR1,MTIM_CMS0);
				SET_BIT(MTIM5_CR1,MTIM_CMS1);
				break;
			}
			/* Enable Update Interrupt Event */
			SET_BIT(MTIM5_DIER,MTIM_UIE);
			break;
		}
	}
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}

/*----------MTIM_u8ExternalTriggerTimerInit Implementation----------*/
u8 MTIM_u8ExternalTriggerTimerInit(TimId_t Copy_uddtTimerId)
{
	u8 Local_u8ErrorState = 0;
	if(Copy_uddtTimerId <= TIM5)
	{
		switch(Copy_uddtTimerId)
		{
		case TIM2:
			/* Set Counter Direction */
		#if MTIM2_COUNTER_DIRECTION ==0
			CLR_BIT(MTIM2_CR1,MTIM_DIR);
		#elif MTIM2_COUNTER_DIRECTION ==1
			SET_BIT(MTIM2_CR1,MTIM_DIR);
		#endif
			/* Enable Update Interrupt Event */
			SET_BIT(MTIM2_DIER,MTIM_UIE);
			/* External trigger configuration */
			/* Select External Trigger Polarity */
		#if EXT_TRIGGER_RAISING == 1
			CLR_BIT(MTIM2_SMCR,MTIM_ETP);
		#elif EXT_TRIGGER_FALLING == 1
			SET_BIT(MTIM2_SMCR,MTIM_ETP);
		#endif
			/* Select External Trigger Prescaler */
		#if EXT_TRIGGER_NO_PRESCALER == 1
			CLR_BIT(MTIM2_SMCR,MTIM_ETPS0);
			CLR_BIT(MTIM2_SMCR,MTIM_ETPS1);
		#elif EXT_TRIGGER_DIVIDED_2 == 1
			SET_BIT(MTIM2_SMCR,MTIM_ETPS0);
			CLR_BIT(MTIM2_SMCR,MTIM_ETPS1);
		#elif EXT_TRIGGER_DIVIDED_4 == 1
			CLR_BIT(MTIM2_SMCR,MTIM_ETPS0);
			SET_BIT(MTIM2_SMCR,MTIM_ETPS1);
		#elif EXT_TRIGGER_DIVIDED_8 == 1
			SET_BIT(MTIM2_SMCR,MTIM_ETPS0);
			SET_BIT(MTIM2_SMCR,MTIM_ETPS1);
		#endif
			/* Select External Trigger Filter */
		#if MTIM2_EXTERNAL_TRIGGER_Filter == 0
			CLR_BIT(MTIM2_SMCR,MTIM_ETF0);
			CLR_BIT(MTIM2_SMCR,MTIM_ETF1);
			CLR_BIT(MTIM2_SMCR,MTIM_ETF2);
			CLR_BIT(MTIM2_SMCR,MTIM_ETF3);
		#elif MTIM2_EXTERNAL_TRIGGER_Filter == 1
			SET_BIT(MTIM2_SMCR,MTIM_ETF0);
			CLR_BIT(MTIM2_SMCR,MTIM_ETF1);
			CLR_BIT(MTIM2_SMCR,MTIM_ETF2);
			CLR_BIT(MTIM2_SMCR,MTIM_ETF3);
		#elif MTIM2_EXTERNAL_TRIGGER_Filter == 2
			CLR_BIT(MTIM2_SMCR,MTIM_ETF0);
			SET_BIT(MTIM2_SMCR,MTIM_ETF1);
			CLR_BIT(MTIM2_SMCR,MTIM_ETF2);
			CLR_BIT(MTIM2_SMCR,MTIM_ETF3);
		#elif MTIM2_EXTERNAL_TRIGGER_Filter == 3
			SET_BIT(MTIM2_SMCR,MTIM_ETF0);
			SET_BIT(MTIM2_SMCR,MTIM_ETF1);
			CLR_BIT(MTIM2_SMCR,MTIM_ETF2);
			CLR_BIT(MTIM2_SMCR,MTIM_ETF3);
		#elif MTIM2_EXTERNAL_TRIGGER_Filter == 4
			CLR_BIT(MTIM2_SMCR,MTIM_ETF0);
			CLR_BIT(MTIM2_SMCR,MTIM_ETF1);
			SET_BIT(MTIM2_SMCR,MTIM_ETF2);
			CLR_BIT(MTIM2_SMCR,MTIM_ETF3);
		#elif MTIM2_EXTERNAL_TRIGGER_Filter == 5
			SET_BIT(MTIM2_SMCR,MTIM_ETF0);
			CLR_BIT(MTIM2_SMCR,MTIM_ETF1);
			SET_BIT(MTIM2_SMCR,MTIM_ETF2);
			CLR_BIT(MTIM2_SMCR,MTIM_ETF3);
		#elif MTIM2_EXTERNAL_TRIGGER_Filter == 6
			CLR_BIT(MTIM2_SMCR,MTIM_ETF0);
			SET_BIT(MTIM2_SMCR,MTIM_ETF1);
			SET_BIT(MTIM2_SMCR,MTIM_ETF2);
			CLR_BIT(MTIM2_SMCR,MTIM_ETF3);
		#elif MTIM2_EXTERNAL_TRIGGER_Filter == 7
			SET_BIT(MTIM2_SMCR,MTIM_ETF0);
			SET_BIT(MTIM2_SMCR,MTIM_ETF1);
			SET_BIT(MTIM2_SMCR,MTIM_ETF2);
			CLR_BIT(MTIM2_SMCR,MTIM_ETF3);
		#elif MTIM2_EXTERNAL_TRIGGER_Filter == 8
			CLR_BIT(MTIM2_SMCR,MTIM_ETF0);
			CLR_BIT(MTIM2_SMCR,MTIM_ETF1);
			CLR_BIT(MTIM2_SMCR,MTIM_ETF2);
			SET_BIT(MTIM2_SMCR,MTIM_ETF3);
		#elif MTIM2_EXTERNAL_TRIGGER_Filter == 9
			SET_BIT(MTIM2_SMCR,MTIM_ETF0);
			CLR_BIT(MTIM2_SMCR,MTIM_ETF1);
			CLR_BIT(MTIM2_SMCR,MTIM_ETF2);
			SET_BIT(MTIM2_SMCR,MTIM_ETF3);
		#elif MTIM2_EXTERNAL_TRIGGER_Filter == 10
			CLR_BIT(MTIM2_SMCR,MTIM_ETF0);
			SET_BIT(MTIM2_SMCR,MTIM_ETF1);
			CLR_BIT(MTIM2_SMCR,MTIM_ETF2);
			SET_BIT(MTIM2_SMCR,MTIM_ETF3);
		#elif MTIM2_EXTERNAL_TRIGGER_Filter == 11
			SET_BIT(MTIM2_SMCR,MTIM_ETF0);
			SET_BIT(MTIM2_SMCR,MTIM_ETF1);
			CLR_BIT(MTIM2_SMCR,MTIM_ETF2);
			SET_BIT(MTIM2_SMCR,MTIM_ETF3);
		#elif MTIM2_EXTERNAL_TRIGGER_Filter == 12
			CLR_BIT(MTIM2_SMCR,MTIM_ETF0);
			CLR_BIT(MTIM2_SMCR,MTIM_ETF1);
			SET_BIT(MTIM2_SMCR,MTIM_ETF2);
			SET_BIT(MTIM2_SMCR,MTIM_ETF3);
		#elif MTIM2_EXTERNAL_TRIGGER_Filter == 13
			SET_BIT(MTIM2_SMCR,MTIM_ETF0);
			CLR_BIT(MTIM2_SMCR,MTIM_ETF1);
			SET_BIT(MTIM2_SMCR,MTIM_ETF2);
			SET_BIT(MTIM2_SMCR,MTIM_ETF3);
		#elif MTIM2_EXTERNAL_TRIGGER_Filter == 14
			CLR_BIT(MTIM2_SMCR,MTIM_ETF0);
			SET_BIT(MTIM2_SMCR,MTIM_ETF1);
			SET_BIT(MTIM2_SMCR,MTIM_ETF2);
			SET_BIT(MTIM2_SMCR,MTIM_ETF3);
		#elif MTIM2_EXTERNAL_TRIGGER_Filter == 15
			SET_BIT(MTIM2_SMCR,MTIM_ETF0);
			SET_BIT(MTIM2_SMCR,MTIM_ETF1);
			SET_BIT(MTIM2_SMCR,MTIM_ETF2);
			SET_BIT(MTIM2_SMCR,MTIM_ETF3);
		#endif
			/* Select External Trigger Mode */
		#if MTIM2_EXTERNAL_TRIGGER_MODE == 1
			/* Reset SMS bits */
			CLR_BIT(MTIM2_SMCR,MTIM_SMS0);
			CLR_BIT(MTIM2_SMCR,MTIM_SMS1);
			CLR_BIT(MTIM2_SMCR,MTIM_SMS2);
			/* Select Trigger to External Trigger Input */
			SET_BIT(MTIM2_SMCR,MTIM_TS0);
			SET_BIT(MTIM2_SMCR,MTIM_TS1);
			SET_BIT(MTIM2_SMCR,MTIM_TS2);
			/* Select slave mode as external clock mode 1 */
			SET_BIT(MTIM2_SMCR,MTIM_SMS0);
			SET_BIT(MTIM2_SMCR,MTIM_SMS1);
			SET_BIT(MTIM2_SMCR,MTIM_SMS2);
		#elif MTIM2_EXTERNAL_TRIGGER_MODE == 2
			SET_BIT(MTIM2_SMCR,MTIM_ECE);
		#endif
			/* Enable trigger event interrupt */
			SET_BIT(MTIM2_DIER,MTIM_TIE);
			break;
		case TIM3:
			/* Set Counter Direction */
		#if MTIM3_COUNTER_DIRECTION ==0
			CLR_BIT(MTIM3_CR1,MTIM_DIR);
		#elif MTIM3_COUNTER_DIRECTION ==1
			SET_BIT(MTIM3_CR1,MTIM_DIR);
		#endif
			/* Enable Update Interrupt Event */
			SET_BIT(MTIM3_DIER,MTIM_UIE);
			/* External trigger configuration */
			/* Select External Trigger Polarity */
		#if EXT_TRIGGER_RAISING == 1
			CLR_BIT(MTIM3_SMCR,MTIM_ETP);
		#elif EXT_TRIGGER_FALLING == 1
			SET_BIT(MTIM3_SMCR,MTIM_ETP);
		#endif
			/* Select External Trigger Prescaler */
		#if EXT_TRIGGER_NO_PRESCALER == 1
			CLR_BIT(MTIM3_SMCR,MTIM_ETPS0);
			CLR_BIT(MTIM3_SMCR,MTIM_ETPS1);
		#elif EXT_TRIGGER_DIVIDED_2 == 1
			SET_BIT(MTIM3_SMCR,MTIM_ETPS0);
			CLR_BIT(MTIM3_SMCR,MTIM_ETPS1);
		#elif EXT_TRIGGER_DIVIDED_4 == 1
			CLR_BIT(MTIM3_SMCR,MTIM_ETPS0);
			SET_BIT(MTIM3_SMCR,MTIM_ETPS1);
		#elif EXT_TRIGGER_DIVIDED_8 == 1
			SET_BIT(MTIM3_SMCR,MTIM_ETPS0);
			SET_BIT(MTIM3_SMCR,MTIM_ETPS1);
		#endif
			/* Select External Trigger Filter */
		#if MTIM3_EXTERNAL_TRIGGER_Filter == 0
			CLR_BIT(MTIM3_SMCR,MTIM_ETF0);
			CLR_BIT(MTIM3_SMCR,MTIM_ETF1);
			CLR_BIT(MTIM3_SMCR,MTIM_ETF2);
			CLR_BIT(MTIM3_SMCR,MTIM_ETF3);
		#elif MTIM3_EXTERNAL_TRIGGER_Filter == 1
			SET_BIT(MTIM3_SMCR,MTIM_ETF0);
			CLR_BIT(MTIM3_SMCR,MTIM_ETF1);
			CLR_BIT(MTIM3_SMCR,MTIM_ETF2);
			CLR_BIT(MTIM3_SMCR,MTIM_ETF3);
		#elif MTIM3_EXTERNAL_TRIGGER_Filter == 2
			CLR_BIT(MTIM3_SMCR,MTIM_ETF0);
			SET_BIT(MTIM3_SMCR,MTIM_ETF1);
			CLR_BIT(MTIM3_SMCR,MTIM_ETF2);
			CLR_BIT(MTIM3_SMCR,MTIM_ETF3);
		#elif MTIM3_EXTERNAL_TRIGGER_Filter == 3
			SET_BIT(MTIM3_SMCR,MTIM_ETF0);
			SET_BIT(MTIM3_SMCR,MTIM_ETF1);
			CLR_BIT(MTIM3_SMCR,MTIM_ETF2);
			CLR_BIT(MTIM3_SMCR,MTIM_ETF3);
		#elif MTIM3_EXTERNAL_TRIGGER_Filter == 4
			CLR_BIT(MTIM3_SMCR,MTIM_ETF0);
			CLR_BIT(MTIM3_SMCR,MTIM_ETF1);
			SET_BIT(MTIM3_SMCR,MTIM_ETF2);
			CLR_BIT(MTIM3_SMCR,MTIM_ETF3);
		#elif MTIM3_EXTERNAL_TRIGGER_Filter == 5
			SET_BIT(MTIM3_SMCR,MTIM_ETF0);
			CLR_BIT(MTIM3_SMCR,MTIM_ETF1);
			SET_BIT(MTIM3_SMCR,MTIM_ETF2);
			CLR_BIT(MTIM3_SMCR,MTIM_ETF3);
		#elif MTIM3_EXTERNAL_TRIGGER_Filter == 6
			CLR_BIT(MTIM3_SMCR,MTIM_ETF0);
			SET_BIT(MTIM3_SMCR,MTIM_ETF1);
			SET_BIT(MTIM3_SMCR,MTIM_ETF2);
			CLR_BIT(MTIM3_SMCR,MTIM_ETF3);
		#elif MTIM3_EXTERNAL_TRIGGER_Filter == 7
			SET_BIT(MTIM3_SMCR,MTIM_ETF0);
			SET_BIT(MTIM3_SMCR,MTIM_ETF1);
			SET_BIT(MTIM3_SMCR,MTIM_ETF2);
			CLR_BIT(MTIM3_SMCR,MTIM_ETF3);
		#elif MTIM3_EXTERNAL_TRIGGER_Filter == 8
			CLR_BIT(MTIM3_SMCR,MTIM_ETF0);
			CLR_BIT(MTIM3_SMCR,MTIM_ETF1);
			CLR_BIT(MTIM3_SMCR,MTIM_ETF2);
			SET_BIT(MTIM3_SMCR,MTIM_ETF3);
		#elif MTIM3_EXTERNAL_TRIGGER_Filter == 9
			SET_BIT(MTIM3_SMCR,MTIM_ETF0);
			CLR_BIT(MTIM3_SMCR,MTIM_ETF1);
			CLR_BIT(MTIM3_SMCR,MTIM_ETF2);
			SET_BIT(MTIM3_SMCR,MTIM_ETF3);
		#elif MTIM3_EXTERNAL_TRIGGER_Filter == 10
			CLR_BIT(MTIM3_SMCR,MTIM_ETF0);
			SET_BIT(MTIM3_SMCR,MTIM_ETF1);
			CLR_BIT(MTIM3_SMCR,MTIM_ETF2);
			SET_BIT(MTIM3_SMCR,MTIM_ETF3);
		#elif MTIM3_EXTERNAL_TRIGGER_Filter == 11
			SET_BIT(MTIM3_SMCR,MTIM_ETF0);
			SET_BIT(MTIM3_SMCR,MTIM_ETF1);
			CLR_BIT(MTIM3_SMCR,MTIM_ETF2);
			SET_BIT(MTIM3_SMCR,MTIM_ETF3);
		#elif MTIM3_EXTERNAL_TRIGGER_Filter == 12
			CLR_BIT(MTIM3_SMCR,MTIM_ETF0);
			CLR_BIT(MTIM3_SMCR,MTIM_ETF1);
			SET_BIT(MTIM3_SMCR,MTIM_ETF2);
			SET_BIT(MTIM3_SMCR,MTIM_ETF3);
		#elif MTIM3_EXTERNAL_TRIGGER_Filter == 13
			SET_BIT(MTIM3_SMCR,MTIM_ETF0);
			CLR_BIT(MTIM3_SMCR,MTIM_ETF1);
			SET_BIT(MTIM3_SMCR,MTIM_ETF2);
			SET_BIT(MTIM3_SMCR,MTIM_ETF3);
		#elif MTIM3_EXTERNAL_TRIGGER_Filter == 14
			CLR_BIT(MTIM3_SMCR,MTIM_ETF0);
			SET_BIT(MTIM3_SMCR,MTIM_ETF1);
			SET_BIT(MTIM3_SMCR,MTIM_ETF2);
			SET_BIT(MTIM3_SMCR,MTIM_ETF3);
		#elif MTIM3_EXTERNAL_TRIGGER_Filter == 15
			SET_BIT(MTIM3_SMCR,MTIM_ETF0);
			SET_BIT(MTIM3_SMCR,MTIM_ETF1);
			SET_BIT(MTIM3_SMCR,MTIM_ETF2);
			SET_BIT(MTIM3_SMCR,MTIM_ETF3);
		#endif
			/* Select External Trigger Mode */
		#if MTIM3_EXTERNAL_TRIGGER_MODE == 1
			/* Reset SMS bits */
			CLR_BIT(MTIM3_SMCR,MTIM_SMS0);
			CLR_BIT(MTIM3_SMCR,MTIM_SMS1);
			CLR_BIT(MTIM3_SMCR,MTIM_SMS2);
			/* Select Trigger to External Trigger Input */
			SET_BIT(MTIM3_SMCR,MTIM_TS0);
			SET_BIT(MTIM3_SMCR,MTIM_TS1);
			SET_BIT(MTIM3_SMCR,MTIM_TS2);
			/* Select slave mode as external clock mode 1 */
			SET_BIT(MTIM3_SMCR,MTIM_SMS0);
			SET_BIT(MTIM3_SMCR,MTIM_SMS1);
			SET_BIT(MTIM3_SMCR,MTIM_SMS2);
		#elif MTIM3_EXTERNAL_TRIGGER_MODE == 2
			SET_BIT(MTIM3_SMCR,MTIM_ECE);
		#endif
			/* Enable trigger event interrupt */
			SET_BIT(MTIM3_DIER,MTIM_TIE);
			break;
		case TIM4:
			/* Set Counter Direction */
		#if MTIM4_COUNTER_DIRECTION ==0
			CLR_BIT(MTIM4_CR1,MTIM_DIR);
		#elif MTIM4_COUNTER_DIRECTION ==1
			SET_BIT(MTIM4_CR1,MTIM_DIR);
		#endif
			/* Enable Update Interrupt Event */
			SET_BIT(MTIM4_DIER,MTIM_UIE);
			/* External trigger configuration */
			/* Select External Trigger Polarity */
		#if EXT_TRIGGER_RAISING == 1
			CLR_BIT(MTIM4_SMCR,MTIM_ETP);
		#elif EXT_TRIGGER_FALLING == 1
			SET_BIT(MTIM4_SMCR,MTIM_ETP);
		#endif
			/* Select External Trigger Prescaler */
		#if EXT_TRIGGER_NO_PRESCALER == 1
			CLR_BIT(MTIM4_SMCR,MTIM_ETPS0);
			CLR_BIT(MTIM4_SMCR,MTIM_ETPS1);
		#elif EXT_TRIGGER_DIVIDED_2 == 1
			SET_BIT(MTIM4_SMCR,MTIM_ETPS0);
			CLR_BIT(MTIM4_SMCR,MTIM_ETPS1);
		#elif EXT_TRIGGER_DIVIDED_4 == 1
			CLR_BIT(MTIM4_SMCR,MTIM_ETPS0);
			SET_BIT(MTIM4_SMCR,MTIM_ETPS1);
		#elif EXT_TRIGGER_DIVIDED_8 == 1
			SET_BIT(MTIM4_SMCR,MTIM_ETPS0);
			SET_BIT(MTIM4_SMCR,MTIM_ETPS1);
		#endif
			/* Select External Trigger Filter */
		#if MTIM4_EXTERNAL_TRIGGER_Filter == 0
			CLR_BIT(MTIM4_SMCR,MTIM_ETF0);
			CLR_BIT(MTIM4_SMCR,MTIM_ETF1);
			CLR_BIT(MTIM4_SMCR,MTIM_ETF2);
			CLR_BIT(MTIM4_SMCR,MTIM_ETF3);
		#elif MTIM4_EXTERNAL_TRIGGER_Filter == 1
			SET_BIT(MTIM4_SMCR,MTIM_ETF0);
			CLR_BIT(MTIM4_SMCR,MTIM_ETF1);
			CLR_BIT(MTIM4_SMCR,MTIM_ETF2);
			CLR_BIT(MTIM4_SMCR,MTIM_ETF3);
		#elif MTIM4_EXTERNAL_TRIGGER_Filter == 2
			CLR_BIT(MTIM4_SMCR,MTIM_ETF0);
			SET_BIT(MTIM4_SMCR,MTIM_ETF1);
			CLR_BIT(MTIM4_SMCR,MTIM_ETF2);
			CLR_BIT(MTIM4_SMCR,MTIM_ETF3);
		#elif MTIM4_EXTERNAL_TRIGGER_Filter == 3
			SET_BIT(MTIM4_SMCR,MTIM_ETF0);
			SET_BIT(MTIM4_SMCR,MTIM_ETF1);
			CLR_BIT(MTIM4_SMCR,MTIM_ETF2);
			CLR_BIT(MTIM4_SMCR,MTIM_ETF3);
		#elif MTIM4_EXTERNAL_TRIGGER_Filter == 4
			CLR_BIT(MTIM4_SMCR,MTIM_ETF0);
			CLR_BIT(MTIM4_SMCR,MTIM_ETF1);
			SET_BIT(MTIM4_SMCR,MTIM_ETF2);
			CLR_BIT(MTIM4_SMCR,MTIM_ETF3);
		#elif MTIM4_EXTERNAL_TRIGGER_Filter == 5
			SET_BIT(MTIM4_SMCR,MTIM_ETF0);
			CLR_BIT(MTIM4_SMCR,MTIM_ETF1);
			SET_BIT(MTIM4_SMCR,MTIM_ETF2);
			CLR_BIT(MTIM4_SMCR,MTIM_ETF3);
		#elif MTIM4_EXTERNAL_TRIGGER_Filter == 6
			CLR_BIT(MTIM4_SMCR,MTIM_ETF0);
			SET_BIT(MTIM4_SMCR,MTIM_ETF1);
			SET_BIT(MTIM4_SMCR,MTIM_ETF2);
			CLR_BIT(MTIM4_SMCR,MTIM_ETF3);
		#elif MTIM4_EXTERNAL_TRIGGER_Filter == 7
			SET_BIT(MTIM4_SMCR,MTIM_ETF0);
			SET_BIT(MTIM4_SMCR,MTIM_ETF1);
			SET_BIT(MTIM4_SMCR,MTIM_ETF2);
			CLR_BIT(MTIM4_SMCR,MTIM_ETF3);
		#elif MTIM4_EXTERNAL_TRIGGER_Filter == 8
			CLR_BIT(MTIM4_SMCR,MTIM_ETF0);
			CLR_BIT(MTIM4_SMCR,MTIM_ETF1);
			CLR_BIT(MTIM4_SMCR,MTIM_ETF2);
			SET_BIT(MTIM4_SMCR,MTIM_ETF3);
		#elif MTIM4_EXTERNAL_TRIGGER_Filter == 9
			SET_BIT(MTIM4_SMCR,MTIM_ETF0);
			CLR_BIT(MTIM4_SMCR,MTIM_ETF1);
			CLR_BIT(MTIM4_SMCR,MTIM_ETF2);
			SET_BIT(MTIM4_SMCR,MTIM_ETF3);
		#elif MTIM4_EXTERNAL_TRIGGER_Filter == 10
			CLR_BIT(MTIM4_SMCR,MTIM_ETF0);
			SET_BIT(MTIM4_SMCR,MTIM_ETF1);
			CLR_BIT(MTIM4_SMCR,MTIM_ETF2);
			SET_BIT(MTIM4_SMCR,MTIM_ETF3);
		#elif MTIM4_EXTERNAL_TRIGGER_Filter == 11
			SET_BIT(MTIM4_SMCR,MTIM_ETF0);
			SET_BIT(MTIM4_SMCR,MTIM_ETF1);
			CLR_BIT(MTIM4_SMCR,MTIM_ETF2);
			SET_BIT(MTIM4_SMCR,MTIM_ETF3);
		#elif MTIM4_EXTERNAL_TRIGGER_Filter == 12
			CLR_BIT(MTIM4_SMCR,MTIM_ETF0);
			CLR_BIT(MTIM4_SMCR,MTIM_ETF1);
			SET_BIT(MTIM4_SMCR,MTIM_ETF2);
			SET_BIT(MTIM4_SMCR,MTIM_ETF3);
		#elif MTIM4_EXTERNAL_TRIGGER_Filter == 13
			SET_BIT(MTIM4_SMCR,MTIM_ETF0);
			CLR_BIT(MTIM4_SMCR,MTIM_ETF1);
			SET_BIT(MTIM4_SMCR,MTIM_ETF2);
			SET_BIT(MTIM4_SMCR,MTIM_ETF3);
		#elif MTIM4_EXTERNAL_TRIGGER_Filter == 14
			CLR_BIT(MTIM4_SMCR,MTIM_ETF0);
			SET_BIT(MTIM4_SMCR,MTIM_ETF1);
			SET_BIT(MTIM4_SMCR,MTIM_ETF2);
			SET_BIT(MTIM4_SMCR,MTIM_ETF3);
		#elif MTIM4_EXTERNAL_TRIGGER_Filter == 15
			SET_BIT(MTIM4_SMCR,MTIM_ETF0);
			SET_BIT(MTIM4_SMCR,MTIM_ETF1);
			SET_BIT(MTIM4_SMCR,MTIM_ETF2);
			SET_BIT(MTIM4_SMCR,MTIM_ETF3);
		#endif
			/* Select External Trigger Mode */
		#if MTIM4_EXTERNAL_TRIGGER_MODE == 1
			/* Reset SMS bits */
			CLR_BIT(MTIM4_SMCR,MTIM_SMS0);
			CLR_BIT(MTIM4_SMCR,MTIM_SMS1);
			CLR_BIT(MTIM4_SMCR,MTIM_SMS2);
			/* Select Trigger to External Trigger Input */
			SET_BIT(MTIM4_SMCR,MTIM_TS0);
			SET_BIT(MTIM4_SMCR,MTIM_TS1);
			SET_BIT(MTIM4_SMCR,MTIM_TS2);
			/* Select slave mode as external clock mode 1 */
			SET_BIT(MTIM4_SMCR,MTIM_SMS0);
			SET_BIT(MTIM4_SMCR,MTIM_SMS1);
			SET_BIT(MTIM4_SMCR,MTIM_SMS2);
		#elif MTIM4_EXTERNAL_TRIGGER_MODE == 2
			SET_BIT(MTIM4_SMCR,MTIM_ECE);
		#endif
			/* Enable trigger event interrupt */
			SET_BIT(MTIM4_DIER,MTIM_TIE);
			break;
		case TIM5:
			/* Set Counter Direction */
		#if MTIM5_COUNTER_DIRECTION ==0
			CLR_BIT(MTIM5_CR1,MTIM_DIR);
		#elif MTIM5_COUNTER_DIRECTION ==1
			SET_BIT(MTIM5_CR1,MTIM_DIR);
		#endif
			/* Enable Update Interrupt Event */
			SET_BIT(MTIM5_DIER,MTIM_UIE);
			/* External trigger configuration */
			/* Select External Trigger Polarity */
		#if EXT_TRIGGER_RAISING == 1
			CLR_BIT(MTIM5_SMCR,MTIM_ETP);
		#elif EXT_TRIGGER_FALLING == 1
			SET_BIT(MTIM5_SMCR,MTIM_ETP);
		#endif
			/* Select External Trigger Prescaler */
		#if EXT_TRIGGER_NO_PRESCALER == 1
			CLR_BIT(MTIM5_SMCR,MTIM_ETPS0);
			CLR_BIT(MTIM5_SMCR,MTIM_ETPS1);
		#elif EXT_TRIGGER_DIVIDED_2 == 1
			SET_BIT(MTIM5_SMCR,MTIM_ETPS0);
			CLR_BIT(MTIM5_SMCR,MTIM_ETPS1);
		#elif EXT_TRIGGER_DIVIDED_4 == 1
			CLR_BIT(MTIM5_SMCR,MTIM_ETPS0);
			SET_BIT(MTIM5_SMCR,MTIM_ETPS1);
		#elif EXT_TRIGGER_DIVIDED_8 == 1
			SET_BIT(MTIM5_SMCR,MTIM_ETPS0);
			SET_BIT(MTIM5_SMCR,MTIM_ETPS1);
		#endif
			/* Select External Trigger Filter */
		#if MTIM5_EXTERNAL_TRIGGER_Filter == 0
			CLR_BIT(MTIM5_SMCR,MTIM_ETF0);
			CLR_BIT(MTIM5_SMCR,MTIM_ETF1);
			CLR_BIT(MTIM5_SMCR,MTIM_ETF2);
			CLR_BIT(MTIM5_SMCR,MTIM_ETF3);
		#elif MTIM5_EXTERNAL_TRIGGER_Filter == 1
			SET_BIT(MTIM5_SMCR,MTIM_ETF0);
			CLR_BIT(MTIM5_SMCR,MTIM_ETF1);
			CLR_BIT(MTIM5_SMCR,MTIM_ETF2);
			CLR_BIT(MTIM5_SMCR,MTIM_ETF3);
		#elif MTIM5_EXTERNAL_TRIGGER_Filter == 2
			CLR_BIT(MTIM5_SMCR,MTIM_ETF0);
			SET_BIT(MTIM5_SMCR,MTIM_ETF1);
			CLR_BIT(MTIM5_SMCR,MTIM_ETF2);
			CLR_BIT(MTIM5_SMCR,MTIM_ETF3);
		#elif MTIM5_EXTERNAL_TRIGGER_Filter == 3
			SET_BIT(MTIM5_SMCR,MTIM_ETF0);
			SET_BIT(MTIM5_SMCR,MTIM_ETF1);
			CLR_BIT(MTIM5_SMCR,MTIM_ETF2);
			CLR_BIT(MTIM5_SMCR,MTIM_ETF3);
		#elif MTIM5_EXTERNAL_TRIGGER_Filter == 4
			CLR_BIT(MTIM5_SMCR,MTIM_ETF0);
			CLR_BIT(MTIM5_SMCR,MTIM_ETF1);
			SET_BIT(MTIM5_SMCR,MTIM_ETF2);
			CLR_BIT(MTIM5_SMCR,MTIM_ETF3);
		#elif MTIM5_EXTERNAL_TRIGGER_Filter == 5
			SET_BIT(MTIM5_SMCR,MTIM_ETF0);
			CLR_BIT(MTIM5_SMCR,MTIM_ETF1);
			SET_BIT(MTIM5_SMCR,MTIM_ETF2);
			CLR_BIT(MTIM5_SMCR,MTIM_ETF3);
		#elif MTIM5_EXTERNAL_TRIGGER_Filter == 6
			CLR_BIT(MTIM5_SMCR,MTIM_ETF0);
			SET_BIT(MTIM5_SMCR,MTIM_ETF1);
			SET_BIT(MTIM5_SMCR,MTIM_ETF2);
			CLR_BIT(MTIM5_SMCR,MTIM_ETF3);
		#elif MTIM5_EXTERNAL_TRIGGER_Filter == 7
			SET_BIT(MTIM5_SMCR,MTIM_ETF0);
			SET_BIT(MTIM5_SMCR,MTIM_ETF1);
			SET_BIT(MTIM5_SMCR,MTIM_ETF2);
			CLR_BIT(MTIM5_SMCR,MTIM_ETF3);
		#elif MTIM5_EXTERNAL_TRIGGER_Filter == 8
			CLR_BIT(MTIM5_SMCR,MTIM_ETF0);
			CLR_BIT(MTIM5_SMCR,MTIM_ETF1);
			CLR_BIT(MTIM5_SMCR,MTIM_ETF2);
			SET_BIT(MTIM5_SMCR,MTIM_ETF3);
		#elif MTIM5_EXTERNAL_TRIGGER_Filter == 9
			SET_BIT(MTIM5_SMCR,MTIM_ETF0);
			CLR_BIT(MTIM5_SMCR,MTIM_ETF1);
			CLR_BIT(MTIM5_SMCR,MTIM_ETF2);
			SET_BIT(MTIM5_SMCR,MTIM_ETF3);
		#elif MTIM5_EXTERNAL_TRIGGER_Filter == 10
			CLR_BIT(MTIM5_SMCR,MTIM_ETF0);
			SET_BIT(MTIM5_SMCR,MTIM_ETF1);
			CLR_BIT(MTIM5_SMCR,MTIM_ETF2);
			SET_BIT(MTIM5_SMCR,MTIM_ETF3);
		#elif MTIM5_EXTERNAL_TRIGGER_Filter == 11
			SET_BIT(MTIM5_SMCR,MTIM_ETF0);
			SET_BIT(MTIM5_SMCR,MTIM_ETF1);
			CLR_BIT(MTIM5_SMCR,MTIM_ETF2);
			SET_BIT(MTIM5_SMCR,MTIM_ETF3);
		#elif MTIM5_EXTERNAL_TRIGGER_Filter == 12
			CLR_BIT(MTIM5_SMCR,MTIM_ETF0);
			CLR_BIT(MTIM5_SMCR,MTIM_ETF1);
			SET_BIT(MTIM5_SMCR,MTIM_ETF2);
			SET_BIT(MTIM5_SMCR,MTIM_ETF3);
		#elif MTIM5_EXTERNAL_TRIGGER_Filter == 13
			SET_BIT(MTIM5_SMCR,MTIM_ETF0);
			CLR_BIT(MTIM5_SMCR,MTIM_ETF1);
			SET_BIT(MTIM5_SMCR,MTIM_ETF2);
			SET_BIT(MTIM5_SMCR,MTIM_ETF3);
		#elif MTIM5_EXTERNAL_TRIGGER_Filter == 14
			CLR_BIT(MTIM5_SMCR,MTIM_ETF0);
			SET_BIT(MTIM5_SMCR,MTIM_ETF1);
			SET_BIT(MTIM5_SMCR,MTIM_ETF2);
			SET_BIT(MTIM5_SMCR,MTIM_ETF3);
		#elif MTIM5_EXTERNAL_TRIGGER_Filter == 15
			SET_BIT(MTIM5_SMCR,MTIM_ETF0);
			SET_BIT(MTIM5_SMCR,MTIM_ETF1);
			SET_BIT(MTIM5_SMCR,MTIM_ETF2);
			SET_BIT(MTIM5_SMCR,MTIM_ETF3);
		#endif
			/* Select External Trigger Mode */
		#if MTIM5_EXTERNAL_TRIGGER_MODE == 1
			/* Reset SMS bits */
			CLR_BIT(MTIM5_SMCR,MTIM_SMS0);
			CLR_BIT(MTIM5_SMCR,MTIM_SMS1);
			CLR_BIT(MTIM5_SMCR,MTIM_SMS2);
			/* Select Trigger to External Trigger Input */
			SET_BIT(MTIM5_SMCR,MTIM_TS0);
			SET_BIT(MTIM5_SMCR,MTIM_TS1);
			SET_BIT(MTIM5_SMCR,MTIM_TS2);
			/* Select slave mode as external clock mode 1 */
			SET_BIT(MTIM5_SMCR,MTIM_SMS0);
			SET_BIT(MTIM5_SMCR,MTIM_SMS1);
			SET_BIT(MTIM5_SMCR,MTIM_SMS2);
		#elif MTIM5_EXTERNAL_TRIGGER_MODE == 2
			SET_BIT(MTIM5_SMCR,MTIM_ECE);
		#endif
			/* Enable trigger event interrupt */
			SET_BIT(MTIM5_DIER,MTIM_TIE);
			break;
		}
	}
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}

/*----------MTIM_u8PWMInputCaptureInit Implementation----------*/
u8 MTIM_u8PWMInputCaptureInit(TimId_t Copy_uddtTimerId)
{
	u8 Local_u8ErrorState = 0;
	if(Copy_uddtTimerId <= TIM5)
	{
		switch(Copy_uddtTimerId)
		{
		case TIM2:
			/* Select Counter Direction */
		#if MTIM2_COUNTER_DIRECTION ==0
			CLR_BIT(MTIM2_CR1,MTIM_DIR);
		#elif MTIM2_COUNTER_DIRECTION ==1
			SET_BIT(MTIM2_CR1,MTIM_DIR);
		#endif
			/* Timer 1 input channel 1 IC1 configuration */
			/* Select the active input for CCR1 */
			SET_BIT(MTIM2_CCMR1,MTIM_CC1S0);
			CLR_BIT(MTIM2_CCMR1,MTIM_CC1S1);
			/* Select the active polarity for TI1FP1 as raising edge */
			CLR_BIT(MTIM2_CCER,MTIM_CC1P);
			CLR_BIT(MTIM2_CCER,MTIM_CC1NP);
			/* Select the active input for CCR2 */
			CLR_BIT(MTIM2_CCMR1,MTIM_CC2S0);
			SET_BIT(MTIM2_CCMR1,MTIM_CC2S1);
			/* Select the active polarity for TI1FP2 as falling edge */
			SET_BIT(MTIM2_CCER,MTIM_CC2P);
			CLR_BIT(MTIM2_CCER,MTIM_CC2NP);
			/* Select the trigger input */
			SET_BIT(MTIM2_SMCR,MTIM_TS0);
			CLR_BIT(MTIM2_SMCR,MTIM_TS1);
			SET_BIT(MTIM2_SMCR,MTIM_TS2);
			/* Select reset mode from slave mode controller */
			CLR_BIT(MTIM2_SMCR,MTIM_SMS0);
			CLR_BIT(MTIM2_SMCR,MTIM_SMS1);
			SET_BIT(MTIM2_SMCR,MTIM_SMS2);
			/* Enable CC1 and CC2 */
			SET_BIT(MTIM2_CCER,MTIM_CC1E);
			SET_BIT(MTIM2_CCER,MTIM_CC2E);
			break;
		case TIM3:
			/* Select Counter Direction */
		#if MTIM3_COUNTER_DIRECTION ==0
			CLR_BIT(MTIM3_CR1,MTIM_DIR);
		#elif MTIM3_COUNTER_DIRECTION ==1
			SET_BIT(MTIM3_CR1,MTIM_DIR);
		#endif
			/* Timer 1 input channel 1 IC1 configuration */
			/* Select the active input for CCR1 */
			SET_BIT(MTIM3_CCMR1,MTIM_CC1S0);
			CLR_BIT(MTIM3_CCMR1,MTIM_CC1S1);
			/* Select the active polarity for TI1FP1 as raising edge */
			CLR_BIT(MTIM3_CCER,MTIM_CC1P);
			CLR_BIT(MTIM3_CCER,MTIM_CC1NP);
			/* Select the active input for CCR2 */
			CLR_BIT(MTIM3_CCMR1,MTIM_CC2S0);
			SET_BIT(MTIM3_CCMR1,MTIM_CC2S1);
			/* Select the active polarity for TI1FP2 as falling edge */
			SET_BIT(MTIM3_CCER,MTIM_CC2P);
			CLR_BIT(MTIM3_CCER,MTIM_CC2NP);
			/* Select the trigger input */
			SET_BIT(MTIM3_SMCR,MTIM_TS0);
			CLR_BIT(MTIM3_SMCR,MTIM_TS1);
			SET_BIT(MTIM3_SMCR,MTIM_TS2);
			/* Select reset mode from slave mode controller */
			CLR_BIT(MTIM3_SMCR,MTIM_SMS0);
			CLR_BIT(MTIM3_SMCR,MTIM_SMS1);
			SET_BIT(MTIM3_SMCR,MTIM_SMS2);
			/* Enable CC1 and CC2 */
			SET_BIT(MTIM3_CCER,MTIM_CC1E);
			SET_BIT(MTIM3_CCER,MTIM_CC2E);
			break;
		case TIM4:
			/* Select Counter Direction */
		#if MTIM4_COUNTER_DIRECTION ==0
			CLR_BIT(MTIM4_CR1,MTIM_DIR);
		#elif MTIM4_COUNTER_DIRECTION ==1
			SET_BIT(MTIM4_CR1,MTIM_DIR);
		#endif
			/* Timer 1 input channel 1 IC1 configuration */
			/* Select the active input for CCR1 */
			SET_BIT(MTIM4_CCMR1,MTIM_CC1S0);
			CLR_BIT(MTIM4_CCMR1,MTIM_CC1S1);
			/* Select the active polarity for TI1FP1 as raising edge */
			CLR_BIT(MTIM4_CCER,MTIM_CC1P);
			CLR_BIT(MTIM4_CCER,MTIM_CC1NP);
			/* Select the active input for CCR2 */
			CLR_BIT(MTIM4_CCMR1,MTIM_CC2S0);
			SET_BIT(MTIM4_CCMR1,MTIM_CC2S1);
			/* Select the active polarity for TI1FP2 as falling edge */
			SET_BIT(MTIM4_CCER,MTIM_CC2P);
			CLR_BIT(MTIM4_CCER,MTIM_CC2NP);
			/* Select the trigger input */
			SET_BIT(MTIM4_SMCR,MTIM_TS0);
			CLR_BIT(MTIM4_SMCR,MTIM_TS1);
			SET_BIT(MTIM4_SMCR,MTIM_TS2);
			/* Select reset mode from slave mode controller */
			CLR_BIT(MTIM4_SMCR,MTIM_SMS0);
			CLR_BIT(MTIM4_SMCR,MTIM_SMS1);
			SET_BIT(MTIM4_SMCR,MTIM_SMS2);
			/* Enable CC1 and CC2 */
			SET_BIT(MTIM4_CCER,MTIM_CC1E);
			SET_BIT(MTIM4_CCER,MTIM_CC2E);
			break;
		case TIM5:
			/* Select Counter Direction */
		#if MTIM5_COUNTER_DIRECTION ==0
			CLR_BIT(MTIM5_CR1,MTIM_DIR);
		#elif MTIM5_COUNTER_DIRECTION ==1
			SET_BIT(MTIM5_CR1,MTIM_DIR);
		#endif
			/* Timer 1 input channel 1 IC1 configuration */
			/* Select the active input for CCR1 */
			SET_BIT(MTIM5_CCMR1,MTIM_CC1S0);
			CLR_BIT(MTIM5_CCMR1,MTIM_CC1S1);
			/* Select the active polarity for TI1FP1 as raising edge */
			CLR_BIT(MTIM5_CCER,MTIM_CC1P);
			CLR_BIT(MTIM5_CCER,MTIM_CC1NP);
			/* Select the active input for CCR2 */
			CLR_BIT(MTIM5_CCMR1,MTIM_CC2S0);
			SET_BIT(MTIM5_CCMR1,MTIM_CC2S1);
			/* Select the active polarity for TI1FP2 as falling edge */
			SET_BIT(MTIM5_CCER,MTIM_CC2P);
			CLR_BIT(MTIM5_CCER,MTIM_CC2NP);
			/* Select the trigger input */
			SET_BIT(MTIM5_SMCR,MTIM_TS0);
			CLR_BIT(MTIM5_SMCR,MTIM_TS1);
			SET_BIT(MTIM5_SMCR,MTIM_TS2);
			/* Select reset mode from slave mode controller */
			CLR_BIT(MTIM5_SMCR,MTIM_SMS0);
			CLR_BIT(MTIM5_SMCR,MTIM_SMS1);
			SET_BIT(MTIM5_SMCR,MTIM_SMS2);
			/* Enable CC1 and CC2 */
			SET_BIT(MTIM5_CCER,MTIM_CC1E);
			SET_BIT(MTIM5_CCER,MTIM_CC2E);
			break;
		}
	}
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}

/*----------MTIM_u8GeneratePWM Implementation----------*/
u8 MTIM_u8GeneratePWM(TimId_t Copy_uddtTimerId, OutComparePolarity_t Copy_uddtOCP, u8 Copy_u8DutyCycle)
{
	u8 Local_u8ErrorState = 0;
	if(Copy_uddtTimerId <= TIM5)
	{
		switch(Copy_uddtTimerId)
		{
		case TIM2:
			/* Enable Auto-reload preload */
			SET_BIT(MTIM2_CR1,MTIM_ARPE);
			/* Select center aligned mode */
		#if MTIM2_CENTER_MODE_SELECTION == 0U
			CLR_BIT(MTIM2_CR1,MTIM_CMS0);
			CLR_BIT(MTIM2_CR1,MTIM_CMS1);
		#elif MTIM2_CENTER_MODE_SELECTION == 1U
			SET_BIT(MTIM2_CR1,MTIM_CMS0);
			CLR_BIT(MTIM2_CR1,MTIM_CMS1);
		#elif MTIM2_CENTER_MODE_SELECTION == 2U
			CLR_BIT(MTIM2_CR1,MTIM_CMS0);
			SET_BIT(MTIM2_CR1,MTIM_CMS1);
		#elif MTIM2_CENTER_MODE_SELECTION == 3U
			SET_BIT(MTIM2_CR1,MTIM_CMS0);
			SET_BIT(MTIM2_CR1,MTIM_CMS1);
		#endif
			/* Select Counter Direction */
		#if MTIM2_COUNTER_DIRECTION ==0
			CLR_BIT(MTIM2_CR1,MTIM_DIR);
		#elif MTIM2_COUNTER_DIRECTION ==1
			SET_BIT(MTIM2_CR1,MTIM_DIR);
		#endif
			/* Select channel */
		#if TIM_CH1_EN == 1U
			/* Set Capture/Compare 1 as output */
			CLR_BIT(MTIM2_CCMR1,MTIM_CC1S0);
			CLR_BIT(MTIM2_CCMR1,MTIM_CC1S1);
			/* Enable Output Compare 1 preload */
			SET_BIT(MTIM2_CCMR1,MTIM_OC1PE);
			/* Select the polarity of output compare */
			switch(Copy_uddtOCP)
			{
			case MTIM_HIGH:
				CLR_BIT(MTIM2_CCER,MTIM_CC1P);
				break;
			case MTIM_LOW:
				SET_BIT(MTIM2_CCER,MTIM_CC1P);
			}
			CLR_BIT(MTIM2_CCER,MTIM_CC1NP);
			/* Select Output Compare 1 PWM mode*/
		#if MTIM2_PWM_MODE == 1
			CLR_BIT(MTIM2_CCMR1,MTIM_OC1M0);
			SET_BIT(MTIM2_CCMR1,MTIM_OC1M1);
			SET_BIT(MTIM2_CCMR1,MTIM_OC1M2);
		#elif MTIM2_PWM_MODE == 2
			SET_BIT(MTIM2_CCMR1,MTIM_OC1M0);
			SET_BIT(MTIM2_CCMR1,MTIM_OC1M1);
			SET_BIT(MTIM2_CCMR1,MTIM_OC1M2);
		#endif
			/* Enable Capture/Compare 1 output */
			CLR_BIT(MTIM2_CCER,MTIM_CC1E);
			MTIM2_CCR1 = ((Copy_u8DutyCycle*MTIM2_ARR)/100);
		#elif TIM_CH2_EN == 1U
			/* Set Capture/Compare 2 as output */
			CLR_BIT(MTIM2_CCMR1,MTIM_CC2S0);
			CLR_BIT(MTIM2_CCMR1,MTIM_CC2S1);
			/* Enable Output Compare 2 preload */
			SET_BIT(MTIM2_CCMR1,MTIM_OC2PE);
			/* Select the polarity of output compare */
			switch(Copy_uddtOCP)
			{
			case MTIM_HIGH:
				CLR_BIT(MTIM2_CCER,MTIM_CC2P);
				break;
			case MTIM_LOW:
				SET_BIT(MTIM2_CCER,MTIM_CC2P);
			}
			CLR_BIT(MTIM2_CCER,MTIM_CC2NP);
			/* Select Output Compare 2 PWM mode */
		#if MTIM2_PWM_MODE == 1
			CLR_BIT(MTIM2_CCMR1,MTIM_OC2M0);
			SET_BIT(MTIM2_CCMR1,MTIM_OC2M1);
			SET_BIT(MTIM2_CCMR1,MTIM_OC2M2);
		#elif MTIM2_PWM_MODE == 2
			SET_BIT(MTIM2_CCMR1,MTIM_OC2M0);
			SET_BIT(MTIM2_CCMR1,MTIM_OC2M1);
			SET_BIT(MTIM2_CCMR1,MTIM_OC2M2);
		#endif
			/* Enable Capture/Compare 2 output */
			CLR_BIT(MTIM2_CCER,MTIM_CC2E);
			MTIM2_CCR2 = ((Copy_u8DutyCycle*MTIM2_ARR)/100);
		#elif TIM_CH3_EN == 1U
			/* Set Capture/Compare 3 as output */
			CLR_BIT(MTIM2_CCMR1,MTIM_CC3S0);
			CLR_BIT(MTIM2_CCMR1,MTIM_CC3S1);
			/* Enable Output Compare 3 preload */
			SET_BIT(MTIM2_CCMR1,MTIM_OC3PE);
			/* Select the polarity of output compare */
			switch(Copy_uddtOCP)
			{
			case MTIM_HIGH:
				CLR_BIT(MTIM2_CCER,MTIM_CC3P);
				break;
			case MTIM_LOW:
				SET_BIT(MTIM2_CCER,MTIM_CC3P);
			}
			CLR_BIT(MTIM2_CCER,MTIM_CC3NP);
			/* Select Output Compare 3 PWM mode */
		#if MTIM2_PWM_MODE == 1
			CLR_BIT(MTIM2_CCMR1,MTIM_OC3M0);
			SET_BIT(MTIM2_CCMR1,MTIM_OC3M1);
			SET_BIT(MTIM2_CCMR1,MTIM_OC3M2);
		#elif MTIM2_PWM_MODE == 2
			SET_BIT(MTIM2_CCMR1,MTIM_OC3M0);
			SET_BIT(MTIM2_CCMR1,MTIM_OC3M1);
			SET_BIT(MTIM2_CCMR1,MTIM_OC3M2);
		#endif
			/* Enable Capture/Compare 3 output */
			CLR_BIT(MTIM2_CCER,MTIM_CC3E);
			MTIM2_CCR3 = ((Copy_u8DutyCycle*MTIM2_ARR)/100);
		#elif TIM_CH4_EN == 1U
			/* Set Capture/Compare 4 as output */
			CLR_BIT(MTIM2_CCMR1,MTIM_CC4S0);
			CLR_BIT(MTIM2_CCMR1,MTIM_CC4S1);
			/* Enable Output Compare 4 preload */
			SET_BIT(MTIM2_CCMR1,MTIM_OC4PE);
			/* Select the polarity of output compare */
			switch(Copy_uddtOCP)
			{
			case MTIM_HIGH:
				CLR_BIT(MTIM2_CCER,MTIM_CC4P);
				break;
			case MTIM_LOW:
				SET_BIT(MTIM2_CCER,MTIM_CC4P);
			}
			CLR_BIT(MTIM2_CCER,MTIM_CC4NP);
			/* Select Output Compare 4 PWM mode */
		#if MTIM2_PWM_MODE == 1
			CLR_BIT(MTIM2_CCMR1,MTIM_OC4M0);
			SET_BIT(MTIM2_CCMR1,MTIM_OC4M1);
			SET_BIT(MTIM2_CCMR1,MTIM_OC4M2);
		#elif MTIM2_PWM_MODE == 2
			SET_BIT(MTIM2_CCMR1,MTIM_OC4M0);
			SET_BIT(MTIM2_CCMR1,MTIM_OC4M1);
			SET_BIT(MTIM2_CCMR1,MTIM_OC4M2);
		#endif
			/* Enable Capture/Compare 4 output */
			CLR_BIT(MTIM2_CCER,MTIM_CC4E);
			MTIM2_CCR4 = ((Copy_u8DutyCycle*MTIM2_ARR)/100);
		#endif
			/* Initialize all the registers */
			SET_BIT(MTIM2_EGR,MTIM_UG);
			break;
		case TIM3:
			/* Enable Auto-reload preload */
			SET_BIT(MTIM3_CR1,MTIM_ARPE);
			/* Select center aligned mode */
		#if MTIM3_CENTER_MODE_SELECTION == 0U
			CLR_BIT(MTIM3_CR1,MTIM_CMS0);
			CLR_BIT(MTIM3_CR1,MTIM_CMS1);
		#elif MTIM3_CENTER_MODE_SELECTION == 1U
			SET_BIT(MTIM3_CR1,MTIM_CMS0);
			CLR_BIT(MTIM3_CR1,MTIM_CMS1);
		#elif MTIM3_CENTER_MODE_SELECTION == 2U
			CLR_BIT(MTIM3_CR1,MTIM_CMS0);
			SET_BIT(MTIM3_CR1,MTIM_CMS1);
		#elif MTIM3_CENTER_MODE_SELECTION == 3U
			SET_BIT(MTIM3_CR1,MTIM_CMS0);
			SET_BIT(MTIM3_CR1,MTIM_CMS1);
		#endif
			/* Select Counter Direction */
		#if MTIM3_COUNTER_DIRECTION ==0
			CLR_BIT(MTIM3_CR1,MTIM_DIR);
		#elif MTIM3_COUNTER_DIRECTION ==1
			SET_BIT(MTIM3_CR1,MTIM_DIR);
		#endif
			/* Select channel */
		#if TIM_CH1_EN == 1U
			/* Set Capture/Compare 1 as output */
			CLR_BIT(MTIM3_CCMR1,MTIM_CC1S0);
			CLR_BIT(MTIM3_CCMR1,MTIM_CC1S1);
			/* Enable Output Compare 1 preload */
			SET_BIT(MTIM3_CCMR1,MTIM_OC1PE);
			/* Select the polarity of output compare */
			switch(Copy_uddtOCP)
			{
			case MTIM_HIGH:
				CLR_BIT(MTIM3_CCER,MTIM_CC1P);
				break;
			case MTIM_LOW:
				SET_BIT(MTIM3_CCER,MTIM_CC1P);
			}
			CLR_BIT(MTIM3_CCER,MTIM_CC1NP);
			/* Select Output Compare 1 PWM mode */
		#if MTIM3_PWM_MODE == 1
			CLR_BIT(MTIM3_CCMR1,MTIM_OC1M0);
			SET_BIT(MTIM3_CCMR1,MTIM_OC1M1);
			SET_BIT(MTIM3_CCMR1,MTIM_OC1M2);
		#elif MTIM3_PWM_MODE == 2
			SET_BIT(MTIM3_CCMR1,MTIM_OC1M0);
			SET_BIT(MTIM3_CCMR1,MTIM_OC1M1);
			SET_BIT(MTIM3_CCMR1,MTIM_OC1M2);
		#endif
			/* Enable Capture/Compare 1 output */
			CLR_BIT(MTIM3_CCER,MTIM_CC1E);
			MTIM3_CCR1 = ((Copy_u8DutyCycle*MTIM3_ARR)/100);
		#elif TIM_CH2_EN == 1U
			/* Set Capture/Compare 2 as output */
			CLR_BIT(MTIM3_CCMR1,MTIM_CC2S0);
			CLR_BIT(MTIM3_CCMR1,MTIM_CC2S1);
			/* Enable Output Compare 2 preload */
			SET_BIT(MTIM3_CCMR1,MTIM_OC2PE);
			/* Select the polarity of output compare */
			switch(Copy_uddtOCP)
			{
			case MTIM_HIGH:
				CLR_BIT(MTIM3_CCER,MTIM_CC2P);
				break;
			case MTIM_LOW:
				SET_BIT(MTIM3_CCER,MTIM_CC2P);
			}
			CLR_BIT(MTIM3_CCER,MTIM_CC2NP);
			/* Select Output Compare 2 PWM mode */
		#if MTIM3_PWM_MODE == 1
			CLR_BIT(MTIM3_CCMR1,MTIM_OC2M0);
			SET_BIT(MTIM3_CCMR1,MTIM_OC2M1);
			SET_BIT(MTIM3_CCMR1,MTIM_OC2M2);
		#elif MTIM3_PWM_MODE == 2
			SET_BIT(MTIM3_CCMR1,MTIM_OC2M0);
			SET_BIT(MTIM3_CCMR1,MTIM_OC2M1);
			SET_BIT(MTIM3_CCMR1,MTIM_OC2M2);
		#endif
			/* Enable Capture/Compare 2 output */
			CLR_BIT(MTIM3_CCER,MTIM_CC2E);
			MTIM3_CCR2 = ((Copy_u8DutyCycle*MTIM3_ARR)/100);
		#elif TIM_CH3_EN == 1U
			/* Set Capture/Compare 3 as output */
			CLR_BIT(MTIM3_CCMR1,MTIM_CC3S0);
			CLR_BIT(MTIM3_CCMR1,MTIM_CC3S1);
			/* Enable Output Compare 3 preload */
			SET_BIT(MTIM3_CCMR1,MTIM_OC3PE);
			/* Select the polarity of output compare */
			switch(Copy_uddtOCP)
			{
			case MTIM_HIGH:
				CLR_BIT(MTIM3_CCER,MTIM_CC3P);
				break;
			case MTIM_LOW:
				SET_BIT(MTIM3_CCER,MTIM_CC3P);
			}
			CLR_BIT(MTIM3_CCER,MTIM_CC3NP);
			/* Select Output Compare 3 PWM mode */
		#if MTIM3_PWM_MODE == 1
			CLR_BIT(MTIM3_CCMR1,MTIM_OC3M0);
			SET_BIT(MTIM3_CCMR1,MTIM_OC3M1);
			SET_BIT(MTIM3_CCMR1,MTIM_OC3M2);
		#elif MTIM3_PWM_MODE == 2
			SET_BIT(MTIM3_CCMR1,MTIM_OC3M0);
			SET_BIT(MTIM3_CCMR1,MTIM_OC3M1);
			SET_BIT(MTIM3_CCMR1,MTIM_OC3M2);
		#endif
			/* Enable Capture/Compare 3 output */
			CLR_BIT(MTIM3_CCER,MTIM_CC3E);
			MTIM3_CCR3 = ((Copy_u8DutyCycle*MTIM3_ARR)/100);
		#elif TIM_CH4_EN == 1U
			/* Set Capture/Compare 4 as output */
			CLR_BIT(MTIM3_CCMR1,MTIM_CC4S0);
			CLR_BIT(MTIM3_CCMR1,MTIM_CC4S1);
			/* Enable Output Compare 4 preload */
			SET_BIT(MTIM3_CCMR1,MTIM_OC4PE);
			/* Select the polarity of output compare */
			switch(Copy_uddtOCP)
			{
			case MTIM_HIGH:
				CLR_BIT(MTIM3_CCER,MTIM_CC4P);
				break;
			case MTIM_LOW:
				SET_BIT(MTIM3_CCER,MTIM_CC4P);
			}
			CLR_BIT(MTIM3_CCER,MTIM_CC4NP);
			/* Select Output Compare 4 PWM mode */
		#if MTIM3_PWM_MODE == 1
			CLR_BIT(MTIM3_CCMR1,MTIM_OC4M0);
			SET_BIT(MTIM3_CCMR1,MTIM_OC4M1);
			SET_BIT(MTIM3_CCMR1,MTIM_OC4M2);
		#elif MTIM3_PWM_MODE == 2
			SET_BIT(MTIM3_CCMR1,MTIM_OC4M0);
			SET_BIT(MTIM3_CCMR1,MTIM_OC4M1);
			SET_BIT(MTIM3_CCMR1,MTIM_OC4M2);
		#endif
			/* Enable Capture/Compare 4 output */
			CLR_BIT(MTIM3_CCER,MTIM_CC4E);
			MTIM3_CCR4 = ((Copy_u8DutyCycle*MTIM3_ARR)/100);
		#endif
			/* Initialize all the registers */
			SET_BIT(MTIM3_EGR,MTIM_UG);
			break;
		case TIM4:
			/* Enable Auto-reload preload */
			SET_BIT(MTIM4_CR1,MTIM_ARPE);
			/* Select center aligned mode */
		#if MTIM4_CENTER_MODE_SELECTION == 0U
			CLR_BIT(MTIM4_CR1,MTIM_CMS0);
			CLR_BIT(MTIM4_CR1,MTIM_CMS1);
		#elif MTIM4_CENTER_MODE_SELECTION == 1U
			SET_BIT(MTIM4_CR1,MTIM_CMS0);
			CLR_BIT(MTIM4_CR1,MTIM_CMS1);
		#elif MTIM4_CENTER_MODE_SELECTION == 2U
			CLR_BIT(MTIM4_CR1,MTIM_CMS0);
			SET_BIT(MTIM4_CR1,MTIM_CMS1);
		#elif MTIM4_CENTER_MODE_SELECTION == 3U
			SET_BIT(MTIM4_CR1,MTIM_CMS0);
			SET_BIT(MTIM4_CR1,MTIM_CMS1);
		#endif
			/* Select Counter Direction */
		#if MTIM4_COUNTER_DIRECTION ==0
			CLR_BIT(MTIM4_CR1,MTIM_DIR);
		#elif MTIM4_COUNTER_DIRECTION ==1
			SET_BIT(MTIM4_CR1,MTIM_DIR);
		#endif
			/* Select channel */
		#if TIM_CH1_EN == 1U
			/* Set Capture/Compare 1 as output */
			CLR_BIT(MTIM4_CCMR1,MTIM_CC1S0);
			CLR_BIT(MTIM4_CCMR1,MTIM_CC1S1);
			/* Enable Output Compare 1 preload */
			SET_BIT(MTIM4_CCMR1,MTIM_OC1PE);
			/* Select the polarity of output compare */
			switch(Copy_uddtOCP)
			{
			case MTIM_HIGH:
				CLR_BIT(MTIM4_CCER,MTIM_CC1P);
				break;
			case MTIM_LOW:
				SET_BIT(MTIM4_CCER,MTIM_CC1P);
			}
			CLR_BIT(MTIM4_CCER,MTIM_CC1NP);
			/* Select Output Compare 1 PWM mode */
		#if MTIM4_PWM_MODE == 1
			CLR_BIT(MTIM4_CCMR1,MTIM_OC1M0);
			SET_BIT(MTIM4_CCMR1,MTIM_OC1M1);
			SET_BIT(MTIM4_CCMR1,MTIM_OC1M2);
		#elif MTIM4_PWM_MODE == 2
			SET_BIT(MTIM4_CCMR1,MTIM_OC1M0);
			SET_BIT(MTIM4_CCMR1,MTIM_OC1M1);
			SET_BIT(MTIM4_CCMR1,MTIM_OC1M2);
		#endif
			/* Enable Capture/Compare 1 output */
			CLR_BIT(MTIM4_CCER,MTIM_CC1E);
			MTIM4_CCR1 = ((Copy_u8DutyCycle*MTIM4_ARR)/100);
		#elif TIM_CH2_EN == 1U
			/* Set Capture/Compare 2 as output */
			CLR_BIT(MTIM4_CCMR1,MTIM_CC2S0);
			CLR_BIT(MTIM4_CCMR1,MTIM_CC2S1);
			/* Enable Output Compare 2 preload */
			SET_BIT(MTIM4_CCMR1,MTIM_OC2PE);
			/* Select the polarity of output compare */
			switch(Copy_uddtOCP)
			{
			case MTIM_HIGH:
				CLR_BIT(MTIM4_CCER,MTIM_CC2P);
				break;
			case MTIM_LOW:
				SET_BIT(MTIM4_CCER,MTIM_CC2P);
			}
			CLR_BIT(MTIM4_CCER,MTIM_CC2NP);
			/* Select Output Compare 2 PWM mode */
		#if MTIM4_PWM_MODE == 1
			CLR_BIT(MTIM4_CCMR1,MTIM_OC2M0);
			SET_BIT(MTIM4_CCMR1,MTIM_OC2M1);
			SET_BIT(MTIM4_CCMR1,MTIM_OC2M2);
		#elif MTIM4_PWM_MODE == 2
			SET_BIT(MTIM4_CCMR1,MTIM_OC2M0);
			SET_BIT(MTIM4_CCMR1,MTIM_OC2M1);
			SET_BIT(MTIM4_CCMR1,MTIM_OC2M2);
		#endif
			/* Enable Capture/Compare 2 output */
			CLR_BIT(MTIM4_CCER,MTIM_CC2E);
			MTIM4_CCR2 = ((Copy_u8DutyCycle*MTIM4_ARR)/100);
		#elif TIM_CH3_EN == 1U
			/* Set Capture/Compare 3 as output */
			CLR_BIT(MTIM4_CCMR1,MTIM_CC3S0);
			CLR_BIT(MTIM4_CCMR1,MTIM_CC3S1);
			/* Enable Output Compare 3 preload */
			SET_BIT(MTIM4_CCMR1,MTIM_OC3PE);
			/* Select the polarity of output compare */
			switch(Copy_uddtOCP)
			{
			case MTIM_HIGH:
				CLR_BIT(MTIM4_CCER,MTIM_CC3P);
				break;
			case MTIM_LOW:
				SET_BIT(MTIM4_CCER,MTIM_CC3P);
			}
			CLR_BIT(MTIM4_CCER,MTIM_CC3NP);
			/* Select Output Compare 3 PWM mode */
		#if MTIM4_PWM_MODE == 1
			CLR_BIT(MTIM4_CCMR1,MTIM_OC3M0);
			SET_BIT(MTIM4_CCMR1,MTIM_OC3M1);
			SET_BIT(MTIM4_CCMR1,MTIM_OC3M2);
		#elif MTIM4_PWM_MODE == 2
			SET_BIT(MTIM4_CCMR1,MTIM_OC3M0);
			SET_BIT(MTIM4_CCMR1,MTIM_OC3M1);
			SET_BIT(MTIM4_CCMR1,MTIM_OC3M2);
		#endif
			/* Enable Capture/Compare 3 output */
			CLR_BIT(MTIM4_CCER,MTIM_CC3E);
			MTIM4_CCR3 = ((Copy_u8DutyCycle*MTIM4_ARR)/100);
		#elif TIM_CH4_EN == 1U
			/* Set Capture/Compare 4 as output */
			CLR_BIT(MTIM4_CCMR1,MTIM_CC4S0);
			CLR_BIT(MTIM4_CCMR1,MTIM_CC4S1);
			/* Enable Output Compare 4 preload */
			SET_BIT(MTIM4_CCMR1,MTIM_OC4PE);
			/* Select the polarity of output compare */
			switch(Copy_uddtOCP)
			{
			case MTIM_HIGH:
				CLR_BIT(MTIM4_CCER,MTIM_CC4P);
				break;
			case MTIM_LOW:
				SET_BIT(MTIM4_CCER,MTIM_CC4P);
			}
			CLR_BIT(MTIM4_CCER,MTIM_CC4NP);
			/* Select Output Compare 4 PWM mode */
		#if MTIM4_PWM_MODE == 1
			CLR_BIT(MTIM4_CCMR1,MTIM_OC4M0);
			SET_BIT(MTIM4_CCMR1,MTIM_OC4M1);
			SET_BIT(MTIM4_CCMR1,MTIM_OC4M2);
		#elif MTIM4_PWM_MODE == 2
			SET_BIT(MTIM4_CCMR1,MTIM_OC4M0);
			SET_BIT(MTIM4_CCMR1,MTIM_OC4M1);
			SET_BIT(MTIM4_CCMR1,MTIM_OC4M2);
		#endif
			/* Enable Capture/Compare 4 output */
			CLR_BIT(MTIM4_CCER,MTIM_CC4E);
			MTIM4_CCR4 = ((Copy_u8DutyCycle*MTIM4_ARR)/100);
		#endif
			/* Initialize all the registers */
			SET_BIT(MTIM4_EGR,MTIM_UG);
			break;
		case TIM5:
			/* Enable Auto-reload preload */
			SET_BIT(MTIM5_CR1,MTIM_ARPE);
			/* Select center aligned mode */
		#if MTIM5_CENTER_MODE_SELECTION == 0U
			CLR_BIT(MTIM5_CR1,MTIM_CMS0);
			CLR_BIT(MTIM5_CR1,MTIM_CMS1);
		#elif MTIM5_CENTER_MODE_SELECTION == 1U
			SET_BIT(MTIM5_CR1,MTIM_CMS0);
			CLR_BIT(MTIM5_CR1,MTIM_CMS1);
		#elif MTIM5_CENTER_MODE_SELECTION == 2U
			CLR_BIT(MTIM5_CR1,MTIM_CMS0);
			SET_BIT(MTIM5_CR1,MTIM_CMS1);
		#elif MTIM5_CENTER_MODE_SELECTION == 3U
			SET_BIT(MTIM5_CR1,MTIM_CMS0);
			SET_BIT(MTIM5_CR1,MTIM_CMS1);
		#endif
			/* Select Counter Direction */
		#if MTIM5_COUNTER_DIRECTION ==0
			CLR_BIT(MTIM5_CR1,MTIM_DIR);
		#elif MTIM5_COUNTER_DIRECTION ==1
			SET_BIT(MTIM5_CR1,MTIM_DIR);
		#endif
			/* Select channel */
		#if TIM_CH1_EN == 1U
			/* Set Capture/Compare 1 as output */
			CLR_BIT(MTIM5_CCMR1,MTIM_CC1S0);
			CLR_BIT(MTIM5_CCMR1,MTIM_CC1S1);
			/* Enable Output Compare 1 preload */
			SET_BIT(MTIM5_CCMR1,MTIM_OC1PE);
			/* Select the polarity of output compare */
			switch(Copy_uddtOCP)
			{
			case MTIM_HIGH:
				CLR_BIT(MTIM5_CCER,MTIM_CC1P);
				break;
			case MTIM_LOW:
				SET_BIT(MTIM5_CCER,MTIM_CC1P);
			}
			CLR_BIT(MTIM5_CCER,MTIM_CC1NP);
			/* Select Output Compare 1 PWM mode */
		#if MTIM5_PWM_MODE == 1
			CLR_BIT(MTIM5_CCMR1,MTIM_OC1M0);
			SET_BIT(MTIM5_CCMR1,MTIM_OC1M1);
			SET_BIT(MTIM5_CCMR1,MTIM_OC1M2);
		#elif MTIM5_PWM_MODE == 2
			SET_BIT(MTIM5_CCMR1,MTIM_OC1M0);
			SET_BIT(MTIM5_CCMR1,MTIM_OC1M1);
			SET_BIT(MTIM5_CCMR1,MTIM_OC1M2);
		#endif
			/* Enable Capture/Compare 1 output */
			CLR_BIT(MTIM5_CCER,MTIM_CC1E);
			MTIM5_CCR1 = ((Copy_u8DutyCycle*MTIM5_ARR)/100);
		#elif TIM_CH2_EN == 1U
			/* Set Capture/Compare 2 as output */
			CLR_BIT(MTIM5_CCMR1,MTIM_CC2S0);
			CLR_BIT(MTIM5_CCMR1,MTIM_CC2S1);
			/* Enable Output Compare 2 preload */
			SET_BIT(MTIM5_CCMR1,MTIM_OC2PE);
			/* Select the polarity of output compare */
			switch(Copy_uddtOCP)
			{
			case MTIM_HIGH:
				CLR_BIT(MTIM5_CCER,MTIM_CC2P);
				break;
			case MTIM_LOW:
				SET_BIT(MTIM5_CCER,MTIM_CC2P);
			}
			CLR_BIT(MTIM5_CCER,MTIM_CC2NP);
			/* Select Output Compare 2 PWM mode */
		#if MTIM5_PWM_MODE == 1
			CLR_BIT(MTIM5_CCMR1,MTIM_OC2M0);
			SET_BIT(MTIM5_CCMR1,MTIM_OC2M1);
			SET_BIT(MTIM5_CCMR1,MTIM_OC2M2);
		#elif MTIM5_PWM_MODE == 2
			SET_BIT(MTIM5_CCMR1,MTIM_OC2M0);
			SET_BIT(MTIM5_CCMR1,MTIM_OC2M1);
			SET_BIT(MTIM5_CCMR1,MTIM_OC2M2);
		#endif
			/* Enable Capture/Compare 2 output */
			CLR_BIT(MTIM5_CCER,MTIM_CC2E);
			MTIM5_CCR2 = ((Copy_u8DutyCycle*MTIM5_ARR)/100);
		#elif TIM_CH3_EN == 1U
			/* Set Capture/Compare 3 as output */
			CLR_BIT(MTIM5_CCMR1,MTIM_CC3S0);
			CLR_BIT(MTIM5_CCMR1,MTIM_CC3S1);
			/* Enable Output Compare 3 preload */
			SET_BIT(MTIM5_CCMR1,MTIM_OC3PE);
			/* Select the polarity of output compare */
			switch(Copy_uddtOCP)
			{
			case MTIM_HIGH:
				CLR_BIT(MTIM5_CCER,MTIM_CC3P);
				break;
			case MTIM_LOW:
				SET_BIT(MTIM5_CCER,MTIM_CC3P);
			}
			CLR_BIT(MTIM5_CCER,MTIM_CC3NP);
			/* Select Output Compare 3 PWM mode */
		#if MTIM5_PWM_MODE == 1
			CLR_BIT(MTIM5_CCMR1,MTIM_OC3M0);
			SET_BIT(MTIM5_CCMR1,MTIM_OC3M1);
			SET_BIT(MTIM5_CCMR1,MTIM_OC3M2);
		#elif MTIM5_PWM_MODE == 2
			SET_BIT(MTIM5_CCMR1,MTIM_OC3M0);
			SET_BIT(MTIM5_CCMR1,MTIM_OC3M1);
			SET_BIT(MTIM5_CCMR1,MTIM_OC3M2);
		#endif
			/* Enable Capture/Compare 3 output */
			CLR_BIT(MTIM5_CCER,MTIM_CC3E);
			MTIM5_CCR3 = ((Copy_u8DutyCycle*MTIM5_ARR)/100);
		#elif TIM_CH4_EN == 1U
			/* Set Capture/Compare 4 as output */
			CLR_BIT(MTIM5_CCMR1,MTIM_CC4S0);
			CLR_BIT(MTIM5_CCMR1,MTIM_CC4S1);
			/* Enable Output Compare 4 preload */
			SET_BIT(MTIM5_CCMR1,MTIM_OC4PE);
			/* Select the polarity of output compare */
			switch(Copy_uddtOCP)
			{
			case MTIM_HIGH:
				CLR_BIT(MTIM5_CCER,MTIM_CC4P);
				break;
			case MTIM_LOW:
				SET_BIT(MTIM5_CCER,MTIM_CC4P);
			}
			CLR_BIT(MTIM5_CCER,MTIM_CC4NP);
			/* Select Output Compare 4 PWM mode */
		#if MTIM5_PWM_MODE == 1
			CLR_BIT(MTIM5_CCMR1,MTIM_OC4M0);
			SET_BIT(MTIM5_CCMR1,MTIM_OC4M1);
			SET_BIT(MTIM5_CCMR1,MTIM_OC4M2);
		#elif MTIM5_PWM_MODE == 2
			SET_BIT(MTIM5_CCMR1,MTIM_OC4M0);
			SET_BIT(MTIM5_CCMR1,MTIM_OC4M1);
			SET_BIT(MTIM5_CCMR1,MTIM_OC4M2);
		#endif
			/* Enable Capture/Compare 4 output */
			CLR_BIT(MTIM5_CCER,MTIM_CC4E);
			MTIM4_CCR5 = ((Copy_u8DutyCycle*MTIM5_ARR)/100);
		#endif
			/* Initialize all the registers */
			SET_BIT(MTIM5_EGR,MTIM_UG);
			break;
		}
	}
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}

/*----------MTIM_u8PWMStop Implementation----------*/
u8 MTIM_u8PWMStop(TimId_t Copy_uddtTimerId)
{
	u8 Local_u8ErrorState = 0;
	if(Copy_uddtTimerId <= TIM5)
	{
		switch(Copy_uddtTimerId)
		{
		case TIM2:
			/* Select channel */
		#if TIM_CH1_EN == 1U
			/* Disable PWM Mode */
			CLR_BIT(MTIM2_CCMR1,MTIM_OC1M0);
			CLR_BIT(MTIM2_CCMR1,MTIM_OC1M1);
			CLR_BIT(MTIM2_CCMR1,MTIM_OC1M2);
		#elif TIM_CH2_EN == 1U
			/* Disable PWM Mode */
			CLR_BIT(MTIM2_CCMR1,MTIM_OC2M0);
			CLR_BIT(MTIM2_CCMR1,MTIM_OC2M1);
			CLR_BIT(MTIM2_CCMR1,MTIM_OC2M2);
		#elif TIM_CH3_EN == 1U
			/* Disable PWM Mode */
			CLR_BIT(MTIM2_CCMR1,MTIM_OC3M0);
			CLR_BIT(MTIM2_CCMR1,MTIM_OC3M1);
			CLR_BIT(MTIM2_CCMR1,MTIM_OC3M2);
		#elif TIM_CH4_EN == 1U
			/* Disable PWM Mode */
			CLR_BIT(MTIM2_CCMR1,MTIM_OC4M0);
			CLR_BIT(MTIM2_CCMR1,MTIM_OC4M1);
			CLR_BIT(MTIM2_CCMR1,MTIM_OC4M2);
		#endif
			break;
		case TIM3:
			/* Select channel */
		#if TIM_CH1_EN == 1U
			/* Disable PWM Mode */
			CLR_BIT(MTIM3_CCMR1,MTIM_OC1M0);
			CLR_BIT(MTIM3_CCMR1,MTIM_OC1M1);
			CLR_BIT(MTIM3_CCMR1,MTIM_OC1M2);
		#elif TIM_CH2_EN == 1U
			/* Disable PWM Mode */
			CLR_BIT(MTIM3_CCMR1,MTIM_OC2M0);
			CLR_BIT(MTIM3_CCMR1,MTIM_OC2M1);
			CLR_BIT(MTIM3_CCMR1,MTIM_OC2M2);
		#elif TIM_CH3_EN == 1U
			/* Disable PWM Mode */
			CLR_BIT(MTIM3_CCMR1,MTIM_OC3M0);
			CLR_BIT(MTIM3_CCMR1,MTIM_OC3M1);
			CLR_BIT(MTIM3_CCMR1,MTIM_OC3M2);
		#elif TIM_CH4_EN == 1U
			/* Disable PWM Mode */
			CLR_BIT(MTIM3_CCMR1,MTIM_OC4M0);
			CLR_BIT(MTIM3_CCMR1,MTIM_OC4M1);
			CLR_BIT(MTIM3_CCMR1,MTIM_OC4M2);
		#endif
			break;
		case TIM4:
			/* Select channel */
		#if TIM_CH1_EN == 1U
			/* Disable PWM Mode */
			CLR_BIT(MTIM4_CCMR1,MTIM_OC1M0);
			CLR_BIT(MTIM4_CCMR1,MTIM_OC1M1);
			CLR_BIT(MTIM4_CCMR1,MTIM_OC1M2);
		#elif TIM_CH2_EN == 1U
			/* Disable PWM Mode */
			CLR_BIT(MTIM4_CCMR1,MTIM_OC2M0);
			CLR_BIT(MTIM4_CCMR1,MTIM_OC2M1);
			CLR_BIT(MTIM4_CCMR1,MTIM_OC2M2);
		#elif TIM_CH3_EN == 1U
			/* Disable PWM Mode */
			CLR_BIT(MTIM4_CCMR1,MTIM_OC3M0);
			CLR_BIT(MTIM4_CCMR1,MTIM_OC3M1);
			CLR_BIT(MTIM4_CCMR1,MTIM_OC3M2);
		#elif TIM_CH4_EN == 1U
			/* Disable PWM Mode */
			CLR_BIT(MTIM4_CCMR1,MTIM_OC4M0);
			CLR_BIT(MTIM4_CCMR1,MTIM_OC4M1);
			CLR_BIT(MTIM4_CCMR1,MTIM_OC4M2);
		#endif
			break;
		case TIM5:
			/* Select channel */
		#if TIM_CH1_EN == 1U
			/* Disable PWM Mode */
			CLR_BIT(MTIM5_CCMR1,MTIM_OC1M0);
			CLR_BIT(MTIM5_CCMR1,MTIM_OC1M1);
			CLR_BIT(MTIM5_CCMR1,MTIM_OC1M2);
		#elif TIM_CH2_EN == 1U
			/* Disable PWM Mode */
			CLR_BIT(MTIM5_CCMR1,MTIM_OC2M0);
			CLR_BIT(MTIM5_CCMR1,MTIM_OC2M1);
			CLR_BIT(MTIM5_CCMR1,MTIM_OC2M2);
		#elif TIM_CH3_EN == 1U
			/* Disable PWM Mode */
			CLR_BIT(MTIM5_CCMR1,MTIM_OC3M0);
			CLR_BIT(MTIM5_CCMR1,MTIM_OC3M1);
			CLR_BIT(MTIM5_CCMR1,MTIM_OC3M2);
		#elif TIM_CH4_EN == 1U
			/* Disable PWM Mode */
			CLR_BIT(MTIM5_CCMR1,MTIM_OC4M0);
			CLR_BIT(MTIM5_CCMR1,MTIM_OC4M1);
			CLR_BIT(MTIM5_CCMR1,MTIM_OC4M2);
		#endif
			break;
		}
	}
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}

/*----------MTIM_u8TimStop Implementation----------*/
u8 MTIM_u8TimStop(TimId_t Copy_uddtTimerId)
{
	u8 Local_u8ErrorState = 0;
	if(Copy_uddtTimerId <= TIM5)
	{
		switch(Copy_uddtTimerId)
		{
		case TIM2:
			/* Disable timer counter */
			CLR_BIT(MTIM2_CR1,MTIM_CEN);
			break;
		case TIM3:
			/* Disable timer counter */
			CLR_BIT(MTIM3_CR1,MTIM_CEN);
			break;
		case TIM4:
			/* Disable timer counter */
			CLR_BIT(MTIM4_CR1,MTIM_CEN);
			break;
		case TIM5:
			/* Disable timer counter */
			CLR_BIT(MTIM5_CR1,MTIM_CEN);
			break;
		}
	}
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}

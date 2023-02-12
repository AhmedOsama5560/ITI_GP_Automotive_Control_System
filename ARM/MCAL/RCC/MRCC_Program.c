/*
 *  Created on  : Jan 25, 2023
 *  Author      : Reham Mohamed
 *  Version	    : V0.0.0
 *  Description : MRCC_Program.c  ->  Function Implementation
 *  Module Features :
 *  					01- MRCC_voidInitClock(void)
 *  					02- MRCC_voidEnablePeripheralClock()
 *  					03- MRCC_voidDisablePeripheralClock()
 *  					04- MRCC_voidEnableSecuritySystem()
 *  					05- MRCC_voidDisableSecuritySystem()
 */

/*******************************************************************/
/*		              Standard Types LIB                           */
/*******************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"

/*******************************************************************/
/*		              Peripheral Files                             */
/*******************************************************************/

#include "MRCC_Private.h"
#include "MRCC_Interface.h"
#include "MRCC_Config.h"

/*******************************************************************/
/*		              Function Implementation                      */
/*******************************************************************/
void MRCC_voidInitClock(void)
{
	/******* HSI *******/
#if MRCC_CLKSRC == HSI
	/*step 1 : EN HSI*/
	SET_BIT(RCC_CR , 0U);
	/*step 2 : wait until HSI ready*/
	while(GET_BIT(RCC_CR , 1U) == 0);
	/*step 3 : switch to HSI*/
	CLR_BIT(RCC_CFGR , 0U);
	CLR_BIT(RCC_CFGR , 1U);
	/******* HSE *******/
#elif MRCC_CLKSRC == HSE
	/*step 1 : EN HSE*/
	SET_BIT(RCC_CR , 16U);
	/*step 2 : wait until HSE ready*/
	while(GET_BIT(RCC_CR , 17U) == 0);
	/****** HSE RC SOURCE ******/
#if MRCC_HSESRC == HSE_RC
	/*step 3 : EN bypass*/
	SET_BIT(RCC_CR , 18U);
	/*step 4 : switch to HSE*/
	SET_BIT(RCC_CFGR , 0U);
	CLR_BIT(RCC_CFGR , 1U);
#elif MRCC_HSESRC == HSE_CRYSTAL
	/*step 3 : Disable bypass*/
	CLR_BIT(RCC_CR , 18U);
	/*step 4 : switch to HSE*/
	SET_BIT(RCC_CFGR , 0U);
	CLR_BIT(RCC_CFGR , 1U);
#else
#warning "invalid option....."
#endif

	/******* PLL *******/
#elif MRCC_CLKSRC == PLL
	/******* PLL -> HSE *******/
#if MRCC_PLLSRC == PLL_HSE
	/*step 1 : EN HSE*/
	SET_BIT(RCC_CR , 16U);
	/*step 2 : wait until HSE ready*/
	while(GET_BIT(RCC_CR , 17U) == 0);
	/*step 3 : EN PLL*/
	SET_BIT(RCC_CR , 24U);
	/*step 4 : wait until PLL ready*/
	while(GET_BIT(RCC_CR , 25U) == 0);
	/*step 5 : PLL from HSE*/
	SET_BIT(RCC_PLLCFGR , 22U);
	/*step 6 : switch to PLL*/
	CLR_BIT(RCC_CFGR , 0U);
	SET_BIT(RCC_CFGR , 1U);

	/******* PLL -> HSI *******/
#elif MRCC_PLLSRC == PLL_HSI
	/*step 1 : EN HSI*/
	SET_BIT(RCC_CR , 0U);
	/*step 2 : wait until HSI ready*/
	while(GET_BIT(RCC_CR , 1U) == 0);
	/*step 3 : EN PLL*/
	SET_BIT(RCC_CR , 24U);
	/*step 4 : wait until PLL ready*/
	while(GET_BIT(RCC_CR , 25U) == 0);
	/*step 5 : PLL from HSI*/
	CLR_BIT(RCC_PLLCFGR , 22U);
	/*step 6 : switch to PLL*/
	CLR_BIT(RCC_CFGR , 0U);
	SET_BIT(RCC_CFGR , 1U);
#else
#warning "Invalid option....."
#endif

#else
#warning "Invalid option....."
#endif

}
void MRCC_voidEnablePeripheralClock(BusName_t Copy_uddtBusName , u8 Copy_u8PerNum)
{
	switch(Copy_uddtBusName)
	{
		case MRCC_AHB1 : SET_BIT(RCC_AHB1ENR, Copy_u8PerNum);	break;
		case MRCC_AHB2 : SET_BIT(RCC_AHB2ENR, Copy_u8PerNum);	break;
		case MRCC_APB1 : SET_BIT(RCC_APB1ENR, Copy_u8PerNum);	break;
		case MRCC_APB2 : SET_BIT(RCC_APB2ENR, Copy_u8PerNum);	break;
		default		   : /*Do Nothing*/							break;
	}
}
void MRCC_voidDisablePeripheralClock(BusName_t Copy_uddtBusName , u8 Copy_u8PerNum)
{
	switch(Copy_uddtBusName)
	{
		case MRCC_AHB1 : CLR_BIT(RCC_AHB1ENR, Copy_u8PerNum);	break;
		case MRCC_AHB2 : CLR_BIT(RCC_AHB2ENR, Copy_u8PerNum);	break;
		case MRCC_APB1 : CLR_BIT(RCC_APB1ENR, Copy_u8PerNum);	break;
		case MRCC_APB2 : CLR_BIT(RCC_APB2ENR, Copy_u8PerNum);	break;
		default		   : /*Do Nothing*/     					break;
	}
}
void MRCC_voidEnableSecuritySystem(void)
{
	SET_BIT(RCC_CR , 19);
}
void MRCC_voidDisableSecuritySystem(void)
{
	CLR_BIT(RCC_CR , 19);
}



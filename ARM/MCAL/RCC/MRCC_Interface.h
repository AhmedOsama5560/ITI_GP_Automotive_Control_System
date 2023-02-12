/*
 *  Created on  	: Jan 25, 2023
 *  Author      	: Reham Mohamed
 *  Version	    	: V0.0.0
 *  Description     : MRCC_Interface.h  ->  Function Prototypes
 *  Module Features :
 *  					01- MRCC_voidInitClock(void)
 *  					02- MRCC_voidEnablePeripheralClock()
 *  					03- MRCC_voidDisablePeripheralClock()
 *  					04- MRCC_voidEnableSecuritySystem()
 *  					05- MRCC_voidDisableSecuritySystem()
 */

/*******************************************************************/
/*		         what i sell to Customer                    	   */
/*						- the Architect Give The API          	   */
/*								- The Name Of Function   		   */
/*								- what is the input        		   */
/*								- what is the output      		   */
/*								- Macro				       		   */
/*******************************************************************/


/*******************************************************************/
/*		              Header Guard Of The File                     */
/*******************************************************************/

#ifndef MRCC_INTERFACE_H_
#define MRCC_INTERFACE_H_

/*************************** BUS_NAME ******************************/
//#define MRCC_AHB1			0
//#define MRCC_AHB2			1
//#define MRCC_APB1			2
//#define MRCC_APB2			3

typedef enum
{
	MRCC_AHB1 = 0,
	MRCC_AHB2,
	MRCC_APB1,
	MRCC_APB2
}BusName_t;

/************************* AHB1_Prescaller *************************/

typedef enum
{
	MRCC_AHB_PRE1 = 7 ,
	MRCC_AHB_PRE2     ,
	MRCC_AHB_PRE4     ,
	MRCC_AHB_PRE8     ,
	MRCC_AHB_PRE16    ,
	MRCC_AHB_PRE32    ,
	MRCC_AHB_PRE64    ,
	MRCC_AHB_PRE128   ,
	MRCC_AHB_PRE256   ,
	MRCC_AHB_PRE512
}AHB1_PreScaller_t;

/************************* APB1_Prescaller *************************/

typedef enum
{
	MRCC_APB1_PRE1 = 3 ,
	MRCC_APB1_PRE2     ,
	MRCC_APB1_PRE4     ,
	MRCC_APB1_PRE8     ,
	MRCC_APB1_PRE16
}APB1_PreScaller_t;


/************************* APB2_Prescaller *************************/

typedef enum
{
	MRCC_APB2_PRE1 = 3 ,
	MRCC_APB2_PRE2     ,
	MRCC_APB2_PRE4     ,
	MRCC_APB2_PRE8     ,
	MRCC_APB2_PRE16
}APB2_PreScaller_t;


/*************************** CLKSRS_NAME ***************************/

#define HSI				0U
#define HSE				1U
#define PLL				2U

/*************************** HSESRS_NAME ***************************/

#define HSE_RC			0U
#define HSE_CRYSTAL		1U


/*************************** PLLSRS_NAME ***************************/

#define PLL_HSI			0U
#define PLL_HSE			1U


/************ RCC AHB1 Peripheral Clock Enable Register ************/
#define MRCC_GPIOA_EN			0U
#define MRCC_GPIOB_EN			1U
#define MRCC_GPIOC_EN			2U
#define MRCC_GPIOD_EN			3U
#define MRCC_GPIOE_EN			4U
#define MRCC_GPIOH_EN			7U
#define MRCC_CRC_EN				12U
#define MRCC_DMA1_EN			21U
#define MRCC_DMA2_EN			22U

/************ RCC AHB2 Peripheral Clock Enable Register ************/
#define MRCC_OTGFS_EN			7U

/************ RCC APB1 Peripheral Clock Enable Register ************/
#define MRCC_TIM2_EN			0U
#define MRCC_TIM3_EN			1U
#define MRCC_TIM4_EN			2U
#define MRCC_TIM5_EN			3U
#define MRCC_WWDG_EN			11U
#define MRCC_SPI2_EN			14U
#define MRCC_SPI3_EN			15U
#define MRCC_USART2_EN			17U
#define MRCC_I2C1_EN			21U
#define MRCC_I2C2_EN			22U
#define MRCC_I2C3_EN			23U
#define MRCC_PWR_EN				28U

/************ RCC APB2 Peripheral Clock Enable Register ************/
#define MRCC_TIM1_EN			0U
#define MRCC_USART1_EN			4U
#define MRCC_USART6_EN			5U
#define MRCC_ADC1_EN			8U
#define MRCC_SDIO_EN			11U
#define MRCC_SPI1_EN			12U
#define MRCC_SPI4_EN			13U
#define MRCC_SYSCFG_EN			14U
#define MRCC_TIM9_EN			16U
#define MRCC_TIM10_EN			17U
#define MRCC_TIM11_EN			18U


/*******************************************************************/
/*		              Function Prototypes                          */
/*******************************************************************/

/*******************************************************************/
/*		          01- MRCC_voidInitClock(void)		               */
/*-----------------------------------------------------------------*/
/*	@func  : Clock	Initialization								   */
/*	@in    : void												   */
/*	@out   : void												   */
/*******************************************************************/
void MRCC_voidInitClock(void);

/*******************************************************************/
/*		        02- MRCC_voidEnablePeripheralClock()               */
/*-----------------------------------------------------------------*/
/*	@func  : Enable Peripheral Clock							   */
/*	@in[1] : Copy_uddtBusName :									   */
/*							- MRCC_AHB1                            */
/*							- MRCC_AHB2                            */
/*							- MRCC_APB1                            */
/*							- MRCC_APB2                            */
/*	@in[2] : Copy_u8PerNum : 									   */
/* 						- the order of peripheral on selected Reg  */
/*	@out   : void												   */
/*******************************************************************/
void MRCC_voidEnablePeripheralClock(BusName_t Copy_uddtBusName , u8 Copy_u8PerNum);

/*******************************************************************/
/*		        03- MRCC_voidDisablePeripheralClock()               */
/*-----------------------------------------------------------------*/
/*	@func  : Disable Peripheral Clock							   */
/*	@in[1] : Copy_uddtBusName :									   */
/*							- MRCC_AHB1                            */
/*							- MRCC_AHB2                            */
/*							- MRCC_APB1                            */
/*							- MRCC_APB2                            */
/*	@in[2] : Copy_u8PerNum : 									   */
/* 						- the order of peripheral on selected Reg  */
/*	@out   : void												   */
/*******************************************************************/
void MRCC_voidDisablePeripheralClock(BusName_t Copy_uddtBusName , u8 Copy_u8PerNum);

/*******************************************************************/
/*		        04- MRCC_voidEnableSecuritySystem()                */
/*-----------------------------------------------------------------*/
/*	@func  : Enable Clock Security System						   */
/*	@in    : void												   */
/*	@out   : void												   */
/*******************************************************************/
void MRCC_voidEnableSecuritySystem(void);

/*******************************************************************/
/*		        05- MRCC_voidDisableSecuritySystem()               */
/*-----------------------------------------------------------------*/
/*	@func  : Disable Clock Security System						   */
/*	@in    : void												   */
/*	@out   : void												   */
/*******************************************************************/
void MRCC_voidDisableSecuritySystem(void);

#endif /* MRCC_INTERFACE_H_ */
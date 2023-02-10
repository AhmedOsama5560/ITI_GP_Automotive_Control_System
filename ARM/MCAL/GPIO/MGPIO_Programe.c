/*
 * MGPIO_Programe.c
 *
 *  Created on: 7 -2 -2023
 *      Author: kholoud
* Module Features    :                                             */
/*           01- MGPIO_vSetPinMode                                  */
/*           02- MGPIO_vSetPinOutPutTypeS                           */
/*           03- MGPIO_vSetPinOutSpeed                              */
/*           04- MGPIO_vSetPullType                                 */
/*           05- MGPIO_u8ReadData                                   */
/*           06- MGPIO_vWriteData                                   */
/*           07- MGPIO_vSetPinAltFn                                 */
/********************************************************************/


/********************************************************************/
/*                    Standard Types LIB                            */
/********************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"

/********************************************************************/
/*                         Peripheral Files                         */
/********************************************************************/
#include "MGPIO_Interface.h"
#include "MGPIO_Private.h"
#include "MGPIO_Config.h"

/********************************************************************/
/*                      Function Implementation                     */
/********************************************************************/
/*====================================================   Start_FUNCTION   ====================================================*/
/*	Function Set The Mode Of Pin Mode Take 2Bits
*			1- _MODE_INPUT
*			2- _MODE_OUTPUT
*			3- _MODE_ALTF
*			4- _MODE_ANALOG
*/

void MGPIO_vSetPinMode(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8Mode  ){
	switch(Copy_u8PortName)
		{

			case GPIOA: MGPIOA -> MODER |= (u32) (Copy_u8Mode << (2U *Copy_u8PinNum) );  break;
			case GPIOB: MGPIOB -> MODER |= (u32) (Copy_u8Mode << (2U *Copy_u8PinNum) );  break;
			case GPIOC: MGPIOC -> MODER |= (u32) (Copy_u8Mode << (2U *Copy_u8PinNum) );  break;
			default:    									       					     break;
		}
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
/*	Function Set The Type Of OutPut (OpenDrain = 0 , PushPull = 1) :
*								                         - _OUTPUT_TYPE_PUSH_PULL
*								                         - _OUTPUT_TYPE_OPEN_DRAIN
*/
void MGPIO_vSetPinOutPutType(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8OutPutType  ){

	switch(Copy_u8PortName)
	{

		case GPIOA: MGPIOA -> OTYPER |= (u32) (Copy_u8OutPutType << (Copy_u8PinNum) );  break;
		case GPIOB: MGPIOB -> OTYPER |= (u32) (Copy_u8OutPutType << (Copy_u8PinNum) );  break;
		case GPIOC: MGPIOC -> OTYPER |= (u32) (Copy_u8OutPutType << (Copy_u8PinNum) );  break;
		default:    														            break;
	}
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
/* Function Set The Speed (LOW , Meduim , High ,VeryHaigh):
*					                                 - _OUTPUT_SPEED_LOW
*					                                 - _OUTPUT_SPEED_MEDUIM
*					                                 - _OUTPUT_SPEED_HIGH
*					                                 - _OUTPUT_SPEED_VERY_HIGH
*/
void MGPIO_vSetPinOutSpeed(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8OutSpeed ){
	switch(Copy_u8PortName)
		{

			case GPIOA: MGPIOA -> OSPEEDR |= (u32) (Copy_u8OutSpeed << (2U* Copy_u8PinNum) );  break;
			case GPIOB: MGPIOB -> OSPEEDR |= (u32) (Copy_u8OutSpeed << (2U* Copy_u8PinNum) );  break;
			case GPIOC: MGPIOC -> OSPEEDR |= (u32) (Copy_u8OutSpeed << (2U* Copy_u8PinNum) );  break;
			default:    													     	           break;
		}
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
/*	Function Set The PULL :
*					      - _PULL_OFF
*					      - _PULL_UP
*					      - _PULL_DOWN
*/
void MGPIO_vSetPullType(u8 Copy_8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8PullType ){
	switch(Copy_8PortName)
			{

				case GPIOA: MGPIOA -> PUPDR |= (u32) ( Copy_u8PullType << (2U* Copy_u8PinNum) );  break;
				case GPIOB: MGPIOB -> PUPDR |= (u32) ( Copy_u8PullType << (2U* Copy_u8PinNum) );  break;
				case GPIOC: MGPIOC -> PUPDR |= (u32) ( Copy_u8PullType << (2U* Copy_u8PinNum) );  break;
				default:    													     	          break;
			}
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
/*
 *Function To Read Data From IDR
 */
u8 MGPIO_u8ReadData(u8 copy_u8PORT ,u8 copy_u8PIN){
	u8 local_u8var=0;
	switch(copy_u8PORT){
			case GPIOA: local_u8var = GET_BIT(MGPIOA -> IDR ,copy_u8PIN);                  break;
			case GPIOB: local_u8var = GET_BIT(MGPIOB -> IDR ,copy_u8PIN);                  break;
			case GPIOC: local_u8var = GET_BIT(MGPIOC -> IDR ,copy_u8PIN);                  break;
			default:    													     	       break;
	}

	return local_u8var;
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
/*
* Function To Write Data At ODR	Value :
*									  - _LOW
*									  - _HIGH
*/
void MGPIO_vWriteData(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8State){

	if(Copy_u8State == HIGH)
	{
		switch(Copy_u8PortName)
	{

		case GPIOA: SET_BIT (MGPIOA -> ODR , Copy_u8PinNum ); break ;
		case GPIOB: SET_BIT (MGPIOB -> ODR , Copy_u8PinNum ); break ;
		case GPIOC: SET_BIT (MGPIOC -> ODR , Copy_u8PinNum ); break ;
		default:    								     	 break ;
	}
	}
	else
	{
	switch(Copy_u8PortName)
	{

		case GPIOA: CLR_BIT (MGPIOA -> ODR , Copy_u8PinNum ); break ;
		case GPIOB: CLR_BIT (MGPIOB -> ODR , Copy_u8PinNum ); break ;
		case GPIOC: CLR_BIT (MGPIOC -> ODR , Copy_u8PinNum ); break ;
		default:    								      	 break ;


	}
	}

}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void MGPIO_vSetPinAltFn( u8 Copy_u8PortNum ,u8 Copy_u8PinNum, u8 Copy_u8ALF )
{
		if (Copy_u8PinNum <= 7U){
			switch(Copy_u8PortNum)
			{

				case GPIOA: MGPIOA -> AFRL |= (u32) (Copy_u8ALF << (4U * Copy_u8PinNum) );  break;
				case GPIOB: MGPIOB -> AFRL |= (u32) (Copy_u8ALF << (4U * Copy_u8PinNum) );  break;
				case GPIOC: MGPIOC -> AFRL |= (u32) (Copy_u8ALF << (4U * Copy_u8PinNum) );  break;
				default:    														        break;
			}
		}
		else
			{
				switch(Copy_u8PortNum)
			{

				case GPIOA: MGPIOA -> AFRH |= (u32) (Copy_u8ALF << (4U * Copy_u8PinNum) );  break;
				case GPIOB: MGPIOB -> AFRH |= (u32) (Copy_u8ALF << (4U * Copy_u8PinNum) );  break;
				case GPIOC: MGPIOC -> AFRH |= (u32) (Copy_u8ALF << (4U * Copy_u8PinNum) );  break;
				default:    														       break;
			}
			}
}
/*====================================================   END_ FUNCTION   ====================================================*/

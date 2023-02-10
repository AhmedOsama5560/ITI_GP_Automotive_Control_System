/****************************************************************
 *  Name        : MGPIO_Interface.h
 *  Description : Function Prototypes
 *  Author      : kholoud khaled
 *  Created on  : 7 - 2 - 2023
 *  Version     : V0.0
 *  Module Features   :                                             */
/*           01- MGPIO_vSetPinMode                                  */
/*           02- MGPIO_vSetPinOutPutTypeS                           */
/*           03- MGPIO_vSetPinOutSpeed                              */
/*           04- MGPIO_vSetPullType                                 */
/*           05- MGPIO_u8ReadData                                   */
/*           06- MGPIO_vWriteData                                   */
/*           07- MGPIO_vSetPinAltFn                                 */
/********************************************************************/

/********************************************************************/
/*    what i sell to Customer                                       */
/*              - the Architect Give The API                        */
/*                             - The Name Of Function               */
/*                             - what is the input                  */
/*                             - what is the output                 */
/*                             - MCRO                               */
/**************************************************************/
/*                   Header Guard Of File                     */
/**************************************************************/


#ifndef MGPIO_INTERFACE_H_
#define MGPIO_INTERFACE_H_




/*======== ENUM For PORT  ========*/
typedef enum
{
	GPIOA = 0U,
	GPIOB     ,
	GPIOC     ,

}port_t;



/*======== ENUM For PINS  ========*/
typedef enum
{
	_GPIO_PIN_0     =0U,
	_GPIO_PIN_1        ,
	_GPIO_PIN_2        ,
	_GPIO_PIN_3        ,
	_GPIO_PIN_4        ,
	_GPIO_PIN_5        ,
	_GPIO_PIN_6        ,
	_GPIO_PIN_7        ,
	_GPIO_PIN_8        ,
	_GPIO_PIN_9        ,
	_GPIO_PIN_10       ,
	_GPIO_PIN_11       ,
	_GPIO_PIN_12       ,
	_GPIO_PIN_13       ,
	_GPIO_PIN_14       ,
	_GPIO_PIN_15       ,

}PINS_t;

/*======== ENUM For MODE  ========*/
typedef enum
{
	MODE_INPUT  = 0U,
	MODE_OUTPUT     ,
	MODE_ALTF       ,
	MODE_ANALOG     ,
}MODER_t;
/*======== ENUM For Output Type  ========*/
typedef enum
{
	PUSH_PULL  = 0U,
	OPEN_DRAIN     ,
}OTYPER_t;
/*======== ENUM For Output Speed  ========*/
typedef enum
{
	LOW_SPEED         = 0U,
	MEDIUM_SPEED          ,
	HIGH_SPEED            ,
	VERY_HIGH_SPEED       ,
}OSPEEDR_t;
/*======== Macros Of PULL ========*/

#define PULL_OFF       0U
#define PULL_UP        1U
#define PULL_DOWN      2U

/*======== Macros Write Data  ========*/
#define LOW	 0U
#define HIGH    1U

/*======== Macros ALTF  ========*/
#define ALTF_0      0U
#define ALTF_1      1U
#define ALTF_2      2U
#define ALTF_3      3U
#define ALTF_4      4U
#define ALTF_5      5U
#define ALTF_6      6U
#define ALTF_7      7U
#define ALTF_8      8U
#define ALTF_9      9U
#define ALTF_10     10U
#define ALTF_11     11U
#define ALTF_12     12U
#define ALTF_13     13U
#define ALTF_14     14U
#define ALTF_15     15U

/*==========LOCKED PIN =============*/
#define LOCKED_PIN 16U

/*===========================     Function Prototypes     ===========================*/

/*===============   1-Function Set The Mode Of Pin	 ===============*/
void MGPIO_vSetPinMode(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8Mode  );
/*===============   2-Function Set The Type Of OutPut (OpenDrain = 0 , PushPull = 1)  ===============*/
void MGPIO_vSetPinOutPutType(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8OutPutType  );
/*===============	3-Function Set The Speed Of output pin  (LOW , Meduim , High ,VeryHaigh	===============*/
void MGPIO_vSetPinOutSpeed(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8OutSpeed );
/*===============   4-Function Set The PULL ( Almost Input ) ( OFF , UP , DOWN )  ===============*/
void MGPIO_vSetPullType(u8 Copy_8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8PullType );
/*===============   5-Function To Read Data From IDR  ===============*/
u8 MGPIO_u8ReadData(u8 copy_u8PORT ,u8 copy_u8PIN);
/*===============   6-Function To Write Data At ODR	Value = HIGH , LOW  ===============*/
void MGPIO_vWriteData(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8State);
/*===============   7-Function To Set ALTF   ===============*/
void MGPIO_vSetPinAltFn( u8 Copy_u8PortNum ,u8 Copy_u8PinNum, u8 Copy_u8ALF );
/*==========================================================================================================*/


#endif /* MGPIO_INTERFACE_H_ */

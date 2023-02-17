/*
 *  Created on	: Feb 9, 2023
 *  Author		: Reham Mohamed
 *  Version		: V0.0.0
 *  Description : HLED_Interface.h  ->  Function Prototype
 *  Module Features   :
 *           01- void LED_voidINT()
 *			 02- void LED_voidTurnOn()
 *			 03- void LED_voidTurnOff()
 *			 04- void LED_voidToggle()
 *			 05- void LED_voidFlash_Min()
 */

/********************************************************************/
/*    what i sell to Customer                                       */
/*              - the Architect Give The API                        */
/*                             - The Name Of Function               */
/*                             - what is the input                  */
/*                             - what is the output                 */
/*                             - MCRO                               */

/********************************************************************/
/*                     Header Guard Of File                         */
/********************************************************************/


#ifndef HLED_INTERFACE_H_
#define HLED_INTERFACE_H_


/* Port_Id options : GPIOA
			 	 	 GPIOB
             	 	 GPIOC
*/

/* Pin_Id OPTION  : _GPIO_PIN_0 -> _GPIO_PIN_15 */


/****************** Function : LED Initialization ******************/
void LED_voidINT(port_t Copy_u8PortId ,PINS_t Copy_u8PinId);

/********************* Function : LED Turn ON **********************/
void LED_voidTurnOn(port_t Copy_u8PortId ,PINS_t Copy_u8PinId);

/********************* Function : LED Turn OFF *********************/
void LED_voidTurnOff(port_t Copy_u8PortId ,PINS_t Copy_u8PinId);

/********************** Function : LED Toggle **********************/
void LED_voidToggle(port_t Copy_u8PortId ,PINS_t Copy_u8PinId);

/*************** Function : LED Flash for '1' minute ***************/
void LED_voidFlash_Min(port_t Copy_u8PortId ,PINS_t Copy_u8PinId);

#endif /* HLED_INTERFACE_H_ */

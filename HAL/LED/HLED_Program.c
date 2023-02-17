/*
 *  Created on	: Feb 9, 2023
 *  Author		: Reham Mohamed
 *  Version		: V0.0.0
 *  Description : HLED_Interface.h  ->  Function Implementation
 *  Module Features   :
 *           01- void LED_voidINT()
 *			 02- void LED_voidTurnOn()
 *			 03- void LED_voidTurnOff()
 *			 04- void LED_voidToggle()
 *			 05- void LED_voidFlash_Min()
 */

/********************************************************************/
/*                    Standard Types LIB                            */
/********************************************************************/
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"

/********************************************************************/
/*                       	 MCAL Files 	                        */
/********************************************************************/
#include "MGPIO_Interface.h"
#include "MSTK_Interface.h"

/********************************************************************/
/*                       	  HAL Files 	                        */
/********************************************************************/
#include "HLED_Interface.h"

void LED_voidINT(port_t Copy_u8PortId ,PINS_t Copy_u8PinId)
{
	MGPIO_vSetPinMode(Copy_u8PortId ,Copy_u8PinId , MODE_OUTPUT);
	MGPIO_vSetPinOutPutType(Copy_u8PortId , Copy_u8PinId , PUSH_PULL);
	MGPIO_vSetPullType(Copy_u8PortId , Copy_u8PinId ,PULL_OFF );
}

void LED_voidTurnOn(port_t Copy_u8PortId ,PINS_t Copy_u8PinId)
{
	MGPIO_vWriteData(Copy_u8PortId , Copy_u8PinId , HIGH);
}

void LED_voidTurnOff(port_t Copy_u8PortId ,PINS_t Copy_u8PinId)
{
	MGPIO_vWriteData(Copy_u8PortId , Copy_u8PinId , LOW);
}

void LED_voidToggle(port_t Copy_u8PortId ,PINS_t Copy_u8PinId)
{
	MGPIO_vWriteData(Copy_u8PortId , Copy_u8PinId , HIGH);
	_delay_ms(1000);
	MGPIO_vWriteData(Copy_u8PortId , Copy_u8PinId , LOW);
	_delay_ms(1000);
}

void LED_voidFlash_Min(port_t Copy_u8PortId ,PINS_t Copy_u8PinId)
{
	u8 i;
	for(i=0; i<30; i++)
	{
		LED_voidToggle(Copy_u8PortId , Copy_u8PinId);
	}
}


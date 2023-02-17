/*
 * PButton_src.c
 *
 *  Created on: Dec 17, 2022
 *      Author: kholoud
 */

#include "../../SERV/STD_TYPES.h"
#include "../../SERV/BIT_MATH.h"

/*** MCAL include ***/
#include "../../MCAL/DIO/Dio_int.h"
/*** HAL include ***/
#include "PButton_int.h"
#include "PButton_cfg.h"

#include "util/delay.h"


void PButton_voidInit(PortId_t Copy_u8PortId ,PinId_t Copy_u8PinId){
	 DIO_u8SetPinMode (Copy_u8PortId , Copy_u8PinId , INPUT);
	#if PULLUP_RES==0    // active internal pullup
	 	 DIO_u8SetPinVal (Copy_u8PortId , Copy_u8PinId , HIGH);
	#endif
}

uint8 PButton_u8Read(PortId_t Copy_u8PortId ,PinId_t Copy_u8PinId){
	uint8 Local_u8ReturnValue;
	_delay_ms(50);  // to protect from  bouncing
	Local_u8ReturnValue=DIO_u8GetPinVal(Copy_u8PortId , Copy_u8PinId, &Local_u8ReturnValue);
	return Local_u8ReturnValue;
}

/*
 * PButton_int.h
 *
 *  Created on: Dec 17, 2022
 *      Author: kholoud
 */

#ifndef PBUTTON_INT_H_
#define PBUTTON_INT_H_

/******************* Push Button Initialization *******************/
void PButton_voidInit(PortId_t Copy_u8PortId ,PinId_t Copy_u8PinId);

/******************* Read Value Of Push Button *******************/
uint8 PButton_u8Read(PortId_t Copy_u8PortId ,PinId_t Copy_u8PinId);


#endif /* PBUTTON_INT_H_ */

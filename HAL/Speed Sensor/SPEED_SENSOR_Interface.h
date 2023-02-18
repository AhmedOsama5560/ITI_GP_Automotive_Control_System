/********************************************************/
/* Author  : Kholoud Khaled                             */
/* Date    : Feb 7, 2023                                */
/* File    : SPEED_SENSOR_Interface.h                   */
/* Version : V 1.0                                      */
/********************************************************/

#ifndef SPEED_SENSOR_INTERFACE_H_
#define SPEED_SENSOR_INTERFACE_H_

#include "LSTD_TYPES.h"

#define PI     3.14



/*********************************************
 * 							            	 *
 * 			function prototype				 *
 * 								             *
 ********************************************/

void HSpeedSensor_voidInit(void);
void HSpeedSensor_voidIncrementCounter(void);
void HSpeedSensor_U32_Calculate(void);


#endif /* SPEED_SENSOR_INTERFACE_H_ */

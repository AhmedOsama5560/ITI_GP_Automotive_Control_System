/********************************************************/
/* Author  : Kholoud Khaled                             */
/* Date    : Feb 7, 2023                                */
/* File    : SPEED_SENSOR_Config.h                      */
/* Version : V 1.0                                      */
/********************************************************/


#ifndef SPEED_SENSOR_CONFIG_H_
#define SPEED_SENSOR_CONFIG_H_

/* Select EXTINT LINE Connected with Sensor*/

/* Options :
 *
 *	EXTI_LINE0
	EXTI_LINE1
 *
 *
 */
#define SPEED_SENSOR_LINE	EXTI_LINE0

/* Select EXTINT PORT Connected with Sensor*/

/* Options :
 *
 *	EXTI_PORTA
 *	EXTI_PORTB
 *	EXTI_PORTC
 *
 */
#define SPEED_SENSOR_PORT	EXTI_PORTB

/*
 * 		This configurations depend upon wheel used with sensorr/
 */
#define NOF_SLOTS			20
#define WHEEL_DIAMETER_CM	10

#endif /* SPEED_SENSOR_CONFIG_H_ */

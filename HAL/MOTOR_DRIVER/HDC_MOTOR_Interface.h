/*
 * Author: Sandra Ayman
 * Version: V0.0.0
 * Date: 8-2-2023
 * Description: HDC_MOTOR_Interface.h
 */

#ifndef HDC_MOTOR_INTERFACE_H_
#define HDC_MOTOR_INTERFACE_H_
/*---------- Motor Id ----------*/
typedef enum{
	HMOTOR1,
	HMOTOR2,
	HMOTOR3
}MotorId_t;

/*---------- Functions Prototypes ----------*/
/*
 * Description: Initialize the Motor
 * Parameter: Motor Id(HMOTOR1 - HMOTOR2 - HMOTOR3), duty cycle, Timer number
 * Return: Error State
 */
u8 HDC_MOTOR_u8MotorInit(MotorId_t Copy_uddtMotorId, u8 Copy_u8TimerNumber);

/*
 * Description: Motor move clock wise
 * Parameter: Motor Id(HMOTOR1 - HMOTOR2 - HMOTOR3)
 * Return: Error State
 */
u8 HDC_MOTOR_u8MoveClockWise(MotorId_t Copy_uddtMotorId, u32 Copy_u32DutyCycle);

/*
 * Description: Motor move Counter clock wise
 * Parameter: Motor Id(HMOTOR1 - HMOTOR2 - HMOTOR3)
 * Return: Error State
 */
u8 HDC_MOTOR_u8MoveCounterClockWise(MotorId_t Copy_uddtMotorId, u32 Copy_u32DutyCycle);

/*
 * Description: Stop Motor
 * Parameter: Motor Id(HMOTOR1 - HMOTOR2 - HMOTOR3)
 * Return: Error State
 */
u8 HDC_MOTOR_u8StopMove(MotorId_t Copy_uddtMotorId);

#endif /* HDC_MOTOR_INTERFACE_H_ */

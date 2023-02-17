/*
 * Author: Sandra Ayman
 * Version: V0.0.0
 * Date: 11-2-2023
 * Description: HSERVO_MOTOR_Interface.h
 */

#ifndef HSERVO_MOTOR_INTERFACE_H_
#define HSERVO_MOTOR_INTERFACE_H_

/*---------- Servo Motor ID -----------*/
typedef enum{
	HSERVO1,
	HSERVO2,
	HSERVO3,
	HSERVO4
}ServoMotorId_t;
/*---------- Functions Prototypes -----------*/
/* Description: Initialization of Servo Motor
 * Parameter: Servo Motor Id(HSERVO1 - HSERVO2 - HSERVO3 - HSERVO4)
 * Return: Error state
 */
u8 HSERVO_u8ServoInit(ServoMotorId_t Copy_uddtServoId);

/* Description: Set servo motor angle
 * Parameter: Servo Motor Id(HSERVO1 - HSERVO2 - HSERVO3 - HSERVO4), servo motor angle
 * Return: Error state
 */
u8 HSERVO_u8SetServoAngle(ServoMotorId_t Copy_uddtServoId, u8 Copy_u8ServoAngle);

#endif /* HSERVO_MOTOR_INTERFACE_H_ */

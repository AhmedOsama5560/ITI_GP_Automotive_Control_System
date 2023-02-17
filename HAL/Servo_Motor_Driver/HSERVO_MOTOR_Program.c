/*
 * HSERVO_MOTOR_Program.c
 *
 *  Created on: Feb 11, 2023
 *      Author: 20109
 */
/*---------- Include libraries -----------*/
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"

/*---------- Include MCAL Interfaces -----------*/
#include "MRCC_Interface.h"
#include "MGPIO_Interface.h"
#include "MTIMER2_Interface.h"

/*---------- Include HAL Interfaces -----------*/
#include "HSERVO_MOTOR_Config.h"
#include "HSERVO_MOTOR_Interface.h"

/*---------- Functions Prototypes -----------*/
u8 HSERVO_u8ServoInit(ServoMotorId_t Copy_uddtServoId)
{
	u8 Local_u8ErrorState = 0;
	if(Copy_uddtServoId<=HSERVO3)
	{
		switch(Copy_uddtServoId)
		{
		case HSERVO1:
			/* Initialize the timer */
			MTIM_u8TimInit(HSERVO1_TIM_VALUE);
			/* Set Timer Pin ALTF */
			MGPIO_vSetPinMode(HSERVO1_EN_PORT,HSERVO1_EN_PIN,MODE_ALTF);
			/* Set Timer Pin ALTF */
			MGPIO_vSetPinAltFn(HSERVO1_EN_PORT,HSERVO1_EN_PIN,HSERVO1_TIM_ALTF);
			break;
		case HSERVO2:
			/* Initialize the timer */
			MTIM_u8TimInit(HSERVO2_TIM_VALUE);
			/* Enable Timer port */
			MGPIO_vSetPinMode(HSERVO2_EN_PORT,HSERVO2_EN_PIN,MODE_ALTF);
			/* Set Timer Pin ALTF */
			MGPIO_vSetPinAltFn(HSERVO2_EN_PORT,HSERVO2_EN_PIN,HSERVO2_TIM_ALTF);
			break;
		case HSERVO3:
			/* Initialize the timer */
			MTIM_u8TimInit(HSERVO3_TIM_VALUE);
			/* Set Timer Pin ALTF */
			MGPIO_vSetPinMode(HSERVO3_EN_PORT,HSERVO3_EN_PIN,MODE_ALTF);
			/* Set Timer Pin ALTF */
			MGPIO_vSetPinAltFn(HSERVO3_EN_PORT,HSERVO3_EN_PIN,HSERVO3_TIM_ALTF);
			break;
		case HSERVO4:
			/* Initialize the timer */
			MTIM_u8TimInit(HSERVO4_TIM_VALUE);
			/* Set Timer Pin ALTF */
			MGPIO_vSetPinMode(HSERVO4_EN_PORT,HSERVO4_EN_PIN,MODE_ALTF);
			/* Set Timer Pin ALTF */
			MGPIO_vSetPinAltFn(HSERVO4_EN_PORT,HSERVO4_EN_PIN,HSERVO4_TIM_ALTF);
			break;
		}
	}
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}
u8 HSERVO_u8SetServoAngle(ServoMotorId_t Copy_uddtServoId, u8 Copy_u8ServoAngle)
{
	u8 Local_u8ErrorState = 0;
	f32 Local_u32DutyCycle;
	if(Copy_uddtServoId<=HSERVO3)
	{
		switch(Copy_uddtServoId)
		{
		case HSERVO1:
			/* Set Servo angle */
			Local_u32DutyCycle = (f32)HSERVO1_SLOPE * Copy_u8ServoAngle + HSERVO1_OFFSET;
			/* Generate PWM */
			MTIM_u8GeneratePWM(HSERVO1_TIM_VALUE, HSERVO1_TIM_POLARITY,Local_u32DutyCycle );
			break;
		case HSERVO2:
			/* Set Servo angle */
			Local_u32DutyCycle = (f32)HSERVO2_SLOPE * Copy_u8ServoAngle + HSERVO2_OFFSET;
			/* Generate PWM */
			MTIM_u8GeneratePWM(HSERVO2_TIM_VALUE, HSERVO2_TIM_POLARITY,Local_u32DutyCycle );
			break;
		case HSERVO3:
			/* Set Servo angle */
			Local_u32DutyCycle = (f32)HSERVO3_SLOPE * Copy_u8ServoAngle + HSERVO3_OFFSET;
			/* Generate PWM */
			MTIM_u8GeneratePWM(HSERVO3_TIM_VALUE, HSERVO3_TIM_POLARITY,Local_u32DutyCycle );
			break;
		case HSERVO4:
			/* Set Servo angle */
			Local_u32DutyCycle = (f32)HSERVO4_SLOPE * Copy_u8ServoAngle + HSERVO4_OFFSET;
			/* Generate PWM */
			MTIM_u8GeneratePWM(HSERVO4_TIM_VALUE, HSERVO4_TIM_POLARITY,Local_u32DutyCycle );
			break;
		}
	}
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}


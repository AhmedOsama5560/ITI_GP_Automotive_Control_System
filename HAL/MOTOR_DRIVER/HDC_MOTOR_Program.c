/*
 * Author: Sandra Ayman
 * Version: V0.0.0
 * Date: 8-2-2023
 * Description: HDC_MOTOR_Program.c
 */
/*Include libraries*/
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
/*Include MCAL Interfaces*/
#include "MRCC_Interface.h"
#include "MGPIO_Interface.h"
#include "MTIMER2_Interface.h"
/*Include HAL Interfaces*/
#include "HDC_MOTOR_Config.h"
#include "HDC_MOTOR_Interface.h"

/*---------- Functions Implementation ----------*/
/*---------- HDC_MOTOR_u8MotorInit Implementation ----------*/
u8 HDC_MOTOR_u8MotorInit(MotorId_t Copy_uddtMotorId, u8 Copy_u8TimerNumber)
{
	u8 Local_u8ErrorState = 0;
	if(Copy_uddtMotorId<=HMOTOR3)
	{
		switch(Copy_uddtMotorId)
		{
		case HMOTOR1:
			/* Enable Timer port */
			MRCC_voidEnablePeripheralClock(MRCC_AHB1,HMOTOR1_EN_PORT);
			/* Set Timer Pin ALTF */
			MGPIO_vSetPinMode(HMOTOR1_EN_PORT,HMOTOR1_EN_PIN,MODE_ALTF);
			switch(Copy_u8TimerNumber)
			{
			case TIM2:
				/* Enable Timer */
				MRCC_voidEnablePeripheralClock(MRCC_APB1,MRCC_TIM2_EN);
				/* Set ALTF Type */
				MGPIO_vSetPinAltFn(HMOTOR1_EN_PORT,HMOTOR1_EN_PIN,ALTF_1);
				break;
			case TIM3:
				/* Enable Timer */
				MRCC_voidEnablePeripheralClock(MRCC_APB1,MRCC_TIM3_EN);
				/* Set ALTF Type */
				MGPIO_vSetPinAltFn(HMOTOR1_EN_PORT,HMOTOR1_EN_PIN,ALTF_2);
				break;
			case TIM4:
				/* Enable Timer */
				MRCC_voidEnablePeripheralClock(MRCC_APB1,MRCC_TIM4_EN);
				/* Set ALTF Type */
				MGPIO_vSetPinAltFn(HMOTOR1_EN_PORT,HMOTOR1_EN_PIN,ALTF_2);
				break;
			case TIM5:
				/* Enable Timer */
				MRCC_voidEnablePeripheralClock(MRCC_APB1,MRCC_TIM5_EN);
				/* Set ALTF Type */
				MGPIO_vSetPinAltFn(HMOTOR1_EN_PORT,HMOTOR1_EN_PIN,ALTF_2);
				break;
			}
			/* Set Motor Pins as Output */
			MGPIO_vSetPinMode(HMOTOR1_A_PORT,HMOTOR1_A_PIN,MODE_OUTPUT);
			MGPIO_vSetPinMode(HMOTOR1_B_PORT,HMOTOR1_B_PIN,MODE_OUTPUT);
			break;
			case HMOTOR2:
				/* Enable Timer port */
				MRCC_voidEnablePeripheralClock(MRCC_AHB1,HMOTOR2_EN_PORT);
				/* Set Timer Pin ALTF */
				MGPIO_vSetPinMode(HMOTOR2_EN_PORT,HMOTOR2_EN_PIN,MODE_ALTF);
				switch(Copy_u8TimerNumber)
				{
				case TIM2:
					/* Enable Timer */
					MRCC_voidEnablePeripheralClock(MRCC_APB1,MRCC_TIM2_EN);
					/* Set ALTF Type */
					MGPIO_vSetPinAltFn(HMOTOR2_EN_PORT,HMOTOR2_EN_PIN,ALTF_1);
					break;
				case TIM3:
					/* Enable Timer */
					MRCC_voidEnablePeripheralClock(MRCC_APB1,MRCC_TIM3_EN);
					/* Set ALTF Type */
					MGPIO_vSetPinAltFn(HMOTOR2_EN_PORT,HMOTOR2_EN_PIN,ALTF_2);
					break;
				case TIM4:
					/* Enable Timer */
					MRCC_voidEnablePeripheralClock(MRCC_APB1,MRCC_TIM4_EN);
					/* Set ALTF Type */
					MGPIO_vSetPinAltFn(HMOTOR2_EN_PORT,HMOTOR2_EN_PIN,ALTF_2);
					break;
				case TIM5:
					/* Enable Timer */
					MRCC_voidEnablePeripheralClock(MRCC_APB1,MRCC_TIM5_EN);
					/* Set ALTF Type */
					MGPIO_vSetPinAltFn(HMOTOR2_EN_PORT,HMOTOR2_EN_PIN,ALTF_2);
					break;
				}
				/* Set Motor Pins as Output */
				MGPIO_vSetPinMode(HMOTOR2_A_PORT,HMOTOR2_A_PIN,MODE_OUTPUT);
				MGPIO_vSetPinMode(HMOTOR2_B_PORT,HMOTOR2_B_PIN,MODE_OUTPUT);
				break;
				case HMOTOR3:
					/* Enable Timer port */
					MRCC_voidEnablePeripheralClock(MRCC_AHB1,HMOTOR3_EN_PORT);
					/* Set Timer Pin ALTF */
					MGPIO_vSetPinMode(HMOTOR3_EN_PORT,HMOTOR3_EN_PIN,MODE_ALTF);
					switch(Copy_u8TimerNumber)
					{
					case TIM2:
						/* Enable Timer */
						MRCC_voidEnablePeripheralClock(MRCC_APB1,MRCC_TIM2_EN);
						/* Set ALTF Type */
						MGPIO_vSetPinAltFn(HMOTOR3_EN_PORT,HMOTOR3_EN_PIN,ALTF_1);
						break;
					case TIM3:
						/* Enable Timer */
						MRCC_voidEnablePeripheralClock(MRCC_APB1,MRCC_TIM3_EN);
						/* Set ALTF Type */
						MGPIO_vSetPinAltFn(HMOTOR3_EN_PORT,HMOTOR3_EN_PIN,ALTF_2);
						break;
					case TIM4:
						/* Enable Timer */
						MRCC_voidEnablePeripheralClock(MRCC_APB1,MRCC_TIM4_EN);
						/* Set ALTF Type */
						MGPIO_vSetPinAltFn(HMOTOR3_EN_PORT,HMOTOR3_EN_PIN,ALTF_2);
						break;
					case TIM5:
						/* Enable Timer */
						MRCC_voidEnablePeripheralClock(MRCC_APB1,MRCC_TIM5_EN);
						/* Set ALTF Type */
						MGPIO_vSetPinAltFn(HMOTOR3_EN_PORT,HMOTOR3_EN_PIN,ALTF_2);
						break;
					}
					/* Set Motor Pins as Output */
					MGPIO_vSetPinMode(HMOTOR3_A_PORT,HMOTOR3_A_PIN,MODE_OUTPUT);
					MGPIO_vSetPinMode(HMOTOR3_B_PORT,HMOTOR3_B_PIN,MODE_OUTPUT);
					break;
		}
	}
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}

/*---------- HDC_MOTOR_u8MoveClockWise Implementation ----------*/
u8 HDC_MOTOR_u8MoveClockWise(MotorId_t Copy_uddtMotorId, u32 Copy_u32DutyCycle)
{
	u8 Local_u8ErrorState = 0;
	if(Copy_uddtMotorId<=HMOTOR3)
	{
		switch(Copy_uddtMotorId)
		{
		case HMOTOR1:
			MTIM_u8GeneratePWM(HMOTOR1_TIMER_Number, HMOTOR1_TIMER_Polarity,Copy_u32DutyCycle );
			MGPIO_vWriteData(HMOTOR1_A_PORT,HMOTOR1_A_PIN,HIGH);
			MGPIO_vWriteData(HMOTOR1_B_PORT,HMOTOR1_B_PIN,LOW);
			break;
		case HMOTOR2:
			MTIM_u8GeneratePWM(HMOTOR2_TIMER_Number, HMOTOR2_TIMER_Polarity,Copy_u32DutyCycle );
			MGPIO_vWriteData(HMOTOR2_A_PORT,HMOTOR2_A_PIN,HIGH);
			MGPIO_vWriteData(HMOTOR2_B_PORT,HMOTOR2_B_PIN,LOW);
			break;
		case HMOTOR3:
			MTIM_u8GeneratePWM(HMOTOR3_TIMER_Number, HMOTOR3_TIMER_Polarity,Copy_u32DutyCycle );
			MGPIO_vWriteData(HMOTOR3_A_PORT,HMOTOR3_A_PIN,HIGH);
			MGPIO_vWriteData(HMOTOR3_B_PORT,HMOTOR3_B_PIN,LOW);
			break;
		}
	}
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}

/*---------- HDC_MOTOR_u8MoveCounterClockWise Implementation ----------*/
u8 HDC_MOTOR_u8MoveCounterClockWise(MotorId_t Copy_uddtMotorId, u32 Copy_u32DutyCycle)
{
	u8 Local_u8ErrorState = 0;
	if(Copy_uddtMotorId<=HMOTOR3)
	{
		switch(Copy_uddtMotorId)
		{
		case HMOTOR1:
			MTIM_u8GeneratePWM(HMOTOR1_TIMER_Number, HMOTOR1_TIMER_Polarity,Copy_u32DutyCycle );
			MGPIO_vWriteData(HMOTOR1_A_PORT,HMOTOR1_A_PIN,LOW);
			MGPIO_vWriteData(HMOTOR1_B_PORT,HMOTOR1_B_PIN,HIGH);
			break;
		case HMOTOR2:
			MTIM_u8GeneratePWM(HMOTOR2_TIMER_Number, HMOTOR2_TIMER_Polarity,Copy_u32DutyCycle );
			MGPIO_vWriteData(HMOTOR2_A_PORT,HMOTOR2_A_PIN,LOW);
			MGPIO_vWriteData(HMOTOR2_B_PORT,HMOTOR2_B_PIN,HIGH);
			break;
		case HMOTOR3:
			MTIM_u8GeneratePWM(HMOTOR3_TIMER_Number, HMOTOR3_TIMER_Polarity,Copy_u32DutyCycle );
			MGPIO_vWriteData(HMOTOR3_A_PORT,HMOTOR3_A_PIN,LOW);
			MGPIO_vWriteData(HMOTOR3_B_PORT,HMOTOR3_B_PIN,HIGH);
			break;
		}
	}
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}

/*----------  HDC_MOTOR_u8StopMove Implementation ----------*/
u8 HDC_MOTOR_u8StopMove(MotorId_t Copy_uddtMotorId)
{
	u8 Local_u8ErrorState = 0;
	if(Copy_uddtMotorId<=HMOTOR3)
	{
		switch(Copy_uddtMotorId)
		{
		case HMOTOR1:
			MGPIO_vWriteData(HMOTOR1_A_PORT,HMOTOR1_A_PIN,LOW);
			MGPIO_vWriteData(HMOTOR1_B_PORT,HMOTOR1_B_PIN,LOW);
			MTIM_u8PWMStop(HMOTOR1_TIMER_Number);
			break;
		case HMOTOR2:
			MGPIO_vWriteData(HMOTOR2_A_PORT,HMOTOR2_A_PIN,LOW);
			MGPIO_vWriteData(HMOTOR2_B_PORT,HMOTOR2_B_PIN,LOW);
			MTIM_u8PWMStop(HMOTOR2_TIMER_Number);
			break;
		case HMOTOR3:
			MGPIO_vWriteData(HMOTOR3_A_PORT,HMOTOR3_A_PIN,LOW);
			MGPIO_vWriteData(HMOTOR3_B_PORT,HMOTOR3_B_PIN,LOW);
			MTIM_u8PWMStop(HMOTOR3_TIMER_Number);
			break;
		}
	}
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}

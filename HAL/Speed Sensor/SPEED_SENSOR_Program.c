/********************************************************/
/* Author  : Kholoud Khaled                             */
/* Date    : Feb 7, 2023                                */
/* File    : SPEED_SENSOR_Program.c                     */
/* Version : V 1.0                                      */
/********************************************************/

#include "SPEED_SENSOR_Interface.h"
#include "SPEED_SENSOR_Config.h"
#include "SPEED_SENSOR_Private.h"

#include "EXTI_interface.h"
#include "MSTK_Interface.h"

/************* Global Variables **************/
volatile u32 SpeedSensor_U32_Counter = 0;
volatile f32 SpeedSensor_F32_Speed_CM =0;


void HSpeedSensor_voidInit(void)
{
	// Adjust GPIO as EXTI
	//Set IRQ of EXTI
	/* Call function of HSpeedSensor_voidIncrementCounter every lack slot*/
	MEXTI_vPortConfig(SPEED_SENSOR_PORT, SPEED_SENSOR_LINE);
	MEXTI0_vSetCallBack(HSpeedSensor_voidIncrementCounter);
	MEXTI_vEventTrigger(SPEED_SENSOR_LINE, EXTI_RAISING);
	MEXTI_vEnableLine(SPEED_SENSOR_LINE);

	// Adjust SYSTick
	MSTK_voidInit();
	// Set IRQ of SYSTick
	/* Call function of Calculate every 1sec*/
	MSTK_voidSetIntervalPeriodic(1000000, HSpeedSensor_U32_Calculate);
}

void HSpeedSensor_voidIncrementCounter(void)
{
	SpeedSensor_U32_Counter++;

}

void HSpeedSensor_U32_Calculate(void)
{
	SpeedSensor_F32_Speed_CM = (SpeedSensor_U32_Counter *PI*WHEEL_DIAMETER_CM)/NOF_SLOTS;
	SpeedSensor_U32_Counter = 0;
}

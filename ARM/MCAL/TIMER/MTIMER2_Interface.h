/*
 * Author: Sandra Ayman
 * Version: V0.0.0
 * Date: 3-1-2023
 * Description: MTIMER2_Interface.h
 */

#ifndef MTIMER2_INTERFACE_H_H_
#define MTIMER2_INTERFACE_H_H_
/*----------Timer Selection----------*/
typedef enum{
	TIM2,
	TIM3,
	TIM4,
	TIM5
}TimId_t;

/*----------Output compare Polarity----------*/
typedef enum{
	MTIM_HIGH,
	MTIM_LOW
}OutComparePolarity_t;
/*----------External Trigger Polarity----------*/
#define EXT_TRIGGER_RAISING 0U
#define EXT_TRIGGER_FALLING 1U
/*----------External Trigger Prescaler----------*/
#define EXT_TRIGGER_NO_PRESCALER 0U
#define EXT_TRIGGER_DIVIDED_2    1U
#define EXT_TRIGGER_DIVIDED_4    0U
#define EXT_TRIGGER_DIVIDED_8    0U
/*----------Trigger Selection----------*/
#define INTERNAL_TRIGGER0      0U
#define INTERNAL_TRIGGER1      0U
#define INTERNAL_TRIGGER2      0U
#define INTERNAL_TRIGGER3      0U
#define TI1_EDGE_DETECTOR      0U
#define FILTERED_TIMER_INPUT1  0U
#define FILTERED_TIMER_INPUT2  0U
#define EXTERNAL_TRIGGER_INPUT 1U
/*----------Slave Mode Selection----------*/
#define SLAVE_MODE_DISABLE   0U
#define ENCODER_MODE1        0U
#define ENCODER_MODE2        0U
#define ENCODER_MODE3        0U
#define RESET_MODE           0U
#define GATED_MODE           0U
#define TRIGGER_MODE         0U
#define EXTERNAL_CLOCK_MODE1 1U
/*----------Functions Prototype----------*/
/* Function description: Initialize the timer
 * Parameter: timer number(TIM2 - TIM3 - TIM4 - TIM5)
 * Return: Error state
 */
u8 MTIM_u8TimInit(TimId_t Copy_uddtTimerId);
/* Function description: set timer as up counter
 * Parameter: timer number(TIM2 - TIM3 - TIM4 - TIM5)
 * Return: Error state
 */
u8 MTIM_u8UpCounterInit(TimId_t Copy_uddtTimerId);
/* Function description: set timer as down counter
 * Parameter: timer number(TIM2 - TIM3 - TIM4 - TIM5)
 * Return: nothing
 */
u8 MTIM_u8DownCounterInit(TimId_t Copy_uddtTimerId);
/* Function description: set timer as up and down counter
 * Parameter: timer number(TIM2 - TIM3 - TIM4 - TIM5)
 * Return: Error state
 */
u8 MTIM_u8UpDownCounterInit(TimId_t Copy_uddtTimerId);
/* Function description: set timer which takes external clock
 * Parameter: timer number(TIM2 - TIM3 - TIM4 - TIM5)
 * Return: Error state
 */
u8 MTIM_u8ExternalTriggerTimerInit(TimId_t Copy_uddtTimerId);
/* Function description: Measure PWM using input capture mode
 * Parameter: timer number(TIM2 - TIM3 - TIM4 - TIM5)
 * Return: Error state
 */
u8 MTIM_u8PWMInputCaptureInit(TimId_t Copy_uddtTimerId);
/* Function description: Generate PWM using output compare mode
 * Parameter: timer number(TIM2 - TIM3 - TIM4 - TIM5), Output compare polarity(HIGH - LOW), Duty Cycle
 * Return: Error state
 */
u8 MTIM_u8GeneratePWM(TimId_t Copy_uddtTimerId, OutComparePolarity_t Copy_uddtOCP, u8 Copy_u8DutyCycle);
/* Function description: Stop PWM
 * Parameter: timer number(TIM2 - TIM3 - TIM4 - TIM5)
 * Return: Error state
 */
u8 MTIM_u8PWMStop(TimId_t Copy_uddtTimerId);
/* Function description: Stop the timer
 * Parameter: timer number(TIM2 - TIM3 - TIM4 - TIM5)
 * Return: Error state
 */
u8 MTIM_u8TimStop(TimId_t Copy_uddtTimerId);

#endif /*MTIMER2_INTERFACE_H__H_ */

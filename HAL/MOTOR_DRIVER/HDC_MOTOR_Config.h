/*
 * Author: Sandra Ayman
 * Version: V0.0.0
 * Date: 8-2-2023
 * Description: HDC_MOTOR_Config.h
 */

#ifndef HDC_MOTOR_CONFIG_H_
#define HDC_MOTOR_CONFIG_H_
/*Motor PORT & PINS*/
/*Motor 1 PORT &PINS*/
#define HMOTOR1_TIMER_Number   TIM2
#define HMOTOR1_TIMER_Polarity MTIM_HIGH

#define HMOTOR1_EN_PORT     GPIOA
#define HMOTOR1_EN_PIN      _GPIO_PIN_0

#define HMOTOR1_A_PORT         GPIOB
#define HMOTOR1_A_PIN          _GPIO_PIN_0

#define HMOTOR1_B_PORT         GPIOB
#define HMOTOR1_B_PIN          _GPIO_PIN_1

/*Motor 2 PORT &PINS*/
#define HMOTOR2_TIMER_Number   TIM3
#define HMOTOR2_TIMER_Polarity MTIM_HIGH

#define HMOTOR2_EN_PORT     GPIOA
#define HMOTOR2_EN_PIN      _GPIO_PIN_1

#define HMOTOR2_A_PORT         GPIOB
#define HMOTOR2_A_PIN          _GPIO_PIN_2

#define HMOTOR2_B_PORT         GPIOB
#define HMOTOR2_B_PIN          _GPIO_PIN_3

/*Motor 3 PORT &PINS*/
#define HMOTOR3_TIMER_Number   TIM4
#define HMOTOR3_TIMER_Polarity MTIM_HIGH

#define HMOTOR3_EN_PORT     GPIOA
#define HMOTOR3_EN_PIN      _GPIO_PIN_2

#define HMOTOR3_A_PORT         GPIOB
#define HMOTOR3_A_PIN          _GPIO_PIN_4

#define HMOTOR3_B_PORT         GPIOB
#define HMOTOR3_B_PIN          _GPIO_PIN_5


#endif /* HDC_MOTOR_CONFIG_H_ */

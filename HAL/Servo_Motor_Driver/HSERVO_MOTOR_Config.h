/*
 * Author: Sandra Ayman
 * Version: V0.0.0
 * Date: 11-2-2023
 * Description: HSERVO_MOTOR_Config.h
 */

#ifndef HSERVO_MOTOR_CONFIG_H_
#define HSERVO_MOTOR_CONFIG_H_

/*---------- SERVO 1 Configuration ----------*/
#define HSERVO1_TIM_POLARITY    MTIM_HIGH
#define HSERVO1_TIM_ALTF        ALTF_2
#define HSERVO1_TIM_VALUE       TIM3
#define HSERVO1_EN_PORT         GPIOA
#define HSERVO1_EN_PIN          _GPIO_PIN_6
#define HSERVO1_OFFSET          (5U)
#define HSERVO1_SLOPE           (5.0/180)

/*---------- SERVO 2 Configuration ----------*/
#define HSERVO2_TIM_POLARITY    MTIM_HIGH
#define HSERVO2_TIM_ALTF        ALTF_2
#define HSERVO2_TIM_VALUE       TIM5
#define HSERVO2_EN_PORT         GPIOA
#define HSERVO2_EN_PIN          _GPIO_PIN_1
#define HSERVO2_OFFSET          (5U)
#define HSERVO2_SLOPE           (5.0/180)

/*---------- SERVO 3 Configuration ----------*/
#define HSERVO3_TIM_POLARITY    MTIM_HIGH
#define HSERVO3_TIM_ALTF        ALTF_2
#define HSERVO3_TIM_VALUE       TIM5
#define HSERVO3_EN_PORT         GPIOA
#define HSERVO3_EN_PIN          _GPIO_PIN_2
#define HSERVO3_OFFSET          (5U)
#define HSERVO3_SLOPE           (5.0/180)

/*---------- SERVO 4 Configuration ----------*/
#define HSERVO4_TIM_POLARITY    MTIM_HIGH
#define HSERVO4_TIM_ALTF        ALTF_2
#define HSERVO4_TIM_VALUE       TIM5
#define HSERVO4_EN_PORT         GPIOA
#define HSERVO4_EN_PIN          _GPIO_PIN_3
#define HSERVO4_OFFSET          (5U)
#define HSERVO4_SLOPE           (5.0/180)

#endif /* HSERVO_MOTOR_CONFIG_H_ */

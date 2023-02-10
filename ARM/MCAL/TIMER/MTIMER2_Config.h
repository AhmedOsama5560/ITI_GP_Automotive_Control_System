/*
 * MTIMER_Config.h
 *
 *  Created on: Feb 3, 2023
 *      Author: 20109
 */

#ifndef MTIMER2_CONFIG_H_H_
#define MTIMER2_CONFIG_H_H_

/* center aligned mode selection:
                                1- edge aligned mode     (0)->counting depends on direction
                                2- center aligned mode 1 (1)-> down counting in output compare
                                3- center aligned mode 1 (2)-> up counting in output compare
                                4- center aligned mode 1 (3)-> up and down counting in output compare
*/
#define MTIM2_CENTER_MODE_SELECTION 3U
#define MTIM3_CENTER_MODE_SELECTION 3U
#define MTIM4_CENTER_MODE_SELECTION 3U
#define MTIM5_CENTER_MODE_SELECTION 3U

/* Counter Direction options:
                            1- Up counter   (0)
                            2- Down counter (1)
*/
#define MTIM2_COUNTER_DIRECTION 0U
#define MTIM3_COUNTER_DIRECTION 0U
#define MTIM4_COUNTER_DIRECTION 0U
#define MTIM5_COUNTER_DIRECTION 0U

/*External Trigger Modes:
                         1- Mode 1
                         2- Mode 2
*/
#define MTIM2_EXTERNAL_TRIGGER_MODE 1
#define MTIM3_EXTERNAL_TRIGGER_MODE 1
#define MTIM4_EXTERNAL_TRIGGER_MODE 1
#define MTIM5_EXTERNAL_TRIGGER_MODE 1

/*External Trigger Filter*/
#define MTIM2_EXTERNAL_TRIGGER_Filter 0U
#define MTIM3_EXTERNAL_TRIGGER_Filter 0U
#define MTIM4_EXTERNAL_TRIGGER_Filter 0U
#define MTIM5_EXTERNAL_TRIGGER_Filter 0U
/*PWM Mode Options:
                   1- PWM Mode 1
                   2- PWM Mode 2
*/
#define MTIM2_PWM_MODE 1U
#define MTIM3_PWM_MODE 1U
#define MTIM4_PWM_MODE 1U
#define MTIM5_PWM_MODE 1U
/*Enable number of channels*/
#define TIM_CH1_EN 1U
#define TIM_CH2_EN 0U
#define TIM_CH3_EN 0U
#define TIM_CH4_EN 0U
/*Prescaler value*/
#define MTIM2_PRESCALER_VALUE 15
#define MTIM3_PRESCALER_VALUE 15
#define MTIM4_PRESCALER_VALUE 15
#define MTIM5_PRESCALER_VALUE 15
/*Auto Reload value*/
#define MTIM2_AUTORELOAD_VALUE 1000
#define MTIM3_AUTORELOAD_VALUE 1000
#define MTIM4_AUTORELOAD_VALUE 1000
#define MTIM5_AUTORELOAD_VALUE 1000

#endif /*MTIMER2_CONFIG_H__H_ */

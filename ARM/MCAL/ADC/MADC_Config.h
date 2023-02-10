
/*******************************************************************************************************/
/* Author            : Kholoud khaled                                                                  */
/* Version           : V0.0.0                                                                          */
/* Data              : 3 -2 - 2023                                                                     */
/* Description       : MADC_Config.h --> configuration                                                 */
/*******************************************************************************************************/

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/*
	OPTION
			Regular
			Injected
*/

#define ADC_MODE Regular

/*
	OPTION
			_12BIT   //15 ADCCLK cycles
			_10BIT   //13 ADCCLK cycles
			_8BIT    //11 ADCCLK cycles
			_6bIT    //9 ADCCLK cycles

*/

#define ADC_Resolution     			_10BIT

/*
	OPTION
			RIGHT_ALIGNMENT
			LEFT_ALIGNMENT

*/

#define ADC_DATA_ALIGNMENT 			RIGHT_ALIGNMENT
/*
	OPTION
			conversion_[1:16]

*/
#define No_of_conversion            conversion_1


/*
	OPTION
			PCLK2_divided_by_2
			PCLK2_divided_by_4
			PCLK2_divided_by_6
			PCLK2_divided_by_8

*/
#define Prescaller                  PCLK2_divided_by_4


// Config ADC PORT and PIN

#define ADC_PORT     			    MGPIOA
#define ADC_PIN 					MGPIO_PIN8




#endif /* MADC_CONFIG_H_ */

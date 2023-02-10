/*******************************************************************************************************/
/* Author            : Kholoud khaled                                                                  */
/* Version           : V0.0.0                                                                          */
/* Data              : 3 -2 - 2023                                                                     */
/* Description       : MADC_Interface.h --> APIs and interface of module                               */
/* Module  Features  :                                                                                 */
/*      01- MADC_vInit                                                                                 */
/*      02- MADC_vEnable                                                                               */
/*      03- MADC_vDisable                                                                              */
/*      04- MADC_v1StartConv                                                                           */
/*      05- MADC_v1StopConv                                                                            */
/*      06- MADC_v1OrderSelection                                                                      */
/*      07- MADC_u16_1GetInjectedRead                                                                  */
/*      08- MADC_u16_1GetRegularRead                                                                   */
/*      09- MADC_v1SetCallBack                                                                         */
/*******************************************************************************************************/

#ifndef MADC_INTERFACE_H
#define MADC_INTERFACE_H



/*===========   INCLUDE LIB   ===========*/
#include <LBIT_MATH.h>
#include <LSTD_TYPES.h>
/*======================================*/
/*===========  INCLUDE MCAL  ===========*/


/*===============================ENUMS========================================*/


typedef enum
{
	Regular  = 0U,
	Injected     ,
}ADC_MODE_t;

typedef enum
{
	_12BIT = 0B00,
	_10BIT = 0B01,
	_8BIT  = 0B10,
	_6bIT  = 0B11,

}ADC_RESOLUTION_t;

typedef enum
{
	RIGHT_ALIGNMENT = 0b0,
	LEFT_ALIGNMENT = 0B1,
}DATA_ALIGNMENT_t;




typedef enum
{
	SQ1  =0b0000  ,
	SQ2  =0b0001  ,
	SQ3  =0b0010  ,
	SQ4  =0b0011  ,
	SQ5  =0b0100  ,
	SQ6  =0b0101  ,
	SQ7  =0b0110  ,
	SQ8  =0b0111  ,
	SQ9  =0b1000  ,
	SQ10 =0b1001  ,
	SQ11 =0b1010  ,
	SQ12 =0b1011  ,
	SQ13 =0b1100  ,
	SQ14 =0b1101  ,
	SQ15 =0b1110  ,
	SQ16 =0b1111  ,


}SequenceNum_t;

typedef enum
{
	ChannelNum_1  =0b0000  ,
	ChannelNum_2  =0b0001  ,
	ChannelNum_3  =0b0010  ,
	ChannelNum_4  =0b0011  ,
	ChannelNum_5  =0b0100  ,
	ChannelNum_6  =0b0101  ,
	ChannelNum_7  =0b0110  ,
	ChannelNum_8  =0b0111  ,
	ChannelNum_9  =0b1000  ,
	ChannelNum_10 =0b1001  ,
	ChannelNum_11 =0b1010  ,
	ChannelNum_12 =0b1011  ,
	ChannelNum_13 =0b1100  ,
	ChannelNum_14 =0b1101  ,
	ChannelNum_15 =0b1110  ,
	ChannelNum_16 =0b1111  ,
}ChannelNum_t;

typedef enum
{
	conversion_1  =0b0000  ,
	conversion_2  =0b0001  ,
	conversion_3  =0b0010  ,
	conversion_4  =0b0011  ,
	conversion_5  =0b0100  ,
	conversion_6  =0b0101  ,
	conversion_7  =0b0110  ,
	conversion_8  =0b0111  ,
	conversion_9  =0b1000  ,
	conversion_10 =0b1001  ,
	conversion_11 =0b1010  ,
	conversion_12 =0b1011  ,
	conversion_13 =0b1100  ,
	conversion_14 =0b1101  ,
	conversion_15 =0b1110  ,
	conversion_16 =0b1111  ,
}ConversionNum_t;

typedef enum
{
	PCLK2_divided_by_2 = 0b00,
	PCLK2_divided_by_4 = 0b01,
	PCLK2_divided_by_6 = 0b10,
	PCLK2_divided_by_8 = 0b11,
}Prescaller_t;

/*-------------------------------------------------------------------*/
/*===================MACRO========================*/

#define Disable  0b0
#define Enable   0b1
/*-------------------PROTOYYPE--------------------*/
void MADC_vInit(void);

void MADC_vEnable(void);

void MADC_vDisable(void);

void MADC_v1StartConv(ADC_MODE_t Copy_u8_MODE_TYPE);

void MADC_v1StopConv(ADC_MODE_t Copy_u8_MODE_TYPE );

void MADC_v1OrderSelection(ADC_MODE_t Copy_u8_MODE_TYPE  , SequenceNum_t Copy_u8SequenceNum , ChannelNum_t Copy_u8ChannelNum);

u16 MADC_u16_1GetInjectedRead(ChannelNum_t Copy_u8ChannelNum);

u16 MADC_u16_1GetRegularRead(void);

void MADC_v1SetCallBack(void (* ptr)(void));



#endif

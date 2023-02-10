/*******************************************************************************************************/
/* Author            : Kholoud khaled                                                                  */
/* Version           : V0.0.0                                                                          */
/* Data              : 3 -2 - 2023                                                                     */
/* Description       : MADC_Program.c --> Impelementation of APIs                                      */
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
/*      10- MADC_vIQHandeler                                                                           */
/*******************************************************************************************************/

/*===========   INCLUDE LIB   ===========*/
#include <LBIT_MATH.h>
#include <LSTD_TYPES.h>


#include "MADC_Interface.h"
#include "MADC_Privaite.h"
#include "MADC_Config.h"
#include "MRCC_Interface.h"
#include "MGPIO_interface.h"

/*======================================*/


void (*MADC1_CallBack)(void);

/*====================================================   Start_FUNCTION   ====================================================*/


void MADC_vInit(void)
{
	// Enable Peripherals (ADC and GPIOA)

	MRCC_voidEnablePeripheralClock(MRCC_APB2 ,MRCC_ADC1_EN);
	MRCC_voidEnablePeripheralClock(MRCC_AHB1, MRCC_GPIOA_EN);

	// Config ADC Pin as Analog
	MGPIO_vSetPinMode(ADC_PORT,ADC_PIN,MGPIO_ANALOG);
	//MGPIO_vSetPinMode(ADC_PORT ,ADC_PIN,_MODE_ANALOG);
	//MGPIO_vSetPinOutPutType(ADC_PORT ,ADC_PIN, _OUTPUT_TYPE_PUSH_PULL);
	//MGPIO_vSetPinOutSpeed(ADC_PORT ,ADC_PIN ,_OUTPUT_SPEED_MEDUIM);
	//MGPIO_vSetPullType(ADC_PORT ,ADC_PIN ,_PULL_OFF);


	MADC -> CR1 .RES    = ADC_Resolution;
	MADC -> CR2 .ALIGN  = ADC_DATA_ALIGNMENT;
	MADC -> CR1 .JAUTO  = Disable;
	MADC -> CR1 .SCAN   = Disable;
	MADC -> CR1 .EOCIE  = Disable;
	MADC -> CR1 .JEOCIE = Disable;
	MADC -> CR2 .EOCS   = Enable;
	MADC -> CR2 .CONT   = Disable;
	CCR |=	(Prescaller<<(16)) ;


}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
 void MADC_vEnable(void)
 {
	 MADC -> CR2.ADON =0b1;
 }
 /*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
 void MADC_vDisable(void)
 {
	 MADC -> CR2.ADON =0b0;
 }
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
 //FOR ENABLE  DIRECT SINGLE MODE
 void MADC_v1StartConv(ADC_MODE_t Copy_u8_MODE_TYPE)
 {
	 switch (Copy_u8_MODE_TYPE)
	 {
		 case (Regular ) :  MADC -> CR2.SWSTART  = 0b1;   break;
		 case (Injected) : MADC -> CR2.JSWSTART = 0b1; break;
		 default :                                     break;
	 }
 }
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/

// << SWSTART & JSWSTART >> BITS TO START CONVERT

void MADC_v1StopConv(ADC_MODE_t Copy_u8_MODE_TYPE)
{

	  switch (Copy_u8_MODE_TYPE)
	 {
		 case (Regular ) : MADC -> CR2.SWSTART  = 0b0; break;
		 case (Injected) : MADC -> CR2.JSWSTART = 0b0; break;
		 default :                                       break;
	 }


}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
 /*
	1) CHOOSE MODE >> REGULAR OR Injected
	2) CHOOSE SEQ REGULAR   MDAC -> SQR1,2,3  >>REGULAR
							MDAC -> JSQR      >> Injected
	3)LENGTH (NO. OF CONVERSAION  MDAC -> SQR1,2,3 .L 		>>REGULAR
								  MDAC -> JSQR.JL           >> Injected
 */
 void MADC_v1OrderSelection(ADC_MODE_t Copy_u8_MODE_TYPE , SequenceNum_t Copy_u8SequenceNum , ChannelNum_t Copy_u8ChannelNum)
 {

	 #if Copy_u8_MODE_TYPE == Regular
	 MADC ->SQR1    |= No_of_conversion <<20;
	 if(Copy_u8SequenceNum>=1 && Copy_u8SequenceNum<=6)
	 {
		 MADC ->SQR3 |= Copy_u8ChannelNum <<(Copy_u8SequenceNum*5);
	 }
	 else if(Copy_u8SequenceNum>=7 && Copy_u8SequenceNum<=12)
	 {
		 MADC ->SQR2 |= Copy_u8ChannelNum <<(Copy_u8SequenceNum*5);
	 }
	 else if (Copy_u8SequenceNum>=7 && Copy_u8SequenceNum<=12)
	 {
		 MADC ->SQR1 |= Copy_u8ChannelNum <<(Copy_u8SequenceNum*5);
	 }
	 else
	 {
		 /*Error Sequance */
	 }

	 #elif Copy_u8_MODE_TYPE == Injected
	 	 MADC ->JSQR    |= No_of_conversion <<20;
	 	 MADC ->JSQR 	|= Copy_u8ChannelNum <<(Copy_u8SequenceNum*5);
	 #endif
 }
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
 u16 MADC_u16_1GetInjectedRead(ChannelNum_t Copy_u8ChannelNum)
 {
	 u16 Local_u16_ReadingData = 0;


	 switch (Copy_u8ChannelNum)
	 {
		 while ((GET_BIT(MADC ->SR ,2))==0); // end of the conversion of all injected channels in the group bit jeoc

		 //get data
		 case (ChannelNum_1 ) : Local_u16_ReadingData = MADC ->JDR[0];  break;
		 case (ChannelNum_2 ) : Local_u16_ReadingData = MADC ->JDR[1];  break;
		 case (ChannelNum_3 ) : Local_u16_ReadingData = MADC ->JDR[2];  break;
		 case (ChannelNum_4 ) : Local_u16_ReadingData = MADC ->JDR[3];  break;
		 default              :                                       break;
	 }
	 return Local_u16_ReadingData;       //return it
 }

/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
 u16 MADC_u16_1GetRegularRead(void)
 {
	 u16 Local_u16_ReadingData = 0;
	 while ((GET_BIT(MADC ->SR ,1))==0); // end of the conversion of all injected channels in the group bit eoc
	// while ((GET_BIT(MADC ->SR ,4))==0); //wait until conversion end bit strt
	 Local_u16_ReadingData = MADC ->DR;  //get data
	 return Local_u16_ReadingData;       //return it
 }
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void MADC_v1SetCallBack(void (* ptr)(void))
{
	MADC1_CallBack = ptr;
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/

void MADC_vIQHandeler(void)
{
	MADC1_CallBack();
}
/*====================================================   END_ FUNCTION   ====================================================*/

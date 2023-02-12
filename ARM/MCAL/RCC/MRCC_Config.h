/*
 *  Created on  : Jan 25, 2023
 *  Author      : Reham Mohamed
 *  Version	    : V0.0.0
 *  Description : MRCC_Config.h  ->  Configuration
 */

/*******************************************************************/
/*		              Header Guard Of The File                     */
/*******************************************************************/

#ifndef MRCC_CONFIG_H_
#define MRCC_CONFIG_H_

/*
 * 		- CLKSRS Options :
 * 							1- HSI
 * 							2- HSE
 * 							3- PLL
 */

#define MRCC_CLKSRC				HSI

/*
 * 		- HSE Options :
 * 						    1- HSE_RC
 * 						    2- HSE_CRYSTAL
 */

#define MRCC_HSESRC				HSE_CRYSTAL

/*
 * 		- PLL Options :
 * 						    1- PLL_HSE
 * 						    2- PLL_HSI
 */

#define MRCC_PLLSRC				PLL_HSI

#endif /* MRCC_CONFIG_H_ */

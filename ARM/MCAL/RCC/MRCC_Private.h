/*
 *  Created on  : Jan 25, 2023
 *  Author      : Reham Mohamed
 *  Version	    : V0.0.0
 *  Description : MRCC_Private.h  ->  Registers Definition
 */

/*******************************************************************/
/*		              Header Guard Of The File                     */
/*******************************************************************/

#ifndef MRCC_PRIVATE_H_
#define MRCC_PRIVATE_H_

/**********************************************************************************/
/*          - Developer can't edit in it                                          */
/*			- Register Definition                                                 */
/*			- Design :                                                            */
/*						1- #define  : YES										  */
/*						2- struct   : NO                                          */
/*                      3- union	: NO                                          */
/**********************************************************************************/

/******************************** RCC BASE ADDRESS ********************************/
#define MRCC_BASE_ADDRESS			0x40023800

/**********************************************************************************/
/*		                   REGISTERS ADDRESSES OF RCC	                          */
/**********************************************************************************/

#define RCC_CR 						(*((volatile u32*)(MRCC_BASE_ADDRESS + 0x00)))
#define RCC_PLLCFGR					(*((volatile u32*)(MRCC_BASE_ADDRESS + 0x04)))
#define RCC_CFGR 					(*((volatile u32*)(MRCC_BASE_ADDRESS + 0x08)))
#define RCC_CIR						(*((volatile u32*)(MRCC_BASE_ADDRESS + 0x0C)))

#define RCC_AHB1RSTR 				(*((volatile u32*)(MRCC_BASE_ADDRESS + 0x10)))
#define RCC_AHB2RSTR				(*((volatile u32*)(MRCC_BASE_ADDRESS + 0x14)))

#define RCC_APB1RSTR 				(*((volatile u32*)(MRCC_BASE_ADDRESS + 0x20)))
#define RCC_APB2RSTR				(*((volatile u32*)(MRCC_BASE_ADDRESS + 0x24)))

#define RCC_AHB1ENR 				(*((volatile u32*)(MRCC_BASE_ADDRESS + 0x30)))
#define RCC_AHB2ENR					(*((volatile u32*)(MRCC_BASE_ADDRESS + 0x34)))

#define RCC_APB1ENR 				(*((volatile u32*)(MRCC_BASE_ADDRESS + 0x40)))
#define RCC_APB2ENR					(*((volatile u32*)(MRCC_BASE_ADDRESS + 0x44)))

#define RCC_AHB1LPENR 				(*((volatile u32*)(MRCC_BASE_ADDRESS + 0x50)))
#define RCC_AHB2LPENR				(*((volatile u32*)(MRCC_BASE_ADDRESS + 0x54)))

#define RCC_APB1LPENR 				(*((volatile u32*)(MRCC_BASE_ADDRESS + 0x60)))
#define RCC_APB2LPENR				(*((volatile u32*)(MRCC_BASE_ADDRESS + 0x64)))

#define RCC_BDCR 					(*((volatile u32*)(MRCC_BASE_ADDRESS + 0x70)))
#define RCC_CSR						(*((volatile u32*)(MRCC_BASE_ADDRESS + 0x74)))

#define RCC_SSCGR 					(*((volatile u32*)(MRCC_BASE_ADDRESS + 0x80)))
#define RCC_PLLI2SCFGR				(*((volatile u32*)(MRCC_BASE_ADDRESS + 0x84)))
#define RCC_DCKCFGR					(*((volatile u32*)(MRCC_BASE_ADDRESS + 0x8C)))


#endif /* MRCC_PRIVATE_H_ */

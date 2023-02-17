/*
 * MSTK_Private.h
 *
 *  Created on: Feb 7, 2023
 *      Author: Ahmed Khaled Hammad
 */

#ifndef MSTK_PRIVATE_H_
#define MSTK_PRIVATE_H_

#define STK_BASE_ADDRESS 0xE000E010

typedef struct
{
	volatile u32 CTRL   ;
	volatile u32 LOAD   ;
	volatile u32 VAL    ;
	volatile u32 CALIB  ;

}STK_t;

#define MSTK             (( STK_t *)(STK_BASE_ADDRESS))



#endif /* MSTK_PRIVATE_H_ */

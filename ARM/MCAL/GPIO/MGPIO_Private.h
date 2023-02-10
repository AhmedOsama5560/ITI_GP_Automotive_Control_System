/*
 * MGPIO_Private.h
 *
 *  Created on: Feb 7, 2023
 *      Author: cm
 */

#ifndef MGPIO_PRIVATE_H_
#define MGPIO_PRIVATE_H_

#include "LSTD_TYPES.h"

/*=================================================================================
	-----> Macros
			*  Base_Address GPI0x
=================================================================================*/

#define Base_Address_GPIOA 0x40020000
#define Base_Address_GPIOB 0x40020400
#define Base_Address_GPIOC 0x40020800
/*=================================================================================*/

/*================================================================
	-)Struct : General Purpose I/O
=================================================================*/

typedef struct
{

	 volatile u32 MODER;
	 volatile u32 OTYPER;
	 volatile u32 OSPEEDR;
	 volatile u32 PUPDR;
	 volatile u32 IDR;
	 volatile u32 ODR;
	 volatile u32 BSRR;
	 volatile u32 LCKR;
	 volatile u32 AFRL;
	 volatile u32 AFRH;

}GPI0x_t;

/*================================================================
	-)Struct Macros :
			*  Base_Address GPIOA
=================================================================*/

#define MGPIOA ((GPI0x_t*)(Base_Address_GPIOA))


/*================================================================
	-)Struct Macros :
			*  Base_Address GPIOB
=================================================================*/
#define MGPIOB ((GPI0x_t*)(Base_Address_GPIOB))

/*================================================================
	-)Struct Macros :
			*  Base_Address GPIOC
=================================================================*/
#define MGPIOC ((GPI0x_t*)(Base_Address_GPIOC))

#endif /* MGPIO_PRIVATE_H_ */

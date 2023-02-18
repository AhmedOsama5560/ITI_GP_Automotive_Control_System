/*
   Author : Mahinar Ashraf
   Date   : 9-2-2022
   Version: V1
*/

/*===============================================================================================

*	 - Developer can't Edit in it    
*	  - Register _ Defination		
*	  - Design : 
					- #define	:	YES
					- Union		:	NO
					- Struct	:	YES
					
===================================================================================================*/

/*=====================================================================================
===================    guard of file will call on time in .c	    ===================
=======================================================================================*/ 

#ifndef SYSCFG_PRIVATE_H
#define SYSCFG_PRIVATE_H 

/*======================EXIT_BASE_ADDRESS=====================*/


#define SYSCFG_BASE_ADDRESS   0x40013800

/*======================SYSCFG_STRUCT_REGISTER=====================*/
typedef struct 
{
	volatile u32 MEMRMP;
	volatile u32 PMC;
	volatile u32 EXTICR[4];
	volatile u32 CMPCR;

}SYSCFG_t;

#define SYSCFG ((SYSCFG_t*)(SYSCFG_BASE_ADDRESS))


#endif

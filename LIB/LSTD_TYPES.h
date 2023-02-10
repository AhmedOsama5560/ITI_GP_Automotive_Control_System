/*******************************************************************************************************/
/* Author            : Kholoud Khaled                                                                  */
/* Version           : V0.0.0                                                                          */
/* Data              : 2 - 2 - 2023                                                                    */
/* Description       : LSTD_TYPES.h                                                                    */
/*******************************************************************************************************/


#ifndef LSTD_TYPES_H_
#define LSTD_TYPES_H_

/*******************************************************************************************************/
/*                                           BOOLEAN VALUES	     	                                   */       
/********************************************************************************************************/

	#ifndef FALSE
	#define FALSE  (0u)
	#endif

	#ifndef TRUE
	#define TRUE  (1u)
	#endif

	typedef unsigned char            u8;
	typedef signed char              s8;

	typedef unsigned short int  	 u16;
	typedef signed short int    	 s16;

	typedef unsigned long int   	 u32;
	typedef signed long int      	 s32;

    typedef unsigned long long int 	 u64;
	typedef signed long long int     s64;

	typedef float                 	f32;
	typedef double                	f64;
	typedef long double           	f128;

	typedef unsigned long long    	u132;
	typedef signed long long      	s132;

	/*NULL is void pointer*/
	#ifndef NULL
	#define NULL   (void*)0
	#endif
	
	
#endif /* LSTD_TYPES_H_ */

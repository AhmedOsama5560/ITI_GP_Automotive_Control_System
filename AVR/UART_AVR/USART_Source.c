/*
 * USART_Source.c
 *
 *  Created on: Jan 26, 2023
 *      Author: user
 */


#include "../../SERVICE/std_types.h"
#include "../../SERVICE/bit_math.h"
#include "USART_Interface.h"
#include "USART_Config.h"
#include "USART_Private.h"

#define USART_TX_READY		5
#define USART_TX_COMPLETE	6
#define USART_RX_COMPLETE	7

uint16 Global_u16TxBuffer ;
uint16 Global_u16RxBuffer ;

static void USART_vInterruptEnable ( uint8 Copy_u8InterruptSource )
{
	__asm__ __volatile__ ( "sei" ) ;
	SET_BIT ( USART_CTRL_STATUS_B_REGISTER , Copy_u8InterruptSource ) ;
}
static void USART_vInterruptDisable ( uint8 Copy_u8InterruptSource )
{
	CLR_BIT ( USART_CTRL_STATUS_B_REGISTER , Copy_u8InterruptSource ) ;
}

/* Rx Complete ISR */

void (*RX_COMPLETE_ISR)(void) ;
void __vector_13 (void) __attribute__ ((signal , used , externally_visible ));
void __vector_13 (void)
{
	USART_vInterruptDisable ( USART_RX_COMPLETE ) ;

	#if USART_DATA_SIZE_9_BITS == 1

		if ( 1 == GET_BIT ( USART_CTRL_STATUS_B_REGISTER , USART_RX_9TH_DATABIT_BIT ) )
		{
			SET_BIT ( Global_u16RxBuffer , 8 ) ;
		}
		else
		{
			CLR_BIT ( Global_u16RxBuffer , 8 ) ;
		}

	#endif

	//Global_u16RxBuffer |= USART_DATA_REGISTER ;
	Global_u16RxBuffer = USART_DATA_REGISTER ;
	if ( RX_COMPLETE_ISR != NULL )
	{
		RX_COMPLETE_ISR();
	}
}


/* Tx Ready ISR */

void (*TX_READY_ISR)(void) ;
void __vector_14 (void) __attribute__ ((signal , used , externally_visible ));
void __vector_14 (void)
{
	USART_vInterruptDisable ( USART_TX_READY ) ;
	if ( TX_READY_ISR != NULL )
	{
		TX_READY_ISR();
	}
}

/* Tx Complete ISR */

void (*TX_COMPLETE_ISR)(void) ;
void __vector_15 (void) __attribute__ ((signal , used , externally_visible ));
void __vector_15 (void)
{
	USART_vInterruptDisable ( USART_TX_COMPLETE ) ;
	if ( TX_COMPLETE_ISR != NULL )
	{
		TX_COMPLETE_ISR();
	}
}


uint8 USART_u8Init ( void )
{
	uint8 errState = 0 ;
	uint16 Local_u16UBRRVal ;
	uint8 Local_u8UCSRCVal = 128 ;

	#if USART_TX_ENABLE == 1

		SET_BIT ( USART_CTRL_STATUS_B_REGISTER , USART_TX_ENABLE_BIT ) ;

	#endif

	#if USART_RX_ENABLE == 1

		SET_BIT ( USART_CTRL_STATUS_B_REGISTER , USART_RX_ENABLE_BIT ) ;

	#endif


	//USART_SELECT_UCSRC ;

	#if USART_SYNC_MODE == 0

		CLR_BIT ( Local_u8UCSRCVal , USART_MODE_SELECT_BIT ) ;
		CLR_BIT ( Local_u8UCSRCVal , USART_SYNC_CLOCK_POL_BIT ) ;

		#if USART_ASYNC_SPEED_X2_MODE == 0

			CLR_BIT ( USART_CTRL_STATUS_A_REGISTER , USART_ASYNC_SPEED_X2_MODE ) ;

		#else

			SET_BIT ( USART_CTRL_STATUS_A_REGISTER , USART_ASYNC_SPEED_X2_MODE ) ;

		#endif

	#else

		SET_BIT ( Local_u8UCSRCVal , USART_MODE_SELECT_BIT ) ;
		CLR_BIT ( USART_CTRL_STATUS_A_REGISTER , USART_ASYNC_SPEED_X2_MODE ) ;

		#if USART_SYNC_CLOCK_POLARITY == USART_TX_RISING_RX_FALLING

			CLR_BIT ( Local_u8UCSRCVal , USART_SYNC_CLOCK_POL_BIT ) ;

		#elif USART_SYNC_CLOCK_POLARITY == USART_TX_FALLING_RX_RISING

			SET_BIT ( Local_u8UCSRCVal , USART_SYNC_CLOCK_POL_BIT ) ;

		#endif

	#endif


	#if USART_DATA_SIZE_5_BITS == 1

		CLR_BIT ( Local_u8UCSRCVal , USART_DATA_SIZE_BIT0 ) ;
		CLR_BIT ( Local_u8UCSRCVal , USART_DATA_SIZE_BIT1 ) ;
		CLR_BIT ( USART_CTRL_STATUS_B_REGISTER , USART_DATA_SIZE_BIT2 ) ;

	#elif USART_DATA_SIZE_6_BITS == 1

		SET_BIT ( Local_u8UCSRCVal , USART_DATA_SIZE_BIT0 ) ;
		CLR_BIT ( Local_u8UCSRCVal , USART_DATA_SIZE_BIT1 ) ;
		CLR_BIT ( USART_CTRL_STATUS_B_REGISTER , USART_DATA_SIZE_BIT2 ) ;

	#elif USART_DATA_SIZE_7_BITS == 1

		CLR_BIT ( Local_u8UCSRCVal , USART_DATA_SIZE_BIT0 ) ;
		SET_BIT ( Local_u8UCSRCVal , USART_DATA_SIZE_BIT1 ) ;
		CLR_BIT ( USART_CTRL_STATUS_B_REGISTER , USART_DATA_SIZE_BIT2 ) ;

	#elif USART_DATA_SIZE_8_BITS == 1

		SET_BIT ( Local_u8UCSRCVal , USART_DATA_SIZE_BIT0 ) ;
		SET_BIT ( Local_u8UCSRCVal , USART_DATA_SIZE_BIT1 ) ;
		CLR_BIT ( USART_CTRL_STATUS_B_REGISTER , USART_DATA_SIZE_BIT2 ) ;

	#elif USART_DATA_SIZE_9_BITS == 1

		SET_BIT ( Local_u8UCSRCVal , USART_DATA_SIZE_BIT0 ) ;
		SET_BIT ( Local_u8UCSRCVal , USART_DATA_SIZE_BIT1 ) ;
		SET_BIT ( USART_CTRL_STATUS_B_REGISTER , USART_DATA_SIZE_BIT2 ) ;

	#endif


	#if USART_STOP_BITS_2_BITS == 0

		CLR_BIT ( Local_u8UCSRCVal , USART_STOP_BITS_SEL_BIT ) ;

	#else

		SET_BIT ( Local_u8UCSRCVal , USART_STOP_BITS_SEL_BIT ) ;

	#endif

	#if USART_NO_PARITY_MODE == 1

		CLR_BIT ( Local_u8UCSRCVal , USART_PARITY_MODE_SEL_BIT0 ) ;
		CLR_BIT ( Local_u8UCSRCVal , USART_PARITY_MODE_SEL_BIT1 ) ;

	#elif USART_EVEN_PARITY_MODE == 1

		CLR_BIT ( Local_u8UCSRCVal , USART_PARITY_MODE_SEL_BIT0 ) ;
		SET_BIT ( Local_u8UCSRCVal , USART_PARITY_MODE_SEL_BIT1 ) ;

	#elif USART_ODD_PARITY_MODE == 1

		SET_BIT ( Local_u8UCSRCVal , USART_PARITY_MODE_SEL_BIT0 ) ;
		SET_BIT ( Local_u8UCSRCVal , USART_PARITY_MODE_SEL_BIT1 ) ;

	#else

		errState = 1 ;

	#endif

	// Test
	USART_CTRL_STATUS_C_REGISTER = Local_u8UCSRCVal ;


	//USART_SELECT_UBBRH ;

	#if USART_SYNC_MODE == 0

		#if USART_ASYNC_SPEED_X2_MODE == 0

			Local_u16UBRRVal = CPU_FREQUENCY / ( 16UL * USART_BAUD_RATE ) - 1 ;

		#else

			Local_u16UBRRVal = CPU_FREQUENCY / ( 8 * USART_BAUD_RATE ) - 1 ;

		#endif

	#else

		#if USART_SYNC_MASTER_MODE == 1

			Local_u16UBRRVal = CPU_FREQUENCY / ( 2 * USART_BAUD_RATE ) - 1 ;

		#endif

	#endif

	USART_BAUD_RATE_LOW_REGISTER = (uint8) Local_u16UBRRVal ;
	USART_BAUD_RATE_HIGH_REGISTER = Local_u16UBRRVal >> 8 ;




	return errState ;
}
uint8 USART_u8SyncSendChar ( uint16 Copy_u16Character )
{
	uint8 errState = 0 ;

	#if USART_DATA_SIZE_9_BITS == 1

		if ( 1 == GET_BIT ( Copy_u16Character , 8 ) )
		{
			SET_BIT ( USART_CTRL_STATUS_B_REGISTER , USART_TX_9TH_DATABIT_BIT ) ;
		}
		else
		{
			CLR_BIT ( USART_CTRL_STATUS_B_REGISTER , USART_TX_9TH_DATABIT_BIT ) ;
		}

	#endif

	USART_DATA_REGISTER = ( uint8 ) Copy_u16Character ;

	while ( 0 == GET_BIT ( USART_CTRL_STATUS_A_REGISTER , USART_TX_BUFFER_EMPTY_BIT ) ) ;

	return errState ;
}
uint8 USART_u8SyncReceiveChar ( uint16 * Copy_u16pCharacter )
{
	uint8 errState = 0 ;

	while ( 0 == GET_BIT ( USART_CTRL_STATUS_A_REGISTER , USART_RX_COMPLETE_BIT ) ) ;

	if ( 1 == GET_BIT ( USART_CTRL_STATUS_A_REGISTER , USART_PARITY_ERROR_BIT ) )
	{
		errState = 1 ;
	}
	else if ( 1 == GET_BIT ( USART_CTRL_STATUS_A_REGISTER , USART_OVERRUN_ERROR_BIT ) )
	{
		errState = 2 ;
	}
	else if ( 1 == GET_BIT ( USART_CTRL_STATUS_A_REGISTER , USART_FRAME_ERROR_BIT ) )
	{
		errState = 3 ;
	}
	else
	{

		#if USART_DATA_SIZE_9_BITS == 1

			if ( 1 == GET_BIT ( USART_CTRL_STATUS_B_REGISTER , USART_RX_9TH_DATABIT_BIT ) )
			{
				SET_BIT ( * Copy_u16pCharacter , 8 ) ;
			}
			else
			{
				CLR_BIT ( * Copy_u16pCharacter , 8 ) ;
			}

		#endif

		* Copy_u16pCharacter |= USART_DATA_REGISTER ;
	}

	return errState ;
}
uint8 USART_u8AsyncSendChar ( void (*onCompletionRoutine) (void) )
{
	uint8 errState = 0 ;

	#if USART_DATA_SIZE_9_BITS == 1

		if ( 1 == GET_BIT ( Global_u16TxBuffer , 8 ) )
		{
			SET_BIT ( USART_CTRL_STATUS_B_REGISTER , USART_TX_9TH_DATABIT_BIT ) ;
		}
		else
		{
			CLR_BIT ( USART_CTRL_STATUS_B_REGISTER , USART_TX_9TH_DATABIT_BIT ) ;
		}

	#endif

	USART_DATA_REGISTER = ( uint8 ) Global_u16TxBuffer ;

	TX_COMPLETE_ISR = onCompletionRoutine ;

	USART_vInterruptEnable ( USART_TX_COMPLETE ) ;

	return errState ;
}
uint8 USART_u8AsyncReceiveChar ( void (*onCompletionRoutine) (void) )
{
	uint8 errState = 0 ;

	RX_COMPLETE_ISR = onCompletionRoutine ;

	USART_vInterruptEnable ( USART_RX_COMPLETE ) ;

	return errState ;
}

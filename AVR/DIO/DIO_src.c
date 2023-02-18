#include "../../SERVICE/std_types.h"
#include "../../SERVICE/bit_math.h"


#include "DIO_int.h"
#include "DIO_private.h"
#include "DIO_config.h"


/* DIO_u8SetPortDir Implementation */
#if DIO_U8_SET_PORT_DIR_USED == 1
ErrorState_t DIO_u8SetPortDir ( PortId_t u8PortIdCopy , uint8 u8PortDirCopy )
{
	ErrorState_t errorState = E_OK ;
	volatile uint8 *u8pPortDirRegAddr[4] = { PORT_A_DIR_REG , PORT_B_DIR_REG , PORT_C_DIR_REG , PORT_D_DIR_REG } ;

	if ( u8PortIdCopy >= 0 && u8PortIdCopy <= 3 )
	{
		* u8pPortDirRegAddr [ u8PortIdCopy ] = u8PortDirCopy ;
	}
	else
	{
		errorState = E_NOK ;
	}

	return errorState ;
}
#endif

/* DIO_u8SetPortVal Implementation */
#if DIO_U8_SET_PORT_VAL_USED == 1
ErrorState_t DIO_u8SetPortVal ( PortId_t u8PortIdCopy , uint8 u8PortValCopy )
{
	ErrorState_t errorState = E_OK ;
	volatile uint8 *u8pPortOutRegAddr[4] = { PORT_A_OUT_REG , PORT_B_OUT_REG , PORT_C_OUT_REG , PORT_D_OUT_REG } ;

	if ( u8PortIdCopy >= 0 && u8PortIdCopy <= 3 )
	{
		* u8pPortOutRegAddr [ u8PortIdCopy ] = u8PortValCopy ;
	}
	else
	{
		errorState = E_NOK ;
	}

	return errorState ;
}
#endif


/* DIO_u8GetPortDir Implementation */
#if DIO_U8_GET_PORT_VAL_USED == 1
ErrorState_t DIO_u8GetPortVal ( PortId_t u8PortIdCopy , uint8 * u8pPortValCopy )
{
	ErrorState_t errorState = E_OK ;
	volatile uint8 *u8pPortInRegAddr[4] = { PORT_A_IN_REG , PORT_B_IN_REG , PORT_C_IN_REG , PORT_D_IN_REG } ;

	if ( u8PortIdCopy >= 0 && u8PortIdCopy <= 3 )
	{
		* u8pPortValCopy = * u8pPortInRegAddr [ u8PortIdCopy ] ;
	}
	else
	{
		errorState = E_NOK ;
	}


	return errorState ;
}
#endif

#if DIO_U8_ENABLE_PORT_PULLUP_USED == 1
ErrorState_t DIO_u8EnablePortPullup ( PortId_t u8PortIdCopy )
{
	ErrorState_t errorState = E_OK ;
	volatile uint8 *u8pPortDirRegAddr[4] = { PORT_A_DIR_REG , PORT_B_DIR_REG , PORT_C_DIR_REG , PORT_D_DIR_REG } ;
	volatile uint8 *u8pPortOutRegAddr[4] = { PORT_A_OUT_REG , PORT_B_OUT_REG , PORT_C_OUT_REG , PORT_D_OUT_REG } ;
	uint8 i ;
	if ( u8PortIdCopy >= 0 && u8PortIdCopy <= 3 )
	{
		for ( i = 0 ; i < 8 ; i++ )
		{
			if ( 0 == GET_BIT ( * u8pPortDirRegAddr [ u8PortIdCopy ] , i ) )
			{
				SET_BIT ( * u8pPortOutRegAddr [ u8PortIdCopy ] , i ) ;
			}
			else
			{
				// Nothing
			}
		}
	}
	else
	{
		errorState = E_NOK ;
	}

	return errorState ;
}
#endif


/* DIO_u8SetPinDir Implementation */
#if DIO_U8_SET_PIN_DIR_USED == 1
ErrorState_t DIO_u8SetPinDir ( PortId_t u8PortIdCopy , PinId_t u8PinIdCopy , PinDir_t u8PinDirCopy )
{
	ErrorState_t errorState = E_OK ;
	volatile uint8 *u8pPortDirRegAddr[4] = { PORT_A_DIR_REG , PORT_B_DIR_REG , PORT_C_DIR_REG , PORT_D_DIR_REG } ;

	if ( u8PortIdCopy >= 0 && u8PortIdCopy <= 3 )
	{
		if ( u8PinIdCopy >= 0 && u8PinIdCopy <= 7 )
		{
			if ( INPUT == u8PinDirCopy )
			{
				CLR_BIT ( * u8pPortDirRegAddr [ u8PortIdCopy ] , u8PinIdCopy ) ;
			}
			else if ( OUTPUT == u8PinDirCopy )
			{
				SET_BIT ( * u8pPortDirRegAddr [ u8PortIdCopy ] , u8PinIdCopy ) ;
			}
			else
			{
				errorState = E_NOK ;
			}

		}
	}
	else
	{
		errorState = E_NOK ;
	}


	return errorState ;
}
#endif


#if DIO_U8_SET_PIN_VAL_USED == 1
ErrorState_t DIO_u8SetPinVal ( PortId_t u8PortIdCopy , PinId_t u8PinIdCopy , PinVal_t u8PinValCopy )
{
	ErrorState_t errorState = E_OK ;
	volatile uint8 *u8pPortOutRegAddr[4] = { PORT_A_OUT_REG , PORT_B_OUT_REG , PORT_C_OUT_REG , PORT_D_OUT_REG } ;

	if ( u8PortIdCopy >= 0 && u8PortIdCopy <= 3 )
	{
		if ( u8PinIdCopy >= 0 && u8PinIdCopy <= 7 )
		{
			if ( LOW == u8PinValCopy )
			{
				CLR_BIT ( * u8pPortOutRegAddr [ u8PortIdCopy ] , u8PinIdCopy ) ;
			}
			else if ( HIGH == u8PinValCopy )
			{
				SET_BIT ( * u8pPortOutRegAddr [ u8PortIdCopy ] , u8PinIdCopy ) ;
			}
			else if ( TOGGLE == u8PinValCopy )
			{
				TGL_BIT ( * u8pPortOutRegAddr [ u8PortIdCopy ] , u8PinIdCopy ) ;
			}
			else
			{
				errorState = E_NOK ;
			}

		}
	}
	else
	{
		errorState = E_NOK ;
	}


	return errorState ;
}
#endif


#if DIO_U8_GET_PIN_VAL_USED == 1
ErrorState_t DIO_u8GetPinVal ( PortId_t u8PortIdCopy , PinId_t u8PinIdCopy , uint8 * u8pPinValCopy )
{
	ErrorState_t errorState = E_OK ;
	volatile uint8 *u8pPortInRegAddr[4] = { PORT_A_IN_REG , PORT_B_IN_REG , PORT_C_IN_REG , PORT_D_IN_REG } ;

	if ( u8PortIdCopy >= 0 && u8PortIdCopy <= 3 )
	{
		if ( u8PinIdCopy >= 0 && u8PinIdCopy <= 7 )
		{
			* u8pPinValCopy = GET_BIT ( * u8pPortInRegAddr [ u8PortIdCopy ] , u8PinIdCopy ) ;
		}
	}
	else
	{
		errorState = E_NOK ;
	}

	return errorState ;
}
#endif

#if DIO_U8_ENABLE_PIN_PULLUP_USED == 1
ErrorState_t DIO_u8EnablePinPullup ( PortId_t u8PortIdCopy , PinId_t u8PinIdCopy )
{
	ErrorState_t errorState = E_OK ;
	volatile uint8 *u8pPortDirRegAddr[4] = { PORT_A_DIR_REG , PORT_B_DIR_REG , PORT_C_DIR_REG , PORT_D_DIR_REG } ;
	volatile uint8 *u8pPortOutRegAddr[4] = { PORT_A_OUT_REG , PORT_B_OUT_REG , PORT_C_OUT_REG , PORT_D_OUT_REG } ;

	if ( u8PortIdCopy >= 0 && u8PortIdCopy <= 3 )
	{
		if ( u8PinIdCopy >= 0 && u8PinIdCopy <= 7 )
		{
			if ( 0 == GET_BIT ( * u8pPortDirRegAddr [ u8PortIdCopy ] , u8PinIdCopy ) )
			{
				SET_BIT ( * u8pPortOutRegAddr [ u8PortIdCopy ] , u8PinIdCopy ) ;
			}
			else
			{
				// Nothing
			}
		}
	}
	else
	{
		errorState = E_NOK ;
	}

	return errorState ;
}
#endif

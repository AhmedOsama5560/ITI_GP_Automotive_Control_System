#ifndef DIO_INT_H_
#define DIO_INT_H_


typedef enum { PORT_A , PORT_B , PORT_C , PORT_D } PortId_t ;
typedef enum { PIN_0 , PIN_1 , PIN_2 , PIN_3 ,PIN_4 , PIN_5 , PIN_6 , PIN_7 } PinId_t ;
typedef enum { INPUT , OUTPUT } PinDir_t ;
typedef enum { LOW , HIGH , TOGGLE } PinVal_t ;


/*
 * Function 	: Set direction of port
 * Parameters 	: Port Id , i/p , o/p combination
 * Return 		: Error state
 */
ErrorState_t DIO_u8SetPortDir ( PortId_t u8PortIdCopy , uint8 u8PortDirCopy ) ;


/*
 * Function		: Set output value of port
 * Parameters	: Port Id , o/p combination
 * Return		: Error state
 */
ErrorState_t DIO_u8SetPortVal ( PortId_t u8PortIdCopy , uint8 u8PortValCopy ) ;


/*
 * Function		: Get value of port
 * Parameters	: Port Id , Address of target variable to store port value
 * Return 		: Error state
 */
ErrorState_t DIO_u8GetPortVal ( PortId_t u8PortIdCopy , uint8 * u8pPortValCopy ) ;



ErrorState_t DIO_u8EnablePortPullup ( PortId_t u8PortIdCopy ) ;


/*
 * Function 	: Set direction of pin
 * Parameters 	: Port Id , Pin Id , state ( Input / Output )
 * Return 		: Error state
 */
ErrorState_t DIO_u8SetPinDir ( PortId_t u8PortIdCopy , PinId_t u8PinIdCopy , PinDir_t u8PinDirCopy ) ;


/*
 * Function		: Set output value of pin
 * Parameters	: Port Id , Pin Id , state ( High / Low / Toggle )
 * Return		: Error state
 */
ErrorState_t DIO_u8SetPinVal ( PortId_t u8PortIdCopy , PinId_t u8PinIdCopy , PinVal_t u8PinValCopy ) ;


/*
 * Function		: Get value of pin
 * Parameters	: Port Id , Pin Id  , Address of target variable to store pin value
 * Return 		: Error state
 */
ErrorState_t DIO_u8GetPinVal ( PortId_t u8PortIdCopy , PinId_t u8PinIdCopy , uint8 * u8pPinValCopy ) ;


ErrorState_t DIO_u8EnablePinPullup ( PortId_t u8PortIdCopy , PinId_t u8PinIdCopy ) ;
#endif /* DIO_INT_H_ */

/*
 * USART_Private.h
 *
 *  Created on: Jan 26, 2023
 *      Author: user
 */

#ifndef MCAL_USART_USART_PRIVATE_H_
#define MCAL_USART_USART_PRIVATE_H_

#define		IO_REGISTER(Addr)				*((volatile uint8*)(Addr))

#define		USART_DATA_REGISTER				IO_REGISTER ( 0x2C )

#define		USART_CTRL_STATUS_A_REGISTER	IO_REGISTER ( 0x2B )
#define		USART_MULTI_PROCESSOR_MODE_BIT	0
#define		USART_DOUBLE_SPEED_MODE_BIT		1
#define		USART_PARITY_ERROR_BIT			2
#define		USART_OVERRUN_ERROR_BIT			3
#define		USART_FRAME_ERROR_BIT			4
#define		USART_TX_BUFFER_EMPTY_BIT		5
#define		USART_TX_COMPLETE_BIT			6
#define		USART_RX_COMPLETE_BIT			7

#define		USART_CTRL_STATUS_B_REGISTER	IO_REGISTER ( 0x2A )
#define		USART_TX_9TH_DATABIT_BIT		0
#define		USART_RX_9TH_DATABIT_BIT		1
#define		USART_DATA_SIZE_BIT2			2
#define		USART_TX_ENABLE_BIT				3
#define		USART_RX_ENABLE_BIT				4
#define		USART_TX_READY_INTR_BIT			5
#define		USART_TX_COMPLETE_INTR_BIT		6
#define		USART_RX_COMPLETE_INTR_BIT		7

#define		USART_CTRL_STATUS_C_REGISTER	IO_REGISTER ( 0x40 )
#define		USART_SYNC_CLOCK_POL_BIT		0
#define		USART_DATA_SIZE_BIT0			1
#define		USART_DATA_SIZE_BIT1			2
#define		USART_STOP_BITS_SEL_BIT			3
#define		USART_PARITY_MODE_SEL_BIT0		4
#define		USART_PARITY_MODE_SEL_BIT1		5
#define		USART_MODE_SELECT_BIT			6
#define		USART_REGISTER_SELECT_BIT		7


#define		USART_BAUD_RATE_HIGH_REGISTER	IO_REGISTER ( 0x40 )
#define		USART_BAUD_RATE_LOW_REGISTER	IO_REGISTER ( 0x29 )

#define		USART_SELECT_UCSRC				SET_BIT ( USART_CTRL_STATUS_C_REGISTER , USART_REGISTER_SELECT_BIT ) ;
#define		USART_SELECT_UBBRH				CLR_BIT ( USART_CTRL_STATUS_C_REGISTER , USART_REGISTER_SELECT_BIT ) ;

#endif /* MCAL_USART_USART_PRIVATE_H_ */

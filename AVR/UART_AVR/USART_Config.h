/*
 * USART_Config.h
 *
 *  Created on: Jan 26, 2023
 *      Author: user
 */

#ifndef MCAL_USART_USART_CONFIG_H_
#define MCAL_USART_USART_CONFIG_H_

/* MCU Clock Frequency */
#define		CPU_FREQUENCY					8000000UL

/* USART Transmitter Enable */
#define		USART_TX_ENABLE					1

/* USART Receiver Enable */
#define		USART_RX_ENABLE					1

/* USART Synchronous or Asynchronous Mode Select */
#define		USART_SYNC_MODE					0

/* USART Synchronous Master Mode */
#define		USART_SYNC_MASTER_MODE			1

/* USART Synchronous Clock Polarity Mode Select */
#define		USART_TX_RISING_RX_FALLING		1
#define		USART_TX_FALLING_RX_RISING		2
#define		USART_SYNC_CLOCK_POLARITY		USART_TX_RISING_RX_FALLING

/* USART Baud Rate Select */
#define		USART_BAUD_RATE					9600

/* USART Multiprocessor Mode Select */
#define		USART_MUTLIPROCESSOR_MODE		0

/* USART Asynchronous Double Speed Mode Select */
#define		USART_ASYNC_SPEED_X2_MODE		0

/* USART Data Size Select */
#define		USART_DATA_SIZE_5_BITS			0
#define		USART_DATA_SIZE_6_BITS			0
#define		USART_DATA_SIZE_7_BITS			0
#define		USART_DATA_SIZE_8_BITS			1
#define		USART_DATA_SIZE_9_BITS			0

/* USART Stop Bits Select */
#define		USART_STOP_BITS_2_BITS			0

/* USART Parity Bits Select */
#define		USART_NO_PARITY_MODE			1
#define		USART_EVEN_PARITY_MODE			0
#define		USART_ODD_PARITY_MODE			0

#endif /* MCAL_USART_USART_CONFIG_H_ */

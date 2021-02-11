/************************************************************************************************
 *  File Name : uart.h																			*
 *  Created on : Jan 16, 2020																	*
 *      Author : Mohamad																		*
 ************************************************************************************************/

#ifndef UART_H_
#define UART_H_

#include <avr/io.h>
#include "std_types.h"
#include "common_macros.h"
/************************************************************************************************
 * 					defining macro for the UART Baudrate factor									*
 * 					if not defined by the user.													*
 ************************************************************************************************/
#ifndef UART_BAUD_RATE
#define UART_BAUD_RATE 9600U
#endif
/************************************************************************************************
 * 					Declaring a data type used to handle dynamic configurations					*
 * 					taken from the user.														*
 ************************************************************************************************/
typedef enum {
	ASYNCHRONOUS_U, SYNCHRONOUS_U
} UART_MODE;
typedef enum {
	NO_PARITY, EVEN_PARITY, ODD_PARITY
} UART_PARITY;
typedef enum {
	UART_DISABLED, UART_TRANSMIT, UART_RECEIVE, UART_TRANSMIT_RECEIVE
} UART_TXRX;
typedef struct {
	UART_MODE mode;
} uart_ConfigData;
/************************************************************************************************
 * 					declaring all functions prototypes used in the driver						*
 ************************************************************************************************/
void uart_init(void);
void uart_sendByte(uint8 a_data);
uint8 uart_receiveByte(void);
void uart_sendString(const uint8* a_string);
void uart_receiveString(uint8* a_string);

#endif /* UART_H_ */

/************************************************************************************************
 * 	 File Name : uart.c																			*
 *  Created on : Jan 16, 2020																	*
 *      Author : Mohamad																		*
 ************************************************************************************************/
#include "uart.h"

void uart_init(void) {
	/********************************************************************************************
	 * 	Step: pseudo code for UART driver														*
	 * 	1- Calculate the Baudrate register value depending on CPU frequency and given baudrate	*
	 * 	2-	initializing UART on 2x transmission speed											*
	 * 	3-	Enabling UART on both Transmission and Reception									*
	 * 	4-	Setting the UART character size to 8-bit character									*
	 * 	5-	Setting the value for UBRRH to the most significant byte							*
	 * 	6- 	Setting the value for UBRRL to the least significant byte							*
	 ********************************************************************************************/
	uint16 a_ubrrVal = ((F_CPU / (8 * UART_BAUD_RATE)) - 1);
	UCSRA |= (1 << U2X);
	UCSRB |= (1 << RXEN) | (1 << TXEN); // Enabling both transmission and reception
	UCSRC |= (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0); // setting UART character size on 8-bit and Asynchronous mode
	UBRRH = (a_ubrrVal >> 8);
	UBRRL = a_ubrrVal;

}
void uart_sendByte(uint8 a_data) {
	UDR = a_data; // start sending a byte on UART
	while (!(UCSRA & (1 << TXC)))
		; // polling on until transmit is complete
	SET_BIT(UCSRA, TXC); // clearing TXC flag
}
uint8 uart_receiveByte(void) {

	while (!(UCSRA & (1 << RXC)))
		; // polling on until receiving is complete
	return UDR; // clearing RXC flag and returning the UDR value to the application
}
void uart_sendString(const uint8* a_string) {
	uint8 i = 0;
	while (a_string[i] != '\0') {
		uart_sendByte(a_string[i]);
	}
}
void uart_receiveString(uint8* a_string) {
	uint8 aByte = 0, i = 0;
	aByte = uart_receiveByte();
	while (aByte != '#') {
		a_string[i] = aByte;
		i++;
		aByte = uart_receiveByte();
	}
}

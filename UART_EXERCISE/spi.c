/************************************************************************************************
 * 		 File Name : spi.c																		*
 *  	Created on : Jan 18, 2020																*
 *      	Author : Mohamad																	*
 ************************************************************************************************/

#include "spi.h"
/************************************************************************************************
 * 								Protected global variable of type pointer to function			*
 ************************************************************************************************/
static void (* volatile g_spiBehaviour)(void);
/************************************************************************************************
 * 								All driver functions definitions								*
 ************************************************************************************************/
void SPI_init(SPI_configData* a_data) {

}

void SPI_initMaster(void) {
	/********************************************************************************************
	 * 			Configuring SPI port to set MOSI, SCK and SS pins as output for the slave		*
	 ********************************************************************************************/
	SPI_DDR |= (1 << SPI_MOSI) | (1 << SPI_SCK) | (1 << SPI_SS);
	CLEAR_BIT(SPI_DDR, SPI_MISO); // Setting MISO as input pin
	//SPI_PORT |= (1 << SPI_SS); // initializing slave select bit with one until it takes order
	/********************************************************************************************
	 * 			Configuring SPI module to work as Master										*
	 ********************************************************************************************/
	SPCR = (1 << SPE) | (1 << MSTR); // Enabling SPI and setting the device as master for clock
}

void SPI_initSlave(void) {
	/********************************************************************************************
	 * 			Configuring SPI port to set MOSI, SCK and SS pins as input from the master		*
	 ********************************************************************************************/
	//SET_BIT(SPI_DDR, SPI_MISO); // Setting MISO as output pin
	DDRB = DDRB & (~(1 << PB4));
	DDRB = DDRB & (~(1 << PB5));
	DDRB = DDRB | (1 << PB6);
	DDRB = DDRB & (~(1 << PB7));

	/********************************************************************************************
	 * 			Configuring SPI module to work as Slave											*
	 ********************************************************************************************/
	SET_BIT(SPCR, SPE); // Enabling SPI
}

void SPI_sendByte(const uint8 a_data) {
	SPDR = a_data; // assigning data to SPI data register to start sending it
	while (!(SPSR & (1 << SPIF)))
		; // polling until the data is sent

}

void SPI_sendString(const uint8* a_string) {
	uint8 i = 0;
	while (a_string[i] != '\0') {
		SPI_sendByte(a_string[i]);
		i++;
	}
}

uint8 SPI_receiveByte(void) {

	while (!(SPSR & (1 << SPIF)))
		; // polling until the data is received

	return SPDR;
}

void SPI_receiveString(uint8* a_string) {

	uint8 aByte = 0;
	aByte = SPI_receiveByte();
	while (aByte != '#') {
		(*a_string) = aByte;
		a_string++;
		aByte = SPI_receiveByte();
	}

}
/************************************************************************************************
 * 							SPI functions and ISR for Interrupt mode							*
 ************************************************************************************************/
void SPI_setBehaviour(void (*a_spiBehaviour)(void)) {
	g_spiBehaviour = a_spiBehaviour;
}

ISR(SPI_STC_vect) {
	(*g_spiBehaviour)();
}

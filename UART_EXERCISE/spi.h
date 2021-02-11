/************************************************************************************************
 * 	  	 File Name : spi.h																		*
 *  	Created on : Jan 18, 2020																*
 *      	Author : Mohamad																	*
 ************************************************************************************************/

#ifndef SPI_H_
#define SPI_H_

#include "std_types.h"
#include "common_macros.h"
#include <avr/io.h>
#include <avr/interrupt.h>
/************************************************************************************************
 * 								Defining SPI Module PORT, PIN and DDR							*
 * 								and port pins.													*
 ************************************************************************************************/
#define SPI_PORT PORTB
#define SPI_DDR DDRB
#define SPI_PIN PINB
#define SPI_SS 4
#define SPI_MOSI 5
#define SPI_MISO 6
#define SPI_SCK 7
/************************************************************************************************
 * 								Set SPI_Mode for master and clear it for slave					*
 ************************************************************************************************/
typedef enum {
	Slave, Master
} SPI_Mode;
typedef enum {
	SPINT_DISABLED, SPINT_ENABLED
} SPI_interrupt;
typedef enum {
	SPI_MSB, SPI_LSB
} SPI_dataOrder;
typedef enum {
	SPI_Rising, SPI_Falling
} SPI_clockPolarity;
typedef enum {
	Sample, Setup
} SPI_clockPhase;
typedef enum {
	SPCLCK_4,
	SPCLCK_16,
	SPCLCK_128 = 3,
	SPCLCK_2,
	SPCLCK_8,
	SPCLCK_32,
	SPCLCK_64
} SPI_clockRate;

typedef struct {
	SPI_Mode mode;
	SPI_interrupt intMode;
	SPI_dataOrder order;
	SPI_clockPolarity polarity;
	SPI_clockPhase phase;
	SPI_clockRate rate;
} SPI_configData;
/************************************************************************************************
 *							Declaring all functions prototypes used in the driver				*
 ************************************************************************************************/
void SPI_init(SPI_configData* a_data);
void SPI_initMaster(void);
void SPI_initSlave(void);
void SPI_sendByte(const uint8 a_data);
void SPI_sendString(const uint8* a_string);
uint8 SPI_receiveByte(void);
void SPI_receiveString(uint8* a_string);
void SPI_setBehaviour(void (*a_spiBehaviour)(void));

#endif /* SPI_H_ */

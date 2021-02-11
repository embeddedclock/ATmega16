/************************************************************************************************
 *  File Name : interrupts.h																					*
 *																								*
 * Created on : Jan 7, 2020																		*
 *     Author : Mohamad																			*
 ************************************************************************************************/

#ifndef EXTERNALINTERRUPTS_H_
#define EXTERNALINTERRUPTS_H_
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "std_types.h"
#include "common_macros.h"
/****************************************************************************************************
 * defining macros used in this driver																*
 * INT_NO : defining the number of external interrupts available in the microcontroller used		*
 * INT(N)_PORT : used to define which I/O port contains the external interrupt pin and controls it	*
 * INT(N)_DDR  : used to define which Data direction register to use for setting the interrupt pin	*
 * INT(N)_PIN  : defining the position of the interrupt pin/bit on each I/O port					*
 ****************************************************************************************************/

#define INT_NO 3
#define INT0_PORT PORTD
#define INT0_DDR DDRD
#define INT0_PIN 2
#define INT1_PORT PORTD
#define INT1_DDR DDRD
#define INT1_PIN 3
#define INT2_PORT PORTB
#define INT2_DDR DDRB
#define INT2_PIN 2
/****************************************************************************************************
 * 	defining datatype for data used in this driver													*
 * 	datatype name: eInterruptData																	*
 *	enumeration interruptSelect: selecting between the External interrupts							*
 *	enumeration interruptSignalCapture: determine on which change the interrupt event will happen.	*
 *	interruptPullUp : saving the configuration of internal pullup for the interrupt.				*
 *	eInterruptBehaviour: function pointer to call back the given interrupt functionality.			*
 ****************************************************************************************************/
typedef struct {
	enum {
		eINT0, eINT1, eINT2
	} interruptSelect;
	enum {
		ActiveLowLevel, ActiveAnyChange, ActiveFalling, ActiveRising
	} interruptSignalCapture;
	enum {
		intPupDisabled, intPupEnabled
	} interruptPullUp;
	void (*eInterruptBehaviour)(void);
} eInterruptData;
/************************************************************************************************
 * functions prototypes used in the driver														*
 * function prototype: eInterruptInit takes no parameters and returns void						*
 * eInterruptInit: initializing the selected external interrupt on a user given specifications	*
 ************************************************************************************************/
void eInterruptInit(eInterruptData* a_interruptData);

#endif /* EXTERNALINTERRUPTS_H_ */

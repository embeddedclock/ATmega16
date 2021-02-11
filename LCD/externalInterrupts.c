/************************************************************************************************
 *  file name : interrupts.c																	*
 *  Created on: Jan 7, 2020																		*
 *      Author: Mohamad																			*
 ************************************************************************************************/

#include "externalInterrupts.h"
/************************************************************************************************
 *  Variable name : g_eInterruptBehaviour														*
 *  Variable type : Array of function pointers													*
 *  Variable Functionality : Passing functions' address to specific interrupt service routine	*
 ************************************************************************************************/

static void (*g_eInterruptBehaviour[INT_NO])(void);

/************************************************************************************************
 *  Function name : eInterruptInit																*
 *  Return type : Function returning nothing.													*
 *  Functionality : initializing the interrupts driver on specific configurations				*
 * 	Fun argument(s) quantity : 1																*
 * 	Fun argument(s) type : Pointer to eInterruptData structure									*
 *  Function argument(s) : Pointer to eInterruptData structure contains the user configurations	*
 ************************************************************************************************/

void eInterruptInit(eInterruptData* a_interruptData) {
	/****************************************************************
	 * setting the behaviour to the specific pointer to function	*
	 ****************************************************************/
	g_eInterruptBehaviour[a_interruptData->interruptSelect] =
			a_interruptData->eInterruptBehaviour;
	/************************************************************************
	 * switching between interrupts depending on the given configurations	*
	 ************************************************************************/
	if (eINT0 == a_interruptData->interruptSelect) {
		/********************************************************************************
		 * in this step we are configuring the interrupt sense control of interrupt0	*
		 * as in the given configurations by the user.									*
		 ********************************************************************************/
		a_interruptData->interruptSignalCapture &= 0x03;
		MCUCR = (MCUCR & 0xFD) | (a_interruptData->interruptSignalCapture);

		CLEAR_BIT(INT0_DDR, INT0_PIN); //Setting interrupt0 pin as input by writing logical 0
		SET_BIT(GICR, INT0); // Enabling interrupt0 in the general interrupt control register
		/****************************************************************
		 * Enabling interrupt0											*
		 *  internal pull up resistor depending on user configurations	*
		 ****************************************************************/
		a_interruptData->interruptPullUp &= 0x01;
		if (a_interruptData->interruptPullUp) {
			SET_BIT(INT0_PORT, INT0_PIN);
		}

	} else if (eINT1 == a_interruptData->interruptSelect) {
		/********************************************************************************
		 * in this step we are configuring the interrupt sense control of interrupt1	*
		 * as in the given configurations by the user.									*
		 ********************************************************************************/

		a_interruptData->interruptSignalCapture &= 0x03;

		MCUCR = (MCUCR & 0xF3)
				| ((a_interruptData->interruptSignalCapture) << 2);

		CLEAR_BIT(INT1_DDR, INT1_PIN); //Setting interrupt1 pin as input by writing logical 0
		SET_BIT(GICR, INT1); // Enabling interrupt1 in the general interrupt control register
		/****************************************************************
		 * Enabling interrupt1											*
		 *  internal pull up resistor depending on user configurations	*
		 ****************************************************************/
		a_interruptData->interruptPullUp &= 0x01;
		if (a_interruptData->interruptPullUp) {
			SET_BIT(INT1_PORT, INT1_PIN);
		}

	} else if (eINT2 == a_interruptData->interruptSelect) {
		/********************************************************************************
		 * in this step we are configuring the interrupt sense control of interrupt2	*
		 * as in the given configurations by the user.									*
		 ********************************************************************************/
		a_interruptData->interruptSignalCapture &= 0x01;
		MCUCSR = (MCUCSR & 0xBF)
				| ((a_interruptData->interruptSignalCapture) << ISC2);

		CLEAR_BIT(INT2_DDR, INT2_PIN); //Setting interrupt2 pin as input by writing logical 0
		SET_BIT(GICR, INT2); // Enabling interrupt2 in the general interrupt control register
		/****************************************************************
		 * Enabling interrupt2 											*
		 *  internal pull up resistor depending on user configurations	*
		 ****************************************************************/
		a_interruptData->interruptPullUp &= 0x01;
		if (a_interruptData->interruptPullUp) {
			SET_BIT(INT2_PORT, INT2_PIN);
		}

	}

}
/************************************************************************************************
 *  Interrupt Service routine(s) for the driver to call back a given function					*
 * 																								*
 ************************************************************************************************/
ISR(INT0_vect) {
	(*g_eInterruptBehaviour[eINT0])(); // Calling back the given function for interrupt0
}

ISR(INT1_vect) {
	(*g_eInterruptBehaviour[eINT1])(); // Calling back the given function for interrupt1
}

ISR(INT2_vect) {
	(*g_eInterruptBehaviour[eINT2])(); // Calling back the given function for interrupt2
}


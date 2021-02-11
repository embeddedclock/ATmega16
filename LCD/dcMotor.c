/************************************************************************************************
 *   File Name : dcMotor.c																		*
 *  Created on : Jan 7, 2020																	*
 *      Author : Mohamad																		*
 ************************************************************************************************/

#include "dcMotor.h"

void dcMotorInit(dcMotorData * a_motorData) {
	a_motorData->dcMotorPort &= 0b00000111;
	switch (a_motorData->dcMotorPort) {
	case 0: // PORTA
		SET_BIT(DDRA, a_motorData->dcMotorPin);
		break;
	case 1: // PORTB
		SET_BIT(DDRB, a_motorData->dcMotorPin);
		break;
	case 2: // PORTC
		SET_BIT(DDRC, a_motorData->dcMotorPin);
		break;
	case 3: // PORTD
		SET_BIT(DDRD, a_motorData->dcMotorPin);
		break;
	}
	a_motorData->dcMotorDiPort &= 0b00000111;
	switch (a_motorData->dcMotorDiPort) {
	case 0: // PORTA
		SET_BIT(DDRA, a_motorData->dcMotorDiPin);
		break;
	case 1: // PORTB
		SET_BIT(DDRB, a_motorData->dcMotorDiPin);
		break;
	case 2: // PORTC
		SET_BIT(DDRC, a_motorData->dcMotorDiPin);
		break;
	case 3: // PORTD
		SET_BIT(DDRD, a_motorData->dcMotorDiPin);
		break;
	}

}
void dcMotorRev(dcMotorData * a_motorData) {
	switch (a_motorData->dcMotorDiPort) {
	case 0: // PORTA
		TOGGLE_BIT(PORTA, a_motorData->dcMotorDiPin);
		break;
	case 1: // PORTB
		TOGGLE_BIT(PORTB, a_motorData->dcMotorDiPin);
		break;
	case 2: // PORTC
		TOGGLE_BIT(PORTC, a_motorData->dcMotorDiPin);
		break;
	case 3: // PORTD
		TOGGLE_BIT(PORTD, a_motorData->dcMotorDiPin);
		break;
	}
}
void dcMotorCW(dcMotorData * a_motorData) {

}
void dcMotorCCW(dcMotorData * a_motorData) {

}

/*
 * pushButton.c
 *
 *  Created on: Jan 6, 2020
 *      Author: Mohamad
 */

#include "pushButton.h"

void setPushButton(pushButton* a_pushButton) {

	CLEAR_BIT((*(volatile uint8*)( (a_pushButton->pbPort)-1 + SHIFT)),
			a_pushButton->pbPin); // setting the pin as input pin
	if (1 == a_pushButton->pb_pullupStatus) { //if the internal pull-up resistor is requested
		SET_BIT(PORTA, a_pushButton->pbPin); // Enabling the internal pull-up resistor
	}
}
uint8 readPushButton(pushButton* a_pushButton) {
	uint8 a_currentStatus = 0;
	volatile uint8* a_Port =
			(volatile uint8*) (a_pushButton->pbPort + SHIFT - 2);
	a_currentStatus = (((*a_Port) & (1 << a_pushButton->pbPin))
			>> a_pushButton->pbPin);
	_delay_ms(50);
	if (a_currentStatus
			== (((*a_Port) & (1 << a_pushButton->pbPin)) >> a_pushButton->pbPin)) {
		return a_currentStatus;
	}
	return (((*a_Port) & (1 << a_pushButton->pbPin)) >> a_pushButton->pbPin);
}

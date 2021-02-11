/*
 * led.c
 *
 *  Created on: Jan 7, 2020
 *      Author: Mohamad
 */

#include "led.h"

void setLED(LED* a_LED) {
	*((volatile uint8*) (a_LED->LED_Port) - 1) |= (1 << a_LED->LED_Pin); //setting given LED pin as output

	offLED(a_LED); //setting the LED off as initial value
}
void onLED(LED* a_LED) {
	if (a_LED->LED_Activity == Active_High) {

		SET_BIT((*((volatile uint8* )(a_LED->LED_Port))), a_LED->LED_Pin);
	} else if (a_LED->LED_Activity == Active_Low) {
		CLEAR_BIT((*((volatile uint8* )(a_LED->LED_Port))), a_LED->LED_Pin);
	}
}

void offLED(LED* a_LED) {
	if (a_LED->LED_Activity == Active_High) {

		CLEAR_BIT((*((volatile uint8* )(a_LED->LED_Port))), a_LED->LED_Pin);
	} else if (a_LED->LED_Activity == Active_Low) {
		SET_BIT((*((volatile uint8* )(a_LED->LED_Port))), a_LED->LED_Pin);
	}
}

void toggleLED(LED* a_LED) {
	TOGGLE_BIT((*((volatile uint8* )(a_LED->LED_Port))), a_LED->LED_Pin);
}

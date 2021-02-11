/*
 * led.h
 *
 *  Created on: Jan 7, 2020
 *      Author: Mohamad
 */

#ifndef LED_H_
#define LED_H_

#include "std_types.h"
#include "common_macros.h"
#include "dio.h"

typedef struct {
	enum {
		LPORT_A = 0x3B, LPORT_B = 0x38, LPORT_C = 0x35, LPORT_D = 0x32
	} LED_Port;
	enum {
		LPIN_0, LPIN_1, LPIN_2, LPIN_3, LPIN_4, LPIN_5, LPIN_6, LPIN_7
	} LED_Pin;
	enum {
		Active_Low, Active_High
	} LED_Activity;
} LED;

void setLED(LED* a_LED);
void onLED(LED* a_LED);
void offLED(LED* a_LED);
void toggleLED(LED* a_LED);

#endif /* LED_H_ */

/************************************************************************************************
 *   File Name : dcMotor.h																		*
 *  Created on : Jan 7, 2020																	*
 *      Author : Mohamad																		*
 ************************************************************************************************/

#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#include <avr/io.h>
#include <util/delay.h>
#include "common_macros.h"

typedef struct {
	enum {
		dcMPORTA, dcMPORTB, dcMPORTC, dcMPORTD
	} dcMotorPort;
	enum {
		dcMPin0, dcMPin1, dcMPin2, dcMPin3, dcMPin4, dcMPin5, dcMPin6, dcMPin7
	} dcMotorPin;
	enum {
		mDiPORTA, mDiPORTB, mDiPORTC, mDiPORTD
	} dcMotorDiPort;
	enum {
		mDiPin0, mDiPin1, mDiPin2, mDiPin3, mDiPin4, mDiPin5, mDiPin6, mDiPin7
	} dcMotorDiPin;
} dcMotorData;

void dcMotorInit(dcMotorData * a_motorData);
void dcMotorRev(dcMotorData * a_motorData);
void dcMotorCW(dcMotorData * a_motorData);
void dcMotorCCW(dcMotorData * a_motorData);
#endif /* DCMOTOR_H_ */

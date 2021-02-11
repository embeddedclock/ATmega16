/************************************************************************************************
 *   File Name : pwm.c																			*
 *  Created on : Jan 7, 2020																	*
 *      Author : Mohamad																		*
 ************************************************************************************************/

#include "pwm.h"

/************************************************************************************************
 * FOCnPWM = fclk_I/O / N*256																	*
 * FOCnPWM = the frequency on the pwm pin which is output compare pin to the specified timer	*
 *    fclk = the MCU frequency																	*
 *       N = the prescaler factor form 2 to 1024												*
 ************************************************************************************************/

void pwmInit(pwmConfig * a_pwmConfig) {
	switch (a_pwmConfig->pwmTimer) {
	case 0: // Timer0
		/****************************************************************************************
		 * configuring timer0 to work on fast pwm with clear timer on compare event and set at 0*
		 ****************************************************************************************/
		TCCR0 |= (1 << WGM01) | (1 << WGM00) | (1 << COM01);
		TCNT0 = 0; // starting the count from zero
		OCR0 = (a_pwmConfig->pwmDuty / (float) 100) * (255); // giving the duty cycle to the timer
		pwmStart(a_pwmConfig); // starting pwm on the given configurations
		break;
	case 1: // Timer1
		break;
	case 2: // Timer2
		break;
	}
}

void pwmStart(pwmConfig * a_pwmConfig) {
	switch (a_pwmConfig->pwmTimer) {
	case 0: // Timer0
		a_pwmConfig->pwmPrescaler &= 0b00000111;
		TCCR0 = (TCCR0 & 0xF8) | a_pwmConfig->pwmPrescaler;
		break;
	case 1: // Timer1
		break;
	case 2: // Timer2
		break;
	}
}

void pwmStop(pwmConfig * a_pwmConfig) {
	switch (a_pwmConfig->pwmTimer) {
	case 0: // Timer0
		TCCR0 = (TCCR0 & 0xF8); // Turning off the clock for the timer
		break;
	case 1: // Timer1
		break;
	case 2: // Timer2
		break;
	}
}
void pwmChangeDuty(pwmConfig * a_pwmConfig) {
	switch (a_pwmConfig->pwmTimer) {
	case 0: // Timer0
		OCR0 = (a_pwmConfig->pwmDuty / (float) 100) * (255); // giving the duty cycle to the timer
		break;
	case 1: // Timer1
		break;
	case 2: // Timer2
		break;
	}
}

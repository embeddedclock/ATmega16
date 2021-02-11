/************************************************************************************************
 *   File Name :  pwm.h																		*
 *  Created on : Jan 7, 2020																	*
 *      Author : Mohamad																		*
 ************************************************************************************************/

#ifndef PWM_H_
#define PWM_H_

#include "std_types.h"
#include <avr/io.h>
#include <avr/interrupt.h>

typedef struct {
	enum {
		pwmT0, pwmT1, pwmT2
	} pwmTimer;
	enum {
		pwm_off,
		pwm_1,
		pwm_8,
		pwm_64,
		pwm_256,
		pwm_1024,
		pwm_ExternalFalling,
		pwm_ExternalRising
	} pwmPrescaler;
	uint8 pwmDuty;
} pwmConfig;

void pwmInit(pwmConfig * a_pwmConfig);
void pwmStart(pwmConfig * a_pwmConfig);
void pwmStop(pwmConfig * a_pwmConfig);
void pwmChangeDuty(pwmConfig * a_pwmConfig);
#endif /* PWM_H_ */

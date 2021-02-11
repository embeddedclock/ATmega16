/************************************************************************************************
 *   File Name : main.c																			*
 *  Created on : Dec 28, 2019																	*
 *      Author : Mohamad																		*
 ************************************************************************************************/

//#include "calculator.h"
//#include "std_types.h"
//#include "dio.h"
//#include "pushButton.h"
//#include "led.h"
#include <util/delay.h>
#include "adc.h"
#include "lcd.h"
#include "externalInterrupts.h"
#include "dcMotor.h"
#include "pwm.h"

/************************************************************************************************
 * Variable Name : led1																			*
 * Variable type : LED																			*
 * Variable function : declaring and initializing variable of type LED with led configurations	*
 ************************************************************************************************/
dcMotorData motor1 = { dcMPORTB, dcMPin3, mDiPORTB, mDiPin4 };
pwmConfig pwm1 = { pwmT0, pwm_64, 0 };
void calculate_temperature(uint16 a_analogVal) {
	/*
	 * 0V ----> 0*C
	 * 2V ----> 140*C
	 * 5V ----> 1023
	 * 2V ----> 2/5 * 1023 = 410
	 * 410 --->140*C
	 *  R ----> ??*C
	 *  T = (R/410)*140
	 */
	uint16 temperature = (a_analogVal * 100) / 1023;
	lcd_goToRowColumn(0, 0);
	lcd_integerToString(temperature);
}

void displaySpeed(uint16 a_analogVal) {
	pwm1.pwmDuty = ((float) a_analogVal / 1023) * 100;
	pwmChangeDuty(&pwm1);
	lcd_goToRowColumn(0, 7);
	lcd_integerToString(a_analogVal);
}

void interruptBehaviour(void) {
	dcMotorRev(&motor1);
}
int main(void) {
	ADC_DATA adc1 = { AREF, Enabled, Right, ADC0, _8, &displaySpeed };
	eInterruptData eint0 = { eINT1, ActiveRising, intPupDisabled,
			&interruptBehaviour };

	/****************************************************************************
	 * initializing all drivers for the project depending on user configs		*
	 *
	 ****************************************************************************/
	lcd_init(); //initializing LCD driver
	lcd_displayString("Speed: "); // giving constant string at the beginning of the program
	adc_init(&adc1); //initializing adc on configurations of adc1
	dcMotorInit(&motor1); // setting up a motor on motor1 configurations
	eInterruptInit(&eint0); // initializing external interrupts driver based on eint0 configurations
	pwmInit(&pwm1); // initializing pwm based on pwm1 configurations
	sei();
	//Enabling global interrupts

	while (1) {
		adc_start(&adc1); // starting adc conversion on adc1 configurations
	}
}

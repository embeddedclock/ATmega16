/*
 * calculator.h
 *
 *  Created on: Dec 31, 2019
 *      Author: Mohamad
 */

#ifndef CALCULATOR_H_
#define CALCULATOR_H_
#include <stdlib.h>
#include <util/delay.h>
#include <avr/io.h>

#include "common_macros.h"
#include "std_types.h"
#include "keypad.h"
#include "lcd.h"

#define CALCULATOR(OPERATION,OPERAND1,OPERAND2,RESULT) {\
	switch (OPERATION) {\
			case '*':\
				RESULT = (OPERAND1 * OPERAND2);\
				break;\
			case '+':\
				RESULT = (OPERAND1 + OPERAND2);\
				break;\
			case '-':\
				RESULT = (OPERAND1 - OPERAND2);\
				break;\
			case '/':\
				RESULT = OPERAND1 / OPERAND2;\
				break;\
			default:\
				break;\
			}\
}

void calculatorCalculate(void);

#endif /* CALCULATOR_H_ */

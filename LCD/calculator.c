/*
 * calculator.c
 *
 *  Created on: Dec 31, 2019
 *      Author: Mohamad
 */

#include "calculator.h"

/*
 * declaring all static/protected functions in this driver
 */
void calculatorCalculate(void) {
	uint64 a_result = 0/*, a_mulResult = 0*/;
	uint32 a_operand1 = 0, a_operand2 = 0;
	uint8 keypadCharacter = 0, a_operation = 0;
	while (keypadCharacter != 13) {
		keypadCharacter = keypad_getNumber();
		lcd_displayCharacter(keypadCharacter);
		if (keypadCharacter >= 48 && keypadCharacter <= 57) {
			if (a_operation == 0) {
				a_operand1 = (a_operand1 * 10)
						+ atoi((int8 *) &keypadCharacter);

			} else {
				a_operand2 = (a_operand2 * 10)
						+ atoi((int8 *) &keypadCharacter);

			}

		} else if (keypadCharacter >= 42 && keypadCharacter <= 47) {
			if (0 != a_operation) {
				switch (a_operation) {
				case '+':
					a_operand1 += a_operand2;
					a_operand2 = 0;
					break;
				case '-':
					a_operand1 -= a_operand2;
					a_operand2 = 0;
					break;
				case '*':
					a_operand1 *= a_operand2;
					a_operand2 = 0;
					break;
				case '/':
					a_operand1 /= a_operand2;
					a_operand2 = 0;
					break;
				default:
					break;
				}
			}
			a_operation = keypadCharacter;
		} else if (keypadCharacter == '=') {
			CALCULATOR(a_operation, a_operand1, a_operand2, a_result);
			lcd_integerToString(a_result);

		}
	}
	lcd_clear();

}

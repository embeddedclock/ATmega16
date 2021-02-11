/*
 * Keypad.c
 *
 *  Created on: Dec 29, 2019
 *      Author: Mohamad
 */

#include "keypad.h"
/*
 * private functions prototypes
 */
static uint8 keypad_numberToAscii(uint8 a_KeypadNumber);
/*
 * functions definitions
 */
void keypad_init(void) {
	KEYPAD_COLS_DDR |= 0xf0; //initializing keypad column pins as output
	KEYPAD_ROWS_DDR &= ~(0x0f); // initializing keypad rows as input
	KEYPAD_ROWS_PORT |= (0x0f); // activating internal pull-up resistors on keypad rows
}
uint8 keypad_getNumber(void) {
	uint8 a_rows = 0, a_cols = 0;
	KEYPAD_COLS_PORT = 0b00001111;
	while (TRUE) {
		for (a_cols = 0; a_cols < COLUMNS; a_cols++) {
			KEYPAD_COLS_DDR = (0b00010000 << a_cols);

			for (a_rows = 0; a_rows < ROWS; a_rows++) {

				if (!(KEYPAD_ROWS_PINS & (1 << a_rows))) {
					while ((!(KEYPAD_ROWS_PINS & (1 << a_rows))))
						;
					return keypad_numberToAscii(
							((COLUMNS * a_rows) + a_cols + 1));

				}
			}
		}
	}

}
static uint8 keypad_numberToAscii(uint8 a_KeypadNumber) {
#if (COLUMNS == 4)
	switch (a_KeypadNumber) {
	case 1:
		return '7';
		break;
	case 2:
		return '8';
		break;
	case 3:
		return '9';
		break;
	case 4:
		return '/';
		break;
	case 5:
		return '4';
		break;
	case 6:
		return '5';
		break;
	case 7:
		return '6';
		break;
	case 8:
		return '*';
		break;
	case 9:
		return '1';
		break;
	case 10:
		return '2';
		break;
	case 11:
		return '3';
		break;
	case 12:
		return '-';
		break;
	case 13:
		return a_KeypadNumber;
		break;
	case 14:
		return '0';
		break;
	case 15:
		return '=';
		break;
	case 16:
		return '+';
		break;
	default:
		return 'E';
		break;
	}
#elif (COLUMNS == 3)

	switch(a_KeypadNumber) {
		case 1: return '1';
		break;
		case 2: return '2';
		break;
		case 3: return '3';
		break;
		case 4: return '4';
		break;
		case 5: return '5';
		break;
		case 6: return '6';
		break;
		case 7: return '7';
		break;
		case 8: return '8';
		break;
		case 9: return '9';
		break;
		case 10: return '*';
		break;
		case 11: return '0';
		break;
		case 12: return '#';
		break;
		default: return a_KeypadNumber;
	}
#endif
}

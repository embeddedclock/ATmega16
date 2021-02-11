/*
 * Keypad.h
 *
 *  Created on: Dec 29, 2019
 *      Author: Mohamad
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <avr/io.h>
#include <util/delay.h>

#include "common_macros.h"
#include "std_types.h"
/*
 * defining all macros used in this driver
 */
#define KEYPAD_CONFIG 4x4
#define ROWS 4
#define COLUMNS 4
#define KEYPAD_ROWS_PORT PORTA
#define KEYPAD_COLS_PORT PORTA
#define KEYPAD_ROWS_DDR DDRA
#define KEYPAD_COLS_DDR DDRA
#define KEYPAD_ROWS_PINS PINA
#define KEYPAD_COLS_PINS PINA
/*
 * declaring all functions used in this driver
 */
void keypad_init(void);
uint8 keypad_getNumber(void);
#endif /* KEYPAD_H_ */

/*
 * LCD.h
 *
 *  Created on: Dec 28, 2019
 *      Author: Mohamad
 */

#ifndef LCD_H_
#define LCD_H_
/*
 * including all needed libraries to the driver
 */
#include <avr/io.h>
#include <util/delay.h>
#include "std_types.h"
#include <stdlib.h>

#include "common_macros.h"
/*
 * defining all macros used in the driver
 */
#define DATA_REG_DDR DDRC
#define CONTROL_REG_DDR DDRD
#define DATA_REG PORTC
#define CONTROL_REG PORTD
#define RS PD4
#define RW PD5
#define EN PD6
#define LCD_CLEAR_COMMAND 0x01
#define CURSOR_ON 0x0E
#define CURSOR_OFF 0x0C
#define SET_CURSOR_LOCATION 0x80
#define TWO_LINE_LCD_Eight_BIT_MODE 0x38

/*
 * declaring all functions used in the driver "prototypes"
 */
void lcd_init(void);
void lcd_sendCommand(uint8 command);
void lcd_displayCharacter(uint8 data);
void lcd_displayString(const int8 * string);
void lcd_goToRowColumn(uint8 row, uint8 col);
void lcd_displayStringRowColumn(uint8 row, uint8 col, const char *Str);
void lcd_integerToString(uint64 data);
void lcd_clear(void);

#endif /* LCD_H_ */

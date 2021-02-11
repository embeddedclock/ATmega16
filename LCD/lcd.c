/*
 * LCD.c
 *
 *  Created on: Dec 28, 2019
 *      Author: Mohamad
 */

#include "lcd.h"
/*
 *
 */
void lcd_init(void) {
	DATA_REG_DDR = 0xFF; /* Configure the data port as output port */
	CONTROL_REG_DDR |= (1 << EN) | (1 << RS) | (1 << RW); /* Configure the control pins(E,RS,RW) as output pins */

	lcd_sendCommand(TWO_LINE_LCD_Eight_BIT_MODE); /* use 2-line lcd + 8-bit Data Mode + 5*7 dot display Mode */

	lcd_sendCommand(CURSOR_OFF); /* cursor off */

	lcd_sendCommand(LCD_CLEAR_COMMAND); /* clear LCD at the beginning */

}

void lcd_sendCommand(uint8 command) {
	CLEAR_BIT(CONTROL_REG, RS); /* Instruction Mode RS=0 */
	CLEAR_BIT(CONTROL_REG, RW); /* write data to LCD so RW=0 */
	_delay_ms(1); /* delay for processing Tas = 50ns */
	SET_BIT(CONTROL_REG, EN); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */
	DATA_REG = command; /* out the required command to the data bus D0 --> D7 */
	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	CLEAR_BIT(CONTROL_REG, EN); /* disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
}

void lcd_displayCharacter(uint8 data) {
	SET_BIT(CONTROL_REG, RS); /* Instruction Mode RS=1 */
	CLEAR_BIT(CONTROL_REG, RW); /* write data to LCD so RW=0 */
	_delay_ms(1); /* delay for processing Tas = 50ns */
	SET_BIT(CONTROL_REG, EN); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */
	DATA_REG = data; /* out the required command to the data bus D0 --> D7 */
	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	CLEAR_BIT(CONTROL_REG, EN); /* disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
}

void lcd_displayString(const int8 * string) {
	while ((*string) != '\0') {
		lcd_displayCharacter((*string));
		string++;
	}

}

void lcd_goToRowColumn(uint8 row, uint8 col) {
	uint8 Address;

	/* first of all calculate the required address */
	switch (row) {
	case 0:
		Address = col;
		break;
	case 1:
		Address = col + 0x40;
		break;
	case 2:
		Address = col + 0x10;
		break;
	case 3:
		Address = col + 0x50;
		break;
	}
	/* to write to a specific address in the LCD
	 * we need to apply the corresponding command 0b10000000+Address */
	lcd_sendCommand(Address | SET_CURSOR_LOCATION);
}

void lcd_displayStringRowColumn(uint8 row, uint8 col, const char *Str) {
	lcd_goToRowColumn(row, col); /* go to to the required LCD position */
	lcd_displayString(Str); /* display the string */
}

void lcd_integerToString(uint64 data) {
	char buff[16]; /* String to hold the ascii result */
	itoa(data, buff, 10); /* 10 for decimal */
	lcd_displayString(buff);
}
void lcd_clear(void) {
	lcd_sendCommand(LCD_CLEAR_COMMAND); /* clear LCD at the beginning */
}

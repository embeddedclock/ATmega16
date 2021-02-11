/*
 * main.c
 *
 *  Created on: Dec 6, 2019
 *      Author: Mohamad
 */
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
void dc_motor_on_cw(void) {
	DDRC |= (1 << 0) | (1 << 1); // setting pin 0 and 2 in portc as output
	PORTC |= (1 << 0);
	PORTC &= ~(1 << 1);
}
void dc_motor_on_ccw(void) {
	DDRC |= (1 << 1) | (1 << 0); // setting pin 0 and 2 in portc as output
	PORTC |= (1 << 1);
	PORTC &= ~(1 << 0);
}
void dc_motor_off(void) {
	DDRC |= (1 << 1) | (1 << 0); // setting pin 0 and 2 in portc as output
	PORTC &= ~((1 << 1) | (1 << 0));
}
int main(void) {
	char flag = 0;
	unsigned char counter = 0;
	const unsigned char stepper1[8] = { 8, 12, 4, 6, 2, 3, 1, 9 };
	DDRA &= ~(1 << 0);
	DDRC |= 0x0F;
	PORTC &= ~0x0F;
	while (1) {
		if ((PINA & (1 << 0)) && flag == 0) {
			_delay_ms(20);
			if (PINA & (1 << 0)) {
				flag = 1;
				if (counter < 8) {
					PORTC = stepper1[counter];
					counter++;
				} else {
					counter = 0;
				}

			}

		} else if(!(PINA & (1 << 0))) {
			flag = 0;
		}

	}

	return 0;

}

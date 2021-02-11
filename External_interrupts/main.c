/*
 * main.c
 *
 *  Created on: Dec 9, 2019
 *      Author: Mohamad
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

ISR(INT0_vect){
 PORTC &=~(1<<PC0);
}

ISR(INT1_vect){
	PORTC |=(1<<PC0);
}

ISR(INT2_vect){
	PORTC ^=(1<<PC0);
}

int main(void)
{
	DDRC |=(1<<PC0);
	DDRD &=~(1<<PD2);
	DDRD &=~(1<<PD3);
	DDRB &=~(1<<PB2);
	PORTD |=(1<<PD2);
	PORTB |=(1<<PB2);
	GICR |= (1<<INT2)|(1<<INT1)|(1<<INT0);
	MCUCR |=(1<<ISC10)|(1<<ISC11)|(1<<ISC01);
	MCUCSR &=~(1<<ISC2);
	SREG |= (1<<7);
	while(1)
	{
		//do nothing
	}
	return 0;
}

/*
 * main.c
 *
 *  Created on: Dec 7, 2019
 *      Author: Mohamad
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
void timer1_init_pwm(unsigned int frequency,unsigned char duty)
{
	TCCR1A = (1<<COM1A1)|(1<<WGM11);//setting wave generation mode bit 1
	TCCR1B = (1<<WGM13)|(1<<WGM12)|(1<<CS10)|(1<<CS11);//initializing timer/counter1 on fast PWM and prescaler = 64
	ICR1 = (unsigned short)(8000000/(frequency*64))-1;
	TCNT1 = 0;
	OCR1A = duty;
	DDRD |=(1<<5);
/*
 * han3ml project hwa digital clock
 * hansta5dm 6 7-segments bas 3antare2 selective 7-segment aw multiplexer
 * +
 */

}

int main(void)
{
	timer1_init_pwm(50,5);
	_delay_ms(1000);
	timer1_init_pwm(50,7.5);
	while(1)
	{
	timer1_init_pwm(50,124);
	_delay_ms(1000);
	timer1_init_pwm(50,187);
	_delay_ms(1000);
	timer1_init_pwm(50,250);
	_delay_ms(1000);
	}
	return 0;
}

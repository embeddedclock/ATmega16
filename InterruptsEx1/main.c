#define F_CPU 8000000U
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
void int0_init(void)
{
	DDRD &=~(1<<2);
	PORTD |=(1<<2);
	MCUCSR |=(1<<ISC01);
	MCUCSR &=~(1<<ISC00);
	GICR|=(1<<INT0);
	SREG |=(1<<7);

}
void int1_init(void)
{
	DDRD &=~(1<<3);
	PORTD |=(1<<3);
	MCUCSR |=(1<<ISC11);
	MCUCSR &=~(1<<ISC10);
	GICR|=(1<<INT1);
	SREG |=(1<<7);
}

ISR(INT1_vect)
{
	unsigned char counter = 0;
	for(counter = 0; counter<5; counter++)
	{
		PORTC=0xFF;
		_delay_ms(1000);
		PORTC=0x00;
		_delay_ms(1000);
	}

}


int main(void)
{
	int1_init();
	DDRC |=0xFF;
	PORTC = 0x00;
	while(1)
	{
		if(PORTC == 0)
		{
			PORTC = 1;
			_delay_ms(1000);
		}

		PORTC*=2;

		_delay_ms(1000);
	}
	return 0;
}

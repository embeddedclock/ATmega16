#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
unsigned char counter = 0;
//initializing timer0 on normal mode
void timer0_init_normal(void)
{
	TCCR0 = (1<<CS02)|(1<<CS00); //Using the internal clock of the uC using 1024 prescaler
	TIMSK|=(1<<TOIE0); //Enabling timer interrupt for overflow or normal mode through Timer mask register
	SREG |=(1<<7);	//enabling global interrupt  bit in status word register
	TCNT0 = 0;	// initializing timer/counter register with zero
}
//definition of initializing function to timer0 on CTC mode
void timer0_init_ctc(unsigned char counts)
{
	OCR0 = counts;
	TCCR0 = (1<<CS02)|(1<<CS00)|(1<<WGM01); //Using the internal clock of the uC using 1024 prescaler/Enabling timer0
	TIMSK|=(1<<OCIE0); //Enabling timer interrupt for output compare mode through Timer mask register
	SREG |=(1<<7);	//enabling global interrupt  bit in status word register
	TCNT0 = 0;	// initializing timer/counter register with zero
}
//16-bit timer1 initialization on normal mode
void timer1_init_normal(void)
{
	TCCR1A = 0;//do nothing with Timer/Counter1 control register A and just set it with zero
	TCCR1B = (1<<CS12)|(1<<CS10);//Enabling interrupt 1 on normal mode with prescaler of 1024
	TIMSK |=(1<<TOIE1); //Timer1 interrupt on overflow enable
	SREG |= (1<<7); // setting Ibit of global interrupt enable
	TCNT1 = 0; // initializing Timer/counter1 by zero
}

/// initializing 16-bit timer1 on CTC mode
void timer1_init_ctca(unsigned int counts)
{
	OCR1A = counts;//initializing output compare register for timer1 A with given counts
	TCCR1A = 0; // setting control register for timer1 with zero
	TCCR1B = (1<<CS12)|(1<<CS10)|(1<<WGM12); //enabling timer1 with internal clock on prescaler of 1024 on CTC mode
	TIMSK |= (1<<OCIE1A); //Enabling timer1 interrupt on output compare event
	SREG |=(1<<7); // setting global interrupt but for enabling interrupts
	TCNT1 = 0; // initializing timer/counter1 register with zero

}
//Timer/Counter2 initializing function definition
void timer2_init_normal(void)
{
	TCCR2 = (1<<CS22)|(1<<CS21)|(1<<CS20); // Enabling timer2 on normal mode with prescaler of 1024
	TIMSK|= (1<<TOIE2); // Enabling timer interrupt on overflow
	SREG|=(1<<7); // Enabling global interrupt
	TCNT2 = 0; // initializing timer/counter2 register with zero
}
//initializing Timer/Counter2 on CTC mode
void timer2_init_ctc(unsigned char counts)
{
	OCR2 = counts; //setting the compare value in the output compare register
	TCCR2 = (1<<CS22)|(1<<CS21)|(1<<CS20)|(1<<WGM21); // Enabling Timer/Counter2 on 1024prescaler and CTC mode
	TIMSK |=(1<<OCIE2); // Enabling timer/counter2 interrupt on output compare
	SREG |= (1<<7); // Enabling global interrupts
	TCNT2 = 0; //initializing timer/counter2 register with zero
}
///interrupt service routine
ISR(TIMER2_COMP_vect)
{
	if(counter < 4)
	{
		counter++; //incrementing the unsigned 8-bit variable
	}else{
		PORTC^=(1<<0);
		counter = 0;
	}
}
int main(void)
{
	timer2_init_ctc(244);/*timer1 interrupt on overflow will toggle the led connected on portc pin0 once every 8.3seconds*/
	//initializing the LED on GPIOPC - active high
	DDRC |= (1<<0);// setting bit/pin 0 in PORTC as output
	PORTC &=~(1<<0); // clearing bit 0 in PORTC as the LED is active HIGH /initialized by zero
	/*Super Loop*/
	while(1)
	{
		/*Do nothing in the loop*/
	}

	return 0;
}

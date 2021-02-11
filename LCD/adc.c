/*
 * adc.c
 *
 *  Created on: Dec 28, 2019
 *      Author: Mohamad
 */
/*
 * including the header file for the ADC driver
 */
#include "adc.h"
/*
 * static/protected global variable of type pointer to function to save the called back function
 */
static void (*g_behaviour)(uint16) = NULL_PTR;
/*
 * the initializing function to adc on a specific channel
 */
void adc_init(ADC_DATA* a_adcData) {
	ADMUX = a_adcData->refSelect; //setting the reference voltage of the ADC as AREF not AVCC
	if (a_adcData->interruptEnable) {
		SET_BIT(ADCSRA, ADIE); // Enabling ADC interrupt
	} else {
		CLEAR_BIT(ADCSRA, ADIE); // disabling ADC interrupt
	}
	a_adcData->prescaler &= 0x07;
	ADCSRA = (ADCSRA & 0xF8) | (a_adcData->prescaler); // Enabling analog to digital converter on a prescaler
	SET_BIT(ADCSRA, ADEN); // Enabling ADC
}
/*
 * reading channel, starting conversion and returning back the conversion value
 * as a 16-bit unsigned integer.
 */
uint16 adc_readChannel(ADC_DATA* a_adcData) {
	a_adcData->channel_num &= 0x07;
	ADMUX = (ADMUX & 0xE0) | (a_adcData->channel_num); // giving the channel number to the ADC
	ADCSRA |= (1 << ADSC); // starting conversion
	while (!(ADCSRA & (1 << ADIF)))
		// polling until the flag is equal to 1
		;
	SET_BIT(ADCSRA, ADIF); //resetting the flag to zero by writing logical one to the ADIF bit
	return ADC;
}
/*
 * the interrupt service routine for the ADC in case of using the interrupt
 */
ISR(ADC_vect) {
	(*g_behaviour)(ADC); // calling back the function given to the driver using function pointer
}
/*
 * starting conversion for interrupt mode
 */
void adc_start(ADC_DATA* a_adcData) {
	g_behaviour = a_adcData->behaviour; // assigning the address of the given function to the global function pointer
	a_adcData->channel_num &= 0x07;
	ADMUX = (ADMUX & 0xF0) | (a_adcData->channel_num); // assigning the channel number to the ADC
	SET_BIT(ADCSRA, ADSC); //start converting
}
/*
 * disabling/terminating function to any ADC process
 */
void adc_stop(void) {
	CLEAR_BIT(ADCSRA, ADEN); // Disabling ADC/Terminating current process
}

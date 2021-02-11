/*
 * adc.h
 *
 *  Created on: Dec 28, 2019
 *      Author: Mohamad
 */

#ifndef ADC_H_
#define ADC_H_

/*
 * including microcontroller library
 * including
 */
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "common_macros.h"
#include "std_types.h"
/*
 * defining all macros required and used in this driver
 */
#define ADC_PIN
#define ADC_PORT
#define ADC_MODE 0
/*
 * if ADC_MODE =  1 then adc is working on interrupt mode else if
 *    ADC_MODE = 1 then it works on polling mode
 */
//types used and defined for this driver
typedef struct {
	enum {
		AREF = 0, AVCC = 1, Internal2_56 = 3
	} refSelect;
	enum {
		Disabled, Enabled
	} interruptEnable;
	enum {
		Right, Left
	} dataPresentation;
	enum {
		ADC0, ADC1, ADC2, ADC3, ADC4, ADC5, ADC6, ADC7
	} channel_num;
	enum {
		_2 = 1, _4, _8, _16, _32, _64, _128
	} prescaler;
	void (*behaviour)(uint16);

} ADC_DATA;

/*
 * declaring all functions used in the driver (prototypes)
 */
void adc_init(ADC_DATA* a_adcData);
uint16 adc_readChannel(ADC_DATA* a_adcData);
void adc_start(ADC_DATA* a_adcData);
void adc_stop(void);

#endif /* ADC_H_ */

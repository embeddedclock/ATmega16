/************************************************************************************************
 *   File Name : icu.h																			*
 *  Created on : Jan 7, 2020																	*
 *      Author : Mohamad Hamdi																	*
 ************************************************************************************************/

#ifndef ICU_H_
#define ICU_H_

#include "std_types.h"
#include "common_macros.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
/************************************************************************************************
 * 										Types Declaration										*
 ************************************************************************************************/
typedef enum {
	NO_CLOCK, F_CPU_CLOCK, F_CPU_8, F_CPU_64, F_CPU_256, F_CPU_1024
} icuClock;
typedef enum {
	ICU_FALLING, ICU_RISING
} icuEdgeType;
typedef struct {
	icuClock clock;
	icuEdgeType edge;
} icuConfigData;

void icuInit(const icuConfigData* a_icuConfig);

#endif /* ICU_H_ */

/*
 * pushButton.h
 *
 *  Created on: Jan 6, 2020
 *      Author: Mohamad
 */

#ifndef PUSHBUTTON_H_
#define PUSHBUTTON_H_
#include "std_types.h"
#include "dio.h"
#include "common_macros.h"
#include <util/delay.h>
/*
 * declaring all data types used in this driver
 */
typedef struct {
	enum {
		PORT_A = 0x1B, PORT_B = 0x18, PORT_C = 0x15, PORT_D = 0x12
	} pbPort;
	enum {
		PIN_0, PIN_1, PIN_2, PIN_3, PIN_4, PIN_5, PIN_6, PIN_7
	} pbPin;
	enum {
		no_pullup, pullup
	} pb_pullupStatus;
} pushButton;
/*
 * defining all macros used in this driver
 */

/*
 * declaring functions used in this driver
 */
void setPushButton(pushButton* a_pushButton);
uint8 readPushButton(pushButton* a_pushButton);
#endif /* PUSHBUTTON_H_ */

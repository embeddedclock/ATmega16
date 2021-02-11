/*
 * dio.h
 *
 *  Created on: Jan 6, 2020
 *      Author: Mohamad
 */

#ifndef DIO_H_
#define DIO_H_

#include "std_types.h"

#define SHIFT 0x20

#define PORTA ((*((volatile manage_8bit_reg*)(0x1B + SHIFT))).reg)
#define PA0 ((*((volatile manage_8bit_reg*)(0x1B + SHIFT))).bits.bit0)
#define PA1 ((*((volatile manage_8bit_reg*)(0x1B + SHIFT))).bits.bit1)
#define PA2 ((*((volatile manage_8bit_reg*)(0x1B + SHIFT))).bits.bit2)
#define PA3 ((*((volatile manage_8bit_reg*)(0x1B + SHIFT))).bits.bit3)
#define PA4 ((*((volatile manage_8bit_reg*)(0x1B + SHIFT))).bits.bit4)
#define PA5 ((*((volatile manage_8bit_reg*)(0x1B + SHIFT))).bits.bit5)
#define PA6 ((*((volatile manage_8bit_reg*)(0x1B + SHIFT))).bits.bit6)
#define PA7 ((*((volatile manage_8bit_reg*)(0x1B + SHIFT))).bits.bit7)

#define DDRA ((*((volatile manage_8bit_reg*)(0x1A + SHIFT))).reg)
#define DDRA0 ((*((volatile manage_8bit_reg*)(0x1A + SHIFT))).bits.bit0)
#define DDRA1 ((*((volatile manage_8bit_reg*)(0x1A + SHIFT))).bits.bit1)
#define DDRA2 ((*((volatile manage_8bit_reg*)(0x1A + SHIFT))).bits.bit2)
#define DDRA3 ((*((volatile manage_8bit_reg*)(0x1A + SHIFT))).bits.bit3)
#define DDRA4 ((*((volatile manage_8bit_reg*)(0x1A + SHIFT))).bits.bit4)
#define DDRA5 ((*((volatile manage_8bit_reg*)(0x1A + SHIFT))).bits.bit5)
#define DDRA6 ((*((volatile manage_8bit_reg*)(0x1A + SHIFT))).bits.bit6)
#define DDRA7 ((*((volatile manage_8bit_reg*)(0x1A + SHIFT))).bits.bit7)

#define PINA ((*((volatile manage_8bit_reg*)(0x19 + SHIFT))).reg)
#define PINA0 ((*((volatile manage_8bit_reg*)(0x19 + SHIFT))).bits.bit0)
#define PINA1 ((*((volatile manage_8bit_reg*)(0x19 + SHIFT))).bits.bit1)
#define PINA2 ((*((volatile manage_8bit_reg*)(0x19 + SHIFT))).bits.bit2)
#define PINA3 ((*((volatile manage_8bit_reg*)(0x19 + SHIFT))).bits.bit3)
#define PINA4 ((*((volatile manage_8bit_reg*)(0x19 + SHIFT))).bits.bit4)
#define PINA5 ((*((volatile manage_8bit_reg*)(0x19 + SHIFT))).bits.bit5)
#define PINA6 ((*((volatile manage_8bit_reg*)(0x19 + SHIFT))).bits.bit6)
#define PINA7 ((*((volatile manage_8bit_reg*)(0x19 + SHIFT))).bits.bit7)

#define PORTB ((*((volatile manage_8bit_reg*)(0x18 + SHIFT))).reg)
#define PB0 ((*((volatile manage_8bit_reg*)(0x18 + SHIFT))).bits.bit0)
#define PB1 ((*((volatile manage_8bit_reg*)(0x18 + SHIFT))).bits.bit1)
#define PB2 ((*((volatile manage_8bit_reg*)(0x18 + SHIFT))).bits.bit2)
#define PB3 ((*((volatile manage_8bit_reg*)(0x18 + SHIFT))).bits.bit3)
#define PB4 ((*((volatile manage_8bit_reg*)(0x18 + SHIFT))).bits.bit4)
#define PB5 ((*((volatile manage_8bit_reg*)(0x18 + SHIFT))).bits.bit5)
#define PB6 ((*((volatile manage_8bit_reg*)(0x18 + SHIFT))).bits.bit6)
#define PB7 ((*((volatile manage_8bit_reg*)(0x18 + SHIFT))).bits.bit7)

#define DDRB ((*((volatile manage_8bit_reg*)(0x17 + SHIFT))).reg)
#define DDRB0 ((*((volatile manage_8bit_reg*)(0x17 + SHIFT))).bits.bit0)
#define DDRB1 ((*((volatile manage_8bit_reg*)(0x17 + SHIFT))).bits.bit1)
#define DDRB2 ((*((volatile manage_8bit_reg*)(0x17 + SHIFT))).bits.bit2)
#define DDRB3 ((*((volatile manage_8bit_reg*)(0x17 + SHIFT))).bits.bit3)
#define DDRB4 ((*((volatile manage_8bit_reg*)(0x17 + SHIFT))).bits.bit4)
#define DDRB5 ((*((volatile manage_8bit_reg*)(0x17 + SHIFT))).bits.bit5)
#define DDRB6 ((*((volatile manage_8bit_reg*)(0x17 + SHIFT))).bits.bit6)
#define DDRB7 ((*((volatile manage_8bit_reg*)(0x17 + SHIFT))).bits.bit7)

#define PINB ((*((volatile manage_8bit_reg*)(0x16 + SHIFT))).reg)
#define PINB0 ((*((volatile manage_8bit_reg*)(0x16 + SHIFT))).bits.bit0)
#define PINB1 ((*((volatile manage_8bit_reg*)(0x16 + SHIFT))).bits.bit1)
#define PINB2 ((*((volatile manage_8bit_reg*)(0x16 + SHIFT))).bits.bit2)
#define PINB3 ((*((volatile manage_8bit_reg*)(0x16 + SHIFT))).bits.bit3)
#define PINB4 ((*((volatile manage_8bit_reg*)(0x16 + SHIFT))).bits.bit4)
#define PINB5 ((*((volatile manage_8bit_reg*)(0x16 + SHIFT))).bits.bit5)
#define PINB6 ((*((volatile manage_8bit_reg*)(0x16 + SHIFT))).bits.bit6)
#define PINB7 ((*((volatile manage_8bit_reg*)(0x16 + SHIFT))).bits.bit7)

#define PORTC ((*((volatile manage_8bit_reg*)(0x15 + SHIFT))).reg)
#define PC0 ((*((volatile manage_8bit_reg*)(0x15 + SHIFT))).bits.bit0)
#define PC1 ((*((volatile manage_8bit_reg*)(0x15 + SHIFT))).bits.bit1)
#define PC2 ((*((volatile manage_8bit_reg*)(0x15 + SHIFT))).bits.bit2)
#define PC3 ((*((volatile manage_8bit_reg*)(0x15 + SHIFT))).bits.bit3)
#define PC4 ((*((volatile manage_8bit_reg*)(0x15 + SHIFT))).bits.bit4)
#define PC5 ((*((volatile manage_8bit_reg*)(0x15 + SHIFT))).bits.bit5)
#define PC6 ((*((volatile manage_8bit_reg*)(0x15 + SHIFT))).bits.bit6)
#define PC7 ((*((volatile manage_8bit_reg*)(0x15 + SHIFT))).bits.bit7)

#define DDRC ((*((volatile manage_8bit_reg*)(0x14 + SHIFT))).reg)
#define DDRC0 ((*((volatile manage_8bit_reg*)(0x14 + SHIFT))).bits.bit0)
#define DDRC1 ((*((volatile manage_8bit_reg*)(0x14 + SHIFT))).bits.bit1)
#define DDRC2 ((*((volatile manage_8bit_reg*)(0x14 + SHIFT))).bits.bit2)
#define DDRC3 ((*((volatile manage_8bit_reg*)(0x14 + SHIFT))).bits.bit3)
#define DDRC4 ((*((volatile manage_8bit_reg*)(0x14 + SHIFT))).bits.bit4)
#define DDRC5 ((*((volatile manage_8bit_reg*)(0x14 + SHIFT))).bits.bit5)
#define DDRC6 ((*((volatile manage_8bit_reg*)(0x14 + SHIFT))).bits.bit6)
#define DDRC7 ((*((volatile manage_8bit_reg*)(0x14 + SHIFT))).bits.bit7)

#define PINC ((*((volatile manage_8bit_reg*)(0x13 + SHIFT))).reg)
#define PINC0 ((*((volatile manage_8bit_reg*)(0x13 + SHIFT))).bits.bit0)
#define PINC1 ((*((volatile manage_8bit_reg*)(0x13 + SHIFT))).bits.bit1)
#define PINC2 ((*((volatile manage_8bit_reg*)(0x13 + SHIFT))).bits.bit2)
#define PINC3 ((*((volatile manage_8bit_reg*)(0x13 + SHIFT))).bits.bit3)
#define PINC4 ((*((volatile manage_8bit_reg*)(0x13 + SHIFT))).bits.bit4)
#define PINC5 ((*((volatile manage_8bit_reg*)(0x13 + SHIFT))).bits.bit5)
#define PINC6 ((*((volatile manage_8bit_reg*)(0x13 + SHIFT))).bits.bit6)
#define PINC7 ((*((volatile manage_8bit_reg*)(0x13 + SHIFT))).bits.bit7)

#define PORTD ((*((volatile manage_8bit_reg*)(0x12 + SHIFT))).reg)
#define PD0 ((*((volatile manage_8bit_reg*)(0x12 + SHIFT))).bits.bit0)
#define PD1 ((*((volatile manage_8bit_reg*)(0x12 + SHIFT))).bits.bit1)
#define PD2 ((*((volatile manage_8bit_reg*)(0x12 + SHIFT))).bits.bit2)
#define PD3 ((*((volatile manage_8bit_reg*)(0x12 + SHIFT))).bits.bit3)
#define PD4 ((*((volatile manage_8bit_reg*)(0x12 + SHIFT))).bits.bit4)
#define PD5 ((*((volatile manage_8bit_reg*)(0x12 + SHIFT))).bits.bit5)
#define PD6 ((*((volatile manage_8bit_reg*)(0x12 + SHIFT))).bits.bit6)
#define PD7 ((*((volatile manage_8bit_reg*)(0x12 + SHIFT))).bits.bit7)

#define DDRD ((*((volatile manage_8bit_reg*)(0x11 + SHIFT))).reg)
#define DDRD0 ((*((volatile manage_8bit_reg*)(0x11 + SHIFT))).bits.bit0)
#define DDRD1 ((*((volatile manage_8bit_reg*)(0x11 + SHIFT))).bits.bit1)
#define DDRD2 ((*((volatile manage_8bit_reg*)(0x11 + SHIFT))).bits.bit2)
#define DDRD3 ((*((volatile manage_8bit_reg*)(0x11 + SHIFT))).bits.bit3)
#define DDRD4 ((*((volatile manage_8bit_reg*)(0x11 + SHIFT))).bits.bit4)
#define DDRD5 ((*((volatile manage_8bit_reg*)(0x11 + SHIFT))).bits.bit5)
#define DDRD6 ((*((volatile manage_8bit_reg*)(0x11 + SHIFT))).bits.bit6)
#define DDRD7 ((*((volatile manage_8bit_reg*)(0x11 + SHIFT))).bits.bit7)

#define PIND ((*((volatile manage_8bit_reg*)(0x10 + SHIFT))).reg)
#define PIND0 ((*((volatile manage_8bit_reg*)(0x10 + SHIFT))).bits.bit0)
#define PIND1 ((*((volatile manage_8bit_reg*)(0x10 + SHIFT))).bits.bit1)
#define PIND2 ((*((volatile manage_8bit_reg*)(0x10 + SHIFT))).bits.bit2)
#define PIND3 ((*((volatile manage_8bit_reg*)(0x10 + SHIFT))).bits.bit3)
#define PIND4 ((*((volatile manage_8bit_reg*)(0x10 + SHIFT))).bits.bit4)
#define PIND5 ((*((volatile manage_8bit_reg*)(0x10 + SHIFT))).bits.bit5)
#define PIND6 ((*((volatile manage_8bit_reg*)(0x10 + SHIFT))).bits.bit6)
#define PIND7 ((*((volatile manage_8bit_reg*)(0x10 + SHIFT))).bits.bit7)

#endif /* DIO_H_ */

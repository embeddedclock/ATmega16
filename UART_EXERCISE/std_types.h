/*
 * standard_types.h
 *
 *  Created on: Dec 28, 2019
 *      Author: Mohamad
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_
/*
 *defining unsigned types
 */
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef unsigned long long uint64;
/*
 * defining signed types
 */
typedef char int8;
typedef short int16;
typedef long int32;
typedef long long int64;
/*
 * type for data and prephiral mapped registers(8-bits registers)
 */
typedef union manage_8bit {
	uint8 reg;
	struct reg_8bits {
		uint8 bit0 :1;
		uint8 bit1 :1;
		uint8 bit2 :1;
		uint8 bit3 :1;
		uint8 bit4 :1;
		uint8 bit5 :1;
		uint8 bit6 :1;
		uint8 bit7 :1;
	} bits;
} manage_8bit_reg;
/*
 * type for data and prephiral mapped registers(16-bits registers)
 */
typedef union manage_16bit {
	uint16 reg;
	struct reg_16bits {
		uint16 bit0 :1;
		uint16 bit1 :1;
		uint16 bit2 :1;
		uint16 bit3 :1;
		uint16 bit4 :1;
		uint16 bit5 :1;
		uint16 bit6 :1;
		uint16 bit7 :1;
		uint16 bit8 :1;
		uint16 bit9 :1;
		uint16 bit10 :1;
		uint16 bit11 :1;
		uint16 bit12 :1;
		uint16 bit13 :1;
		uint16 bit14 :1;
		uint16 bit15 :1;
	} bits;
} manage_16bit_reg;
/*
 * type for data and prephiral mapped registers(32-bits registers)
 */
typedef union manage_32bit {
	uint32 reg;
	struct reg_32bits {
		uint32 bit0 :1;
		uint32 bit1 :1;
		uint32 bit2 :1;
		uint32 bit3 :1;
		uint32 bit4 :1;
		uint32 bit5 :1;
		uint32 bit6 :1;
		uint32 bit7 :1;
		uint32 bit8 :1;
		uint32 bit9 :1;
		uint32 bit10 :1;
		uint32 bit11 :1;
		uint32 bit12 :1;
		uint32 bit13 :1;
		uint32 bit14 :1;
		uint32 bit15 :1;
		uint32 bit16 :1;
		uint32 bit17 :1;
		uint32 bit18 :1;
		uint32 bit19 :1;
		uint32 bit20 :1;
		uint32 bit21 :1;
		uint32 bit22 :1;
		uint32 bit23 :1;
		uint32 bit24 :1;
		uint32 bit25 :1;
		uint32 bit26 :1;
		uint32 bit27 :1;
		uint32 bit28 :1;
		uint32 bit29 :1;
		uint32 bit30 :1;
		uint32 bit31 :1;
	} bits;
} manage_32bit_reg;
#endif /* STD_TYPES_H_ */

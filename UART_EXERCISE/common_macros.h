/*
 * good_macros.h
 *
 *  Created on: Dec 28, 2019
 *      Author: Mohamad
 */

#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_

#define SUM(A,B)((A)+(B))
#define SET_BIT(VAR,BIT) (VAR|=(1<<BIT))
#define CLEAR_BIT(VAR,BIT) (VAR&=~(1<<BIT))
#define TOGGLE_BIT(VAR,BIT) (VAR^=(1<<BIT))
#define TRUE 1
#define FALSE 1
#define HIGH 1
#define LOW 1
#define NULL_PTR ((void*)0U)

#endif /* COMMON_MACROS_H_ */

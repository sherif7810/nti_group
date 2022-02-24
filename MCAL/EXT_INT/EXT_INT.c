/*
 * EXT_INT.c
 *
 * Created: 14/02/2022 10:28:34 ص
 *  Author: DELL
 */ 
#include "EXT_INT_CFG.h"
#include "EXT_INT.h"
#include "BIT_MATH.h"
#include "REG.h"
#include <avr/interrupt.h>

void (*EXT_INT_0_CALL_BACK)(void);

void EXT_INT_0_INIT(void)
{
	#if SENSE_CONTROL == FALLING_EDGE
	// To select falling edge -> Fire interrupt. Comment is deleted, because of the above line.
	CLR_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
	#elif SENSE_CONTROL == RISING_EDGE
	SET_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
	#elif SENSE_CONTROL == LOGICAL_CHANGE
	SET_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
	#elif SENSE_CONTROL == LOW_LEVEL
	CLR_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
	#endif
	
	// To enable global int.
	SET_BIT(SREG,7);
	// To enable INT0 int.
	SET_BIT(GICR,6);
}

void EXT_INT_0_SET_CALL_BACK(void (*ptr)(void))
{
	EXT_INT_0_CALL_BACK = ptr;
}

ISR(INT0_vect)
{
	EXT_INT_0_CALL_BACK();
}
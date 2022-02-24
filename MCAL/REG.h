/*
 * REG.h
 *
 * Created: 08/02/2022 09:56:51 ص
 *  Author: DELL
 */ 


#ifndef REG_H_
#define REG_H_

#include "STD_TYPES.h"

#define PORTA *(volatile u8*) 0x3B
#define DDRA *(volatile u8*) 0x3A
#define PINA *(volatile u8*) 0x39

#define PORTB *(volatile u8*) 0x38
#define DDRB *(volatile u8*) 0x37
#define PINB *(volatile u8*) 0x36

#define PORTC *(volatile u8*) 0x35
#define DDRC *(volatile u8*) 0x34
#define PINC *(volatile u8*) 0x33

#define PORTD *(volatile u8*) 0x32
#define DDRD *(volatile u8*) 0x31
#define PIND *(volatile u8*) 0x30

/*EXT_INT_REGISTERS*/
#define SREG (*((volatile u8*) 0x5F))
#define GICR (*((volatile u8*) 0x5B))
#define MCUCR (*((volatile u8*) 0x55))

/*ADC_REGISTERS*/
#define ADMUX (*((volatile u8*) 0x27))
#define ADCSRA (*((volatile u8*) 0x26))
#define ADCL (*((volatile u8*) 0x24))
#define ADCH (*((volatile u8*) 0x25))
#define ADC_VALUE (*((volatile u16*) 0x24))

/*TIMER_0_REGISTERS*/
#define TCCR0 (*((volatile u8*) 0x53))
#define TIMSK (*((volatile u8*) 0x59))
#define TCNT0 (*((volatile u8*) 0x52))
#define OCR0 (*((volatile u8*) 0x5C))

/*WDT_REGISTERS*/
#define WDTCR (*((volatile u8*) 0x41))

#endif /* REG_H_ */
/*
 * ADC.c
 *
 * Created: 15/02/2022 01:05:39 م
 *  Author: DELL
 */ 
#include "ADC_CFG.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "REG.h"

void ADC_INIT(void)
{
	#if V_REF == AVCC
	CLR_BIT(ADMUX,7);
	SET_BIT(ADMUX,6);
	#elif V_REF == AREF_PIN
	CLR_BIT(ADMUX,7);
	CLR_BIT(ADMUX,6);
	#elif V_REFF == _2V
	SET_BIT(ADMUX,7);
	SET_BIT(ADMUX,6);
	#endif
	#if ADJUST == R_ADJUST
	CLR_BIT(ADMUX,5);
	#elif ADJUST == L_ADJUST
	SET_BIT(ADMUX,5);
	#endif
	#if ADC_CHANNEL == CHANNEL_0
	CLR_BIT(ADMUX,4);
	CLR_BIT(ADMUX,3);
	CLR_BIT(ADMUX,2);
	CLR_BIT(ADMUX,1);
	CLR_BIT(ADMUX,0);
	#endif
	// Prescaler division factor
	#if PRESCALER_D_FACTOR == 128
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
	#endif
	
	// To enable auto trigger mode
	SET_BIT(ADCSRA,5);
	// To enable ADC
	SET_BIT(ADCSRA,7);
}

u16 ADC_READ(void)
{
	SET_BIT(ADCSRA,6);
	while (GET_BIT(ADCSRA,4) == 0);
	return ADC_VALUE;
}
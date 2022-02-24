/*
 * ADC.h
 *
 * Created: 15/02/2022 01:05:50 م
 *  Author: DELL
 */ 


#ifndef ADC_H_
#define ADC_H_

void ADC_INIT(void);
u16 ADC_READ(void);

#define AVCC 1
#define AREF_PIN 2
#define _2V 3

#define R_ADJUST 0
#define L_ADJUST 1

#define CHANNEL_0 0

#endif /* ADC_H_ */
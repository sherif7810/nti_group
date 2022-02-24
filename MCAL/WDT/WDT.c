/*
 * WDT.c
 *
 * Created: 20/02/2022 01:09:21 م
 *  Author: DELL
 */ 
#include "REG.h"
#include "BIT_MATH.h"
#include "avr\wdt.h"

void WDT_INIT(void)
{
	// Prescaler	
	SET_BIT(WDTCR,2);
	SET_BIT(WDTCR,1);
	SET_BIT(WDTCR,0);
	
	// Enable
	SET_BIT(WDTCR,3);
}

void WDT_REFRESH(void)
{
	asm("WDR");

}
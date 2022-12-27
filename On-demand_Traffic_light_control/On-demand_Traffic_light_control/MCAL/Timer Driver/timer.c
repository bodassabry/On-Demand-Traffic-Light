/*
 * timer.c
 *
 * Created: 14/11/2022 01:15:49 ص
 *  Author: future
 */ 

#include "timer.h"

EN_timerError_t Timer_init()
{
	// choose timer mode
	TCCR0 = 0x00; // Normal mode
	// timer set initial value
	TCNT0 = 0x00;
	return TIMER_OK;
}

EN_timerError_t delay(unsigned int x)
{
	x *= 4;
	// Timer start -> set prescaler
	TCCR0 |= (1<<0); // No prescaler
	
	while(x--){
		// wait until the overflow flag to be set
		while ((TIFR & (1<<0)) == 0);
		// clear the overflow flag
		TIFR |= (1<<0);
	}
	
	// timer stop
	TCCR0 = 0x00;
	return TIMER_OK;
}

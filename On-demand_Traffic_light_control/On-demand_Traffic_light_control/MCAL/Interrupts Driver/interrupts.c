/*
 * interrupts.c
 *
 * Created: 20/11/2022 10:10:23 م
 *  Author: future
 */ 
#include "interrupts.h"

void INTERRUPTS_init()
{
	// enable global interrupt
	sei();
	// choose the external interrupt sense - falling edge
	MCUCR |= (1<<1);
	MCUCR &= ~(1<<0);
	// enable external interrupt 0
	GICR |= (1<<6);
}

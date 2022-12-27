/*
 * registers.h
 *
 * Created: 11/4/2022 11:05:24 PM
 *  Author: omar-sabry
 */ 
/************************************************************************/
/* All microcontroller registers                                        */
/************************************************************************/
#ifndef REGISTERS_H_
#define REGISTERS_H_
#include "data_types.h"

/************************************************************************/
/* DIO Registers                                                        */
/************************************************************************/
// PORTA registers
#define PORTA *((volatile uint8_t*)0x3B) // 8-bit register
#define DDRA *((volatile uint8_t*)0x3A) // 8-bit register
#define PINA *((volatile uint8_t*)0x39) // 8-bit register

// PORTB registers
#define PORTB *((volatile uint8_t*)0x38) // 8-bit register
#define DDRB *((volatile uint8_t*)0x37) // 8-bit register
#define PINB *((volatile uint8_t*)0x36) // 8-bit register

// PORTC registers
#define PORTC *((volatile uint8_t*)0x35) // 8-bit register
#define DDRC *((volatile uint8_t*)0x34) // 8-bit register
#define PINC *((volatile uint8_t*)0x33) // 8-bit register

// PORTD registers
#define PORTD *((volatile uint8_t*)0x32) // 8-bit register
#define DDRD *((volatile uint8_t*)0x31) // 8-bit register
#define PIND *((volatile uint8_t*)0x30) // 8-bit register

/************************************************************************/
/* Timer Registers                                                      */
/************************************************************************/

// Timer 0
#define TCCR0 *((volatile uint8_t*)0x53) // 8-bit register
#define TCNT0 *((volatile uint8_t*)0x52) // 8-bit register
#define TIFR *((volatile uint8_t*)0x58) // 8-bit register

/************************************************************************/
/* External Interrupts registers                                        */
/************************************************************************/
#define MCUCR *((volatile uint8_t*)0x55) // 8-bit register
#define MCUCSR *((volatile uint8_t*)0x54) // 8-bit register
#define GICR *((volatile uint8_t*)0x5B) // 8-bit register
#define GIFR *((volatile uint8_t*)0x5A) // 8-bit register

/************************************************************************/
/* ADC registers                                        */
/************************************************************************/
#define ADMUX *((volatile uint8_t*)0x27) // 8-bit register
#define ADCSRA *((volatile uint8_t*)0x26) // 8-bit register
#define ADCL *((volatile uint8_t*)0x24) // 8-bit register
#define ADCH *((volatile uint8_t*)0x25) // 8-bit register


#endif /* REGISTERS_H_ */
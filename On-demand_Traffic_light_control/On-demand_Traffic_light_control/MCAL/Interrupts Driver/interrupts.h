/*
 * interrupts.h
 *
 * Created: 10/11/2022 01:22:31 ص
 *  Author: future
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include "../../Utilities/registers.h"

/************************************************************************/
/*						      Interrupt vectors                         */
/************************************************************************/
// External interrupt vectors
// External interrupt request 0
#define EXT_INT_0 __vector_1
// External interrupt request 1
#define EXT_INT_1 __vector_2
// External interrupt request 2
#define EXT_INT_2 __vector_3


// set global interrupts, set I-bit in status register to 1
#define sei() __asm__ __volatile__ ("sei" ::: "memory")

// clear global interrupts, set I-bit in status register to 0
#define cli() __asm__ __volatile__ ("cli" ::: "memory")

// ISR definition 
#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal, used));\
void INT_VECT(void)

void INTERRUPTS_init();

#endif /* INTERRUPTS_H_ */
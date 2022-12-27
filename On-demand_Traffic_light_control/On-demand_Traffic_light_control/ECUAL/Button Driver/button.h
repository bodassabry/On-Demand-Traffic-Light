/*
 * button.h
 *
 * Created: 11/6/2022 10:37:21 PM
 *  Author: omar-sabry
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO Driver/dio.h"
#include "../../MCAL/Timer Driver/timer.h"
#include "../../MCAL/Interrupts Driver/interrupts.h"


#define BUTTON_1_PORT PORT_D
#define BUTTON_1_PIN PIN2

// button state macros
#define LOW 0
#define HIGH 1

// initialize
EN_dioError_t BUTTON_init(uint8_t buttonPort, uint8_t buttonPin);

// button read
uint8_t BUTTON_read(uint8_t buttonPort, uint8_t buttonPin);

// button press type
void PRESS_type(uint8_t buttonPort, uint8_t buttonPin, uint8_t *checker);

#endif /* BUTTON_H_ */
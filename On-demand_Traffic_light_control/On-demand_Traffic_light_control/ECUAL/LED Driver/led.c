/*
 * led.c
 *
 * Created: 11/6/2022 8:31:35 PM
 *  Author: omar-sabry
 */ 
#include "led.h"

// initialize led
EN_dioError_t LED_init(uint8_t ledPort, uint8_t ledPin){ // output device
	DIO_init(ledPin, ledPort, OUT);
}
// turn led on
EN_dioError_t LED_on(uint8_t ledPort, uint8_t ledPin){
	DIO_write(ledPin, ledPort, HIGH);
}
// turn led off
EN_dioError_t LED_off(uint8_t ledPort, uint8_t ledPin){
	DIO_write(ledPin, ledPort, LOW);
}
// toggle a led
EN_dioError_t LED_toggle(uint8_t ledPort, uint8_t ledPin){
	DIO_toggle(ledPin, ledPort);
}
// read led state
uint8_t LED_read(uint8_t ledPort, uint8_t ledPin)
{
	uint8_t value;
	DIO_read(ledPin, ledPort, &value);
	return value;
}

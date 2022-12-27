/*
 * button.c
 *
 * Created: 11/6/2022 10:37:12 PM
 *  Author: omar-sabry
 */ 
#include "button.h"

// initialize
EN_dioError_t BUTTON_init(uint8_t buttonPort, uint8_t buttonPin){
	DIO_init(buttonPin, buttonPort, IN);
}
// button read
uint8_t BUTTON_read(uint8_t buttonPort, uint8_t buttonPin){
	uint8_t value;
	DIO_read(buttonPin, buttonPort, &value);
	return value;
}
// get press type, short press or long press
void PRESS_type(uint8_t buttonPort, uint8_t buttonPin, bool *checker)
{
	uint8_t value;
	delay(500);
	value = BUTTON_read(buttonPort, buttonPin);
	if (value == 0)
	{
		*checker = true;
	}
	else
	{
		*checker = false;
	}
}

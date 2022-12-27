/*
 * dio.c
 *
 * Created: 11/4/2022 11:33:49 PM
 *  Author: omar-sabry
 */ 
#include "dio.h"
// global variables
// function deffinitions

// initialize direction input or output
EN_dioError_t DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction){
	switch(portNumber){
		case PORT_A:
			if(direction == IN){
				DDRA &= ~(1<<pinNumber); // Input
				return DIO_OK;
			}
			else if(direction == OUT){
				DDRA |= (1<<pinNumber); // Output
				return DIO_OK;
			}
			else{
				return WRONG_DIR;
			}
		break;
		case PORT_B:
			if(direction == IN){
				DDRB &= ~(1<<pinNumber); // Input
				return DIO_OK;
			}
			else if(direction == OUT){
				DDRB |= (1<<pinNumber); // Output
				return DIO_OK;
			}
			else{
				return WRONG_DIR;
			}
		break;
		case PORT_C:
		if(direction == IN){
			DDRC &= ~(1<<pinNumber); // Input
			return DIO_OK;
		}
		else if(direction == OUT){
			DDRC |= (1<<pinNumber); // Output
			return DIO_OK;
		}
		else{
			return WRONG_DIR;
		}
		break;
		case PORT_D:
		if(direction == IN){
			DDRD &= ~(1<<pinNumber); // Input
			return DIO_OK;
		}
		else if(direction == OUT){
			DDRD |= (1<<pinNumber); // Output
			return DIO_OK;
		}
		else{
			return WRONG_DIR;
		}
		break;
		default:
			return WRONG_PORT;
		break;
	}
}
// write high or low
EN_dioError_t DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value){
	switch(portNumber){
		case PORT_A:
		if(value == LOW){
			PORTA &= ~(1<<pinNumber); // Write 0
			return DIO_OK;
		}
		else if(value == HIGH){
			PORTA |= (1<<pinNumber); // Write 1
			return DIO_OK;
		}
		else{
			return WRONG_VAL;
		}
		break;
		case PORT_B:
		if(value == LOW){
			PORTB &= ~(1<<pinNumber); // Write 0
			return DIO_OK;
		}
		else if(value == HIGH){
			PORTB |= (1<<pinNumber); // Write 1
			return DIO_OK;
		}
		else{
			return WRONG_VAL;
		}
		break;
		case PORT_C:
		if(value == LOW){
			PORTC &= ~(1<<pinNumber); // Write 0
			return DIO_OK;
		}
		else if(value == HIGH){
			PORTC |= (1<<pinNumber); // Write 1
			return DIO_OK;
		}
		else{
			return WRONG_VAL;
		}
		break;
		case PORT_D:
		if(value == LOW){
			PORTD &= ~(1<<pinNumber); // Write 0
			return DIO_OK;
		}
		else if(value == HIGH){
			PORTD |= (1<<pinNumber); // Write 1
			return DIO_OK;
		}
		else{
			return WRONG_VAL;
		}
		break;
		default:
			return WRONG_PORT;
		break;
	}
}
// toggle between high and low
EN_dioError_t DIO_toggle(uint8_t pinNumber, uint8_t portNumber){
	uint8_t value;
	DIO_read(pinNumber, portNumber, &value);
	switch(portNumber){
		case PORT_A:
		if(value == HIGH){
			PORTA &= ~(1<<pinNumber); // Write 0
			return DIO_OK;
		}
		else if(value == LOW){
			PORTA |= (1<<pinNumber); // Write 1
			return DIO_OK;
		}
		else{
			return WRONG_VAL;
		}
		break;
		case PORT_B:
		if(value == HIGH){
			PORTB &= ~(1<<pinNumber); // Write 0
			return DIO_OK;
		}
		else if(value == LOW){
			PORTB |= (1<<pinNumber); // Write 1
			return DIO_OK;
		}
		else{
			return WRONG_VAL;
		}
		break;
		case PORT_C:
		if(value == HIGH){
			PORTC &= ~(1<<pinNumber); // Write 0
			return DIO_OK;
		}
		else if(value == LOW){
			PORTC |= (1<<pinNumber); // Write 1
			return DIO_OK;
		}
		else{
			return WRONG_VAL;
		}
		break;
		case PORT_D:
		if(value == HIGH){
			PORTD &= ~(1<<pinNumber); // Write 0
			return DIO_OK;
		}
		else if(value == LOW){
			PORTD |= (1<<pinNumber); // Write 1
			return DIO_OK;
		}
		else{
			return WRONG_VAL;
		}
		break;
		default:
			return WRONG_PORT;
		break;
	}
}
// read pin state
uint8_t DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value){
	switch(portNumber){
		case PORT_A:
			*value = ((PINA&(1<<pinNumber))>>pinNumber);
		break;
		case PORT_B:
			*value = ((PINB&(1<<pinNumber))>>pinNumber);
		break;
		case PORT_C:
			*value = ((PINC&(1<<pinNumber))>>pinNumber);
		break;
		case PORT_D:
			*value = ((PIND&(1<<pinNumber))>>pinNumber);
		break;
		default:
			return WRONG_PORT;
		break;
	}
}
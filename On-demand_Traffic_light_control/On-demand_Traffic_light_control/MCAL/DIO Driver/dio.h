/*
 * dio.h
 *
 * Created: 11/4/2022 11:34:02 PM
 *  Author: omar-sabry
 */ 


#ifndef DIO_H_
#define DIO_H_
// include registers.h
#include "../../Utilities/registers.h"
#define F_CPU 1000000UL

// all internal typedefs
// all driver macros
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

// Direction defines
#define IN 0
#define OUT 1

// Value defines
#define LOW 0
#define HIGH 1
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

// error codes
typedef enum EN_dioError_t{
	DIO_OK = 3, WRONG_DIR, WRONG_VAL, WRONG_PORT
	}EN_dioError_t;

// all driver function prototypes
EN_dioError_t DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction); // initialize dio direction

EN_dioError_t DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value); // write data to dio

EN_dioError_t DIO_toggle(uint8_t pinNumber, uint8_t portNumber); // toggle dio 

uint8_t DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value); // Read dio



#endif /* DIO_H_ */
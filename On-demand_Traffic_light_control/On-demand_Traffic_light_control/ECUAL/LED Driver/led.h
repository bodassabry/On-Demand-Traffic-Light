/*
 * led.h
 *
 * Created: 11/6/2022 8:31:55 PM
 *  Author: omar-sabry
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO Driver/dio.h"


#define LED_1_PORT PORT_A
#define LED_1_PIN PIN0
#define LED_2_PORT PORT_A
#define LED_2_PIN PIN1
#define LED_3_PORT PORT_A
#define LED_3_PIN PIN2
#define LED_4_PORT PORT_B
#define LED_4_PIN PIN0
#define LED_5_PORT PORT_B
#define LED_5_PIN PIN1
#define LED_6_PORT PORT_B
#define LED_6_PIN PIN2


EN_dioError_t LED_init(uint8_t ledPort, uint8_t ledPin);
EN_dioError_t LED_on(uint8_t ledPort, uint8_t ledPin);
EN_dioError_t LED_off(uint8_t ledPort, uint8_t ledPin);
EN_dioError_t LED_toggle(uint8_t ledPort, uint8_t ledPin);
uint8_t LED_read(uint8_t ledPort, uint8_t ledPin);


#endif /* LED_H_ */
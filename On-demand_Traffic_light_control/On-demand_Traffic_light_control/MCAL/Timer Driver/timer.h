/*
 * timer.h
 *
 * Created: 14/11/2022 01:15:41 ص
 *  Author: future
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../Utilities/registers.h"

typedef enum EN_timerError_t
{
	TIMER_OK, INIT_ERROR, DELAY_ERROR
}EN_timerError_t;

EN_timerError_t Timer_init();
EN_timerError_t delay();


#endif /* TIMER_H_ */
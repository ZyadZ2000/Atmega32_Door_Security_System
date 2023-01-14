/*-------------------------------------------------------------------
 [FILE NAME]: timer1.h
 [AUTHOR(S)]: Zyad Nezar
 [DATE CREATED]: 9/10/2022
 [DESCRIPTION]: Header file for TIMER1 driver
 -------------------------------------------------------------------*/

#ifndef TIMER1_H_
#define TIMER1_H_

#include "../std_types.h"

typedef enum{
 STOPPED,PRESCALE_1,PRESCALE_8,PRESCALE_64,PRESCALE_256,PRESCALE_1024
}Timer1_Prescaler;

typedef enum{
 NORMAL,COMPARE
}Timer1_Mode;

typedef struct {
 uint16 initial_value;
 uint16 compare_value; // it will be used in compare mode only.
 Timer1_Prescaler prescaler;
 Timer1_Mode mode;
} Timer1_ConfigType;

/* Function to initialize the timer with configurations */
void Timer1_init(const Timer1_ConfigType * Config_Ptr);

/* Deinitialize the timer */
void Timer1_deInit(void);

/* set the callback function that's called on an interrupt */
void Timer1_setCallBack(void(*a_ptr)(void));

#endif

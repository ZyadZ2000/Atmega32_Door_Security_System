/*-------------------------------------------------------------------
 [FILE NAME]: timer1.c
 [AUTHOR(S)]: Zyad Nezar
 [DATE CREATED]: 9/10/2022
 [DESCRIPTION]: Source file for TIMER1 driver
 -------------------------------------------------------------------*/

#include "timer1.h"
#include "../MCAL/gpio.h"
#include <avr/interrupt.h> /* to use timer1 interrupts */
#include "avr/io.h" /* to use timer1 registers */

static volatile void (*g_callBack)(void) = NULL_PTR;

ISR(TIMER1_COMPA_vect){
  if(g_callBack != NULL_PTR){
	(*g_callBack)();
  }
}

ISR(TIMER1_OVF_vect){
	if(g_callBack != NULL_PTR){
		(*g_callBack)();
	  }
}

void Timer1_init(const Timer1_ConfigType * Config_Ptr){
	TCCR1A = (1<<FOC1A); /* FOC1A is 1 in non-PWM mode */
	TCNT1 = Config_Ptr->initial_value; /* initialize the timer counter value */
	TCCR1B = (Config_Ptr->prescaler); /* configure the prescaler */
	if(Config_Ptr->mode == COMPARE){
		TCCR1B |= (1<<WGM12);
		OCR1A = Config_Ptr->compare_value;
		TIMSK = (1<<OCIE1A); /* Enable interrupt on compare match */
	}
	else{
		TIMSK = (1<<TOIE1); /* Enable interrupt on overflow */
	}
}

void Timer1_deInit(void){
	/* disable the clock */
	TCCR1B = 0;
}

void Timer1_setCallBack(void(*a_ptr)(void)){
	g_callBack = a_ptr;
}

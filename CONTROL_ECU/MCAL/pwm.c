/*-------------------------------------------------------------------
 [FILE NAME]: pwm.c
 [AUTHOR(S)]: Zyad Nezar
 [DATE CREATED]: 9/10/2022
 [DESCRIPTION]: Source file for PWM driver
 -------------------------------------------------------------------*/

/*----------------------------INCLUDES----------------------------*/

#include "pwm.h"
#include "avr/io.h" /* To use the timer registers */
#include "gpio.h" /* To configure the gpio pins */

/*----------------------------FUNCTION DEFINITIONS----------------------------*/

void PWM_Timer0_Start(uint8 duty_cycle) {

	/* Initializing the count from 0 */

	TCNT0 = 0;

	/* Setting the compare value for the desired duty cycle precentage */

	OCR0 = (uint8) (duty_cycle * 2.55);

	/* OC0 output pin */

	GPIO_setupPinDirection(PORTB_ID, PIN3_ID, PIN_OUTPUT);

	/* Configuring the timer in fast PWM with prescaler F_CPU/8 */

	TCCR0 = (1 << WGM00) | (1 << WGM01) | (1 << COM01) | (1 << CS01);
}

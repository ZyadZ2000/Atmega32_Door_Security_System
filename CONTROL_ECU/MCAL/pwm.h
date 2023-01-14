/*-------------------------------------------------------------------
 [FILE NAME]: pwm.h
 [AUTHOR(S)]: Zyad Nezar
 [DATE CREATED]: 9/10/2022
 [DESCRIPTION]: Header file for PWM driver
 -------------------------------------------------------------------*/

#ifndef PWM_H_
#define PWM_H_

/*----------------------------INCLUDES----------------------------*/

#include "../std_types.h"

/*----------------------------FUNCTION DECLARATIONS----------------------------*/

/*-------------------------------------------------------------------
 [Function Name]: PWM_Timer0_Start
 [Description]: Function responsible for starting the timer and
 generate the pwm
 [Args]: uint8 duty_cycle: Percentage of the duty cycle
 [Returns]: void
 -------------------------------------------------------------------*/

void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* PWM_H_ */

/*-------------------------------------------------------------------
 [FILE NAME]: buzzer.h
 [AUTHOR(S)]: Zyad Nezar
 [DATE CREATED]: 2/11/2022
 [DESCRIPTION]: Header file for Buzzer driver
 -------------------------------------------------------------------*/

#ifndef BUZZER_H_
#define BUZZER_H_

#include "../std_types.h"

#define BUZZER_PORT_ID PORTA_ID
#define BUZZER_PIN_ID PIN0_ID

/* initialize the buzzer pin direction and turn off the buzzer*/
void Buzzer_init(void);

/* turn the buzzer on or off */
void Buzzer_on(void);
void Buzzer_off(void);

#endif

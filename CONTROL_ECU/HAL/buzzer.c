/*-------------------------------------------------------------------
 [FILE NAME]: buzzer.c
 [AUTHOR(S)]: Zyad Nezar
 [DATE CREATED]: 2/11/2022
 [DESCRIPTION]: Source file for Buzzer driver
 -------------------------------------------------------------------*/

#include "buzzer.h"
#include "../MCAL/gpio.h"

void Buzzer_init(void){
	GPIO_setupPinDirection(BUZZER_PORT_ID,BUZZER_PIN_ID,PIN_OUTPUT);
	GPIO_writePin(BUZZER_PORT_ID,BUZZER_PIN_ID,LOGIC_LOW);
}

void Buzzer_on(void){
	GPIO_writePin(BUZZER_PORT_ID,BUZZER_PIN_ID,LOGIC_HIGH);
}

void Buzzer_off(void){
	GPIO_writePin(BUZZER_PORT_ID,BUZZER_PIN_ID,LOGIC_LOW);
}

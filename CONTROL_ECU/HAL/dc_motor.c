/*-------------------------------------------------------------------
 [FILE NAME]: dc_motor.c
 [AUTHOR(S)]: Zyad Nezar
 [DATE CREATED]: 9/10/2022
 [DESCRIPTION]: Source file for DC MOTOR driver
 -------------------------------------------------------------------*/

/*----------------------------INCLUDES----------------------------*/

#include "dc_motor.h"

#include "../common_macros.h" /* To use common macros like GET_BIT */
#include "../std_types.h"
#include "../MCAL/gpio.h"   /* To configure the GPIO pins */
#include "../MCAL/pwm.h"   /* To generate the PWM for the motor */

void DcMotor_Init(void) {

	/* Setting the direction for the INPUT1/2 Pins of the motor as output */

	GPIO_setupPinDirection(DC_MOTOR_PORT_ID, DC_MOTOR_INPUT1_PIN_ID,
			PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_PORT_ID, DC_MOTOR_INPUT2_PIN_ID,
			PIN_OUTPUT);

	/* Stop the motor at the beginning */

	DcMotor_Rotate(M_STOPPED);
}

void DcMotor_Rotate(DcMotor_State state) {

	/* Setting the rotation direction of the motor */

	GPIO_writePin(DC_MOTOR_PORT_ID, DC_MOTOR_INPUT1_PIN_ID, GET_BIT(state, 0));
	GPIO_writePin(DC_MOTOR_PORT_ID, DC_MOTOR_INPUT2_PIN_ID, GET_BIT(state, 1));

	/* Generating the pwm with the desired speed precentage */
 if(state == M_STOPPED){
	PWM_Timer0_Start(0);
 }
 else{
	 PWM_Timer0_Start(100);
 }
}

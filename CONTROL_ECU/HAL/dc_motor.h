/*-------------------------------------------------------------------
 [FILE NAME]: dc_motor.h
 [AUTHOR(S)]: Zyad Nezar
 [DATE CREATED]: 9/10/2022
 [DESCRIPTION]: Header file for DC MOTOR driver
 -------------------------------------------------------------------*/

#ifndef DC_MOTOR_H
#define DC_MOTOR_H

/*----------------------------INCLUDES----------------------------*/

#include "../std_types.h"

/*----------------------------DEFINITIONS----------------------------*/

#define DC_MOTOR_PORT_ID  PORTB_ID
#define DC_MOTOR_INPUT1_PIN_ID PIN0_ID
#define DC_MOTOR_INPUT2_PIN_ID PIN1_ID

/*----------------------------ENUMS----------------------------*/

/*-------------------------------------------------------------------
 [Enum Name]: DcMotor_State
 [Description]: This enum is responsible for the choosing the desired
 state or rotation direction of the motor
 -------------------------------------------------------------------*/

typedef enum {
	M_STOPPED, A_CW, CW
} DcMotor_State;

/*----------------------------FUNCTION DECLARATIONS----------------------------*/

/*-------------------------------------------------------------------
 [Function Name]: DcMotor_init
 [Description]: Function responsible for initializing the DC MOTOR
 [Args]: void
 [Returns]: void
 -------------------------------------------------------------------*/

void DcMotor_Init(void);

/*-------------------------------------------------------------------
 [Function Name]: DcMotor_Rotate
 [Description]: Function responsible for configuring the direction
 and speed of the motor
 [Args]: DcMotor_State state: direction/state of the motor
 uint8 speed: Desired speed of the motor (as precentage)
 [Returns]: void
 -------------------------------------------------------------------*/

void DcMotor_Rotate(DcMotor_State state);

#endif /* DC_MOTOR_H */

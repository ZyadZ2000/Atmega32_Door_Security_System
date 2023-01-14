/*-------------------------------------------------------------------
 [FILE NAME]: gpio.h
 [AUTHOR(S)]: Zyad Nezar
 [DATE CREATED]: 9/10/2022
 [DESCRIPTION]: Header file for GPIO driver
 -------------------------------------------------------------------*/

#ifndef GPIO_H_
#define GPIO_H_

/*----------------------------INCLUDES----------------------------*/

#include "../std_types.h"

/*----------------------------DEFINITIONS----------------------------*/

#define NUM_OF_PORTS           4
#define NUM_OF_PINS_PER_PORT   8

#define PORTA_ID               0
#define PORTB_ID               1
#define PORTC_ID               2
#define PORTD_ID               3

#define PIN0_ID                0
#define PIN1_ID                1
#define PIN2_ID                2
#define PIN3_ID                3
#define PIN4_ID                4
#define PIN5_ID                5
#define PIN6_ID                6
#define PIN7_ID                7

/*----------------------------ENUMS----------------------------*/

/*-------------------------------------------------------------------
 [Enum Name]: GPIO_PinDirectionType
 [Description]: This enum is responsible for choosing the direction
 type of the pin
 -------------------------------------------------------------------*/

typedef enum {
	PIN_INPUT, PIN_OUTPUT
} GPIO_PinDirectionType;

/*-------------------------------------------------------------------
 [Enum Name]: GPIO_PortDirectionType
 [Description]: This enum is responsible for choosing the direction
 type of the whole port
 -------------------------------------------------------------------*/

typedef enum {
	PORT_INPUT, PORT_OUTPUT = 0xFF
} GPIO_PortDirectionType;

/*----------------------------FUNCTION DECLARATIONS----------------------------*/

/*-------------------------------------------------------------------
 [Function Name]: GPIO_setupPinDirection
 [Description]: Setup the direction of the required pin input/output
 If the input port number or pin number are not correct, The function will not handle the request
 [Args]: uint8 port_num: Number of the chosen port
 uint8 pin_num: Number of the chosen pin
 GPIO_PinDirectionType direction: The desired direction Type
 [Returns]: void
 -------------------------------------------------------------------*/

void GPIO_setupPinDirection(uint8 port_num, uint8 pin_num,
		GPIO_PinDirectionType direction);

/*-------------------------------------------------------------------
 [Function Name]: GPIO_writePin
 [Description]: Write the value Logic High or Logic Low on the required pin.
 If the input port number or pin number are not correct, The function will not handle the request
 If the pin is input, this function will enable/disable the internal pull-up resistor
 [Args]: uint8 port_num: Number of the chosen port
 uint8 pin_num: Number of the chosen pin
 uint8 value: The desired output value on the pin high/low
 [Returns]: void
 -------------------------------------------------------------------*/
void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value);

/*-------------------------------------------------------------------
 [Function Name]: GPIO_readPin
 [Description]: Read and return the value for the required pin, it should be Logic High or Logic Low
 If the input port number or pin number are not correct, The function will not return low
 [Args]: uint8 port_num: Number of the chosen port
 uint8 pin_num: Number of the chosen pin
 [Returns]: uint8 reading
 -------------------------------------------------------------------*/

uint8 GPIO_readPin(uint8 port_num, uint8 pin_num);

/*-------------------------------------------------------------------
 [Function Name]: GPIO_setupPortDirection
 [Description]: Setup the direction of the required port all pins input/output
 If the input port number is not correct, The function will not handle the request
 [Args]: uint8 port_num: Number of the chosen port
 GPIO_PortDirectionType direction: PORT_INPUT or PORT_OUTPUT
 [Returns]: void
 -------------------------------------------------------------------*/

void GPIO_setupPortDirection(uint8 port_num, GPIO_PortDirectionType direction);

/*-------------------------------------------------------------------
 [Function Name]: GPIO_writePort
 [Description]: Write the value on the required port
 If any pin in the port is output pin the value will be written
 If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor
 If the input port number is not correct, The function will not handle the request
 [Args]: uint8 port_num: Number of the chosen port
 uint8 value: Value to be written on the port
 [Returns]: void
 -------------------------------------------------------------------*/

void GPIO_writePort(uint8 port_num, uint8 value);

/*-------------------------------------------------------------------
 [Function Name]: GPIO_readPort
 [Description]: Read and return the value of the required port
 If the input port number is not correct, The function will return ZERO value
 [Args]: uint8 port_num: Number of the chosen port
 [Returns]: uint8 reading
 -------------------------------------------------------------------*/

uint8 GPIO_readPort(uint8 port_num);

#endif /* GPIO_H_ */

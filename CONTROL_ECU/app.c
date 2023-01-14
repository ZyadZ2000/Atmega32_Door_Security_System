#include "HAL/buzzer.h"
#include "HAL/dc_motor.h"
#include "HAL/external_eeprom.h"
#include "MCAL/timer1.h"
#include "MCAL/twi.h"
#include "MCAL/uart.h"
#include <avr/io.h>
#include <string.h>
#include <util/delay.h>

Timer1_ConfigType timer1_config = { 0, 8192, PRESCALE_1024, COMPARE };
uint8 g_tick = 0;

void count(void) {
	g_tick++;
}

int main(void) {
	uint8 valid = 0;
	uint8 recieved_request; /* variable to recieve the request from the HMI_ECU */
	uint8 recieved_option; /* variable to recieve the selected menu option from the HMI_ECU */
	uint8 recieved_password[6]; /* array to store the sent password */
	uint8 recieved_re_password[6];
	uint8 eeprom_password[6]; /* array to retrieve the password from the eeprom*/
	uint8 flag = 0;
	uint8 i;
	TWI_ConfigType twi_config = { 0b00000001, 400 };
	TWI_init(&twi_config);
	UART_ConfigType Config_Ptr = { BITS_8, NO_PARITY, BITS_1, 9600 };
	UART_init(&Config_Ptr);
	Buzzer_init();
	DcMotor_Init();
	Timer1_setCallBack(count);
	SREG |= (1 << 7);
	while (1) {
		valid = 0;
		recieved_request = UART_recieveByte();
		if (recieved_request == 'm') {
			UART_receiveString(recieved_password);
			UART_receiveString(recieved_re_password);
			if (!strcmp(recieved_password, recieved_re_password)) {
				for (i = 0; i < 5; i++) {
					EEPROM_writeByte(0x0011 + i, recieved_password[i]);
					_delay_ms(20);
				}
				UART_sendByte('t');
			} else {
				UART_sendByte('f');
			}
		} else if (recieved_request == 'v') {
			UART_receiveString(recieved_password);
			for (i = 0; i < 5; i++) {
				EEPROM_readByte(0x0011 + i, &eeprom_password[i]);
				_delay_ms(20);
			}
			eeprom_password[5] = '\0';
			if (!strcmp(recieved_password, eeprom_password)) {
				UART_sendByte('t');
				valid = 1;
			} else {
				UART_sendByte('f');
			}
			if (valid) {
				recieved_option = UART_recieveByte();
				if (recieved_option == '+') {
					DcMotor_Rotate(CW);
					Timer1_init(&timer1_config);
					while (g_tick < 15)
						;
					g_tick = 0;
					DcMotor_Rotate(M_STOPPED);
					while (g_tick < 3)
						;
					g_tick = 0;
					DcMotor_Rotate(A_CW);
					while (g_tick < 15)
						;
					g_tick = 0;
					DcMotor_Rotate(M_STOPPED);
					Timer1_deInit();
				}
			}
		} else if (recieved_request == 'w') {
			Buzzer_on();
			Timer1_init(&timer1_config);
			while (g_tick < 60)
				;
			g_tick = 0;
			Buzzer_off();
			Timer1_deInit();
		}
	}
	return 0;
}

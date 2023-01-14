#include <stdio.h>
#include <string.h>
#include "MCAL/uart.h"
#include "HAL/lcd.h"
#include "MCAL/gpio.h"
#include "MCAL/timer1.h"
#include "HAL/keypad.h"
#include <avr/io.h>
#include <util/delay.h>

Timer1_ConfigType timer1_config = { 0, 8192, PRESCALE_1024, COMPARE };
uint8 g_tick = 0;


/* Function to count ticks every second */

void count(void) {
	g_tick++;
}

/* Function to get the password and display * on LCD */

void enterPass(uint8 *pass) {
	uint8 passCount = 0;
	uint8 pressedKey = ' ';
	while (passCount < 5) {
		pass[passCount] = KEYPAD_getPressedKey();
		LCD_displayCharacter('*');
		passCount++;
		/* if Button is pressed for 250ms it's considered a new press */
		_delay_ms(250);
	}
	pass[passCount] = '\0';

	/* '=' as the enter button */
	while (pressedKey != '='){
		pressedKey = KEYPAD_getPressedKey();
		_delay_ms(250);
	};
}

void register_menu(void) {
	uint8 passMatched = 'f';  /* to check if the two passwords are matched initialized to false */
	uint8 password[6];  /* array to store the enterd password */
	uint8 re_password[6]; /* array to store the re-enterd password */
	do {
		LCD_clearScreen();
		LCD_displayStringRowColumn(0, 0, "Plz enter pass:");
		LCD_moveCursor(1, 0);
		enterPass(password);
		LCD_clearScreen();
		LCD_displayStringRowColumn(0, 0, "Plz re-enter the");
		LCD_moveCursor(1, 0);
		LCD_displayString("same pass: ");
		enterPass(re_password);
		UART_sendByte('m'); /* tell the CONTROL_ECU to check matching */
		UART_sendString(password);
		UART_sendByte('#');
		UART_sendString(re_password);
		UART_sendByte('#');
		passMatched = UART_recieveByte(); /* receive the matching result from the CONTROL_ECU */
	} while (passMatched != 't'); /* repeat until the two passwords are matched */
}

void options_menu(void) {
	uint8 password[6];
	uint8 valid; /* variable to check if the enterd password is correct */
	uint8 trial_count; /* variable to count the number of trials  */
	uint8 pressedKey;
	while (1) {
		LCD_clearScreen();
		trial_count = 0;
		pressedKey = ' ';
		valid = 'f';
		LCD_displayStringRowColumn(0, 0, "+ : Open Door");
		LCD_displayStringRowColumn(1, 0, "- : Change Pass");
		while (pressedKey != '+' && pressedKey != '-') {
			pressedKey = KEYPAD_getPressedKey();
			_delay_ms(250);
		}
		do {
			/* if incorrect password for 3 trials give error */
			if (trial_count == 3) {
				UART_sendByte('w'); //send warning to activate buzzer
				LCD_clearScreen();
				LCD_displayString("ERROR!!!");
				Timer1_init(&timer1_config); /* start counting seconds */
				while (g_tick < 60)
					;
				g_tick = 0;
				Timer1_deInit(); /* stop the timer */
				break;
			}
			LCD_clearScreen();
			LCD_displayStringRowColumn(0, 0, "Plz enter pass:");
			LCD_moveCursor(1, 0);
			enterPass(password);
			UART_sendByte('v'); //tell the CONTROL_ECU to validate password
			UART_sendString(password);
			UART_sendByte('#');
			valid = UART_recieveByte(); //wait for response
			trial_count++;
		} while (valid == 'f');
		LCD_clearScreen();
		if (valid == 't') {
			UART_sendByte(pressedKey); //tell the CONTROL_ECU to rotate the motor or change the password if validated
			switch (pressedKey) {
			case '+':
				LCD_displayStringRowColumn(0, 0, "Door unlocking");
				Timer1_init(&timer1_config);
				while (g_tick < 15)
					;
				g_tick = 0;
				LCD_clearScreen();
				while (g_tick < 3)
					;
				g_tick = 0;
				LCD_displayStringRowColumn(0, 0, "Door locking");
				while (g_tick < 15)
					;
				g_tick = 0;
				Timer1_deInit();
				break;
			case '-':
				register_menu();
				break;
			}
		}
	}
}

int main(void) {
	UART_ConfigType Config_Ptr = { BITS_8, NO_PARITY, BITS_1, 9600 };
	UART_init(&Config_Ptr);
	LCD_init();
	Timer1_setCallBack(count);
	SREG |= (1 << 7); /* Enable Global interrupts */
	register_menu();
	while (1) {
		options_menu();
	}
	return 0;
}

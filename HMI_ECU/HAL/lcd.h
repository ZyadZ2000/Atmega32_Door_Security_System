/*-------------------------------------------------------------------
 [FILE NAME]: lcd.h
 [AUTHOR(S)]: Zyad Nezar
 [DATE CREATED]: 9/10/2022
 [DESCRIPTION]: Header file for LCD driver
 -------------------------------------------------------------------*/

#ifndef LCD_H_
#define LCD_H_

/*----------------------------INCLUDES----------------------------*/

#include "../std_types.h"

/*----------------------------DEFINITIONS----------------------------*/

/* LCD Data bits mode configuration, its value should be 4 or 8*/
#define LCD_DATA_BITS_MODE 8

#if((LCD_DATA_BITS_MODE != 4) && (LCD_DATA_BITS_MODE != 8))

#error "Number of Data bits should be equal to 4 or 8"

#endif

/* LCD HW Ports and Pins Ids */
#define LCD_RS_PORT_ID                 PORTC_ID
#define LCD_RS_PIN_ID                  PIN0_ID

#define LCD_RW_PORT_ID                 PORTC_ID
#define LCD_RW_PIN_ID                  PIN1_ID

#define LCD_E_PORT_ID                  PORTC_ID
#define LCD_E_PIN_ID                   PIN2_ID

#define LCD_DATA_PORT_ID               PORTA_ID

#if (LCD_DATA_BITS_MODE == 4)

#define LCD_DB4_PIN_ID                 PIN3_ID
#define LCD_DB5_PIN_ID                 PIN4_ID
#define LCD_DB6_PIN_ID                 PIN5_ID
#define LCD_DB7_PIN_ID                 PIN6_ID

#endif

/* LCD Commands */
#define LCD_CLEAR_COMMAND                    0x01
#define LCD_GO_TO_HOME                       0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE        0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE         0x28
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT1   0x33
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT2   0x32
#define LCD_CURSOR_OFF                       0x0C
#define LCD_CURSOR_ON                        0x0E
#define LCD_SET_CURSOR_LOCATION              0x80

/*----------------------------FUNCTION DECLARATIONS----------------------------*/

/*-------------------------------------------------------------------
 [Function Name]: LCD_init
 [Description]: Function responsible for initializing the ADC
 Setup the LCD pins directions by use the GPIO driver
 Setup the LCD Data Mode 4-bits or 8-bits
 [Args]: void
 [Returns]: void
 -------------------------------------------------------------------*/

void LCD_init(void);

/*-------------------------------------------------------------------
 [Function Name]: LCD_sendCommand
 [Description]: Send the required command to screen
 [Args]: uint8 command: The desired command
 [Returns]: void
 -------------------------------------------------------------------*/

void LCD_sendCommand(uint8 command);

/*-------------------------------------------------------------------
 [Function Name]: LCD_displayCharacter
 [Description]: Send and display the required character to screen
 [Args]: uint8 data: The desired character
 [Returns]: void
 -------------------------------------------------------------------*/

void LCD_displayCharacter(uint8 data);

/*-------------------------------------------------------------------
 [Function Name]: LCD_displayString
 [Description]: Send and display the required string to screen
 [Args]: const char *Str: The desired string
 [Returns]: void
 -------------------------------------------------------------------*/

void LCD_displayString(const char *Str);

/*-------------------------------------------------------------------
 [Function Name]: LCD_moveCursor
 [Description]: Move the cursor to a specified row and column index on the screen
 [Args]: uint8 row: Number of the chosen row
 uint8 col: Number of the chosen column
 [Returns]: void
 -------------------------------------------------------------------*/

void LCD_moveCursor(uint8 row, uint8 col);

/*-------------------------------------------------------------------
 [Function Name]: LCD_displayStringRowColumn
 [Description]: Display the required string in a specified row and column index on the screen
 [Args]: uint8 row: Number of the chosen row
 uint8 col: Number of the chosen column
 const char *Str: The desired string
 [Returns]: void
 -------------------------------------------------------------------*/

void LCD_displayStringRowColumn(uint8 row, uint8 col, const char *Str);

/*-------------------------------------------------------------------
 [Function Name]: LCD_intgerToString
 [Description]: Display the required decimal value on the screen
 [Args]: int data: the required decimal value
 [Returns]: void
 -------------------------------------------------------------------*/

void LCD_intgerToString(int data);

/*-------------------------------------------------------------------
 [Function Name]: LCD_clearScreen
 [Description]: Send the clear command to screen
 [Args]: void
 [Returns]: void
 -------------------------------------------------------------------*/

void LCD_clearScreen(void);

#endif /* LCD_H_ */

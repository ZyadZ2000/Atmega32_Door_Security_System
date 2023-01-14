# Atmega32_Door_Security_System

This system is a door security systems that unlocks the door using a password

# System Description:

The system consists of two ECUs, one for human machine interface, the other is for control.

It lets you create a password, then gives you two options, either to open the door or change the password, both of those options require the original password,
if the password is false for 3 consecutive times, a warning message is displayed

*Note: Password is enterd by '=' on the keypad*

# Implemented Drivers: GPIO, UART, I2C, Timer, Keypad, DC Motor, EEPROM, LCD, Buzzer

<img src="https://user-images.githubusercontent.com/85132955/212493424-516f53a6-db42-4a4a-b908-2ab111cc272e.png" style="display: block; width: 80%;">


<img src="https://user-images.githubusercontent.com/85132955/212493441-bf32924b-d183-4037-aa98-5a3d789548c2.png" style="display: block; width: 50%;">


# How to use:

Download the project along with the proteus simulation <a href="https://www.mediafire.com/file/dtg1kb8p13hi09y/Final_Project.rar/file">Here</a>.

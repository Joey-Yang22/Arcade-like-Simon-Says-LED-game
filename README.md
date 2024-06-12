# Arcade-like-Simon-Says-LED-game

Introduction:
This game is a Simon says / memorization game. This project consists of having the player be given a pattern of LEDs and the user has to memorize the pattern that has been outputted. The game starts with it being set to the main menu, where the user has the option to play music by pressing the joystick. An 16x2 LCD display will indicate when we are in the main menu, when we are playing, when we lose/win, and when the music has been turned on or off. The game will start once the user has pressed down on the joystick. An LED matrix will indicate how many LEDs there will be / the round number. The pattern will start with 1 LED shown. As the user gets the pattern correctly, the number of LEDs will increase by 1 and the period that lights up the LEDs will increase. Original LED period is 1s. Between rounds 5-9, it will have a period of 0.7s. And finally between rounds 10-15, it will have a period of 0.4s. There are 15 rounds in total, and once the user manages to memorize a 15 LED pattern, there will be a win sound, and the 16x2 LCD display will show that they have won. After 5 seconds, it will go back to the main menu. If the user loses (gets the pattern incorrectly), then the LCD display will show an option to insert tokens (up on the joystick), where the player can insert 5 tokens to be able to play at the round they had lost to. If the user doesn’t insert 5 tokens within 7 seconds, the game will go back to the main menu. If they manage to get 5 tokens, the user can now start where they left off and try and win, but once they lose again, they unfortunately cannot try again and will be sent back to the main menu.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Specific hardware Build-ups:
Hardware build-up | Passive Buzzer: Before the game starts, the user is able to play a menu song by pressing on the joystick. This menu song will repeat again and again until the player presses the joystick again to turn it off, or when the user begins playing the game. I also used it to play a tune when they lose and when they win the game.The song that I used is based off an undertale OST. Here’s the link on what it sounds like: https://www.youtube.com/watch?v=BLBfWuJ3s7g&list=PLF_hYfaUn2BZJyEmkQ-BmgAIMnL9al6dj&index=3&ab_channel=8-bit-musik


Hardware build-up | LED matrix: The LED matrix is used to show the round number / how many LEDs will show when they are playing. It also will show a smiley face when they are in the main menu or win the game, and a frown face when they lose the game. When they win the game, the face actually blinks until the game is back to the main menu.


Hardware build-up | Shift Register: Since I’m using the LED matrix on pins 13 - 8 and the LCD 16x2 display on pins 7-2, and also 4 buttons and a 2 joystick options on all of PINC, I am using the shift register to be able to output my 4 LEDs. I have the data in the pin PORTB0, my clock on PORTD1, and my latch on PORTD0. This made me unable to use serialATmega library anymore, so if I needed to print something for debugging purposes, then my LEDs will just have to be off for the time being.


Software build-up | Period increase: The period that lights up the LEDs when you start the game originally starts at 1s. During the game, the period of the LEDs increases. Rounds 5-9 has a 0.7s period, and rounds 10-15 has 0.4s period.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

User Guide
For my inputs, we have 4 buttons, with each button corresponding to a given LED, and we have a joystick, where pressing on the joystick will toggle the music in the main menu, pushing down on the joystick starts the game, and pushing up only activates during the insert token lose screen. For my outputs, I am using an LED matrix to show the round number/the # of LEDs being shown in that round, and a smiley face when they win and a frown face when they lose
Pattern of the LEDs will be randomized everytime the user has started playing. Buttons do not work unless the game has been started and will not work until the given pattern has finished being outputted. So during the main menu the buttons will not make a sound or light up an LED. In contrast to the music toggle, once the game has started, the user is unable to play the tune even if they try clicking the joystick. Music toggle will only be available during the main menu. Insert token will not work unless we are in the state of showcasing our try again/lose screen. Inserting tokens during the game over the lost screen will not make the game go back to play mode.


Hardware Components Used
Buttons x4
Red LED  x1
Blue LED  x1
Green LED  x1
Yellow LED  x1
LED matrix  x1
Passive buzzer x1
Joystick  x1
Shift register  x1
16x2 LCD Display  x1
1k resistor	x8
10k resistor  x2
A bunch of wires


Software Libraries Used
Externally-provided libraries:
LCD.h - to initialize LCD display
timerISR.h - to be able to have/use concurrent state machines
periph.h - to be able to read my joystick
serialATmega.h - to be able to print serially in my code
spiAVR.h - to be able to send data into my LED matrix
stdlib.h - to use the srand() and rand() function to have a different pattern for the LEDs everytime the user starts the game.
help.h - my own created helper function that gives me the ability to control the LED matrix and the shift register.

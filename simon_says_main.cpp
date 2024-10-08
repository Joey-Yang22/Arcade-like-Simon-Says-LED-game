/*       Name: Joey Yang | Email: joey.yang.j@gmail.com:



 *         Project Description: My version of simon says where we replicate a pattern given to us

 *        

 *         I acknowledge all content contained herein, excluding template or example code, is my own original work.

 *

 *         Demo Link: <https://youtu.be/ZUVSq-4shMw?si=4JycsWiBlWHHipzV>

 */

#include "timerISR.h"
#include "helper.h"
#include "periph.h"
#include "LCD.h"
#include "serialATmega-1.h"
#include "spiAVR.h"
#include "help.h"

#include <stdlib.h>

void MUSICOFF()
{
    ICR1 = 100000;
    OCR1A = 100000 / 2;
}



int rando;              //random integer that is increasing over time to change the seed


int tokens;

int NONOTE = 0;
int C4 = 7662;
int D4 = 6825;
int Dsharp4 = 6430;
int E4 = 6078;
int F4 = 5730;
int G4 = 5101;
int A4 = 4544;
int B4 = 4056;
int C5 = 3823;
int D5 = 3406;

int BEGIN[] = {F4, A4, C4, A4};                                             //----------------------------------//
int tempo[] = {10, 8, 10, 10};                                             //                                  //
int TUNE1[] = {F4, NONOTE, F4, G4, A4, F4, G4, NONOTE, G4, A4, F4, C4};     //            MY MENU MUSIC         //
int tempo1[] = {10, 1, 5, 5, 10, 10, 10, 1, 5, 5, 10, 10};                  //           __          __         // 
int TUNE2[] = {F4, NONOTE, F4, G4, A4, D5, C5, G4};                         //           |            |         //     
int tempo2[] = {10, 1, 5, 5, 10, 10, 20, 20};                               //                  |               // 
int TUNE3[] = {F4, NONOTE, F4, G4, E4, C4, D4, D5};                         //          \              /        // 
int tempo3[] = {10, 1, 5, 5, 10, 10, 20, 20};                               //            ------------          //
                                                                            //----------------------------------//


int WINTUNE[] = {C4, D4, E4, G4, E4, G4};       //my win song
int wintempo[] = {3, 3, 3, 8, 3, 20};

int LOSETUNE[] = {F4, E4, Dsharp4, D4};         //my lose song
int losetempo[] = {8, 8, 8, 8};

int again;


int patternSize = 0;                    //SAME IDEA AS INPUTS
int inputSize = 0;                      //TO SEE IF INPUTS ARE = TO PATTERN ARRAY SIZE

int pattern[15] = {};                   //array for the actual pattern they need to replicate
int userInput[15] = {};                 //array for the userinput

bool play;           //tells if the game is playing or not
bool winOrlose;      //bool to decide if they lost the round or won the round
int loseScreenCount; //count to measure how long the lose screen shows up for.

bool won;            //bool to decide if they had won the game
int winScreenCount;  //count to measure how long the win screen shows up for.

int score;          //integer for the score
int tempScore;      //integer to save the score of the game

int j;              //need to go through my pattern arrays
int k;              //(just incase) need to go through my userinput arrays

int arrayCount;     //count to output as many lights as the score;

int i;              //need to go through my music arrays
int count;          //count to see if it has reached the end of the array

int repeat;         //count to keep track of repeating the tune

int count2;         //random count variable (NOT NEEDED AT THE MOMENT)

int press;          //integer to see if the user has pressed or not

int musicCount;     //count to only output the music text for only a few seconds
int musicONorOFF;   //int to see if music is on or off

int LEDcount;       //count to track how long the LEDs will light up for randomly

int displayCount = 0; //makes sure that the matrix display outputs once.

int LEDperiod = 0;   //count to increase the timer for how fast the LEDs are showing the pattern


int lcdCount;       //count to display LCD once

int winCount;       //count to show that they won the round


#define NUM_TASKS 5 //TODO: Change to the number of tasks being used


//Task struct for concurrent synchSMs implmentations
typedef struct _task{
	signed 	 char state; 		//Task's current state
	unsigned long period; 		//Task period
	unsigned long elapsedTime; 	//Time elapsed since last task tick
	int (*TickFct)(int); 		//Task tick function
} task;


//TODO: Define Periods for each task
// e.g. const unsined long TASK1_PERIOD = <PERIOD>
const unsigned long TASK1_PERIOD = 100;
const unsigned long TASK2_PERIOD = 100;
const unsigned long TASK3_PERIOD = 100;
const unsigned long TASK4_PERIOD = 100;
const unsigned long TASK5_PERIOD = 100;

const unsigned long GCD_PERIOD = 100;//TODO:Set the GCD Period

task tasks[NUM_TASKS]; // declared task array with 5 tasks


void TimerISR() {
	for ( unsigned int i = 0; i < NUM_TASKS; i++ ) {                   // Iterate through each task in the task array
		if ( tasks[i].elapsedTime == tasks[i].period ) {           // Check if the task is ready to tick
			tasks[i].state = tasks[i].TickFct(tasks[i].state); // Tick and set the next state for this task
			tasks[i].elapsedTime = 0;                          // Reset the elapsed time for the next tick
		}
		tasks[i].elapsedTime += GCD_PERIOD;                        // Increment the elapsed time by GCD_PERIOD
	}
}

//START TASK
enum start{start, IDLE, PLAY};
int start_tick(int state);

int start_tick(int state)
{
    switch(state){  //state transitions
        case start:
            state = IDLE;
            count2 = 0;
            break;

        case IDLE:
            if((ADC_read(5) >= 0 && ADC_read(5) <= 200) && (play == false) && (winOrlose == false) && (won == false))
            {
                state = PLAY;
                score = 0;
                MUSICOFF();
                play = true;
                off();
                LEDperiod = 10;
            }
        break;

        case PLAY:
        /*if(won)
        {
            state = IDLE;
            LEDperiod = 10;
            play = false;
        }
        if(winOrlose)
        {
            state = IDLE;
            play = false;
            LEDperiod = 10;
        }*/

        if(!play){
            state = IDLE;
            LEDperiod = 10;
        }

        break;

        default:
            state = IDLE;

    }

    switch(state){  //state actions

       case IDLE:
       if(!won && !winOrlose)
        {
        if(count2 <= 10){
            outputRed();
            count2++;
        }
        if(count2 > 10 && count2 <= 20){
            outputBlue();
            count2++;
        }
        if(count2 > 20 && count2 <= 30){
            outputGreen();
            count2++;
        }
        if(count2 > 30 && count2 <= 40){
            outputYellow();
            count2++;
        }
        if(count2 > 40 && count2 <= 50){
            off();
            count2++;

        }
        if(count2 > 50 && count2 <= 60){
            count2 = 0;
        }       

        arrayCount = 0;
        inputSize = 0;

        rando++;
        if(rando > 99999){
            rando = 0;
        }
      }  
        break;

        case PLAY:
        if(score > 15){
            won = true;
            score = 0;
            clear();
        }
        
        break;


        default:
            break;

    }
    return state;
}


//LCD TASK
enum lcd{lcd_start, WELCOME, GAME, MUSIC, WIN, LOSE, GAMEOVER};
int lcd_tick(int state);

int lcd_tick(int state)
{
    char token_char = tokens + '0';
    switch(state) //state transitions
    {
        

        case lcd_start:
            state = WELCOME;
            musicCount = 0;
            musicONorOFF = 0;
            displayCount = 0;
            lcdCount = 0;
            winScreenCount = 0;
            again = 0;
        break;

        case WELCOME:
            if(play)
            {
                lcd_clear();
                state = GAME;
                lcdCount = 0;
                displayCount = 0;
            }
            else if(ADC_read(0) >= 0 && ADC_read(0) <= 200) //if button is pressed
            {
                state = MUSIC;
                musicONorOFF++;
                musicCount = 0;
                lcd_clear();
            }
        break;

        case MUSIC:
        if(musicCount > 15)
        {
            state = WELCOME;
            musicCount = 0;
            lcd_clear();
            lcdCount = 0;
        }
        break;

        case GAME:
          if(won)
            {
                state = WIN;
                lcdCount = 0;
                displayCount = 0;
                lcd_clear();
                clear();

            }
            if(winOrlose)
            {
                state = LOSE;
                lcdCount = 0;
                displayCount = 0;
                lcd_clear();
                clear();
            }
        break;

        case WIN:
        
        if(winScreenCount > 100){
            state = WELCOME;
            play = false;
            won = false;
            lcd_clear();
            lcdCount = 0;
            winScreenCount = 0;
            displayCount = 0;
            again = 0;
        }
        break;

        case LOSE:
        if(tokens == 5)
        {
            state = GAME;
            winOrlose = false;
            displayCount = 0;
            lcd_clear();
            loseScreenCount = 0;
        }
        if(loseScreenCount > 150)
        {
            state = WELCOME;
            play = false;
            winOrlose = false;
            lcd_clear();
            clear();
            lcdCount = 0;
            loseScreenCount = 0;
            displayCount = 0;
            tokens = 0;
            again = 0;
        }
    }

    switch(state) //state actions
    {
        case WELCOME:
        if(lcdCount < 1)
        {
           lcd_write_str("Welcome to");
           lcd_goto_xy (1, 3);
           lcd_write_str("Simon Says!");
           lcd_goto_xy (1, 15);
           lcd_write_str("  ");
        }
        if(displayCount < 1)
        {
            outNumber(0);
        }
        displayCount++;
        lcdCount++;
        break;

        case GAME:
        if(lcdCount < 1)
        {
            lcd_goto_xy (0, 0);
            lcd_write_str("PLAY MODE");
        }
        if(displayCount < 1)
        {
            outNumber(score);
        }
        displayCount++;
        lcdCount++;
        break;

        case WIN:
        if(lcdCount < 1)
        {
            lcd_goto_xy(0, 0);
            lcd_write_str("YOU WIN");
            lcd_goto_xy(1, 0);
            lcd_write_str("NICE WORK!!");
        }
        if(displayCount < 1)
        {
            outNumber(score);
        }
        displayCount++;
        lcdCount++;
        winScreenCount++;
        break;

        case LOSE:
        if((lcdCount < 1) && (again == 0)){
            lcd_goto_xy(0, 0);
            lcd_write_str("YOU LOST");
            lcd_goto_xy(1, 0);
            lcd_write_str("INSERT TOKEN: ");
            token_char = tokens + '0';
            lcd_write_character(token_char);
        }
        if((lcdCount < 1) && (again == 1))
        {
            //lcd_clear();
            lcd_goto_xy(0, 0);
            lcd_write_str("GAME OVER");
            lcd_goto_xy(1, 0);
            lcd_write_str("NICE TRY");
        }
        if(displayCount < 1)
        {
            frown();
        }
        displayCount++;
        lcdCount++;
        loseScreenCount++;

        break;

        case MUSIC:
        if((musicONorOFF % 2 == 1) && (musicCount < 1))
        {
            lcd_write_str("Music: ON");
            musicCount++;
        }
        else if((musicONorOFF % 2 == 0) && (musicCount < 1))
        {
            lcd_write_str("Music: OFF");
            musicCount++;
        }
        musicCount++;
        break;

    }
    return state;
}


//LED BUTTON TASK
enum button{button_start, WAIT1, YELLOW, GREEN, BLUE, RED, UP};
int button_tick(int state);

int button_tick(int state)
{
    switch(state)
    {
        case button_start:
            state = WAIT1;
            displayCount = 0;
            k = 0;
            inputSize = 0;
        break;

        case WAIT1:
            if(ADC_read(5) >= 800 && ADC_read(5) <= 1023)
            {
                state = UP;
                if(winOrlose && again == 0)
                {
                    tokens++;
                    lcdCount = 0;
                }
            }
            if(!(GetBit(PINC, 1)) && play && !won && !winOrlose)
            {
                userInput[inputSize] = 0;
                state = YELLOW;
            }
            if(!(GetBit(PINC, 2)) && play && !won && !winOrlose)
            {
                userInput[inputSize] = 1;
                state = GREEN;
            }
            if(!(GetBit(PINC, 3)) && play && !won && !winOrlose)
            {
                userInput[inputSize] = 2;           
                state = BLUE;
            }
            if(!(GetBit(PINC, 4)) && play && !won && !winOrlose)
            {
                userInput[inputSize] = 3;           
                state = RED;
            }
        break;

        case UP:
        if(ADC_read(5) <= 600 && ADC_read(5) >= 500)
        {
            state = WAIT1;
            lcdCount = 0;
            
        }
        break;


        case YELLOW:
        if((GetBit(PINC, 1)))
        {
            off();
            inputSize++;

            state = WAIT1;
            MUSICOFF();
        }
        break;

        case GREEN:
        if((GetBit(PINC, 2)))
        {
            off();
            inputSize++;

            state = WAIT1;
            MUSICOFF();
        }
        break;

        case BLUE:
        if((GetBit(PINC, 3)))
        {
            off();
            inputSize++;

            state = WAIT1;
            MUSICOFF();
        }
        break;

        case RED:
        if((GetBit(PINC, 4)))
        {
            off();
            inputSize++;

            state = WAIT1;
            MUSICOFF();
        }
        break;


        default:
            state = button_start;

    }

    switch(state)
    {
        case WAIT1:
        break;


        case YELLOW:
            outputYellow();
                ICR1 = C4;
                OCR1A = C4 / 2;

            if(userInput[inputSize] != pattern[inputSize])
            {
                winOrlose = true;
            }
        break;

        case GREEN:
            outputGreen();
                ICR1 = D4;
                OCR1A = D4 / 2;

            if(userInput[inputSize] != pattern[inputSize]){
                winOrlose = true;
            }
        break;

        case BLUE:
            outputBlue();
                ICR1 = E4;
                OCR1A = E4 / 2;

            if(userInput[inputSize] != pattern[inputSize]){
                winOrlose = true;
            }
        break;

        case RED:
            outputRed();
                ICR1 = F4;
                OCR1A = F4 / 2;

            if(userInput[inputSize] != pattern[inputSize]){
                winOrlose = true;
            }
        break;


        default:
        break;

    }

    return state;
}


//MUSIC TASK
enum buzz{buzz_start, ONPRESS, PRESS, OFFPRESS, WAIT, WINSONG, LOSESONG};
int buzz_tick(int state);

int buzz_tick(int state)
{
    switch(state)   //state transitions
    {
        case buzz_start:
            state = WAIT;
            count = 0;
            i = 0;
            repeat = 0;
        break;

        case WAIT:
            if((ADC_read(0) >= 0 && ADC_read(0) <= 200) && (play == false))
            {
                state = ONPRESS;
            }
            else
            {
                state = WAIT;
            }
            if(won){
                state = WINSONG;
                count = 0;
                i = 0;
            }
            if(winOrlose){
                state = LOSESONG;
                count = 0;
                i = 0;
            }

        break;

        case LOSESONG:
        if(!winOrlose){
            state = WAIT;
            count = 0;
            i = 0;
        }
        break;

        case WINSONG:
        if(!won)
        {
            state = WAIT;
            count = 0;
            i = 0;
        }
        break;

        case ONPRESS:
         if(ADC_read(0) <= 1023 && ADC_read(0) >= 800)
            {
                state = PRESS;
            } 
        break;

        case PRESS:
           if(ADC_read(0) >= 0 && ADC_read(0) <= 200)
            {
                state = OFFPRESS;
                 OCR1A = 10000;
                 i = 0;
                 count = 0;
                 repeat = 0;
            }
            if(play)
            {
                state = WAIT;
            }
        break;

        case OFFPRESS:
            if(ADC_read(0) <= 1023 && ADC_read(0) >= 800)
            {
                state = WAIT;
            } 
            break;

        default:
            state = buzz_start;

    }

    switch(state)   //state actions
    {
        case WAIT:
            i = 0;
            count = 0;
            
        break;

        case WINSONG:
            if(count < wintempo[i]){
                ICR1 = WINTUNE[i];
                OCR1A = WINTUNE[i] / 2;
                count++;
            }
            if(count == wintempo[i])
            {
                count = 0;
                i++;
            }
            if(i > 5){
                MUSICOFF();
            }

        break;

        case LOSESONG:
        if(count < losetempo[i]){
                ICR1 = LOSETUNE[i];
                OCR1A = LOSETUNE[i] / 2;
                count++;
            }
            if(count == losetempo[i])
            {
                count = 0;
                i++;
            }
            if(i > 3){
                MUSICOFF();
            }
        break;



        case PRESS:
        if(repeat < 2)
        {
            if(count < tempo[i])
            {
                ICR1 = BEGIN[i];
                OCR1A = BEGIN[i] / 2;
                count++;
            }
            if(count == tempo[i])
            {
                count = 0;
                i++;
            }
            if(i > 3)
            {
                i = 0;
                count = 0;
                repeat++;
            }
        }
        if(repeat == 2)
        {
            if(count < tempo1[i]){
                ICR1 = TUNE1[i];
                OCR1A = TUNE1[i] / 2;
                count++;
            }
            if(count == tempo1[i])
            {
                count = 0;
                i++;
            }
            if(i > 11) 
            {
                i = 0;
                count = 0;
                repeat++;
            }
        }
        if(repeat == 3)
        {
            if(count < tempo2[i])
            {
                ICR1 = TUNE2[i];
                OCR1A = TUNE2[i] / 2;
                count++;
            }
            if(count == tempo2[i])
            {
                count = 0;
                i++;
            }
            if(i > 7)
            {
                i = 0;
                count = 0;
                repeat++;
            }
        }
        if(repeat == 4)
        {
            if(count < tempo1[i]){
                ICR1 = TUNE1[i];
                OCR1A = TUNE1[i] / 2;
                count++;
            }
            if(count == tempo1[i])
            {
                count = 0;
                i++;
            }
            if(i > 11) 
            {
                i = 0;
                count = 0;
                repeat++;
            }
        }
        if(repeat == 5)
        {
            if(count < tempo3[i]){
                ICR1 = TUNE3[i];
                OCR1A = TUNE3[i] / 2;
                count++;
            }
            if(count == tempo3[i])
            {
                count = 0;
                i++;
            }
            if(i > 7) 
            {
                i = 0;
                count = 0;
                repeat = 0;
            }
        }
                
          
        break;

        default:
        break;
    }
    return state;
}


enum ROUNDSTART{round_start, READY, GAMEPLAY, Y, G, B, R, W, L};
int game_tick(int state);

int game_tick(int state)
{
    switch(state){
        case round_start:
            state = READY;

            won = false;
            winCount = 15;
            LEDcount = 0;
            score = 0;
            LEDperiod = 10;
            patternSize = 0;
            arrayCount = 0;
            tempScore = 0;
        break;

        case READY:
            if(play == false){
                state = READY;
            }
            else if(play == true)
            {
                state = GAMEPLAY;
                winOrlose = false;
                srand(rando);
                for(int i = 0; i < 15; i++)
                {
                    pattern[i] = rand() % 4;
                }
            }
        break;

        case W:
            if(winScreenCount > 100)
            {
                state = READY;
                won = false;
                LEDcount = 0;
            }
        break;

        case L:
        if(tokens == 5)
        {
            state = GAMEPLAY;
            off();
            again++;
            winOrlose = false; 
            tokens = 0;
            //winCount = 0;
            tempScore = score;
            score = tempScore - 1;
            arrayCount = inputSize;
        }
        if(!winOrlose)
        {
            state = READY;
            LEDcount = 0;
        }
        break;

        case GAMEPLAY:
        if(winOrlose)
        {
            state = L;
            //score = 0;
            //arrayCount = 0;
            LEDcount = 0;
        }
        if(won)
        {
            state = W;
            LEDcount = 0;
        }
        if((arrayCount < score) && winCount == 15)
        {
            if(pattern[arrayCount] == 0)
            {
                state = Y;
                arrayCount++;

                LEDcount = 0;
            }
            else if(pattern[arrayCount] == 1)
            {
                state = G;
                arrayCount++;

                LEDcount = 0;
            }
            else if(pattern[arrayCount] == 2)
            {
                state = B;
                arrayCount++;

                LEDcount = 0;
            }
            else if(pattern[arrayCount] == 3)
            {
                state = R;
                arrayCount++;
                LEDcount = 0;
            }
        }
        break;

        case Y:
        if(LEDcount >= LEDperiod)
        {
            state = GAMEPLAY;
            MUSICOFF();
            off();
            LEDcount = 0;
        }
        break;

        case G:
        if(LEDcount >= LEDperiod)
        {
            state = GAMEPLAY;
            MUSICOFF();
            off();
            LEDcount = 0;
        }
        break;

        case B:
        if(LEDcount >= LEDperiod)
        {
            state = GAMEPLAY;
            MUSICOFF();
            off();
            LEDcount = 0;

        }
        break;

        case R:
        if(LEDcount >= LEDperiod)
        {
            state = GAMEPLAY;
            MUSICOFF();
            off();
            LEDcount = 0;
        }
        break;

        
        default:
            state = round_start;
        break;
    }

    switch(state){

        case READY:
        break;

        case W:
        if(LEDcount < 10)
        {
            outAll();
        }
        if(LEDcount >= 10 && LEDcount < 20)
        {
            off();
        }
        if(LEDcount >= 20 && LEDcount < 30){
            outAll();
            clear();
            blink();
        }
        if(LEDcount >= 30 && LEDcount < 40){
            off();
            clear();
            outNumber(score);
        }
        if(LEDcount >= 40 && LEDcount < 50){
            outAll();
        }
        if(LEDcount >= 50 && LEDcount < 60){
            off();
        }
        if(LEDcount >= 60 && LEDcount < 70){
            outAll();
        }
        if(LEDcount >= 70 && LEDcount < 80){
            off();
            clear();
            blink();
        }
        if(LEDcount >= 80 && LEDcount < 90){
            outAll();
            clear();
            outNumber(score);
        }
        if(LEDcount >= 90 && LEDcount < 100){
            off();
        }
        LEDcount++;
        break;

        case L:
        if(LEDcount < 10){
            leftTwo();
        }
        if(LEDcount >= 10 && LEDcount < 20)
        {
            rightTwo();
        }
        if(LEDcount >= 20 && LEDcount < 30){
            leftTwo();
        }
        if(LEDcount >= 30 && LEDcount < 40){
            rightTwo();
        }
        if(LEDcount >= 40 && LEDcount < 50){
            leftTwo();
        }
        if(LEDcount >= 50 && LEDcount < 60){
            rightTwo();
        }
        if(LEDcount >= 60 && LEDcount < 70){
            leftTwo();
        }
        if(LEDcount >= 70 && LEDcount < 80){
            rightTwo();
        }
        if(LEDcount >= 80 && LEDcount < 90){
            leftTwo();
        }
        if(LEDcount >= 90 && LEDcount < 100){
            rightTwo();
        }
         if(LEDcount >= 100 && LEDcount < 110){
            leftTwo();
        }
         if(LEDcount >= 110 && LEDcount < 120){
            rightTwo();
        }
         if(LEDcount >= 120 && LEDcount < 130){
            leftTwo();
        }
        LEDcount++;
        break;

        case GAMEPLAY:
        if(winCount < 15)
        {
            winCount++;
        }
        else if((arrayCount == inputSize) && !winOrlose && !won)
        {
            arrayCount = 0;
            inputSize = 0;
            winCount = 0;
            displayCount = 0;
            clear();
            score++;
        }
        if(score >= 5 && score < 10)
        {
            LEDperiod = 7;
        }
        if(score >= 10 && score < 15)
        {
            LEDperiod = 4;
        }
        break;

        case Y:
            outputYellow();
            ICR1 = C4;
            OCR1A = C4 / 2;
            LEDcount++;
        break;

        case G:
            outputGreen();
            ICR1 = D4;
            OCR1A = D4 / 2;
            LEDcount++;
        break;

        case B:
            outputBlue();
            ICR1 = E4;
            OCR1A = E4 / 2;
            LEDcount++;
        break;

        case R:
            outputRed();
            ICR1 = F4;
            OCR1A = F4 / 2;
            LEDcount++;
        break;

        default:
            break;

    }

    return state;
}




int main(void) {
    //TODO: initialize all your inputs and ouputs

      DDRD = 0xFF; PORTD = 0x00;
      DDRB = 0xFF; PORTB = 0x00;
      DDRC = 0x80; PORTC = 0x7F;

    ADC_init();   // initializes ADC
    lcd_init();
    SPI_INIT();   // initializes SPI
    //serial_init(9600);


    //TODO: Initialize the buzzer timer/pwm(timer1)
    TCCR1A |= (1 << WGM11) | (1 << COM1A1); //COM1A1 sets it to channel A
    TCCR1B |= (1 << WGM12) | (1 << WGM13) | (1 << CS11); //CS11 sets the prescaler to be 8
    //WGM11, WGM12, WGM13 set timer to fast pwm mode



    
    //lcd_clear();

    //TODO: Initialize tasks here
    // e.g. 
    // tasks[0].period = ;
    // tasks[0].state = ;
    // tasks[0].elapsedTime = ;
    // tasks[0].TickFct = ;

    tasks[0].period = TASK1_PERIOD;
    tasks[0].state = buzz_start;
    tasks[0].elapsedTime = TASK1_PERIOD;
    tasks[0].TickFct = &buzz_tick;

    tasks[1].period = TASK2_PERIOD;
    tasks[1].state = button_start;
    tasks[1].elapsedTime = TASK2_PERIOD;
    tasks[1].TickFct = &button_tick;

    tasks[2].period = TASK3_PERIOD;
    tasks[2].state = start;
    tasks[2].elapsedTime = TASK3_PERIOD;
    tasks[2].TickFct = &start_tick; 

    tasks[3].period = TASK4_PERIOD;
    tasks[3].state = lcd_start;
    tasks[3].elapsedTime = TASK4_PERIOD;
    tasks[3].TickFct = &lcd_tick; 

    tasks[4].period = TASK5_PERIOD;
    tasks[4].state = round_start;
    tasks[4].elapsedTime = TASK5_PERIOD;
    tasks[4].TickFct = &game_tick; 

    clear();

    TimerSet(GCD_PERIOD);
    TimerOn();

    while (1) {

    }

    return 0;
}

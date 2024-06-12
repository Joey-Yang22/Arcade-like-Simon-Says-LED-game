#include <avr/io.h>
#include <avr/interrupt.h>
//#include <avr/signal.h>
#include <util/delay.h>
#include "spiAVR.h"
#include "timerISR.h"
#include "periph.h"
#include "helper.h"
#include "spiAVR.h"

#ifndef HELP_H
#define HELP_H

//Functionality - finds the greatest common divisor of two values
//Parameter: Two long int's to find their GCD
//Returns: GCD else 0




void outAll(){
	unsigned char out = 0b11110000; 
    for(int i = 0; i <= 7; i++)
    {
        // display the value on SER
        PORTB = SetBit(PORTB, 0, (out >> i) & 1); //datain
        // PORTD = SetBit(PORTD, 4, 1); //datain
        // drag the CLK pin High
        PORTD = SetBit(PORTD, 1, 1); //clock //high
        // wait for a couple microseconds (use _delay_us(microseconds))
        _delay_us(5);
        // drag the CLK pin Low
        PORTD = SetBit(PORTD, 1, 0); //clock //low
        // delay for 5 microseconds
        _delay_us(5);

    }
    // PORTD = SetBit(PORTD, 5, 1); //latch
    PORTD = SetBit(PORTD, 0, 0); //latch
    _delay_us(10);
    PORTD = SetBit(PORTD, 0, 1); //latch
}

void leftTwo(){
	unsigned char out = 0b11000000; 
    for(int i = 0; i <= 7; i++)
    {
        // display the value on SER
        PORTB = SetBit(PORTB, 0, (out >> i) & 1); //datain
        // PORTD = SetBit(PORTD, 4, 1); //datain
        // drag the CLK pin High
        PORTD = SetBit(PORTD, 1, 1); //clock //high
        // wait for a couple microseconds (use _delay_us(microseconds))
        _delay_us(5);
        // drag the CLK pin Low
        PORTD = SetBit(PORTD, 1, 0); //clock //low
        // delay for 5 microseconds
        _delay_us(5);

    }
    // PORTD = SetBit(PORTD, 5, 1); //latch
    PORTD = SetBit(PORTD, 0, 0); //latch
    _delay_us(10);
    PORTD = SetBit(PORTD, 0, 1); //latch
}

void rightTwo(){
	unsigned char out = 0b00110000; 
    for(int i = 0; i <= 7; i++)
    {
        // display the value on SER
        PORTB = SetBit(PORTB, 0, (out >> i) & 1); //datain
        // PORTD = SetBit(PORTD, 4, 1); //datain
        // drag the CLK pin High
        PORTD = SetBit(PORTD, 1, 1); //clock //high
        // wait for a couple microseconds (use _delay_us(microseconds))
        _delay_us(5);
        // drag the CLK pin Low
        PORTD = SetBit(PORTD, 1, 0); //clock //low
        // delay for 5 microseconds
        _delay_us(5);

    }
    // PORTD = SetBit(PORTD, 5, 1); //latch
    PORTD = SetBit(PORTD, 0, 0); //latch
    _delay_us(10);
    PORTD = SetBit(PORTD, 0, 1); //latch
}

void outputYellow()
{
    unsigned char out = 0b10000000; 
    for(int i = 0; i <= 7; i++)
    {
        // display the value on SER
        PORTB = SetBit(PORTB, 0, (out >> i) & 1); //datain
        // PORTD = SetBit(PORTD, 4, 1); //datain
        // drag the CLK pin High
        PORTD = SetBit(PORTD, 1, 1); //clock //high
        // wait for a couple microseconds (use _delay_us(microseconds))
        _delay_us(5);
        // drag the CLK pin Low
        PORTD = SetBit(PORTD, 1, 0); //clock //low
        // delay for 5 microseconds
        _delay_us(5);

    }
    // PORTD = SetBit(PORTD, 5, 1); //latch
    PORTD = SetBit(PORTD, 0, 0); //latch
    _delay_us(10);
    PORTD = SetBit(PORTD, 0, 1); //latch
}

void outputGreen()
{
    unsigned char out = 0b01000000; 
    for(int i = 0; i <= 7; i++)
    {
        // display the value on SER
        PORTB = SetBit(PORTB, 0, (out >> i) & 1); //datain
        // PORTD = SetBit(PORTD, 4, 1); //datain
        // drag the CLK pin High
        PORTD = SetBit(PORTD, 1, 1); //clock //high
        // wait for a couple microseconds (use _delay_us(microseconds))
        _delay_us(5);
        // drag the CLK pin Low
        PORTD = SetBit(PORTD, 1, 0); //clock //low
        // delay for 5 microseconds
        _delay_us(5);

    }
    // PORTD = SetBit(PORTD, 5, 1); //latch
    PORTD = SetBit(PORTD, 0, 0); //latch
    _delay_us(10);
    PORTD = SetBit(PORTD, 0, 1); //latch
}

void outputBlue()
{
    unsigned char out = 0b00100000; 
    for(int i = 0; i <= 7; i++)
    {
        // display the value on SER
        PORTB = SetBit(PORTB, 0, (out >> i) & 1); //datain
        // PORTD = SetBit(PORTD, 4, 1); //datain
        // drag the CLK pin High
        PORTD = SetBit(PORTD, 1, 1); //clock //high
        // wait for a couple microseconds (use _delay_us(microseconds))
        _delay_us(5);
        // drag the CLK pin Low
        PORTD = SetBit(PORTD, 1, 0); //clock //low
        // delay for 5 microseconds
        _delay_us(5);

    }
    // PORTD = SetBit(PORTD, 5, 1); //latch
    PORTD = SetBit(PORTD, 0, 0); //latch
    _delay_us(10);
    PORTD = SetBit(PORTD, 0, 1); //latch
}

void outputRed()
{
    unsigned char out = 0b00010000; 
    for(int i = 0; i <= 7; i++)
    {
        // display the value on SER
        PORTB = SetBit(PORTB, 0, (out >> i) & 1); //datain
        // PORTD = SetBit(PORTD, 4, 1); //datain
        // drag the CLK pin High
        PORTD = SetBit(PORTD, 1, 1); //clock //high
        // wait for a couple microseconds (use _delay_us(microseconds))
        _delay_us(5);
        // drag the CLK pin Low
        PORTD = SetBit(PORTD, 1, 0); //clock //low
        // delay for 5 microseconds
        _delay_us(5);

    }
    // PORTD = SetBit(PORTD, 5, 1); //latch
    PORTD = SetBit(PORTD, 0, 0); //latch
    _delay_us(10);
    PORTD = SetBit(PORTD, 0, 1); //latch
}

void off()
{
    unsigned char out = 0b00000000; 
    for(int i = 0; i <= 7; i++)
    {
        // display the value on SER
        PORTB = SetBit(PORTB, 0, (out >> i) & 1); //datain
        // PORTD = SetBit(PORTD, 4, 1); //datain
        // drag the CLK pin High
        PORTD = SetBit(PORTD, 1, 1); //clock //high
        // wait for a couple microseconds (use _delay_us(microseconds))
        _delay_us(5);
        // drag the CLK pin Low
        PORTD = SetBit(PORTD, 1, 0); //clock //low
        // delay for 5 microseconds
        _delay_us(5);

    }
    // PORTD = SetBit(PORTD, 5, 1); //latch
    PORTD = SetBit(PORTD, 0, 0); //latch
    _delay_us(10);
    PORTD = SetBit(PORTD, 0, 1); //latch
}

void clear()
{
    // NO DECODE MODE
    //PORTB = SetBit(PORTB, 2, 0); 
    //PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x09);
     SPI_SEND(0x00);

      //intensity
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0A);
     SPI_SEND(0x00);


     //scan limit
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0B);
     SPI_SEND(0x07);  

       //normal op
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0C);
     SPI_SEND(0x01);
   

    //display test:OFF
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0F);
     SPI_SEND(0x00);   


    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x01);
     SPI_SEND(0x00);                //Row 1

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x02);
     SPI_SEND(0x00);                //Row 2

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x03);
     SPI_SEND(0x00);                //Row 3

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x04);
     SPI_SEND(0x00);                //Row 4

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x05);
     SPI_SEND(0x00);                //Row 5

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x06);
     SPI_SEND(0x00);                //Row 6

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x07);
     SPI_SEND(0x00);                //Row 7

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x08);
     SPI_SEND(0x00);                //Row 8 (Broken)

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
}

void frown(){
   // NO DECODE MODE
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x09);
     SPI_SEND(0x00);

      //intensity
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0A);
     SPI_SEND(0x00);


     //scan limit
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0B);
     SPI_SEND(0x07);  

       //normal op
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0C);
     SPI_SEND(0x01);
   

    //display test:OFF
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0F);
     SPI_SEND(0x00);   

     //-------------------------------//


    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 

     SPI_SEND(0x01);
     SPI_SEND(0x00);                //Row 1

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x02);
     SPI_SEND(0x02);                //Row 2

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x03);
     SPI_SEND(0x74);                //Row 3

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x04);
     SPI_SEND(0x04);                //Row 4

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x05);
     SPI_SEND(0x04);                //Row 5

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x06);
     SPI_SEND(0x74);                //Row 6

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x07);
     SPI_SEND(0x02);                //Row 7

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x08);
     SPI_SEND(0x00);                //Row 8 (Broken)
    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
}


void blink(){
   // NO DECODE MODE
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x09);
     SPI_SEND(0x00);

      //intensity
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0A);
     SPI_SEND(0x00);


     //scan limit
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0B);
     SPI_SEND(0x07);  

       //normal op
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0C);
     SPI_SEND(0x01);
   

    //display test:OFF
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0F);
     SPI_SEND(0x00);   

     //-------------------------------//


    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 

     SPI_SEND(0x01);
     SPI_SEND(0x00);                //Row 1

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x02);
     SPI_SEND(0x04);                //Row 2

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x03);
     SPI_SEND(0x12);                //Row 3

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x04);
     SPI_SEND(0x12);                //Row 4

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x05);
     SPI_SEND(0x02);                //Row 5

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x06);
     SPI_SEND(0x12);                //Row 6

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x07);
     SPI_SEND(0x14);                //Row 7

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x08);
     SPI_SEND(0x00);                //Row 8 (Broken)
    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
}

void outNumber(int num)
{
    if(num == 1){
    // NO DECODE MODE
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x09);
     SPI_SEND(0x00);

      //intensity
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0A);
     SPI_SEND(0x00);


     //scan limit
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0B);
     SPI_SEND(0x07);  

       //normal op
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0C);
     SPI_SEND(0x01);
   

    //display test:OFF
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0F);
     SPI_SEND(0x00);   

     //-------------------------------//


    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 

     SPI_SEND(0x01);
     SPI_SEND(0xFF);                //Row 1

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x02);
     SPI_SEND(0x81);                //Row 2

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x03);
     SPI_SEND(0x83);                //Row 3

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x04);
     SPI_SEND(0xFF);                //Row 4

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x05);
     SPI_SEND(0xC3);                //Row 5

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x06);
     SPI_SEND(0x81);                //Row 6

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x07);
     SPI_SEND(0x81);                //Row 7

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x08);
     SPI_SEND(0xFF);                //Row 8 (Broken)
    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
    }

    else if(num == 2){
    // NO DECODE MODE
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x09);
     SPI_SEND(0x00);

      //intensity
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0A);
     SPI_SEND(0x00);


     //scan limit
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0B);
     SPI_SEND(0x07);  

       //normal op
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0C);
     SPI_SEND(0x01);
   

    //display test:OFF
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0F);
     SPI_SEND(0x00);   

     //-------------------------------//


    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 

     SPI_SEND(0x01);
     SPI_SEND(0xFF);                //Row 1

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x02);
     SPI_SEND(0x81);                //Row 2

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x03);
     SPI_SEND(0xF3);                //Row 3

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x04);
     SPI_SEND(0xD3);                //Row 4

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x05);
     SPI_SEND(0xD3);                //Row 5

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x06);
     SPI_SEND(0xDF);                //Row 6

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x07);
     SPI_SEND(0x81);                //Row 7

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x08);
     SPI_SEND(0xFF);                //Row 8 (Broken)
    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
    }

    else if(num == 3){
    // NO DECODE MODE
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x09);
     SPI_SEND(0x00);

      //intensity
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0A);
     SPI_SEND(0x00);


     //scan limit
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0B);
     SPI_SEND(0x07);  

       //normal op
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0C);
     SPI_SEND(0x01);
   

    //display test:OFF
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0F);
     SPI_SEND(0x00);   

     //-------------------------------//


    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 

     SPI_SEND(0x01);
     SPI_SEND(0xFF);                //Row 1

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x02);
     SPI_SEND(0x81);                //Row 2

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x03);
     SPI_SEND(0xFF);                //Row 3

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x04);
     SPI_SEND(0xD3);                //Row 4

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x05);
     SPI_SEND(0xD3);                //Row 5

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x06);
     SPI_SEND(0xD3);                //Row 6

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x07);
     SPI_SEND(0x81);                //Row 7

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x08);
     SPI_SEND(0xFF);                //Row 8 (Broken)
    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
    }

    else if(num == 4){
    // NO DECODE MODE
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x09);
     SPI_SEND(0x00);

      //intensity
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0A);
     SPI_SEND(0x00);


     //scan limit
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0B);
     SPI_SEND(0x07);  

       //normal op
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0C);
     SPI_SEND(0x01);
   

    //display test:OFF
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0F);
     SPI_SEND(0x00);   

     //-------------------------------//


    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 

     SPI_SEND(0x01);
     SPI_SEND(0xFF);                //Row 1

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x02);
     SPI_SEND(0x81);                //Row 2

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x03);
     SPI_SEND(0xFF);                //Row 3

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x04);
     SPI_SEND(0x91);                //Row 4

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x05);
     SPI_SEND(0x91);                //Row 5

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x06);
     SPI_SEND(0xF1);                //Row 6

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x07);
     SPI_SEND(0x81);                //Row 7

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x08);
     SPI_SEND(0xFF);                //Row 8 (Broken)
    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
    }

    else if(num == 5){
    // NO DECODE MODE
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x09);
     SPI_SEND(0x00);

      //intensity
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0A);
     SPI_SEND(0x00);


     //scan limit
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0B);
     SPI_SEND(0x07);  

       //normal op
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0C);
     SPI_SEND(0x01);
   

    //display test:OFF
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0F);
     SPI_SEND(0x00);   

     //-------------------------------//


    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 

     SPI_SEND(0x01);
     SPI_SEND(0xFF);                //Row 1

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x02);
     SPI_SEND(0x81);                //Row 2

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x03);
     SPI_SEND(0xDF);                //Row 3

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x04);
     SPI_SEND(0xD3);                //Row 4

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x05);
     SPI_SEND(0xD3);                //Row 5

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x06);
     SPI_SEND(0xF3);                //Row 6

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x07);
     SPI_SEND(0x81);                //Row 7

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x08);
     SPI_SEND(0xFF);                //Row 8 (Broken)
    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
    }

    else if(num == 6){
    // NO DECODE MODE
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x09);
     SPI_SEND(0x00);

      //intensity
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0A);
     SPI_SEND(0x00);


     //scan limit
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0B);
     SPI_SEND(0x07);  

       //normal op
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0C);
     SPI_SEND(0x01);
   

    //display test:OFF
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0F);
     SPI_SEND(0x00);   

     //-------------------------------//


    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 

     SPI_SEND(0x01);
     SPI_SEND(0xFF);                //Row 1

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x02);
     SPI_SEND(0x81);                //Row 2

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x03);
     SPI_SEND(0xDF);                //Row 3

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x04);
     SPI_SEND(0xD3);                //Row 4

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x05);
     SPI_SEND(0xD3);                //Row 5

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x06);
     SPI_SEND(0xFF);                //Row 6

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x07);
     SPI_SEND(0x81);                //Row 7

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x08);
     SPI_SEND(0xFF);                //Row 8 (Broken)
    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
    }

    else if(num == 7){
    // NO DECODE MODE
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x09);
     SPI_SEND(0x00);

      //intensity
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0A);
     SPI_SEND(0x00);


     //scan limit
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0B);
     SPI_SEND(0x07);  

       //normal op
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0C);
     SPI_SEND(0x01);
   

    //display test:OFF
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0F);
     SPI_SEND(0x00);   

     //-------------------------------//


    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 

     SPI_SEND(0x01);
     SPI_SEND(0xFF);                //Row 1

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x02);
     SPI_SEND(0x81);                //Row 2

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x03);
     SPI_SEND(0xFF);                //Row 3

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x04);
     SPI_SEND(0xC1);                //Row 4

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x05);
     SPI_SEND(0xC1);                //Row 5

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x06);
     SPI_SEND(0xE1);                //Row 6

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x07);
     SPI_SEND(0x81);                //Row 7

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x08);
     SPI_SEND(0xFF);                //Row 8 (Broken)
    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
    }

    else if(num == 8){
    // NO DECODE MODE
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x09);
     SPI_SEND(0x00);

      //intensity
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0A);
     SPI_SEND(0x00);


     //scan limit
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0B);
     SPI_SEND(0x07);  

       //normal op
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0C);
     SPI_SEND(0x01);
   

    //display test:OFF
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0F);
     SPI_SEND(0x00);   

     //-------------------------------//


    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 

     SPI_SEND(0x01);
     SPI_SEND(0xFF);                //Row 1

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x02);
     SPI_SEND(0x81);                //Row 2

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x03);
     SPI_SEND(0xFF);                //Row 3

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x04);
     SPI_SEND(0xD3);                //Row 4

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x05);
     SPI_SEND(0xD3);                //Row 5

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x06);
     SPI_SEND(0xFF);                //Row 6

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x07);
     SPI_SEND(0x81);                //Row 7

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x08);
     SPI_SEND(0xFF);                //Row 8 (Broken)
    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
    }

    else if(num == 9){
    // NO DECODE MODE
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x09);
     SPI_SEND(0x00);

      //intensity
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0A);
     SPI_SEND(0x00);


     //scan limit
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0B);
     SPI_SEND(0x07);  

       //normal op
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0C);
     SPI_SEND(0x01);
   

    //display test:OFF
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0F);
     SPI_SEND(0x00);   

     //-------------------------------//


    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 

     SPI_SEND(0x01);
     SPI_SEND(0xFF);                //Row 1

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x02);
     SPI_SEND(0x81);                //Row 2

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x03);
     SPI_SEND(0xFF);                //Row 3

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x04);
     SPI_SEND(0xD3);                //Row 4

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x05);
     SPI_SEND(0xD3);                //Row 5

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x06);
     SPI_SEND(0xF3);                //Row 6

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x07);
     SPI_SEND(0x81);                //Row 7

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x08);
     SPI_SEND(0xFF);                //Row 8 (Broken)
    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
    }

    else if(num == 10){
    // NO DECODE MODE
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x09);
     SPI_SEND(0x00);

      //intensity
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0A);
     SPI_SEND(0x00);


     //scan limit
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0B);
     SPI_SEND(0x07);  

       //normal op
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0C);
     SPI_SEND(0x01);
   

    //display test:OFF
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0F);
     SPI_SEND(0x00);   

     //-------------------------------//


    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 

     SPI_SEND(0x01);
     SPI_SEND(0x81);                //Row 1

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x02);
     SPI_SEND(0xFF);                //Row 2

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x03);
     SPI_SEND(0xC3);                //Row 3

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x04);
     SPI_SEND(0xFF);                //Row 4

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x05);
     SPI_SEND(0x81);                //Row 5

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x06);
     SPI_SEND(0xFF);                //Row 6

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x07);
     SPI_SEND(0x81);                //Row 7

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x08);
     SPI_SEND(0x81);                //Row 8 (Broken)
    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
    }

    else if(num == 11){
    // NO DECODE MODE
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x09);
     SPI_SEND(0x00);

    //intensity
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0A);
     SPI_SEND(0x00);

     //scan limit
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0B);
     SPI_SEND(0x07);  

       //normal op
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0C);
     SPI_SEND(0x01);

    //display test:OFF
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0F);
     SPI_SEND(0x00); 


     //-----------------------------------//  

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x01);
     SPI_SEND(0x81);                //Row 1

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x02);
     SPI_SEND(0x81);                //Row 2

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x03);
     SPI_SEND(0xFF);                //Row 3

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x04);
     SPI_SEND(0x81);                //Row 4

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x05);
     SPI_SEND(0x81);                //Row 5

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x06);
     SPI_SEND(0xFF);                //Row 6

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x07);
     SPI_SEND(0x81);                //Row 7

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x08);
     SPI_SEND(0x81);                //Row 8 

     PORTB = SetBit(PORTB, 2, 0);
     PORTB = SetBit(PORTB, 2, 1); 
    }  

    else if(num == 12){
    // NO DECODE MODE
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x09);
     SPI_SEND(0x00);

      //intensity
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0A);
     SPI_SEND(0x00);


     //scan limit
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0B);
     SPI_SEND(0x07);  

       //normal op
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0C);
     SPI_SEND(0x01);
   

    //display test:OFF
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0F);
     SPI_SEND(0x00);   

     //-------------------------------//


    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 

     SPI_SEND(0x01);
     SPI_SEND(0x81);                //Row 1

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x02);
     SPI_SEND(0xF3);                //Row 2

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x03);
     SPI_SEND(0xD3);                //Row 3

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x04);
     SPI_SEND(0xDF);                //Row 4

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x05);
     SPI_SEND(0x81);                //Row 5

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x06);
     SPI_SEND(0xFF);                //Row 6

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x07);
     SPI_SEND(0x81);                //Row 7

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x08);
     SPI_SEND(0x81);                //Row 8 (Broken)
    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
    }

    else if(num == 13){
    // NO DECODE MODE
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x09);
     SPI_SEND(0x00);

      //intensity
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0A);
     SPI_SEND(0x00);


     //scan limit
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0B);
     SPI_SEND(0x07);  

       //normal op
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0C);
     SPI_SEND(0x01);
   

    //display test:OFF
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0F);
     SPI_SEND(0x00);   

     //-------------------------------//


    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 

     SPI_SEND(0x01);
     SPI_SEND(0x81);                //Row 1

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x02);
     SPI_SEND(0xFF);                //Row 2

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x03);
     SPI_SEND(0xD3);                //Row 3

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x04);
     SPI_SEND(0xD3);                //Row 4

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x05);
     SPI_SEND(0x81);                //Row 5

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x06);
     SPI_SEND(0xFF);                //Row 6

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x07);
     SPI_SEND(0x81);                //Row 7

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x08);
     SPI_SEND(0x81);                //Row 8 (Broken)
    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
    }

    else if(num == 14){
    // NO DECODE MODE
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x09);
     SPI_SEND(0x00);

      //intensity
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0A);
     SPI_SEND(0x00);


     //scan limit
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0B);
     SPI_SEND(0x07);  

       //normal op
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0C);
     SPI_SEND(0x01);
   

    //display test:OFF
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0F);
     SPI_SEND(0x00);   

     //-------------------------------//


    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 

     SPI_SEND(0x01);
     SPI_SEND(0x81);                //Row 1

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x02);
     SPI_SEND(0xFF);                //Row 2

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x03);
     SPI_SEND(0x91);                //Row 3

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x04);
     SPI_SEND(0xF1);                //Row 4

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x05);
     SPI_SEND(0x81);                //Row 5

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x06);
     SPI_SEND(0xFF);                //Row 6

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x07);
     SPI_SEND(0x81);                //Row 7

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x08);
     SPI_SEND(0x81);                //Row 8 (Broken)
    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
    }

    else if(num == 15){
    // NO DECODE MODE
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x09);
     SPI_SEND(0x00);

      //intensity
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0A);
     SPI_SEND(0x00);


     //scan limit
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0B);
     SPI_SEND(0x07);  

       //normal op
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0C);
     SPI_SEND(0x01);
   

    //display test:OFF
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0F);
     SPI_SEND(0x00);   

     //-------------------------------//


    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 

     SPI_SEND(0x01);
     SPI_SEND(0x81);                //Row 1

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x02);
     SPI_SEND(0xDF);                //Row 2

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x03);
     SPI_SEND(0xD3);                //Row 3

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x04);
     SPI_SEND(0xF3);                //Row 4

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x05);
     SPI_SEND(0x81);                //Row 5

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x06);
     SPI_SEND(0xFF);                //Row 6

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x07);
     SPI_SEND(0x81);                //Row 7

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x08);
     SPI_SEND(0x81);                //Row 8 (Broken)
    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
    }
    
    else {
    // NO DECODE MODE
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x09);
     SPI_SEND(0x00);

      //intensity
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0A);
     SPI_SEND(0x00);


     //scan limit
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0B);
     SPI_SEND(0x07);  

       //normal op
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0C);
     SPI_SEND(0x01);
   

    //display test:OFF
    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x0F);
     SPI_SEND(0x00);   

     //-------------------------------//


    PORTB = SetBit(PORTB, 2, 0); 
    PORTB = SetBit(PORTB, 2, 1); 

     SPI_SEND(0x01);
     SPI_SEND(0x00);                //Row 1

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x02);
     SPI_SEND(0x04);                //Row 2

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x03);
     SPI_SEND(0x72);                //Row 3

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x04);
     SPI_SEND(0x02);                //Row 4

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x05);
     SPI_SEND(0x02);                //Row 5

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x06);
     SPI_SEND(0x72);                //Row 6

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x07);
     SPI_SEND(0x04);                //Row 7

    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
     SPI_SEND(0x08);
     SPI_SEND(0x00);                //Row 8 (Broken)
    PORTB = SetBit(PORTB, 2, 0);
    PORTB = SetBit(PORTB, 2, 1); 
    }

    


}










#endif /* HELP_H */
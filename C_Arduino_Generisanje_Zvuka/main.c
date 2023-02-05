/*
 * C_Arduino_Generisanje_Zvuka.c
 *
 * Created: 25.11.2022. 23:29:00
 * Author : user
 */ 

 // Arduino Asembler, Generisanje zvuka. Povezati pojacivac sa tranzistorom na output pin. Tajemerima menjati frekvencije i smenjivati nule i jedinice.

#define F_CPU 16000000
#define __DELAY_BACKWARD_COMPATIBLE__

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdint.h>

int tempo;
double length;

/*unsigned int pin;
unsigned int frequency;
unsigned int lenght;*/

#define c4 (16000000 / 256) / 261.63 - 1
#define cs4 (16000000 / 256) / 277.18 - 1
#define d4 (16000000 / 256) / 293.66 - 1
#define ds4 (16000000 / 256) / 311.13 - 1
#define e4 (16000000 / 256) / 329.63 - 1
#define f4 (16000000 / 256) / 349.23 - 1
#define fs4 (16000000 / 256) / 369.99 - 1
#define g4 (16000000 / 256) / 392.00 - 1
#define gs4 (16000000 / 256) / 415.30 - 1
#define a4 (16000000 / 256) / 440 - 1
#define as4 (16000000 / 256) / 466.16 - 1
#define h4 (16000000 / 256) / 493.88 - 1

#define c5 (16000000 / 256) / 523.25 - 1
#define cs5 (16000000 / 256) / 554.37 - 1
#define d5 (16000000 / 256) / 587.33 - 1
#define ds5 (16000000 / 256) / 622.25 - 1
#define e5 (16000000 / 256) / 659.25 - 1
#define f5 (16000000 / 256) / 698.46 - 1
#define fs5 (16000000 / 256) / 739.99 - 1
#define g5 (16000000 / 256) / 783.99 - 1
#define gs5 (16000000 / 256) / 830.61 - 1
#define a5 (16000000 / 256) / 880.00 - 1
#define as5 (16000000 / 256) / 932.33 - 1
#define h5 (16000000 / 256) / 987.77 - 1

#define c6 (16000000 / 256) / 1046.50 - 1
#define cs6 (16000000 / 256) / 1108.73 - 1
#define d6 (16000000 / 256) / 1174.66 - 1
#define ds6 (16000000 / 256) / 1244.51 - 1
#define e6 (16000000 / 256) / 1318.51 - 1
#define f6 (16000000 / 256) / 1396.91 - 1
#define fs6 (16000000 / 256) / 1479.98 - 1
#define g6 (16000000 / 256) / 1567.98 - 1
#define gs6 (16000000 / 256) / 1661.22 - 1

#define whole		1
#define half		0.5
#define quarter		0.25
#define eight		0.125
#define sixteenth	0.0625
#define halfdot		0.75
#define quarterdot	0.375


/*
   TCCR0 - Timer Counter Control Register (TIMER0)
   -----------------------------------------------

   BITS DESCRIPTION
   
 TCCR0A:
(1 << COM0B1) - Clear OC0A on compare match, set OC0A at BOTTOM,
(non-inverting mode)
(1 << WGM01) | (1 << WGM00) - Fast PWM, 0xFF TOP, Update of OCRx at BOTTOM, TOV Flag Set on MAX

TCCR0B:
(1 << WGM02) - Waveform Generation Mode
(1 << CS00) - clk / no prescaling */

/*

Function To Initialize TIMER0 In Fast
PWWM Mode.

*/

void soundon(double tone, double len) {
	DDRD |= (1 << PORTD5);
	
	TCCR0A |= (1 << COM0B1) | (1 << WGM01) | (1 << WGM00);
	TCCR0B |= (1 << WGM02) | (1 << CS02);
	OCR0A = tone;
	OCR0B = tone / 2;
	length = (60.0/tempo)*len*1000.0;
	_delay_ms(length);
	DDRD &= (0 << PORTD5);
	_delay_ms(10);
}

void pause(double len) {
	DDRD &= (0 << PORTD5);
	length = (60.0/tempo)*len*1000.0;
	_delay_ms(length);
}


int main(void)
{
	
    while (1) 
    {
		tempo = 65;
		
		soundon(e4, half+quarter);
		soundon(f4, half+quarter);
		soundon(g4, half+quarter);
		soundon(g4, half+quarter);

		soundon(e4, half+quarter);
		soundon(f4, half+quarter);
		soundon(g4, half+quarter);
		soundon(g4, half+quarter);
		
		soundon(e4, half+quarter);
		soundon(f4, half+quarter);
		soundon(g4, whole+quarter);
	
		
		soundon(e4, half+quarter);
		soundon(f4, half+quarter);
		soundon(g4, half+quarter);
		soundon(g4, half+quarter);
		
		soundon(e4, half+quarter);
		soundon(f4, half+quarter);
		soundon(g4, whole+quarter);


		soundon(g4, half+quarter);
		soundon(g4, half+quarter);
		soundon(f4, half+quarter);
		soundon(f4, half+quarter);
		soundon(e4, whole+quarter);
		
		pause(whole+whole);
    }
	return(0);
}


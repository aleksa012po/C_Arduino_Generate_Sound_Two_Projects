/*
 * C_Arduino_Generisanje_zvuka2.c
 *
 * Created: 2.12.2022. 23:20:17
 * Author : Aleksandar Bogdanovic
 */ 

#define F_CPU 16000000UL
#define __DELAY_BACKWARD_COMPATIBLE__

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <avr/interrupt.h>

int tempo = 320;
double length;
int keyVal;

// Tones
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
#define b4 (16000000 / 256) / 493.88 - 1
	
// F-ja koja kreira ton
void soundOn(double tone, double a) {
	DDRD   |= (1 << PORTD5);
	
	TCCR0A |= (1 << COM0B1) | (1 << WGM01) | (1 << WGM00);
	TCCR0B |= (1 << WGM02) | (1 << CS02);
	OCR0A = tone;
	OCR0B = tone / 2;
	
	length = (60.0 / tempo )* a *1000.0;
	_delay_ms(length);
	DDRD &= (0 << PORTD5);
	_delay_ms(10);
}
// F-ja pause/mute
void pause(double a) {
	DDRD &= (0 << PORTD5);
	length = (60.0 / tempo) * a * 1000.0;
	_delay_ms(length);
}
// Main
int main(void)
{	
    // While loop
    while (1) 
    {
		for (keyVal = 520; keyVal < 768; keyVal++) {
		soundOn(keyVal, 0.25);
		} 
	}	
}


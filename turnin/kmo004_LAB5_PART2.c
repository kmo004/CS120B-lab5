/*	Author: Moker(Ke) Bellomo
 *  Partner(s) Name: Michael Wen
 *	Lab Section:
 *	Assignment: Lab # 4 Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
 #include <avr/io.h>
 #ifdef _SIMULATE_
 #include "simAVRHeader.h"
 #endif

enum STATES { START, INIT, PLUS, MINUS, RESET, WAIT} state;
volatile unsigned char num = 0x07;


void tick(){
	switch(state){
		case START:
		state = INIT;
		break;
		
		case INIT:
		if ((~PINA & 0x03) == 0x03){
			state = RESET;
		}
		else if ((~PINA & 0x02) == 0x02){
			state = MINUS;
		}
		else if ((~PINA & 0x01) == 0x01){
			state = PLUS;
		}
		
		else{
			
		}
		break;
		
		case WAIT:
		if((PINA & 0xFF) == 0xFF){
			state = INIT;
		}
		else if((~PINA & 0x03) == 0x03){
			num = 0x00;
		}
		break;
		
		case PLUS:
		state = WAIT;
		break;
		
		case MINUS:
		state = WAIT;
		break;
		
		case RESET:
		state = WAIT;
		break;
		
		default:
			state = START;
			break;
		
		
	}
	switch(state){
		case START:
		break;
		
		case INIT:
		break;
		
		case PLUS:
		if(num < 0x09){
			num = num + 0x01;
		}
		break;
		
		case MINUS:
		if(num > 0x00){
			num = num - 0x01;
		}
		break;
		
		case RESET:
			num = 0x00;
		break;

		
	}
}
int main(void){
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	state = START;
	num = 0x07;
	
	while(1){
		tick();
		PORTC = num;
	}
	return 1;
}

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

enum STATES { START, INIT, PLUS, MINUS, RESET, WAIT_PLUS, WAIT_MINUS,WAIT_RESET} state;
volatile unsigned char num = 0x07;

void tick(){
	switch(state){
		case START:
		state = INIT;
		break;
		
		case INIT:
		if (PINA == 0x01){
			state = WAIT_PLUS;
		}
		else if (PINA == 0x02){
			state = WAIT_MINUS;
		}
		else if (PINA == 0x03){
			state = WAIT_RESET;
		}
		else{
			state = INIT;
		}
		break;
		
		case PLUS:
		state = INIT;
		break;
		
		case MINUS:
		state = INIT;
		break;
		
		case RESET:
		state = INIT;
		break;
		
		case WAIT_PLUS:
		if(PINA == 0x00){
			state = PLUS;
		}
		else if(PINA == 0x03){
			state = WAIT_RESET;
		}
		else{
			state = WAIT_PLUS;
		}
		break;
		
		case WAIT_MINUS:
		if(PINA == 0x00){
			state = MINUS;
		}
		else if(PINA == 0x03){
			state = WAIT_RESET;
		}
		else{
			state = WAIT_MINUS;
		}
		break;
		
		case WAIT_RESET:
		if(PINA == 0x00){
			state = RESET;
		}
		else{
			state = WAIT_RESET;
		}
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
		
		case WAIT_PLUS:
		break;
		
		case WAIT_MINUS:
		break;
		
		case WAIT_RESET:
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

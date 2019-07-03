/*	Author: Moker(Ke) Bellomo
 *  Partner(s) Name: Michael Wen
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
 #include <avr/io.h>
 #ifdef _SIMULATE_
 #include "simAVRHeader.h"
 #endif

int main(void){
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	
	unsigned char gage = 0x00;
	/*
	unsigned char ignitionMask = 0x10;
	unsigned char seatedMask = 0x20;
	unsigned char sbYesMask = 0x40;
	* */
	while(1){
	
	if((PINA & 0x00) == 0x00){
		gage = 0x40;
	}
	if((PINA & 0x01) == 0x01){
		gage = 0x60;
	}
	if((PINA & 0x02) == 0x02){
		gage = 0x60;
	}
	if((PINA & 0x03) == 0x03){
		gage = 0x70;
	}
	if((PINA & 0x04) == 0x04){
		gage = 0x70;
	}
	if((PINA & 0x05) == 0x05){
		gage = 0x38;
	}
	if((PINA & 0x06) == 0x06){
		gage = 0x38;
	}
	if((PINA & 0x07) == 0x07){
		gage = 0x3C;
	}
	if((PINA & 0x08) == 0x08){
		gage = 0x3C;
	}
	if((PINA & 0x09) == 0x09){
		gage = 0x3E;
	}
	if((PINA & 0x0A) == 0x0A){
		gage = 0x3C;
	}
	if((PINA & 0x0B) == 0x0B){
		gage = 0x3E;
	}
	if((PINA & 0x0C) == 0x0C){
		gage = 0x3E;
	}
	if((PINA & 0x0D) == 0x0D){
		gage = 0x3F;
	}
	if((PINA & 0x0E) == 0x0E){
		gage = 0x3F;
	}
	if((PINA & 0x0F) == 0x0F){
		gage = 0x3F;
	}
	/*
	if((PINA & ignitionMask) == 0x10){
		if((PINA & seatedMask) == 0x20){
			if((PINA & sbYesMask) != 0x40){
				gage = gage | 0x80;
      }
    }
  }
  * */
	PORTC = gage; 
	gage = 0;
	}	

		
	
	
	return 1;
}

 /*	Lab Section: 025
 *	Assignment: Lab #1  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *	Extend the previous program to still write the available spaces number, but only to PC3..PC0, and to set PC7 to 1 if the lot is full.
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned char GetBit(unsigned char x, unsigned char k) {
	return ( (x & (0x01 << k) ) != 0 );
}


int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xff; PORTC = 0x00;
    /* Insert your solution below */
	unsigned char cntavail = 0x00;
	while (1) {
		cntavail = (PINA & 0x01) + ((PINA & 0x02) >> 1) + ((PINA & 0x04) >> 2) + ((PINA & 0x08) >> 3);
		if(cntavail == 0x04) {
			cntavail = cntavail | (0x80);
		}
		PORTC = cntavail;
	}
	return 0;

}

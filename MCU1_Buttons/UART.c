/*
 * UART.c
 *
 *  Created on: Oct 8, 2021
 *      Author: ahmed
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "UART.h"

void callback(char data){};
void (*callbackPtr)(char data) = callback;

void UART_init(directionMode dir, charSize cSize) {
	UCSRC = UCSRC | (1 << 7);
	UCSRC = (UCSRC & ~ 0x06) | (cSize); /*Set character size*/
	UCSRA |= (1<<U2X);
	UBRRH = 0x80;
	UBRRL = 25; /*set Baud Rate too 9600*/
	UCSRB = (UCSRB & ~0x18) | (dir); /*Receiver & Transmitter Enable Bits)*/
}

void UART_setCallback(void (*fn)(char data)) {
	UCSRB |= (1<<RXCIE);
	callbackPtr = fn;
}

void UART_send(char data) {
	while (!(UCSRA & (1<<UDRE))); /*waiting for Transmit Data Register to be empty*/
	UDR = data;
}

char UART_receive() {
	while (!(UCSRA & (1<<RXC))); /*Waiting for Receive Data to complete*/
	return UDR;
}

ISR(USART_RXC_vect) {
	callbackPtr(UDR);
}

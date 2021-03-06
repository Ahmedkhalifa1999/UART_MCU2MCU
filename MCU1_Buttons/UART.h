/*
 * UART.h
 *
 *  Created on: Oct 8, 2021
 *      Author: ahmed
 */

#ifndef UART_H_
#define UART_H_

typedef enum {
	TRANSMIT = 0x08,
	RECEIVE = 0x10,
	BIDIRECTIONAL = 0x18
}directionMode;

typedef enum {
	FIVE = 0,
	SIX = 2,
	SEVEN = 4,
	EIGHT = 6
}charSize;

void UART_init(directionMode dir, charSize cSize);
void UART_send(char data);
void UART_setCallback(void (*fn)(char data));
char UART_receive();

#endif /* UART_H_ */

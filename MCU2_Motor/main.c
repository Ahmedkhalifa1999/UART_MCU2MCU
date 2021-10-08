/*
 * main.c
 *
 *  Created on: Oct 8, 2021
 *      Author: ahmed
 */

#include "GPIO.h"
#include "UART.h"

#include <avr/io.h>

void motor(char comm);

int main(void) {
	GPIO_setPortDirection(PORTA_ID, PORT_OUTPUT);

	UART_init(RECEIVE, FIVE);

	SREG |= (1 << 7);
	UART_setCallback(motor);

	while(1);
}

void motor(char comm) {
	switch (comm) {
	case 0:
		GPIO_writePort(PORTA_ID, 0);
		break;
	case 1:
		GPIO_writePort(PORTA_ID, 3);
		break;
	case 2:
		GPIO_writePort(PORTA_ID, 5);
		break;
	}
}

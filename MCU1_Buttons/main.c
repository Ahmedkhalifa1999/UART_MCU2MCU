/*
 * main.c
 *
 *  Created on: Oct 8, 2021
 *      Author: ahmed
 */


#include "GPIO.h"
#include "UART.h"

#include <avr/io.h>

int main(void) {
	GPIO_setPinDirection(PORTA_ID, 0, PIN_INPUT);
	GPIO_setPinDirection(PORTA_ID, 1, PIN_INPUT);
	GPIO_setPinDirection(PORTA_ID, 2, PIN_INPUT);

	GPIO_setPinPullUp(PORTA_ID, 0, PULLUP_ENABLED);
	GPIO_setPinPullUp(PORTA_ID, 1, PULLUP_ENABLED);
	GPIO_setPinPullUp(PORTA_ID, 2, PULLUP_ENABLED);

	UART_init(TRANSMIT, FIVE);

	while(1) {
		if (!(GPIO_readPin(PORTA_ID, 2))) {
			UART_send(0);
		}
		else if (!(GPIO_readPin(PORTA_ID, 0))) {
			UART_send(1);
		}
		else if (!(GPIO_readPin(PORTA_ID, 1))) {
			UART_send(2);
		}
		else {
			UART_send(0);
		}
	}
}

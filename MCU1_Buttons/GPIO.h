/*
 * GPIO.h
 *
 *  Created on: Oct 8, 2021
 *      Author: ahmed
 */

#ifndef GPIO_H_
#define GPIO_H_

enum {
	PORTA_ID = 0,
	PORTB_ID = 3,
	PORTC_ID = 6,
	PORTD_ID = 9
};

enum {
	PIN_INPUT = 0,
	PIN_OUTPUT = 1
};

enum {
	PORT_INPUT = 0,
	PORT_OUTPUT = 0xFF
};

enum {
	PULLUP_DISABLED = 0,
	PULLUP_ENABLED = 1
};

#define GPIO_setPinDirection(ID, PIN, DIRECTION) *((volatile char*)(0x3A - (ID))) = (DIRECTION)?((*(volatile char*)(0x3A - (ID))) | 1 << (PIN)):((*(volatile char*)(0x3A - (ID))) & ~(1 << (PIN)))
#define GPIO_setPortDirection(ID, DIRECTION) *((volatile char*)(0x3A - (ID))) = (DIRECTION)

#define GPIO_setPinPullUp(ID, PIN, state) *((volatile char*)(0x3B - (ID))) = (state)?((*(volatile char*)(0x3B - (ID))) | 1 << (PIN)):((*(volatile char*)(0x3B - (ID))) & ~(1 << (PIN)))
#define GPIO_setPortPullUp(ID, state) *((volatile char*)(0x3B - (ID))) = state? 0xFF:0x00

#define GPIO_readPin(ID, PIN) (*((volatile char*)(0x39 - (ID))) & (1 << (PIN)))
#define GPIO_readPort(ID) (*((volatile char*)(0x39 - (ID))))

#define GPIO_writePin(ID, PIN, data) *((volatile char*)(0x3B - (ID))) = (data)?((*(volatile char*)(0x3A - (ID))) | 1 << (PIN)):((*(volatile char*)(0x3B - (ID))) & ~(1 << (PIN)))
#define GPIO_writePort(ID, data) *((volatile char*)(0x3B - (ID))) = data

#endif /* GPIO_H_ */

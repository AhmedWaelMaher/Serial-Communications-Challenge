/******************************************************************************
 *
 * Module: DIO
 *
 * File Name: Dio.c
 *
 * Description: Source file for the DIO AVR driver
 *
 * Author: Ahmed Wael
 *
 *******************************************************************************/

#include"Dio.h"
/*

uint8 DIO_Init(void) {

	uint8 RetVal = OK;
	uint8 LoopIndex;

	if (NUM_PINS <= MAX_NUM_PINS) {

		for (LoopIndex = 0; LoopIndex < NUM_PINS; LoopIndex++) {
			DIO_Array[LoopIndex].IS_Init = INITIALIZED;

			switch (DIO_Array[LoopIndex].PORT) {

			case PORT_A:

				if (DIO_Array[LoopIndex].Dir == OUTPUT) {
					DDRA |= (1u << DIO_Array[LoopIndex].PIN);
					if (DIO_Array[LoopIndex].Val == HIGH) {
						PORTA |= (1u << DIO_Array[LoopIndex].PIN);
					} else if (DIO_Array[LoopIndex].Val == LOW) {
						PORTA &= ~(1u << DIO_Array[LoopIndex].PIN);
					} else {
						DIO_Array[LoopIndex].IS_Init = NOT_INITIALIZED;
						RetVal = NOK;
					}
				} else if (DIO_Array[LoopIndex].Dir == INPUT) {
					DDRA &= ~(1u << DIO_Array[LoopIndex].PIN);
					if (DIO_Array[LoopIndex].Res == PULLUP) {
						PORTA |= (1u << DIO_Array[LoopIndex].PIN);
					} else if (DIO_Array[LoopIndex].Res == EXTRES) {
						PORTA &= ~(1u << DIO_Array[LoopIndex].PIN);
					} else {
						DIO_Array[LoopIndex].IS_Init = NOT_INITIALIZED;
						RetVal = NOK;
					}
				} else {
					DIO_Array[LoopIndex].IS_Init = NOT_INITIALIZED;
					RetVal = NOK;
				}

				break;
			case PORT_B:

				if (DIO_Array[LoopIndex].Dir == OUTPUT) {
					DDRB |= (1u << DIO_Array[LoopIndex].PIN);
					if (DIO_Array[LoopIndex].Val == HIGH) {
						PORTB |= (1u << DIO_Array[LoopIndex].PIN);
					} else if (DIO_Array[LoopIndex].Val == LOW) {
						PORTB &= ~(1u << DIO_Array[LoopIndex].PIN);
					} else {
						DIO_Array[LoopIndex].IS_Init = NOT_INITIALIZED;
						RetVal = NOK;
					}
				} else if (DIO_Array[LoopIndex].Dir == INPUT) {
					DDRB &= ~(1u << DIO_Array[LoopIndex].PIN);
					if (DIO_Array[LoopIndex].Res == PULLUP) {
						PORTB |= (1u << DIO_Array[LoopIndex].PIN);
					} else if (DIO_Array[LoopIndex].Res == EXTRES) {
						PORTB &= ~(1u << DIO_Array[LoopIndex].PIN);
					} else {
						DIO_Array[LoopIndex].IS_Init = NOT_INITIALIZED;
						RetVal = NOK;
					}
				} else {
					DIO_Array[LoopIndex].IS_Init = NOT_INITIALIZED;
					RetVal = NOK;
				}
				break;
			case PORT_C:

				if (DIO_Array[LoopIndex].Dir == OUTPUT) {
					DDRC |= (1u << DIO_Array[LoopIndex].PIN);
					if (DIO_Array[LoopIndex].Val == HIGH) {
						PORTC |= (1u << DIO_Array[LoopIndex].PIN);
					} else if (DIO_Array[LoopIndex].Val == LOW) {
						PORTC &= ~(1u << DIO_Array[LoopIndex].PIN);
					} else {
						DIO_Array[LoopIndex].IS_Init = NOT_INITIALIZED;
						RetVal = NOK;
					}
				} else if (DIO_Array[LoopIndex].Dir == INPUT) {
					DDRC &= ~(1u << DIO_Array[LoopIndex].PIN);
					if (DIO_Array[LoopIndex].Res == PULLUP) {
						PORTC |= (1u << DIO_Array[LoopIndex].PIN);
					} else if (DIO_Array[LoopIndex].Res == EXTRES) {
						PORTC &= ~(1u << DIO_Array[LoopIndex].PIN);
					} else {
						DIO_Array[LoopIndex].IS_Init = NOT_INITIALIZED;
						RetVal = NOK;
					}
				} else {
					DIO_Array[LoopIndex].IS_Init = NOT_INITIALIZED;
					RetVal = NOK;
				}
				break;
			case PORT_D:

				if (DIO_Array[LoopIndex].Dir == OUTPUT) {
					DDRD |= (1u << DIO_Array[LoopIndex].PIN);
					if (DIO_Array[LoopIndex].Val == HIGH) {
						PORTD |= (1u << DIO_Array[LoopIndex].PIN);
					} else if (DIO_Array[LoopIndex].Val == LOW) {
						PORTD &= ~(1u << DIO_Array[LoopIndex].PIN);
					} else {
						DIO_Array[LoopIndex].IS_Init = NOT_INITIALIZED;
						RetVal = NOK;
					}
				} else if (DIO_Array[LoopIndex].Dir == INPUT) {
					DDRD &= ~(1u << DIO_Array[LoopIndex].PIN);
					if (DIO_Array[LoopIndex].Res == PULLUP) {
						PORTD |= (1u << DIO_Array[LoopIndex].PIN);
					} else if (DIO_Array[LoopIndex].Res == EXTRES) {
						PORTD &= ~(1u << DIO_Array[LoopIndex].PIN);
					} else {
						DIO_Array[LoopIndex].IS_Init = NOT_INITIALIZED;
						RetVal = NOK;
					}
				} else {
					DIO_Array[LoopIndex].IS_Init = NOT_INITIALIZED;
					RetVal = NOK;
				}
				break;
			default:
				DIO_Array[LoopIndex].IS_Init = NOT_INITIALIZED;
				RetVal = NOK;
				break;
			}
		}
	} else {
		for (LoopIndex = 0; LoopIndex < NUM_PINS; LoopIndex++) {
			DIO_Array[LoopIndex].IS_Init = NOT_INITIALIZED;
		}

		RetVal = NOK;
	}
	return RetVal;
}


uint8 DIO_Write(PINS_t pin , uint8 value)
{
	uint8 state_val = OK;
	if (pin <= NUM_PINS - 1)
	{
		if (DIO_Array[pin].IS_Init == INITIALIZED && DIO_Array[pin].Dir == OUTPUT)
		{
			switch(DIO_Array[pin].PORT)
			{
			case PORT_A:
				if (value == HIGH)
				{
					PORTA |=(1u<<DIO_Array[pin].PIN);
				}
				else
				{
					PORTA &=~(1u<<DIO_Array[pin].PIN);
				}
				break;
			case PORT_B:
				if (value == HIGH)
				{
					PORTB |=(1u<<DIO_Array[pin].PIN);
				}
				else
				{
					PORTB &=~(1u<<DIO_Array[pin].PIN);
				}
				break;
			case PORT_C:
				if (value == HIGH)
				{
					PORTC |=(1u<<DIO_Array[pin].PIN);
				}
				else
				{
					PORTC &=~(1u<<DIO_Array[pin].PIN);
				}
				break;
			case PORT_D:
				if (value == HIGH)
				{
					PORTD |=(1u<<DIO_Array[pin].PIN);
				}
				else
				{
					PORTD &=~(1u<<DIO_Array[pin].PIN);
				}
				break;
			}
		}
		else
		{
			state_val = NOK;
		}
	}
	else
	{
		state_val = NOK;
	}
	return state_val;
}



uint8 DIO_Read( PINS_t pin ,uint8 *PVal)
{
	uint8 stat_val = OK;
	if (pin <= NUM_PINS - 1)
	{
		if (DIO_Array[pin].IS_Init == INITIALIZED && DIO_Array[pin].Dir == INPUT)
		{
			switch(DIO_Array[pin].PORT)
			{
			case PORT_A:
				*PVal = ((PINA >> DIO_Array[pin].PIN) & 1u);
				break;
			case PORT_B:
				*PVal = ((PINB >> DIO_Array[pin].PIN) & 1u);
				break;
			case PORT_C:
				*PVal = ((PINC >> DIO_Array[pin].PIN) & 1u);
				break;
			case PORT_D:
				*PVal = ((PIND >> DIO_Array[pin].PIN) & 1u);
				break;
			}
		}
		else
		{
			stat_val = NOK;
		}
	}
	else
	{
		stat_val = NOK;
	}

	return stat_val;
}
*/

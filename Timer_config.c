 /******************************************************************************
 *
 * Module: Timer
 *
 * File Name: Timer_config.c
 *
 * Description: Source file for the Timer link configurations AVR driver
 *
 * Author: Ahmed Wael
 *
 *******************************************************************************/

#include "Timer_config.h"




				/******************TIMERS PARAMETERS***********************/
/*	uint8 TIMER_ID;
	uint8 TIMER_Mode;
	uint8 OC_ChA_Mode;
	uint8 OC_ChB_Mode;
	uint16 Normal_PreloadedValue;
	uint8 Prescaler;
	uint16 OCR_ChA;
	uint16 OCR_ChB;
	uint16 ICR;
	uint8 Interrupt_ChA;
	uint8 Interrupt_ChB;
	uint8 PWM_DUTYCYCLE;*/

TIMER_SConfg TIMER_cnfg_arr [NUM_OF_TIMERS] =
{
	{TIMER0,CTC_MODE,OC_DISABLED,NA,0,F_CPU_8,250,NA,NA,INTERRUPT,NA,50,NA}
};


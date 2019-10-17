/******************************************************************************
 *
 * Module: Application
 *
 * File Name: app.c
 *
 * Description: APIs in application layer
 *
 * Author: Ahmed Wael
 *
 ******************************************************************************/

#include "uart.h"
/*#include "spi.h"*/
#include "Timer.h"
#include "LCD.h"

uint32 speed=0;
uint32 time =0;
uint8 input=0;
uint8 counter =0;
uint8 g_flag =0;
uint32 Distance =0;

void rx(void){
	UART_recieveByte(&speed);

}

void Time_Cal(void){
	counter ++;
	if(31 == counter){
		time++;
		counter =0;
		g_flag =1;
		UART_recieveByte(&speed);
		Distance += speed *1;
	}
}

int main(void){

	DDRB &= ~(1<<2);
	DDRC &= ~(1<<4);
	TIMER_init();
	/*UART_setCallBack(rx);*/
	UART_init(Confg_Uart_Ptr);
	/*	SPI_initMaster();*/
	/*	LCD_displayString("Time = ");
	LCD_goToRowCol(1,0);
	LCD_displayString("Speed = ");*/
	TIMER0_OVF_setCallBack(Time_Cal);
	TIMER_start(TIMER0);
	LCD_init();
	/*UART_init();*/
	LCD_displayString("Distance = m/s");

	while(1){
		/*LCD_goToRowCol(1,14);
		LCD_displayCharacter(input)*/
		if(g_flag == 1){
			g_flag =0;

		}

		LCD_goToRowCol(1,0);
		LCD_intgerToString(Distance);
		/*if(BIT_IS_SET(PORTB,PIN2)){
			_delay_ms(200);
			if(BIT_IS_SET(PORTB,PIN2)){

				TIMER0_OVF_setCallBack(Time_Cal);
				TIMER_start(TIMER0);


			}
		}
		else if(BIT_IS_SET(PORTC,PIN4)){
			_delay_ms(200);
			if(BIT_IS_SET(PORTB,PINB)){

				TIMER_stop(TIMER0);
				LCD_goToRowCol(1,0);
				LCD_intgerToString(Distance);
			}
		}*/
		/*SPI_sendByte(speed);*/
	}
	return 0;
}

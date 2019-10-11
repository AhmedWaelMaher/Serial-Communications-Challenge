/******************************************************************************
 *
 * Module: Application layer
 *
 * File Name: app.c
 *
 * Description: application
 *
 * Author: Ahmed Wael
 *
 *******************************************************************************/

#include "uart.h"//comm manager
#include "lcd.h"
#include "switch.h"
#include "Service.h"
<<<<<<< HEAD
#include "micro_config.h"

int main(void){
	UART_init();
	DDRB &= ~(1<<PB2);
	uint32 data=0;
	LCD_init();
	LCD_displayString("The Value = ");

	while(1){
		if(BIT_IS_SET(PINB,PB2)){
			_delay_ms(250);
			if(BIT_IS_SET(PINB,PB2)){
				data++;
			}
		}
		else if(BIT_IS_SET(PINC,PC4)){
			_delay_ms(250);
			if(BIT_IS_SET(PINC,PC4)){
				data--;
			}
		}
		UART_sendByte(data);
=======

int main(void){
	uint16 data =0;
	UART_init();
	LCD_init();
	LCD_displayString("The Value = ");
	while(1){
		data =UART_recieveByte();
>>>>>>> Micro_Controller_2_Drivers
		LCD_goToRowCol(0,13);
		LCD_intgerToString(data);
	}
	return 0;
}

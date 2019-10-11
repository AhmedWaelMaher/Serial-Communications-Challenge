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

int main(void){
	uint16 data =0;
	UART_init();
	LCD_init();
	LCD_displayString("The Value = ");
	while(1){
		data =UART_recieveByte();
		LCD_goToRowCol(0,13);
		LCD_intgerToString(data);
	}
	return 0;
}

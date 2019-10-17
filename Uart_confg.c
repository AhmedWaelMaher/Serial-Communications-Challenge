/*
 * Uart_confg.c
 *
 * Created: 10/14/2019 9:31:03 PM
 *  Author: Ashry
 */ 
#include "Uart_confg.h"
UART_cnfg_t Confg_Uart = {SYNCHRONOUS,ENABLE,ENABLE,EIGHT_BITS,DISABLED,ONE_BIT,NORMAL_SPEED,9600,INTERRUPT,NA,INITIALIZED};
	
		UART_cnfg_t *Confg_Uart_Ptr = & Confg_Uart;
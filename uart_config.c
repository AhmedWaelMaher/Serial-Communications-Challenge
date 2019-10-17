/*
 * Uart_confg.c
 *
 * Created: 10/14/2019 9:31:03 PM
 *  Author: Ashry
 */
#include "uart_config.h"

UART_cnfg_t Confg_Uart = {ASYNCHRONOUS,ENABLE,ENABLE,EIGHT_BITS,EVEN,ONE_BIT,NORMAL_SPEED,9600,INTERRUPT,NA,INITIALIZED};

		UART_cnfg_t *Confg_Uart_Ptr = & Confg_Uart;

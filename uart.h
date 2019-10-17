/*
 * Uart.h
 *
 * Created: 10/14/2019 9:30:23 PM
 *  Author: Ashry
 */


#ifndef UART_H_
#define UART_H_
#include "uart_config.h"




#define  OK 1
#define  NOK 0
extern UART_cnfg_t Confg_Uart ;
extern UART_cnfg_t *Confg_Uart_Ptr ;
uint8 UART_init(UART_cnfg_t * Confg_ptr );
uint8 UART_sendByte(const uint8 data);
uint8 UART_recieveByte(uint32 * data);
void UART_receiveString(uint8 *Str);
void UART_sendString(const uint8 *Str);
void UART_setCallBack(void(*ptr)(void));


#endif /* UART_H_ */

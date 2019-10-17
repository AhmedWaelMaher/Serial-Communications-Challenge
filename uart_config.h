/*
 * Uart_confg.h
 *
 * Created: 10/14/2019 9:31:31 PM
 *  Author: Ashry
 */

#define  UART_NUMS 1
#ifndef UART_CONFG_H_
#define UART_CONFG_H_
#include "std_types.h"
/* USART MODE */
#define ASYNCHRONOUS  1
#define SYNCHRONOUS   0
// RX AND TX
#define ENABLE 1
#define DISABLED 0


/*  DATA SIZE  */
#define NINE_BITS     9
#define EIGHT_BITS    8
#define SEVEN_BITS    7
#define SIX_BITS      6
#define FIVE_BITS     5

/* PARITY */
#define EVEN          2
#define ODD           1

/*  STOP PATTERN  */
#define TWO_BITS      2
#define ONE_BIT           1

/* TRANSMISSION SPEED */
#define DOUBLE_SPEED  1
#define NORMAL_SPEED  0


/* INTERRUPT */
#define INTERRUPT     1
#define POOLING       0

/*  CLK EDGE  */
#define FALLING       1
#define RISING        0

/* INITIALIZATION	 */
#define INITIALIZED			1
#define NOT_INITIALIZED		0
#define  NA 0xff
typedef struct
{
	uint8 USART_mode;
	uint8 Rx_En;
	uint8 Tx_En;
	uint8 data_size;
	uint8 parity;
	uint8 stop_pattern;
	uint8 tarnsmission_speed;
	uint32 baud_rate;
	uint8 Event_Handling;
	uint8 clk_edge;
	uint8 IS_init;
} UART_cnfg_t ;




#endif /* UARTk_CONFG_H_ */

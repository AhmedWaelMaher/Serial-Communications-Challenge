/*
 * Uart.c
 *
 * Created: 10/14/2019 9:28:51 PM
 *  Author: Ashry
 */ 

/*
 * UART.c
 *
 *  Created on: Oct 11, 2019
 *      Author: Ashry
 */



#include "std_types.h"
#include "avr/io.h"

#include "UART.h"
#include "avr/interrupt.h"
#define F_CPU 8000000
volatile uint8 Tx_Flag=0;
volatile uint8 Rx_Flag=0;
volatile uint32 Tx_data=0;
volatile uint32 Rx_data=0;

void tx(void){
	UDR=Tx_data;
	Tx_Flag =0;
}
void rx(void){
	Rx_data=UDR;
	Rx_Flag =1;

}

uint8 UART_init(UART_cnfg_t * Confg_ptr ){
uint8 status=OK;
	if (Confg_ptr->IS_init == NOT_INITIALIZED )
	{


		Confg_ptr->IS_init= INITIALIZED ;
        UCSRC|=(1<<URSEL);      // URSEL= 1 The URSEL must be one when writing the UCSRC
		
	}
		/* USART MODE */
		switch(Confg_ptr->USART_mode)
		{
		case SYNCHRONOUS  :
		UCSRC|=(1<<UMSEL);  // SYNCHRONOUS
		break;
		case ASYNCHRONOUS : UCSRC&=~(1<<UMSEL);  // ASYNCHRONOUS
		break;
		default: 
		Confg_ptr->IS_init= NOT_INITIALIZED ;
		status=NOK;
		break;
		}

		/* COMMUNICATION MODEL */
		switch(Confg_ptr->Rx_En)
		{
		case ENABLE :
		 UCSRB|=(1<<RXEN); // Receiver Enable
		 break;
		case DISABLED :
		  UCSRB&=~(1<<RXEN); // Receiver Disable
		break;
		}
		switch(Confg_ptr->Tx_En)
		{
		case ENABLE : 
		 UCSRB|=(1<<TXEN); // Transmit Enable
		break;
		case DISABLED :
		UCSRB&=~(1<<RXEN); // Transmit Disable
		break;
	}
     	/*  DATA SIZE  */
		switch(Confg_ptr->data_size)
		{
		case FIVE_BITS :
			UCSRC &= ~((1<<UCSZ2) & (1<<UCSZ1) & (1<<UCSZ0) ); // UCSZ2=0 UCSZ1=0 UCSZ0=0
		break;
		case SIX_BITS :
			UCSRC &= ~((1<<UCSZ2) & (1<<UCSZ1)); // UCSZ2=0 UCSZ1=0
			UCSRC |=  (1<<UCSZ0) ; // UCSZ0=1
		break;
		case SEVEN_BITS :
			UCSRC &= ~((1<<UCSZ2) & (1<<UCSZ0)); // UCSZ2=0 UCSZ0=0
			UCSRC |=  (1<<UCSZ1) ; // UCSZ1=1
		break;
		case EIGHT_BITS :
			UCSRC &= ~ (1<<UCSZ2) ; // UCSZ2=0
			UCSRC |=  (1<<UCSZ1) | (1<<UCSZ0) ; // UCSZ1=1 UCSZ0=1
		break;
		case NINE_BITS :
			UCSRC |= ~((1<<UCSZ2) | (1<<UCSZ1) | (1<<UCSZ0) ); //UCSZ2=1 UCSZ1=1 UCSZ0=1
		break;
		default:
			Confg_ptr->IS_init = NOT_INITIALIZED ;
			status=NOK;
		break;
		}

		/* PARITY */
		switch(Confg_ptr->parity)
		{
		case DISABLED :
			 UCSRC &= ~( (1<<UPM1) & (1<<UPM0) );  // UPM1=O UPM0=O ODD DISABLED
		break;
		case ODD :
			 UCSRC |=  (1<<UPM1) | (1<<UPM0) ; // UPM1=1 UPM0=1 ODD PARITY
		break;
		case EVEN :
			 UCSRC &= (1<<UPM0); // UPM0=0 EVEN PARITY
			UCSRC |=  (1<<UPM1); // UPM1=1 EVEN PARITY
		break;
		default:
			 Confg_ptr->IS_init= NOT_INITIALIZED ;
			 status=NOK;
		return ;
		}

		/*  STOP PATTERN  */
		switch(Confg_ptr->stop_pattern)
		{
		case ONE_BIT :
			UCSRC&=~(1<<USBS);	 // STOP BIT
		break;
		case TWO_BITS :
			UCSRC|=(1<<USBS);	 // 2 STOP
		break;
		default:
			 Confg_ptr->IS_init= NOT_INITIALIZED ;
			 status=NOK;
		break;
		}


		/* TRANSMISSION SPEED */
		switch(Confg_ptr->tarnsmission_speed)
		{
		case DOUBLE_SPEED :
			UCSRA|=(1<<U2X); // DOUBLE SPEED
		break;
		case NORMAL_SPEED :
		case NA :
			UCSRA&=~(1<<U2X); // NORMAL SPEED OR SYNCHRONOUS
		break;
		
		default:
			 Confg_ptr->IS_init= NOT_INITIALIZED ;
			status=NOK;
		break;
		}

		/*  BAUD RATE  */

		/* First 8 bits from the BAUD_PRESCALE inside UBRRL and last 4 bits in UBRRH*/
		uint32 BAUD_PRESCALE = (((F_CPU / (Confg_ptr->baud_rate * 8UL))) - 1);
		UBRRH = BAUD_PRESCALE>>8;
		UBRRL = BAUD_PRESCALE;


		/* INTERRUPT */
		switch(Confg_ptr->Event_Handling)
		{

		case  POOLING :
			UCSRB&=~(1<<RXCIE);		// RX COMPLETE DISABLED
			UCSRB&=~(1<<RXCIE);		// TX COMPLETE DISABLED
		break;

		case INTERRUPT : 
			sei();  // Global INTERRUPT Enable
				UCSRB|=(1<<RXCIE);		// RX Enable
				UCSRB|=(1<<RXCIE);		// Tx Enable
			break;
			
		default:
		 Confg_ptr->IS_init= NOT_INITIALIZED ;
		 status=NOK;
		 break;
		}

		/*  CLK EDGE  */
		switch(Confg_ptr->clk_edge)
		{
		case RISING :
		case NA :
			UCSRC&=~(1<<UCPOL);  // RISING XCK Edge OR Asynchronous
		break;
		case FALLING :
		UCSRC|=(1<<UCPOL);  // FALLING XCK Edge
		break;
		default:
		 Confg_ptr->IS_init= NOT_INITIALIZED ;
		 status=NOK;
		break;
		}

	return status;
}



uint8 UART_sendByte(const uint8 data){
uint8 status =OK;

	if ( (Confg_Uart_Ptr->IS_init==INITIALIZED) && (Confg_Uart_Ptr->Event_Handling== POOLING ) )
	{

		while (!(UCSRA & (1<<UDRE))){} // UDRE flag is set when the TX buffer (UDR) is empty

		UDR = data; ///Put the required data in the UDR register

	}
else if ( (Confg_Uart_Ptr->IS_init==INITIALIZED) && (Confg_Uart_Ptr->Event_Handling== INTERRUPT ) ){
	Tx_Flag=1;
	Tx_data=data;
	
}
else{
	status = NOK;
}
return status;

}




uint8 UART_recieveByte(uint8 * data){
 uint8 status =OK;
 
		if ( (Confg_Uart_Ptr->IS_init==INITIALIZED) && (Confg_Uart_Ptr->Event_Handling== POOLING ) )
		{

			while (!(UCSRA & (1<<UDRE))){} // UDRE flag is set when the TX buffer (UDR) is empty

			*data=UDR; // Read the received data from  (UDR) ///Put the required data in the UDR register

		}
else if ( (Confg_Uart_Ptr->IS_init==INITIALIZED) && (Confg_Uart_Ptr->Event_Handling== INTERRUPT ) ){
if(Rx_Flag==1){
	*data=Rx_data;
		Rx_Flag =0;
}	
}
else{
	status = NOK;
}
return status;
		


	}




ISR(USART_RXC_vect)
{
	
		
			rx();
		
}


ISR(USART_TXC_vect)
{
	if(Tx_Flag==1){
	tx();
	}
}




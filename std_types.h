/******************************************************************************
 *
 * Module: Common - Platform Types Abstraction
 *
 * File Name: std_types.h
 *
 * Description: standards types for AVR
 *
 * Author: Ahmed Wael
 *
 *******************************************************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_
#include "micro_config.h"

#define NULL (void*)0
/* Boolean Data Type */
typedef unsigned char bool;

/* Boolean Values */
#ifndef FALSE
#define FALSE       (0u)
#endif
#ifndef TRUE
#define TRUE        (1u)
#endif

#define HIGH        (1u)
#define LOW         (0u)

#define OK 1
#define NOK 0

typedef unsigned char         uint8;          /*           0 .. 255             */
typedef signed char           sint8;          /*        -128 .. +127            */
typedef unsigned short        uint16;         /*           0 .. 65535           */
typedef signed short          sint16;         /*      -32768 .. +32767          */
typedef unsigned long         uint32;         /*           0 .. 4294967295      */
typedef signed long           sint32;         /* -2147483648 .. +2147483647     */
typedef unsigned long long    uint64;         /*       0..18446744073709551615  */
typedef signed long long      sint64;
typedef float                 float32;
typedef double                float64;


// DDR Direct Register
//PIN  Input register
//port output register

//registers addresses for Port A
#define DDRA (*(( volatile uint8*)0x3A))
#define PINA (*(( volatile uint8*)0x39))
#define PORTA (*(( volatile uint8*)0x3B))


//registers addresses for port B
#define DDRB (*(( volatile uint8*)0x37))
#define PORTB (*((volatile uint8*)0x38))
#define PINB (*((volatile uint8*)0x36))


//registers addresses port C
#define DDRC (*((volatile uint8*)0x34))
#define PORTC (*((volatile uint8*)0x35))
#define PINC (*((volatile uint8*)0x33))


//registers addresses for port D
#define DDRD (*((volatile uint8*)0x31))
#define PORTD (*((volatile uint8*)0x32))
#define PIND (*((volatile uint8*)0x30))

#define PA0 0
#define PA1 1
#define PA2 2
#define PA3 3
#define PA4 4
#define PA5 5
#define PA6 6
#define PA7 7

#define PB0 0
#define PB1 1
#define PB2 2
#define PB3 3
#define PB4 4
#define PB5 5
#define PB6 6
#define PB7 7

#define PC0 0
#define PC1 1
#define PC2 2
#define PC3 3
#define PC4 4
#define PC5 5
#define PC6 6
#define PC7 7

#define PD0 0
#define PD1 1
#define PD2 2
#define PD3 3
#define PD4 4
#define PD5 5
#define PD6 6
#define PD7 7


/********************TIMERS REGISTERS*****************************/


//Timer control Register address for timer 1 channel A
#define TCCR1A (*(( volatile uint8*)0x4F))
#define TCCR1A_COM1A1 7
#define TCCR1A_COM1A0 6
#define TCCR1A_COM1B1 5
#define TCCR1A_COM1B0 4
#define TCCR1A_FOC1A  3
#define TCCR1A_FOC1B  2
#define TCCR1A_WGM11  1
#define TCCR1A_WGM10  0
//Timer control Register address for timer 1 channel B

#define TCCR1B (*(( volatile uint8*)0x4E))
#define TCCR1B_ICNC1 7
#define TCCR1B_ICES1 6
#define TCCR1B_WGM13 4
#define TCCR1B_WGM12 3
#define TCCR1B_CS12  2
#define TCCR1B_CS11  1
#define TCCR1B_CS10  0

//Timer1 registers address Timer/Counter1 – TCNT1H and TCNT1L

#define TCNT1L (*(( volatile uint16*)0x4C))

//Output Compare Register 1 A – OCR1AH and OCR1AL
#define OCR1AL (*(( volatile uint16*)0x4A))

//Output Compare Register 1 B– OCR1BH and OCR1BL
#define OCR1BL (*(( volatile uint16*)0x48))

//Input Capture Register 1 –ICR1H and ICR1L
#define ICR1L (*(( volatile uint16*)0x46))


//Timer control Register address for timer 0

#define TCCR0 (*(( volatile uint8*)0x53))
#define TCCR0_F0C0 7
#define TCCR0_WGM00 6
#define TCCR0_COM01 5
#define TCCR0_COM00 4
#define TCCR0_WGM01 3
#define TCCR0_CS02 2
#define TCCR0_CS01 1
#define TCCR0_CS00 0


//Timer registers address
#define TCNT0 (*(( volatile uint8*)0x52))


//Output Compare Register address
#define OCR0 (*(( volatile uint8*)0x5C))


//Timer/Counter Interrupt Mask Register – TIMSK
#define TIMSK (*(( volatile uint8*)0x59))
#define TIMSK_OCIE2 7
#define TIMSK_TOIE2 6
#define TIMSK_TICIE1 5
#define TIMSK_OCIE1A 4
#define TIMSK_OCIE1B 3
#define TIMSK_TOIE1 2
#define TIMSK_OCIE0 1
#define TIMSK_TOIE0 0


//Timer/Counter Interrupt Flag Register – TIFR
#define TIFR (*(( volatile uint8*)0x58))
#define TIFR_OCF2 7
#define TIFR_TOV2 6
#define TIFR_ICF1 5
#define TIFR_OCF1A 4
#define TIFR_OCF1B 3
#define TIFR_TOV1 2
#define TIFR_OCF0 1
#define TIFR_TOV0 0



//Timer control Register address for timer 2

#define TCCR2 (*(( volatile uint8*)0x45))
#define TCCR2_F0C2 7
#define TCCR2_WGM20 6
#define TCCR2_COM21 5
#define TCCR2_COM20 4
#define TCCR2_WGM21 3
#define TCCR2_CS22 2
#define TCCR2_CS21 1
#define TCCR2_CS20 0

#define ASSR (*(( volatile uint8*)0x42))
#define ASSR_AS2 3
#define ASSR_TCN2UB 2
#define ASSR_OCR2UB 1
#define ASSR_TCR2UB 0

//Timer registers address
#define TCNT2 (*(( volatile uint8*)0x44))


//Output Compare Register address
#define OCR2 (*(( volatile uint8*)0x43))


//register address for SREG Status Register
#define SREG (*((volatile uint8*)0x5F))
//to enable the Global Interrupt Flag pin
#define SREG_I 7


//ADDRESS OF GICR "GLOBAL INTERRUPT CONTROL REGISTER"
#define GICR_ADDRESS 0x5B
#define GICR (*(volatile uint8 *) GICR_ADDRESS)
#define GIFR_ADDRESS 0x5A
#define GIFR  (*(volatile uint8 *) GIFR_ADDRESS)

//ADDRESS OF MCUCR "MCU CONTROL REGISTER"
#define MCUCR_ADDRESS 0x55
#define MCUCR (*(volatile uint8 *) MCUCR_ADDRESS)

//ADDRESS OF MCUCSR "MCU CONTROL SENSE REGISTER"
#define MCUCSR_ADDRESS 0x54
#define MCUCSR (*(volatile uint8 *) MCUCSR_ADDRESS)
/*

//ADDRESS OF UART DRIVER
#define UCSRC   (*((volatile uint8 *)0x20))
#define UCPOL   0
#define UCSZ0   1
#define UCSZ1   2
#define USBS    3
#define UPM0    4
#define UPM1    5
#define UMSEL   6
#define URSEL   7

#define UBRRH   (*((volatile uint8 *)0x20))
#define URSEL   7

#define UCSRA   (*((volatile uint8 *)0x0B))
#define MPCM    0
#define U2X     1
#define PE      2
#define DOR     3
#define FE      4
#define UDRE    5
#define TXC     6
#define RXC     7
#define NULL (void *)0

#define UBRRL    (*((volatile uint8 *)0x09))
#define UBRRH    (*((volatile uint8 *)0x20))
#define UDR     (*((volatile uint8 *) 0x0C))

#define UCSRB    (*((volatile uint8 *)0x0A))
#define TXB8    0
#define RXB8    1
#define UCSZ2   2
#define TXEN    3
#define RXEN    4
#define UDRIE   5
#define TXCIE   6
#define RXCIE   7

//ADDRESS OF SPI DRIVER
#define SPCR    (*((volatile uint8 *)0x0D))
#define SPR0    0
#define SPR1    1
#define CPHA    2
#define CPOL    3
#define MSTR    4
#define DORD    5
#define SPE     6
#define SPIE    7

#define SPDR   (*((volatile uint8 *)0x0F))

#define SPSR    (*((volatile uint8 *)0x0E))
#define SPI2X   0
#define WCOL    6
#define SPIF    7
*/



#endif STD_TYPE_H_

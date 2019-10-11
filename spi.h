 /******************************************************************************
 *
 * Module: SPI
 *
 * File Name: spi.h
 *
 * Description: Header file for the SPI AVR driver
 *
 * Author: Ahmed Wael
 *
 *******************************************************************************/

#ifndef SPI_H_
#define SPI_H_

#include "std_types.h"
#include "common_macros.h"
#include "Regs.h"
#include "micro_config.h"

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void SPI_initMaster(void); 
void SPI_initSlave(void);
void SPI_sendByte(const uint8 data);
uint8 SPI_recieveByte(void);
void SPI_sendString(const uint8 *Str);
void SPI_receiveString(char *Str);

#endif

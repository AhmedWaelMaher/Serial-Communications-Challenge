/******************************************************************************
 *
 * Module: DIO
 *
 * File Name: Dio.h
 *
 * Description: Header file for the DIO AVR driver
 *
 * Author: Ahmed Wael
 *
 *******************************************************************************/

#ifndef DIO_H_
#define DIO_H_

#include "Dio_config.h"

#define MAX_NUM_PINS (uint8 )32


uint8 DIO_Init(void);
uint8 DIO_Write(uint8 pin , uint8 value);
uint8 DIO_Read(uint8 pin ,uint8 *PVal);




#endif /* DIO_H_ */

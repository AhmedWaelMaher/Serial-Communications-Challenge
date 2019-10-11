 /******************************************************************************
 *
 * Module: Service
 *
 * File Name: Service.h
 *
 * Description: service layer
 *
 * Author: Ahmed Wael
 *
 *******************************************************************************/

#ifndef SERVICE_H_
#define SERVICE_H_

#include "DIO.h"
#include "TIMER.h"
#include "communication_manager.h"

#define F_CPU_D 16000000ul

uint8 SERVICE_init (void);
uint8 Delay(uint8 TIMER_ID,uint64 Delay);
#endif /* SERVICE_H_ */

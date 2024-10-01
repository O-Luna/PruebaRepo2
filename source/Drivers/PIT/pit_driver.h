/*
 * pit_driver.h
 *
 *  Created on: 28 sep. 2024
 *      Author: oralu
 */

#ifndef DRIVERS_PIT_PIT_DRIVER_H_
#define DRIVERS_PIT_PIT_DRIVER_H_

volatile extern uint8_t u_sec;
volatile extern uint8_t d_sec;

void PIT_init_d();
void PIT_Delay(int time);



#endif /* DRIVERS_PIT_PIT_DRIVER_H_ */

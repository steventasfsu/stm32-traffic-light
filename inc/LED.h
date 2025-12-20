/*
 * LED.h
 *
 *  Created on: Dec 3, 2025
 *      Author: thorn
 */

#ifndef LED_H_
#define LED_H_
#include "stm32l476xx.h"

void configure_light1(void);

void configure_light2(void);

void turn_on_light1_RED(void);

void turn_on_light1_GREEN(void);

void turn_on_light1_YELLOW(void);

void turn_off_light1_RED(void);

void turn_off_light1_GREEN(void);

void turn_off_light1_YELLOW(void);

void turn_on_light2_RED(void);

void turn_on_light2_GREEN(void);

void turn_on_light2_YELLOW(void);

void turn_off_light2_RED(void);

void turn_off_light2_GREEN(void);

void turn_off_light2_YELLOW(void);

void configure_walk(void);

void turn_on_walk1(void);

void turn_off_walk1(void);

void turn_off_walk2(void);

void turn_off_walk2(void);

#endif /* LED_H_ */

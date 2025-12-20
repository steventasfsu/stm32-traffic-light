/*
 * SysTick.h
 *
 *  Created on: Dec 3, 2025
 *      Author: thorn
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_
#include "stm32l476xx.h"

// Modular function to configure SysTick	module
static void SysTick_DelayTicks(uint32_t ticks);

// SysTick Exception Handler
//void SysTick_Handler(void);

void DelayMs(uint32_t ms);

#endif /* SYSTICK_H_ */

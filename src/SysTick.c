/*
 * SysTick.c
 *
 *  Created on: Dec 3, 2025
 *      Author: thorn
 */
#include "SysTick.h"
volatile uint32_t g_msTicks = 0;

static void SysTick_DelayTicks(uint32_t ticks)
{
    SysTick->CTRL = 0;                       // stop
    SysTick->LOAD = ticks - 1;               // set reload
    SysTick->VAL  = 0;                       // reset current value

    // CLKSOURCE = CPU clock, ENABLE = 1, NO interrupt
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk;

    // wait until COUNTFLAG is set (timer counted to 0 once)
    while ((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) == 0) {
        // just wait
    }

    SysTick->CTRL = 0;                       // stop SysTick
}

// public function: delay in ms (for 4 MHz clock)
void DelayMs(uint32_t ms)
{
    // 4 MHz → 4000 cycles per ms
    uint32_t ticks = ms * 4000U;             // 1 ms = 4000 ticks

    // max SysTick reload is 2^24 - 1 ≈ 16.7M, so up to ~4 seconds at 4MHz
    if (ticks == 0) return;
    SysTick_DelayTicks(ticks);
}



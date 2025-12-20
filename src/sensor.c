/*
 * sensor.c
 *
 *  Created on: Dec 3, 2025
 *      Author: thorn
 */


#include "sensor.h"
void configure_Sensor_pin(void){
    // GPIOC clock
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;
    //---------------- SW1 (PC2, pull-down) ----------------
    GPIOC->MODER &= ~(3UL<<(2*2));   // input
    GPIOC->PUPDR &= ~(3UL<<(2*2));
    GPIOC->PUPDR |=  (1UL<<(2*2));   // pull-down

    //---------------- SW2 (PC3, pull-down) ----------------
    GPIOC->MODER &= ~(3UL<<(2*3));   // input
    GPIOC->PUPDR &= ~(3UL<<(2*3));	 // Reset PUPDR setting
    GPIOC->PUPDR |=  (1UL<<(2*3));   // pull-down
}

void configure_EXTI_Sensor(void){
    // 1) Enable SYSCFG clock
    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
    // 2) Map EXTI2 and EXTI3 to Port C  (EXTICR[0] handles EXTI0..3)
    SYSCFG->EXTICR[0] &= ~((0xF << 8) | (0xF << 12));   // clear fields for EXTI2, EXTI3
    SYSCFG->EXTICR[0] |=  ((0x2 << 8) | (0x2 << 12));   // 0x2 = Port C
    // 3) Configure trigger edges
    //    SW1 on PC2 is negative logic → Falling edge
    //    SW2 on PC3 is negative logic → falling edge
    EXTI->RTSR1 &= ~((1<<2) | (1<<3));	//Reset Rising setting
    EXTI->FTSR1 &= ~((1<<2) | (1<<3));	//Reset Falling setting
    EXTI->FTSR1 |=  (1<<2);     // Falling on line 2
    EXTI->FTSR1 |=  (1<<3);     // Falling on line 3
    // 4) Clear any stale pending flags
    EXTI->PR1 = (1<<2) | (1<<3);
    // 5) Unmask EXTI lines
    EXTI->IMR1 |= (1<<2) | (1<<3);
    // 6) Enable NVIC IRQs
    NVIC_EnableIRQ(EXTI2_IRQn);
    NVIC_EnableIRQ(EXTI3_IRQn);
}





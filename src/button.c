/*
 * button.c
 *
 *  Created on: Dec 3, 2025
 *      Author: thorn
 */

#include "button.h"

void configure_Push_Button_pin(){
    // 1. Enable the clock to GPIO Port A
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;

	// 2. Configure GPIO Mode to 'Input': Input(00), Output(01), AlterFunc(10), Analog(11)
	GPIOA->MODER &= ~(3UL<<(2*0));  	// Input (00)
	GPIOA->MODER &= ~(3UL<<(2*1));
	// 3. Configure GPIO Push-Pull to 'No Pull-up or Pull-down': No pull-up, pull-down (00), Pull-up (01), Pull-down (10), Reserved (11)
	GPIOA->PUPDR &= ~(3UL << (2*0));	// Reset PUPDR settings for both
	GPIOA->PUPDR &= ~(3UL << (2*1));
	GPIOA->PUPDR |=  (2UL << (2*0));   // Set the buttons to pull-down resistor
	GPIOA->PUPDR |=  (2UL << (2*1));
}

void configure_EXTI(void){
	// 1. Configure the SYSCFG module to link EXTI line 0 and 1 to GPIO PA0 and PA1
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;							// Enable the clock to SYSCFG
	SYSCFG->EXTICR[0] &= ~((0xF << 0) | (0xF << 4));   // clear fields for EXTI0, EXTI1
	SYSCFG->EXTICR[0] |=  ((0x0 << 0) | (0x0 << 4));   // 0x0 = Port A

	// 2. Enable (unmask) the EXTI 0 and 1 interrupt by setting its corresponding bit in the EXTI's IMR.
	EXTI->IMR1 |= (1<<0);     //Interrupt Mask Register (IMR): 0 = marked, 1 = not masked (i.e., enabled)
	EXTI->IMR1 |= (1<<1);
	// 3. Enable interrupt trigger for Rising (button press) edge
	EXTI->RTSR1 |= (1<<0);  //Rising trigger selection register (RTSR):0 = disabled, 1 = enabled
	EXTI->RTSR1 |= (1<<1);  //Falling trigger selection register (FTSR): 0 = disabled, 1 = enabled
	EXTI->PR1 = (1<<0) | (1<<1);
	// 4. Enable the interrupt
	NVIC_EnableIRQ(EXTI0_IRQn);
	NVIC_EnableIRQ(EXTI1_IRQn);
}



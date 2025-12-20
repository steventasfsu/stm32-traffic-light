/*
 * LED.c
 *
 *  Created on: Dec 6, 2025
 *      Author: thorn
 */


#include "LED.h"

void configure_light1(void){
	    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
	//---------------- LED1 (PB4) RED ----------------
	    GPIOB->MODER &= ~(3UL<<(2*4));   // clear mode
	    GPIOB->MODER |=  (1UL<<(2*4));   // output
	    GPIOB->OTYPER &= ~(1UL<<4);      // push-pull
	    GPIOB->PUPDR  &= ~(3UL<<(2*4));  // no pull
	    GPIOB->ODR    &= ~(1UL<<4);      // start OFF (PB4 low)
    //  ---------------- LED2 (PB5) GREEN----------------
	    GPIOB->MODER &= ~(3UL<<(2*5));
	    GPIOB->MODER |=  (1UL<<(2*5));   // output
	    GPIOB->OTYPER &= ~(1UL<<5);
	    GPIOB->PUPDR  &= ~(3UL<<(2*5));
	    GPIOB->ODR    &=  ~(1UL<<5);
	//  ---------------- LED3 (PB3) YELLOW----------------
		GPIOB->MODER &= ~(3UL<<(2*3));
		GPIOB->MODER |=  (1UL<<(2*3));   // output
		GPIOB->OTYPER &= ~(1UL<<3);
		GPIOB->PUPDR  &= ~(3UL<<(2*3));
		GPIOB->ODR    &=  ~(1UL<<3);
}
void turn_on_light1_RED(void){
	GPIOB->ODR |= (1 << 4);
}

void turn_on_light1_GREEN(void){
	GPIOB->ODR |= (1 << 5);
}

void turn_on_light1_YELLOW(void){
	GPIOB->ODR |= (1 << 3);
}

void turn_off_light1_RED(void){
	GPIOB->ODR &= ~(1 <<4);
}

void turn_off_light1_GREEN(void){
	GPIOB->ODR &= ~(1 <<5);
}
void turn_off_light1_YELLOW(void){
	GPIOB->ODR &= ~(1 <<3);
}

void configure_light2(void){
	 	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
	//---------------- LED1 (PA5) RED ----------------
		GPIOA->MODER &= ~(3UL<<(2*5));   // clear mode
		GPIOA->MODER |=  (1UL<<(2*5));   // output
		GPIOA->OTYPER &= ~(1UL<<5);      // push-pull
		GPIOA->PUPDR  &= ~(3UL<<(2*5));  // no pull
		GPIOA->ODR    &= ~(1UL<<5);      // start OFF (PB4 low)
	//  ---------------- LED2 (PA6) GREEN----------------
		GPIOA->MODER &= ~(3UL<<(2*6));
		GPIOA->MODER |=  (1UL<<(2*6));   // output
		GPIOA->OTYPER &= ~(1UL<<6);
		GPIOA->PUPDR  &= ~(3UL<<(2*6));
		GPIOA->ODR    &=  ~(1UL<<6);
	//  ---------------- LED3 (PA7) YELLOW----------------
		GPIOA->MODER &= ~(3UL<<(2*7));
		GPIOA->MODER |=  (1UL<<(2*7));   // output
		GPIOA->OTYPER &= ~(1UL<<7);
		GPIOA->PUPDR  &= ~(3UL<<(2*7));
		GPIOA->ODR    &=  ~(1UL<<7);
}

void turn_on_light2_RED(void){
	GPIOA->ODR |= (1 << 5);
}

void turn_on_light2_GREEN(void){
	GPIOA->ODR |= (1 << 6);
}

void turn_on_light2_YELLOW(void){
	GPIOA->ODR |= (1 << 7);
}

void turn_off_light2_RED(void){
	GPIOA->ODR &= ~(1 <<5);
}

void turn_off_light2_GREEN(void){
	GPIOA->ODR &= ~(1 <<6);
}

void turn_off_light2_YELLOW(void){
	GPIOA->ODR &= ~(1 <<7);
}

void configure_walk(void){
	 	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
	//---------------- LED1 (PC6)  ----------------
		GPIOC->MODER &= ~(3UL<<(2*6));   // clear mode
		GPIOC->MODER |=  (1UL<<(2*6));   // output
		GPIOC->OTYPER &= ~(1UL<<6);      // push-pull
		GPIOC->PUPDR  &= ~(3UL<<(2*6));  // no pull
		GPIOC->ODR    &= ~(1UL<<6);      // start OFF (PB4 low)
	//  ---------------- LED2 (PC8) ----------------
		GPIOC->MODER &= ~(3UL<<(2*8));
		GPIOC->MODER |=  (1UL<<(2*8));   // output
		GPIOC->OTYPER &= ~(1UL<<8);
		GPIOC->PUPDR  &= ~(3UL<<(2*8));
		GPIOC->ODR    &=  ~(1UL<<8);
}

void turn_on_walk1(void){
	GPIOC->ODR |= (1 << 6);
}

void turn_off_walk1(void){
	GPIOC->ODR &= ~(1 <<6);
}

void turn_on_walk2(void){
	GPIOC->ODR |= (1 <<8);
}

void turn_off_walk2(void){
	GPIOC->ODR &= ~(1 <<8);
}

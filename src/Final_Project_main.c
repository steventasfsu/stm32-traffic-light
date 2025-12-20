/*
 * Final_Project_main.c
 *
 *  Created on: Dec 2, 2025
 *      Author: thorn
 */
//#include "stm32l476xx.h"
#include "stm32l476xx.h"
#include "sensor.h"
#include "LED.h"
#include "SysTick.h"
#include "button.h"
volatile int8_t counter = 0;

//Interrupt for button 1
void EXTI0_IRQHandler(void){
    if (EXTI->PR1 & (1<<0)) {
    	EXTI->PR1 = (1<<0);
    	counter++;
    	//checks if corresponding light is already green then walk light can turn on right away
        if(GPIOB->ODR & (1 << 5)){
        	turn_on_walk1();
        	DelayMs(3000); // delay for 3 seconds to keep light on
        	turn_off_walk1();
    	//if the light was red it has to go through the process of turning it green
        }else{
        	DelayMs(3000);
        	turn_off_light2_GREEN();
        	DelayMs(200);
        	turn_on_light2_YELLOW();
        	DelayMs(3000);
        	turn_off_light2_YELLOW();
        	DelayMs(200);
        	turn_on_light2_RED();
        	DelayMs(200);
        	turn_on_walk1();
        	turn_off_light1_RED();
        	DelayMs(200);
        	turn_on_light1_GREEN();
        	DelayMs(3000);
        	turn_off_walk1();
        }
    }
}

// interrupt for button 2
void EXTI1_IRQHandler(void){
    if (EXTI->PR1 & (1<<1)) {
    	EXTI->PR1 = (1<<1);
    	counter++;
    	//checks if corresponding light is already green then walk light can turn on right away
    	if(GPIOA->ODR & (1 << 6)){
			turn_on_walk2();
			DelayMs(3000); // delay for 3 seconds to keep light on
			turn_off_walk2();
		//if the light was red it has to go through the process of turning it green
		}else{
			DelayMs(3000);
			turn_off_light1_GREEN();
			DelayMs(200);
			turn_on_light1_YELLOW();
			DelayMs(3000);
			turn_off_light1_YELLOW();
			DelayMs(200);
			turn_on_light1_RED();
			DelayMs(200);
			turn_on_walk2();
			turn_off_light2_RED();
			DelayMs(200);
			turn_on_light2_GREEN();
			DelayMs(3000);
			turn_off_walk2();
		}
    }
}

// interrupt for sensor 1
void EXTI2_IRQHandler(void){
    if (EXTI->PR1 & (1<<2)) {
    	EXTI->PR1 = (1<<2);
    	// if statement checks if the corresponding light is already green
        if(GPIOA->ODR & (1 << 6)){
        	DelayMs(3000); // 3 second delay before lights are changed
        	turn_off_light2_GREEN();
        	DelayMs(200); //small delay so when we can notice one light turning off before another turning on
        	turn_on_light2_YELLOW();
        	DelayMs(3000);
        	turn_off_light2_YELLOW();
        	DelayMs(200);
        	turn_on_light2_RED();
        	DelayMs(200);
        	turn_off_light1_RED();
			DelayMs(200);
        	turn_on_light1_GREEN();
        }
    }
}

// interrupt for sensor 2
void EXTI3_IRQHandler(void){
	// check is interruption was caused
	 if (EXTI->PR1 & (1<<3)) {
	    	EXTI->PR1 = (1<<3); // clear interruption by setting to 1
	    	//if statement used to see if the corresponding traffic light is already green before proceeding
	        if(GPIOB->ODR & (1 << 5)){
	        	DelayMs(3000); // delay before doing anything
	        	turn_off_light1_GREEN();
	        	DelayMs(200);  // small delay so when we can notice one light turning off before another turning on
	        	turn_on_light1_YELLOW();
	        	DelayMs(3000);
	        	turn_off_light1_YELLOW();
	        	DelayMs(200);
	        	turn_on_light1_RED();
	        	DelayMs(200);
	        	turn_off_light2_RED();
	        	DelayMs(200);
	        	turn_on_light2_GREEN();
	        }
	    }
}

// main code
int main(void){
	// Use the functions from the header files to configure inputs and outputs
    configure_Sensor_pin();
    configure_EXTI_Sensor();
    configure_light1();
    configure_light2();
    configure_Push_Button_pin();
    configure_EXTI();
    configure_walk();
    // start with traffic light one green and traffic light red
    turn_on_light1_GREEN();
    turn_on_light2_RED();
    // main loop (do nothing, wait for interrupts)
    while(1){
    }
}


/*
 * button.h
 *
 *  Created on: Dec 3, 2025
 *      Author: thorn
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include "stm32l476xx.h"
//This function contains the configuration fo the button, like output type and push pull
void configure_Push_Button_pin();
// this function contains the exti interrupt when the button is pressed
void configure_EXTI(void);

#endif /* BUTTON_H_ */

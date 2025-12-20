/*
 * sensor.h
 *
 *  Created on: Dec 3, 2025
 *      Author: thorn
 */

#ifndef SENSOR_H_
#define SENSOR_H_

#include "stm32l476xx.h"
//This function contains the configuration fo the button, like output type and push pull
void configure_Sensor_pin();
// this function contains the exti interrupt when the button is pressed
void configure_EXTI_Sensor(void);

#endif /* SENSOR_H_ */

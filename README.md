**ENGR 478 Final Project: Traffic Light**

**SFSU Group: C-Note**
Bryan Thorne
Steven Ta
Kevin Thai

# stm32-traffic-light
Embedded traffic light controller built on an STM32 Nucleo-L476RG board. Includes dual traffic signals, pedestrian walk lights, IR sensors, and button inputs. Implements a finite-state machine, SysTick timing, and real-world intersection behavior.

**Introduction**

The goal of our project was to create a traffic light using the STM32L476RG board. We made two different traffic lights that were used to simulate an intersection of two one-way roads. We also wanted to make it more realistic by adding in a pedestrian walk light. We used an IR break beam sensor to detect the presence of the car, and we used a push button for the pedestrians. For the code, we integrated the use of interrupts for the sensors and buttons, then we used the systick timer for any delay that we needed. Our motivation came from seeing these types of intersections in SF and wondering how we could use the STM32 board to make it.

**Components: **

•	2 IR break beam sensors  
•	2 Push buttons  
•	Wiring  
•	8 LEDs  
    o	2 Red  
    o	2 Green  
    o	2 Yellow  
    o	2 Clear  
•	2 10kΩ resistors (for the button)  
•	8 330Ω resistors (for the LEDs)

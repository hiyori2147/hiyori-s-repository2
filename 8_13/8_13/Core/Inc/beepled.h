#ifndef __LED_FLOW_H
#define __LED_FLOW_H

#include "stm32f4xx_hal.h"
#define LED_PORT        GPIOA
#define LED_PINS        (GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7)
#define LED_COUNT       4  // LED??

// ????
void LED_Flow_Init(TIM_HandleTypeDef *htim);
void LED_Flow_Start(void);


#endif /* __LED_FLOW_H */

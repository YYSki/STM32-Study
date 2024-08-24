#ifndef BSP_LED_H
#define BSP_LED_H

#include "stm32f10x_gpio.h"

typedef enum {
    LED1 = GPIO_Pin_12,
    LED2 = GPIO_Pin_13,
} LedNum_t;

typedef enum {
    LED_ON  = Bit_SET,
    LED_OFF = Bit_RESET,
} LedStatus_t;

void LED_Init(void);
void LED_SetLED(LedNum_t LedNum, LedStatus_t LedStatus);
void LED_TurnLed(LedNum_t LedNum);

#endif

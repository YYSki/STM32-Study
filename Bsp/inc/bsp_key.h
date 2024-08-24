#ifndef BSP_KEY_H
#define BSP_KEY_H

#include "stm32f10x_gpio.h"

typedef enum {
    KEY1 = GPIO_Pin_8,
    KEY2 = GPIO_Pin_12,
} KeyNum_t;

typedef enum {
    KEY_ON = 0,
    KEY_OFF,
} KeyStatus_t;

void KEY_Init(void);
KeyStatus_t KEY_KeyScan(KeyNum_t KeyNum);

#endif

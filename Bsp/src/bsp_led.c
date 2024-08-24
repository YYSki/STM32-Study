#include "bsp_led.h"
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"

void LED_Init(void) {
    GPIO_InitTypeDef GPIO_LedSet = {
        .GPIO_Pin   = GPIO_Pin_12 | GPIO_Pin_13,
        .GPIO_Mode  = GPIO_Mode_Out_PP,
        .GPIO_Speed = GPIO_Speed_50MHz,
    };

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // 开启GPIOB时钟
    GPIO_Init(GPIOB, &GPIO_LedSet);
}

void LED_SetLED(LedNum_t LedNum, LedStatus_t LedStatus) {
    GPIO_WriteBit(GPIOB, LedNum, (BitAction)LedStatus);
}

void LED_TurnLed(LedNum_t LedNum) {
    if (LED_ON == GPIO_ReadOutputDataBit(GPIOB, LedNum)) {
        LED_SetLED(LedNum, LED_OFF);
    } else if (LED_OFF == GPIO_ReadOutputDataBit(GPIOB, LedNum)) {
        LED_SetLED(LedNum, LED_ON);
    }
}

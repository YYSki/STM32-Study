#include "bsp_key.h"
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"

void KEY_Init(void) {
    GPIO_InitTypeDef GPIO_KeySet = {
        .GPIO_Pin   = GPIO_Pin_8 | GPIO_Pin_12,
        .GPIO_Mode  = GPIO_Mode_IPU, /* 上拉输入 */
        .GPIO_Speed = GPIO_Speed_50MHz,
    };

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_Init(GPIOA, &GPIO_KeySet);
}

KeyStatus_t KEY_KeyScan(KeyNum_t KeyNum) {
    KeyStatus_t keyStatus = KEY_OFF;

    if (KEY_ON == GPIO_ReadInputDataBit(GPIOA, KeyNum)) {
        /* 按下消抖 */
        for (int i = 0; i < 1000000; i++) {}
        /* 再次读取 GPIO 状态 */
        keyStatus = (KeyStatus_t)GPIO_ReadInputDataBit(GPIOA, KeyNum);
        /* 抬起消抖 */
        for (int i = 0; i < 1000000; i++) {}
    }

    return keyStatus;
}

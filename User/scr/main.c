#include "bsp_key.h"
#include "bsp_led.h"

int main(void) {
    LED_Init();
    KEY_Init();

    while (1) {
        if (KEY_ON == KEY_KeyScan(KEY1)) {
            LED_TurnLed(LED1);
        }

        if (KEY_ON == KEY_KeyScan(KEY2)) {
            LED_TurnLed(LED2);
        }
    }

    // return 0;
}

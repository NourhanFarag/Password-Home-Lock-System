#include "button.h"
#include "delay.h"

unsigned char Button_readStart(void) {
    if (START_BUTTON_PIN == 0) {
        delay_ms(20);
        if (START_BUTTON_PIN == 0) {
            while (START_BUTTON_PIN == 0);
            return BUTTON_PRESSED;
        }
    }
    return BUTTON_RELEASED;
}

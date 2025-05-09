#include "button.h"
#include "delay.h"

unsigned char Button_isACPressed(void) {
    if (AC_button == BUTTON_PRESSED) {
        delay_ms(20);  // debounce delay
        if (AC_button == BUTTON_PRESSED) {
            while (AC_button == BUTTON_PRESSED); // wait for release
            return BUTTON_PRESSED;
        }
    }
    return BUTTON_RELEASED;
}

unsigned char Button_isLightPressed(void) {
    if (Light_button == BUTTON_PRESSED) {
        delay_ms(20);  // debounce delay
        if (Light_button == BUTTON_PRESSED) {
            while (Light_button == BUTTON_PRESSED); // wait for release
            return BUTTON_PRESSED;
        }
    }
    return BUTTON_RELEASED;
}

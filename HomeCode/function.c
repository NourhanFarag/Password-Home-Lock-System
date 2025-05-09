#include "function.h"
#include "lcd.h"
#include "keypad.h"
#include "delay.h"
#include "password.h"

extern unsigned char correct_pass_flag;

void Password_inputFromUser(void) {
    unsigned char i = 0, key;
    for (i = 0; i < 4; i++) entered_pass[i] = 0;

    i = 0;
    while (1) {
        key = Keypad_getKey();
        if (key == '#') break;

        if (key >= '0' && key <= '9' && i < 4) {
            entered_pass[i] = key;
            LCD_writeChar(entered_pass[i]);
            i++;
        } else if (key == '*' && i > 0) {
            i--;
            entered_pass[i] = 0;
            LCD_setCursor(1, i);
            LCD_writeChar(' ');
            LCD_setCursor(1, i);
        }

        delay_ms(50);
    }

    while (Keypad_getKey() != '#');
}

void Password_checkCorrect(void) {
    unsigned char i;
    correct_pass_flag = 0;
    for (i = 0; i < 4; i++) {
        if (entered_pass[i] != saved_pass[i])
            correct_pass_flag = 1;
    }
}

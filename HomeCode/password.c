#include "password.h"
#include "lcd.h"
#include "leds.h"
#include "delay.h"

// Define real memory for globals
unsigned char saved_pass[5] = {'1', '2', '3', '4', '\0'};
unsigned char entered_pass[5];
unsigned char num_ofCorrect_Password = 3;

void Password_successAction(void) {
    LCD_clear();
    LCD_writeText("Open");
    delay_ms(1000);

    LCD_clear();
    LCD_writeText("Close");
    delay_ms(500);

    LED_setGreen(LED_OFF);
    LCD_clear();
}

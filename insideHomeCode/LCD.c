#include "lcd.h"

void LCD_init(void) {
    LCD_RS = 0;
    LCD_En = 0;
    delay_ms(20);  // Required startup delay
    LCD_DATA_PORT = 0x00;

    LCD_sendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE); // 8-bit, 2 line
    LCD_sendCommand(LCD_CURSOR_OFF);                // Cursor off
    LCD_sendCommand(LCD_CLEAR_COMMAND);             // Clear LCD
}

void LCD_sendCommand(unsigned char command) {
    LCD_RS = 0;      // Command mode
    delay_ms(1);
    LCD_En = 1;      // Enable high
    delay_ms(1);
    LCD_DATA_PORT = command;
    delay_ms(1);
    LCD_En = 0;      // Enable low
    delay_ms(1);
}

void LCD_displayCharacter(unsigned char my_data) {
    LCD_RS = 1;      // Data mode
    delay_ms(1);
    LCD_En = 1;      // Enable high
    delay_ms(1);
    LCD_DATA_PORT = my_data;
    delay_ms(1);
    LCD_En = 0;      // Enable low
    delay_ms(1);
}

void LCD_displayString(const char *Str) {
    unsigned char i;
    for (i = 0; Str[i] != '\0'; i++) {
        LCD_displayCharacter(Str[i]);
    }
}

void LCD_clearScreen(void) {
    LCD_sendCommand(LCD_CLEAR_COMMAND);
}

void LCD_moveCursor(unsigned char row, unsigned char col) {
    unsigned char memory_address;

    switch (row) {
        case 0: memory_address = col; break;
        case 1: memory_address = col + 0x40; break;
        case 2: memory_address = col + 0x10; break;
        case 3: memory_address = col + 0x50; break;
        default: memory_address = col; break;
    }
    LCD_sendCommand(memory_address | LCD_SET_CURSOR_LOCATION);
}

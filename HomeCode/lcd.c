#include <reg51.h>
#include "delay.h"
#include "lcd.h"

void LCD_init(void) {
    LCD_RS = 0;
    LCD_E = 0;
    LCD_RW = 0;
    delay_ms(20);
    LCD_DATA_PORT = 0x00;

    LCD_sendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE);
    LCD_sendCommand(LCD_CURSOR_OFF);
    LCD_sendCommand(LCD_CLEAR_COMMAND);
}

void LCD_sendCommand(unsigned char command) {
    LCD_RS = 0;     // Command mode
    LCD_RW = 0;     // Write mode
    delay_ms(1);
    LCD_E = 1;
    delay_ms(1);
    LCD_DATA_PORT = command;
    delay_ms(1);
    LCD_E = 0;
    delay_ms(1);
}

void LCD_writeChar(unsigned char character) {
    LCD_RS = 1;     // Data mode
    LCD_RW = 0;     // Write mode
    delay_ms(1);
    LCD_E = 1;
    delay_ms(1);
    LCD_DATA_PORT = character;
    delay_ms(1);
    LCD_E = 0;
    delay_ms(1);
}

void LCD_writeText(const char *text) {
    while (*text) {
        LCD_writeChar(*text++);
    }
}

void LCD_clear(void) {
    LCD_sendCommand(LCD_CLEAR_COMMAND);
}

void LCD_setCursor(unsigned char row, unsigned char col) {
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

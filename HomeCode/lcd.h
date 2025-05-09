#ifndef LCD_H
#define LCD_H

#include <reg51.h>
#include "delay.h"

// LCD Control Pins using sbit
sbit LCD_RS = P0^0;
sbit LCD_E  = P0^1;
sbit LCD_RW = P0^2;

// LCD Data Port
#define LCD_DATA_PORT P1

// LCD Command Constants
#define LCD_CLEAR_COMMAND                0x01
#define LCD_GO_TO_HOME                   0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE    0x38
#define LCD_CURSOR_OFF                   0x0C
#define LCD_CURSOR_ON                    0x0E
#define LCD_SET_CURSOR_LOCATION          0x80

// Function Prototypes
void LCD_init(void);
void LCD_sendCommand(unsigned char command);
void LCD_writeChar(unsigned char character);
void LCD_writeText(const char *text);
void LCD_clear(void);
void LCD_setCursor(unsigned char row, unsigned char col);

#endif /* LCD_H */

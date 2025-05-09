#ifndef LCD_H
#define LCD_H

#include <reg51.h>
#include "delay.h"

// LCD Control Pins
sbit LCD_RS = P0^1;
sbit LCD_En = P0^0;

// LCD Data Port
#define LCD_DATA_PORT P1

// LCD Command Constants
#define LCD_CLEAR_COMMAND                0x01
#define LCD_GO_TO_HOME                   0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE    0x38
#define LCD_CURSOR_OFF                   0x0C
#define LCD_CURSOR_ON                    0x0E
#define LCD_SET_CURSOR_LOCATION          0x80

// LCD Function Prototypes
void LCD_init(void);
void LCD_sendCommand(unsigned char command);
void LCD_displayCharacter(unsigned char my_data);
void LCD_displayString(const char *Str);
void LCD_clearScreen(void);
void LCD_moveCursor(unsigned char row, unsigned char col);

#endif /* LCD_H */

#ifndef KEYPAD_H
#define KEYPAD_H

#include <reg51.h>
#include "lcd.h"
#include "delay.h"

/* Define keypad configuration */
#define KEYPAD_NUM_COLS 3
#define KEYPAD_NUM_ROWS 4

/* Define ports for rows and columns */
#define KEYPAD_PORT P2

/* Button states */
#define KEYPAD_BUTTON_PRESSED  0
#define KEYPAD_BUTTON_RELEASED 1

/* Define pin mappings for rows */
sbit KEYPAD_ROW1 = KEYPAD_PORT^3;
sbit KEYPAD_ROW2 = KEYPAD_PORT^4;
sbit KEYPAD_ROW3 = KEYPAD_PORT^5;
sbit KEYPAD_ROW4 = KEYPAD_PORT^6;

/* Define pin mappings for columns */
sbit KEYPAD_COL1 = KEYPAD_PORT^0;
sbit KEYPAD_COL2 = KEYPAD_PORT^1;
sbit KEYPAD_COL3 = KEYPAD_PORT^2;

/* Function prototype */
unsigned char Keypad_getKey(void);

#endif /* KEYPAD_H */

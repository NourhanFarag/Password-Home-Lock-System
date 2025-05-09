#ifndef BUTTON_H
#define BUTTON_H

#include <reg51.h>

// Define START button pin properly
sbit START_BUTTON_PIN = P3^3;

// Button states
#define BUTTON_PRESSED   1
#define BUTTON_RELEASED  0

// Function Prototype
unsigned char Button_readStart(void);

#endif

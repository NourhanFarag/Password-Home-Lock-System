#ifndef BUTTON_H
#define BUTTON_H

#include <reg51.h>

// Define Button Pins
sbit AC_button = P3^2;
sbit Light_button = P3^3;

// Define Button States
#define BUTTON_PRESSED  0
#define BUTTON_RELEASED 1

// Function Prototypes
unsigned char Button_isACPressed(void);
unsigned char Button_isLightPressed(void);

#endif /* BUTTON_H */

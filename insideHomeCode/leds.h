#ifndef LEDS_H
#define LEDS_H

#include <reg51.h>

// LED Pin Definitions
sbit LED_WHITE  = P0^5;
sbit LED_BLUE   = P0^4;
sbit LED_YELLOW = P0^3;
sbit LED_ORANGE = P0^2;

// LED States
#define LED_ON   0
#define LED_OFF  1

// Function Prototypes
void LED_setWhite(unsigned char status);
void LED_setBlue(unsigned char status);
void LED_setYellow(unsigned char status);
void LED_setOrange(unsigned char status);

#endif /* LEDS_H */

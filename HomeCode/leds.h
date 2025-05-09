#ifndef LEDS_H
#define LEDS_H

#include <reg51.h>

// LED Pin Definitions
sbit LED_RED = P0^5;
sbit LED_GREEN = P0^4;

// LED States
#define LED_ON   0
#define LED_OFF  1

// Function Prototypes
void LED_setRed(unsigned char state);
void LED_setGreen(unsigned char state);

#endif /* LEDS_H */

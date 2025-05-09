#include <reg51.h>
#include "lcd.h"
#include "delay.h"
#include "button.h"
#include "leds.h"
#include "i2c_slave.h"

// Global variables
unsigned char AC_button_count = 0;
unsigned char Light_button_count = 0;
bit smart_mode = 0;

// Function prototypes
void LCD_showSmartFeatures(void);
void LCD_showHomeScreen(void);

void main(void) {
    LCD_init();
    I2C_Slave_Init();

    LED_setWhite(LED_OFF);
    LED_setBlue(LED_OFF);
    LED_setYellow(LED_OFF);
    LED_setOrange(LED_OFF);

    LCD_showHomeScreen();

    while (1) {
        I2C_Slave_Check();  // Check for I2C 'S'

        if (smart_mode) {
            // AC Button Handling
            if (Button_isACPressed() == BUTTON_PRESSED) {
                AC_button_count++;
                if (AC_button_count == 1) {
                    LCD_moveCursor(0, 10);
                    LCD_displayString("ON ");
                } else if (AC_button_count == 2) {
                    AC_button_count = 0;
                    LCD_moveCursor(0, 10);
                    LCD_displayString("OFF");
                }
            }

            // Light Button Handling
            if (Button_isLightPressed() == BUTTON_PRESSED) {
                Light_button_count++;
                if (Light_button_count == 1) {
                    LCD_moveCursor(1, 14);
                    LCD_displayString("M1"); 
                    LED_setOrange(LED_ON);
                    LED_setYellow(LED_OFF);
                    LED_setBlue(LED_OFF);									
									  LED_setWhite(LED_OFF); 
                } else if (Light_button_count == 2) {
                    LCD_moveCursor(1, 14);
                    LCD_displayString("M2");
                    LED_setOrange(LED_ON);
                    LED_setYellow(LED_ON);
                    LED_setBlue(LED_OFF);									
									  LED_setWhite(LED_OFF); 
                } else if (Light_button_count == 3) {
                    LCD_moveCursor(1, 14);
                    LCD_displayString("M3");
                    LED_setOrange(LED_ON);
                    LED_setYellow(LED_ON);
                    LED_setBlue(LED_ON);									
									  LED_setWhite(LED_OFF); 
                } else if (Light_button_count == 4) {
                    LCD_moveCursor(1, 14);
                    LCD_displayString("M4");
                    LED_setOrange(LED_ON);
                    LED_setYellow(LED_ON);
                    LED_setBlue(LED_ON);									
									  LED_setWhite(LED_ON); 
                } else if (Light_button_count == 5) {
                    Light_button_count = 0;
                    LCD_moveCursor(1, 13);
                    LCD_displayString("OFF");
                    LED_setOrange(LED_OFF);
                    LED_setYellow(LED_OFF);
                    LED_setBlue(LED_OFF);									
									  LED_setWhite(LED_OFF); 
                }
            }
        }
    }
}

void LCD_showSmartFeatures(void) {
    LCD_clearScreen();
    LCD_moveCursor(0, 0);
    LCD_displayString("AC Status:   ");
    LCD_moveCursor(1, 0);
    LCD_displayString("Light Status:");
}

void LCD_showHomeScreen(void) {
    LCD_clearScreen();
    LCD_displayString("   Smart Home   ");
    LCD_moveCursor(1, 0);
    LCD_displayString(" We Always Here ");
}

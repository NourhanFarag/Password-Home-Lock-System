#include <reg51.h>
#include "i2c_slave.h"

sbit SDA = P0^6;
sbit SCL = P0^7;

extern bit smart_mode;
void LCD_showSmartFeatures(void);

void I2C_Slave_Init(void) {
    SDA = 1;
    SCL = 1;
}

void I2C_Slave_Check(void) {
    if (!SCL && !SDA) {
        smart_mode = 1;
        LCD_showSmartFeatures();
    }
}

#include "i2c.h"
#include "delay.h"

void I2C_init(void) {
    SDA = 1;
    SCL = 1;
}

void I2C_Start(void) {
    SDA = 1; SCL = 1;
    delay_ms(1);
    SDA = 0;
    delay_ms(1);
    SCL = 0;
}

void I2C_Stop(void) {
    SCL = 0; SDA = 0;
    delay_ms(1);
    SCL = 1;
    SDA = 1;
    delay_ms(1);
}

bit I2C_WaitAck(void) {
    SDA = 1;
    SCL = 1;
    delay_ms(1);
    if (SDA) {
        SCL = 0;
        return 0;
    }
    SCL = 0;
    return 1;
}

void I2C_Write(unsigned char dat) {
    unsigned char i;
    for (i = 0; i < 8; i++) {
        SDA = (dat & 0x80);
        SCL = 1;
        delay_ms(1);
        SCL = 0;
        dat <<= 1;
    }
    I2C_WaitAck();
}


#ifndef I2C_H
#define I2C_H

#include <reg51.h>

sbit SDA = P0^6;
sbit SCL = P0^7;


void I2C_init(void);
void I2C_start(void);
void I2C_stop(void);
void I2C_write(unsigned char byte);
bit I2C_WaitAck(void);


#endif

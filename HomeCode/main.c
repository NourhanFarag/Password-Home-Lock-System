#include <reg51.h>
#include "lcd.h"
#include "keypad.h"
#include "leds.h"
#include "delay.h"
#include "password.h"
#include "function.h"
#include "i2c.h"
#include "button.h"

unsigned char correct_pass_flag = 0;
unsigned char reEnter_pass_flag = 0;

void main() {
    unsigned char i;
    static bit welcome_shown = 0;

    LCD_init();
    I2C_init();
    LED_setRed(LED_OFF);
    LED_setGreen(LED_OFF);

    while (1) {
        if (Button_readStart() == BUTTON_PRESSED) {
            welcome_shown = 0;

            LCD_clear();
            LCD_writeText("Enter Password:");
            LCD_setCursor(1, 0);
            Password_inputFromUser();
            Password_checkCorrect();

            if (correct_pass_flag == 0) {
                LED_setGreen(LED_ON);
                LED_setRed(LED_OFF);
                num_ofCorrect_Password = 3;

                Password_successAction();
                I2C_start();
                I2C_write('S');
                I2C_stop();
                delay_ms(300);
            } else {
                num_ofCorrect_Password--;
                LED_setRed(LED_ON);
                LED_setGreen(LED_OFF);

                while (num_ofCorrect_Password != 0) {
                    LCD_clear();
                    LCD_writeText("WRONG PASS");
                    delay_ms(300);

                    LCD_clear();
                    LCD_writeText("Attempts Left:");
                    LCD_writeChar(num_ofCorrect_Password + '0');
                    delay_ms(300);

                    LCD_clear();
                    LCD_writeText("Enter Password:");
                    LCD_setCursor(1, 0);
                    Password_inputFromUser();
                    Password_checkCorrect();

                    if (correct_pass_flag == 1) {
                        num_ofCorrect_Password--;
                        if (num_ofCorrect_Password == 1) {
                            LED_setRed(LED_ON);
                        }
                        delay_ms(100);
                    } else if (correct_pass_flag == 0) {
                        reEnter_pass_flag = 1;
                        num_ofCorrect_Password = 3;
                        break;
                    }
                }
            }

            if (reEnter_pass_flag == 1) {
                reEnter_pass_flag = 0;
                LED_setGreen(LED_ON);
                LED_setRed(LED_OFF);

							  Password_successAction();
                I2C_start();
                I2C_write('S');
                I2C_stop();
                delay_ms(300);
            }

            if (num_ofCorrect_Password == 0) {
                LCD_clear();
                LCD_writeText("ACCESS DENIED");
                LCD_setCursor(1, 0);
                LCD_writeText("INTRUDER ALERT!");
                delay_ms(1000);

                
                for (i = 0; i < 6; i++) {
                    if (i % 2 == 0) {
                        LED_setRed(LED_ON);
                        LED_setGreen(LED_OFF);
                    } else {
                        LED_setRed(LED_OFF);
                        LED_setGreen(LED_ON);
                    }
                    delay_ms(300);
                }

                while (1); // System locked; manual reset needed
            }
        } else if (!welcome_shown) {
            LCD_clear();
            LCD_writeText("Welcome Home -_-");
            welcome_shown = 1;
        }
    }
}
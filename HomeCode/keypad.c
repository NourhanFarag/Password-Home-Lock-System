#include "keypad.h"

/* Function to get the pressed key */
unsigned char Keypad_getKey(void) {
    while (1) {
        // Set all columns high
        KEYPAD_COL1 = 1;
        KEYPAD_COL2 = 1;
        KEYPAD_COL3 = 1;

        delay_ms(50);

        // Activate each row and scan columns
        KEYPAD_ROW1 = 0; KEYPAD_ROW2 = 1; KEYPAD_ROW3 = 1; KEYPAD_ROW4 = 1;
        if (KEYPAD_COL1 == 0) { delay_ms(50); while (KEYPAD_COL1 == 0); return '1'; }
        if (KEYPAD_COL2 == 0) { delay_ms(50); while (KEYPAD_COL2 == 0); return '2'; }
        if (KEYPAD_COL3 == 0) { delay_ms(50); while (KEYPAD_COL3 == 0); return '3'; }

        KEYPAD_ROW1 = 1; KEYPAD_ROW2 = 0; KEYPAD_ROW3 = 1; KEYPAD_ROW4 = 1;
        if (KEYPAD_COL1 == 0) { delay_ms(50); while (KEYPAD_COL1 == 0); return '4'; }
        if (KEYPAD_COL2 == 0) { delay_ms(50); while (KEYPAD_COL2 == 0); return '5'; }
        if (KEYPAD_COL3 == 0) { delay_ms(50); while (KEYPAD_COL3 == 0); return '6'; }

        KEYPAD_ROW1 = 1; KEYPAD_ROW2 = 1; KEYPAD_ROW3 = 0; KEYPAD_ROW4 = 1;
        if (KEYPAD_COL1 == 0) { delay_ms(50); while (KEYPAD_COL1 == 0); return '7'; }
        if (KEYPAD_COL2 == 0) { delay_ms(50); while (KEYPAD_COL2 == 0); return '8'; }
        if (KEYPAD_COL3 == 0) { delay_ms(50); while (KEYPAD_COL3 == 0); return '9'; }

        KEYPAD_ROW1 = 1; KEYPAD_ROW2 = 1; KEYPAD_ROW3 = 1; KEYPAD_ROW4 = 0;
        if (KEYPAD_COL1 == 0) { delay_ms(50); while (KEYPAD_COL1 == 0); return '*'; }
        if (KEYPAD_COL2 == 0) { delay_ms(50); while (KEYPAD_COL2 == 0); return '0'; }
        if (KEYPAD_COL3 == 0) { delay_ms(50); while (KEYPAD_COL3 == 0); return '#'; }
    }
}

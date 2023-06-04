#pragma once

#include <inttypes.h>

typedef int8_t pin_t;

/* Operation of GPIO by pin. */
#define setPinInput(pin)
#define setPinInputHigh(pin)
#define setPinInputLow(pin)
#define setPinOutputPushPull(pin)
#define setPinOutputOpenDrain(pin)
#define setPinOutput(pin)

#define writePinHigh(pin)
#define writePinLow(pin)
#define writePin(pin, level)     
#define togglePin(pin)


#define PINDEF(port, pin)   (pin)

/*
#define MATRIX_ROW_PINS { D4, C6, D7, E6 }
#define MATRIX_COL_PINS { F4, F5, F6, F7, B1, B3 }
*/
#define B1 PINDEF(B, 1)
#define B3 PINDEF(B, 3)
#define C6 PINDEF(C, 6)
#define E6 PINDEF(E, 6)
#define D4 PINDEF(D, 4)
#define D7 PINDEF(D, 7)
#define F4 PINDEF(F, 4)
#define F5 PINDEF(F, 5)
#define F6 PINDEF(F, 6)
#define F7 PINDEF(F, 7)

extern uint8_t readPin(pin_t pin);

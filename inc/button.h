#ifndef BUTTON_H_
#define BUTTON_H_

#define BUTPORT PORTD
#define BUTPIN PIND


#include "main.h"

enum button_state{
    RELEASED,
    PRESSED
    };


void buttons();
void buttons_init();
uint8_t debounce(uint8_t pin);
void edit_light();

extern volatile int light;

#endif /* BUTTON_H_ */
#ifndef BUTTON_H_
#define BUTTON_H_

#define BUTPORT PINC

#include "main.h"

enum button_state{
    RELEASED,
    PRESSED
    };

void Buttons_Handler();
void Buttons_init();
int Debounce(uint8_t pin);
void Edit_LCD_bright();

#endif /* BUTTON_H_ */
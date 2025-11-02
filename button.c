#include "button.h"

volatile int light = 75;

void buttons_init()
    {
        DDRC = 0b10000000;
        PORTC |= 0b11100000;
    }

void buttons()
    {

    // press button 1 (to PC6)
    if (debounce(6)){PORTC ^= (1<<7);} // invert pin sound


    // press button 2 (to PC5)
    if (debounce(5)){edit_light();} //

    // press button 3 (to PC4)
    //if (debounce(4)) { }

    // press button 4 (to PC3)
    //if (debounce(3)) { }


    }

void edit_light()
    {

    light = light + 25;   

        if (light >= 110)
        {
            light = 0;   

        }
 
    } 


uint32_t start_button[8] = {0}; // нулевые стартовые значения 

uint8_t debounce(uint8_t pin)
{
    if (!(BUTPIN & (1<< pin))) 
    {
        if (ms_cnt - start_button[pin] >= 20)
        {	

            if (!(BUTPIN & (1 << pin))) 
                {
                    start_button[pin] = ms_cnt;
                    return 1;

                }
            
        }     

    } 



return 0;

}



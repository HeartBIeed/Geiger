#ifndef UART_H_
#define UART_H_

#include "../main.h"

ISR(USART_RXC_vect);
void USART_ini(uint16_t speed);

volatile unsigned int received_byte = 0;
volatile unsigned int data_ready = 0;


#endif /* UART_H_ */
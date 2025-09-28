#ifndef LCD1602_H_
#define LCD1602_H_

#include "main.h"
#define E1 PORTA|=0x8 // E в 1 стробирующая шина
#define E0 PORTA&=0xF7 // E в 0
#define RS1 PORTA|=0x4 // RS в 1 (данные)
#define RS0 PORTA&=0xFB // RS в 0 (команда)

void LCD_ini_1602(void);
void send(unsigned char c,unsigned char mode); 
void setpos(unsigned char x, unsigned y); 
void send_ptr_str(char *str);
void sendchar(unsigned char c);

#endif /* LCD1602_H_ */

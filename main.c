#include "main.h"



int main(void)
{
	LCD_ini_1602();

	
//------------------PWM---------------------

		uint16_t top = freq(3000,8);
	pwm_init(top);//шим высоковольтного ненератора
		
		uint16_t dt1 = pwm_proc(50);
		set_duty(dt1,dt1);
		
	pwm_init_lcd(); //подсветка лсд
		OCR0 = pwm_proc(10); //10%

		




// ------------DHT11-----------------------

	char data[13] = "T:25°C H:60%";
//	dht_write_data(data);
	setpos(0,1);
	send_ptr_str(data);

while(1)
	{
		
	time_to_lcd();


	}
}
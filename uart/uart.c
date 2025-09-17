void USART_ini(uint16_t speed)
{
	UBRRH =(speed>>8);
	UBRRL = speed;

	UCSRB |= (1<<RXEN)|(1<<TXEN)|(1<<RXCIE); //RXCIE - innterr
	UCSRA |= (1<<U2X); // 8 MGc
	UCSRC |= (1<<URSEL)|(1<<USBS)|(1<<UCSZ1)|(1<<UCSZ0); //sel assync umsel non 2 uscz 11 - 8 bit
}

void USART_TX(unsigned int data)
{
	while (!(UCSRA&(1<<UDRE))); //проверяем в усра удре бит что он 0 ибо это готовность к записи
	
	UDR = data; // sendc data

}


volatile unsigned int received_byte = 0;
volatile unsigned int data_ready = 0;

ISR(USART_RXC_vect) {
	received_byte = UDR;  // сохраняем байт в глобальную переменную
	data_ready = 1;
}

void echo()
{
	USART_TX(received_byte);

}
int x = 0;

void UART_read_data(char* buffer,uint8_t len)
{
	int i = 0;

	while (i < len - 1)
	{
		if (data_ready == 1)
		{
			if (received_byte =='\n' || received_byte =='\r'){break;}
			
			buffer[i] = received_byte;
			i++;
			data_ready = 0;
		}
		

	}
	
	buffer[i] = '\0';
}


char UART_wait()
{
	unsigned char array[10];
	unsigned char string[10];
	
	if (data_ready == 1)
	{
		string[10] = UART_read_data(array[],10);
		
	}
	return array[];
}



void lcd_out(char s)
{
	int y = 0;
	
	setpos(x,y);
	sendchar(s);
	x = x+1;
	if (x > 16)
	{x = 0;
	}
	//	char mystr[] = "Hello World!";
	//	send_ptr_str(mystr); //отправка массива
}
*/
	
	sei();
	USART_init(103);
	USART_TX('U');


	while(1)
	{
		if (data_ready ==1)
		{
			lcd_out(received_byte);
			echo();
			data_ready =0;
		}
		
	}

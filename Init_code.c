/*
 * Init_code.c
 *
 * Created: 12-04-2016 17:59:55
 *  Author: sripals
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD    = 0x01;
	PORTD   = 0x00;
	
    while(1)
    {
        PORTD   = ~ PORTD;
		_delay_ms(1000);
		
    }
}
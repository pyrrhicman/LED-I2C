/*
 * Created: 4/16/2018 4:48:39 PM
 * Author : Mohammad
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <D:\GitHub\LED-I2C\LED-I2C Lib\i2c_master.c>

char data_received;
int main(void)
{
	i2c_init();
	DDRA = 0;
	DDRB = 0;
    /* Replace with your application code */
    while (1) 
    {
		while(PINB ==1){
		char key = 0x2f;
		i2c_start(0x10<<1 | I2C_WRITE);
		i2c_write(PINA);
		i2c_stop();
		_delay_ms(10);
		i2c_start(0x10<<1 | I2C_READ);
		data_received = i2c_read_ack();
		i2c_read_nack();
		i2c_stop();
		}
    }
}


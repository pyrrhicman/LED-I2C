/*
 * Created: 4/16/2018 4:48:39 PM
 * Author : Mohammad
 */ 

#define F_CPU 8000000UL
#define _LCD_LIB_

#include <avr/io.h>
#include <util/delay.h>
#include <D:\GitHub\LED-I2C\LED-I2C Lib\i2c_master.c>
#include <D:\GitHub\LCD-Lib-Cplusplus\LIB\CharacterLCD.h>
#include <D:\GitHub\LCD-Lib-Cplusplus\LIB\CharacterLCD.cpp>
char data_received;

Character_LCD LCD1;

int main(void)
{
	i2c_init();
	DDRA = 0;
	DDRB = 0;
			LCD1.SetRSPin (ADD(PORTD),ADD(DDRD),0);
			LCD1.SetRWPin (ADD(PORTD),ADD(DDRD),1);
			LCD1.SetEPin  (ADD(PORTD),ADD(DDRD),2);
			LCD1.SetD4Pin (ADD(PORTD),ADD(DDRD),3);
			LCD1.SetD5Pin (ADD(PORTD),ADD(DDRD),4);
			LCD1.SetD6Pin (ADD(PORTD),ADD(DDRD),5);
			LCD1.SetD7Pin (ADD(PORTD),ADD(DDRD),6);
			LCD1.Init(16,2);

	
    /* Replace with your application code */
    while (1) 
    {
		
		LCD1.Clr();
		LCD1.Printf("test",0,0);
		while(PINB ==1){
		char key = 0x2f;
		i2c_start(0x10<<1 | I2C_WRITE);
		i2c_write(PINA);
		i2c_stop();
		_delay_ms(10);
		i2c_start(0x10<<1 | I2C_READ);
		data_received = i2c_read_ack();
		LCD1.Clr();
		LCD1.SendChar(data_received);
		LCD1.SendChar(PINA);
		i2c_read_nack();
		i2c_stop();
		_delay_ms(100);
		}
    }
}


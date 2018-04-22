/*
 * Created: 4/16/2018 4:48:39 PM
 * Author : Mohammad
 */ 

#define F_CPU 8000000UL
#define _LCD_LIB_

#include <stdio.h>
#include <string.h>

#include <avr/io.h>
#include <util/delay.h>
#include <D:\GitHub\LED-I2C\LED-I2C Lib\i2c_master.c>
#include <D:\GitHub\LCD-Lib-Cplusplus\LIB\CharacterLCD.h>
#include <D:\GitHub\LCD-Lib-Cplusplus\LIB\CharacterLCD.cpp>
char data_received;
Character_LCD LCD1;
#define SLAVE_1_ADRR 0b00000010
#define SLAVE_2_ADRR 0b00000100
#define SLAVE_3_ADRR 0b00001000
#define SLAVE_4_ADRR 0b00010000
int main(void)
{
	LCD1.SetRSPin (ADD(PORTD),ADD(DDRD),0);
	LCD1.SetRWPin (ADD(PORTD),ADD(DDRD),1);
	LCD1.SetEPin  (ADD(PORTD),ADD(DDRD),2);
	LCD1.SetD4Pin (ADD(PORTD),ADD(DDRD),3);
	LCD1.SetD5Pin (ADD(PORTD),ADD(DDRD),4);
	LCD1.SetD6Pin (ADD(PORTD),ADD(DDRD),5);
	LCD1.SetD7Pin (ADD(PORTD),ADD(DDRD),6);
	LCD1.Init(16,2);
	
	i2c_init();
	LCD1.SendString("TWBR :");
	LCD1.INTNumber((int)TWBR);
	LCD1.GotoXY(1,1);
	LCD1.SendString(" TWPS :");
	
	LCD1.INTNumber((int)TWSR & 0x03);
	_delay_ms(1000);
	
	DDRA = 0;
	DDRB = 0;
			
	unsigned char ADDRESS;
    /* Replace with your application code */
    while (1) 
    {
		
		//LCD1.Clr();
		//LCD1.Printf("test",0,0);
		while((PINB & 0x01) ==1){
		LCD1.Clr();
		
		
		ADDRESS = PINB & 0b11111110;
		LCD1.SendString("PORT is : ");
		LCD1.INTNumber((int)PINA);	
		LCD1.SendString("ADDRESS : ",1,1);
		LCD1.INTNumber((int)ADDRESS);
		i2c_start(ADDRESS <<1 | I2C_WRITE);
		i2c_write(PINA);
		i2c_stop();
		_delay_ms(1000);
		
		
		
		/*
		i2c_start(0x10<<1 | I2C_READ);
		data_received = i2c_read_ack();
		LCD1.Clr();
		LCD1.SendChar(data_received);
		LCD1.SendChar(PINA);
		i2c_read_nack();
		i2c_stop();
		_delay_ms(2000);
		*/
		}
    }
}


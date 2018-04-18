/*
 * LED-I2C-Slave 2 C++.cpp
 *
 * Created: 4/16/2018 10:37:25 PM
 * Author : Mohammad
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <D:\GitHub\LED-I2C\LED-I2C Lib\I2CSlave.c>
volatile uint8_t i2c_RX_buff, i2c_TX_buff;
volatile unsigned char RX_point=0, TX_point=0;
volatile bool i2c_packet_reveived=false;

#define I2C_ADDR 0b00000100
volatile uint8_t data;

void I2C_received(uint8_t received_data){
	data = received_data;
	PORTA = data;
}
void I2C_requested(){
	I2C_transmitByte(data);
}

void setup(){
	I2C_setCallbacks(I2C_received,I2C_requested);
	I2C_init(I2C_ADDR);
}
int main(void)
{
	DDRA =255;
	setup();
	
    /* Replace with your application code */
    while (1) 
    {
		_delay_ms(2000);
		PORTA = 0;
    }
}


/*
 * DC_Motor.c
 *
 * Created: 28/01/2021 07:52:53 ص
 *  Author: Smart
 */ 
#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include "DIO.h"
#include "LCD.h"


void DC_Motor_Init(){
      
      DDRC |=(1<<4)|(1<<3) ;   // H_BREDGE
      DDRD |=(1<<PD5);
   	/*set fast PWM mode with non-inverted output*/
   	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS00);
   	DDRB|=(1<<PB3);  /*set OC0 pin as output*/
    OCR0=254;
}

void DC_Motor_Run(){
		
		PORTC |=(1<<3);
		PORTC &=~(1<<4);
		LCD_SendString("Motor Start");
		_delay_ms(100);
		LCD_Clear();
		
	
}
void DC_Motor_Stop(){
	
	PORTC &=~(1<<3);
	PORTC &=~(1<<4);
}



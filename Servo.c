/*
 * Servo.c
 *
 * Created: 28/01/2021 07:51:19 ص
 *  Author: Smart
 */ 

#include "servo.h"



void Servo_Init(){
	
	DDRC |=(1<<4)|(1<<3) ;   // H_BREDGE
	DDRD |=(1<<PD5);
	ICR1 =4999;
	TCCR1A = ((1<<COM1A1)|(1<<WGM11)); //(1<<COM1A1)Clear OC1A/OC1B on compare match, set OC1A/OC1B at BOTTOM,(non-inverting mode)
	TCCR1B = ((1<<WGM12)|(1<<WGM13)|(1<<CS11)|(1<<CS10));            //FPWM_Mode (14);   (1<<WGM12) to using mode Fast PWM, 8-bit   &(1<<CS11)|(1<<CS10) for prescaling N=64
	OCR1A =191;
	
}
void Servo_Run(){
	Sevo_angle(0);
	_delay_ms(1000);
	
		
}
void Servo_Back(){
	Sevo_angle(120);
	_delay_ms(1000);
    
}

void Sevo_angle(unsigned short angle){
	OCR1A = (((maxcount-minicount)*(angle - miniangle)) / (maxangle-miniangle))+(minicount - 1) ;
}
/*
 * ADC.c
 *
 * Created: 21/01/2021 06:56:25 ص
 *  Author: Smart
 */ 
#include "ADC.h"

void ADC_Init(){
	ADMUX =(1<<REFS0)|(1<<REFS1);
	ADCSRA = (1 << ADEN)|( 1<< ADPS2)|(1 << ADPS1)|(1 << ADPS0) ;
	
}
unsigned short ADC_Read(unsigned channel){
	unsigned short data =0;
	ADMUX |= (ADMUX & 0b11100000) | (channel & 0b00011111); //to choose the channel 
	ADCSRA |=(1<<ADSC); //to start conversion 
	while(((ADCSRA>>ADIF)& 1)==0);     //using to do conversion it completed
	//while(!((ADCSRA>>ADIF)&1)); the same as above condation
	ADCSRA |=(1<<ADIF);     //this condition to clear flag
	data = ADCL ;
	data |= (ADCH << 8);
	
	return data;
	
}
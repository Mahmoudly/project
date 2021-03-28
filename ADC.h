/*
 * ADC.h
 *
 * Created: 21/01/2021 06:56:42 ص
 *  Author: Smart
 */ 


#ifndef ADC_H_
#define ADC_H_
#include <avr/io.h>

void ADC_Init();
unsigned short ADC_Read(unsigned channel);


#endif /* ADC_H_ */
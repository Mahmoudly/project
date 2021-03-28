/*
* UART.h
*
* Created: 24/01/2021 04:21:32 م
*  Author: Smart
*/


#ifndef UART_H_
#define UART_H_
#include <avr/io.h>
#define F_CPU 16000000UL

#define BaodRate 9600          //Internal Clock Generation – The Baud Rate Generato


#define DoupleSpeed 0    // Table 68. Examples of UBRR Settings for Commonly Used Oscillator Frequencies //U2X = 1

#if (DoupleSpeed == 0)
#define MyUBRR ((F_CPU/(16UL*BaodRate))-1)  //Asynchronous Normal Mode (U2X = 0) &UL it is important to be find casting 

#else

#define MyUBRR ((F_CPU/(8UL*BaodRate))-1) //Asynchronous Double Speed Mode (U2X = 1)
#endif

void Uart_Init();
void Uart_TxChar(char data);
char Uart_RxChar ();
void Uart_TxString(char * string);




#endif /* UART_H_ */
/*
* Master_Amit.c
*
* Created: 29/01/2021 05:50:03 م
* Author : Smart
*/
#include "SPI.h"
#define F_CPU 16000000UL
#include "util/delay.h"
#include "DIO.h"

#include "LCD.h"
#include "UART.h"
#include "stdlib.h" //using to convert from int to char

char string[50];
int shift ;
int main(void)
{
	char string[50];
	DIO_Init();
	LCD_Init();
	
	Uart_Init();
	SPI_InitType InitData ={Master,MSB};
	SPI_Init(&InitData);
	Slave_EN();
	unsigned char data=0;
	int i ;
	
	
	while (1)
	{
		
		
		
		data=SPI_TxRx(0xAA);
		itoa(data ,string,10);
		LCD_SendString(string);
		_delay_ms(100);
		LCD_Clear();
		
		
	    
		Uart_TxString("temp=");
		Uart_TxString(string);
		Uart_TxString("\r\n");
		_delay_ms(100);
		
			//LCD_SendString(string);
		//	_delay_ms(100);
		//	LCD_Clear();
			//	_delay_ms(500);
		//}
		
		
		
		
	}
	
}
//لازم نظبط ال انابل والدس ابل عشان يظبط معايا في الارسال والاستقبال وميطلعش ايرور في عملية الشفتنج

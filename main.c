/*
* ADC.c
*
* Created: 21/01/2021 06:54:29 ص
* Author : Smart
*/
#include "stdlib.h" //using to convert from int to char
#include "DIO.h"
#include "LCD.h"
#include "ADC.h"
#include "SPI.h"
#include "servo.h"
#include "DC_Motor.h"
#include "SPI.h"


int main(void)
{
	unsigned char data =0;     //value that return from ADC
	unsigned short temp =0;
	char string[50];            // using to convert from int to char
	DIO_Init();
	ADC_Init();
	LCD_Init();
	Servo_Init();
	DC_Motor_Init();
	SPI_Init(salve);
	
	int angle =0;
	int i=0;
	while (1)
	{
	   
		temp=(ADC_Read(1)/4.2);
		//_delay_ms(100);
		SPI_TxRx(temp);
	     itoa(temp ,string,10);
		LCD_SendString(string);      //notes if we not using delay prefct in lcd we find problem in screen lcd
		_delay_ms(20);
		LCD_Clear();
	
		
		
		
		
		if ((ADC_Read(1)/4.2)>=33)
		{   if ((angle<90))
			{
				Servo_Run();
				angle =90;
				
			}
			
			DC_Motor_Run();
			
		}
		else{
			
			Servo_Back();
			DC_Motor_Stop();
			angle=0;
		}
		
	}
}


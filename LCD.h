/*
 * LCD.h
 *
 * Created: 17/01/2021 03:37:33 م
 *  Author: Smart
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "DIO.h"
#define F_CPU 16000000UL
#include <util/delay.h>

#define LCDDataPort PORTA_Reg
#define RS DIO_ChannelB1
#define Rw DIO_ChannelB2
#define E DIO_ChannelC0

void LCD_Init(void);
void LCD_Cmd(Unit8 cmd);
void LCD_SendChar(Unit8 data);
void LCD_SendString(Unit8*string);
void LCD_SendStringPos(Unit8 * string,Unit8 line ,Unit8 pos);
void LCD_Custom_Char (Unit8 loc, Unit8 *msg);
void LCD_Clear();
#endif /* LCD_H_ */
  
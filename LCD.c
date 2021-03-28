/*
 * LCD.c
 *
 * Created: 17/01/2021 03:36:57 م
 *  Author: Smart
 */ 


#include "LCD.h"

void LCD_Init(void)
{
    _delay_ms(20);
	DIO_WriteChannel(Rw,STD_Low);
	LCD_Cmd(0x33);                //the frist term from data from data sheet
	_delay_ms(150);              
	LCD_Cmd(0x32);              //the seconde term from data from data sheet
	LCD_Cmd(0x28);              //set function to choose the line and mod bit 
	LCD_Cmd(0x06);              //entiry mode to choose how cursor moving and how move character 
	LCD_Cmd(0x0C);              // display on/off lcd and on/off cursor and blinking cursor 
	LCD_Cmd(0x01);              //clear lcd to protect it from error in data 
	_delay_ms(2);               //delay to protect it from ovarlap data
}
void LCD_Cmd(Unit8 cmd){
	LCDDataPort = ((LCDDataPort & 0x0F) | (cmd & 0xF0));
	DIO_WriteChannel(RS,STD_Low);
	DIO_WriteChannel(E,STD_Low);
	_delay_us(100);
	DIO_WriteChannel(E,STD_High);
	_delay_ms(3);
	
	LCDDataPort = ((LCDDataPort & 0x0F) | (cmd << 4));
	DIO_WriteChannel(RS,STD_Low);
	DIO_WriteChannel(E,STD_Low);
	_delay_us(100);
	DIO_WriteChannel(E,STD_High);
		_delay_ms(2);                 //we can neglated her and using it _delay_us(150) in above   
}
void LCD_SendChar(Unit8 data){
	LCDDataPort = (LCDDataPort & 0x0F) | (data & 0xF0);
	DIO_WriteChannel(RS,STD_High);
	DIO_WriteChannel(E,STD_Low);
	_delay_us(100);
	DIO_WriteChannel(E,STD_High);
	_delay_ms(2);
	
	LCDDataPort = (LCDDataPort & 0x0F) | (data << 4);
	DIO_WriteChannel(RS,STD_High);
	DIO_WriteChannel(E,STD_Low);
	_delay_us(100);
	DIO_WriteChannel(E,STD_High);
	_delay_ms(2);
}
const int i=0;
void LCD_SendString(Unit8 * string){
	Unit8 i=0;
	while(string[i] != '\0'){
		LCD_SendChar(string[i]);
		i++ ;
	}
	
}
 void LCD_SendStringPos(Unit8 * string,Unit8 line ,Unit8 pos){
	 switch(line)
	 {
		 case 1:
		 LCD_Cmd((0x80 |(pos & 0x0F)));
		 LCD_SendString(string);
		 break;
		 case 2:
		 LCD_Cmd((0xC0 |(pos & 0x0F)));
		 LCD_SendString(string);
		 break;
	 }
 } 
void LCD_Custom_Char (Unit8 loc, Unit8 *msg)
{
    unsigned char i;
    if(loc<8)
    {
     LCD_Cmd (0x40 + (loc*8));  /* Command 0x40 and onwards forces           
                                       the device to point CGRAM address */
       for(i=0;i<8;i++)  /* Write 8 byte for generation of 1 character */       //LCD هنا تم استخدام الريجستر الخاص بمجموعة  تخزين داخل 
           LCD_SendChar(msg[i]);      
    }   
}
void LCD_Clear(){
	LCD_Cmd(0x01);
}

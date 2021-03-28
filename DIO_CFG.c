/*
* DIO_CFG.c
*
* Created: 16/01/2021 05:45:44 م
*  Author: Smart
*/
#include "DIO_CFG.h"
#include "DIO_HW.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_TYPES.h"
const DIO_Pin_CFGType PinCFG[]={
	//PORTA
	{Input,STD_Low},
	{Input,STD_Low},   //for the ADC it is input 
	{Input,STD_Low},
	{Input,STD_Low},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	//PORTB
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	//PORTC
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	//PORTD
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	
};

void DIO_Init(){
	DIO_PortTypes Portx ;
	DIO_ChannelTypes ChannelPos ;
	Unit8 Count =0;
	for(Count=DIO_ChannelA0 ;Count<PINCOUNT;Count++)
	{
		Portx =Count/8;
		ChannelPos =Count%8;
		switch(Portx){
			case DIO_PortA:
			if(PinCFG[Count].level==Output)
			{
				SetBit(DDRA_Reg,ChannelPos);
			}
			else{
				ClearBit(DDRA_Reg,ChannelPos);
			}
			break;
			case DIO_PortB:
			if(PinCFG[Count].level==Output)
			{
				SetBit(DDRB_Reg,ChannelPos);
			}
			else{
				ClearBit(DDRB_Reg,ChannelPos);
			}
			break;
			case DIO_PortC:
			if(PinCFG[Count].level==Output)
			{
				SetBit(DDRC_Reg,ChannelPos);
			}
			else{
				ClearBit(DDRC_Reg,ChannelPos);
			}
			break;
			case DIO_PortD:
			if(PinCFG[Count].level==Output)
			{
				SetBit(DDRD_Reg,ChannelPos);
			}
			else{
				ClearBit(DDRD_Reg,ChannelPos);
			}
			break;
		}
	}
	
}

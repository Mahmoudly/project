﻿/*
 * DIO.c
 *
 * Created: 16/01/2021 05:45:26 م
 *  Author: Smart
 */ 



#include "DIO.h"

void DIO_WriteChannel(DIO_ChannelTypes ChannelId , STD_LevelTypes level){
	DIO_PortTypes Portx = (ChannelId/8);
	DIO_ChannelTypes ChannelPos = (ChannelId%8);
	switch(Portx){
		case DIO_PortA:
		if(level==STD_High){
			SetBit(PORTA_Reg,ChannelPos);
		}
		else{
			ClearBit(PORTA_Reg,ChannelPos);
		}
		
		  break ;
		
		case DIO_PortB:
		
		if(level==STD_High){
			SetBit(PORTB_Reg,ChannelPos);
		}
		else{
			ClearBit(PORTB_Reg,ChannelPos);
		}
		
		
		break ;
		case DIO_PortC:
		if(level==STD_High){
			SetBit(PORTC_Reg,ChannelPos);
		}
		else{
			ClearBit(PORTC_Reg,ChannelPos);
		}
		
		
		break ;
		case DIO_PortD:
		if(level==STD_High){
			SetBit(PORTD_Reg,ChannelPos);
		}
		else{
		       ClearBit(PORTD_Reg,ChannelPos);
		}
		
		
		break ; 
	}
	
}
 
  STD_LevelTypes DIO_ReadChannel (DIO_ChannelTypes ChannelId)
  {
	  DIO_PortTypes Portx = (ChannelId/8);
	  DIO_ChannelTypes ChannelPos = (ChannelId%8);
	  STD_LevelTypes level =STD_Low;
	  switch(Portx){
		  case DIO_PortA:
		  level= GetBit(PINA_Reg,ChannelPos);
	  
	  break;
	    case DIO_PortB:
	    level= GetBit(PINB_Reg,ChannelPos);
	    
	    break;
		  case DIO_PortC:
		  level= GetBit(PINC_Reg,ChannelPos);
		  
		  break;
		    case DIO_PortD:
		    level= GetBit(PIND_Reg,ChannelPos);
		    
		    break;
	  }
	  return level ;
  }
  
/*
 * SPI1.c
 *
 * Created: 25/01/2021 07:35:06 م
 *  Author: Smart
 */ 

#include "SPI.h"


void SPI_Init(SPI_StatusTypes status){
	switch (status){
		
		case Master:
		DDRB |= ((1<<SCK)|(1<<MOSI)|(1<<ss));
		DDRB &=~ (1<<MISO);
		SPCR |= ((1<<SPE)|(1<<MSTR));          //  (1<<SPE) This bit must be set to enable any SPI operations.&Bit 4 – MSTR: Master/Slave Select
		
		
		
		break;
		
		case salve:
		DDRB |= ((1<<MISO));
		DDRB &=~ ((1<<SCK)|(1<<MOSI)|(1<<ss));
		SPCR |= (1<<SPE) ;
		
		
		break;
	}
	
}

unsigned char SPI_TxRx(unsigned char data){
	SPDR =data;                         //Transmit operation 
	while(!((SPSR>>SPIF)&1));          //   Bit 7 – SPIF: SPI Interrupt Flag this flag mutual between receive and transmit 
	return SPDR   ;                    //SPI Data Register – this recieve value 
}


//  هنا يستخدم الميكروكنترول نظام يعني العنوان الصغير يتخزن في اول بايت  (littl indain )

//we can using way of UNION with all register her 
/*
 * SPI1.c
 *
 * Created: 25/01/2021 07:35:06 م
 *  Author: Smart
 */ 

#include "SPI.h"


void SPI_Init(SPI_InitType * InitData){
	switch (InitData->status){                                 //if we not using SPI_INitType we using the Status instead of InitData->status
		
		case Master:
		DDRB |= ((1<<SCK)|(1<<MOSI)|(1<<ss));
		DDRB &=~ (1<<MISO);
		Slave_DIS();
		//SPCR |= ((1<<SPE)|(1<<MSTR));          //  (1<<SPE) This bit must be set to enable any SPI operations.&Bit 4 – MSTR: Master/Slave Select
		//SPI->SPI_SPCR=((1<<SPE)|(1<<MSTR));     // to acsecs the data in struct using with type struct 
		/*{SPI->SPI_SPCR.SMSTR=1;    //if we using typedef of SPI_SPCRType we using it instead of SPI->SPI_SPCR=((1<<SPE)|(1<<MSTR));and SPCR |= ((1<<SPE)|(1<<MSTR));
		SPI->SPI_SPCR.SSPIE =1;}*/
		 SPI->SPI_SPCR.AllReg = 0x10;               //using with Typedef union to access register all bit it is the same as SPI->SPI_SPCR=((1<<MSTR));
		 SPI->SPI_SPCR.Bits.SSPE =1;           //her we can access bit by bit in register her we set bit enable  
		
		
		break;
		
		case salve:
		DDRB |= ((1<<MISO));
		DDRB &=~ ((1<<SCK)|(1<<MOSI)|(1<<ss));
		SPCR |= (1<<SPE);
		
		
		break;
	}
	
}

unsigned char SPI_TxRx(unsigned char data){
	SPDR =data;                         //Transmit operation 
	//while(!((SPSR>>SPIF)&1));          //   Bit 7 – SPIF: SPI Interrupt Flag this flag mutual between receive and transmit 
	while(SPI->SPI_SPSR.SSPIF ==0);     //we using with typedef SPI_SPSR instead of while(!((SPSR>>SPIF)&1));
	
	return SPDR  ;                     //SPI Data Register – this recieve value 
}
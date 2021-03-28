/*
* SPI.h
*
* Created: 25/01/2021 07:35:31 م
*  Author: Smart
*/


#ifndef SPI_H_
#define SPI_H_

#include "avr/io.h"
#define ss 4
#define MOSI 5
#define MISO 6                //MOSI &MISO it is pin using output or input data change 0 1 from master to salve 
#define SCK 7

#define Slave_EN() (PORTB &=~ (1<<ss))
#define Slave_DIS() (PORTC |=(1<<ss))   //because if we using more than one device to control Salve device is work 

typedef enum{
	Master =0,
	salve
}SPI_StatusTypes;

typedef enum{
	   MSB=0,
	   LSB
}SPI_DORDTypes;
typedef struct{
	unsigned char SSPI2X:1;
	unsigned char RES0:1;
	unsigned char RES1:1;
	unsigned char RES2:1;        // SPI Control regesiter bits we give it number of bit
	unsigned char RES3:1;
	unsigned char RES4:1;
	unsigned char SWCOL:1;
	unsigned char SSPIF:1;
}SPI_SPSRBits;


typedef struct{
	unsigned char SSPR:2;
	unsigned char SCPHA:1;
	unsigned char SCPOL:1;
	unsigned char SMSTR:1;        // SPI Status  regesiter bits we give it number of bit 
	unsigned char SDORD:1;
	unsigned char SSPE:1;
	unsigned char SSPIE:1;
	}SPI_SPCRBits;
	typedef union{
		SPI_SPCRBits Bits;
		unsigned char AllReg;
		}SPI_SPCRTypes;

typedef struct{
	 SPI_SPCRTypes SPI_SPCR;
	SPI_SPSRBits SPI_SPSR;           // data type is typedef from struct
	unsigned char SPI_SPDR;
	}SPI_RegTypes;
#define SPI ((volatile SPI_RegTypes *)0x2D) //we using pointet to pointe to typdef all element in structur 
typedef struct{
       SPI_StatusTypes status;
	   SPI_DORDTypes DataOrder 	;
	
	}SPI_InitType;
	
//void SPI_Init(SPI_StatusTypes status);    //if we not using the SPI_InitType
   void SPI_Init(SPI_InitType * InitData);

unsigned char SPI_TxRx(unsigned char data);  //Because the SPI TRANSSMIT AND RECIVE AT A TIME



#endif /* SPI_H_ */
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

typedef enum{
	Master =0,
	salve
}SPI_StatusTypes;

void SPI_Init(SPI_StatusTypes status);

unsigned char SPI_TxRx(unsigned char data);  //Because the SPI TRANSSMIT AND RECIVE AT A TIME



#endif /* SPI_H_ */
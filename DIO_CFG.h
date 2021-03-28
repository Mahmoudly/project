/*
 * DIO_CFG.h
 *
 * Created: 16/01/2021 05:45:11 م
 *  Author: Smart
 */ 


#ifndef DIO_CFG_H_
#define DIO_CFG_H_
#include "DIO_HW.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_TYPES.h"
 
 typedef struct{
	 DIO_DirTypes PinDir ;
	 STD_LevelTypes level ;
	 
	 }DIO_Pin_CFGType;
#define PINCOUNT 32
void DIO_Init(void);


#endif /* DIO_CFG_H_ */
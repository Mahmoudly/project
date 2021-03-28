/*
 * DIO.h
 *
 * Created: 16/01/2021 05:44:39 م
 *  Author: Smart
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "DIO_HW.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_TYPES.h"
#include "DIO_CFG.h"
void DIO_WriteChannel(DIO_ChannelTypes ChannelId ,STD_LevelTypes level);
STD_LevelTypes DIO_ReadChannel (DIO_ChannelTypes ChannelId);


 

#endif /* DIO_H_ */
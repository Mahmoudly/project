/*
 * DIO_HW.h
 *
 * Created: 16/01/2021 04:27:01 م
 *  Author: Smart
 */ 


#ifndef DIO_HW_H_
#define DIO_HW_H_
#include "STD_TYPES.h"

#define PORTA_Reg (*((volatile Unit8 *)0x3B))
#define DDRA_Reg (*((volatile Unit8 *)0x3A))
#define PINA_Reg (*((volatile Unit8 *)0x39))


#define PORTB_Reg (*((volatile Unit8 *)0x38))
#define DDRB_Reg (*((volatile Unit8 *)0x37))
#define PINB_Reg (*((volatile Unit8 *)0x36))


#define PORTC_Reg (*((volatile Unit8 *)0x35))
#define DDRC_Reg (*((volatile Unit8 *)0x34))
#define PINC_Reg (*((volatile Unit8 *)0x33))


#define PORTD_Reg (*((volatile Unit8 *)0x32))
#define DDRD_Reg (*((volatile Unit8 *)0x31))
#define PIND_Reg (*((volatile Unit8 *)0x30))
 
 
 #define TCCR1A_Reg (*((volatile Unit8 *)0x4F))
 #define TCCR1B_Reg (*((volatile Unit8 *)0x4E))
 #define OCR1AL_Reg (*((volatile Unit8 *)0x4A))
 #define OCR1AH_Reg (*((volatile Unit8 *)0x4B))
#define  OCR1A_Reg (*((volatile Unit8 *)0x4B))

#define ICR1L_Reg (*((volatile Unit8 *)0x46))
#define ICR1H_Reg (*((volatile Unit8 *)0x47))
#define  ICR1_Reg (*((volatile Unit8 *)0x46))


#endif /* DIO_HW_H_ */
/*
 * servo.h
 *
 * Created: 28/01/2021 07:51:49 ص
 *  Author: Smart
 */ 


#ifndef SERVO_H_
#define SERVO_H_

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#define miniangle 0
#define maxangle 180
#define minicount 250
#define maxcount 500


void Servo_Init();
void Servo_Run();
void Servo_Back();
void Sevo_angle(unsigned short angle);




#endif /* SERVO_H_ */




/*
 * BIT_MATH.h
 *
 * Created: 16/01/2021 04:25:43 م
 *  Author: Smart
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SetBit(Reg,BitNo) (Reg |= (1<<BitNo))
#define ClearBit(Reg,BitNo) (Reg &=~ (1<<BitNo))
#define ToggleBit(Reg,BitNo) (Reg ^= (1<<BitNo))
#define GetBit(Reg,BitNo) ((Reg>>BitNo)&1)
#endif /* BIT_MATH_H_ */
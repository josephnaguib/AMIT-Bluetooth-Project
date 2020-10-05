/*
* bit_math.h
*
* Created: 5/20/2020 11:12:39 AM
*  Author: mnaguib
*/


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define setBit(REG,BIT)    REG |= (1<<(BIT))
#define clearBit(REG,BIT)  REG &=~(1<<(BIT))
#define togglebit(REG,BIT) REG ^= ((1<<(BIT)))

#define setBits(REG,MASK)    REG |= (MASK)
#define clearBits(REG,MASK)  REG &=~(MASK)
#define togglebits(REG,MASK) REG ^= (MASK)

#define setALLBits(REG)    REG = (0xFF)
#define clearALLBits(REG)  REG =(0x00)
#define toggleALLbits(REG) REG ^=(0xFF)

#define readBit(REG,BIT)   ((REG>>(BIT))&(0x01))


#endif /* BIT_MATH_H_ */
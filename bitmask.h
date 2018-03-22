#ifndef BITMASK_H
#define BITMASK_H

#include <defines.h>

class BitMask
{
    __uint64 remainder;
    __uint64 quotient;
public:    
    __uint8 *setValueToVec(__uint8 *vec, __uint64 bitNum, bool value);
    __uint64 static delBit(__uint64 a, __uint64 b, __uint8 bitNum);
    __uint64 static getBitMask1(__uint8 bitNum);
    BitMask();
private:    
    __uint8 getBitMask0(__uint8 bitNum);    
    void setInd(__uint64 ind);
};

#endif // BITMASK_H

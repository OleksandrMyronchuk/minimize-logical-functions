#include "bitmask.h"
#include <cstdlib>
#include <cstring>

#include <bitset>
#include <iostream>

__uint8 *BitMask::setValueToVec(__uint8 *vec, __uint64 bitNum, bool value)
{
    this->setInd(bitNum);
    if (bitNum == 0)
    {
        vec = (__uint8*)malloc(1);
        vec[0] = 0;
        vec[1] = '\0';       
    }
    else if (this->remainder == 0)
    {
        vec = (__uint8*)realloc(vec, this->quotient + 1);
        vec[this->quotient + 1] = '\0';
    }
    if (!value) return vec;
    vec[this->quotient] = vec[this->quotient] ^ this->getBitMask0(this->remainder);
    return vec;
}

BitMask::BitMask()
{

}

__uint8 BitMask::getBitMask0(__uint8 bitNum)
{
    __uint8 sequence[] = {1, 2, 4, 8, 16, 32, 64, 128};
    return sequence[bitNum];
}

__uint64 BitMask::getBitMask1(__uint8 bitNum)
{
    /*
    00000001
    00000011
    ...
    11111111
    */
    __uint64 sequence[] = {
        0x1,
        0x3,
        0x7,
        0xf,
        0x1f,
        0x3f,
        0x7f,
        0xff,
        0x1ff,
        0x3ff,
        0x7ff,
        0xfff,
        0x1fff,
        0x3fff,
        0x7fff,
        0xffff,
        0x1ffff,
        0x3ffff,
        0x7ffff,
        0xfffff,
        0x1fffff,
        0x3fffff,
        0x7fffff,
        0xffffff,
        0x1ffffff,
        0x3ffffff,
        0x7ffffff,
        0xfffffff,
        0x1fffffff,
        0x3fffffff,
        0x7fffffff,
        0xffffffff,
        0x1ffffffff,
        0x3ffffffff,
        0x7ffffffff,
        0xfffffffff,
        0x1fffffffff,
        0x3fffffffff,
        0x7fffffffff,
        0xffffffffff,
        0x1ffffffffff,
        0x3ffffffffff,
        0x7ffffffffff,
        0xfffffffffff,
        0x1fffffffffff,
        0x3fffffffffff,
        0x7fffffffffff,
        0xffffffffffff,
        0x1ffffffffffff,
        0x3ffffffffffff,
        0x7ffffffffffff,
        0xfffffffffffff,
        0x1fffffffffffff,
        0x3fffffffffffff,
        0x7fffffffffffff,
        0xffffffffffffff,
        0x1ffffffffffffff,
        0x3ffffffffffffff,
        0x7ffffffffffffff,
        0xfffffffffffffff,
        0x1fffffffffffffff,
        0x3fffffffffffffff,
        0x7fffffffffffffff,
        0xffffffffffffffff
    };

    return sequence[bitNum];

}

__uint64 BitMask::delBit(__uint64 a, __uint64 b, __uint8 bitNum)
{
    a |= BitMask::getBitMask1(bitNum);
    a = a >> 1;
    b |= (BitMask::getBitMask1(63)<<bitNum);
    return a & b;
}

void BitMask::setInd(__uint64 ind)
{
    this->remainder = ind % 8;
    this->quotient = ind / 8;
}

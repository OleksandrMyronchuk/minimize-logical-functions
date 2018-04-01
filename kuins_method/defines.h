#ifndef DEFINES_H
#define DEFINES_H
#include "global.h"

namespace nsKuainRule {

#define __uint64 unsigned long long
#define __uint8 unsigned char

#define boolToStr(a) a ? "true" : "false"

#define eraseLastComma( str ) do { \
    if(',' == str.at(str.length() - 1)) \
        str.erase( str.length() - 1 ); \
    } while( false )

}

#endif // DEFINES_H

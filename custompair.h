#ifndef CUSTOMPAIR_H
#define CUSTOMPAIR_H

template<class _T1, class _T2>
struct customPair
{
    _T1 first;
    _T1 second;

    customPair(){}
    customPair(_T1 firstValue) : first(firstValue){}
    customPair(_T1 firstValue, _T2 secondValue) : first(firstValue), second(secondValue){}

    inline bool operator==( customPair &other)
    {
        return this->first < other.first;
    }
    inline bool operator<( customPair &other)
    {
        return this->first < other.first;
    }
    inline bool operator>( customPair &other)
    {
        return this->first > other.first;
    }
};

#endif // CUSTOMPAIR_H

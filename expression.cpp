#include "expression.h"

#include <vector>
#include <iostream>
#include <bitset>
#include <cmath>
#include <exception>
#include <minijson_writer.hpp>
#include <typeinfo>

/**** CONSTRUCTOR & DESTRUCTOR ****/
Expression::Expression() : _shortenedVars(0){}
Expression::~Expression(){}

/**** OVERRIDE FUNCTIONS ****/
std::string Expression::print() const
{
    std::string data;

    bool entry(false);
    data += "{\"expr\":[";
    __uint8 expressionSize = Expression::getVarSize();
    for(__uint8 i(0); i < expressionSize; i++)
    {
        if( compareBits(0xffffffffffffffffull, ~this->_shortenedVars, i) )
        {
            if(entry)
                data += ',';
            else
                entry = "true";
            data += '[';
            data += boolToStr( ((__uint64)pow(2, i) & this->_variables) );/*?optimize*/
            data += ',';
            data += std::to_string( (unsigned)i+1 );
            data += ']';
        }
    }
    data += "]}";
    return data;
}

/**** UNIQUE FUNCTIONS ****/
Expression *Expression::gluing(const Expression &var1, const Expression &var2)
{
    if( var1 == var2 ) /*check if ???*/
        return nullptr;

    std::size_t varSize = Expression::getVarSize();

    for(__uint8 i(0); i < varSize; i++)
    {
        if( !compareBits(var1._shortenedVars, var2._shortenedVars, i) )
                    return nullptr;
    }

    __uint8 indOfNotEqualVar;//Index of the not equal variable
    bool changeIndicator(false);//Check if the indOfNotEqualVar is unique
    for(__uint8 i(0); i < varSize; i++)
    {
        if( !compareBits(var1._variables, var2._variables, i) )
        {
            if(changeIndicator)//if the indOfNotEqualVar is not unique, leave the function
                return nullptr;
            indOfNotEqualVar = i;
            changeIndicator = true;
        }
    }
    if(!changeIndicator)//nothing was change
        return nullptr;
    Expression *result = new Expression;
    result->_shortenedVars = var1._shortenedVars;
    result->_shortenedVars ^= (__uint64)pow(2, indOfNotEqualVar);
    result->_variables = var1._variables;
    return result;
}

bool Expression::compareBits(__uint64 value1, __uint64 value2, __uint8 ind)
{
    __uint64 currentBit = (__uint64)pow(2, ind);
    return (value1 & currentBit) == (value2 & currentBit);
}

void Expression::setAllVars(__uint64 vars)
{
    this->_variables = vars;
}

std::pair<__uint64, __uint64> Expression::getAllVars() const
{
    return std::make_pair(this->_variables, this->_shortenedVars);
}

/*std::size_t Expression::getVarSize(std::size_t setVarSize)
{
    static std::size_t staticVarSize = 0;
    if(setVarSize != 0)
        staticVarSize = setVarSize;
    return staticVarSize;
}*/

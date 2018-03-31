#include "expression.h"

#include <vector>
#include <iostream>
#include <bitset>
#include <cmath>
#include <exception>
#include <typeinfo>

/**** CONSTRUCTOR & DESTRUCTOR ****/
Expression::Expression(){}
Expression::~Expression(){}

/**** OVERRIDE FUNCTIONS ****/
std::string Expression::print() const
{
    std::string data;
    
    data += "{\"expr\":[";
    std::size_t expressionSize = this->_variables.size();
    for(std::size_t i(0); i < expressionSize; i++)
    {
		if (!this->getShortend(i))
		{			
            data += '[';
            data += boolToStr( this->getValue( i ) );/*?optimize*/
            data += ',';
            data += std::to_string( (unsigned)i+1 );
            data += ']';
			data += ',';
        }
    }
	eraseLastComma(data);
    data += "]}";
    return data;
}

/**** UNIQUE FUNCTIONS ****/
Expression *Expression::gluing(const Expression &var1, const Expression &var2)
{
    if( var1.compareAllVariables( var2 ) ) /*check if ???*/
        return nullptr;

    std::size_t varSize = var1._variables.size();

    for(std::size_t i(0); i < varSize; i++)
    {
        if( var1.getShortend( i ) != var2.getShortend( i ) )
            return nullptr;
    }

    __uint64 indOfNotEqualVar;//Index of the not equal variable
    bool changeIndicator(false);//Check if the indOfNotEqualVar is unique
    for(std::size_t i(0); i < varSize; i++)
    {
        if( var1.getValue( i ) != var2.getValue( i ) )
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
    result->_variables = var1._variables;
    result->_variables[ indOfNotEqualVar ] = eValue::logNone;
    return result;
}

void Expression::setVar(bool var)
{
    this->_variables.push_back( (var ? logTrue : logFalse) );
}

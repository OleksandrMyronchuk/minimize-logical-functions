#include <iostream>
#include <cmath>
#include "constituent.h"
#include "expression.h"

/**** CONSTRUCTOR & DESTRUCTOR ****/
Constituent::Constituent(const std::vector<bool> &cons)
{
    this->setCons(cons);
}
Constituent::~Constituent(){}

/**** OVERRIDE FUNCTIONS ****/
std::string Constituent::print() const
{
    std::string data;

    std::size_t allConstituentSize = this->_cons.size();
    data += "{\"cnst\":[";
    for(std::size_t i( 0 ); i < allConstituentSize; i++)
    {
        if(i != 0)
            data += ',';
        data += boolToStr( this->_cons.at( i ) );
    }
    data += "]}";
    return data;
}

std::size_t Constituent::allVarSize()
{
    return sqrt( this->_cons.size() );
}

std::size_t Constituent::getSize()
{
    return this->_cons.size();
}

std::vector<bool> Constituent::getAllCons() const
{
    return this->_cons;
}

/**** UNIQUE FUNCTIONS ****/
void Constituent::setCons(const std::vector<bool> &cons)
{
    this->_cons = cons;
}

std::vector<Expression> Constituent::getAllTrueExpr()
{
    std::vector<Expression> allTrueExpr;
    std::size_t consSize = getSize();
    std::size_t varsSize = this->allVarSize();
    for(__uint64 i(0); i < consSize; i++)
    {
        if( this->_cons.at(i) )
        {
            Expression expr;
            for(__uint64 j(0); j < varsSize; j++)
            {
                expr.setVar( (__uint64)pow(2, j) & i );
            }
            allTrueExpr.push_back( expr );
        }
    }
    return allTrueExpr;
}

























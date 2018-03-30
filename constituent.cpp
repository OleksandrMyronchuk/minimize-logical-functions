#include <iostream>
#include "constituent.h"
#include "expression.h"

/**** CONSTRUCTOR & DESTRUCTOR ****/
Constituent::Constituent(){}
Constituent::~Constituent(){}

/**** OVERRIDE FUNCTIONS ****/
std::string Constituent::print() const
{
    std::string data;

    std::size_t allConstituentSize = pow(2, this->???);
    data += "{\"cnst\":[";
    for(std::size_t i(0), j(0); i < allConstituentSize; i++)
    {
        if(i != 0)
            data += ',';
        if( this->_truCons.at(j) == i )
        {
            data += "true";
            j++;
        }
        else
        {
            data += "false";
        }
    }
    data += "]}";
    return data;
}

/**** UNIQUE FUNCTIONS ****/
void Constituent::setCons(const __uint64 &cons)
{
    this->_cons = cons;
}


#include "shortnormalform.h"

#include <iostream>
#include <bitset>
#include <algorithm>

/**** CONSTRUCTOR & DESTRUCTOR ****/
ShortNormalForm::ShortNormalForm() {}
ShortNormalForm::~ShortNormalForm() {}

/**** OVERRIDE FUNCTIONS ****/
std::vector<Expression> &ShortNormalForm::getAllExpr()
{
    return this->_expressionSNFs;
}

std::string ShortNormalForm::print() const
{
    std::string data;

    std::size_t expressionSNFsSize = this->_expressionSNFs.size();
    data += "{\"snf\":[";
    for(std::size_t i(0); i < expressionSNFsSize; i++)
    {
        if(i != 0)
            data += ',';
        data += this->_expressionSNFs[i].print();
    }
    data += "]}";
    return data;
}

/**** UNIQUE FUNCTIONS ****/
std::vector<__uint64> ShortNormalForm::deleteDuplicates()/*номера які були видалені*/
{
    std::size_t expressionSNFsSize = this->_expressionSNFs.size();
    std::vector<__uint64> duplicates;
    for(std::size_t i(0); i < expressionSNFsSize; i++)
    {
        for(std::size_t j(i + 1); j < expressionSNFsSize; j++)
        {
            if( this->_expressionSNFs.at(i) == this->_expressionSNFs.at(j) )
            {
                duplicates.push_back( j + duplicates.size() );
                this->_expressionSNFs.erase( this->_expressionSNFs.begin() + j );
                expressionSNFsSize--;
                j--;
            }
        }
    }
    return duplicates;
}

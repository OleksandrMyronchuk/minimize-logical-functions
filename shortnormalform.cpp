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
    std::sort(this->_expressionSNFs.begin(), this->_expressionSNFs.end());
    std::size_t expressionSNFsSize = this->_expressionSNFs.size() - 1;
    std::vector<__uint64> duplicates;
    for(std::size_t i(0); i < expressionSNFsSize; i++)
    {
        if(this->_expressionSNFs.at(i) == this->_expressionSNFs.at(i + 1))
        {
            duplicates.push_back( i + duplicates.size() );
            this->_expressionSNFs.erase( this->_expressionSNFs.begin() + i );
            expressionSNFsSize--;
        }
    }
    return duplicates;
}

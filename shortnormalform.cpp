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
    return this->_expressionSNFs; /*return the SNF vector*/
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
std::vector<__uint64> ShortNormalForm::deleteDuplicates()
{    
    std::size_t expressionSNFsSize = this->_expressionSNFs.size(); /*Get size of the SNF vector*/
    std::vector<__uint64> duplicates; /*Create a new vector to save deleted numbers*/
    for(std::size_t i(0); i < expressionSNFsSize; i++) /*Overcoming all possible combinations of the SNF*/
    {
        for(std::size_t j(i + 1); j < expressionSNFsSize; j++)
        {            
            if( this->_expressionSNFs.at(i).compareAllVariables( this->_expressionSNFs.at(j) ) ) /*Check if the expressions "i" and "j" are the same*/
            {                
                duplicates.push_back( j + duplicates.size() ); /*Push a duplicate number to the vector*/
                this->_expressionSNFs.erase( this->_expressionSNFs.begin() + j ); /*Erase the current duplicate expression*/
                expressionSNFsSize--; /*Change size of the SNF (because one expression was deleted)*/
                j--; /*Change the number of loop steps*/
            }
        }
    }
    return duplicates; /*return numbers that were deleted*/
}

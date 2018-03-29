#include "perfectnormalform.h"

#include <iostream>
#include <bitset>
#include <cmath>
#include <minijson_writer.hpp>

/**** CONSTRUCTOR & DESTRUCTOR ****/
PerfectNormalForm::PerfectNormalForm(const std::vector<__uint64> &truCons) :
    _expressionPNFs( truCons.size() )
{        
    this->setAllExpr( truCons ); /*Init the _expressionPNFs vector*/
}
PerfectNormalForm::~PerfectNormalForm(){}

/**** OVERRIDE FUNCTIONS ****/
std::vector<Expression> &PerfectNormalForm::getAllExpr()
{
    return this->_expressionPNFs; /*return the PNF vector*/
}

std::string PerfectNormalForm::print() const
{    
/*

{
pnf:[ <expr> ]
cnst: [ 1 or 0, 1 or 0, … 1 or 0 ]
//
нумерація починається з 0, і не потребує додаткових змінних.
Наприклад.
cnst[0] <номер = 1, значення = cnst[0]> / cnst[22] <номер = 23, значення = cnst[22]>
//
}

*/
    std::string data;

    std::size_t expressionPNFsSize = this->_expressionPNFs.size();
    data += "{\"pnf\":[";
    for(__uint64 i(0); i < expressionPNFsSize; i++)
    {
        if(i != 0)
            data += ',';
        data += this->_expressionPNFs[i].print();
    }
    data += "]}\n";
    ???data += this->Constituent::print();
    return data;
}

/**** UNIQUE FUNCTIONS ****/
void PerfectNormalForm::setAllExpr(const std::vector<__uint64> &truCons)
{
    for(__uint64 i(0); i < truCons.size(); i++) /*For each true contituent*/
        this->_expressionPNFs[i].setAllVars(truCons[i]); /*Set variables to the _expressionPNFs vector of expressions*/
}

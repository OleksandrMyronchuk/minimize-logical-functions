#include "initkuainrule.h"

#include <iostream>
#include <kuainrule.h>
#include <expression.h>

/**** CONSTRUCTOR & DESTRUCTOR ****/
InitKuainRule::InitKuainRule( std::size_t numVars, const std::vector<__uint64> &truCons )
///!!!:::
{
    this->_numVars = varNum;
    this->perfectNormalForm = new PerfectNormalForm( truCons );
    this->constituent = new Constituent( truCons );
}

/**** OVERRIDE FUNCTIONS ****/
std::string InitKuainRule::print() const
{
    std::string data;

    data += this->perfectNormalForm->print();
    data += '\n';
    data += this->shortNormalForm->print();
    data += '\n';
    data += this->normalForm->print();
    data += '\n';
    data += this->_data;
    return data;
}

/**** UNIQUE FUNCTIONS ****/
NormalForm *InitKuainRule::run()
{   
    this->shortNormalForm = this->gluingLoop( this->perfectNormalForm );
    this->normalForm = this->absorption( this->perfectNormalForm, this->shortNormalForm );
    return this->normalForm;
}

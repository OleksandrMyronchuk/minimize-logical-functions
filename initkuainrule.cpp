#include "initkuainrule.h"

#include <iostream>
#include <kuainrule.h>
#include <expression.h>

/**** CONSTRUCTOR & DESTRUCTOR ****/
InitKuainRule::InitKuainRule( __uint8 varNum, const std::vector<__uint64> &truCons )
{
    Expression::getVarSize(varNum);
    this->perfectNormalForm = new PerfectNormalForm( truCons );
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
    data += KuainRule::print();
    return data;
}

/**** UNIQUE FUNCTIONS ****/
NormalForm *InitKuainRule::run()
{   
    this->shortNormalForm = KuainRule::gluingLoop( this->perfectNormalForm );
    this->normalForm = KuainRule::absorption( this->perfectNormalForm, this->shortNormalForm );    
    return this->normalForm;
}

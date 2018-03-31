#include "initkuainrule.h"

#include <iostream>
#include <cmath>
#include "kuainrule.h"
#include "expression.h"

/**** CONSTRUCTOR & DESTRUCTOR ****/
InitKuainRule::InitKuainRule( const std::vector<bool> &cons )
{
	this->constituent = new Constituent(cons);
	this->perfectNormalForm = new PerfectNormalForm(this->constituent->getAllTrueExpr());
}

/**** OVERRIDE FUNCTIONS ****/
std::string InitKuainRule::print() const
{
    std::string data;

    data += this->perfectNormalForm->print();    
    data += '\n';
	data += this->constituent->print();
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

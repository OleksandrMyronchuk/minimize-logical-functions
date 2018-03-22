#ifndef PERFECTNORMALFORM_H
#define PERFECTNORMALFORM_H

#include <vector>
#include <defines.h>
#include <expression.h>
#include <constituent.h>
#include <abstractobject.h>
#include <abstractnormalform.h>

class PerfectNormalForm : public Constituent, public AbstractNormalForm
{
private:
    std::vector <Expression> _expressionPNFs;
public:
    /**** CONSTRUCTOR & DESTRUCTOR ****/
    PerfectNormalForm(const std::vector<__uint64>& truCons);
    ~PerfectNormalForm();

    /**** OVERRIDE FUNCTIONS ****/
    std::vector<Expression> &getAllExpr() override;
    std::string print() const override;

     /**** UNIQUE FUNCTIONS ****/
    void setNumOfVectorVar(const std::vector<__uint64> &truCons);    
};

#endif // PERFECTNORMALFORM_H

#ifndef SHORTNORMALFORM_H
#define SHORTNORMALFORM_H

#include <defines.h>
#include <expression.h>
#include <abstractnormalform.h>
#include <abstractobject.h>
#include <cstddef>
#include <vector>

class ShortNormalForm : public AbstractNormalForm, public AbstractObject
{
    std::vector<Expression> _expressionSNFs;
public:
    /**** Constructor & Destructor ****/    
    ShortNormalForm();
    ~ShortNormalForm();

    /**** OVERRIDE FUNCTIONS ****/
    std::vector<Expression> &getAllExpr() override;
    std::string print() const override;

    /**** UNIQUE FUNCTIONS ****/
    std::vector<__uint64> deleteDuplicates();
};

#endif // SHORTNORMALFORM_H

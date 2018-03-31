#ifndef NORMALFORM_H
#define NORMALFORM_H

#include "expression.h"
#include "abstractnormalform.h"
#include "abstractobject.h"
#include <vector>

class NormalForm : public AbstractNormalForm, public AbstractObject
{
    std::vector <Expression> _expressionNFs;
public:
    /**** CONSTRUCTOR & DESTRUCTOR ****/
    NormalForm();
    ~NormalForm();

    /**** OVERRIDE FUNCTIONS ****/
    /*!
     * \brief Get all expressions from the NF class
     * \return Vector of \a Expression objects
     */
    std::vector<Expression> &getAllExpr() override;
    std::string print() const override;
};

#endif // NORMALFORM_H

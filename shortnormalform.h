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
    /*!
     * \brief Get all expressions from the SNF class
     * \return Vector of \a Expression objects
     */
    std::vector<Expression> &getAllExpr() override;
    std::string print() const override;

    /**** UNIQUE FUNCTIONS ****/
    /*!
     * \brief Delete duplicate expression from the \a SNF class
     *
     * Delete duplicate expression from the \a ShortNormalForm class
     * the order of removal is not important, as well as the result of the return
     *
     * For example:
     * The \a SNF contains the following expressions: \a 1010, \a 1101, \a 1010, \a 0001;
     * The \a deleteDuplicates method delete \a 1010 from first position or third position and
     * return \a 1 or \a 3 number as the vector \a std::vector<__uint64>
     *
     * \return Numbers of the position of duplicate expressions
     */
    std::vector<__uint64> deleteDuplicates();
};

#endif // SHORTNORMALFORM_H

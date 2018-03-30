#ifndef INITCRAMERRULE_H
#define INITCRAMERRULE_H
#include <defines.h>
#include <perfectnormalform.h>
#include <constituent.h>
#include <shortnormalform.h>
#include <normalform.h>
#include "kuainrule.h"
#include <vector>
#include <fstream>
#include <abstractobject.h>

class InitKuainRule : public AbstractObject, public KuainRule
{
private:
    /*!
     * \brief Perfect normal form object
     */
    PerfectNormalForm *perfectNormalForm;

    /*!
     * \brief Short normal form object
     */
    ShortNormalForm *shortNormalForm;

    /*!
     * \brief Normal form object (result)
     */
    NormalForm *normalForm;

    /*!
     * \brief Constituent object
     */
    Constituent *constituent;
public:
    /**** CONSTRUCTOR & DESTRUCTOR ****/
    /*!
     * \brief InitKuainRule ??????????????????????????????????????????????????????????????????
     * \param cons
     */
    InitKuainRule(const std::vector<__uint64> &cons);

    /**** OVERRIDE FUNCTIONS ****/
    /*!
     * \brief print
     * \return
     */
    std::string print() const;

    /**** UNIQUE FUNCTIONS ****/
    /*!
     * \brief Run calculation
     * \return Shortened normal form from the truth table
     */
    NormalForm *run();
};

#endif // INITCRAMERRULE_H

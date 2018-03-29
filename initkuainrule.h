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
     * \brief Init the "Kuain Rule"
     *
     * Set the initial data that was subsequently processed by calling the \a run method
     * \param [in] varNum - The number of variables \n
     * For example: \n
     * The following truth table includes \a x1, \a x2 variables, their total number is equal to two
     * <table>
     * <caption>Truth table №1</caption>
     * <tr><th>#    <th>x1  <th>x2  <th>Constituents
     * <tr><th>0    <td>0   <td>0   <td>0
     * <tr><th>1    <td>0   <td>1   <td>1
     * <tr><th>2    <td>1   <td>0   <td>1
     * <tr><th>3    <td>1   <td>1   <td>0
     * </table>
     * In order to insert the \a Truth \a table \a №1 into the \a InitKuainRule constructor, first parameter should be \a 2
     * \param [in] truCons - Truth constituents
     * For example:
     * The table \a Truth \a table \a №1 contains \a 1, \a 2 true constituents
     * In order to insert the \a Truth \a table \a №1 into the \a InitKuainRule constructor, second parameter should be \a {1, 2}
     * or a reference to vector that contains these number
     * \note The count of the \a truCons parameter begins with a zero number
     */
    InitKuainRule(std::size_t numVars, const std::vector<__uint64>& truCons);

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

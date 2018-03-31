#ifndef PERFECTNORMALFORM_H
#define PERFECTNORMALFORM_H

#include <vector>
#include "defines.h"
#include "expression.h"
#include "constituent.h"
#include "abstractobject.h"
#include "abstractnormalform.h"

namespace nsKuainRule {

	class PerfectNormalForm : public AbstractObject, public AbstractNormalForm
	{
	private:
		std::vector <Expression> _expressionPNFs;
	public:
		/**** CONSTRUCTOR & DESTRUCTOR ****/
		/*!
		 * \brief The \a PerfectNormalForm constructor
		 *
		 * Set the constituent of the \a PerfectNormalForm and \a Constituent clases
		 *
		 * For example:
		 * The following table shows the truth table
		 * <table>
		 * <caption>Truth table</caption>
		 * <tr><th>#    <th>x1  <th>x2  <th>Constituents
		 * <tr><th>0    <td>0   <td>0   <td>0
		 * <tr><th>1    <td>0   <td>1   <td>1
		 * <tr><th>2    <td>1   <td>0   <td>1
		 * <tr><th>3    <td>1   <td>1   <td>0
		 * </table>
		 *
		 * Numbers \a 1, \a 2 should be put to the method as the \a truCons parameter \n
		 * The following example explains one of the ways, how to init the \a PerfectNormalForm object
		 * \code
		 * PerfectNormalForm perfectNormalForm({1, 2});
		 * \endcode
		 * \param [in] truCons - Vector of true constituents
		 * \note The count of the \a truCons parameter begins with a zero number
		 */
		PerfectNormalForm(const std::vector<Expression> &allExpr);
		~PerfectNormalForm();

		/**** OVERRIDE FUNCTIONS ****/
		/*!
		 * \brief Get all expressions from the PNF class
		 * \return Vector of \a Expression objects
		 */
		std::vector<Expression> &getAllExpr() override;
		std::string print() const override;

		/**** UNIQUE FUNCTIONS ****/
	   /*!
		* \brief Set all expressions to the PNF class
		* \param [in] truCons - Vector of true constituents
		*/
		void setAllExpr(const std::vector<Expression> &allExpr);
	};

}

#endif // PERFECTNORMALFORM_H

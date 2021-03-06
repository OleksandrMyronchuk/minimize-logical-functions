#ifndef NORMALFORM_H
#define NORMALFORM_H
#include "global.h"

#include <vector>
#include "expression.h"
#include "abstractnormalform.h"
#include "abstractobject.h"

namespace nsKuainRule {

	class NormalForm : public AbstractNormalForm, public AbstractObject
	{
		std::vector <Expression> _expressionNFs;
	public:
		/**** CONSTRUCTOR & DESTRUCTOR ****/
		KUAINRULE_API NormalForm();
		KUAINRULE_API virtual ~NormalForm();

		/**** OVERRIDE FUNCTIONS ****/
		/*!
		 * \brief Get all expressions from the NF class
		 * \return Vector of \a Expression objects
		 */
		KUAINRULE_API std::vector<Expression> &getAllExpr() override;
		KUAINRULE_API std::string print() const override;
	};

}
#endif // NORMALFORM_H

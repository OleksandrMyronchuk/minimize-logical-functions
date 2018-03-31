#include "abstractnormalform.h"

namespace nsKuainRule {

	/**** UNIQUE FUNCTIONS ****/
	const Expression &AbstractNormalForm::getExprById(__uint64 ind)
	{
		return this->getAllExpr().at(ind);
	}

	std::size_t AbstractNormalForm::exprSize()
	{
		return this->getAllExpr().size();
	}

	void AbstractNormalForm::setExpr(Expression *expression)
	{
		this->getAllExpr().push_back(*expression);
	}

	void AbstractNormalForm::setExpr(const Expression &expression)
	{
		this->getAllExpr().push_back(expression);
	}

}
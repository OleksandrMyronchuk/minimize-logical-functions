#ifndef ABSTRACTNORMALFORM_H
#define ABSTRACTNORMALFORM_H
#include "global.h"

#include <vector>
#include "expression.h"

namespace nsKuainRule {


	class AbstractNormalForm
	{
	public:
		/**** PURE VIRTUAL FUNCTIONS  ****/
		KUAINRULE_API virtual std::vector<Expression> &getAllExpr() = 0;

		/**** UNIQUE FUNCTIONS ****/
		KUAINRULE_API const Expression &getExprById(__uint64 ind);
		KUAINRULE_API std::size_t exprSize();//Кількість Exptrtion у векторі
		KUAINRULE_API void setExpr(Expression *expression);
		KUAINRULE_API void setExpr(const Expression &expression);
	};

}
#endif // ABSTRACTNORMALFORM_H

#ifndef ABSTRACTNORMALFORM_H
#define ABSTRACTNORMALFORM_H

#include <vector>
#include "expression.h"

namespace nsKuainRule {


	class AbstractNormalForm
	{
	public:
		/**** PURE VIRTUAL FUNCTIONS  ****/
		virtual std::vector<Expression> &getAllExpr() = 0;

		/**** UNIQUE FUNCTIONS ****/
		const Expression &getExprById(__uint64 ind);
		std::size_t exprSize();//Кількість Exptrtion у векторі
		void setExpr(Expression *expression);
		void setExpr(const Expression &expression);
	};

}
#endif // ABSTRACTNORMALFORM_H

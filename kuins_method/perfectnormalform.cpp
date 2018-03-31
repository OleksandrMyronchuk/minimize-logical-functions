#include <cstddef>
#include "perfectnormalform.h"

namespace nsKuainRule {

	/**** CONSTRUCTOR & DESTRUCTOR ****/
	PerfectNormalForm::PerfectNormalForm(const std::vector<Expression> &allExpr)
	{
		this->setAllExpr(allExpr);
	}
	PerfectNormalForm::~PerfectNormalForm() {}

	/**** OVERRIDE FUNCTIONS ****/
	std::vector<Expression> &PerfectNormalForm::getAllExpr()
	{
		return this->_expressionPNFs; /*return the PNF vector*/
	}

	std::string PerfectNormalForm::print() const
	{
		std::string data;

		std::size_t expressionPNFsSize = this->_expressionPNFs.size();
		data += "{\"pnf\":[";
		for (__uint64 i(0); i < expressionPNFsSize; i++)
		{
			if (i != 0)
				data += ',';
			data += this->_expressionPNFs[i].print();
		}
		data += "]}";
		return data;
	}

	/**** UNIQUE FUNCTIONS ****/
	void PerfectNormalForm::setAllExpr(const std::vector<Expression> &allExpr)
	{
		this->_expressionPNFs = allExpr;
	}

}
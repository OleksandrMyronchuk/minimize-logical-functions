#include "normalform.h"

#include <iostream>
#include <bitset>

namespace nsKuainRule {

	/**** CONSTRUCTOR & DESTRUCTOR ****/
	NormalForm::NormalForm() {}
	NormalForm::~NormalForm() {}

	/**** OVERRIDE FUNCTIONS ****/
	std::vector<Expression> &NormalForm::getAllExpr()
	{
		return this->_expressionNFs; /*return the NF vector*/
	}

	std::string NormalForm::print() const
	{
		std::string data;

		std::size_t expressionNFsSize = this->_expressionNFs.size();
		data += "{\"nf\":[";
		for (std::size_t i(0); i < expressionNFsSize; i++)
		{
			if (i != 0)
				data += ',';
			data += this->_expressionNFs[i].print();
		}
		data += "]}";
		return data;
	}

}
#ifndef EXPRESSION_H
#define EXPRESSION_H
#include "global.h"

#include "abstractobject.h"
#include "defines.h"
#include <cstddef>
#include <vector>

namespace nsKuainRule {

	enum eValue { logFalse = 0b0, logTrue = 0b1, logNone = 0b10 };

	class Expression : public AbstractObject
	{
	private:
		inline bool getValue(__uint64 ind) const
		{
			return this->_variables.at(ind) & 1;
		}
		inline bool getShortend(__uint64 ind) const
		{
			return this->_variables.at(ind) & 2;
		}
		std::vector<__uint8> _variables;
	public:
		/**** CONSTRUCTOR & DESTRUCTOR ****/
		KUAINRULE_API Expression();
		KUAINRULE_API virtual ~Expression();

		/**** OVERRIDE FUNCTIONS ****/
		KUAINRULE_API std::string print() const override;

		/**** UNIQUE FUNCTIONS ****/
		KUAINRULE_API Expression static *gluing(const Expression &var1, const Expression &var2);
		KUAINRULE_API void setVar(bool var);
		inline bool compareAllValues(const Expression &other) const
		{
			std::size_t currectVarSize = this->_variables.size();

			if (currectVarSize != other._variables.size()) /*check size*/
				return false;
			for (std::size_t i(0); i < currectVarSize; i++) /*check value*/
			{
				if (this->getShortend(i) || other.getShortend(i))
					continue; /*skip none value*/
				if (this->getValue(i) != other.getValue(i))
					return false;
			}
			return true;
		}
		inline bool compareAllVariables(const Expression &other) const
		{
			std::size_t currectVarSize = this->_variables.size();

			if (currectVarSize != other._variables.size()) /*check size*/
				return false;

			for (std::size_t i(0); i < currectVarSize; i++) /*check value*/
			{
				if (this->_variables.at(i) != other._variables.at(i))
					return false;
			}
			return true;
		}
	};

}
#endif // EXPRESSION_H

#ifndef CONSTITUENT_H
#define CONSTITUENT_H
#include "global.h"

#include <vector>
#include <cstddef>
#include "expression.h"
#include "abstractobject.h"

namespace nsKuainRule {

	class Constituent : public AbstractObject
	{
	private:
		std::vector<bool> _cons;
	public:
		/**** CONSTRUCTOR & DESTRUCTOR ****/
		KUAINRULE_API Constituent(const std::vector<bool> &cons);
		KUAINRULE_API virtual ~Constituent();

		/**** OVERRIDE FUNCTIONS ****/
		KUAINRULE_API std::string print() const override;

		/**** UNIQUE FUNCTIONS ****/
		KUAINRULE_API std::size_t allVarSize();
		KUAINRULE_API std::size_t getSize();
		KUAINRULE_API std::vector<bool> getAllCons() const;
		KUAINRULE_API void setCons(const std::vector<bool> &cons);
		KUAINRULE_API std::vector<Expression> getAllTrueExpr();
	};

}
#endif // CONSTITUENT_H

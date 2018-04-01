#ifndef ABSTRACTOBJECT_H
#define ABSTRACTOBJECT_H
#include "global.h"

#include <string>

namespace nsKuainRule {

	class AbstractObject
	{
	public:
		/**** PURE VIRTUAL FUNCTIONS ****/
		KUAINRULE_API virtual std::string print() const = 0;
	};

}
#endif // ABSTRACTOBJECT_H

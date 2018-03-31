#ifndef ABSTRACTOBJECT_H
#define ABSTRACTOBJECT_H

#include <vector>
#include <string>

namespace nsKuainRule {

	class AbstractObject
	{
	public:
		/**** PURE VIRTUAL FUNCTIONS ****/
		virtual std::string print() const = 0;
	};

}
#endif // ABSTRACTOBJECT_H

#ifndef ABSTRACTOBJECT_H
#define ABSTRACTOBJECT_H

#ifdef KUAINRULE_EXPORTS  
#define KUAINRULE_API __declspec(dllexport)   
#else  
#define KUAINRULE_API __declspec(dllimport)   
#endif

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

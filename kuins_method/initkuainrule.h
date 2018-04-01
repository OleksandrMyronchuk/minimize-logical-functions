#ifndef INITCRAMERRULE_H
#define INITCRAMERRULE_H
#include "global.h"

#include <vector>
#include "perfectnormalform.h"
#include "shortnormalform.h"
#include "normalform.h"
#include "constituent.h"
#include "abstractobject.h"
#include "kuainrule.h"

namespace nsKuainRule {

	class InitKuainRule : public AbstractObject, public KuainRule
	{
	private:
		/*!
		 * \brief Perfect normal form object
		 */
		PerfectNormalForm *perfectNormalForm;

		/*!
		 * \brief Short normal form object
		 */
		ShortNormalForm *shortNormalForm;

		/*!
		 * \brief Normal form object (result)
		 */
		NormalForm *normalForm;

		/*!
		 * \brief Constituent object
		 */
		Constituent *constituent;
	public:
		/**** CONSTRUCTOR & DESTRUCTOR ****/
		/*!
		 * \brief InitKuainRule ??????????????????????????????????????????????????????????????????
		 * \param cons
		 */
		KUAINRULE_API InitKuainRule(const std::vector<bool> &cons);
		KUAINRULE_API virtual ~InitKuainRule();

		/**** OVERRIDE FUNCTIONS ****/
		/*!
		 * \brief print
		 * \return
		 */
		KUAINRULE_API std::string print() const;

		/**** UNIQUE FUNCTIONS ****/
		/*!
		 * \brief Run calculation
		 * \return Shortened normal form from the truth table
		 */
		KUAINRULE_API NormalForm *run();
	};

}

#endif // INITCRAMERRULE_H

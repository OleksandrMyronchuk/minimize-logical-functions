#ifndef CRAMERRULE_H
#define CRAMERRULE_H
#include "global.h"

#include <string>
#include "shortnormalform.h"
#include "normalform.h"
#include "perfectnormalform.h"

namespace nsKuainRule {

	class KuainRule
	{
	protected:
		/*!
		 * \brief Text data about the work methods
		 */
		std::string _data;
	private:
		/**** UNIQUE FUNCTIONS ****/
		/*!
		 * \brief Temporary text data about the work methods
		 */
		std::string _lastData;

		/*!
		 * \brief Number of variables
		 */
		std::size_t _numVars;

		/*!
		 * \brief Gluing one of the expression
		 *
		 * \param [in] typeNormalForm - Normal form that should be shortened \n
		 * Typically, as a \a typeNormalForm may be the \a PerfectNormalForm or \a ShortNormalForm
		 *
		 * \return Shortened normal form from the \a typeNormalForm
		 */
		template <typename tNF>
		ShortNormalForm *gluing(tNF *typeNormalForm);
	public:
		/**** CONSTRUCTOR & DESTRUCTOR ****/
		KUAINRULE_API KuainRule();
		KUAINRULE_API ~KuainRule();

		/**** OVERRIDE FUNCTIONS ****/
		/*!
		 * \brief print
		 * \return
		 */
		KUAINRULE_API std::string print();

		/**** UNIQUE FUNCTIONS ****/
		/*!
		 * \brief Gluing all expressions
		 *
		 * Operation (full) of gluing is determined by the ratio: \n
		 * x ∧ y ∨ x ∧ y̅ = x;
		 * \param [in] perfectNormalForm - Perfect normal form object
		 * \return Shortened normal form from the perfect normal form
		 */
		KUAINRULE_API ShortNormalForm *gluingLoop(PerfectNormalForm *perfectNormalForm);

		/*!
		 * \brief Operation of absorption
		 *
		 * The absorption operation is determined by the ratio: \n
		 * x ∨ x ∧ y = x;
		 * \param [in] perfectNormalForm - Perfect normal form object
		 * \param [in] shortNormalForm - Short normal form object
		 * \return \a NormalForm that was result from the absorption of \a perfectNormalForm and \a shortNormalForm objects
		 */
		KUAINRULE_API NormalForm *absorption(PerfectNormalForm *perfectNormalForm, ShortNormalForm *shortNormalForm);
	};

}
#endif // CRAMERRULE_H

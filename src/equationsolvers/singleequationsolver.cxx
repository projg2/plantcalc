/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "singleequationsolver.hxx"

SingleEquationSolver::SingleEquationSolver(EquationSystem& eqs, double epsilon)
	: _eqs(eqs), _epsilon(epsilon)
{
}

bool SingleEquationSolver::iterate()
{
	EquationSystem& eqs = _eqs;
	EquationSystem::iterator it;
	bool any_solved = false;

	for (it = eqs.begin(); it != eqs.end();)
	{
		Equation& e = **it;

		if (e.solve(_epsilon))
		{
			any_solved = true;
			it = eqs.erase(it);
		}
		else
			++it;
	}

	return any_solved;
}

/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "mediumconnection.hxx"

MediumConnection::MediumConnection(MediumPin& from, MediumPin& to)
	: _from(from), _to(to),
	_p_eq(from.p(), to.p()),
	_T_eq(from.T(), to.T()),
	_h_eq(from.h(), to.h()),
	_s_eq(from.s(), to.s()),
	_x_eq(from.x(), to.x()),
	_D_eq(from.D(), to.D()),
	_substance(0),
	_state_eq(_substance, from.p(), from.T(), from.h(), from.s(), from.x())
{
}

MediumPin& MediumConnection::from()
{
	return _from;
}

MediumPin& MediumConnection::to()
{
	return _to;
}

const MediumSubstance* MediumConnection::substance()
{
	return _substance;
}

void MediumConnection::substance(const Substance* new_subst)
{
	const MediumSubstance* subst = 0;

	if (new_subst) // use references to throw an exception
		subst = &dynamic_cast<const MediumSubstance&>(*new_subst);

	substance(subst);
}

void MediumConnection::substance(const MediumSubstance* new_subst)
{
	_substance = new_subst;
}

EquationSystem MediumConnection::equations()
{
	EquationSystem ret;

	ret.push_back(&_state_eq);
	ret.push_back(&_p_eq);
	ret.push_back(&_T_eq);
	ret.push_back(&_h_eq);
	ret.push_back(&_s_eq);
	ret.push_back(&_x_eq);
	ret.push_back(&_D_eq);

	return ret;
}

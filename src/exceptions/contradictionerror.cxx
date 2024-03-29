/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "contradictionerror.hxx"

ContradictionError::ContradictionError()
{
}

const char* ContradictionError::what() const throw()
{
	return "Contradicting equation.";
}

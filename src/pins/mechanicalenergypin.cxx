/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include "mechanicalenergypin.hxx"

MechanicalEnergyPin::MechanicalEnergyPin(const DeviceID& dev_id, const char* name)
	: Pin(dev_id, name),
	_P(_pin_id, "P")
{
}

MechanicalEnergyPin::variable_list_type MechanicalEnergyPin::variables()
{
	variable_list_type ret;

	ret.push_back(&_P);

	return ret;
}

Variable& MechanicalEnergyPin::P()
{
	return _P;
}

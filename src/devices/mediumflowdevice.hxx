/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_DEVICES_MEDIUMFLOWDEVICE_HXX
#define _PLANTCALC_DEVICES_MEDIUMFLOWDEVICE_HXX 1

#include "../device.hxx"
#include "../equationsystem.hxx"
#include "../pins/mediumpin.hxx"
#include "../equations/equalityequation.hxx"

class MediumFlowDevice : public Device
{
	MediumPin _in, _out;

	EqualityEquation _primary_mass_eq;

protected:
	MediumFlowDevice();

	virtual EquationSystem equations();

public:
	MediumPin& in();
	MediumPin& out();
};

#endif /*_PLANTCALC_DEVICES_MEDIUMFLOWDEVICE_HXX*/
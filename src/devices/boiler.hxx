/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_DEVICES_BOILER_HXX
#define _PLANTCALC_DEVICES_BOILER_HXX 1

#include "mediumflowdevice.hxx"
#include "../pins/fuelpin.hxx"
#include "../variables/devicevariable.hxx"

class Boiler : public MediumFlowDevice
{
	DeviceVariable _efficiency;

	FuelPin _fuel_in;
	LinearEquation _energy_balance_eq;
	LinearEquation _fuel_energy_eq;

protected:
	virtual Pin* iter_pin_get(int index);
	virtual DeviceVariable* iter_var_get(int index);

public:
	Boiler(double efficiency = 1);
	Boiler(double efficiency, double pout, double Tout);

	Variable& efficiency();

	FuelPin& fuel_in();

	virtual EquationSystem equations();
};

#endif /*_PLANTCALC_DEVICES_BOILER_HXX*/

/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef PLANTCALC_DEVICES_TURBINE_HXX
#define PLANTCALC_DEVICES_TURBINE_HXX 1

#include "common/reversibleturbine.hxx"

/**
 * A simple turbine.
 *
 * The Turbine class provides a simple turbine model which can be used
 * to obtain mechanical power through decompressing the medium.
 *
 * The real output enthalpy is calculated using the following equation:
 *
 * @f[
 * h_{out} = ( 1 - \eta_h ) h_{in} + \eta_h h_{ideal}
 * @f]
 *
 * with @f$ \eta_h @f$ being the isenthropic efficiency,
 * and @f$ h_{ideal} @f$ being the 'ideal' specific enthalpy obtained
 * in the loop.
 */
class Turbine : public ReversibleTurbine
{
	OwnedVariable _mechanical_efficiency_reciprocal;

	LinearEquation _real_expansion_eq;
	LinearEquation _mech_eff_reciprocal_eq;
	LinearEquation _energy_balance_eq;

public:
	/**
	 * Instantiate a new Turbine.
	 *
	 * @param[in] name The device name.
	 * @param[in] isenthropic_efficiency Initial isenthropic efficiency
	 * value.
	 * @param[in] mechanical_efficiency Initial mechanical efficiency value.
	 */
	Turbine(const char* name, double isenthropic_efficiency = 1,
			double mechanical_efficiency = 1);
	/**
	 * Instantiate a new Turbine and set the output pressure.
	 *
	 * @param[in] name The device name.
	 * @param[in] isenthropic_efficiency Initial isenthropic efficiency
	 * value.
	 * @param[in] mechanical_efficiency Initial mechanical efficiency value.
	 * @param[in] pout Initial output pressure [MPa].
	 */
	Turbine(const char* name, double isenthropic_efficiency,
			double mechanical_efficiency, double pout);

	virtual EquationSystem equations();
};

#endif /*_PLANTCALC_DEVICES_TURBINE_HXX*/

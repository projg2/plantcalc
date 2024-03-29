/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef PLANTCALC_DEVICES_COMMON_REVERSIBLETURBINE_HXX
#define PLANTCALC_DEVICES_COMMON_REVERSIBLETURBINE_HXX 1

#include "mediumflowdevice.hxx"
#include "../../connections/mediumconnection.hxx"
#include "../../pins/mechanicalenergypin.hxx"
#include "../../pins/mediumpin.hxx"
#include "../../equations/additiveinverseequation.hxx"
#include "../../equations/equalityequation.hxx"
#include "../../equations/linearequation.hxx"
#include "../../variables/ownedvariable.hxx"

/**
 * A simple reversible turbine (pump, compressor) model.
 *
 * The ReversibleTurbine provides a base class for devices which convert
 * medium energy into mechanical energy through decompression,
 * or the other way around.
 *
 * The following equation describes the heat exchange:
 *
 * @f[
 * D ( h_{in} - h_{out} ) = P \eta_m
 * @f]
 *
 * where @f$ D @f$ is the medium flux, @f$ h_{in} - h_{out} @f$ is
 * the difference between specific enthalpy of inlet and outlet
 * medium, @f$ P @f$ is the mechanical power and @f$ \eta_m @f$
 * is the mechanical efficiency.
 *
 * The mathematical model requires an abstract loop being connected
 * (loop_out() to loop_in()) in order to be able to perform real
 * expansion calculations. The 'ideal' output parameters will be set
 * in the loop.
 *
 * The real output enthalpy is expressed in the Turbine and Pump
 * sub-classes.
 */
class ReversibleTurbine : public MediumFlowDevice
{
	MediumPin _loop_in;

	LinearEquation _one_minus_isen_eff_eq;

	AdditiveInverseEquation _loop_mass_eq;
	AdditiveInverseEquation _loop_mass_balance_eq;
	EqualityEquation _loop_pressure_eq;
	EqualityEquation _ideal_expansion_eq;

	MediumConnection _loop_conn;

protected:
	MechanicalEnergyPin _energy_pin;

	OwnedVariable _mechanical_efficiency;

	OwnedVariable _isenthropic_efficiency;
	OwnedVariable _one_minus_isenthropic_efficiency;

	MediumPin _loop_out;

	/**
	 * Instantiate a new ReversibleTurbine.
	 *
	 * @param[in] name A short name for the device.
	 * @param[in] isenthropic_efficiency Initial isenthropic efficiency
	 * value.
	 * @param[in] mechanical_efficiency Initial mechanical efficiency value.
	 */
	ReversibleTurbine(const char* name,
			double isenthropic_efficiency,
			double mechanical_efficiency);
	/**
	 * Instantiate a new ReversibleTurbine and set the output pressure.
	 *
	 * @param[in] name A short name for the device.
	 * @param[in] isenthropic_efficiency Initial isenthropic efficiency
	 * value.
	 * @param[in] mechanical_efficiency Initial mechanical efficiency value.
	 * @param[in] pout Initial output pressure [MPa].
	 */
	ReversibleTurbine(const char* name,
			double isenthropic_efficiency,
			double mechanical_efficiency,
			double pout);

public:
	/**
	 * The isenthropic efficiency.
	 *
	 * The isenthropic efficiency is used to calculate the real
	 * output parameters.
	 */
	Variable& isenthropic_efficiency();
	/**
	 * The mechanical effiency.
	 *
	 * The mechanical efficiency is used to calculate the amount
	 * of mechanical energy obtained or consumed by the device.
	 */
	Variable& mechanical_efficiency();

	/**
	 * The energy output pin.
	 */
	MechanicalEnergyPin& energy_pin();

	virtual bool pins_connected(const Pin& lhs, const Pin& rhs) const;
	virtual EquationSystem equations();

	virtual pin_list_type pins();
	virtual variable_list_type variables();

	virtual connection_list_type internal_connections();
};

#endif /*_PLANTCALC_DEVICES_COMMON_REVERSIBLETURBINE_HXX*/

/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_IDS_DEVICEVARIABLEID_HXX
#define _PLANTCALC_IDS_DEVICEVARIABLEID_HXX 1

#include "deviceid.hxx"

#include <ostream>

class DeviceVariableID
{
private:
	DeviceID& _device;
	const char* _name;

	friend std::ostream&
		operator<<(std::ostream& f, const DeviceVariableID& dvid);

public:
	DeviceVariableID(DeviceID& device, const char* name);

	const char* name() const;
};

std::ostream& operator<<(std::ostream& f, const DeviceVariableID& dvid);

#endif /*_PLANTCALC_IDS_DEVICEVARIABLEID_HXX*/

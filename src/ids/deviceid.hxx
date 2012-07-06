/* plantcalc -- Power plant modelling
 * (c) 2012 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once

#ifndef _PLANTCALC_IDS_DEVICEID_HXX
#define _PLANTCALC_IDS_DEVICEID_HXX 1

#include <ostream>

class DeviceID
{
private:
	const char* _name;
	int _num;

	friend std::ostream& operator<<(std::ostream& f, const DeviceID& did);

public:
	DeviceID(const char* name);
};

std::ostream& operator<<(std::ostream& f, const DeviceID& did);

#endif /*_PLANTCALC_IDS_DEVICEID_HXX*/
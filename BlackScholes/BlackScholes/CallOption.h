#pragma once

#include "Date.h"

class CallOption
{
private: double _strike;	// S or K
		 double _riskFreeIR;	// r
		 Date _expiry{ 0,0,0 };
public: int daysUntilExpiry();
		CallOption(Date expiry) : _expiry(expiry) {};
};
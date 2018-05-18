#include "CallOption.h"

int CallOption::daysUntilExpiry()
{
	return _expiry - Date::now();
}
#include "leap.h"

namespace leap {
	bool is_leap_year(int year) {

		//return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));

		if (year % 4 == 0)
		{
			if (year % 100 == 0)
			{
				return (year % 400 == 0);
			}
			return true;
		}
		return false;
	}
}  // namespace leap

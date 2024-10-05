#include "darts.h"
#include<cmath>

namespace darts {
	int score(double x, double y) {
		//distance from the center
		double distance = std::sqrt(x * x + y * y);

		//scoring based on distance
		if (distance > 10.0)
		{
			return 0;
			//outside of the outer circle
		}
		else if (distance > 5.0) {
			return 1;
			//within the outer circle
		}
		else if (distance > 1.0)
		{
			return 5;  
			// Within the middle circle
		}
		else {
			return 10;  
			// Within the inner circle (including the center)
		}
	}

} // namespace darts
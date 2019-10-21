#pragma once

enum DotProductTest{	// angle between vector a and b ...
	Collinear,			// ... is exactly 0 degrees
	OppositeCollinear,	// ... is exactly 180 degrees
	Perpendicular,		// ... is exactly 90 degrees
	SameDireciton,		// ... is less than < 90 degrees
	OppositeDirection,	// ... is greater than > 90 degrees
	
	COUNT
};
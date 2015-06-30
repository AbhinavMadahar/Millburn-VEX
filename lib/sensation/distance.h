/******************************************************************************
This file manages the SONAR, or distance, sensor and makes it simpler to use.

It is called the distance sensor to separate the way it works and how it is
meaningful in the code. We can just say distance() because that is more
obviously meaningful than SONAR()

Before using it, please make sure the correct #pragma is used
TODO: figure out the right #pragma to use to make a senseSound
******************************************************************************/

#define included__distance true

#ifndef included__syntax
	#include "../syntax.h"
#endif

#ifndef included__math
	#include "../math.h"
#endif

unsigned byte distanceCorrected () {
	return SensorValue[senseDistance];
}

// the distance sensor is more likely to overestimate than underestimate
// thus, find the shortest distance measured
unsigned byte distance() {
	const unsigned int nRepeats = 5;
	unsigned byte shortest = 255; // start at the highest and go down from there

	repeat (nRepeats)
		shortest = least(shortest, distanceCorrected());

	return shortest;
}

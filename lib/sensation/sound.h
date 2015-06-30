/******************************************************************************
This file manages the Volume, or sound, sensor and makes it simpler to use.

Before using it, please make sure the correct #pragma is used
TODO: figure out the right #pragma to use to make a senseSound
******************************************************************************/

#define included__sound true

#ifndef included__syntax
	#include "../syntax.h"
#endif

unsigned byte soundCorrected() {
	return SensorValue[senseSound];
}

unsigned byte sound() {
	const unsigned byte nRepeats = 5;
	unsigned int total = 0;

	repeat (nRepeats)
		total += soundCorrected();

	return total / nRepeats;
}

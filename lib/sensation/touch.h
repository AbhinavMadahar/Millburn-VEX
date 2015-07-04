/******************************************************************************
This file manages the touch sensor and makes it simpler to use.

Because the touch sensor detects if it is pressed, the function to use it is
called `pressed()`

Before using it, please make sure the correct #pragma is used
TODO: figure out the right #pragma to use to make a senseTouch
******************************************************************************/
#ifndef included__touch
#define included__touch true

#include "syntax.h"

#define touched pressed

bool pressedCorrected() {
	return SensorValue[senseTouch] == 1;
}

// the touch sensor is all-or-nothing so return true if it gets touched at all
bool pressed() {
	unsigned byte nRepeats = 5;

	repeat (nRepeats)
		if pressedCorrected()
			return true;

	return false;
}

#endif

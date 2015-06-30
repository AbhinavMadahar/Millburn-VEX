/******************************************************************************
This file manages the color sensor and makes it simpler to use.

Before using it, please make sure the correct #pragma is used
TODO: figure out the right #pragma to use to make a senseColor
******************************************************************************/
#define included__color true

#ifndef included__syntax
	#include "../syntax.h"
#endif

typedef enum Color {
	grey,
	yellow,
	orange,
	red,
	blue
};

Color toColor(int reading); // TODO: find the color ranges and implement this

// XXX: do not use this outside this file- use color()
unsigned byte colorCorrected() {
	return SensorValue[senseColor];
}

// returns the average color to avoid a misreading
Color color() {
	const unsigned byte nRepeats = 5; // may not work well past 256 repeats
	unsigned int total = 0;
	repeat (nRepeats)
		total += colorCorrected();
	return toColor(total / nRepeats);
}

/******************************************************************************
These are some of the robot's measurements, as well as measurements of the
field.
******************************************************************************/
#ifndef included__measurements
#define included__measurements true

#include "syntax.h"

// TODO: add the measurements for the robot's height
const float robotHeight;
const float robotLength;
const float robotWidth;
const float robotMass;

// the field is a square, so the side lengths are all the same
const float fieldLength = 365.76; // 12 feet
const float fieldHeight; // height of the walls

const float goalHeight;
const float goalSideLength;
const float goalHypotenuse = sqrt(2 * goalSideLength * goalSideLength);

const float ballRadius;
const float ballDiameter = 2 * ballRadius;
const float ballVolume = 2 * PI * ballRadius * ballRadius;

#endif

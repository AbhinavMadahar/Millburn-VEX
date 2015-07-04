/******************************************************************************
These are some of the robot's measurements, as well as measurements of the
field.
******************************************************************************/
#ifndef included__measurements
#define included__measurements true

#include "syntax.h"

// TODO: add the measurements for the robot's height
const float robotHeight cm;
const float robotLength cm;
const float robotWidth cm;
const float robotMass kg;

// the field is a square, so the side lengths are all the same
const float fieldLength = 365.76 cm; // 12 feet
const float fieldHeight cm; // height of the walls

const float goalHeight cm;
const float goalSideLength cm;
const float goalHypotenuse = sqrt(2 * goalSideLength * goalSideLength) cm;

const float ballRadius cm;
const float ballDiameter = 2 * ballRadius cm;
const float ballVolume = 2 * PI * ballRadius * ballRadius cm;

#endif

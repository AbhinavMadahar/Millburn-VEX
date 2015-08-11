#ifndef included__angular
#define included__angular true

#include "motors.h"

// starts spinning and does not stop by itself
// spins clockwise if speed is positive, anticlockwise if negative
void spin(int speed) {
	goLeft(speed);
	goRight(-speed);
}

void spin(int speed, unsigned int duration) {
	spin(speed);
	wait1Msec(duration);
	spin(0);
}

#endif

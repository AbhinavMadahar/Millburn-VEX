#ifndef included__angular
#define included__angular true

#include "motors.h"

// turning will be implemented when the robot design is decided
void turn(const signed char deg); // turns clockwise

void left() {
	turn(-90 deg);
}
void right() {
	turn(90 deg);
}
void spin() {
	turn(360 deg);
}

#endif

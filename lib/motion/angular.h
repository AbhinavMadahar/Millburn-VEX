#define included__angular true

#ifndef included__motors
	#include "motors.h"
#endif

// turning will be implemented when the robot design is decided
void turn(const signed char deg); // turns clockwise

void left() {
	turn(-90 deg);
}
void right() {
	turn(90 deg);
}
void spin() {
	turn(180 deg);
}

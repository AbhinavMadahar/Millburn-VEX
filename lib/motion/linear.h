/******************************************************************************
This file manages linear motion, like moving a certain speed forward.
******************************************************************************/
#ifndef included__linear
#define included__linear true

#include "motors.h"
#include "../syntax.h"

// for now, these are just forward declarations
// when the robot design is decided, they will be implemented
void go(const signed char cm per sec);
void forward(const signed float cm);

void freeze() {
	go(0);
}

#endif

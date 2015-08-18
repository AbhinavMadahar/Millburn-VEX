/*******************************************************************************
This file manages time-related activities such as:
	* delaying

Unless specified otherwise, all time units are in seconds
*******************************************************************************/
#ifndef included__time
#define included__time true

#include "syntax.h"

// marked as inline to avoid making a needlessly expensive function call
void pause(float duration) { // duration will be converted to positive
	duration = abs(duration);
	wait1Msec(1000 * duration); // convert to milliseconds
}

// marked as inline to avoid making a needlessly expensive function call
void sleep() {
	// it is more efficient to just wait for as long as possible between checks
	while (true)
		pause(60);
}

#endif

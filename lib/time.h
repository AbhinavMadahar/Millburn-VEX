/*******************************************************************************
This file manages time-related activities such as:
	* delaying

Unless specified otherwise, all time units are in seconds
*******************************************************************************/

// force redefinition just in case included__time was marked as false
#undef included__time
#define included__time true

#ifndef included__syntax
	#include "syntax.h"
#endif

// marked as inline to avoid making a needlessly expensive function call
inline void pause(const float unsigned duration sec) {
	wait1Msec(1000 * duration); // convert to milliseconds
}

// marked as inline to avoid making a needlessly expensive function call
inline void sleep() {
	// it is more efficient to just wait for as long as possible between checks
	while (true)
		pause(60 sec);
}

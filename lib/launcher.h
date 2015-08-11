/*******************************************************************************
This file manages the Launcher, but NOT the Elevator.
*******************************************************************************/

#ifndef included__launcher
#define included__launcher true

#include "syntax.h"
#include "math.h"
#include "motion/motors.h"
#include "sensation/distance.h"

// TODO: define where the left and right motor pointers point
const TMotors *leftLauncherMotor;
const TMotors *rightLauncherMotor;

bool launcherUsingAuto = false;

void setLauncherSpeed(int);

// enable automatic calibration with `StartTask(launcherAutoSpeed);`
// disable it with `StopTask(launcherAutoSpeed)`
task launcherAutoSpeed() {
	launcherUsingAuto = true;

	const int waitDuration = 50; // milliseconds between recalibrations

	while (true) {
		int bestSpeed; // TODO: find out how fast it should go given distance
		setLauncherSpeed(bestSpeed);
		wait1Msec(waitDuration);
	}
}

// the speed must be in the interval [0, 100]
// overrides the autocalibration if it is used
void setLauncherSpeed(unsigned int speed) {
	if (launcherUsingAuto)
		StopTask(launcherAutoSpeed);

	speed = least(speed, 100);

	motor[*leftLauncherMotor] = speed;
	motor[*rightLauncherMotor] = speed;
}

// pass -5 to slow down by 5 percent, 15 to increase by 15 percent, etc.
void changeLauncherSpeedBy(int difference) {
	int current = motor[*leftLauncherMotor]; // left and right are the same
	setLauncherSpeed(current + difference);
}

#endif
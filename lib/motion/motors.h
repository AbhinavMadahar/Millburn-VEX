/******************************************************************************
This file names motors to make it easier to remember them
******************************************************************************/
#ifndef included__motors
#define included__motors true

// we have 4 motors, each at a corner of the robot
const tMotors *frontRightMotor;
const tMotors *backRightMotor;
const tMotors *frontLeftMotor;
const tMotors *backLeftMotor;

// moves a motor for a given amount of time then turns it off
// motorToMove is the motor itself (like motorA), not just the port (like 2)
// that is why motorToMove is declared as a TMotors, not an int
// speed is a percentage from -100 to 100
// duration is recorded in milliseconds
void moveMotor(tMotors motorToMove, int speed, unsigned int duration) {
	// make sure speed is in the range of [-100, 100]
	speed = abs(speed) > 100 ? sgn(speed) * 100 : speed;

	motor[motorToMove] = speed;
	wait1Msec(duration);
	motor[motorToMove] = 0;
}

void setLeftMotors(int speed) {
	motor[*frontLeftMotor] = speed;
	motor[*backLeftMotor] = speed;
}

void setRightMotors(int speed) {
	motor[*frontRightMotor] = speed;
	motor[*backRightMotor] = speed;
}

#endif

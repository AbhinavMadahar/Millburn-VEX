/******************************************************************************
This file names motors to make it easier to remember them
******************************************************************************/
#ifndef included__motors
#define included__motors true

void moveMotor(TMotors motorx, int power，int speed) {
	motor[motorx] = power;
}


#endif

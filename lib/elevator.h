/*******************************************************************************
This file manages the elevator but NOT the launcher
*******************************************************************************/

#ifndef included__elevator
#define included__elevator

const TMotors *upperElevatorMotor;
const TMotors *lowerElevatorMotor;

// cant set the elevator speed to negative because it would go in reverse
void setElevatorSpeed(unsigned int speed) {
	speed = least(speed, 100);

	motor[*upperElevatorMotor] = speed;
	motor[*lowerElevatorMotor] = speed;
}

// pass 5 to make it go 5% faster, -14 to make it go 14% slower, etc.
void changeElevatorSpeedBy(int difference) {
	int current = motor[*upperElevatorMotor]; // upper and lower have same speed
	setElevatorSpeed(current + difference);
}

#endif
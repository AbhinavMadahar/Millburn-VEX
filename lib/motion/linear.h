/******************************************************************************
This file manages linear motion, like moving a certain speed forward.
******************************************************************************/
#ifndef included__linear
#define included__linear true

#include "../syntax.h"
#include "motors.h"

// moves the entire robot forwards or backwards
go(int speed) {
	speed = abs(speed) > 100 ? sgn(speed) * 100 : speed;

	setRightMotors(speed);
	setLeftMotors(speed);
}

goLeft(int speed) {
	speed = abs(speed) > 100 ? sgn(speed) * 100 : speed;

	setRightMotors(speed);
	setLeftMotors(0);
}

goRight(int speed) {
	speed = abs(speed) > 100 ? sgn(speed) * 100 : speed;

	setRightMotors(0);
	setLeftMotors(speed);
}

go(int speed, unsigned int duration) {
	go(speed);
	wait1Msec(duration);
	go(0);
}

goLeft(int speed, unsigned int duration) {
	goLeft(speed);
	wait1Msec(duration);
	goLeft(0);
}

goRight(int speed, unsigned int duration) {
	goRight(speed);
	wait1Msec(duration);
	goRight(0);
}

#endif

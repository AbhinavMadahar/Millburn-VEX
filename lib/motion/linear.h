/******************************************************************************
This file manages linear motion, like moving a certain speed forward.
******************************************************************************/
#ifndef included__linear
#define included__linear true

#include "../syntax.h"
#include "motors.h"

// moves the entire robot forwards or backwards
void go(int speed) {
	speed = abs(speed) > 100 ? sgn(speed) * 100 : speed;

	setRightMotors(speed);
	setLeftMotors(speed);
}

void goLeft(int speed) {
	speed = abs(speed) > 100 ? sgn(speed) * 100 : speed;

	setRightMotors(speed);
	setLeftMotors(0);
}

void goRight(int speed) {
	speed = abs(speed) > 100 ? sgn(speed) * 100 : speed;

	setRightMotors(0);
	setLeftMotors(speed);
}

void go(int speed, unsigned int duration) {
	go(speed);
	wait1Msec(duration);
	go(0);
}

void goLeft(int speed, unsigned int duration) {
	goLeft(speed);
	wait1Msec(duration);
	goLeft(0);
}

void goRight(int speed, unsigned int duration) {
	goRight(speed);
	wait1Msec(duration);
	goRight(0);
}

#endif

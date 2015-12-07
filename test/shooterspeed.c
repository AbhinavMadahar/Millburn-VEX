#pragma config(Sensor, dgtl1,  senseDistanceFront, sensorSONAR_cm)
#pragma config(Motor,  port2,           launchBottomLeft, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           launchTopLeft, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           launchTopRight, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           launchBottomRight, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           wheelBackLeft, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           wheelFrontLeft, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           wheelFrontRight, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           wheelBackRight, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          conveyor,      tmotorVex393_HBridge, openLoop, reversed)

#include "../lib/launcher/shooter.c"
#include "../lib/launcher/conveyor.c"
#include "../lib/time.c"

task main() {
	// add all the data you collect into the Google Slides chart
	motor[reaper] = 100;
	startConveyorBelt();
	setShooterSpeed(50);
	sleep();
}

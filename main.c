#pragma config(Motor,  port2,           launchBottomLeft,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           launchTopLeft,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           launchTopRight,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           launchBottomRight,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           wheelBackLeft,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           wheelFrontLeft,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           wheelFrontRight,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           wheelBackRight,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          conveyor,      tmotorVex393_HBridge, openLoop, reversed)

#include "autonomous.c"
#include "manual.c"

task main() {
	const int autonomousDuration = 15 * 1000; // milliseconds
	const int manualDuration = (60 + 15) * 1000; // milliseconds

	startTask(autonomous);
	wait1Msec(autonomousDuration);
	stopTask(autonomous);

	startTask(manual);
	wait1Msec(manualDuration);
	stopTask(manual);
}

#include "../time.c"

void setShooterSpeed(int speed) {
	motor[launchTopLeft] = speed;
	motor[launchTopRight] = speed;
	motor[launchBottomLeft] = speed;
	motor[launchBottomRight] = speed;
}

// this is used for the autocalibrateShooterSpeed
// it allows me to figure out how fast to set the shooter
// TODO: implement shooterSpeedToReach
int shooterSpeedToReach(int speed) {
	const int speedToReachRatio = 30; // just a guess for now
	return speedToReachRatio * speed;
}

void autocalibrateShooterSpeed() {
	const int distanceToGoal = distance(senseDistanceFront);
	setShooterSpeed(shooterSpeedToReach(distanceToGoal));
}

// this task makes the robot continuously correct the shooter speed
// if it is good enough, we can add it to the manual task as an option
// that way, we can have a backup in case a driver needs some help
task automateShooterSpeed() {
	// if it is set too high the motors can't change fast enough
	const int correctionsPerSecond = 5;

	while (true) {
		autocalibrateShooterSpeed();
		pause(1000 / correctionsPerSecond);
	}

}

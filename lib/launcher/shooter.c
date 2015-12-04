#include "../time.c"

int shooterSpeed;

// when the ball hits the shooter, the motors stop
// this task keeps the motor on
task maintainShooterSpeed() {
	while (true) {
		motor[launchTopLeft] = shooterSpeed;
		motor[launchTopRight] = shooterSpeed;
		motor[launchBottomLeft] = shooterSpeed;
		motor[launchBottomRight] = shooterSpeed;
		pause(10);
	}
}

void setShooterSpeed(int speed) {
	shooterSpeed = speed;
	if (speed == 0)
		stopTask(maintainShooterSpeed);
	else
		startTask(maintainShooterSpeed);
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

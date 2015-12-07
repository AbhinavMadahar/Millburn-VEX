#include "../time.c"
#include "../math.c"

void setShooterSpeed(int shooterSpeed) {
	motor[launchTopLeft] = shooterSpeed;
	motor[launchTopRight] = shooterSpeed;
	motor[launchBottomLeft] = shooterSpeed;
	motor[launchBottomRight] = shooterSpeed;
}

// this is used for the autocalibrateShooterSpeed
// it allows the bot to calculate how fast to set the shooter to get a low goal
// TODO: implement shooterSpeedToReach
int shooterSpeedToReach(int distance) {
	const int speedToReachRatio = 30; // just a guess for now
	return speedToReachRatio * distance;
}

void autocalibrateShooterSpeed() {
	const int distanceToGoal = distance();
	setShooterSpeed(shooterSpeedToReach(distanceToGoal));
}

// it takes a while for the shooter to get to speed
// this function takes the speed it was set to and returns how fast it should be
// returns in terms of encoder counts per second
int correctShooterSpeed(int speed) {
	// TODO: find a way to model the speed given and the correct shooter speed
	return speed;
}

// returns in terms of encoder counts per second
int currentShooterSpeed() {
	// we can use the motor encoder to determine the shooter's current speed
	const int duration = 50;

	nMotorEncoder[shooterEncoder] = 0; // clear the measurement
	pause(duration);
	const int distanceSpun = nMotorEncoder[shooterEncoder];
	const int speed = distanceSpun / duration;
	return speed;
}

// the shooter takes some time to get to the correct speed
// for example, if you set the speed to 127 it takes a few seconds to get there
// this function determines if the robot is up to speed yet
bool shooterIsReady() {
	const int setSpeed = motor[launchTopLeft]; // the speed it should be
	const int correctSpeed = correctShooterSpeed(setSpeed);
	const int currentSpeed = currentShooterSpeed();
	return isAlmost(correctSpeed, currentSpeed);
}

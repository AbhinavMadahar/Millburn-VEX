#include "wheels.c"
#include "../sensation/touch.c"

const int blockLength = 61; // centimeters
const int blockDiagonalLength = sqrt(2) * blockLength; // pythagorean theorem
const float topSpeed = (3 * blockLength) / 2000.0; // robot top speed in cm/ms

// convert from the raw speed (like 127) to centimeters per millisecond (cm/ms)
float rawSpeedToCMMS(int raw) {
	// right now it is a very rough conversion process
	// I saw the robot move at 127 speed and it went about 3 blocks in 2 seconds
	// that gives us a raw calculation for the top speed right now
	// we assume that the raw speed to actual speed ratio is linear
	// moving at 67 is half of the topSpeed if we assume that the ratio is linear
	const float percentage = raw / 127; // dimensionless
	return percentage * topSpeed; // cm/ms
}

int rawSpeedFromCMMS(float cmms) {
	// just reverse the formula from rawSpeedToCMMS
	// cmms is percentage * topSpeed
	// percentage is raw / 127
	// we want to find raw, so we're given the formula:
	// cmms = raw / 127 * topSpeed
	// we already know cmms and topSpeed, so solving for raw gives us:
	// cmms / topSpeed * 127 = raw
	return cmms / topSpeed * 127;
}

// monitors the front touch button to stop the bot when it hits something
task avoidCollision() {
	const int checksPerSecond = 10;
	while (true) {
		if (isPressed()) {
			freeze();
			break;
		}
		wait1Msec(1000.0 / checksPerSecond);
	}
}

// this is the function that should be used to make linear movement
// it will manage basically everything about movement
// distance is in centimeters
// speed here is in centimeters per millisecond, unlike in setWheelSpeed
// if the distance is negative it will go backwards
// speed is a scalar in physics, so it cannot be negative
// plugging in a negative speed value will be undone and saved as the abs
void go(int distance, float speed = topSpeed) {
	speed = abs(speed);
	const int rawSpeed = sgn(distance) * rawSpeedFromCMMS(speed);
	const int momentumDuration = 1.75 * rawSpeed; // time to wait for the momentum to die
	const int moveDuration = distance / speed;

	// make the needed movement and stop
	setWheelSpeed(rawSpeed);
	pause(moveDuration);
	freeze();

	pause(momentumDuration);
}

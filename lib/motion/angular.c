#include "wheels.c"
#include "../time.c"
#include "../sensation/gyro.c"

const int defaultSpinSpeed = 40;

void spinClockwise(int speed = defaultSpinSpeed) {
	setRightWheelSpeed(-speed);
	setLeftWheelSpeed(speed);
}

void spinCounterClockwise(int speed = defaultSpinSpeed) {
	spinClockwise(-speed);
}

void spin(int speed = defaultSpinSpeed) {
	spinClockwise(speed);
}

// the spin() function just sets the robot to spin at a raw speed like 127
// this is not helpful because we don't know how fast 127 or 33 are
// this function converts the raw speed like 127 to the speed in deg/msec
float rawSpeedToDMS(int raw) {
	// I set raw speed was to 80 and put it into spin for 5 seconds
	// it ended up turning 400 degrees
	// thus, a raw speed of 80 moves it 400 degrees in 3 seconds or 133 deg/msec
	// 100 => 450 degrees in 3 seconds to get 150 deg/msec
	// assume that it's a linear ratio
	// when the raw speed increased by 20, the DMS increased by 17 deg/msec
	// thus, the ratio is 17/20
	const float ratio = 17 / 20.0;

	// that said, it still has to be a minimum value to turn the robot
	const int threshold = 25; // around where the robot didn't turn at all

	return raw > threshold ? raw * ratio : 0;
}

// the inverse of the rawSpeedToDMS
// read the rawSpeedToDMS comments before reading this function
int rawSpeedFromDMS(float dms) {
	const float ratio = 20.0 / 17;
	return dms * ratio;
}

void turn(int angle, int duration = 500) {
	freeze();

	const float speed = rawSpeedFromDMS(angle / (float) duration);

	spin(speed);
	pause(duration);

	freeze();
}

void right() {
	turn(90);
}

void left() {
	turn(-90);
}

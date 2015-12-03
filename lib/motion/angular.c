#include "wheels.c"
#include "../time.c"
#include "../math.c"
#include "../sensation/gyro.c"

const int defaultSpinSpeed = 40;

// speed is in raw speed
void spinClockwise(int speed = defaultSpinSpeed) {
	setRightWheelSpeed(-speed);
	setLeftWheelSpeed(speed);
}

// speed is in raw speed
void spinCounterClockwise(int speed = defaultSpinSpeed) {
	spinClockwise(-speed);
}

// speed is in raw speed
void spin(int speed = defaultSpinSpeed) {
	spinClockwise(speed);
}

// the spin() function just sets the robot to spin at a raw speed like 127
// this is not helpful because we don't know how fast 127 or 33 are
// this function converts the raw speed like 127 to the speed in deg/msec
float rawSpeedToDMS(int raw) {
	// I made a simple program that runs the spin() function on various speeds
	// the raw speed to degrees turned per millisecond conversion is:
	// raw => proper
	// 10 => 0
	// 20 => 0
	// 30 => 0.0133333333
	// 40 => 0.0466666667
	// 50 => 0.075
	// 60 => 0.0933333333
	// 70 => 0.115
	// 80 => 0.135
	// 90 => 0.15
	// 100 => 0.15
	// for now, we'll just make a simple approximation based on these values

	switch (approximateTo(abs(raw), 10)) {
		case 30:
			return 0.01333;
		case 40:
			return 0.048;
		case 50:
			return 0.075;
		case 60:
			return 0.0933333;
		case 70:
			return 0.115;
		case 80:
			return 0.135;
		case 90:
		case 100:
			return 0.15;
		default:
			return 0;
	}
}

// angle is in degrees clockwise
// duration is in milliseconds
void turn(int angle) {
	freeze();

	const float speed = 40 * sgn(angle);
	const float duration = angle / rawSpeedToDMS(speed);

	spin(speed);
	pause(duration);

	freeze();
	pause(200); // let the momentum die off
}

void right() {
	turn(90);
}

void left() {
	turn(-90);
}

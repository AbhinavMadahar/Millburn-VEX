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

void turn(int angle, int speed = defaultSpinSpeed) {
	freeze();

  const int initialAngle = gyro();
  while (abs(gyro() - initialAngle) < angle) {
    spin(speed);
  }

  freeze();
}

void right(int speed = defaultSpinSpeed) {
	turn(90, speed);
}

void left(int speed) {
  right(-90, -speed);
}

const float wheelRightOverLeftRatio = 0.95 / 1;

void setRightWheelSpeed(int speed) {
	motor[wheelFrontRight] = speed / wheelRightOverLeftRatio;
	motor[wheelBackRight] = speed / wheelRightOverLeftRatio;
}

void setLeftWheelSpeed(int speed) {
	motor[wheelFrontLeft] = speed;
	motor[wheelBackLeft] = speed;
}

void setWheelSpeed(int speed) {
	setLeftWheelSpeed(speed);
	setRightWheelSpeed(speed);
}

void freeze() {
	setLeftWheelSpeed(0);
	setRightWheelSpeed(0);
}

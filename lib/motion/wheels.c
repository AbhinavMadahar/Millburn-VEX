void setRightWheelSpeed(int speed) {
	motor[wheelFrontRight] = speed;
	motor[wheelBackRight] = speed;
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

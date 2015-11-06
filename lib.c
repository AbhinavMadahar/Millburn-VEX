// these are functions relevant to both the autonomous and manual control
// it assumes that the main.c file already has the motor config done in #params

const int defaultSpeedSpeed = 80;
const int blockLength = 61; // centimeters

bool isAlmost(int value, int constant) {
	if (constant == 0 && value != 0) {
		int aux = constant;
		constant = value;
		value = aux;
	}
	const float minimumAccuracy = 95.0;
	return abs((value - constant) / constant) <= (1 - minimumAccuracy / 100);
}

void setShooterSpeed(int speed) {
	motor[launchTopLeft] = speed;
	motor[launchTopRight] = speed;
	motor[launchBottomLeft] = speed;
	motor[launchBottomRight] = speed;
}

void setRightWheelSpeed(int speed) {
	motor[wheelFrontRight] = speed;
	motor[wheelBackRight] = speed;
}

void setLeftWheelSpeed(int speed) {
	motor[wheelFrontLeft] = speed;
	motor[wheelBackLeft] = speed;
}

void spinClockwise(int speed = defaultSpeedSpeed) {
	setRightWheelSpeed(-speed);
	setLeftWheelSpeed(speed);
}

void spinCounterClockwise(int speed = defaultSpeedSpeed) {
	spinClockwise(-speed);
}

void spin(int speed = defaultSpeedSpeed) {
	spinClockwise(speed);
}

void setWheelSpeed(int speed) {
	setLeftWheelSpeed(speed);
	setRightWheelSpeed(speed);
}

void freeze() {
	setLeftWheelSpeed(0);
	setRightWheelSpeed(0);
}

// finds the distance by taking the average of a bunch of different measurements
int distance(tSensors sensor = senseDistanceBack) {
	const int totalChecks = 5;
	int total = 0;
	for (int i; i < totalChecks; i++)
		total += SensorValue[sensor];
	return total / totalChecks;
}

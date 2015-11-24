// the gyroscopic sensor detects how much the robot has turned

// the gyro sensor cannot be set up via a pragma
// thus, I have to define the port it is connected to
// then, the setUpGyro() function will set it up
#define gyroPort in8

// TODO: find out if this function can be run while the robot is moving
void setUpGyro() {
	// the gyro sensor only needs to be set up once, and it takes a while to do it
	// thus, we want to avoid setting it up 2+ times because we have limited time
	// have a static variable that remembers if the gyro has been set up
	// it is static, so it gets initialised when the function first gets run
	// after the first run, it is set to true and doesn't get destroyed
	// the second time the function is called, alreadySetUp is true
	// thus, we know that there is no good reason to run the function and quit out
	static bool alreadySetUp = false;

	if (alreadySetUp)
		return;

	const int waitDurations[2] = {1500, 2500}; // TODO: find the best values

	// you have to give the sensor some time to let it set everything up
	SensorType[gyroPort] = sensorNone;
	wait1Msec(waitDurations[0]);
	SensorType[gyroPort] = sensorGyro;
	wait1Msec(waitDurations[1]);

	alreadySetUp = true;
}

// use this function instead of using the SensorValue directly
// it will take the raw measurement from the SensorValue and normalise it
float gyro() {
	// we need to return the measurement in degrees turned clockwise
	return SensorValue[gyroPort] / 10.0;
}

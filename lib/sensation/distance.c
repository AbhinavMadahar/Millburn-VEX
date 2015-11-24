// finds the distance by taking the average of a bunch of different measurements
int distance(tSensors sensor = senseDistanceFront) {
	const int totalChecks = 5;
	int total = 0;
	for (int i; i < totalChecks; i++)
		total += SensorValue[sensor];
	return total / totalChecks;
}

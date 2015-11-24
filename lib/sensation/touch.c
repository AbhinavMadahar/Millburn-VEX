int isPressed(tSensors sensor = senseTouchFront) {
	const int totalChecks = 5;
	for (int i; i < totalChecks; i++) {
		if (SensorValue[sensor] == 1) {
			return true;
		}
	}
	return false;
}

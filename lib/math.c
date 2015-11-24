bool isAlmost(int value, int constant, const float minimumAccuracy = 95.0) {
	if (constant == 0 && value != 0) {
		int aux = constant;
		constant = value;
		value = aux;
	} else if (constant == 0 && value == 0) {
		return true;
	} else {
		return abs((value - constant) / constant) <= (1 - minimumAccuracy / 100);
	}
}

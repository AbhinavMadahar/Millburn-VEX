// time is always measured in milliseconds
// that way, we can have precise measurements of time without using floats

void pause(int duration) {
	wait1Msec(abs(duration));
}

void sleep() {
	while (true)
		pause(10000);
}

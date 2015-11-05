#include "autonomous.c"
#include "manual.c"

task main() {
	const int autonomousDuration = 15 * 1000; // milliseconds
	const int manualDuration = (60 + 15) * 1000; // milliseconds

	startTask(autonomous);
	wait1Msec(autonomousDuration);
	stopTask(autonomous);

	startTask(manual);
	wait1Msec(manualDuration);
	stopTask(manual);
}

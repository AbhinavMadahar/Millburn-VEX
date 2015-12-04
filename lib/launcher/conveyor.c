#include "../lib/sensation/distance.c"

int conveyorSpeed;

// when the ball hits the shooter, the motors stop
// this task keeps the motor on
task maintainConveyorSpeed() {
	while (true) {
		motor[conveyor] = conveyorSpeed;
		pause(10);
	}
}

void setConveyorSpeed(int speed) {
	conveyorSpeed = speed;
	if (speed == 0)
		stopTask(maintainConveyorSpeed);
	else
		startTask(maintainConveyorSpeed);
}

void startConveyorBelt() {
	setConveyorSpeed(127);
}

void stopConveyorBelt() {
	setConveyorSpeed(0);
}

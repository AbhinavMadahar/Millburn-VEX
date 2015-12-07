#include "../lib/sensation/distance.c"

void setConveyorSpeed(int speed) {
	motor[conveyor] = conveyorSpeed;
}

void startConveyorBelt() {
	setConveyorSpeed(127);
}

void stopConveyorBelt() {
	setConveyorSpeed(0);
}

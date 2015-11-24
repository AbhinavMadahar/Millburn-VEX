#include "../lib/sensation/distance.c"

void setConveyorSpeed(int speed) { // just a forward-declaration for now
	motor[conveyor] = speed;
}

void startConveyorBelt() {
	setConveyorSpeed(127);
}

void stopConveyorBelt() {
	setConveyorSpeed(0);
}

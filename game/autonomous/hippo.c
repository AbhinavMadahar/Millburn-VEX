#include "../../lib/launcher/conveyor.c"
#include "../../lib/motion/angular.c"
#include "../../lib/motion/linear.c"
#include "../../lib/sensation/distance.c"

task hippo() {
	motor[reaper] = 127;
	startConveyorBelt();

	turn(45);
	const bool willTurnRight = distance() > blockDiagonalLength * 2;
	turn(-45); // go back to the starting position

	// now, from the starting position, face the goal
	go(blockLength);
	turn(willTurnRight ? 45 : -35);

	go(blockDiagonalLength * 1.5);
	go(-blockDiagonalLength * 1.35);
	stopConveyorBelt();

	go(-blockDiagonalLength * 0.75);
}

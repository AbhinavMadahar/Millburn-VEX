// this file is only supposed to be used in the main.c file
// that is why it assumes that it has the sensors all configured via pragmas

#include "../../lib/math.c"
#include "../../lib/launcher/conveyor.c"
#include "../../lib/launcher/shooter.c"
#include "../../lib/motion/angular.c"
#include "../../lib/motion/linear.c"
#include "../../lib/sensation/distance.c"

// after shooting, the shooter needs to get back up to speed
// we want to avoid putting a ball in so that the shooter can get to speed
// this task will manage the conveyor and avoid shooting balls until it's ready
task automateConveyor() {
	const int conveyorSpeed = 100;
	const int checkFrequency = 10; // Hertz
	while (true) {
		setConveyorSpeed(shooterIsReady() ? conveyorSpeed : 0);
		pause(1000 / checkFrequency);
	}
}

// this task continuously corrects the shooter speed to get in a low goal
task automateShooterSpeed() {
	// if it is set too high the motors can't change fast enough
	const int correctionsPerSecond = 5;

	while (true) {
		autocalibrateShooterSpeed();
		pause(1000 / correctionsPerSecond);
	}
}

task gunman() {
	// it takes a while to start up the shooter, so have it start first thing
	// while the shooter is starting, we can move into shooting position
	setShooterSpeed(90);

	// the robot is in an 6-by-6 grid
	// thus, we can imagine it as a smaller chessboard, and use chess vocab
	// the axis along which lie the goals has its columns demarked A to F
	// the other axis is demarked 0 to 5 because programmers use 0-indexing
	// take that Magnus Carlsen

	// each team has a color, but that's really not important
	// all we have to do for autonomous is turn the robot to the goal
	// this means we have to move forwards a block and turn 45 deg left or right
	// it should turn right if the robot starts on B0 or F1
	// it should turn left if it starts on A1 or E0
	// we have to figure out if the goal is on the left or the right
	// if there is nothing on the right of the bot, it's B0 or F1
	// if it's on B0 or F1, it should turn right
	// thus, if there is nothing on the right, it should turn right
	// and same for the left
	turn(45);
	const bool willTurnRight = distance() > blockDiagonalLength * 2;
	turn(-45); // go back to the starting position

	// now, from the starting position, face the goal
	go(blockLength);
	turn(willTurnRight ? 45 : -35);

	// start launching the balls on the way to the goal
	//startTask(automateShooterSpeed);
	//startTask(automateConveyor);

	// go in front of the goal
	go(blockDiagonalLength * 3);
}

// this file is only supposed to be used in the main.c file
// that is why it assumes that it has the sensors all configured via pragmas

#include "../lib/launcher/conveyor.c"
#include "../lib/launcher/shooter.c"
#include "../lib/motion/angular.c"
#include "../lib/motion/linear.c"
#include "../lib/sensation/distance.c"
#include "../lib/sensation/touch.c"

// this task does not manage time because the main task will do it
task autonomous() {
	// the robot is in an 6-by-6 grid
	// thus, we can imagine it as a smaller chessboard, and use chess vocab
	// the axis along which lie the goals has its columns demarked A to F
	// the other axis is demarked 0 to 5 because programmers use 0-indexing
	// take that Magnus Carlsen

	// we know for sure that all robots start in either A1, B0, E0, or F1
	// A1 and B0 belong to the blue alliance and E0 and F1 to the red
	// we do not know what color we will be
	// we can decide on which block our robot is (among the 2 in our team)
	// thus, we can pretend that we will be in either A1 or F1 for easiness
	// we can know which of the 2 blocks we started on by turning right
	// if we are on A1, the wall is to the right of the robot
	// if we are on F1, the wall is on the left of the robot
	right();
	go(blockLength);
	const bool startedOnA1 = distance() < blockLength;

	// we now know where we started, so let's go back
	go(-blockLength);
	left();

	// now, from the starting position...
	go(blockLength); // go to B1 or E1
	turn(startedOnA1 ? -45 : 45); // face our team's goal

	// we are now facing our team's goal
	// before we started autonomous, we loaded up the robot with 4 balls
	// we are now going to launch them
	startConveyorBelt();
	startTask(automateShooterSpeed);

	// we also want to pick up any balls that are in front of us, so go forwards
	go(3 * blockDiagonalLength); // go in front of the goal, but not hitting it

	// we are going to stop facing our goal, so don't want to launch balls anymore
	stopConveyorBelt();
	stopTask(automateShooterSpeed);
	setShooterSpeed(0);

	// go back to the middle of the field and face the midpoint of the goals
	go(-2 * blockDiagonalLength);
	turn(startedOnA1 ? -45 : 45);

	// drive into the wall and collect the balls in front of the robot
	// start the conveyor belt so we can store the balls
	// however, keep the shooter off until we face the goal again
	startConveyorBelt();
	go(3 * blockLength);

	// now, go back to the middle and launch the balls to the correct goal
	go(-3 * blockLength);
	turn(startedOnA1 ? -45 : 45);
	startTask(automateShooterSpeed);
	pause();
}

task testAutonomous() {
	// as the tests pass, remove them and uncomment the next one
	// the code is organised so that functions are composed of simpler functions
	// if the simplest functions work correctly, the more complex ones will work
	// thus, we test simplest first and work our way up

	// turn(-45);
	// turn(-90);
	// turn(45);

	// slowly speeds up the shooter and then slows it down
	// for (int speed = 0; speed < 127; speed++) {
	// 	setShooterSpeed(speed);
	// 	pause(10);
	// }
	// for (int speed = 127; speed >= 0; speed--) {
	// 	setShooterSpeed(speed);
	// 	pause(10);
	// }

	// now, find the relationship between the shooter speed and distance shot
	// use this relationship to implement shooterSpeedToReach(int)

	// while (true) int d = distance();

	// startConveyorBelt();

	// startTask(automateShooterSpeed);

	// while (true) {
	// 	setShooterSpeed(isPressed() ? 127 : 0);
	// }

	// at this point, it seems like lib/ has been tested correctly
	// you are now ready to test autonomous()
}

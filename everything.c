/******************************************************************************
Purpose: compile everything at once to find errors
Do not use for: actually executing
Testing status: none
******************************************************************************/

#include "lib/display.h"
#include "lib/math.h"
#include "lib/measurements.h"
#include "lib/syntax.h"
#include "lib/time.h"

#include "lib/motion/angular.h"
#include "lib/motion/linear.h"
#include "lib/motion/motors.h"

#include "lib/sensation/color.h"
#include "lib/sensation/distance.h"
#include "lib/sensation/sound.h"
#include "lib/sensation/touch.h"

task main() {} // RobotC requires a main task

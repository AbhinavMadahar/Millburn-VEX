#include "../lib/motion/wheels.c"
#include "../lib/launcher/shooter.c"

task manual()
{
	while (!(vexRT[Btn7L]))
	{

	}
	bool conveyor1Pressed = false;
	bool conveyor2Pressed = false;
	bool launcherOnPressed = false;
	bool launcherOffPressed = false;
	bool launcherSlowPressed = false;
	bool launcherFastPressed = false;
	bool reaperPressed = false;
	int reaperSpeed = 100;
	int conveyorSpeed = 127;
	int launcherSpeed = 125;


	while(true)
	{
		motor[conveyor] = conveyorSpeed;
		motor[reaper] = reaperSpeed;
		setShooterSpeed(launcherSpeed);

		//LCD Stuff
		int sonarVal = distance();
		clearLCDLine(0);																						// Clear line 1 (0) of the LCD
		clearLCDLine(1);																						// Clear line 2 (1) of the LCD
 		string s;
 		sprintf(s, "Sonar Value: %d", sonarVal);
		//Display the sonar sensor value
		displayLCDString(0, 0, s);



		//MAIN JOYSTICK: MOVING
		//nonstrafing
		if (vexRT[Btn5U] == false && vexRT[Btn6U] == false)
		{
			motor[wheelFrontRight] = vexRT[Ch2];
			motor[wheelBackRight] = vexRT[Ch2];
			motor[wheelFrontLeft] = vexRT[Ch3];
			motor[wheelBackLeft] = vexRT[Ch3];
		}
		//strafing
		else if (vexRT[Btn5U])
		{
			motor[wheelFrontRight] = 127;
			motor[wheelFrontLeft] = -127;
			motor[wheelBackLeft] = 127;
			motor[wheelBackRight] = -127;
		}
		else if (vexRT[Btn6U])
		{
			motor[wheelFrontRight] = -127;
			motor[wheelFrontLeft] = 127;
			motor[wheelBackLeft] = -127;
			motor[wheelBackRight] = 127;
		}
		//turning on conveyor belt
		if (vexRT[Btn8U] && conveyor1Pressed == false)
		{
			conveyorSpeed = 127;
			conveyor1Pressed = true;
		}
		if (!vexRT[Btn8U])
		{
			conveyor1Pressed = false;
		}
		//turning conveyor belt off
		if (vexRT[Btn8D] && conveyor2Pressed == false)
		{
			conveyorSpeed = 0;
			conveyor2Pressed = true;
		}
		if (!vexRT[Btn8D])
		{
			conveyor2Pressed = false;
		}


		//SECONDARY JOCKSTICK: EVERYTHING ELSE
		//turn on shooter
		if (vexRT[Btn7RXmtr2] && conveyor1Pressed == false)
		{
			launcherSpeed = 127;
			launcherOnPressed = true;
		}
		if (!vexRT[Btn7RXmtr2])
		{
			launcherOffPressed = false;
		}
		//turn on shooter
		if (vexRT[Btn7LXmtr2] && conveyor1Pressed == false)
		{
			launcherSpeed = 0;
			launcherOffPressed = true;
		}
		if (!vexRT[Btn7LXmtr2])
		{
			launcherOffPressed = false;
		}
		//slow down shooter
		if (vexRT[Btn5DXmtr2] && launcherSlowPressed == false)
		{
			if (launcherSpeed - 25 >= 0)
			{
				launcherSpeed -= 25;
			}
			launcherSlowPressed = true;
		}
		if (!vexRT[Btn5DXmtr2])
		{
			launcherSlowPressed = false;
		}
		//speed up shooter
		if (vexRT[Btn6DXmtr2] && launcherFastPressed == false)
		{
			if (launcherSpeed + 25 <= 125)
			{
				launcherSpeed += 25;
			}
			launcherFastPressed = true;
		}
		if (!vexRT[Btn6DXmtr2])
		{
			launcherFastPressed = false;
		}
		//for moving the conveyor belt a little bit
		if ((vexRT[Ch2Xmtr2] > 25 || vexRT[Ch2Xmtr2] < -25))
		{
			conveyorSpeed = vexRT[Ch2Xmtr2];
		}
		//reverse reaper
		if (vexRT[Btn7UXmtr2] && reaperPressed == false)
		{
			if (reaperSpeed == -100)
			{
				reaperSpeed = 100;
			}
			else
			{
				reaperSpeed = -100;
			}
			reaperPressed = true;
		}
		if (!vexRT[Btn7UXmtr2])
		{
			reaperPressed = false;
		}
		//turning on conveyor belt
		if (vexRT[Btn8UXmtr2] && conveyor1Pressed == false)
		{
			conveyorSpeed = 127;
			conveyor1Pressed = true;
		}
		if (!vexRT[Btn8UXmtr2])
		{
			conveyor1Pressed = false;
		}
		//turning conveyor belt off
		if (vexRT[Btn8DXmtr2] && conveyor2Pressed == false)
		{
			conveyorSpeed = 0;
			conveyor2Pressed = true;
		}
		if (!vexRT[Btn8DXmtr2])
		{
			conveyor2Pressed = false;
		}

	}
}

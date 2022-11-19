int x;
int prevElbowAngle =0;
int currElbowAngle =0;
int sleepElbow =2;

int count = 0;
int starter;
task counter()
{
starter =0;
	while(true)
	{
		displayString(10,"%i",count);
		wait1Msec(1000);
		count = count+1;
		//displayString(10,"  ");
	}
}

//task sleepRobot()
//{

//	while(true)
//	{
//		if(sleepElbow==1)
//		{
//			displayString(11,"ReturnToDefault");
//			//stopTask(counter);
//			starter = 0;
//		}else if(sleepElbow==0)
//		{
//			for(starter =0; starter < 1; starter++)
//			{
//	//			startTask(counter);
//			}
//		}else if(starter == 1)
//		{}
//		displayString(11,"active");
//	}
//}



task moveArm()
{
	while(true)
	{
		sleepElbow = 0;
		x=time100[T1];
		currElbowAngle =nMotorEncoder(motorA);
		displayString(5,"%i",currElbowAngle);
		displayString(6,"%i",x);
		if(currElbowAngle == prevElbowAngle)
		{
			displayString(7,"Same Angle");
			}else{
			displayString(7,"Diff Angle");
			displayString(8," No Sleep");
			clearTimer(T1);
			while(starter == 0)
			{
				startTask(counter);
				starter = 1;
			}

		}

		wait1Msec(100);
		if(time100[T1]>=40)
		{
			displayString(8,"Sleep");
			sleepElbow = 1;
			while(starter  == 1)
			{
				stopTask(counter);
				starter = 0;
			}

			displayString(9,"%i", sleepElbow);
			//	displayString(9,"Sleep:"  , "%i", sleepElbow);
		}

		prevElbowAngle=currElbowAngle;
	}

}
task main()
{

	if(getMotorBrakeMode(motorA) != motorCoast)
	{
		setMotorBrakeMode(motorA, motorCoast);
	}
	displayString(3,"Coast");

	startTask(moveArm);
	wait1Msec(200);
	clearTimer(T1);
	startTask(counter);
	wait1Msec(3000);
	//	startTask(sleepRobot);
	while(true)
	{
		wait1Msec(200);                                 // Allow for a short wait, freeing up the CPU for other tasks.
		displayCenteredBigTextLine(0, "TASK M");     // Display that Main is running.
	}
	return;
}

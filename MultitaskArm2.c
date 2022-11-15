/*

Names: Koketso G. , Joshua A. , Ishaan K. , Maximilian E-F.
Date: November 15th, 2022
Code Version: 2
Project: Robot Reflection
Purpose: Integrating multitasking to allow for multiple functions
to occur simultaneously

Attributions:

- RobotC multitasking example program
*/






task TOne()
{
	//Loop continously
	while(true)
	{
		//If button is active
		while(SensorValue[S1]==1)
		{
			//Degbugging
			displayString(6,"touch");

			//Close gripper
			motor[motorD] = -5;
			//Debug
			displayString(8,"%f",nMotorEncoder(motorD));
			//Wait some time so no overloading occurs
			wait1Msec(50);
		}
		//If gripper sensor is not active, then return to opened state
		//While gripper is not fully open
		while(nMotorEncoder(motorD)<0){
			//Debug
			displayString(6," No touch");
			//open gripper
			motor[motorD] = 5;
			//Debug
			displayString(8,"%f",nMotorEncoder(motorD));
			wait1Msec(50);
		}
		//Otherwise if the gripper is at the fully opened angle, stop it from opening any further
		motor[motorD] = 0;
	}
}


task TTwo()
{
	//Loop continously
	while(true)
	{
			//If the human arm is at a larger angle then the robot one
		if(nMotorEncoder(motorA)>nMotorEncoder(motorC)){
			//Rotate the robot arm about the elbow motor to align it with the human arm
			motor[motorC] = 20;
			//While the robot arm is being aligned with the human arm, gear ratio considered
			while ((nMotorEncoder(motorC))<((nMotorEncoder(motorA))*2))
			{
				displayString(5,"%f",nMotorEncoder(motorA));
			}
			//Once it is aligned, stop moving the arm
			motor[motorC] = 0;

		}else
		{
			//Otherwise, the robot arm angle must be smaller than the human arm, so rotate it the other way
			motor[motorC] = -20;
			//While the robot arm is being aligned with the human arm, gear ratio considered
			while (nMotorEncoder(motorA)< (nMotorEncoder(motorC)/2))
			{}
			//Once it is aligned, stop moving the arm
			motor[motorC] = 0;
		}
	}
}

	task main()
	{
		//Initialize sensors and variales
		SensorType[S1] = sensorEV3_Touch;
		wait1Msec(50);
		nMotorEncoder(motorD) = 0;
		displayString(8,"%f",nMotorEncoder(motorD));
		nMotorEncoder(motorA)=0;
		nMotorEncoder(motorC)=0;

		/*If the elbow motor is not in coast mode, set it to coast mode
			This is important because the elbow motor should have no
			ressitance when being rotated. It serves as a sensor in this case.
		*/
		if(getMotorBrakeMode(motorA) != motorCoast)
		{
			setMotorBrakeMode(motorA, motorCoast);
		}
		//Debug
		displayString(3,"Coast");


		//Run the other tasks simultaneously
		startTask(TOne);
		startTask(TTwo);

		while(true)
		{
			wait1Msec(300);                                 // Allow for a short wait, freeing up the CPU for other tasks.

			displayCenteredBigTextLine(0, "TASK M");     // Display that Main is running.
		}
		return;
	}

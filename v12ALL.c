#pragma config(Sensor, S1,     HTAC,           sensorI2CCustom)
#include "C:\Program Files (x86)\Robomatter Inc\ROBOTC Development Environment 4.X\Sample Programs\EV3\3rd Party Driver Library\include\hitechnic-accelerometer.h"
// Create struct to hold sensor data
tHTAC accelerometer;

//Shoulder Y
task updateAngleShoulderY()
{
	//Loop continously
	while(true)
	{
		eraseDisplay();
		float angle = getGyroDegrees(S2);
		displayTextLine(7,"%f",angle);
		displayString(8,"%f",nMotorEncoder(motorB));

		wait1Msec(100);
		if(((angle*-1))>(nMotorEncoder(motorB)))
		{
			motor[motorB] = 5;
			displayString(9,"right");
		}
		else if ((angle*-1)<(nMotorEncoder(motorB)))
		{
			motor[motorB] = -5;
			displayString(9,"left");
			}else{
			motor[motorB] = 0;
		}
	}
	wait1Msec(100);
}

// Shoulder X
task updateAngleShoulderX()
{

	//Loop continously
	while(true)
	{
		// Read all of the axes at once
		if (!readSensor(&accelerometer))
		{
			displayTextLine(4, "ERROR!!");
			wait1Msec(2000);
			stopAllTasks();
		}
		if(((accelerometer.x)/2*4)>(nMotorEncoder(motorC)))
		{
			motor[motorC] = 20;
			displayString(8,"%f",nMotorEncoder(motorC));
			displayString(9,"lower");
		}
		else if(((accelerometer.x)/2*4)<(nMotorEncoder(motorC)))
		{
			motor[motorC] = -20;
		}
		else{
			motor[motorC] = 0;
		}
		wait1Msec(100);
	}

}

// Elbow
task updateAngleElbow()
{
	while(true)
	{
		if(nMotorEncoder(motorA)>nMotorEncoder(motorD)){
			motor[motorD] = 20;
			while ((nMotorEncoder(motorD))<((nMotorEncoder(motorA))*2))
			{
				displayString(5,"%f",nMotorEncoder(motorA));
			}
			motor[motorD] = 0;

		}else
		{
			motor[motorD] = -20;
			while (nMotorEncoder(motorA)<=nMotorEncoder(motorD)/2)
			{}
			motor[motorD] = 0;
		}
	}
}

// Gripper

task updateGripper()
{
	//Loop continously
	while(true)
	{
		//If button is active
		while(SensorValue[S3]==1)
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

// Sleep Robot
void sleepRobot()
{

}

void returnToRestPosition()
{

}





task main()
{
	// Initialise and ctHTAC accelerometer;onfigure struct and port
	initSensor(&accelerometer, S1);
	SensorType[S2] = sensorEV3_Gyro;
	wait1Msec(50);
	SensorMode[S2] = modeEV3Gyro_Calibration;
	wait1Msec(50);
	SensorMode[S2] = modeEV3Gyro_RateAndAngle;
	wait1Msec(50);
	//displayCenteredTextLine(0, "HiTechnic");
	//displayCenteredBigTextLine(1, "Accel");
	//displayCenteredTextLine(3, "Test 1");
	//displayCenteredTextLine(5, "Connect sensor");
	//displayCenteredTextLine(6, "to S1");
	//	sleep(2000);
	nMotorEncoder(motorC) = 0;
	nMotorEncoder(motorB) = 0;
	nMotorEncoder(motorA) = 0;
	nMotorEncoder(motorD) = 0;
	startTask(updateAngleShoulderY);
	wait1Msec(500);
	startTask(updateAngleShoulderX);
	wait1Msec(500);
	startTask(updateAngleElbow);
	wait1Msec(500);
	startTask(updateGripper);
	//startTask(TOne);
	if(getMotorBrakeMode(motorD) != motorCoast)
	{
		setMotorBrakeMode(motorA, motorCoast);
	}
	displayString(3,"Coast");


	while(true)
	{
		wait1Msec(200);                                 // Allow for a short wait, freeing up the CPU for other tasks.
		displayCenteredBigTextLine(0, "TASK M");     // Display that Main is running.
	}
	return;
}

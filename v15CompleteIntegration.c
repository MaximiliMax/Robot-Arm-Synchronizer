#pragma config(Sensor, S2,     HTAC,           sensorI2CCustom)
#include "C:\Program Files (x86)\Robomatter Inc\ROBOTC Development Environment 4.X\Sample Programs\EV3\3rd Party Driver Library\include\hitechnic-accelerometer.h"
#include "mindsensors-motormux.h"
// Create struct to hold sensor data
tHTAC accelerometer;


//Functions



task exitProgram()
{
displayString(1,"idle");
while(!getButtonPress(buttonEnter))
{}
while(getButtonPress(buttonEnter))
{}
displayString(1,"Pressed");
	stopAllTasks();
}








//Shoulder Y
task updateAngleShoulderY()
{
	float angle;
	while(true)
	{
		angle = getGyroDegrees(S3);
//	eraseDisplay();
//	displayString(2,"Angle Y");
//	displayString(3,"%f",((angleY)));
//	displayString(4,"Shoulder Encoder Y");
//	displayString(5,"%f",nMotorEncoder[motorB])
//	displayTextLine(7,"%f",angle);
//	displayString(8,"%f",nMotorEncoder(motorB));
		wait1Msec(100);
		if(((angle*-1))>(nMotorEncoder[motorA]+3))
		{
			motor[motorA] = 7;
			displayString(9,"right");
		}
		else if (((angle*-1))<(nMotorEncoder[motorA]-3))
		{
			motor[motorA] = -7;
			displayString(9,"left");
			}else{
			motor[motorA] = 0;
		}
	}
	wait1Msec(100);
}









// Shoulder X
task updateAngleShoulderX()
{

	while(true)
	{
		displayString(7,"check");
			displayString(8,"%f",accelerometer.x);
		// Read all of the axes at once
		if (!readSensor(&accelerometer))
		{
			displayTextLine(4, "ERROR!!");
			wait1Msec(2000);
			stopAllTasks();
		}
		//displayString(6,"Acc y");
		//displayString(7,"%f",(accelerometer.y)*-1);
		//displayString(8,"Acc X");
displayString(9,"check2");

		if(((accelerometer.x)/2*4)>(nMotorEncoder[motorB]+5))
		{
			motor[motorB] = 20;
		}
		else if(((accelerometer.x)/2*4)<(nMotorEncoder[motorB]-5))
		{
			motor[motorB] = -20;
		}
		else{
			motor[motorB] = 0;
		}
		wait1Msec(100);
	}

}













// Elbow
task updateAngleElbow()
{
	int humanElbowAngle;
	int robotElbowAngle;
	while(true)
	{
	humanElbowAngle = MSMMotorEncoder(mmotor_S1_1);
	robotElbowAngle = nMotorEncoder(motorC);
	displayString(7,"%f",MSMMotorEncoder(mmotor_S1_1));
	displayString(8,"%f",nMotorEncoder(motorC));
		if((humanElbowAngle*4)>(robotElbowAngle+10))
		{
			motor[motorC] = 20;
		}else if((humanElbowAngle*4)<(robotElbowAngle-10))
		{
			motor[motorC] = -20;
		}else
		{
			motor[motorC] = 0;

		}
	wait1Msec(100);
	}
}













// Gripper
task updateGripper()
{
	while(true)
	{
		//If button is active
		while(SensorValue[S4]==1)
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

















task main()
{
	initSensor(&accelerometer, S2);
	SensorType[S3] = sensorEV3_Gyro;
	wait1Msec(50);
	SensorMode[S3] = modeEV3Gyro_Calibration;
	wait1Msec(50);
	SensorMode[S3] = modeEV3Gyro_RateAndAngle;
	wait1Msec(50);
	SensorType[S1] = sensorI2CCustom;
	MSMMUXinit();
	nMotorEncoder(motorC) = 0;
	nMotorEncoder(motorB) = 0;
	nMotorEncoder(motorA) = 0;
	nMotorEncoder(motorD) = 0;
	MSMMotorEncoderReset(mmotor_S1_1);
	startTask(updateAngleShoulderY);
	wait1Msec(500);
	startTask(updateAngleShoulderX);
	wait1Msec(500);
	startTask(exitProgram);
	wait1Msec(500);
	startTask(updateAngleElbow);
	wait1Msec(500);
	startTask(updateGripper);
	//startTask(TOne);
//	MSMotorStop(mmotor_S1_1);
	//MSMotorStop(mmotor_S1_2);
	//if(getMotorBrakeMode(mmotor_S1_1) != motorCoast)
	//{
	//	setMotorBrakeMode(mmotor_S1_1, motorCoast);
	//}
	displayString(3,"Coast");

	while(true)
	{
		wait1Msec(300);                                 // Allow for a short wait, freeing up the CPU for other tasks.
		//displayCenteredBigTextLine(0, "TASK M");     // Display that Main is running.
	}
	return;


}

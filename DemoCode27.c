/*
The program assumes common.h, mindsensors-ev3smux.h and UW_sensorMux.c are in the same directory
as this file.
*/
#pragma config(Sensor, S2,     HTAC,           sensorI2CCustom)
#include "C:\Program Files (x86)\Robomatter Inc\ROBOTC Development Environment 4.X\Sample Programs\EV3\3rd Party Driver Library\include\hitechnic-accelerometer.h"
#include "mindsensors-motormux.h"
#include "UW_sensorMux.c"
// Create struct to hold sensor data
tHTAC accelerometer;


// Configure your sensor channel type by calling initSensorMux.  The following are available:
// colorReflectedLight
// colorAmbientLight
// colorMeasureColor
// gyroAngle
// gyroRate
// sonarCM
// sonarInches
// sonarPresence
// touchStateBump

/*
msensor specifies sensor port, and channel
e.g. msensor_S1_1 is sensor port S1 and channel C1
*/

/*
The example program assumes the sensor mux is plugged into S1, and the channels are:
touch sensor, ultrasonic sensor, and gyro
*/





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
	wait1Msec(50);
}




// Shoulder X
task updateAngleShoulderX()
{

	while(true)
	{
//		displayString(7,"check");
		//		displayString(8,"%f",accelerometer.x);
		// Read all of the axes at once
		if (!readSensor(&accelerometer))
		{
			displayTextLine(4, "ERROR!!");
			wait1Msec(2000);
			stopAllTasks();
		}
	//	displayString(9,"check2");
	//	displayString(10,"%f", accelerometer.x);
		if(((accelerometer.x)/2*6)>(nMotorEncoder[motorB]+5))
		{
			motor[motorB] = 20;
		}
		else if(((accelerometer.x)/2*6)<(nMotorEncoder[motorB]-5))
		{
			motor[motorB] = -20;
		}
		else{
			motor[motorB] = 0;
		}
		wait1Msec(50);
	}

}



// Elbow
task updateAngleElbow()
{
	int humanElbowAngle;
	int robotElbowAngle;
	while(true)
	{
		humanElbowAngle = MSMMotorEncoder(mmotor_S4_1);
		robotElbowAngle = nMotorEncoder(motorC);
		//displayString(7,"%f",MSMMotorEncoder(mmotor_S4_1));
		//displayString(8,"%f",nMotorEncoder(motorC));
		if((humanElbowAngle*8)>(robotElbowAngle+10))
		{
			motor[motorC] = 10;
		}
		else if((humanElbowAngle*8)<(robotElbowAngle-10))
		{
			motor[motorC] = -10;
		}
		else
		{
			motor[motorC] = 0;

		}
		wait1Msec(50);
	}
}

int hand;
task updateGripper()
{
	while(true)
	{
		if (!initSensorMux(msensor_S1_3, touchStateBump))
			return;
		wait1Msec(50);
		if (!initSensorMux(msensor_S1_2, sonarCM))
		return;
		wait1Msec(50);

		hand = readMuxSensor(msensor_S1_2);
		displayBigTextLine(8,"IDLE");
		while(readMuxSensor(msensor_S1_3)==1)
		{
//			displayString(6,"touch");
			motor[motorD] = -5;
	//		displayString(8,"%f",nMotorEncoder(motorD));
			wait1Msec(50);
		}
		while(nMotorEncoder(motorD)<0){
	//		displayString(6," No touch");
			motor[motorD] = 5;
	//		displayString(8,"%f",nMotorEncoder(motorD));
			wait1Msec(50);
		}
		motor[motorD] = 0;
	}
}

void config()
{

	SensorType[S3] = sensorEV3_Gyro;
	wait1Msec(50);
	SensorMode[S3] = modeEV3Gyro_Calibration;
	wait1Msec(50);
	SensorMode[S3] = modeEV3Gyro_RateAndAngle;
	wait1Msec(50);
	initSensor(&accelerometer, S2);
	wait1Msec(100);



	nMotorEncoder(motorC) = 0;
	nMotorEncoder(motorB) = 0;
	nMotorEncoder(motorA) = 0;
	nMotorEncoder(motorD) = 0;
	SensorType[S4] = sensorI2CCustom;
	MSMMUXinit();
	wait1Msec(200);
	MSMMotorEncoderReset(mmotor_S4_1);


	// Configure sensor port
	SensorType[S1] = sensorEV3_GenericI2C;
	wait1Msec(500);

}
task main()
{
config();

	startTask(updateGripper);
	wait1Msec(500);

	while(hand!=255)
{}



//if(hand==255)



	startTask(updateAngleShoulderX);
	wait1Msec(100);

	startTask(updateAngleElbow);
	wait1Msec(50);
	startTask(updateAngleShoulderY);
	wait1Msec(200);

	while(hand==255)
	{
		wait1Msec(500);                                 // Allow for a short wait, freeing up the CPU for other tasks.
		//displayCenteredBigTextLine(0, "TASK M");     // Display that Main is running.
	}
	stopTask(updateGripper);
	stopTask(updateAngleShoulderX);
	stopTask(updateAngleElbow);
	stopTask(updateAngleShoulderY);


	motor[motorA]=0;
	motor[motorB]=0;
	motor[motorC]=0;

	if(nMotorEncoder[motorA]<0)
	{
		motor[motorA]=20;
		while(nMotorEncoder[motorA]<0)
		{}
    motor[motorA]=0;
	}
	else
	{
		motor[motorA]=-20;
		while(nMotorEncoder[motorA]>0)
		{}
    motor[motorA]=0;
	}
	while(nMotorEncoder[motorB]>0)
	{
		motor[motorB]=-20;
	}
	motor[motorB]=0;

	while(nMotorEncoder[motorC]>0)
	{
		motor[motorC]=-20;
	}
	motor[motorC]=0;

}

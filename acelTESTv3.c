#pragma config(Sensor, S1,     HTAC,           sensorI2CCustom)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/**
* hitechnic-accelerometer.h provides an API for the HiTechnic Acceleration Sensor.  This program
* demonstrates how to use that API.
*
* Changelog:
* - 0.1: Initial release
* - 0.2: Make use of new API calls
* - 0.3: Better comments
* - 0.4: Fixed display line (thanks Dave)
* - 0.5: Removed single axis functions, they're no longer in the driver\n
*        Removed common.h from includes
*
* Credits:
* - Big thanks to HiTechnic for providing me with the hardware necessary to write and test this.
*
* License: You may use this code as you wish, provided you give credit where it's due.
*
* THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 4.10 AND HIGHER

* Xander Soldaat (xander_at_botbench.com)
* 20 February 2011
* version 0.5
*/


#include "C:\Program Files (x86)\Robomatter Inc\ROBOTC Development Environment 4.X\Sample Programs\EV3\3rd Party Driver Library\include\hitechnic-accelerometer.h"

/*
task TThree()
{
	float zangle = accelerometer.z;
	nMotorEncoder(motorB) = 0;
	displayString(9,"TThree");
	//Loop continously

		//displayTextLine(0,"HTAC Test 1");
		//displayTextLine(2, "   X    Y    Z");

		//displayTextLine(3, "%4d %4d %4d", accelerometer.x, accelerometer.y, accelerometer.z);
		//// Alternatively, you can read them like this:
		//displayTextLine(4, "%4d %4d %4d", accelerometer.axes[0], accelerometer.axes[1], accelerometer.axes[2]);
		//displayTextLine(4,"%f",((accelerometer.x)/2));
		//displayTextLine(6,"%f",nMotorEncoder(motorB));
		sleep(100);


		while (((zangle))>(nMotorEncoder(motorB)))
		{
			motor[motorB] = 20;
			displayString(8,"%f",nMotorEncoder(motorB));
			displayString(9,"lower");
		}
		while (((zangle))< (nMotorEncoder(motorB)))
		{
			motor[motorB] = -20;
			displayString(9,"higher");
		}
		motor[motorB] = 0;
	wait1Msec(100);
}
*/

task TTwo()
{
	 displayCenteredTextLine(7, "TTWO");
	nMotorEncoder(motorC) = 0;
	//Loop continously
			// Create struct to hold sensor data
tHTAC accelerometer;
	float xangle = accelerometer.x;
 displayCenteredTextLine(9,"%f", xangle);
		//  displayTextLine(0,"HTAC Test 1");
		//  displayTextLine(2, "   X    Y    Z");

		//  displayTextLine(3, "%4d %4d %4d", accelerometer.x, accelerometer.y, accelerometer.z);
		//// Alternatively, you can read them like this:
		//  displayTextLine(4, "%4d %4d %4d", accelerometer.axes[0], accelerometer.axes[1], accelerometer.axes[2]);
		//  displayTextLine(4,"%f",((accelerometer.x)/2));
		//  displayTextLine(6,"%f",nMotorEncoder(motorC));

		sleep(100);
		while (((xangle)/2*4)>(nMotorEncoder(motorC)))
		{
			motor[motorC] = 20;
			displayString(8,"%f",nMotorEncoder(motorC));
			displayString(9,"lower");
		}
		while (((xangle)/2*4)< (nMotorEncoder(motorC)))
		{
			motor[motorC] = -20;
			displayString(9,"higher");
		}
		motor[motorC] = 0;
	wait1Msec(100);
}

task main () {

	// Create struct to hold sensor data
tHTAC accelerometer;
  initSensor(&accelerometer, S1);
  displayCenteredTextLine(0, "HiTechnic");
  displayCenteredBigTextLine(1, "Accel");
  displayCenteredTextLine(3, "Test 1");
  displayCenteredTextLine(5, "Connect sensor");
  displayCenteredTextLine(6, "to S1");
  sleep(2000);
   nMotorEncoder(motorC) = 0;
 		nMotorEncoder(motorB) = 0;
startTask(TTwo);
wait1Msec(2000);
//startTask(TThree);
//  playSound(soundBeepBeep);
//  while(bSoundActive) sleep(1);


}

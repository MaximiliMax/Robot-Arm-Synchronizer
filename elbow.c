task main()
{
	SensorType[S1] = sensorEV3_Touch;
	wait1Msec(50);
	nMotorEncoder(motorD) = 0;
	displayString(8,"%f",nMotorEncoder(motorD));

	nMotorEncoder(motorA)=0;
	nMotorEncoder(motorC)=0;
	if(getMotorBrakeMode(motorA) != motorCoast)
	{
		setMotorBrakeMode(motorA, motorCoast);
	}
	displayString(3,"Coast");


	while(1==1)
	{


		//Hand


		while(SensorValue[S1]==1)
		{

			displayString(6,"touch");
			motor[motorD] = -5;
			displayString(8,"%f",nMotorEncoder(motorD));
			wait1Msec(100);
		}
		while(nMotorEncoder(motorD)<0){
			displayString(6," No touch");
			motor[motorD] = 5;
			displayString(8,"%f",nMotorEncoder(motorD));
			wait1Msec(100);
		}
		motor[motorD] = 0;


		while(getButtonPress(buttonRight))
		{
			motor[motorB] = -15;
		}
		motor[motorB] = 0;

		while(getButtonPress(buttonLeft))
		{
			motor[motorB] = 15;
		}
		motor[motorB] = 0;

		//Elbow




		if(nMotorEncoder(motorA)>nMotorEncoder(motorC)){
			motor[motorC] = 20;
			while ((nMotorEncoder(motorC))<((nMotorEncoder(motorA))*2))
			{
				displayString(5,"%f",nMotorEncoder(motorA));
			}
			motor[motorC] = 0;

		}else
		{
			motor[motorC] = -20;
			while (nMotorEncoder(motorA)< (nMotorEncoder(motorC)/2))
			{}
			motor[motorC] = 0;



		}

	}


}

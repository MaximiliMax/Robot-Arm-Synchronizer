# Robot Arm Syncgronizer
![Hero_Shot](https://user-images.githubusercontent.com/69880859/214206669-7a899684-68eb-4cd2-ad90-e297770b5580.jpg)
Project Purpose: Translate human arm motion to a robot arm
University MTE 100 - MTE 121 Course Project

This project was made possible by the works of Xander Soldaat at Bot Bench which can be found in the link below:
https://github.com/botbench/robotcdriversuite

![20221202_045158](https://user-images.githubusercontent.com/69880859/214206731-0ada67b8-57a4-4f63-b3bc-e4304852e3de.jpg)
This project aimed to create a device that allowed the operation of a robot arm using the natural movements of a human arm. The 3 degrees of freedom arm is controlled by unique wearable sensors.



# Wearable Sensor Setup

## Hand Controller
![hand shot](https://user-images.githubusercontent.com/69880859/214206983-d9e0ca70-df66-4dce-b4d5-ccbf8f15b145.jpg)
- Responsible for controlling the gripper
- Arm only operates when hand is in device using ultrasound sensor
   ^ This was pretty cool to see because the robot is in sleep mode until the user puts their hand in the hand controller and it springs to life and becomes very responsive. A very cool feeling!
- Another cool part is when the user decides to put the robot to sleep, and takes their hand out, the robot returns to a default rest position automatically. Also cool to see in action, similar to an automated robot arm.

## Elbow Controller
![20221202_070751](https://user-images.githubusercontent.com/69880859/214206743-221d6c90-0c2a-488c-ad58-39134511b6f6.jpg)
- Responsible for controllin the elbow flexion in the robot arm
- Required the use of an external power supply

## Gyro - Shoulder Yaw
![20221202_070926](https://user-images.githubusercontent.com/69880859/214206764-7d07df9d-23f4-4035-82e2-367859ae875b.jpg)
- Responsible for rotating the shoulder joint left to right
- After having consistent difficulty with the accelerometer, it was discovered that the component was not suitable for multi axis rotaiton measuring. Instead, we had to adjust and included a gyro that lies fixed to the table.

## Accelerometer - Shoulder Pitch
![20221202_072401](https://user-images.githubusercontent.com/69880859/214206773-774e6d42-41d8-40cf-9684-6eefc3411d50.jpg)
- Responsible for rotating the shoulder up and down

## Demo Angle 1
https://user-images.githubusercontent.com/69880859/214205848-4d4ff07f-d88f-48ee-845a-955de6202581.MOV

## Demo Angle 2
https://user-images.githubusercontent.com/69880859/214205902-2f82448c-034f-4907-8ba6-2df5b6a2bfcd.MOV

*Note it was pretty cool controlling the robot, at times it really felt like my arm was one with the robot arm 😅

Although the project met the requirements and the demo was really fun, I wish we spent more time recording the projects functionality. This is one of the many lessons I have learned in this stressful yet fun project! Shoutout to the group members and look forward to what the next project entails!


# Robot Arm Synchronizer

## Demo Angle 1


https://github.com/MaximiliMax/Robot-Arm-Synchronizer/assets/69880859/3da54aeb-7bdc-4039-940b-57b35099fc13



## Demo Angle 2


https://github.com/MaximiliMax/Robot-Arm-Synchronizer/assets/69880859/2ebdbe2d-c5b7-4bd8-ba1f-65f45127b169


![Hero_Shot](https://user-images.githubusercontent.com/69880859/214206669-7a899684-68eb-4cd2-ad90-e297770b5580.jpg)
Project Purpose: Translate human arm motion to a robot arm

University First Year | MTE 100 & MTE 121 Course Project

Acknowledgements:
This project was made possible by the excellent work of Xander Soldaat at Bot Bench which can be found in the link below:
https://github.com/botbench/robotcdriversuite
Thank you very much!

# Brief Description
This course project was an opportunity to do something intresting yet challenging - an opportunity to learn and grow. With an ambitious mindset, our group decided to attempt to create a robotic arm that mimics the natural movements of a human arm. It is aimed towards the application of remote controlled robot arms to replace human workers in hazardous environments or perhaps can be used in remote surgical operations (with many imoprovements of course!). This project also provided an insight into how we can effectively use robotics in conjuction with the human body in a comfortable and non-intrusive manner. After many limitations, countless challenges, and whole lotta hard work, I am proud to present what could be seen as a small step towards a future with robotics better utilizing natural human biomechanics.


![20221202_045158](https://user-images.githubusercontent.com/69880859/214206731-0ada67b8-57a4-4f63-b3bc-e4304852e3de.jpg)
- Includes: multi-axis shoudler joint, elbow joint, and gripper
- Some features include: Live human operation, Rest state, Automated default position return, relatively high precision for all the limitations with the project assignment details

- Limitations included: Short time constraint, very small broke student budget, was only allowed to use Lego EV3/NXT and Tetrix, motor mechanical capabilities, sensor/motor limited ports, etc.

# Wearable Sensor Setup

## Hand Controller
![hand shot](https://user-images.githubusercontent.com/69880859/214206983-d9e0ca70-df66-4dce-b4d5-ccbf8f15b145.jpg)
- Responsible for controlling the gripper
- Arm only operates when hand is in device using ultrasound sensor. This was pretty cool to see because the robot is in sleep mode until the user puts their hand in the hand controller and it springs to life and becomes very responsive. A very thrilling feeling!
- Another exciting aspect is the auto-return function. When the user decides to put the robot to sleep, they may choose to simply take their hand out and the robot will return to a default rest position automatically. Also cool to see in action!

## Elbow Controller
![20221202_070751](https://user-images.githubusercontent.com/69880859/214206743-221d6c90-0c2a-488c-ad58-39134511b6f6.jpg)
- Responsible for controlling the elbow flexion in the robot arm
- Required the use of an external power supply

## Gyro - Shoulder Yaw Controller
![20221202_070926](https://user-images.githubusercontent.com/69880859/214206764-7d07df9d-23f4-4035-82e2-367859ae875b.jpg)
- Responsible for rotating the shoulder joint left to right
- After having consistent difficulty with the accelerometer, it was discovered that the component was not suitable for accurately measuring multi axis rotation over extended periods of time. Instead, we had to adapt and decided to include a stationary gyro that lies parrallel and fixed to a table. Rotating this component would rotate the shoulder left to right.

## Accelerometer - Shoulder Pitch Controller
![20221202_072401](https://user-images.githubusercontent.com/69880859/214206773-774e6d42-41d8-40cf-9684-6eefc3411d50.jpg)
- Responsible for rotating the shoulder up and down



Note: Although the demo was a little janky (pulled an all nighter prior), it was pretty cool controlling the robot, at times it really felt like my arm was one with the robot arm 😅.

Although the project met the requirements and the demo was really fun, I wish we spent more time recording the projects functionality and showcasing its ability in a better manner. It is great to have a cool project but the presentation of such project is just as important as the idea. This is one of the many lessons I have learned in this stressful yet rewarding project! Shoutout to the group members and look forward to what the next project entails! Hope you found this project cool too!


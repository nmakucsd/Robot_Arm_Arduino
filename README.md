# Robot_Arm_Arduino
This project uses an Arduino to take input from flex sensors attached to the fingers of a glove to control a robotic arm's fingers powered by five servos.

Each flex sensor acts like a potentiometer, supplying more current the more a sensor is bent. Each sensor is attached to the back of a person's fingers. As the person bends each individual finger, the corresponding degree of bendage supplies a unique input value to the Arduino.

The Arduino, using the input given from the flex sensors, maps the significant and readable value of the flex sensors to a degree value for the servo from 0 - 180. The fine tuning of this depends on each individual sensor, because of slight hardware errors.

With the correct values assigned to the servos, a string is then attached to each servo which acts as a tendon for 3D printed finger that flexes with the tendon's tension/pull. The tendon runs along the inside of each printed finger and attaches around the inside of the tip of the finger. 

With the strength of the Servos used the arm was able to grab multiple objects with decent grip. Objects that the arm was able to grab include: a tennis ball, a filled cup, books, and objects of relative size.

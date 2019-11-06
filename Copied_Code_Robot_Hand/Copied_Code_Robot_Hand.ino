#include <Servo.h>

Servo myservo1; // create servo object to control a servo
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;

void setup()
{
Serial.begin(9600);

myservo1.attach(8); // attaches the servo on pin 9 to the servo object
myservo2.attach(9);
myservo3.attach(10);
myservo4.attach(11);
myservo5.attach(12);
}

void loop()
{
if(Serial.available() >=5)
{
byte servoAng1 = Serial.read();
byte servoAng2 = Serial.read();
byte servoAng3 = Serial.read();
byte servoAng4 = Serial.read();
byte servoAng5 = Serial.read();


// Send the servo to the position read...  (note: you get to make this happen)
myservo1.write(servoAng1);
myservo2.write(servoAng2);
myservo3.write(servoAng3);
myservo4.write(servoAng4);
myservo5.write(servoAng5);

Serial.print(servoAng1);
}
}

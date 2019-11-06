#include <Servo.h> 
Servo servo1;  
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;  


int servoposition1 = 0;  
int servoposition2 = 0;
int servoposition3 = 0;
int servoposition4 = 0;
int servoposition5 = 0;  

void setup() {
  
Serial.begin(9600);

servo1.attach(12);  
servo2.attach(11);
servo3.attach(10);
servo4.attach(9);
servo5.attach(8);  
}

void loop()

{
if(Serial.available() >=5)   

byte servoposition1 = Serial.read();  
byte servoposition2 = Serial.read();
byte servoposition3 = Serial.read();
byte servoposition4 = Serial.read();
byte servoposition5 = Serial.read();  

  servo1.write(servoposition1);  
  servo2.write(servoposition2);
  servo3.write(servoposition3);
  servo4.write(servoposition4);
  servo5.write(servoposition5);  
  
  Serial.print (servoposition1);
    
delay(30);
}

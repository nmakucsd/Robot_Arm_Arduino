
int flexpin3 = 3;
int flexpin4 = 4;
int flexpin5 = 5; 

#include <Servo.h> 

Servo servo3;
Servo servo4;
Servo servo5;  


int servoposition3 = 0;
int servoposition4 = 0;
int servoposition5 = 0; 

void setup() 
{ 
 Serial.begin(9600); //allows serial reading
 
servo3.attach(10);
servo4.attach(9);
servo5.attach(8);  
 } 
 
 void loop() 
{ 
  int flexposition3;
  int flexposition4;
  int flexposition5;  
  

  flexposition3 = analogRead(flexpin3);
  flexposition4 = analogRead(flexpin4);
  flexposition5 = analogRead(flexpin5);  
  
  servoposition3 = map(flexposition3, 340, 510, 0, 180);
  servoposition4 = map(flexposition4, 320, 520, 0, 180);
  servoposition5 = map(flexposition5, 240, 470, 0, 180); 

  servoposition3 = constrain(servoposition3, 0, 180);
  servoposition4 = constrain(servoposition4, 0, 180);
  servoposition5 = constrain(servoposition5, 0, 180);  

Serial.println(servoposition3); 
//Serial.println(servoposition4); 
//Serial.println(servoposition5); 


  servo3.write(servoposition3);
  servo4.write(servoposition4);
  servo5.write(servoposition5);  
  
delay(30);
}

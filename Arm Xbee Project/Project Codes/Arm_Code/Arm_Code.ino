int flexpin1 = 1; 
int flexpin2 = 2;
int flexpin3 = 3;
int flexpin4 = 4;
int flexpin5 = 5; 

void setup() 
{ 

 Serial.begin(9600);
 
 } 
 
 void loop() 
{ 

 
  int flexposition1;    // Input value from the analog pin. 
  int flexposition2;  
  int flexposition3;
  int flexposition4;
  int flexposition5;  
  byte servoposition1;   // Output value to the servo.
  byte servoposition2;
  byte servoposition3;
  byte servoposition4;
  byte servoposition5; 
  
  flexposition1 = analogRead(flexpin1);  
  flexposition2 = analogRead(flexpin2);
  flexposition3 = analogRead(flexpin3);
  flexposition4 = analogRead(flexpin4);
  flexposition5 = analogRead(flexpin5);  
  
  servoposition1 = map(flexposition1, 285, 300, 0, 180);  
  servoposition2 = map(flexposition2, 350, 530, 0, 180);
  servoposition3 = map(flexposition3, 340, 510, 0, 180);
  servoposition4 = map(flexposition4, 370, 520, 0, 180);
  servoposition5 = map(flexposition5, 330, 525, 0, 180); 
  servoposition1 = constrain(servoposition1, 0, 180);  
  servoposition2 = constrain(servoposition2, 0, 180);
  servoposition3 = constrain(servoposition3, 0, 180);
  servoposition4 = constrain(servoposition4, 0, 180);
  servoposition5 = constrain(servoposition5, 0, 180);  
  
Serial.println(servoposition1);  
Serial.println(servoposition2);
Serial.println(servoposition3);
Serial.println(servoposition4);
Serial.println(servoposition5); 

}


#include <Servo.h>

Servo Servo1;

int potentiometer = 0; 
int val ;
void setup() 
{
  Servo1.attach (9);
}

void loop() 
{
  val = analogRead(potentiometer);
  val = map(val, 0, 1023, 0, 179);
  Servo1.write (val);
  delay (15);
}
 

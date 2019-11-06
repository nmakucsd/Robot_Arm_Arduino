/*
SparkFun Inventor's Kit for Arduino
Example sketch 09

FLEX SENSOR

  Use the "flex sensor" to change the position of a servo

  In the previous sketch, we learned how to command a servo to
  mode to different positions. In this sketch, we'll introduce
  a new sensor, and use it to control the servo.

  A flex sensor is a plastic strip with a conductive coating.
  When the strip is straight, the coating will be a certain
  resistance. When the strip is bent, the particles in the coating
  get further apart, increasing the resistance. You can use this
  sensor to sense finger movement in gloves, door hinges, stuffed
  animals, etc. See http://www.sparkfun.com/tutorials/270 for
  more information.

Hardware connections:

  Flex sensor:

    The flex sensor is the plastic strip with black stripes.
    It senses bending away from the striped side.

    The flex sensor has two pins, and since it's a resistor,
    the pins are interchangable.

    Connect one of the pins to ANALOG IN pin 0 on the Arduino.
    Connect the same pin, through a 10K Ohm resistor (brown
    black orange) to GND.
    Connect the other pin to 5V.

  Servo:

    The servo has a cable attached to it with three wires.
    Because the cable ends in a socket, you can use jumper wires
    to connect between the Arduino and the servo. Just plug the
    jumper wires directly into the socket.

    Connect the RED wire (power) to 5 Volts (5V)
    Connect the WHITE wire (signal) to digital pin 9
    Connect the BLACK wire (ground) to ground (GND)

    Note that servos can use a lot of power, which can cause your
    Arduino to reset or behave erratically. If you're using large
    servos or many of them, it's best to provide them with their
    own separate 5V supply. See this Arduino Forum thread for info:
    http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1239464763

This sketch was written by SparkFun Electronics,
with lots of help from the Arduino community.
This code is completely free for any use.
Visit http://learn.sparkfun.com/products/2 for SIK information.
Visit http://www.arduino.cc to learn about the Arduino.

Version 2.0 6/2012 MDG
*/


// Include the servo library to add servo-control functions:

#include <Servo.h> 

// Create a servo "object", called servo1. Each servo object
// controls one servo (you can have a maximum of 12):

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

// Define the analog input pin to measure flex sensor position:

int flexpin1 = 1; 
int flexpin2 = 2;
int flexpin3 = 3;
int flexpin4 = 4;
int flexpin5 = 5;

void setup() 
{ 
  // Use the serial monitor window to help debug our sketch:

 Serial.begin(9600);

  // Enable control of a servo on pin 9:

  servo1.attach(12);
  servo2.attach(11);
  servo3.attach(10);
  servo4.attach(9);
  servo5.attach(8);
  
} 


void loop() 
{ 
  int flexposition1;    // Input value from the analog pin.
  int flexposition2;
  int flexposition3;
  int flexposition4;
  int flexposition5;
  int servoposition1;   // Output value to the servo.
  int servoposition2;
  int servoposition3;
  int servoposition4;
  int servoposition5;
  
 

  // Read the position of the flex sensor (0 to 1023):

  flexposition1 = analogRead(flexpin1);
  flexposition2 = analogRead(flexpin2);
  flexposition3 = analogRead(flexpin3);
  flexposition4 = analogRead(flexpin4);
  flexposition5 = analogRead(flexpin5);

  // Because the voltage divider circuit only returns a portion
  // of the 0-1023 range of analogRead(), we'll map() that range
  // to the servo's range of 0 to 180 degrees. The flex sensors
  // we use are usually in the 600-900 range:

  servoposition1 = map(flexposition1, 285, 450, 0, 180);
  servoposition2 = map(flexposition2, 350, 530, 0, 180);
  servoposition3 = map(flexposition3, 340, 510, 0, 180);
  servoposition4 = map(flexposition4, 370, 520, 0, 180);
  servoposition5 = map(flexposition5, 330, 525, 0, 180);
  servoposition1 = constrain(servoposition1, 0, 180);
  servoposition2 = constrain(servoposition2, 0, 180);
  servoposition3 = constrain(servoposition3, 0, 180);
  servoposition4 = constrain(servoposition4, 0, 180);
  servoposition5 = constrain(servoposition5, 0, 180);

  // Now we'll command the servo to move to that position:

  servo1.write(servoposition1);
  servo2.write(servoposition2);
  servo3.write(servoposition3);
  servo4.write(servoposition4);
  servo5.write(servoposition5);
  

  // Because every flex sensor has a slightly different resistance,
  // the 600-900 range may not exactly cover the flex sensor's
  // output. To help tune our program, we'll use the serial port to
  // print out our values to the serial monitor window:

       Serial.print("flex sensor 1: ");
      Serial.print(flexposition1);
      Serial.print("  servo 1: ");
      Serial.println(servoposition1);
        Serial.print("flex sensor 2: ");
      Serial.print(flexposition2);
      Serial.print("  servo 2: ");
      Serial.println(servoposition1);
        Serial.print("flex sensor 3: ");
      Serial.print(flexposition3);
      Serial.print("  servo 3: ");
      Serial.println(servoposition3);
        Serial.print("flex sensor 4: ");
      Serial.print(flexposition4);
      Serial.print("  servo 4: ");
      Serial.println(servoposition4);
        Serial.print("flex sensor 5: ");
      Serial.print(flexposition5);
      Serial.print("  servo 5: ");
      Serial.println(servoposition5);
      
    
  // Note that all of the above lines are "print" except for the
  // last line which is "println". This puts everything on the
  // same line, then sends a final carriage return to move to
  // the next line.

  // After you upload the sketch, turn on the serial monitor
  // (the magnifying-glass icon to the right of the icon bar).
  // You'll be able to see the sensor values. Bend the flex sensor
  // and note its minimum and maximum values. If you replace the
  // 600 and 900 in the map() function above, you'll exactly match
  // the flex sensor's range with the servo's range.

    // wait 20ms between servo updates
    
   delay(20);
} 

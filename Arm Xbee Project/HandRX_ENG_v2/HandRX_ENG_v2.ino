/*
Robot Hand

Created by Santin Gabriele, 2014
I.T.S.T. "J. F. Kennedy", cl. 5^A EA
Thanks to Elias De Lamper for suggestions to improve this program!
*/

#include <Servo.h>   // Library needed to use function for servomotors

Servo ServoThumb, ServoIndex,        // Viene assegnato un nome a ciascun servomotore.
ServoMiddle, ServoAnnular, ServoPinky;

byte startPackage; // Variable that will contain the character of start package set in the GloveTX sketch, "<" 

int AngThumb   = 0;   // Variables with the values for the servomotors (between 0 and 180)
int AngIndex   = 0;
int AngMiddle  = 0;
int AngAnnular = 0;
int AngPinky   = 0;


void setup()
{
  Serial.begin(9600);      // Serial communication is activated at 9600 baud/s.
  
  ServoThumb.attach(12);  // The servomotors are asigned to the pins of the Arduino UNO board.
  delay(300);              // A delay of 300ms is set for a secure connection (this can be optional)
  ServoIndex.attach(11);   
  delay(300);
  ServoMiddle.attach(10);
  delay(300);
  ServoAnnular.attach(9);
  delay(300);
  ServoPinky.attach(8);
  delay(300);
  
  Serial.println("Ready to receive."); 
}

void loop()
{ 
  if(Serial.available()) {    // Witing for data incoming from the other XBee module
    
    startPackage = Serial.read(); // The first value will be "<", the other are assigned to the finger
    AngThumb   = Serial.read();       
    AngIndex   = Serial.read();       
    AngMiddle  = Serial.read();
    AngAnnular = Serial.read();
    AngPinky   = Serial.read();
    
    if(startPackage == '<'){   // Verifying that the first value is "<"
    
      if(AngThumb!=255)  // Sometimes the incoming value goes to 255, I couldn't discover yet the reason, so I simply excluded it when it happens. You can remove this line for every finger if you don't have this kind of problem
      ServoThumb.write(AngThumb);  // The servomotors rotates of the assigned degrees
                                                    
      if(AngIndex!=255)
      ServoIndex.write(AngIndex);
    
      if(AngMiddle!=255)
      ServoMiddle.write(AngMiddle);
    
      if(AngAnnular!=255)
      ServoAnnular.write(AngAnnular);
    
      if(AngPinky!=255)
      ServoPinky.write(AngPinky);    
    }
  }
  delay(30); // a delay to make the servomotors working correctly (a lower value could make the system not working, higher value make it slower)
}            

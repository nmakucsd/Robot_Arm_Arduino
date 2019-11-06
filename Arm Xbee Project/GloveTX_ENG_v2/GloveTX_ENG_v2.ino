/*
Flex Glove

Created by Santin Gabriele, 2014
I.T.S.T. "J. F. Kennedy", cl. 5^A EA
Thanks to Elias De Lamper for suggestions to improve this program!
*/

int ResThumb   = 4;  // Variables of the analog read form the flex sensors connected to the analog pins of Arduino LilyPad
int ResIndex   = 3;  
int ResMiddle  = 2;
int ResAnnular = 1;
int ResPinky   = 0;

int OpenedThumb   =0; // Variables of the values when the hand is completely opened
int OpenedIndex   =0; // This is needed for a continuous calibration
int OpenedMiddle  =0;
int OpenedAnnular =0;
int OpenedPinky   =0;

int ClosedThumb;      // Variables of the values when the hand is completely closed
int ClosedIndex;      // We can't set it to zero since that the minimum value reached
int ClosedMiddle;     // in the analog read never reach zero. We'll assign the value of
int ClosedAnnular;    // a first analog read, then the program in the loop will
int ClosedPinky;      // automatically  assing lower values

int thumb   =0;       // Variables of the values to send
int index   =0;
int middle  =0;
int annular =0;
int pinky   =0;


void setup()
{
  Serial.begin(9600);   // Activating serial communication, XBee Series 1 are pre-programmed at 9600 baud/s
  
  pinMode(ResThumb,   INPUT);   // The variables of the sensor are set as input
  pinMode(ResIndex,   INPUT);
  pinMode(ResMiddle,  INPUT);
  pinMode(ResAnnular, INPUT);
  pinMode(ResPinky,   INPUT);

  ClosedThumb   = analogRead(ResThumb);
  ClosedIndex   = analogRead(ResIndex);  
  ClosedMiddle  = analogRead(ResMiddle); 
  ClosedAnnular = analogRead(ResAnnular);
  ClosedPinky   = analogRead(ResPinky);  
}

void loop()
{
  thumb   = analogRead(ResThumb);  
  index   = analogRead(ResIndex);  
  middle  = analogRead(ResMiddle); 
  annular = analogRead(ResAnnular);
  pinky   = analogRead(ResPinky);  
  
  if(thumb   > OpenedThumb)   // Calibration reading and setting the maximum values. This needs you to completely open your hand a few times
  OpenedThumb   = thumb;
  if(index   > OpenedIndex)
  OpenedIndex   = index;
  if(middle  >  OpenedMiddle)
  OpenedMiddle  = middle;
  if(annular > OpenedAnnular)
  OpenedAnnular = annular;
  if(pinky   > OpenedPinky)
  OpenedPinky   = pinky;
  
  if(thumb   < ClosedThumb)  // Calibration reading and setting the minimum values. This needs you to completely close your hand a few times
  ClosedThumb   = thumb;
  if(index   < ClosedIndex)
  ClosedIndex   = index;
  if(middle  < ClosedMiddle)
  ClosedMiddle  = middle;
  if(annular < ClosedAnnular)
  ClosedAnnular = annular;
  if(pinky   < ClosedPinky)
  ClosedPinky   = pinky;
  
  thumb   = map(thumb  ,ClosedThumb  ,OpenedThumb  ,0,180);  // The analog read has to be readapted in values between 0 and 180 to be used by the servomotors.
  index   = map(index  ,ClosedIndex  ,OpenedIndex  ,0,180);  // The minimum and maximum values from the calibrations are used to correctly set the analog reads.
  middle  = map(middle ,ClosedMiddle ,OpenedMiddle ,0,180);
  annular = map(annular,ClosedAnnular,OpenedAnnular,0,180);  
  pinky   = map(pinky  ,ClosedPinky  ,OpenedPinky  ,0,180);
  
  Serial.write("<");      // This character represent the beginning of the package of the five values
  Serial.write(thumb);    // The values are sent via the Tx pin (the digital pin 1)
  Serial.write(index);  
  Serial.write(middle);  
  Serial.write(annular);
  Serial.write(pinky);
  
  delay(30);
}

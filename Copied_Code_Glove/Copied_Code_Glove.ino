int Finger1 = 1;
int Finger2 = 2;
int Finger3 = 3;
int Finger4 = 4;
int Finger5 = 5;

void setup()
{
Serial.begin(9600);
}

void loop()
{
byte servoValue1;
byte servoValue2;
byte servoValue3;
byte servoValue4;
byte servoValue5;

int FingerV1 = analogRead(Finger1);
int FingerV2 = analogRead(Finger2);
int FingerV3 = analogRead(Finger3);
int FingerV4 = analogRead(Finger4);
int FingerV5 = analogRead(Finger5);

if (FingerV1 < 200) FingerV1 = 200;
else if (FingerV1 > 460) FingerV1 = 460;
if (FingerV2 < 200) FingerV2 = 200;
else if (FingerV2 > 460) FingerV2 = 460;
if (FingerV3 < 200) FingerV3 = 200;
else if (FingerV3 > 460) FingerV3 = 460;
if (FingerV4 < 200) FingerV4 = 200;
else if (FingerV4 > 460) FingerV4 = 460;
if (FingerV5 < 200) FingerV5 = 200;
else if (FingerV5 > 460) FingerV5 = 460;

byte servoVal1 = map(FingerV1,460, 200, 255, 0);
byte servoVal2 = map(FingerV2,460, 200, 255, 0);
byte servoVal3 = map(FingerV3,460, 200, 255, 0);
byte servoVal4 = map(FingerV4,460, 200, 255, 0);
byte servoVal5 = map(FingerV5,460, 200, 255, 0);

Serial.print(servoVal1);
Serial.print(servoVal2);
Serial.print(servoVal3);
Serial.print(servoVal4);
Serial.print(servoVal5);


delay(100);
}



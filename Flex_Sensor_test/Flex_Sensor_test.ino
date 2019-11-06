int flexSensorPin = A0; // analog pin 0

void setup() {
  // put your setup code here, to run once:
    Serial.begin (9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    int flexSensorReading = analogRead(flexSensorPin);
    
    delay (1000); // just here to slow down the output for easier reading
    
    int flex0to100 = map (flexSensorReading, 150, 400, 100, 0);
    Serial.println(flex0to100);
}

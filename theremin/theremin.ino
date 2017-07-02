int sensorVal;
int sensorLow = 1023;
int sensorHigh = 0;

const int ledPin = 13;
const int photoPin = A0;
const int soundPin = 8;
const int soundLength = 20;
const int calibrationTime = 5000;

const int arduoLow = 50;
const int arduoHigh = 4000;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  
  while( millis() < calibrationTime ) {
    sensorVal = analogRead(photoPin);
    if( sensorVal > sensorHigh ) {
      sensorHigh = sensorVal;
    }
    if( sensorVal < sensorLow ) {
      sensorLow = sensorVal;
    }
  }

  digitalWrite(ledPin, LOW);
}

void loop() {
  sensorVal = analogRead(photoPin);

  int pitch = map( sensorVal, sensorLow, sensorHigh, arduoLow, arduoHigh );
  tone(soundPin, pitch, soundLength);

  delay(10);
}

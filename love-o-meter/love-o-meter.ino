const int sensorPin = A0;
const float baselineTemp = 68.0;

void setup() {
  Serial.begin(9600);
  for( int pin = 2; pin < 5; pin++ ) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  float voltage = (sensorVal/1024.0) * 5.0;
  float temp = (((voltage -.5) * 100) * 1.8) + 32;
  Serial.print("Sensor value: ");
  Serial.print(sensorVal);
  Serial.print(", Volts : ");
  Serial.print(voltage);
  Serial.print(", degrees F: ");
  Serial.println(temp);

  if( temp < baselineTemp ) {
    changeLight(2, LOW);
    changeLight(3, LOW);
    changeLight(4, LOW);
  } else if( temp >= 71.6 && temp < 75.2 ) {
    changeLight(2, HIGH);
    changeLight(3, LOW);
    changeLight(4, LOW);
  } else if( temp >= 75.2 && temp < 78.8 ) {
    changeLight(4, LOW);
    changeLight(2, HIGH);
    changeLight(3, HIGH);
  } else if( temp >= 78.8 ) {
    changeLight(2, HIGH);
    changeLight(3, HIGH);
    changeLight(4, HIGH);
  }
  delay(1);
}

void changeLight(int lightToTurnOn, uint8_t state) {
  digitalWrite(lightToTurnOn, state);
}


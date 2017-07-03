/**
 * Using serial communication, control a program on the computer
 * using the Arduino
 */

const int potPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.write(analogRead(potPin)/4);
  delay(1);
}

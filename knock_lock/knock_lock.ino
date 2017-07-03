#include <Servo.h>
/**
 * Secret locking mechanism to keep unwanted guests out
 * of your space
 */
 Servo myServo;
 const int piezo = A0;
 const int switchPin = 2;
 const int yellowLed = 3;
 const int greenLed = 4;
 const int redLed = 5;

 int knockVal;
 int switchVal;

 const int quietKnock = 5;
 const int loudKnock = 100;

 boolean locked = false;
 int numberOfKnocks = 0;

void setup() {
  myServo.attach(9);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);
  unlockTheBox();
}

void loop() {
  if( locked == false ) {
    switchVal = digitalRead(switchPin);
    if(switchVal == HIGH) {
      lockTheBox();
    }
  }
  if( locked == true ) {
    tryToUnlock();
  }
}

/**
 * Lock the box and set the motor and LEDs accordingly
 */
void lockTheBox() {
  locked = true;
  digitalWrite(greenLed, LOW);
  digitalWrite(redLed, HIGH);
  myServo.write(90);
  Serial.println("The box is locked!");
  delay(1000);
}

/**
 * Unlock the box and set the motor and LEDs accordingly
 */
void unlockTheBox() {
  locked = false;
  myServo.write(0);
  delay(20);
  digitalWrite(greenLed, HIGH);
  digitalWrite(redLed, LOW);
  Serial.println("The box is unlocked!");
}

/**
 * Try to unlock the box based on user actions
 */
void tryToUnlock() {
  knockVal = analogRead(piezo);
  if( numberOfKnocks < 3 && knockVal > 0 ) {
    if( checkForKnock(knockVal) == true ) {
      numberOfKnocks++;
    }
    Serial.println(3-numberOfKnocks);
    Serial.println(" more knocks to go");
  }
  if( numberOfKnocks >= 3 ) {
    unlockTheBox();
    numberOfKnocks = 0;
  }
}

/**
 * Check for knock validity
 */
boolean checkForKnock( int knock ) {
  boolean isValidKnock = false;
  if( knock > quietKnock && knock < loudKnock ) {
    digitalWrite(yellowLed, HIGH);
    delay(50);
    digitalWrite(yellowLed, LOW);
    Serial.println("Valid knock of value ");
    Serial.println(knock);
    isValidKnock = true;
  } else {
    Serial.print("Invalid knock of value ");
    Serial.println(knock);
  }
  return isValidKnock;
}


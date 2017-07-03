/**
 * Create moving images in forward and reverse with arduino
 * when you connect a motor to an H-bridge and some still images.
 */
 
const int controlPin1 = 2;
const int controlPin2 = 3;
const int enablePin = 9;
const int directionSwitchPin = 4;
const int onOffSwitchStateSwitchPin = 5;
const int potPin = A0;

int onOffSwitchState = 0;
int previousOnOffSwitchState = 0;
int directionSwitchState = 0;
int previousDirectionSwitchState = 0;

int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;

void setup() {
  pinMode(directionSwitchPin, INPUT);
  pinMode(onOffSwitchStateSwitchPin, INPUT);
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  
  digitalWrite(enablePin, LOW);
}

void loop() {
  onOffSwitchState = digitalRead(onOffSwitchStateSwitchPin);
  delay(1);
  directionSwitchState = digitalRead(directionSwitchPin);
  motorSpeed = analogRead(potPin)/4;

  checkMotorEnabledChange();

  checkMotorDirectionChange();

  setMotorDirection();

  turnTheMotor();

  previousDirectionSwitchState = directionSwitchState;
  previousOnOffSwitchState = onOffSwitchState;
}

/**
 * Check to see if on/off sensor has changed
 */
void checkMotorEnabledChange() {
  if( onOffSwitchState != previousOnOffSwitchState ) {
    if( onOffSwitchState == HIGH ) {
      motorEnabled = !motorEnabled;
    }
  }
}

/**
 * Check to see if the direction has changed
 */
void checkMotorDirectionChange() {
  if( directionSwitchState != previousDirectionSwitchState ) {
    if( directionSwitchState == HIGH ) {
      motorDirection = !motorDirection;
    }
  }
}

/**
 * Change the pins to turn the motor in the proper direction
 */
 void setMotorDirection() {
  if( motorDirection == 1 ) {
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
  } else {
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
  }
 }

/**
 * PWM the motor if it is enabled
 */
 void turnTheMotor() {
  if( motorEnabled == 1 ) {
    analogWrite(enablePin, motorSpeed);
  } else {
    analogWrite(enablePin, 0);
  }
 }


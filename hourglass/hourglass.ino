const int switchPin = 8;

unsigned long previousTime = 0;

int switchState = 0;
int prevSwitchState = 0;

int led = 2;
long interval = 400;

void setup() {
  for( int ledPin = 2; ledPin < 8; ledPin++ ) {
    pinMode( ledPin, OUTPUT );
  }

  pinMode( switchPin, INPUT);
}

void loop() {
  unsigned long currentTime = millis();
  if( currentTime - previousTime > interval ) {
    previousTime = currentTime;
    if( led > 7 ) {
      while(!checkSwitchStateChanged(currentTime)) {
        changeAllLights(LOW);
        delay(400);
        changeAllLights(HIGH);
        delay(400);
      }
    } else {
      digitalWrite(led, HIGH);
      led++;
    }
  }
  checkSwitchStateChanged(currentTime);
}

void changeAllLights( int status ) {
  for( int ledPin = 2; ledPin < 8; ledPin++ ) {
    digitalWrite( ledPin, status );
  }
  led = 2;
}

boolean checkSwitchStateChanged(unsigned long currentTime) {
  boolean switchStateChange = false;
  switchState = digitalRead( switchPin );
  if( switchState != prevSwitchState ) {
    changeAllLights(LOW);
    previousTime = currentTime;
    switchStateChange = true;
  }
  prevSwitchState = switchState;

  return switchStateChange;
}


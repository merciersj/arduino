const int cNote = 262;
const int dNote = 294;
const int eNote = 330;
const int fNote = 349;
const int notes[] = {cNote, dNote, eNote, fNote};

const int keyboardPin = A0;
const int piezoPin = 8;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int keyVal = analogRead(keyboardPin);
  Serial.println(keyVal);

  if( keyVal == 1023 ) {
    // play C
    tone(piezoPin, notes[0]);
  } else if( keyVal >= 1000 && keyVal <= 1005 ) {
    // play D
    tone(piezoPin, notes[1]);
  }  else if( keyVal >= 505 && keyVal <= 515 ) {
    // play E
    tone(piezoPin, notes[2]);
  } else if( keyVal >= 950 && keyVal <= 990 ) {
    // play F
    tone(piezoPin, notes[3]);
  } else {
    noTone(piezoPin);
  }
}

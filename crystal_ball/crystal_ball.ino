
#include <LiquidCrystal.h>

/**
 * Create a crystal ball to tell your future
 */
 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int buttonPin = A0;
int switchState = 0;
int prevSwitchState = 0;
int reply;
const String answers[] = {"Yes", "Kitten promise", "Certainly", "Ask Jasper", "Unsure", "Most likely", "I'm bored", "Food time?", "No"};

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  printWelcomeMessage();
}

void loop() {
  switchState = analogRead(buttonPin);
  Serial.println(switchState);
  if( switchState == 1023 ) {
    reply = random(9);
    writeReply();
    delay(3000);
    printWelcomeMessage();
  }
}

/**
 * Print the welcome message to the lcd
 */
void printWelcomeMessage() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Ask the");
  lcd.setCursor(0, 1);
  lcd.print("Magic Watso!");
}

/**
 * Write the random reply to the lcd
 */
void writeReply() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Watso says:");
  lcd.setCursor(0, 1);
  lcd.print( answers[reply] );
}

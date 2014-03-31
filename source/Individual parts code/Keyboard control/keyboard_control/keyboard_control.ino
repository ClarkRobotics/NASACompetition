#include <stdio.h>

#define LED 2

void setup() {
   Serial.begin(9600);
   pinMode(LED, OUTPUT);
   digitalWrite(LED, HIGH);
   Keyboard.begin();
}

void loop() {
  getInput();
}

void LEDOn() {
  digitalWrite(LED, HIGH);
}

void LEDOff() {
  digitalWrite(LED, LOW);
}

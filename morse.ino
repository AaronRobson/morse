/*
  Morse code key to emulated keyboard.
*/

#include "Keyboard.h"

#define KEY_SPACE 0x20

const int buttonPin = 2;
const int ledPin = 13;
const unsigned long debounceMs = 50;
const uint8_t keyToSend = KEY_SPACE;

// variables
int buttonState = LOW;
int lastButtonState = LOW;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);

  Keyboard.begin();
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      digitalWrite(ledPin, HIGH);
      Serial.println("on");
      Keyboard.press(keyToSend);
    } else {
      digitalWrite(ledPin, LOW);
      Serial.println("off");
      Keyboard.release(keyToSend);
    }

    delay(debounceMs);
  }

  lastButtonState = buttonState;
}

#include <Arduino.h>
//gx12-7 input
const int lowSpeedPin = 2;
const int highSpeedPin = 3;
const int reversePin = 4;
const int brakePin = 5;
const int casperModePin = 6;
//
const float lowSpeedFactor = 0.25;
const float midSpeedFactor = 0.50;
const float highSpeedFactor = 1;
const float reverseSpeedFactor =0.1;
const float casperLowSpeedFactor = 0.05;
const float casperMidSpeedFactor = 0.08;
const float casperHighSpeedFactor = 0.10;
const float casperReverseSpeedFactor =0.1;



void setup() {
  pinMode(lowSpeedPin, INPUT_PULLUP);
  pinMode(highSpeedPin, INPUT_PULLUP);
  pinMode(reversePin, INPUT_PULLUP);
  pinMode(brakePin, INPUT_PULLUP);
  pinMode(casperModePin, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
}

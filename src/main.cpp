#include <Arduino.h>
#define ON LOW
//gx12-7 input
const int midSpeedPin = 2;
const int highSpeedPin = 3;
const int reversePin = 4;
const int brakePin = 5;
const int casperModePin = 6;
// speed factors 
const float lowSpeedFactor = 0.25;
const float midSpeedFactor = 0.50;
const float highSpeedFactor = 1;
const float reverseSpeedFactor =0.1;
const float casperLowSpeedFactor = 0.05;
const float casperMidSpeedFactor = 0.08;
const float casperHighSpeedFactor = 0.10;
const float casperReverseSpeedFactor =0.1;
float speedFactor = 0;



void setup() {
  pinMode(midSpeedPin, INPUT_PULLUP);
  pinMode(highSpeedPin, INPUT_PULLUP);
  pinMode(reversePin, INPUT_PULLUP);
  pinMode(brakePin, INPUT_PULLUP);
  pinMode(casperModePin, INPUT_PULLUP);
}

void loop() {
  if(casperModePin == HIGH){ // code runs if casper mode is on
    if(highSpeedPin == ON){
      speedFactor == casperHighSpeedFactor;
    } else if (midSpeedPin == ON){
      speedFactor == casperMidSpeedFactor;
    } else {
      speedFactor == casperLowSpeedFactor;
    }
    if (reversePin == ON){
      speedFactor = speedFactor* reverseSpeedFactor;
    }
  } else { // code runs if casper mode is on
    if(highSpeedPin == ON){
      speedFactor == highSpeedFactor;
    } else if (midSpeedPin == ON){
      speedFactor == midSpeedFactor;
    } else {
      speedFactor == lowSpeedFactor;
    }
    if (reversePin == ON){
      speedFactor = speedFactor* reverseSpeedFactor;
    } 
    

  }
}



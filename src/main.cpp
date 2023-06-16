#include <Arduino.h>
#include <Servo.h>
#define ON LOW
#define OFF HIGH
//gx12-7 input
const int midSpeedPin = 2;
const int highSpeedPin = 3;
const int reversePin = 4;
const int brakePin = 5;
const int casperModePin = 6;
// gx12-3 gas paddle
const int gasPaddlePin = A2;
// vesc comunication
const int vescPwmPin = 9;
const int vescPwmZeroSpeed = 1500;
// speed factors 
const float lowSpeedFactor = 0.25;
const float midSpeedFactor = 0.50;
const float highSpeedFactor = 1;
const float reverseSpeedFactor =0.1;
const float casperLowSpeedFactor = 0.05;
const float casperMidSpeedFactor = 0.08;
const float casperHighSpeedFactor = 0.10;
const float casperReverseSpeedFactor =-0.1;
// set temp variabels
float speedFactor = 0;
int gasLevel = 0;
int speedPwm = 0;

Servo vesc;

void setup() {
  Serial.begin(9600);
  // setup pinmode gx12-7 inputs
  pinMode(midSpeedPin, INPUT_PULLUP);
  pinMode(highSpeedPin, INPUT_PULLUP);
  pinMode(reversePin, INPUT_PULLUP);
  pinMode(brakePin, INPUT_PULLUP);
  pinMode(casperModePin, INPUT_PULLUP);
  // setup vecs comunicatons
  vesc.attach(vescPwmPin);
  vesc.writeMicroseconds(1500);
}

void loop() {
  if(digitalRead(brakePin) == OFF){
    Serial.print("brake = off ");
    if(digitalRead(casperModePin) == HIGH){ // code runs if casper mode is on
      Serial.print("casperMode = on ");
      if(digitalRead(highSpeedPin) == ON){
        speedFactor = casperHighSpeedFactor;
        Serial.print("high speed ");
      } else if (digitalRead(midSpeedPin) == ON){
        speedFactor = casperMidSpeedFactor;
        Serial.print("mid speed ");
      } else {
        speedFactor = casperLowSpeedFactor;
        Serial.print("low speed ");
      }
      if (digitalRead(reversePin) == ON){
        speedFactor = speedFactor* reverseSpeedFactor;
        Serial.print("reverse = on ");
      } else{Serial.print("reverse = off ");}
    } else { 
      Serial.print("casperMode = off ");
      if(digitalRead(highSpeedPin) == ON){
        speedFactor = highSpeedFactor;
        Serial.print("high speed ");
      } else if (digitalRead(midSpeedPin) == ON){
        speedFactor = midSpeedFactor;
        Serial.print("mid speed ");
      } else {
        speedFactor = lowSpeedFactor;
        Serial.print("low speed ");
      }
      if (digitalRead(reversePin) == ON){
        speedFactor = speedFactor* reverseSpeedFactor;
        Serial.print("reverse = on ");
      } else{Serial.print("reverse = off ");}
    } 
  } else {
    Serial.print("brake = off ");
    speedFactor = 0;
  } 
    Serial.print("speed factor: ");
    Serial.print(speedFactor);
    gasLevel= analogRead(gasPaddlePin)*speedFactor;
    speedPwm = map(gasLevel,-1023,1023,1000,2000);
    vesc.writeMicroseconds(speedPwm);
    Serial.print(" pwm: ");
    Serial.println(speedPwm);
    
}



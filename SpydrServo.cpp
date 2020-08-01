/*
SpydrServo.cpp - Library for writing continous rotation
servo motors to a position depending on a potentiometer
with an 8 degree margine for error.
Created by Treebug842, August 1, 2020
*/

#include "Arduino.h"
#include "SpydrServo.h"

void SpydrServo::attach(int servoPin, int potPin) 
{
  _servo.attach(servoPin);
  _potPin = potPin;
}

void SpydrServo::write(int pos) 
{
  for (int x = 0; x < 4000; x++) 
  {
    _potRead = analogRead(_potPin);
    _pot = map(_potRead, 0, 1023, 0, 180);
    
    if (_pot < (pos + 4) && _pot > (pos - 4)) 
    {
      _servo.write(_stall);
    }
    else if (_pot > pos) 
    {
      _servo.write(_stall + 10);
    }
    else if (_pot < pos) 
    {
      _servo.write(_stall - 10);
    }
    else {
      _servo.write(_stall);
    }
    _potRead = analogRead(_potPin);
    _pot = map(_potRead, 0, 1023, 0, 180);
  
    if (_pot < 5) 
    {
      _servo.write(_stall - 10);
    }
    if (_pot > 175) 
    {
      _servo.write(_stall + 10);
    }
  }
  _servo.write(_stall);
}

void SpydrServo::detach() 
{
  _servo.detach();
}

int SpydrServo::read() 
{
  _potRead = analogRead(_potPin);
  _pot = map(_potRead, 0, 1023, 0, 180);
  potRead = _pot;
  return potRead;
}
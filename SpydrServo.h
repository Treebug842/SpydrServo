/*
SpydrServo.h - Library for writing continous rotation
servo motors to a position depending on a potentiometer
with an 8 degree margine for error.
Created by Treebug842, August 1, 2020
*/

#ifndef SpydrServo_h
#define SpydrServo_h

#include "Arduino.h"
#include <Servo.h>

class SpydrServo 
{
  public:
    void attach(int servoPin, int potPin);
    void write(int pos);
    void detach();
    int read();
    int potRead;

  private:
    int _stall = 93;
    int _potPin;
    int _potRead;
    int _pot;
    Servo _servo;
};

#endif
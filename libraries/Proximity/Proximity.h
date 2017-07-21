/*
  Proximity.h - Library for checking proximity with ultrasonic sensor on a servo.
  Created by Doug Leary, July 20, 2017.
  Released into the public domain.
*/
#ifndef Proximity_h
#define Proximity_h

#include "Arduino.h"
#include "Servo.h"

class Proximity
{
  public:
    Proximity(Servo s);
	void forward();
	void left();
	void right();
	int getDistance();

private:
	int Echo = A4;
	int Trig = A5;
	int direction = 90;
	Servo myservo;
};

#endif

/*
  Wheels.cpp - Library for driving a 4-wheel car.
  Created by Doug Leary, July 20, 2017.
  Released into the public domain.
*/
#include "Arduino.h"
#include "Wheels.h"

Wheels::Wheels()
{
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
	pinMode(ENA, OUTPUT);
	pinMode(ENB, OUTPUT);
	stop();
}

void Wheels::forward()
{
	setSpeed(speedBoth);
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);
}

void Wheels::back()
{
	setSpeed(speedBoth);
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
}

void Wheels::left()
{
	setSpeed(speedBoth);
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
}

void Wheels::right()
{
	setSpeed(speedBoth);
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);
}

void Wheels::stop()
{
	digitalWrite(ENA, LOW);
	digitalWrite(ENB, LOW);
	speedBoth = stopped;
}

void Wheels::setSpeed(int both) {
	speedBoth = both;
	analogWrite(ENA, both);
	analogWrite(ENB, both);
}

void Wheels::setSpeed(int left, int right) {
	speedBoth = (left + right) / 2;
	speedLeft = left;
	speedRight = right;
	analogWrite(ENA, right);
	analogWrite(ENB, left);
}

void Wheels::veerLeft()
{
	setSpeed(max(speedLeft - veer, slow), min(speedRight + veer, fast));
}

void Wheels::veerRight()
{
	setSpeed(min(speedLeft + veer, fast), max(speedRight - veer, slow));
}

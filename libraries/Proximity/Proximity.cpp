/*
  Proximity.cpp - Library for proximity detection with an ultrasonic sensor on a servo.
  Created by Doug Leary, July 20, 2017.
  Released into the public domain.
*/
#include "Arduino.h"
#include "Servo.h"
#include "Proximity.h"

Proximity::Proximity(Servo s)
{
	myservo = s;
	pinMode(Echo, INPUT);
	pinMode(Trig, OUTPUT);
	myservo.attach(3);	// attach servo on pin 3
	Serial.begin(9600);
}

void Proximity::forward() {
	_direction = 90;
	myservo.write(_direction);
}

void Proximity::left() {
	_direction = 20;
	myservo.write(_direction);
}

void Proximity::right() {
	_direction = 180;
	myservo.write(_direction);
}

/* Ultrasonic distance measurement */
int Proximity::getDistance()
{
	digitalWrite(Trig, LOW);
	delayMicroseconds(2);
	digitalWrite(Trig, HIGH);
	delayMicroseconds(20);
	digitalWrite(Trig, LOW);
	float Fdistance = pulseIn(Echo, HIGH);
	Fdistance = Fdistance / 58;

	#ifdef send
		Serial.print("distance at ");
		Serial.print(_direction);
		Serial.print(" deg: ");
		Serial.println(Fdistance);
	#endif

	return (int)Fdistance;
}



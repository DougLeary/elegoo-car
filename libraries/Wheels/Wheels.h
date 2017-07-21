/*
  Wheels.h - Library for driving a 4-wheel car.
  Created by Doug Leary, July 20, 2017.
  Released into the public domain.
*/
#ifndef Wheels_h
#define Wheels_h

#include "Arduino.h"

class Wheels
{
  public:
    Wheels();
	const int stopped = 0;
	const int slow = 100;
	const int medium = 175;
	const int fast = 250;

    void forward();
	void back();
	void left();
	void right();
	void veerLeft();
	void veerRight();
	void stop();
	void setSpeed(int both);
	void setSpeed(int left, int right);

private:
	const int veer = 10;

	int in1 = 6;
	int in2 = 7;
	int in3 = 8;
	int in4 = 9;
	int ENA = 5;
	int ENB = 11;
	int speedBoth = stopped;
	int speedLeft = speedBoth;
	int speedRight = speedBoth;
};

#endif

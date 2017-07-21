# elegoo-car

Playing around with the Elegoo Smart Car - https://www.amazon.com/Elegoo-Ultrasonic-Bluetooth-Intelligent-Educational/dp/B01M2Z9ZTV

## Overview

My initial goal is to improve the sample code and make programming the car more noob-friendly.

This is a great kit which my daughter enjoyed assembling, but with no coding background and no knowledge of Arduino she had some trouble working with the provided software (which contained some bugs and inaccurate comments). She wanted to program the car, but the learning curve was kind of a barrier to enjoying it right away. I thought a more layered structure would make programming the car more accessible to people of different technical levels.

## Wheels

The Wheels library abstracts the operation of the four motors that control the wheels, providing methods for moving forward, back, left, right, and stopping. There are three fixed speeds (slow, medium, fast), and a veer function that makes gradual turns by varying the speeds of the wheels on both sides.

## Proximity

The car can measure distance to more-or-less solid obstacles using ultrasound, making it possible to program it to roam around autonomously. The ultrasound distance sensors are mounted on a servo that aims them. The simple Proximity library provides methods to aim the sensor forward, left or right, and a getDistance function.

/* Elegoo robot car object avoidance */

#include <Wheels.h>
Wheels car;

#include <Servo.h>
Servo myservo;

#include <Proximity.h>
Proximity eyes(myservo);

// variables //
int forwardDistance = 0;
int rightDistance = 0;
int leftDistance = 0;
int tooClose = 40;

void setup() 
{ 
  car.stop();
  car.setSpeed(car.medium);
  eyes.forward();

} 

void loop() 
{
  forwardDistance = eyes.getDistance();
  if (forwardDistance > tooClose)
  {
    car.forward();
  }
  else
  {     
    car.stop();
    delay(500);

    eyes.left();
    delay(1000);
    leftDistance = eyes.getDistance();
    
    eyes.right();
    delay(1000);
    rightDistance = eyes.getDistance();
    
    eyes.forward();
    
    if ((leftDistance < tooClose) || (rightDistance < tooClose))
    {
      // back up and turn around
      car.back();
      delay(200);
      // turn around by turning left twice
      car.left();
      car.left();
    }
    else if (leftDistance > rightDistance)
    {
      car.left();
      delay(500);
    }
    else if (rightDistance > leftDistance)
    {
      car.right();
      delay(500);
    }
  }
}


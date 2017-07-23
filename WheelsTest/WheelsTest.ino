/* Elegoo robot car object avoidance */

#ifndef send
#define send
#endif

#include <Wheels.h>
Wheels car;

//#include <Proximity.h>
//Proximity eyes(myservo);

// variables //
//int forwardDistance = 0;
//int rightDistance = 0;
//int leftDistance = 0;
int tooClose = 40;
int _direction;
int _servoDelay = 500;

#include <Servo.h> //servo library

Servo myservo; // create servo object to control servo
int Echo = A4;  
int Trig = A5; 
int rightDistance = 0, leftDistance = 0, forwardDistance = 0 ;

void setupEyes()
{
  pinMode(Echo, INPUT);
  pinMode(Trig, OUTPUT);
  myservo.attach(3);  // attach servo on pin 3
}

void eyesforward() {
  if (_direction != 90) {
    #ifdef send
    Serial.print("Eyes Forward");
    #endif
    _direction = 90;
    myservo.write(_direction);
    delay(_servoDelay); 
  }
}

void eyesleft() {
  #ifdef send
  Serial.print("Eyes Left   ");
  #endif
  _direction = 180;
  myservo.write(_direction);
  delay(_servoDelay); 
}

void eyesright() {
  #ifdef send
  Serial.print("Eyes Right  ");
  #endif
  _direction = 15;
  myservo.write(_direction);
  delay(_servoDelay); 
}

/* Ultrasonic distance measurement */
int getDistance()
{
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(20);
  digitalWrite(Trig, LOW);
  float Fdistance = pulseIn(Echo, HIGH);
  Fdistance = Fdistance / 58;

  if ((_direction != 90) || (Fdistance < tooClose)) {
    #ifdef send
      Serial.print(" - distance: ");
      Serial.println(Fdistance);
    #endif
  }

  return (int)Fdistance;
}

 /*Ultrasonic distance measurement Sub function*/
int Distance_test()   
{
  digitalWrite(Trig, LOW);   
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);  
  delayMicroseconds(20);
  digitalWrite(Trig, LOW);   
  float Fdistance = pulseIn(Echo, HIGH);  
  Fdistance= Fdistance/58;       
  return (int)Fdistance;
}  

void setup() 
{ 
  Serial.begin(9600);
  setupEyes();
//  myservo.attach(3);// attach servo on pin 3 to servo object
//  Serial.begin(9600);     
//  pinMode(Echo, INPUT);    
//  pinMode(Trig, OUTPUT);  
  car.stop();  
} 
//void setup() 
//{ 
//  car.stop();
//  car.setSpeed(car.medium);
//  eyes.forward();
//} 

void loop() 
{
    eyesforward();
    forwardDistance = getDistance();

//  forwardDistance = eyes.getDistance();
//  if (forwardDistance > tooClose)
  if (forwardDistance < tooClose)
  {     
    car.stop();
    delay(500);

      eyesleft();          
      leftDistance = getDistance();

      eyesright();              
      rightDistance = getDistance();
      Serial.println();
    
//    eyes.left();
//    leftDistance = eyes.getDistance();
//    eyes.right();
//    rightDistance = eyes.getDistance();
    
//    eyes.forward();
      eyesforward();
    
    if ((leftDistance < tooClose) || (rightDistance < tooClose))
    {
      // back up and turn around
      car.back();
      delay(500);
      // turn around by turning left twice
      car.left();
      delay(200);
      car.left();
      delay(200);
    }
    else if (leftDistance > rightDistance)
    {
      car.left();
      delay(200);
    }
    else if (rightDistance > leftDistance)
    {
      car.right();
      delay(200);
    }
  }
  else
  {
    car.forward();
  }

}


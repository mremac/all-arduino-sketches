#include <Servo.h>

const int trigPin = A4;
const int echoPin = A5;
const int leg1A = 2;
const int leg1B = 3;
const int leg2A = 6;
const int leg2B = 7;
const int leg3A = 8;
const int leg3B = 9;
const int leg4A = 10;
const int leg4B = 11;
Servo a;
Servo b;
Servo c;
Servo d;
String choice = "right";

long duration, inches, cm;
void setup(){
  // initialize serial communication:
  Serial.begin(9600);
}
void loop(){
  forward();
  microDelay(10);
  scan();
  if(cm < 60){
    int rannum = random(3);
      if(rannum == 1){
        for(int a = 0; cm < 20; a ++){
          right();
          right();
          right();
          scan();
          microDelay(50);
        }
          stabilise();
      } else{
        for(int a = 0; cm < 20; a ++){
          left();
          left();
          left();
          scan();
          microDelay(50);
      }
          stabilise();
    }
  }
}

void scan(){
  
  // establish variables for duration of the ping, 
  // and the distance result in inches and centimeters:
 
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
}
  
void forward(){
  a.attach(leg1A);
  b.attach(leg2A);
  c.attach(leg4A);
  d.attach(leg3A);
  for(int x = 0; x < 50; x++){
  a.write(140 - x);
  b.write(x);
  d.write(x);
  delay(10);
  }
  b.detach();
  d.detach();
  b.attach(leg1B);
  d.attach(leg4B);
  for(int x = 0; x < 135; x ++){
      a.write(x/2 + 90);
      b.write(120);
      c.write(180 - x);
      d.write(120);
      delay(10);
  }
  b.detach();
  d.detach();
  b.attach(leg1B);
  d.attach(leg4B);
  for(int x = 0; x < 50; x++){
  b.write(180);
  d.write(180);
  delay(10);
  }
  for(int x = 0; x < 135; x ++){
      a.write(180 - x);
      c.write(x + 45);
      delay(10);
  }
  a.detach();
  b.detach();
  c.detach();
  d.detach();
  //
  //
  //
  //
  a.attach(leg2A);
  b.attach(leg1A);
  c.attach(leg3A);
  d.attach(leg4A);
  for(int x = 0; x < 55; x++){
  b.write(180 - x);
  c.write(45 + x);
  d.write(180 - x);
  delay(10);
  }
  b.detach();
  d.detach();
  b.attach(leg2B);
  d.attach(leg3B);
  for(int x = 0; x < 135; x ++){
      a.write(x);
      b.write(20);
      c.write(90 - x/2);
      d.write(40);
      delay(10);
  }
  b.detach();
  d.detach();
  b.attach(leg2B);
  d.attach(leg3B);
  for(int x = 0; x < 50; x++){
  b.write(0);
  d.write(0);
  delay(10);
  }
  for(int x = 0; x < 135; x ++){
      a.write(135 - x);
      c.write(x);
      delay(10);
  }
  for(int x = 0; x < 50; x++){
  d.write(40);
  delay(1);
  }
  a.detach();
  b.detach();
  c.detach();
  d.detach();
}

void right(){
  a.attach(leg4A);
  b.attach(leg4B);
  for(int x = 45; x < 135; x ++){
    a.write(x);
    b.write(90 + abs(180 - 2*x));
    microDelay(0);
  }
  a.detach();
  b.detach();
  a.attach(leg2A);
  b.attach(leg2B);
  for(int x = 0; x < 90; x ++){
    a.write(45 + x);
    b.write(90 - abs(90 - 2*x));
    microDelay(0);
  }
  a.detach();
  b.detach();
  a.attach(leg1A);
  b.attach(leg1B);
  for(int x = 45; x < 135; x ++){
    a.write(x);
    b.write(90 + abs(180 - 2*x));
    microDelay(0);
  }
  a.detach();
  b.detach();
  a.attach(leg3A);
  b.attach(leg3B);
  for(int x = 0; x < 90; x ++){
    a.write(45 + x);
    b.write(90 - abs(90 - 2*x));
    microDelay(0);
  }
  a.detach();
  b.detach();
  a.attach(leg1A);
  b.attach(leg2A);
  c.attach(leg3A);
  d.attach(leg4A);
  for(int y = 0; y < 90; y ++){
    a.write(45);
    b.write(45);
    c.write(45);
    d.write(45);
    microDelay(0);
  }
  a.detach();
  b.detach();
  c.detach();
  d.detach();
}

void left(){
  a.attach(leg2A);
  b.attach(leg2B);
  for(int x = 45; x < 135; x ++){
    a.write(180 - x);
    b.write(90 - abs(90 - 2*x));
    microDelay(0);
  }
  a.detach();
  b.detach();
  a.attach(leg4A);
  b.attach(leg4B);
  for(int x = 0; x < 90; x ++){
    a.write(135 - x);
    b.write(90 + abs(90 - 2*x));
    microDelay(0);
  }
  a.detach();
  b.detach();
  a.attach(leg3A);
  b.attach(leg3B);
  for(int x = 45; x < 135; x ++){
    a.write(180 - x);
    b.write(90 - abs(90 - 2*x));
    microDelay(0);
  }
  a.detach();
  b.detach();
  a.attach(leg1A);
  b.attach(leg1B);
  for(int x = 0; x < 90; x ++){
    a.write(135 - x);
    b.write(90 + abs(90 - 2*x));
    microDelay(0);
  }
  a.detach();
  b.detach();
  a.attach(leg1A);
  b.attach(leg2A);
  c.attach(leg3A);
  d.attach(leg4A);
  for(int y = 0; y < 90; y ++){
    a.write(135);
    b.write(135);
    c.write(135);
    d.write(135);
    microDelay(0);
  }
  a.detach();
  b.detach();
  c.detach();
  d.detach();
}

void stabilise(){
  a.attach(leg2A);
  b.attach(leg2B);
  for(int x = 45; x < 135; x ++){
    a.write(90);
    b.write(90 - abs(90 - 2*x));
    microDelay(0);
  }
  a.detach();
  b.detach();
  a.attach(leg4A);
  b.attach(leg4B);
  for(int x = 0; x < 90; x ++){
    a.write(90);
    b.write(90 + abs(90 - 2*x));
    microDelay(0);
  }
  a.detach();
  b.detach();
  a.attach(leg3A);
  b.attach(leg3B);
  for(int x = 45; x < 135; x ++){
    a.write(90);
    b.write(90 - abs(90 - 2*x));
    microDelay(0);
  }
  a.detach();
  b.detach();
  a.attach(leg1A);
  b.attach(leg1B);
  for(int x = 0; x < 90; x ++){
    a.write(90);
    b.write(90 + abs(90 - 2*x));
    microDelay(0);
  }
  a.detach();
  b.detach();
}
 
long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}
 
long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

void microDelay(int additionaltime){
  delay(10 + additionaltime);
}

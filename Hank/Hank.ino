#include <Servo.h>

const int trigPin = A0;
const int echoPin = A1;
const int leg1A = 2;
const int leg1B = 3;
const int leg2A = 6;
const int leg2B = 7;
const int leg3A = 8;
const int leg3B = 9;
const int leg4A = 10;
const int leg4B = 11;

int piezo = 13;
Servo fan;
Servo a;
Servo b;
Servo c;
Servo d;
String choice = "right";

long duration, inches, cm;
void setup(){
  // initialize serial communication:
  Serial.begin(9600);
  pinMode(piezo, OUTPUT);
  fan.write(180);
}

void loop(){
  digitalWrite(piezo, LOW);
  forward();
  microDelay(10);
  scan();
  if(cm < 30){
    if(choice == "right"){
      left();
      left();
      choice = "left";
    } else{
      right();
      right();
      choice = "right";
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
  int dl = 5;
  int mx = 180;
  a.attach(leg1A);
  b.attach(leg2A);
  c.attach(leg3B);
  d.attach(leg4B);
  for(int x = 0; x < 90; x ++){
    a.write(135);
    b.write(0);
    c.write(90);
    d.write(90);
    delay(dl);
  }
//  delay(1000);
  a.detach();
  b.detach();
  c.detach();
  d.detach();
  a.attach(leg3A);
  b.attach(leg4A);
  c.attach(leg1B);
  d.attach(leg2B);
  for(int x = 0; x < 135; x ++){
    a.write(135 - x);
    b.write(x);
    c.write(0);
    d.write(180);
    delay(dl);
  }
//  delay(500);
  a.detach();
  b.detach();
  a.attach(leg3B);
  b.attach(leg4B);
  for(int x = 0; x < 90; x ++){
    c.write(0);
    d.write(180);
    delay(dl);
  }
  a.detach();
  b.detach();
  c.detach();
  d.detach();
  a.attach(leg3A);
  b.attach(leg4A);
  c.attach(leg1B);
  d.attach(leg2B);
  for(int x = 0; x < 90; x ++){
    a.write(135); 
    b.write(0);
    c.write(90);
    d.write(90);
    delay(dl);
  }
//  delay(1000);
  a.detach();
  b.detach();
  c.detach();
  d.detach();
  a.attach(leg1A);
  b.attach(leg2A);
  c.attach(leg3B);
  d.attach(leg4B);
  for(int x = 0; x < 135; x ++){
    a.write(135 - x);
    b.write(x);
    c.write(90);
    d.write(90);
    delay(dl);
  }
//  delay(500); 
  c.detach();
  d.detach();
  c.attach(leg1B);
  d.attach(leg2B);
  for(int x = 0; x < 90; x ++){
    c.write(0);
    d.write(180);
    delay(dl);
  }
  a.detach();
  b.detach();
  c.detach();
  d.detach();
}

void right(){
  int dl = 5;
  int mx = 180;
  a.attach(leg1A);
  b.attach(leg2A);
  c.attach(leg3B);
  d.attach(leg4B);
  for(int x = 0; x < 90; x ++){
    a.write(0);
    b.write(0);
    c.write(90);
    d.write(90);
    delay(dl);
  }
//  delay(1000);
  a.detach();
  b.detach();
  c.detach();
  d.detach();
  a.attach(leg3A);
  b.attach(leg4A);
  c.attach(leg1B);
  d.attach(leg2B);
  for(int x = 0; x < 135; x ++){
    a.write(x);
    b.write(x);
    c.write(0);
    d.write(180);
    delay(dl);
  }
//  delay(500);
  a.detach();
  b.detach();
  a.attach(leg3B);
  b.attach(leg4B);
  for(int x = 0; x < 90; x ++){
    c.write(0);
    d.write(180);
    delay(dl);
  }
  a.detach();
  b.detach();
  c.detach();
  d.detach();
  a.attach(leg3A);
  b.attach(leg4A);
  c.attach(leg1B);
  d.attach(leg2B);
  for(int x = 0; x < 90; x ++){
    a.write(0); 
    b.write(0);
    c.write(90);
    d.write(90);
    delay(dl);
  }
//  delay(1000);
  a.detach();
  b.detach();
  c.detach();
  d.detach();
  a.attach(leg1A);
  b.attach(leg2A);
  c.attach(leg3B);
  d.attach(leg4B);
  for(int x = 0; x < 135; x ++){
    a.write(x);
    b.write(x);
    c.write(90);
    d.write(90);
    delay(dl);
  }
//  delay(500); 
  c.detach();
  d.detach();
  c.attach(leg1B);
  d.attach(leg2B);
  for(int x = 0; x < 90; x ++){
    c.write(0);
    d.write(180);
    delay(dl);
  }
  a.detach();
  b.detach();
  c.detach();
  d.detach();
}

void left(){
  int dl = 5;
  int mx = 180;
  a.attach(leg1A);
  b.attach(leg2A);
  c.attach(leg3B);
  d.attach(leg4B);
  for(int x = 0; x < 90; x ++){
    a.write(135);
    b.write(135);
    c.write(90);
    d.write(90);
    delay(dl);
  }
//  delay(1000);
  a.detach();
  b.detach();
  c.detach();
  d.detach();
  a.attach(leg3A);
  b.attach(leg4A);
  c.attach(leg1B);
  d.attach(leg2B);
  for(int x = 0; x < 135; x ++){
    a.write(135 - x);
    b.write(135 - x);
    c.write(0);
    d.write(180);
    delay(dl);
  }
//  delay(500);
  a.detach();
  b.detach();
  a.attach(leg3B);
  b.attach(leg4B);
  for(int x = 0; x < 90; x ++){
    c.write(0);
    d.write(180);
    delay(dl);
  }
  a.detach();
  b.detach();
  c.detach();
  d.detach();
  a.attach(leg3A);
  b.attach(leg4A);
  c.attach(leg1B);
  d.attach(leg2B);
  for(int x = 0; x < 90; x ++){
    a.write(135); 
    b.write(135);
    c.write(90);
    d.write(90);
    delay(dl);
  }
//  delay(1000);
  a.detach();
  b.detach();
  c.detach();
  d.detach();
  a.attach(leg1A);
  b.attach(leg2A);
  c.attach(leg3B);
  d.attach(leg4B);
  for(int x = 0; x < 135; x ++){
    a.write(135 - x);
    b.write(135 - x);
    c.write(90);
    d.write(90);
    delay(dl);
  }
//  delay(500); 
  c.detach();
  d.detach();
  c.attach(leg1B);
  d.attach(leg2B);
  for(int x = 0; x < 90; x ++){
    c.write(0);
    d.write(180);
    delay(dl);
  }
  a.detach();
  b.detach();
  c.detach();
  d.detach();
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

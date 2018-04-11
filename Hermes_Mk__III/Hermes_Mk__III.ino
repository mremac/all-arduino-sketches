#include <Servo.h>

const int trigPin = A4;
const int echoPin = A5;
Servo a;
Servo b;
Servo c;
Servo d;
long duration, inches, cm;
void setup(){
  // initialize serial communication:
  Serial.begin(9600);
}
void loop(){
  forward();
  delay(10);
  scan();
  delay(10);
  if(cm < 20){
    for(int a = 0; cm < 20; a ++){
      right();
      right();
      right();
      scan();
      delay(50);
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
  a.attach(6);
  b.attach(7);
  c.attach(12);
  d.attach(9);
  for(int x = 0; x < 90; x ++){
    a.write(90 + x);
    b.write(90 + abs(2*x - 90));
    c.write(90 - x);
    d.write(135);
    delay(5);
  }
  a.detach();
  b.detach();
  c.detach();
  d.detach();
  a.attach(8);
  b.attach(9);
  c.attach(2);
  d.attach(7);
  for(int x = 0; x < 90; x ++){
    a.write(180 - x);
    b.write(90 + abs(2*x - 90));
    c.write(x);
    d.write(135);
    delay(5);
  }
  a.detach();
  b.detach();
  c.detach();
  d.detach();
  a.attach(2);
  b.attach(3);
  c.attach(8);
  d.attach(13);
  for(int x = 0; x < 90; x ++){
    a.write(90 - x);
    b.write(90 - abs(2*x - 90));
    c.write(45 + x);
    d.write(45);
    delay(5);
  }
  for(int y = 0; y < 10; y ++){
    d.write(0);
    delay(5);
  }
  a.detach();
  b.detach();
  c.detach();
  d.detach();
  a.attach(12);
  b.attach(13);
  c.attach(6);
  d.attach(3);
  for(int x = 0; x < 90; x ++){
    a.write(x);
    b.write(90 - abs(2*x - 90));
    c.write(135 - x);
    d.write(45);
    delay(5);
  }
  a.detach();
  b.detach();
  c.detach();
  d.detach();
}

void right(){
  a.attach(6);
  b.attach(7);
  for(int x = 0; x < 90; x ++){
    a.write(90 + x);
    b.write(100 + abs(90 - 2*x));
    delay(5);
  }
  a.detach();
  b.detach();
  a.attach(2);
  b.attach(3);
  for(int x = 0; x < 90; x ++){
    a.write(x);
    b.write(80 - abs(90 - 2*x));
    delay(5);
  }
  a.detach();
  b.detach();
  a.attach(8);
  b.attach(9);
  for(int x = 0; x < 90; x ++){
    a.write(90 + x);
    b.write(100 + abs(90 - 2*x));
    delay(5);
  }
  a.detach();
  b.detach();
  a.attach(12);
  b.attach(13);
  for(int x = 0; x < 90; x ++){
    a.write(x);
    b.write(80 - abs(90 - 2*x));
    delay(5);
  }
  a.detach();
  b.detach();
  a.attach(2);
  b.attach(6);
  c.attach(8);
  d.attach(12);
  for(int y = 0; y < 90; y ++){
    a.write(0);
    b.write(90);
    c.write(90);
    d.write(0);
    delay(5);
  }
  a.detach();
  b.detach();
  c.detach();
  d.detach();
}

void left(){
  a.attach(2);
  b.attach(3);
  for(int x = 0; x < 90; x ++){
    a.write(90 - x);
    b.write(80 - abs(90 - 2*x));
    delay(5);
  }
  a.detach();
  b.detach();
  a.attach(6);
  b.attach(7);
  for(int x = 0; x < 90; x ++){
    a.write(180 - x);
    b.write(100 + abs(90 - 2*x));
    delay(5);
  }
  a.detach();
  b.detach();
  a.attach(12);
  b.attach(13);
  for(int x = 0; x < 90; x ++){
    a.write(90 - x);
    b.write(80 - abs(90 - 2*x));
    delay(5);
  }
  a.detach();
  b.detach();
  a.attach(8);
  b.attach(9);
  for(int x = 0; x < 90; x ++){
    a.write(180 - x);
    b.write(100 + abs(90 - 2*x));
    delay(5);
  }
  a.detach();
  b.detach();
  a.attach(2);
  b.attach(6);
  c.attach(8);
  d.attach(12);
  for(int y = 0; y < 90; y ++){
    a.write(90);
    b.write(180);
    c.write(180);
    d.write(90);
    delay(5);
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

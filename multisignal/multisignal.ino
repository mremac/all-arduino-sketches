#include <Servo.h>

Servo aa;
Servo ab;
Servo ba;
Servo bb;
int aaPin = 7;
int abPin = 6;
int baPin = 3;
int bbPin = 2;

void setup(){
  Serial.begin(9600);
  aa.attach(aaPin);
  ab.attach(abPin);
  ba.attach(baPin);
  bb.attach(bbPin);
}

void loop(){
  while(Serial.available() == 1);
  int val = Serial.read();
  aa.write(val);
  ab.write(180-val);
  ba.write(val);
  bb.write(180-val);
}

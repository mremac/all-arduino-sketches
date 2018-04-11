#include <Servo.h>

Servo aa;
Servo ab;
Servo ac;
Servo ad;
Servo ba;
Servo bb;
Servo bc;
Servo bd;
int aaPin = 7;
int abPin = 2;
int acPin = 10;
int adPin = 8;
int baPin = 3;
int bbPin = 6;
int bcPin = 11;
int bdPin = 9;
int indicator = 0;

void setup(){
  Serial.begin(9600);
  aa.attach(aaPin);
  ab.attach(abPin);
  ac.attach(acPin);
  ad.attach(adPin);
  ba.attach(baPin);
  bb.attach(bbPin);
  bc.attach(bcPin);
  bd.attach(bdPin);
}

void loop(){
  while(Serial.available() == 1);
  int val = Serial.read();
  if(indicator == 0){
  aa.write(180 - val);
  ab.write(val);
  ac.write(180 - val);
  ad.write(val);
  indicator = 1;
  } else if(indicator == 1){
  ba.write(90 - val);
  bb.write(90 - val);
  bc.write(90 - val);
  bd.write(90 - val);
  indicator = 0;
  }
}

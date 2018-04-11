#include <Servo.h>

Servo aa;
Servo ab;
Servo ba;
Servo bb;
int aaPin = 7;
int abPin = 2;
int baPin = 6;
int bbPin = 3;
int indicator = 0;

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
  if(val < 100 ){
  if(indicator == 0){
  ba.write(2*val - 45);
  indicator = 1;
  } else if(indicator == 1){
  bb.write(315 - 4*val);
  indicator = 0;
  }
  } else{
  aa.write(270 - 2*val);
  ab.write(2*val - 110);
  }
  delay(10);
}

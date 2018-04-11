#include <Servo.h>

Servo aa;
Servo ab;
Servo ba;
Servo bb;
int aaPin = 2;
int abPin = 3;
int baPin = 6;
int bbPin = 7;


void setup() {
  aa.attach(aaPin);
  ab.attach(abPin);
  ba.attach(baPin);
  bb.attach(bbPin);
}

void loop() {
  for(int i=0; i<180; i++){
  aa.write(i);
  ab.write(i);
  ba.write(i);
  bb.write(i);
  delay(5);
  }
  delay(1000);
  for(int i=180; i>0; i--){
  aa.write(i);
  ab.write(i);
  ba.write(i);
  bb.write(i);
  delay(5);
  }
} 

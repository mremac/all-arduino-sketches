#include <Servo.h>
  Servo aa;
  Servo ab;
  Servo ba;
  Servo bb;
  int aaPin = 2;
  int abPin = 6;
  int baPin = 3;
  int bbPin = 7;
  int w = 90;
  int x = 90;
  int y = 90;
  int z = 90;

void setup(){
  aa.attach(aaPin);
  ab.attach(abPin);
  ba.attach(baPin);
  bb.attach(bbPin);
  Serial.begin(9600);
}

void loop(){
  int input = Serial.read();
  if(input = ('A')){
    w--;
    aa.write(w);
  }
  if(input = ('D')){
    w++;
    aa.write(w);
  }
  if(input = ('W')){
    x++;
    ba.write(x);
  }
  if(input = ('S')){
    x--;
    ba.write(x);
  }
}

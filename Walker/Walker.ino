#include <Servo.h>
Servo aa;
Servo ab;
Servo ac;
Servo ad;
Servo ba;
Servo bb;
Servo bc;
Servo bd;
int aaPin = 2;
int abPin = 3;
int acPin = 4;
int adPin = 5;
int baPin = 6;
int bbPin = 7;
int bcPin = 8;
int bdPin = 9;
void setup(){
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
  int i;
  int X = 120;
  for(i = 0; i < X; i ++){
    aa.write(i);
    ab.write(i);
    ac.write(X - i);
    ad.write(X - i);
    ba.write(X*i - i*i);
    bb.write(X*i - i*i);
  }
  for(i = 0; i < X; i ++){
    aa.write(X - i);
    ab.write(X - i);
    ac.write(i);
    ad.write(i);
    bc.write(X*i - i*i);
    bd.write(X*i - i*i);
  }
}

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
int abPin = 6;
int acPin = 8;
int adPin = 10;
int baPin = 3;
int bbPin = 7;
int bcPin = 9;
int bdPin = 11;
int X;
void setup(){
  aa.attach(aaPin);
  ab.attach(abPin);
  ac.attach(acPin);
  ad.attach(adPin);
  ba.attach(baPin);
  bb.attach(bbPin);
  bc.attach(bcPin);
  bd.attach(bdPin);
  X = 45;
  aa.write(0);
  ab.write(0);
  ac.write(0);
  ad.write(0);
  ba.write(0);
  bb.write(0);
  bc.write(0);
  bd.write(0);
}
void loop(){
  int i;
  for(i = 0; i < X; i ++){
    aa.write(i);
    ab.write(i);
    ac.write(i);
    ad.write(i);
    ba.write(X - i);
    bb.write(X - i);
  delay(100);
  }
  delay(1000);
  i = X;
  for(i = X; i > 0; i --){
    aa.write(i);
    ab.write(i);
    ac.write(i);
    ad.write(i);
    bc.write(X - i);
    bd.write(X - i);
  delay(100);
  }
  delay(1000);
}

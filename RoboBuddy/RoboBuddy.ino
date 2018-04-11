#include <Servo.h>

Servo aa;
Servo ab;
Servo ba;
Servo bb;
int aaPin = 7;
int abPin = 2;
int baPin = 6;
int bbPin = 3;

void setup(){
  aa.attach(aaPin);
  ab.attach(abPin);
  ba.attach(baPin);
  bb.attach(bbPin);
}
int i;
int b;
void loop(){
  i = 0;
  for(i = 0; i <= 40; i ++){
    int x = 70 + i;
    aa.write(x);
    int y = 70 + i;
    ab.write(y);
    int a = 20 - pow((0.2*i-8), 2);
    if(a >= 0){
      b = a;
    }
    ba.write(b);
    delay(10);
  }
  delay(100);
  for(i = 40; i >= 0; i --){
    int x = 70 + i;
    aa.write(x);
    int y = 70 + i;
    ab.write(y);
    int a = 20 - pow((0.2*i-8), 2);
    if(a >= 0){
      b = a;
    }
    bb.write(b);
    delay(10);
  }
}

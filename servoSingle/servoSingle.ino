#include <Servo.h>
#include <Serial.h>

Servo aa;
int aaPin = 7;

void setup(){
  Serial.begin(9600);
  aa.attach(aaPin);
}

void loop(){
  aa.write(90);
  delay(1000);
  if(Serial.available() == 1){
    int val = Serial.read();
    aa.write(val);
  }
  delay(1000);
  aa.write(0);
  delay(1000);
}



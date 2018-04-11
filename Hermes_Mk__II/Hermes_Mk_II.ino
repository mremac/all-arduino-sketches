#include <Servo.h>

Servo a;
Servo b;
Servo c;
Servo d;
void setup(){
}
void loop(){
  for(int x = 0; x < 15; x ++){
  forward();
  delay(5);
  }
  delay (500);
  for(int x = 0; x < 8; x ++){
  right();
  delay(5);
  }
  delay (500);
  for(int x = 0; x < 15; x ++){
  forward();
  delay(5);
  }
  delay (500);
  for(int x = 0; x < 8; x ++){
  left();
  delay(5);
  }
  delay (500);
}

void forward(){
  a.attach(2);
  b.attach(3);
  c.attach(8);
  d.attach(11);
  for(int x = 0; x < 90; x ++){
    a.write(x);
    b.write(90 - abs(2*x - 90));
    c.write(180 - x);
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
  a.attach(6);
  b.attach(7);
  c.attach(10);
  d.attach(9);
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
  a.attach(8);
  b.attach(9);
  c.attach(3);
  d.attach(7);
  for(int x = 0; x < 90; x ++){
    a.write(90 + x);
    b.write(90 + abs(2*x - 90));
    c.write(15);
    d.write(90);
    delay(5);
  }
  a.detach();
  b.detach();
  c.detach();
  d.detach();
  a.attach(10);
  b.attach(11);
  c.attach(7);
  d.attach(3);
  for(int x = 0; x < 90; x ++){
    a.write(90 - x);
    b.write(90 - abs(2*x - 90));
    c.write(180);
    d.write(90);
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
  a.attach(10);
  b.attach(11);
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
  d.attach(10);
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
  a.attach(10);
  b.attach(11);
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
  d.attach(10);
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

#include <Servo.h>
#include <math.h>
float deltaY, deltaZ, phi, theta, mu;
int radA, radB;
Servo baseL;
Servo baseR;
Servo joint;
Servo wristPitch;
int i = 0;
int x = 0;
bool thi = true;

void setup(){
  baseL.attach(4);
  baseR.attach(5);
  joint.attach(6);
  wristPitch.attach(7);
  baseL.write(0);
  baseR.write(0);
  joint.write(0);
  wristPitch.write(0);
  delay(50);
  radA = 200;
  radB = 120;
  deltaY = -100;
  deltaZ = 0;

  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Arm test!");
}

void loop(){
  delay(5);
  x ++;
  if(x == 10){
    x = 0;
    if(thi){
      i ++;
    } else{
      i --;
    }
  }
  if(i == 90){
    thi = false;
  } else if(i == 0){
    thi = true;
  }
  joint.write(120 - i);
  baseL.write(180 - i);
  baseR.write(i);
  wristPitch.write(180);
  
//  if (Serial.available())
//  {
//     goTo(Serial.read(), Serial.read());
//  }
}

void goTo(int d, int h){
  d = d - 220;
  float x0, y0;
  x0 = (1/(2*d))*(pow(radA, 2) - pow(radB, 2) + d*d + h*h);
  y0 = (1/(2*h))*(pow(radA, 2) - pow(radB, 2) + d*d + h*h);
  phi = atan(y0/x0);
  float beta = atan((h - y0)/(d - x0));
  theta = beta - deltaY;
  //IMPROVE THIS ASSHOLE
  baseL.write(phi);
  baseR.write(180 - phi);
  joint.write(theta);
  mu = phi - theta - deltaY - deltaZ;
  wristPitch.write(mu);
}

#include <AFMotor.h>

const int ledPin = 13;
 
AF_Stepper motorR(100, 2);
AF_Stepper motorL(100, 1);
 
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Stepper test!");
 
  motorR.setSpeed(70);  // 10 rpm   
  motorR.step(100, FORWARD, INTERLEAVE); 
  motorR.release();

  
  motorL.setSpeed(70);  // 10 rpm   
  motorL.step(100, FORWARD, INTERLEAVE); 
  motorL.release();

  
  delay(1000);
}

void forw(int rFactor, int lFactor){
  motorR.step(rFactor, FORWARD, DOUBLE); 
  motorL.step(lFactor, BACKWARD, DOUBLE);
}

void back(int rFactor, int lFactor){
  motorR.step(rFactor, BACKWARD, DOUBLE); 
  motorL.step(lFactor, FORWARD, DOUBLE);
}

void spincw(int speed){
  motorR.step(speed, FORWARD, DOUBLE); 
  motorL.step(speed, FORWARD, DOUBLE);
}

void spinccw(int speed){
  motorR.step(speed, BACKWARD, DOUBLE); 
  motorL.step(speed, BACKWARD, DOUBLE);
}
 
void loop() {
  Serial.println("Hello Pi");
  if (Serial.available())
  {
     flash(Serial.read());
  }
}

void flash(int n)
{
  Serial.println(n);
  if(n == 49){
  //FORWARD

  for(int i = 0; i < 50; i++){
    forw(1, 1);
  }

//    delay(500);
} else if(n==50){
  
  //BACKWARD
  
  for(int i = 0; i < 50; i++){
    back(1, 1);
  }

//    delay(500);

} else if(n==51){

  //SPIN CW
  
  for(int i = 0; i < 50; i++){
    spincw(1);
  }

//    delay(500);

} else if(n==52){

  //SPIN CCW
  
  for(int i = 0; i < 50; i++){
    spinccw(1);
  }

//    delay(500);

} else if(n==53){

  //TURN RIGHT

  for(int i = 0; i < 50; i++){
    forw(2, 1);
  }

//    delay(500);

} else if(n==54){

  //TURN LEFT

  for(int i = 0; i < 50; i++){
    forw(1, 2);
  }

//    delay(500);

} else if(n=55){

  //BACKTURN LEFT

  for(int i = 0; i < 50; i++){
    back(2, 1);
  }

//    delay(500);

} else if(n==56){

  //BACKTURN RIGHT

  for(int i = 0; i < 50; i++){
    back(1, 2);
  }

//    delay(500);
}

//Serial.println(n);
}

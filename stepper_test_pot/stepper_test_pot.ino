#include <AFMotor.h>
#include <Stepper.h>
// input pin for the potentiometer
int read_potentiometer = A0;
int value_potentiometer = 0;

AF_Stepper motorL(100, 1);

void setup()
{
  Serial.begin(9600);// set up Serial library at 9600 bps
  Serial.println("Stepper test!");

    
  motorL.setSpeed(70);  // 10 rpm   
  motorL.step(100, FORWARD, INTERLEAVE); 
  motorL.release();

  delay(1000);
}

void loop() {
  value_potentiometer = analogRead(read_potentiometer); 

  Serial.println(value_potentiometer/4.5);
  if(value_potentiometer > 80){
    motorL.setSpeed(value_potentiometer/4.5);  // 10 rpm 
    motorL.step(5, FORWARD, DOUBLE); 
  }
}



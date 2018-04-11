#include <AFMotor.h>
 
AF_Stepper motorR(200, 1);
int led_pin = 13;


void setup()
{
  pinMode(led_pin, OUTPUT);
  digitalWrite(led_pin, LOW);
  
  motorR.setSpeed(50);  // 10 rpm   
  motorR.step(100, FORWARD, SINGLE); 
  motorR.release();
}

void loop()
{
  printVolts();
}
 
 void printVolts()
{
  int sensorValue = analogRead(A9); //read the A0 pin value
  float voltage = sensorValue * (5.00 / 1023.00) * 2; //convert the value to a true voltage.
  
//  digitalWrite(led_pin, HIGH);
//  delay(voltage*1000);
//  digitalWrite(led_pin, LOW);
//  delay(1000);
  if(voltage <= 8){
    digitalWrite(led_pin, HIGH);
  } else{
    digitalWrite(led_pin, LOW);
    motorR.step(2, FORWARD, DOUBLE);
  }
}

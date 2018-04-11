#include <Servo.h>

int arm = 1;
Servo armServo;
void setup() {
  // put your setup code here, to run once:
  armServo.attach(arm);
}

void loop() {
  for(int i = 0; i < 90; i ++){
    armServo.write(0);
    delay(20);
  }
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 90; i ++){
    armServo.write(i);
    delay(20);
  }
}

#include <IRremote.h>

int DS_pin = 8;
int STCP_pin = 9;
int SHCP_pin = 10;
//IRrecv irrecv(6);
decode_results results;

void setup() {
  pinMode(DS_pin, OUTPUT);
  pinMode(STCP_pin, OUTPUT);
  pinMode(SHCP_pin, OUTPUT);
  Serial.begin(9600);
//  irrecv.enableIRIn();
  writeReg();
}
boolean registers[8];
// the loop routine runs over and over again forever:
void loop() {
  int maybe = digitalRead(11);
  Serial.println(maybe);
  // read the input on analog pin 0:
//  if (irrecv.decode(&results)) {
//    irrecv.resume(); // Receive the next value
//  }
  // print out the value you read:
  for(int i = 0; i <= 8; i++) {
    registers[i] = HIGH;
    delay(500);
    writeReg();
  }
  for(int i = 0; i <= 8; i++) {
    registers[i] = LOW;
    delay(500);
    writeReg();
  }
  delay(1);        // delay in between reads for stability
}

void writeReg() {
  digitalWrite(SHCP_pin, LOW);
  for(int i = 0; i < 8; i ++){
    digitalWrite(STCP_pin, HIGH);
    digitalWrite(DS_pin, registers[i]);
    digitalWrite(STCP_pin, LOW);
  }
  digitalWrite(SHCP_pin, HIGH);
//  if (irrecv.decode(&results)) {
  int maybe = digitalRead(11);
  Serial.println(maybe);
//    irrecv.resume(); // Receive the next value
//  }
}

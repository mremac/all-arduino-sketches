#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>
RF24 radio(9, 10); // CNS, CE
const byte address[6] = "00001";
void setup() {
  radio.begin();
  //radio.setRetries(15, 15);
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  Serial.begin(9600);
}

void loop() {
//  if(radio.available()){
  const char text[] = "Hello World";
  Serial.println(text);
  radio.write(&text, sizeof(text));
  Serial.println(text);
  delay(1000);
//  }
} 
 

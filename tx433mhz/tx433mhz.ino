#define rfTransmitPin 4  //RF Transmitter pin = digital pin 4
 #define ledPin 13        //Onboard LED = digital pin 13
 #define joy1 A0
 #define joy2 A1

 void setup(){
   pinMode(rfTransmitPin, OUTPUT);     
   pinMode(ledPin, OUTPUT);    
   Serial.begin(9600);
 }

 void loop(){
//   for(int i=4000; i>5; i=i-(i/3)){
     int i = 100;
     int value1 = analogRead(joy1);
     int value2 = analogRead(joy2);
     Serial.println(value1/5);
     Serial.println(value2/5);
     
     digitalWrite(rfTransmitPin, HIGH);     //Transmit a HIGH signal
     digitalWrite(ledPin, HIGH);            //Turn the LED on
     delay(value1/5);                           //Wait for 1 second
     
     digitalWrite(rfTransmitPin,LOW);      //Transmit a LOW signal
     digitalWrite(ledPin, LOW);            //Turn the LED off
     delay(value2/5);                            //Variable delay
     Serial.println(i);
//   }
 }

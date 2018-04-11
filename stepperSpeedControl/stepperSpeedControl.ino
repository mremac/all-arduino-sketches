#include <Stepper.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define rfReceivePin A0  //RF Receiver pin = Analog pin 0

 unsigned int data = 0;   // variable used to store received data
 const unsigned int upperThreshold = 400;  //upper threshold value
 const unsigned int lowerThreshold = 50;  //lower threshold value

 bool sampling = false;
 bool endSampling = false;
 int zeros = 0;
 int nonzeros = 0;
 int rezeros = 0;
  int x = 0;
  int y = 0;
  int r = 0;
  int l = 0;

RF24 radio(9, 10); // CE, CSN
const byte address[6] = "00001";
const int stepsPerRevolution = 100;  
// ^^change this to fit the number of steps per revolution
// for your motor
Stepper myStepper(stepsPerRevolution, 2, 1, 3, 4);
Stepper othStepper(stepsPerRevolution, 5, 6, 7, 8);

int stepCount = 0;  // number of steps the motor has taken

void setup() {
  Serial.begin(9600);
}

void loop() {
   data=analogRead(rfReceivePin);    //listen for data on Analog pin 0
   if(data<lowerThreshold){
//     Serial.println(data);
     zeros ++;
   }

   if(zeros >5){
    sampling = true;
   }
   
   while(sampling == true){
    if(r > 0 && l > 0){
      myStepper.setSpeed(r);
      // step 1/100 of a revolution:
      myStepper.step(stepsPerRevolution / 100);
      othStepper.setSpeed(l);
      // step 1/100 of a revolution:
      othStepper.step(stepsPerRevolution / 100);
    }
    
     delay (5);
     data=analogRead(rfReceivePin);    //listen for data on Analog pin 0
     if(data<lowerThreshold){
//       Serial.println(data);
       if (endSampling == true){
         rezeros ++;
       }else{
         zeros ++;
       }
     }
     if(data>upperThreshold){
//       Serial.println(data);
       nonzeros ++;
     }
     if(nonzeros >5){
      endSampling = true;
     }

     if(rezeros >5){
       sampling = false;
       endSampling = false;
       x = zeros;
       y = nonzeros;
       zeros = 0;
       nonzeros = 0;
       rezeros = 0;
//    Serial.print("x:");
//    Serial.println(x);
//    Serial.print("y:");
//    Serial.println(y);
     }
   }

   
   if(sampling == false){
    // read the sensor value:
    int sensorReading = 1000;

    // map it to a range from 0 to 100:
    //    int motorSpeed = map(sensorReading, 0, 1023, 0, 100);
    int motorSpeed = 100;
    // set the motor speed:
    if(x > 0 && y > 0){
      r = y + x - 15;
      l = y - x;
      r = r*7;
      l = l*7;
      Serial.print("R:");
      Serial.println(r);
      Serial.print("L:");
      Serial.println(l);
    if (r > 0 && l > 0) {
      myStepper.setSpeed(r);
      // step 1/100 of a revolution:
      myStepper.step(stepsPerRevolution / 100);
      othStepper.setSpeed(l);
      // step 1/100 of a revolution:
      othStepper.step(stepsPerRevolution / 100);
      }
//    zeros = 0;
//    nonzeros = 0;
   }
   }
}


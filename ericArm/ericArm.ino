#include <Servo.h>

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false; 
Servo eyeTilt; Servo topLip; Servo bottomLip; 
Servo lidBlink; Servo eyeTurn; Servo headTurn; 
Servo headNod;

String inData;

int topLipPos;

char chone;
char chtwo;
char chthree;


int bottomLipPos;

int eyeTiltMax = 160;
int eyeTiltMin =100;

int topLipMax = 180;
int topLipMin = 0;

int bottomLipMax = 180;
int bottomLipMin = 0;

int lidBlinkMax = 180;
int lidBlinkMin = 0;

int eyeTurnMax = 180;
int eyeTurnMin = 0;

int headTurnMax = 150;
int headTurnMin = 0;

int headNodMax = 120;
int headNodMin = 10;






void setup() {

  //servo1.setMaximumPulse(2000);
  //servo1.setMinimumPulse(700);

  
  topLipPos = (topLipMin+topLipMax)/2;
  bottomLipPos = (bottomLipMin+bottomLipMax)/2;

  
  //pinMode(1,OUTPUT);
  eyeTilt.attach(8); //analog pin 0
  topLip.attach(6); //analog pin 1
  bottomLip.attach(7); //analog pin 1
  lidBlink.attach(5); //analog pin 1
  eyeTurn.attach(4); // good
  headTurn.attach(3); //analog pin 1
  headNod.attach(2); // good
  Serial.begin(19200);
  
  Serial.println("Ready");


 reset();

 //eyeTiltWrite(60);

}

// Buffer to store incoming commands from serial port




void loop() {

  
    while (Serial.available() > 0)
    {
        char recieved = Serial.read();
         
        // Process message when new line character is recieved
        inData += recieved;
        if (recieved == '$')
        {
            inData.remove(inData.length()-1,1);
            Serial.println("Arduino Received: ");
            Serial.println(inData);
       
            processInput(inData);
            
            
            inData = ""; // Clear recieved buffer
        }
        
    }

    
}


void processInput(String data)

{
  Serial.println("processInput");
  char motorRef = data.charAt(0);
  data.remove(0,1);

  Serial.println("motorRef:");
  Serial.println(motorRef);
  
  int motorPos = data.toInt();

  Serial.println("to:");
  Serial.println(motorPos);

if (motorRef == 'q')
{
  float scale = eyeTiltMax - eyeTiltMin; 
 
  scale = scale/100*motorPos;
  
  motorPos = eyeTurnMin + scale;
  eyeTiltWrite(motorPos);
}

if (motorRef == 'w')
{
  float scale = topLipMax - topLipMin; 
 
  scale = scale/100*motorPos;
  
  motorPos = topLipMin +scale;
  topLipWrite(motorPos);
}

if (motorRef == 'e')
{
  float scale = bottomLipMax - bottomLipMin; 
 
  scale = scale/100*motorPos;
  
  motorPos = bottomLipMin +scale;
  bottomLipWrite(motorPos);
}

if (motorRef == 'r')
{
  float scale = lidBlinkMax - lidBlinkMin; 
 
  scale = scale/100*motorPos;
  
  motorPos = lidBlinkMin +scale;
  lidBlinkWrite(motorPos);
}

if (motorRef == 't')
{
  float scale = eyeTurnMax - eyeTurnMin; 
 
  scale = scale/100*motorPos;
  
  motorPos = eyeTurnMin +scale;
  eyeTurnWrite(motorPos);
}

 if (motorRef == 'y')
{
  float scale = headTurnMax - headTurnMin; 
 
  scale = scale/100*motorPos;
  
  motorPos = headTurnMin +scale;
  headTurnWrite(motorPos);
}

 if (motorRef == 'u')
{
    float scale = headNodMax - headNodMin; 
 
  scale = scale/100*motorPos;
  
  motorPos = headNodMin +scale;
  headNodWrite(motorPos);
}
 
        

  
}

//void serialEvent() {
//
//int  v = 0;
//  while (Serial.available()) {
//    // get the new byte:
//    char ch = (char)Serial.read();
//    // add it to the inputString:

//  switch(ch) {
//      
//        case 'q':
//          
//          chone = (char)Serial.read();
//          chtwo = (char)Serial.read();
//          chthree = (char)Serial.read();
//          v = (int)chone + chtwo + chthree;
//          Serial.println(v);
//          eyeTiltWrite(v);
//          v = 0;
//          break;
//        case 'w':
//         // topLipWrite(v);
//          v = 0;
//          break;
//        case 'e':
//          //bottomLipWrite(v);
//          v = 0;
//          break;
//        case 'r':
//          lidBlinkWrite(v);
//          v = 0;
//          break;
//        case 't':
//          eyeTurnWrite(v);
//          v = 0;
//          break;
//        case 'y':
//          headTurnWrite(v);
//          v = 0;
//          break;
//        case 'u':
//          headNodWrite(v);
//          v = 0;
//          break;
//      }
//
//    
//    inputString += inChar;
//    // if the incoming character is a newline, set a flag
//    // so the main loop can do something about it:
//    if (inChar == '\n') {
//      stringComplete = true;
//    }
//  }
//}

//void loop() {
//
////static int v = 0;
////
////if ( Serial.available()) {
////char ch = Serial.read();
////
////switch(ch) {
////  case '0'...'9':
////    v =  ch - '0';
////    Serial.println(v);
////    break;
////  case 'q':
////    eyeTiltWrite(v);
////    v = 0;
////    break;
////  case 'w':
////   // topLipWrite(v);
////    v = 0;
////    break;
////  case 'e':
////    //bottomLipWrite(v);
////    v = 0;
////    break;
////  case 'r':
////    lidBlinkWrite(v);
////    v = 0;
////    break;
////  case 't':
////    eyeTurnWrite(v);
////    v = 0;
////    break;
////  case 'y':
////    headTurnWrite(v);
////    v = 0;
////    break;
////  case 'u':
////    headNodWrite(v);
////    v = 0;
////    break;
////}
////  }
//
//  //Servo::refresh();
//
//} 

void eyeTiltWrite(int pos)
{
  if (pos > eyeTiltMax)

  {
    eyeTilt.write(eyeTiltMax);
  }

  else if (pos < eyeTiltMin)

  {
    eyeTilt.write(eyeTiltMin);
  }

  else 

  {
    eyeTilt.write(pos);
  }
}

void topLipWrite(int pos)
{
  if (pos < bottomLipPos)

  {
    topLip.write(topLipMax);
  
  }

  
  if (pos > topLipMax)

  {
    topLip.write(topLipMax);
    topLipPos = topLipMax;
  }

  else if (pos < eyeTiltMin)

  {
    topLip.write(topLipMin);
    topLipPos = topLipMin;
  }

  else 

  {
    topLip.write(pos);
    topLipPos = pos;
  }

}

void bottomLipWrite(int pos)
{

  if (pos > bottomLipMax)

  {
    bottomLip.write(bottomLipMax);
    bottomLipPos = bottomLipMax;
  }

  else if (pos < bottomLipMin)

  {
    bottomLip.write(bottomLipMin);
    bottomLipPos = bottomLipMin;
  }

  else 

  {
    bottomLip.write(pos);
     bottomLipPos = pos;
  }
 
}

void lidBlinkWrite(int pos)
{

  if (pos > lidBlinkMax)

  {
    lidBlink.write(lidBlinkMax);
  }

  else if (pos < lidBlinkMin)

  {
    lidBlink.write(lidBlinkMin);
  }

  else 

  {
    lidBlink.write(pos);
  }
 
}

void eyeTurnWrite(int pos)
{
  Serial.println("eyeTurnPos");
  Serial.println(pos);
  
  if (pos > eyeTurnMax)

  {
    eyeTurn.write(eyeTurnMax);
  }

  else if (pos < eyeTurnMin)

  {
    eyeTurn.write(eyeTurnMin);
  }

  else 

  {
    eyeTurn.write(pos);
  }
 
}

void headTurnWrite(int pos)
{

  if (pos > headTurnMax)

  {
    headTurn.write(headTurnMax);
  }

  else if (pos < headTurnMin)

  {
    headTurn.write(headTurnMin);
  }

  else 

  {
    headTurn.write(pos);
  }
 
}

void headNodWrite(int pos)
{

  if (pos > headNodMax)

  {
    headNod.write(headNodMax);
  }

  else if (pos < headNodMin)

  {
    headNod.write(headNodMin);
  }

  else 

  {
    headNod.write(pos);
  }
 
}

void reset()

{
   headNodWrite((headNodMin+headNodMax)/2);

  eyeTurnWrite((eyeTurnMin+eyeTurnMax)/2);
//
  eyeTiltWrite((eyeTiltMin+eyeTiltMax)/2);
//
   headTurnWrite((headTurnMin+headTurnMax)/2);
  //  headTurnWrite(100);
//
  lidBlinkWrite(lidBlinkMax);
//
  topLipWrite((topLipMin+topLipMax)/2);
//
  bottomLipWrite((bottomLipMin+bottomLipMax)/2);

  
}





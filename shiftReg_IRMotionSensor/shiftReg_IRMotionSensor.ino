
int DS_pin = 8;
int STCP_pin = 9;
int SHCP_pin = 10;
//IRrecv irrecv(6);
//decode_results results;

int calibrationTime = 30;        

//the time when the sensor outputs a low impulse
long unsigned int lowIn;         

//the amount of milliseconds the sensor has to be low 
//before we assume all motion has stopped
long unsigned int pause = 5000;  

boolean lockLow = true;
boolean takeLowTime;  

int pirPin = 3;    //the digital pin connected to the PIR sensor's output
int ledPin = 13;

void setup() {
  pinMode(DS_pin, OUTPUT);
  pinMode(STCP_pin, OUTPUT);
  pinMode(SHCP_pin, OUTPUT);
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  digitalWrite(pirPin, LOW);

  //give the sensor some time to calibrate
  Serial.print("calibrating sensor ");
    for(int i = 0; i < calibrationTime; i++){
      Serial.print(".");
      delay(1000);
      }
    Serial.println(" done");
    Serial.println("SENSOR ACTIVE");
    delay(50);
//  irrecv.enableIRIn();

  writeReg();
}
boolean registers[8];
// the loop routine runs over and over again forever:
void loop() {
  if(digitalRead(pirPin) == HIGH){
    for(int i = 0; i <= 8; i++) {
    registers[2] = HIGH;
    registers[i] = LOW;
    delay(100);
    writeReg();
  }
       digitalWrite(ledPin, HIGH);   //the led visualizes the sensors output pin state
       if(lockLow){  
         //makes sure we wait for a transition to LOW before any further output is made:
         lockLow = false;            
         Serial.println("---");
         Serial.print("motion detected at ");
         Serial.print(millis()/1000);
         Serial.println(" sec"); 
         delay(50);
         }         
         takeLowTime = true;
       }

     if(digitalRead(pirPin) == LOW){       
       
  for(int i = 0; i <= 8; i++) {
    registers[i] = HIGH;
    delay(100);
    writeReg();
  }
  for(int i = 0; i <= 8; i++) {
    registers[i] = LOW;
    delay(100);
    writeReg();
  }
  delay(1); 
       digitalWrite(ledPin, LOW);  //the led visualizes the sensors output pin state

       if(takeLowTime){
        lowIn = millis();          //save the time of the transition from high to LOW
        takeLowTime = false;       //make sure this is only done at the start of a LOW phase
        }
       //if the sensor is low for more than the given pause, 
       //we assume that no more motion is going to happen
       if(!lockLow && millis() - lowIn > pause){  
           //makes sure this block of code is only executed again after 
           //a new motion sequence has been detected
           lockLow = true;                        
           Serial.print("motion ended at ");      //output
           Serial.print((millis() - pause)/1000);
           Serial.println(" sec");
           delay(50);
           }
       }
  // read the input on analog pin 0:
//  if (irrecv.decode(&results)) {
//    irrecv.resume(); // Receive the next value
//  }
  // print out the value you read:
  // delay in between reads for stability
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
//    irrecv.resume(); // Receive the next value
//  }
}

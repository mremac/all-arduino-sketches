#include <Servo.h>
const int button1Pin = 2;
const int button2Pin = 8;// the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int button1State = 0;         // variable for reading the pushbutton status
int button2State = 0;
Servo aa;
int aaPin = 7;
int a = 0;
int b = 0;
void setup() {
  aa.attach(aaPin);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);      
  // initialize the pushbutton pin as an input:
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);  
}

void loop(){
  // read the state of the pushbutton value:
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (button1State == HIGH) {
    digitalWrite(ledPin, HIGH);
    a++;
    delay(5);
    if(a>=180){
      a = 179;
    }
    aa.write(a);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW); 
  }
  if(button2State == HIGH){
    digitalWrite(ledPin, HIGH);
    a--;
    delay(5);
    if(a<=0){
      a = 1;
    }
    aa.write(a);
  }
}

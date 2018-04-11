//Argus Mk. I code. Includes drive functions for turning clockwise or 
//anticlockwise or driving forward, scanner code and camera code

const int  leftSide = 3;
const int rightSide = 4;

const int trigPin = A4;
const int echoPin = A5;


long duration, inches, cm;

void setup(){
  Serial.begin(9600);
  pinMode(rightSide, OUTPUT);
  pinMode(leftSide, OUTPUT);
  digitalWrite(rightSide, LOW);
  digitalWrite(leftSide, LOW);
  delay(5000);
}

void loop(){
//  for (int x = 0; x<100;x++){
  digitalWrite(rightSide, HIGH);
  digitalWrite(leftSide, HIGH);
  delay(80);
  digitalWrite(rightSide, LOW);
  digitalWrite(leftSide, LOW);
  delay(80);
//  }

//scan();
}

void scan(){
  
  // establish variables for duration of the ping, 
  // and the distance result in inches and centimeters:
 
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
}

long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

void microDelay(int additionaltime){
  delay(5 + additionaltime);
}

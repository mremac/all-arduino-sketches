const int THERM_PIN = A5;
const int FAN_PIN = 13;
int prevTemp = 0;

void setup(){
  pinMode(THERM_PIN, INPUT);
  pinMode(FAN_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  delay(500);
  int temp = analogRead(THERM_PIN);
  Serial.println(temp);
  
  if(temp > prevTemp){
    digitalWrite(FAN_PIN, HIGH);
  } else{
    digitalWrite(FAN_PIN, LOW);
  }
  prevTemp = temp;
}

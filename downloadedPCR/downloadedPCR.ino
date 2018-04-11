const int thermpin = 5;
const int heatpin = 3;
const int coolpin = 13;

const int hot = 40; //these are resistance-based temperatures, not yet calibrated for Celsius
const int tm = 20;
const int elongtemp = 30;

const int delaytime = 2000;
const int elongtime = 5000;

int cyclecount = 1;

void setup(){ 
  pinMode(thermpin, INPUT);
  pinMode(heatpin, OUTPUT);
  pinMode(coolpin, OUTPUT);
  analogReference(EXTERNAL);
  Serial.begin(9600);
}


void loop(){
  

int temp = analogRead(thermpin);

do {
  //Begin PCR Reaction by heating to 95 degrees; 
  digitalWrite(heatpin, HIGH); 
  temp = analogRead(thermpin);
  Serial.print("Cycle #");
  Serial.print(cyclecount);
  Serial.print(", Heating Lamp ON, Temp = ");
  Serial.println(temp);
  
} while (temp < hot);

digitalWrite(heatpin, LOW);
Serial.println("DNA Dissociating");
delay(delaytime);

do {
   digitalWrite(coolpin, HIGH);
   temp = analogRead(thermpin);
   Serial.print("Cycle #");
   Serial.print(cyclecount);
   Serial.print(", Cooling to Tm, Temp = ");
   Serial.println(temp);
} while (temp > tm);


digitalWrite(coolpin, LOW);
Serial.println("Primers Annealing");
delay(delaytime);

do{
  digitalWrite(heatpin, HIGH);
  temp = analogRead(thermpin);
  Serial.print("Cycle #");
  Serial.print(cyclecount);  
  Serial.print(", Heating to Extension Temp, Temp = ");
  Serial.println(temp);
} while (temp < elongtemp);

digitalWrite(heatpin, LOW);
  Serial.print("Cycle #");
  Serial.print(cyclecount);
Serial.println(", DNA Elongating");
delay(elongtime);
//strobe bulb to maintain elongtemp?

cyclecount++;

//digitalWrite(cyclespin, cyclesdonecount);

   

 
   
}

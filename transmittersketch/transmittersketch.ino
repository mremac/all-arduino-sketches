#include <VirtualWire.h>
#include <string.h>

byte message[VW_MAX_MESSAGE_LEN];
byte messageLength = VW_MAX_MESSAGE_LEN; 

void setup() {
  Serial.begin(9600);
  vw_set_ptt_inverted(true);
  vw_setup(2000);
  vw_set_tx_pin(4);
  vw_set_rx_pin(2);
  vw_rx_start();
}

void loop() {
   sendMessage("1", "5");
   if (vw_get_message(message, &messageLength)) {
       int command = processResponse((char*)message, 1); //Byte Array Response and Pin Code.
       if (command) {
         Serial.print("Received Command: ");
         Serial.print(command);
         Serial.print("\n");
       }
   delay(1000);
   }
}
 
void sendMessage(char* pinCode, char *data) {
  if (strlen(data) > 0) {
    //double startTime = millis();
    //Serial.println("Sending...");
    int msgSize = (strlen(data) + strlen(pinCode) + 1);
    char packetData[msgSize];
    strcat(packetData, pinCode);
    strcat(packetData, ".");
    strcat(packetData, data);
 
      //Serial.println("Debugging ");
      //Serial.print("Sending Command: ");
      //Serial.print(data);
      //Serial.print(" with Pin Code: ");
      //Serial.print(pinCode);
      //Serial.print("\n");
 
      vw_send((uint8_t *)packetData, msgSize);
      vw_wait_tx();
 
      //double endTime = millis();
      //double timeTaken = (endTime - startTime); 
      //Serial.print("Time Taken: ");
      //Serial.print(timeTaken);
      //Serial.print(" ms\n");
  }  
}
  
int processResponse(char* message, int pinCode) {
    char *p = message;
    char *buf;
    int o = 0;
    int pin;
    int command;
 
    while ((buf = strtok_r(p, ".", &p)) != NULL)  {
       if (o == 0) {
         pin = atoi(buf);
       } else {
         command = atoi(buf);
       }
       o++;
    }
 
    if (pinCode == pin && command > 0) {
      return command;
    } else {
      return 0; 
    }
}

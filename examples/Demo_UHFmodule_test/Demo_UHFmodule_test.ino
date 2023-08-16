/*
  Demo code to test working of UHF module, 
  basically some of operation demonstrated from UHF manual like
  2.1  Get the reader module information
  2.2  Single polling command
  2.3  Several times polling command
*/
#include <HardwareSerial.h>
#include "Uhf.h"

#define mySerial Serial2

//Uncomment corresponding commands to configure UHF, more command can be added in UHF.h
//#define COMMANDS HARDWARE_VERSION
//#define COMMANDS MULTIPLE_READ
#define COMMANDS SINGLE_READ
//#define COMMANDS STOP_READ

// Function to setup region, if module range is less. Calling this function sets EU or US region as per requirement
// For EU region add command -> SET_REGION_EU
// For US region add command -> SET_REGION_US
void setRegion(){
  mySerial.write(SET_REGION_EU, sizeof(SET_REGION_EU)); // send command to UHF module for region configuration
  delay(100);
  int len = mySerial.available();
  while (len <= 0){
    Serial.print("wait..\n");
    delay(500);
    mySerial.write(SET_REGION_EU, sizeof(SET_REGION_EU)); // send command to UHF module for region configuration
    len = mySerial.available();
  }
  
  if (len > 0) {
    mySerial.readBytes(container, len); // Read Response from UHF module, and parse frame received
    frameParse(container, len); // This process done in Uhf.cpp file
  }
}

void setup() {
  pinMode(21,OUTPUT);
  digitalWrite(21,LOW); // LOW - to enable the module and HIGH to disable the module
  
  mySerial.begin(115200, SERIAL_8N1, 18, 17);
  Serial.begin(115200);
  mySerial.setTimeout(2000);

  //Uncomment below function to set region to increase range of UHF module if default getting low range 
  //setRegion(); 
}

void loop() {
  mySerial.write(COMMANDS, sizeof(COMMANDS)); // send command to UHF module for configuration
  delay(100);
  int len = mySerial.available();
  if (len > 0) {
    mySerial.readBytes(container, len); // Read Response from UHF module, and parse frame received
    frameParse(container, len); // This process done in Uhf.cpp file
  }
  delay(1000);
}

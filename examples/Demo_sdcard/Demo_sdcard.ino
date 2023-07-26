// Code detects if micro SDcard present and gives storage detail
#include "FS.h"
#include "SD.h"
#include <SPI.h>

//Define SPI interfacing pins for micro SD card with ESP32
#define SD_MOSI 2
#define SD_MISO 41
#define SD_SCK 42
#define SD_CS 1

void setup(void) {
  Serial.begin(115200); // define serial communication with baudrate
  
  // Configure SPI pins for sdcard
  SPI.begin(SD_SCK, SD_MISO, SD_MOSI);
  if(!SD.begin(SD_CS, SPI, 80000000)){
    Serial.println("Card Mount Failed");
    return;
  }
  
  uint8_t cardType = SD.cardType();

  if(cardType == CARD_NONE){
      Serial.println("No SD card attached");
      return;
  }

  Serial.print("SD Card Type: ");
  if(cardType == CARD_MMC){
      Serial.println("MMC");
  } else if(cardType == CARD_SD){
      Serial.println("SDSC");
  } else if(cardType == CARD_SDHC){
      Serial.println("SDHC");
  } else {
      Serial.println("UNKNOWN");
  }

  uint64_t cardSize = SD.cardSize() / (1024 * 1024);
  Serial.printf("SD Card Size: %lluMB\n", cardSize);
}

void loop() {
  delay(10);
}

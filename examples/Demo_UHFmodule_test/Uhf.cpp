#include "Uhf.h"
#include <Arduino.h>

void extractEPC(byte frm[], int le) {
  
  Serial.print("\nComplete Frame: ");
  for (int i = 0; i < le; i++) {
      Serial.print(frm[i], HEX);    //To print in HEX format
      Serial.write(32); // To add space between each byte print
    }
    
  Serial.print("\nExtracted Info Byte from Frame: ");

  // Verify response with 2nd Byte -> Type and 3rd Byte -> COMMAND
  if (frm[1] == 0x02 && frm[2] == 0x22) {  // Extracts info Frame -> multiple read, single read command
    
    // exclude starting 3bytes - HEADER , TYPE, COMMAND and Last 4 bytes - CRC(MSB),CRC(LSB), CHECKSUM,  END
    // information contained inbetween bytes,
    for (int i = 3; i < le - 3; i++) { 
      Serial.print(frm[i], HEX);    //To print in HEX format on terminal
      Serial.write(32);   // To add space between each byte print on terminal
    }
    Serial.write(10);
    
    Serial.print("EPC = 0x");
    for (int i = 8; i < le - 4; i++) { // UHF EPC value starts from 8th byte
      Serial.print(frm[i], HEX);    //To print in HEX format on terminal
    }
    Serial.write(10);
  }

  
  // Verify response with 2nd Byte -> Type and 3rd Byte -> COMMAND
  if (frm[1] == 0x01 && frm[2] == 0x03) { // Extracts info Frame -> Hardware_version Data
    //Serial.write(42);   // This add * on terminal 
    for (int i = 5; i < le - 2; i++) {
      Serial.print(frm[i], HEX);
      asciiVal += (char)frm[i];   // create ASCII string format of Response Byte Data 
      Serial.write(32);   // To add space between each byte print
    }
    Serial.write(10);
    Serial.println(asciiVal);    //To print in ASCII format
    asciiVal = "";
  }
  Serial.println();
}


void frameParse(byte dataCom[], int lent) {
  //Serial.write(98);
  bool frameBeginFlag = false;
  bool frameEndFlag = true;
  long frameLength;   
  long strNum;      
  byte strBuff[4096];
  int n = lent;
  for (int j = 0; j < n; j++)
  {

    if (frameBeginFlag)
    {
      strBuff[strNum] = dataCom[j];
      if (strNum == 4)
      {
        frameLength = 256 * strBuff[3] + strBuff[4];
        if (frameLength > 3072)
        {
          frameBeginFlag = false;
          continue;
        }
      }
      else if (strNum == frameLength + 6 && strBuff[strNum] == 0x7E)
      {
        int checksum = 0;
        for (int i = 1; i < strNum - 1; i++)
        {
          checksum += strBuff[i];
        }
        checksum = checksum % 256;
        if (checksum != strBuff[strNum - 1])
        {
          // Console.WriteLine("ERROR FRAME, checksum is not right!");
          frameBeginFlag = false;
          frameEndFlag = true;
          continue;
        }
        frameBeginFlag = false;
        frameEndFlag = true;

        //Send out
        byte packet[strNum + 1];
        for (int i = 0; i <= strNum; i++)
        {
          packet[i] = strBuff[i];
        }
        extractEPC(packet, strNum + 1);

      }
      else if (strNum == frameLength + 6 && strBuff[strNum] != 0x7E)
      {
        // Console.WriteLine("ERROR FRAME, cannot get FRAME_END when extends frameLength");
        frameBeginFlag = false;
        frameEndFlag = true;
        continue;
      }
      strNum++;
    }
    else if (dataCom[j] == 0xBB && frameBeginFlag != true)
    {
      strNum = 0;
      strBuff[strNum] = dataCom[j];
      frameBeginFlag = true;
      frameEndFlag = false;
      strNum = 1;
    }
  }
}

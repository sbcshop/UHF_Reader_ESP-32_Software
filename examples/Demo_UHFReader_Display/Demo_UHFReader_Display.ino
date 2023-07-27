
/*********Libraries************************/
#include <HardwareSerial.h>
#include <SPI.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789

/*********User Define*********/
#define mySerial Serial2
byte container[1024]; //A buff container to contain received bytes
byte MULTIPLE_READ[]   = {0XBB, 0X00, 0X27, 0X00, 0X03, 0X22, 0X27, 0X10, 0X83, 0X7E}; //Command for multiple reading of UHF card.
byte HARDWARE_VERSION[]    = {0XBB,0X00,0X03,0X00,0X01,0X00,0X04,0X7E};//Command for Hardware Version.
String epcData;       // variable to store the data for displaying on tft screen.
const int uhf_enable = 21;  // Enable pin of UHF module connected at GPIO21
const int buzzerPin = 8;    // buzzer at GPIO40

// define Display SPI pins 
#define TFT_CS        10  
#define TFT_RST       14 
#define TFT_DC        13
#define TFT_MOSI      11
#define TFT_CLK       12
#define BackLight     9

// configure SPI and create instance for display 
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST);

void setup() {
  pinMode(buzzerPin, OUTPUT); // set Buzzer pin as OUTPUT
  pinMode(uhf_enable,OUTPUT); // set UHF Enable pin as OUTPUT
  
  digitalWrite(uhf_enable,LOW); // LOW - to enable the module and HIGH to disable the module

  pinMode(BackLight,OUTPUT); // Set backLight LED pin OUTPUT
  digitalWrite(BackLight,HIGH); // turn display backlight ON
  
  mySerial.begin(115200, SERIAL_8N1, 18, 17);
  Serial.begin(115200);

  tft.init(135, 240);           // Init ST7789 240x135
  
  // SPI speed defaults to SPI_DEFAULT_FREQ defined in the library, you can override it here
  // Note that speed allowable depends on chip and quality of wiring, if you go too fast, you
  // may end up with a black screen some times, or all the time.
  //tft.setSPISpeed(40000000);
  Serial.println(F("Initialized"));

  tft.setRotation(3); // Change display rotation as per requirement, value-> 0 (defualt), 1, 2, 3
  tft.setTextSize(2); 
  tft.setTextWrap(false);
  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(0, 30);
  tft.setTextSize(3);
  tft.setTextColor(ST77XX_YELLOW);
  tft.println("Hello...");
  delay(500);

  tft.setTextSize(2); 
  tft.setTextWrap(false);
  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(0, 30);
  tft.setTextColor(ST77XX_YELLOW);
  tft.println("Scan Cards...");
  beep(1245,500);
  mySerial.setTimeout(200);
}

void loop() {
  mySerial.write(MULTIPLE_READ, sizeof(MULTIPLE_READ)); // send command to UHF module for configuration
  delay(200);
  int len = mySerial.available();
  if (len > 0) {
    mySerial.readBytes(container, len); // Read Response from UHF module, and parse frame received
    frameParse(container, len);         // This process done in Uhf.cpp file
    extractEPC(container,len);          //Extract the EPC Data.
    displayText(epcData);
    epcData="";
  }
    
  delay(5);
}

//Function to beep the buzzer
void beep(int note, int duration){  // need note frequency and time duration (in millis)
  tone(buzzerPin, note, duration);
  delay(duration);
}

//Function to display the text
void displayText(const String text){
  tft.setTextSize(2); 
  tft.setTextWrap(false);
  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(0,30);
  tft.setTextColor(ST77XX_YELLOW);
  tft.println(text);
  delay(500);
}


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

    
    //creating the string of the EPC data from the UHF reader frame
    epcData = "EPC:\n\n0x";
    for (byte i = 8; i < le - 4; i++) { // UHF EPC value starts from 8th byte
      epcData+= String(frm[i],HEX); // Storing the values in an string variable epcData
    }
    Serial.write(10);  
  }

  
  // Verify response with 2nd Byte -> Type and 3rd Byte -> COMMAND
  if (frm[1] == 0x01 && frm[2] == 0x03) { // Extracts info Frame -> Hardware_version Data
    //Serial.write(42);   // This add * on terminal 
    for (int i = 5; i < le - 2; i++) {
      Serial.print(frm[i], HEX);
      Serial.write(32);   // To add space between each byte print
    }
    Serial.write(10);

    epcData = "EPC:\n\n0X"; //
    for (byte i = 5; i < le - 2; i++) { // UHF EPC value starts from 8th byte
      epcData+= String(frm[i],HEX); // Storing the values in an string variable epcData
    }
    Serial.write(10);
  }
  Serial.println();
}

//Function for frame parsing.
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

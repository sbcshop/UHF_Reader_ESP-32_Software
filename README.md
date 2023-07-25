# UHF_Reader_ESP-32_Software
<img src="https://github.com/sbcshop/UHF_Reader_Pico_W_Software/blob/main/images/UHF%20Reader%20banner.jpg">

This github page provides a getting started guide and other working details for the UHF reader for ESP32. The UHF Reader for ESP32 is a rapid multi-tag reading device for efficient and effective inventory management.

### Features:
- UHF Reader for ESP32 is powered by ESP32 S3 WROOM - 1
- Onboard High-performance UHF RFID reader module
- 24 hours x 365 days’ work normally
- 1.14” TFT display for visual interaction
- Multi-tone Buzzer onboard for Audio alerts
- Type C interface for programming and power 
- Onboard 2 user programmable buttons, Boot and Reset button
- SD card slot for storage and data transfer
- Battery power and charging circuit for portable use
- Status LED for Power and Battery charging available
- Multipurpose GPIOs breakout for interfacing external peripherals
- Arduino and Espressif IDF platform support for programming.

### Specifications:
- ESP32-S3 series of SoCs having Xtensa® dual-core 32-bit LX7 microprocessor, 2.4 GHz Wi-Fi (802.11 b/g/n) and Bluetooth® 5 (LE), Flash up to 16 MB, PSRAM up to 8 MB 
- Operating voltage of pins 3.3V and board supply 5V
- Display resolution 240 × 135 pixels
- ST7789 display driver
- UHF Module:
  - UHF Frequency Range :  EU/UK -> 865.1-867.9 MHz, US-> 902.25-927.75 MHz
  - Protocols Supported : EPCglobal UHF Class 1 Gen 2 / ISO 18000-6C
  - Onboard Antenna
  - Reading Distance: 1-1.5 meters depending tags 
  - Can identify over 50 tags simultaneously
  - Communication interface: TTL UART Interface for UHF
  - Communication baud rate: 115200 bps（default and recommend) - 38400bps
  - Operation current: 180mA @ 3.5V (26 dBm Output，25°C), 110mA @ 3.5V (18 dBm Output，25°C)
  - Working humidity < 95% (+ 25 °C)
  - Heat-dissipating method Air cooling(no need out install cooling fin）
  - Tags storage capacity: 200pcs tags @ 96 bit EPC
  - Output power: 18-26 dBm
  - Output power accuracy: +/- 1dB
  - Tags RSSI: support

## Getting Started with UHF Reader for ESP32
### Hardware Overview
#### Pinout
<img src="https://github.com/sbcshop/UHF_Reader_ESP-32_Software/blob/main/images/uhf%20reader%20esp%20pinout.jpg">

- (1) 1.14” Display
- (2) UHF module
- (3) Type C
- (4) & (6) programmable button
- (5) & (10) GPIOs Breakout with Power Pins
- (7) Buzzer
- (8) ESP32 S3 Wroom -1 
- (9) Boot Button
- (11) Reset Button
- (12) Battery Connector
- (13) TF card slot

#### GPIO Pins Detail
<img src=" ">

### Interfacing Details
- ESP32 and UHF module interfacing
  |Ardi-32 | UHF shield | Function |
  |---|---|---|
  | IO18 | U_RX | Serial Tx of UHF to Serial Rx of ESP32 |
  | IO17 | U_TX | Serial Rx of UHF to Serial Tx of ESP32 |
  | IO1 | U_EN | UHF Enable pin, LOW to disable and HIGH to enable |  

  | ESP32 | UHF Module Pin | Function |
  |---|---|---|
  |GP4 (Tx) | UHF_RX | Serial UART connection |
  |GP5 (Rx) | UHF_TX  | Serial UART connection |
  |GP26 | EN  | UHF Reader enable pin, LOW to activate and HIGH to deactivate|

- ESP32 and Display interfacing
  
  | ESP32 | Display Pin | Function |
  |---|---|---|
  |GP6 | SCLK | Clock pin of SPI interface for display|
  |GP7 | DIN  | MOSI (Master OUT Slave IN) data pin of SPI interface|
  |GP11 | DC | Data/Command pin of SPI interface|
  |GP13 | CS   | Chip Select pin of SPI interface for display|
  |GP14 | Reset | Display Reset Pin |
  |GP12 | BL | Backlight of Display |
  
- ESP32 and micro SD card interfacing

  | ESP32 | microSD Card | Function |
  |---|---|---|
  |GP18 | SCLK |Clock pin of SPI interface for microSD card |
  |GP19 | DIN  | MOSI (Master OUT Slave IN) data pin of SPI interface|
  |GP16 | DOUT | MISO (Master IN Slave OUT) data pin of SPI interface|
  |GP17 | CS   | Chip Select pin of SPI interface for SDcard|

- Buttons, Buzzer and LED Interfacing with ESP32
  | ESP32 | Buttons | Function |
  |---|---|---|
  |GP10 | BT2 | programmable button |
  |GP9 | BT3 | programmable button |
  |GP8 | BT4 | programmable button |
  |GP22 | Buzzer | Buzzer positive |
  |GP25 | LED | OnBoard LED pin of Pico W  |
 
- Breakout GPIOs
  | ESP32 |Physical Pin | Multi-Function |
  |---|---|---|
  |GP0 | 1  | General IO / SPI0 RX / I2C0 SDA / UART0 TX |
  |GP1 | 2 | General IO / SPI0 CSn / I2C0 SCL / UART0 RX |
  |GP2 | 4 | General IO / SPI0 SCK / I2C1 SDA |
  |GP3 | 5 | General IO / SPI0 TX / I2C1 SCL |
  |GP21 | 27 | General IO / I2C0 SCL |
  |GP20 | 26 | General IO / I2C0 SDA |
  |GP28| 34 | General IO / ADC2 / SPI1 RX |
  |GP15| 20 | General IO / SPI1 TX / I2C1 SCL|

### 1. Configure and Setup Development Environment
   - Download Arduino IDE from [official site](https://www.arduino.cc/en/software) and install into your system. We have use Arduino IDE 1.8.19
   - Once installation done will add ESP32 S3 board support into IDE, for this first you need to add below link into preference:
     ``` https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json ```
     
     Select File > Preference, and add link as show in below image,
      <img src= "https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/blob/main/images/preference_board.gif" />
      
   - Now will install ESP32 based boards as shown in below image,

     <img src= "https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/blob/main/images/install_ESP32boards.gif" />
     
   - Once done, keeping default settings select the ESP32S3 Dev Module with suitable com port (may be different in your case) as shown below, 

     <img src="https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/blob/main/images/select_esp32_with_comport.gif">
     
### 2. Testing First Code
   - At this step you are all set to test codes, for easy getting started we have provided various demo [example codes](https://github.com/sbcshop/ArdiFi_Software/tree/main/examples) in github which you can download and try. 
   - Open one example code in Arduino and make sure you have selected correct board with suitable com port, click on upload button to transfer code on Ardi-32.
     <img src="https://github.com/sbcshop/ArdiFi_Software/blob/main/images/uploadCode.gif">
    
   - Checkout other examples below and build your own custom program codes using those references.

### 3. Installing Libraries
   - Download [library zip file](https://github.com/sbcshop/Ardi-32_Software/blob/main/libraries.zip) provided here in github.
   - Extract and copy files inside Document > Arduino > Libraries folder. Make sure to restart Arduino IDE whenever you update or add any libraries.

     <img src= "https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/blob/main/images/library_files_path.png" />

### Commands and Response of UHF module

| Type | Description |
|---|---|
| 0x00 | Command Frame: send from PC/Controller to UHF Module chip |
| 0x01 | Response Frame: send from UHF Module chip to PC/Controller |
| 0x02 | Notice Frame: send from UHF Module chip to PC/Controller |  

- Hardware version Check
  
  <img src="https://github.com/sbcshop/Ardi_UHF_Shield_Software/blob/main/images/hardware_version_cmd.png" width="573" height="270">

  **Expected Response**
  
  <img src="https://github.com/sbcshop/Ardi_UHF_Shield_Software/blob/main/images/HW_response.png" width="573" height="270">

  code snippets(header file)
  ```
  // Add here UHF commands in byte array format to configure, 
  // refer Manual: https://github.com/sbcshop/Ardi_UHF_Shield_Software/blob/main/documents/UHF%20Commands%20Manual.pdf
  static byte HARDWARE_VERSION[]    = {0XBB,0X00,0X03,0X00,0X01,0X00,0X04,0X7E};
  static byte MULTIPLE_READ[]   = {0XBB, 0X00, 0X27, 0X00, 0X03, 0X22, 0X27, 0X10, 0X83, 0X7E};
  static byte SINGLE_READ[]     = {0XBB,0X00,0X22,0X00,0X00,0X22,0X7E};
  static byte STOP_READ[]       = {0XBB,0X00,0X28,0X00,0X00,0X28,0X7E};
  ```
  code snippets (main ino file)
  ```
  //Uncomment corresponding commands to configure UHF, more command can be added in UHF.h
  #define commands HARDWARE_VERSION
  //#define commands MULTIPLE_READ
  //#define commands SINGLE_READ
  //#define commands STOP_READ
  ```
  **Output on Terminal:**
  
  <img src="https://github.com/sbcshop/Ardi_UHF_Shield_Software/blob/main/images/hardware_version_terminal.png" width="573" height="270">

- Similarly for Tag read
  
  <img src="https://github.com/sbcshop/Ardi_UHF_Shield_Software/blob/main/images/single_poll_cmd.png">

  Required Command:
  ```
   static byte SINGLE_READ[]     = {0XBB,0X00,0X22,0X00,0X00,0X22,0X7E};
  ```

  **Output on Terminal:**
  
  <img src="https://github.com/sbcshop/Ardi_UHF_Shield_Software/blob/main/images/tag_read_terminal.png" width="573" height="270">

### Example Codes
   
   In [example](https://github.com/sbcshop/ArdiFi_Software/tree/main/examples) folder you will find demo examples to try out on ArdiFi
   - [Buzzer](https://github.com/sbcshop/ArdiFi_Software/tree/main/examples/buzzerDemo) : code to test onboard Buzze
   - [SD card](https://github.com/sbcshop/ArdiFi_Software/tree/main/examples/sdcard_Demo) : code to test onboard micro SD card interfacing
   
   Also, sample codes are available for Ardi32 shields
   - [Ardi Relay shield Code](https://github.com/sbcshop/ArdiFi_Software/tree/main/examples/Ardi32_relay_shield_interfacing) : code test switching of relays in sequence, for more details refer [Ardi-Relay Shield](https://github.com/sbcshop/Ardi_RFID_Shield_Software) 
   - [Ardi RFID shield Code](https://github.com/sbcshop/ArdiFi_Software/tree/main/examples/Ardi32_RFID_shield_interfacing) : code to test RFID module scan and switching of Relay, for more details refer [Ardi-RFID Shield](https://github.com/sbcshop/Ardi_RFID_Shield_Software) 
   - [Ardi Display shield Code](https://github.com/sbcshop/Ardi-32_Software/tree/main/examples/Ardi32_Display_shield_interfacing) : testing of display and programmable buttons, for this example to try you need to install [libraries](https://github.com/sbcshop/Ardi-32_Software/blob/main/libraries.zip) provided in github. [Step 3](https://github.com/sbcshop/Ardi-32_Software/blob/main/README.md#3-installing-libraries) shows how to install libraries. For more details refer [Ardi-Display Shield](https://github.com/sbcshop/Ardi_Display_Shield_Software) 
   - [Ardi UHF shield Code](https://github.com/sbcshop/Ardi-32_Software/tree/main/examples/Ardi32_UHF_shield_interfacing) : testing onboard UHF module, for more details refer [Ardi-UHF Shield](https://github.com/sbcshop/Ardi_UHF_Shield_Software) 
   
   Using this sample code as a guide, you can modify, build, and share codes!!  
   
## Resources
  * [Schematic](https://github.com/sbcshop/ArdiFi_Hardware/blob/main/Design%20Data/SCH%20%20Ardi-32.pdf)
  * [Hardware Files](https://github.com/sbcshop/ArdiFi_Hardware)
  * [Step File](https://github.com/sbcshop/ArdiFi_Hardware/blob/main/Mechanical%20Data/STEP%20Ardi-32.step)
  * [Getting Started with ESP32 in Arduino](https://docs.espressif.com/projects/arduino-esp32/en/latest/)
  * [ESP32 S3 Hardware Reference](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/hw-reference/index.html)
  * [ESP32 S3 Datasheet](https://github.com/sbcshop/3.2_Touchsy_ESP-32_Capacitive_Software/blob/main/documents/esp32-s3_datasheet_en.pdf)
  * [Arduino IDE 1 overview](https://docs.arduino.cc/software/ide-v1/tutorials/Environment)
### 1. Configure and Setup Development Environment
   - Download Arduino IDE from [official site](https://www.arduino.cc/en/software) and install into your system. We have use Arduino IDE 1.8.19
   - Once installation done will add ESP32 S3 board support into IDE, for this first you need to add below link into preference:
     ``` https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json ```
     
     Select File > Preference, and add link as show in below image,
      <img src= "https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/blob/main/images/preference_board.gif" />
      
   - Now will install ESP32 based boards as shown in below image,

     <img src= "https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/blob/main/images/install_ESP32boards.gif" />
     
   - Once done, keeping default settings select the ESP32S3 Dev Module with suitable com port (may be different in your case) as shown below, 

     <img src="https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/blob/main/images/select_esp32_with_comport.gif">
     
### 2. Testing First Code
   - At this step you are all set to test codes, for easy getting started we have provided various demo [example codes](https://github.com/sbcshop/ArdiFi_Software/tree/main/examples) in github which you can download and try. 
   - Open one example code in Arduino and make sure you have selected correct board with suitable com port, click on upload button to transfer code on Ardi-32.
     <img src="https://github.com/sbcshop/ArdiFi_Software/blob/main/images/uploadCode.gif">
    
   - Checkout other examples below and build your own custom program codes using those references.

### 3. Installing Libraries
   - Download [library zip file](https://github.com/sbcshop/Ardi-32_Software/blob/main/libraries.zip) provided here in github.
   - Extract and copy files inside Document > Arduino > Libraries folder. Make sure to restart Arduino IDE whenever you update or add any libraries.

     <img src= "https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/blob/main/images/library_files_path.png" />
     
### Example Codes
   
   In [example](https://github.com/sbcshop/ArdiFi_Software/tree/main/examples) folder you will find demo examples to try out on ArdiFi
   - [Buzzer](https://github.com/sbcshop/ArdiFi_Software/tree/main/examples/buzzerDemo) : code to test onboard Buzze
   - [SD card](https://github.com/sbcshop/ArdiFi_Software/tree/main/examples/sdcard_Demo) : code to test onboard micro SD card interfacing
   - [Ardi UHF shield Code](https://github.com/sbcshop/Ardi-32_Software/tree/main/examples/Ardi32_UHF_shield_interfacing) : testing onboard UHF module, for more details refer [Ardi-UHF Shield](https://github.com/sbcshop/Ardi_UHF_Shield_Software) 
   
   Using this sample code as a guide, you can modify, build, and share codes!!  
   
## Resources
  * [Schematic](https://github.com/sbcshop/ArdiFi_Hardware/blob/main/Design%20Data/SCH%20%20Ardi-32.pdf)
  * [Hardware Files](https://github.com/sbcshop/ArdiFi_Hardware)
  * [Step File](https://github.com/sbcshop/ArdiFi_Hardware/blob/main/Mechanical%20Data/STEP%20Ardi-32.step)
  * [Getting Started with ESP32 in Arduino](https://docs.espressif.com/projects/arduino-esp32/en/latest/)
  * [ESP32 S3 Hardware Reference](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/hw-reference/index.html)
  * [ESP32 S3 Datasheet](https://github.com/sbcshop/3.2_Touchsy_ESP-32_Capacitive_Software/blob/main/documents/esp32-s3_datasheet_en.pdf)
  * [Arduino IDE 1 overview](https://docs.arduino.cc/software/ide-v1/tutorials/Environment)

## Related Products
   * [UHF Reader for Pico W](https://shop.sb-components.co.uk/products/uhf-reader-based-on-pico-w-esp32?variant=40586828447827) - UHF Reader powered by RPi Pico W
   * [Ardi UHF Shield](https://shop.sb-components.co.uk/products/ardi-uhf-shield-for-arduino-uno?variant=40791294836819) - UHF based shield with Oled display and Buzzer onboard
   * [UHF Lite HAT](https://shop.sb-components.co.uk/products/uhf-rfid-lite-hat) - Raspberry Pi Version
   * [UHF Lite Expansion for Raspberry Pi Pico](https://shop.sb-components.co.uk/products/uhf-rfid-for-pico?_pos=5&_sid=75312e089&_ss=r): UHF Lite Expansion to use with Pico/ Pico W

## Product License

This is ***open source*** product. Kindly check LICENSE.md file for more information.

Please contact support@sb-components.co.uk for technical support.
<p align="center">
  <img width="360" height="100" src="https://cdn.shopify.com/s/files/1/1217/2104/files/Logo_sb_component_3.png?v=1666086771&width=300">
</p>

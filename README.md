# UHF_Reader_ESP-32_Software
<img src="https://cdn.shopify.com/s/files/1/1217/2104/files/bannerUHFReaderforpico-esp32.png?v=1701237229">

This github page provides a getting started guide and other working details for the UHF reader for ESP32. The UHF Reader for ESP32 is a rapid multi-tag reading device for efficient and effective inventory management.

### Features:
- UHF Reader for ESP32 is powered by ESP32 S3 WROOM - 1
- Onboard High-performance UHF RFID reader module
- Both read and write operations 
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
  - UHF module type : Read and Write
  - Protocols Supported : EPCglobal UHF Class 1 Gen 2 / ISO 18000-6C
  - Onboard Integrated Antenna (having Circular polarity)
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

### Interfacing Details
- ESP32 and UHF module interfacing
  
  | ESP32 | UHF Module Pin | Function |
  |---|---|---|
  |IO17 (U1TXD) | RX | Serial UART connection |
  |IO18 (U1RXD) | TX  | Serial UART connection |
  |IO21 | UHF_EN  | UHF Reader enable pin, LOW to activate and HIGH to deactivate|

- ESP32 and Display interfacing
  
  | ESP32 | Display Pin | Function |
  |---|---|---|
  | IO12 | SCLK | Clock pin of SPI interface for display|
  | IO11 | DIN  | MOSI (Master OUT Slave IN) data pin of SPI interface|
  | IO13 | DC | Data/Command pin of SPI interface|
  | IO10 | CS   | Chip Select pin of SPI interface for display|
  | IO14 | RST | Display Reset Pin |
  | IO9 | BL | Backlight of Display |
  
- ESP32 and micro SD card interfacing

  | ESP32 | microSD Card | Function |
  |---|---|---|
  | IO42 | SCLK |Clock pin of SPI interface for microSD card |
  | IO2 | DIN  | MOSI (Master OUT Slave IN) data pin of SPI interface|
  | IO41 | DOUT | MISO (Master IN Slave OUT) data pin of SPI interface|
  | IO1 | CS   | Chip Select pin of SPI interface for SDcard|

- Buttons and Buzzer Interfacing with ESP32
  | ESP32 | Buttons | Function |
  |---|---|---|
  | IO5 | BT1 | programmable button |
  | IO4 | BT2 | programmable button |
  | IO0 | BOOT | BOOT button |
  | IO8 | Buzzer | Buzzer positive |
 
- GPIOs _Breakout 1_
  | ESP32 |Physical Pin | Multi-Function |
  |---|---|---|
  | 5V | - | Positive 5V supply |
  |IO3 | 15  | RTC_GPIO3, GPIO3, TOUCH3, ADC1_CH2  |
  |IO7 | 7 | RTC_GPIO7, GPIO7, TOUCH7, ADC1_CH6 |
  |IO16 | 9 | RTC_GPIO16, GPIO16, U0CTS, ADC2_CH5, XTAL_32K_N |
  |IO15| 8 | RTC_GPIO15, GPIO15, U0RTS, ADC2_CH4, XTAL_32K_P |
  |GND | - | Supply ground pin |
  
- GPIOs _Breakout 2_
  | ESP32 |Physical Pin | Multi-Function |
  |---|---|---|
  | 3.3V | - | Positive 3.3V supply |
  | IO38 | 31 | GPIO38, FSPIWP, SUBSPIWP |
  | IO39 | 32 | MTCK, GPIO39, CLK_OUT3, SUBSPICS1 |
  | IO46 | 16 | GPIO46 |
  | IO40 | 33 | MTDO, GPIO40, CLK_OUT2 |
  | GND | - | Supply ground pin |

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
     
   - In case you don't see com port then you will have to install CP2102 driver from [Link](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers?tab=downloads). Download and install as per your operating system.
     * check below one recommended for windows user
       
       <img src="https://github.com/sbcshop/Ardi-32_Software/blob/main/images/cp2102_driver_link.png" width="626" height="377">
       
     * Once successfully installed then it appears as shown in below image
       
       <img src="https://github.com/sbcshop/Ardi-32_Software/blob/main/images/device_manager_view.png" width="488" height="353">
       
### 2. Testing First Code
   - At this step you are all set to test codes, for easy getting started we have provided various demo [example codes](https://github.com/sbcshop/UHF_Reader_ESP-32_Software/tree/main/examples) in github which you can download and try. 
   - Open one example code in Arduino and make sure you have selected correct board with suitable com port, click on upload button to transfer code on ESP32 of UHF reader Board.
     <img src="https://github.com/sbcshop/ArdiFi_Software/blob/main/images/uploadCode.gif">
    
   - Checkout other examples below and build your own custom program codes using those references.

### 3. Installing Libraries
   - Download [library zip file](https://github.com/sbcshop/UHF_Reader_ESP-32_Software/blob/main/libraries.zip) provided here in github.
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
  // refer Manual: https://github.com/sbcshop/UHF_Reader_ESP-32_Software/blob/main/documents/UHF%20Commands%20Manual.pdf
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

  For more detail refer [Manual](https://github.com/sbcshop/UHF_Reader_ESP-32_Software/blob/main/documents/UHF%20Commands%20Manual.pdf) for various UHF module commands.
  
### Example Codes
   
   In [example](https://github.com/sbcshop/UHF_Reader_ESP-32_Software/tree/main/examples) folder you will find demo examples to try out on UHF reader for ESP32 board, some demo listed below
   - [Buzzer Demo](https://github.com/sbcshop/UHF_Reader_ESP-32_Software/blob/main/examples/Demo_Buzzer_Button) : code to test onboard Buzzer and Buttons
   - [Display Demo](https://github.com/sbcshop/UHF_Reader_ESP-32_Software/blob/main/examples/Demo_Display) : testing code for display
   - [SD card Demo](https://github.com/sbcshop/UHF_Reader_ESP-32_Software/tree/main/examples/Demo_sdcard) : code to test onboard micro SD card interfacing
   - [UHF Module Demo](https://github.com/sbcshop/UHF_Reader_ESP-32_Software/tree/main/examples/Demo_UHFmodule_test) : testing onboard UHF module 
   
   Using this sample code as a guide, you can modify, build, and share codes!!  
   
## Resources
  * [Schematic](https://github.com/sbcshop/UHF_Reader_ESP-32_Hardware/blob/main/Design%20Data/UHF%20Reader%20ESP32%20SCH.pdf)
  * [Hardware Files](https://github.com/sbcshop/UHF_Reader_ESP-32_Hardware/)
  * [Step File](https://github.com/sbcshop/UHF_Reader_ESP-32_Hardware/blob/main/Mechanical%20Data/Step%20UHF%20Reader%20for%20ESP32.step)
  * [Getting Started with ESP32 in Arduino](https://docs.espressif.com/projects/arduino-esp32/en/latest/)
  * [ESP32 S3 Hardware Reference](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/hw-reference/index.html)
  * [ESP32 S3 WROOM 1 Datasheet](https://github.com/sbcshop/UHF_Reader_ESP-32_Software/blob/main/documents/esp32-s3-wroom-1_wroom-1u_datasheet_en.pdf)
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

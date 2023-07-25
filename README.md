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

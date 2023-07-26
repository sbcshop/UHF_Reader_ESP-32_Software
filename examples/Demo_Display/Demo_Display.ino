// Demo code for onboard 1.14" Display Testing 
#include <SPI.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789

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
  pinMode(BackLight,OUTPUT); // Set backLight LED pin OUTPUT
  digitalWrite(BackLight,HIGH); // turn display backlight ON

  tft.init(135, 240);           // Init ST7789 240x135
  // SPI speed defaults to SPI_DEFAULT_FREQ defined in the library, you can override it here
  // Note that speed allowable depends on chip and quality of wiring, if you go too fast, you
  // may end up with a black screen some times, or all the time.
  //tft.setSPISpeed(40000000);
  
  tft.setRotation(3); // Change display rotation as per requirement, value-> 0 (defualt), 1, 2, 3
  tft.setTextSize(1); // Set display text size
  tft.setTextWrap(false);
  tft.fillScreen(ST77XX_BLACK); // clear screen
  tft.setCursor(0, 30); // move cursor to corresponding x, y co-ordinates
  tft.setTextSize(3);
  tft.setTextColor(ST77XX_YELLOW); 
  tft.println("Hello...");
  delay(500);

  tft.setTextSize(2); 
  tft.setTextWrap(false);
  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(0, 30);
  tft.setTextColor(ST77XX_YELLOW);
  tft.println("Thanks for Buying!");
 
  tft.setCursor(0, 70);
  tft.setTextColor(ST77XX_BLUE);
  tft.println("SB Components");
  tft.setTextSize(1);
  tft.setCursor(0, 90);
  tft.setTextColor(ST77XX_WHITE);
  tft.println("https://shop.sb-components.co.uk/");
  delay(500);
  
}

void loop() { 
  delay(50);
}

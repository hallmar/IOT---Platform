#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>
#include <WiFiAP.h>

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define Reset 14
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire, Reset);

// OLED FeatherWing buttons map to different pins depending on board:
#define BUTTON_A 33
#define BUTTON_B 15
#define BUTTON_C 32
#define rota     12
#define rotb     27
#define rotpush  13

// Set these to your desired credentials.
const char* ssid = "ESP32";
const char* password = "password";
String ledstatus = "LED ON";
WiFiServer server(80);

void setup() {
  Serial.begin(115200);

  Serial.println("OLED FeatherWing test");
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3D)) {// Address 0x3D for 128x64
    Serial.println("error!!");
    for (;;);
  }


  Serial.println("OLED begun");

  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display();
  delay(1000);

  // Clear the buffer.
  display.clearDisplay();
  display.display();

  Serial.println("IO test");

  pinMode(BUTTON_A, INPUT);
  pinMode(BUTTON_B, INPUT);
  pinMode(BUTTON_C, INPUT);
  pinMode(rota, INPUT);
  pinMode(rotb, INPUT);
  pinMode(rotpush, INPUT);
  
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
    display.print("Hello!");
  display.display();
}
  void loop(){

  if(digitalRead(rotpush)) display.print("Rotary push");
  if(digitalRead(BUTTON_A)) display.print("A");
  if(digitalRead(BUTTON_B)) display.print("B");
  if(digitalRead(BUTTON_C)) display.print("C");
  display.display();
  delay(10);
  display.clearDisplay();
  display.setCursor(0,0);

  }


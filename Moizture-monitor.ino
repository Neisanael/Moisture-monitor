#define BLYNK_TEMPLATE_ID "TMPL6NyLgS8VX"
#define BLYNK_TEMPLATE_NAME "Kelembapan tanah"
#define BLYNK_AUTH_TOKEN "cwgSowzvzAqjpUcmwJTQQr-9npsucz2X"

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C // Address for 128x32 OLED

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int SoilSensor = A0;
float kelembabanTanah;
int hasilPembacaan;
const int motor = 0;

char ssid[] = "Anang's Home";
char pass[] = "qweiop123890";

void setup() {
  Serial.begin(9600);
  Serial.println("test");
  
  // Initialize the OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(30, 30);
  


  // Initialize Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  display.println("Connecting...");
  display.display();
  // Wait for Blynk connection
  while (!Blynk.connected()) {
    
    delay(100);
  }

  delay(2000); // Optional: short delay to allow everything to stabilize
  pinMode(motor, OUTPUT);
}

void loop() {
  Blynk.run();

  hasilPembacaan = analogRead(SoilSensor);
  kelembabanTanah = 100.0 - ((hasilPembacaan / 1023.0) * 100.0);
  
  display.clearDisplay();
  String text1 = "Moisture: " + String(kelembabanTanah, 2) + "%";
  String text2 = "Motor: " + String(digitalRead(motor) == HIGH ? "OFF" : "ON");
  Blynk.virtualWrite(V2, text1);
  
  int16_t x1, y1;
  uint16_t w1, h1;
  display.getTextBounds(text1, 0, 0, &x1, &y1, &w1, &h1);
  
  int16_t x2, y2;
  uint16_t w2, h2;
  display.getTextBounds(text2, 0, 0, &x2, &y2, &w2, &h2);
  
  // Calculate the position for text1
  int16_t text1X = (SCREEN_WIDTH - w1) / 2;
  int16_t text1Y = (SCREEN_HEIGHT - (h1 + h2)) / 2;
  
  // Calculate the position for text2
  int16_t text2X = (SCREEN_WIDTH - w2) / 2;
  int16_t text2Y = text1Y + h1; // Position text2 below text1
  
  // Set the cursor position and print text1
  display.setCursor(text1X, text1Y);
  display.println(text1);
  
  // Set the cursor position and print text2
  display.setCursor(text2X, text2Y);
  display.println(text2);
  
  display.display();

}

BLYNK_WRITE(V3) // this command is listening when something is written to V1
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable

  if (pinValue == 1){
   digitalWrite(motor, LOW); 
  } else if (pinValue == 0) {
   digitalWrite(motor, HIGH);
  }

}

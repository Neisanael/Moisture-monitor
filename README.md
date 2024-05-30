# Automatic Soil Moisture Monitoring and Irrigation System

This repository contains a program for an automatic soil moisture monitoring and irrigation system implemented using an ESP8266 microcontroller and the Blynk platform for remote control. The system measures soil moisture levels and controls an irrigation motor based on the moisture readings.

## Features
- Automatic monitoring of soil moisture levels.
- Integration with Blynk for remote monitoring and control.
- Real-time display of moisture levels on an OLED display.
- Automatic control of the irrigation motor based on moisture readings.

## Hardware Requirements
- ESP8266 microcontroller board (e.g., NodeMCU)
- Soil moisture sensor
- OLED display (SSD1306)
- Irrigation motor
- Breadboard and jumper wires
- Suitable power supply

## Dependencies

Ensure you have the following libraries installed in your Arduino IDE:

1. **SPI**
   - Library for SPI communication.
   - Installation:
     ```arduino
     #include <SPI.h>
     ```

2. **Wire**
   - Library for I2C communication.
   - Installation:
     ```arduino
     #include <Wire.h>
     ```

3. **Adafruit SSD1306**
   - Library for controlling SSD1306 OLED displays.
   - Installation:
     ```arduino
     #include <Adafruit_SSD1306.h>
     ```

4. **Adafruit GFX**
   - Graphics library for the SSD1306 OLED display.
   - Installation:
     ```arduino
     #include <Adafruit_GFX.h>
     ```

5. **ESP8266WiFi**
   - Library for ESP8266 WiFi connectivity.
   - Installation:
     ```arduino
     #include <ESP8266WiFi.h>
     ```

6. **BlynkSimpleEsp8266**
   - Library for Blynk platform integration.
   - Installation:
     ```arduino
     #include <BlynkSimpleEsp8266.h>
     ```

## Schematic

![Schematic](https://github.com/Neisanael/Moisture-monitor/blob/main/Schematic.png?raw=true)

> **Warning:**
> The schematic provided may vary depending on the specific components you are using. Not all components use the same pins. Please refer to the datasheets of your components before making connections to avoid any damage.


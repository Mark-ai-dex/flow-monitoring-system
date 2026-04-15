# mark kiamba– System Control & OLED Display

##  Overview

This branch contains the implementation of the main system control logic and OLED display interface. It is responsible for handling user inputs, controlling system states, and displaying system information in real time.

---

##  Features Implemented

* Start/Stop system using push buttons
* Long press detection for system reset
* Control of pump via relay
* LED status indication
* OLED display output using I2C communication
* Serial monitoring for debugging

---

##  Hardware Components

* OLED Display (SSD1306 – 128x64)
* Push Buttons (Start & Stop)
* Relay Module (Pump control)
* LED Indicator
* Potentiometer (Analog input)
* ESP32 Microcontroller

---

##  Pin Configuration

| Component     | Pin |
| ------------- | --- |
| Start Button  | 14  |
| Stop Button   | 25  |
| Pump Relay    | 33  |
| LED Indicator | 26  |
| Potentiometer | 34  |
| OLED SDA      | 21  |
| OLED SCL      | 22  |

---

##  System Logic

* Press **Start Button** → System turns ON
* Press **Stop Button (short press)** → System turns OFF
* Hold **Stop Button (>2 seconds)** → System RESET
* When system is OFF:

  * Pump is OFF
  * LED is OFF
* When system is ON:

  * Pump and LED operate normally
  * OLED updates continuously

---

## OLED Display

* Displays system status messages
* Initialized at startup with "SYSTEM BOOT"
* Updates dynamically during operation

---

##  Files Included

* `diagram.json` → Circuit diagram for the system
* Main Arduino code (this implementation)

---

##  Contribution

* Implemented system control logic
* Designed button handling (short press & long press)
* Integrated OLED display
* Configured hardware connections

---

##  Notes

* Uses `Adafruit_GFX` and `Adafruit_SSD1306` libraries
* Ensure correct I2C address (0x3C) for OLED
* ESP32 I2C pins set to SDA = 21, SCL = 22

---

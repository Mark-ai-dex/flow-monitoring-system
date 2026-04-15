#  Smart Flow Control & Cost Monitoring System

##  Overview

This project implements a smart fluid control system using an ESP32 microcontroller. The system monitors and controls fluid flow, calculates the total volume dispensed, and computes cost in real time.

It features user interaction through push buttons, live feedback via an OLED display, and simulates flow using a potentiometer.

---

##  Objectives

* Control a pump system electronically
* Monitor flow rate and total volume
* Calculate cost based on usage
* Display real-time system data
* Implement teamwork using Git and GitHub

---

##  System Features

* Start/Stop control using buttons
* Long press reset functionality
* Real-time flow rate (mL/min)
* Volume tracking (mL)
* Cost calculation (KSh)
* Automatic stop at 5 Litres
* OLED display for monitoring
* LED status indicator
* Relay-controlled pump

---

##  System Operation

###  Start

* Press **Start Button**
* Pump and LED turn ON
* System begins calculating flow, volume, and cost

###  Stop

* Short press **Stop Button**
* System stops immediately

###  Reset

* Hold **Stop Button (>2 seconds)**
* Volume and cost reset to zero

###  Auto Stop

* System automatically stops at **5000 mL (5 Litres)**

---

##  Calculations

### Flow Rate

* Controlled using potentiometer
* Range: **0 – 1000 mL/min**

### Volume

```id="calc01"
volume += flowRate × 0.001
```

### Cost

```id="calc02"
COST_PER_ML = 12 / 80 = 0.15 KSh
cost = volume × COST_PER_ML
```

---

##  Display (OLED)

The OLED displays:

* System state (RUNNING / STOPPED)
* Flow rate (mL/min)
* Volume dispensed (mL)
* Total cost (KSh)
* Maximum volume limit

Startup message:

```id="boot01"
SYSTEM BOOT
```

---

##  Hardware Components

* ESP32 Microcontroller
* OLED Display (SSD1306, I2C)
* Relay Module (Pump control)
* Push Buttons (Start & Stop)
* LED Indicator
* Potentiometer

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



##  Git Workflow

* Repository initialized using Git
* Each member worked on a separate branch:

  * mark kiamba`
  * `collins muoki`
* Changes tracked using commits
* Pull requests created before merging
* Main branch protected with review requirements

---

##  Libraries Used

* Wire.h
* Adafruit_GFX.h
* Adafruit_SSD1306.h
---
##  Team Contributions

### mark kiamba – System Control & Hardware Interface

* Developed the main program structure (`setup()` and `loop()`)
* Implemented button handling logic:

  * Start button functionality
  * Stop (short press)
  * Reset (long press detection using timing)
* Controlled hardware components:

  * Relay (pump control)
  * LED indicator
* Configured ESP32 GPIO pins and input modes
* Initialized and configured I2C communication for the OLED display
* Implemented system state management (`systemRunning`)
* Integrated serial communication for debugging and system feedback

---

###collins muoki– Flow Logic, Calculations & Display System

* Implemented core system operation logic in `runSystem()`
* Designed and implemented:

  * Flow rate calculation using potentiometer input
  * Volume accumulation logic
  * Cost calculation based on volume (KSh)
* Added system safety feature:

  * Automatic shutdown at maximum volume (5 Litres)
* Developed OLED display interface (`updateOLED()`):

  * Displays system state, flow rate, volume, and cost
* Structured real-time data updates for user monitoring
* Defined system constants and variables (flow rate, volume, cost, limits)

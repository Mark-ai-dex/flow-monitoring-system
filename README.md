
#  Feature: Processing, Calculations & Output

##  Contributor

**Collins Muoki**

---

##  Feature Description

This branch implements the core processing, calculation, and output functionalities of the flow monitoring system.

It is responsible for:

* Computing flow rate
* Tracking total volume dispensed
* Calculating cost
* Displaying real-time system data on the OLED

---

##  Functionalities Implemented

### 1. Flow Rate Calculation

* Reads analog input from the potentiometer
* Converts input into flow rate (mL/min) using mapping
* Simulates adjustable flow control

---

### 2. Volume Calculation

* Continuously accumulates volume using:

  * Flow rate
  * Time-step approximation
* Simulates real-time fluid dispensing

---

### 3. Cost Calculation

* Computes total cost based on:

  * Volume dispensed
  * Predefined cost per mL
* Ensures dynamic cost tracking

---

### 4. Automatic Stop Condition

* System automatically stops when:

  * Volume ≥ **5000 mL (5 Litres)**
* Enhances safety and prevents overflow

---

### 5. Output Control

* Activates:

  * Pump (via relay)
  * LED indicator
* Deactivates outputs when system stops

---

### 6. OLED Display

* Displays real-time system parameters:

  * System state (RUNNING / STOPPED)
  * Flow rate (mL/min)
  * Volume (mL)
  * Cost (KSh)
* Updates continuously during operation

---

##  Libraries Contribution (`libraries.txt`)

This branch includes the required libraries:

* Wire.h
* Adafruit_GFX.h
* Adafruit_SSD1306.h

---

##  How to Test

1. Power the system
2. Press **Start Button** (handled by mark)
3. Observe:

   * Pump turns ON
   * LED lights up
   * OLED displays real-time data
4. Allow the system to run:

   * Volume and cost increase progressively
5. At **5000 mL**:

   * System stops automatically

---

##  Integration

This feature works in conjunction with:

* **mark's branch** (system control and button handling)
* Combined to form a complete smart flow control system

---

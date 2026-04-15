Feature: Processing, Calculations & Output 
👤 Contributor

collins muoki

 Feature Description

This branch implements the core processing, calculations, and output system of the flow monitoring project.

It is responsible for computing flow values, tracking usage, calculating cost, and displaying results on the OLED screen.

 Functionalities Implemented
 1. Flow Rate Calculation
Reads analog input from potentiometer
Converts value to flow rate (mL/min) using mapping
 2. Volume Calculation
Continuously accumulates volume using:
flow rate
time step approximation
Simulates real-time fluid flow measurement
 3. Cost Calculation
Computes total cost based on:
volume used
predefined cost per mL
 4. Automatic Stop Condition
Stops system when:
volume ≥ 5000 mL (5 Litres)
Ensures safety and prevents overflow
 5. Output Control
Activates:
Pump (relay)
LED indicator
Deactivates outputs when system stops
 6. OLED Display
Displays real-time system data:
System state (RUNNING/STOPPED)
Flow rate (mL/min)
Volume (mL)
Cost (KSh)
Updates continuously during operation
 Libraries Contribution (libraries.txt)

This branch includes required libraries:

Wire.h
Adafruit_GFX.h
Adafruit_SSD1306.h
 How to Test
Power the system
Press Start Button (handled by Person 1)
Observe:
Pump turns ON
LED lights up
OLED displays real-time data
Allow system to run:
Volume and cost should increase
At 5000 mL:
System stops automatically

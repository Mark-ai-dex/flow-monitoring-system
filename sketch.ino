// ================= FLOW VARIABLES =================
float flowRate = 0;   // mL/min
float volume   = 0;   // mL
float cost     = 0;   // KSh

// ================= CONSTANTS =================
const float MAX_VOLUME = 5000.0;          // 5 Litres = 5000 mL
const float COST_PER_ML = 12.0 / 80.0;     // 0.15 KSh per mL

// ================= SYSTEM RUN LOGIC =================
void runSystem() {

  // TURN ON OUTPUT DEVICES
  digitalWrite(pumpRelay, HIGH);
  digitalWrite(led, HIGH);

  // ================= FLOW RATE CALCULATION =================
  int potValue = analogRead(potPin);
  flowRate = map(potValue, 0, 4095, 0, 1000); // mL/min

  // ================= VOLUME CALCULATION =================
  volume += flowRate * 0.001;

  // ================= COST CALCULATION =================
  cost = volume * COST_PER_ML;

  // ================= SAFETY LIMIT =================
  if (volume >= MAX_VOLUME) {
    systemRunning = false;

    digitalWrite(pumpRelay, LOW);
    digitalWrite(led, LOW);

    Serial.println("MAX 5L REACHED");
  }
}

// ================= OLED DISPLAY =================
void updateOLED() {

  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("FLOW SYSTEM");

  display.setCursor(0, 12);
  display.print("STATE: ");
  display.println(systemRunning ? "RUNNING" : "STOPPED");

  display.setCursor(0, 24);
  display.print("FLOW: ");
  display.print(flowRate);
  display.println(" mL/min");

  display.setCursor(0, 34);
  display.print("VOL: ");
  display.print(volume);
  display.println(" mL");

  display.setCursor(0, 44);
  display.print("COST: KSh ");
  display.println(cost);

  display.setCursor(0, 54);
  display.print("MAX: 5000 mL");

  display.display();
}

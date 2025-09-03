# 🌍 Energy-Efficient Streetlight Control System

## 📖 Overview
This project aims to **reduce electricity consumption**, which is estimated to represent **19% of the world's total energy usage**.  
The system activates streetlights **only when motion is detected** (person or car) and in **low-light conditions**, improving energy efficiency.

---

## ⚙️ Technologies Used
- 🔌 Arduino UNO R3  
- 💻 C Programming  
- 🐍 Python  
- 📱 MIT App Inventor (Android application)

---

## 🔩 Hardware Components

### 🔷 Arduino UNO R3 (ATmega328p)
An open-source microcontroller board capable of reading sensors and controlling actuators.

**Specifications:**
- Operating Voltage: 5V  
- Power Supply: 7–12V (external) or USB  
- I/O Pins: 14 (6 PWM)  
- ADC Pins: 8  
- Flash Memory: 32kB  
- Communication: TWI, SPI, UART  
- Frequency: 16 MHz  

![Arduino](https://github.com/DanielaPavlenco/Streetlight-Control-System/assets/101560755/7bd20b55-11d4-424f-b169-b5ba53a5bffe)

---

### 📡 HC-05 Bluetooth Module
Wireless communication between Arduino and mobile application.

**Specifications:**
- Voltage: 3.6V–6V  
- Current: 30mA  
- Range: up to 10m  
- Baudrate: 9600–460800 bps  

![Bluetooth](https://github.com/DanielaPavlenco/Streetlight-Control-System/assets/101560755/afce8653-8c11-4ac2-8f4e-ecc564d0755b)

---

### 👀 PIR Motion Sensor
Detects heat sources like humans or animals.

**Specifications:**
- Voltage: 3V–5V  
- Distance: 3–7m (adjustable)  
- Angle: <140°  

![PIR](https://github.com/DanielaPavlenco/Streetlight-Control-System/assets/101560755/6ebdd68f-8fb8-49e7-879f-c00ba1810034)

---

### 💡 Light Sensor
Detects brightness level to decide whether lights should turn on.

**Specifications:**
- Voltage: 3.3V–5V  
- Output: Digital (0/1)  

![Light Sensor](https://github.com/DanielaPavlenco/Streetlight-Control-System/assets/101560755/691c35f0-c17d-4a8c-aaa2-d2a221c9edcb)

---

### 🔦 LEDs
- Max Current: 20mA  
- Voltage by Color:  
  - Red: 1.63–2.03V  
  - Green: 1.9–4.0V  
  - Blue: 2.48–3.7V  
  - White: 3.2–3.6V  
  - and more...

![LED](https://github.com/DanielaPavlenco/Streetlight-Control-System/assets/101560755/cdfd5184-354c-4a86-8e35-1127b278f4d6)

---

### 🔌 Resistors
Used for current limitation and voltage division in the circuit.

![Resistor](https://github.com/DanielaPavlenco/Streetlight-Control-System/assets/101560755/2bb6523b-cc71-4fe6-b75b-79ecc2f2b10e)

---

### 🔳 Breadboard
- Dimensions: 16.5 × 5.4 × 0.85 cm  
- 830 connection points  

![Breadboard](https://github.com/DanielaPavlenco/Streetlight-Control-System/assets/101560755/f376e2ec-0648-45a1-80c0-256e0521a269)

---

## 📊 Block Diagram
The system workflow is shown below:

![Block Scheme](https://github.com/DanielaPavlenco/Streetlight-Control-System/assets/101560755/737f83e8-6fb0-448f-b234-134c22c21e9f)

---

## 📱 Software Description
The Android application was built using **MIT App Inventor**.  
It has **five buttons**, each transmitting a different command to Arduino via Bluetooth.

---

## 🚦 Functionalities
- `0` → Turn **OFF** LED  
- `1` → Turn **ON** LED  
- `2` → Control LED using **motion sensor**  
- `3` → Control LED using **light sensor**  
- `4` → Control LED using **both sensors**  

---

## 🧩 Blocks Implementation
MIT App Inventor blocks logic:

![Blocks](https://github.com/DanielaPavlenco/Streetlight-Control-System/assets/101560755/4fbcc570-69c8-46bc-bece-fc9dd041054b)

---

## 📲 Application Interface
The Android app interface allows users to connect to the Bluetooth module and control the streetlight system.

![App Interface](https://github.com/DanielaPavlenco/Streetlight-Control-System/assets/101560755/c2a7ed70-d021-42c8-8e9e-446224a8b948)

---

## 🔗 Setup & Usage
1. Install the generated **.apk file** on your Android device or scan the QR code via MIT AI2 Companion.  
2. Enable **Bluetooth** on your phone.  
3. Pair the phone with the HC-05 Bluetooth module.  
4. Open the app and connect to the module.  
5. Use the buttons to test different functionalities.

---

## ✅ Summary
This project demonstrates how **IoT + sensors** can be combined to reduce energy consumption.  
By activating streetlights **only when necessary**, the system can save significant electricity while maintaining safety.  

---

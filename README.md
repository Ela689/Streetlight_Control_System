# Energy-Efficient Streetlight Control System

## Overview

This project aims to reduce electricity consumption, estimated to represent 19% of the world's total energy consumption. The system will attempt to activate the bulbs only when a person or a car passes, detecting motion and in low light conditions.

## Technologies Used

- Arduino
- C
- Python

## Hardware Description

### Arduino UNO R3 Development Board with ATmega328p Microcontroller

Arduino UNO is an open-source processing platform with flexible and easy-to-use software and hardware. It consists of a compact platform built around a signal processor capable of sensing data from the environment through various sensors and performing actions on the environment through lights, motors, servos, and other mechanical devices. The board can be powered externally using an external power supply and can also be powered directly from a PC via a USB cable.

Specifications:
- Operating Voltage: 5V
- Power Jack Voltage: 7V - 12V
- I/O Pins: 14
- PWM Pins: 6 (out of 14 I/O)
- ADC Pins: 8
- Flash Memory: 32kB (8kB used by bootloader)
- Communication: TWI, SPI, and UART
- Operating Frequency: 16 MHz

   ![image](https://github.com/DanielaPavlenco/Streetlight-Control-System/assets/101560755/7bd20b55-11d4-424f-b169-b5ba53a5bffe)

### HC-05 Bluetooth Module

The HC-05 Bluetooth module is a high-performance module with low power consumption. It is small in size and can transmit data wirelessly up to 10m. It communicates via serial UART and can be configured using the EN pin.

Specifications:
- Operating Voltage: 3.6V - 6V
- Maximum Current Consumption: 30mA
- I/O Pins are 3.3V compatible
- Baudrate: 9600 - 460800 bps
- Transmission Distance: up to 10m

![image](https://github.com/DanielaPavlenco/Streetlight-Control-System/assets/101560755/afce8653-8c11-4ac2-8f4e-ecc564d0755b)

### PIR Motion Sensor Module

The PIR motion sensor detects the movement of a heat source, such as a person, animal, or flame. It has adjustable sensitivity and detection range.

Specifications:
- Operating Voltage: DC 3V-5V
- Detection Distance: 3 - 7m (adjustable)
- Detection Angle: < 140°
- Trigger Method: Non-repeatable trigger (L) / Repeatable trigger (H)

![image](https://github.com/DanielaPavlenco/Streetlight-Control-System/assets/101560755/6ebdd68f-8fb8-49e7-879f-c00ba1810034)

### Light Sensor Module

The light sensor module detects the presence of light and has adjustable sensitivity. It can be used to control relays for light switches.

Specifications:
- Operating Voltage: 3.3V - 5V
- Output: Digital switch display (0 and 1)
- Detection Distance: 3 - 7m (adjustable)

![image](https://github.com/DanielaPavlenco/Streetlight-Control-System/assets/101560755/691c35f0-c17d-4a8c-aaa2-d2a221c9edcb)

### LED

- **Maximum Current:** 20mA
- **Voltage for Different Colors:**
  - Red: 1.63 ~ 2.03V
  - Yellow: 2.10 ~ 2.18V
  - Orange: 2.03 ~ 2.10V
  - Blue: 2.48 ~ 3.7V
  - Green: 1.9 ~ 4.0V
  - Violet: 2.76 ~ 4.0V
  - UV: 3.1 ~ 4.4V
  - White: 3.2 ~ 3.6V

![image](https://github.com/DanielaPavlenco/Streetlight-Control-System/assets/101560755/cdfd5184-354c-4a86-8e35-1127b278f4d6)

### Resistor

- **Function:** Electrical resistance
- **Material:** Metal or metal alloy (wires or bands), carbon film, metal-oxide film, liquid
- **Operating Voltage:** Dependent on the circuit
- **Power Consumption:** Depends on the resistance value and current passing through it

![image](https://github.com/DanielaPavlenco/Streetlight-Control-System/assets/101560755/2bb6523b-cc71-4fe6-b75b-79ecc2f2b10e)

### Breadboard

- **Dimensions:** 16.5 x 5.4 x 0.85cm
- **Number of Points:** 830
- **Required Wire Diameter:** 0.8mm

![image](https://github.com/DanielaPavlenco/Streetlight-Control-System/assets/101560755/f376e2ec-0648-45a1-80c0-256e0521a269)

### Block Scheme 
![image](https://github.com/DanielaPavlenco/Streetlight-Control-System/assets/101560755/737f83e8-6fb0-448f-b234-134c22c21e9f)


### Software Description
This application was developed using the MIT App Inventor online editor for Android. It consists of five buttons that transmit the corresponding codes for the system's functionalities.

## Functionalities

The application offers the following functionalities:

- For value "0": Turn off the LED.
- For value "1": Turn on the LED.
- For value "2": Toggle based on motion sensor.
- For value "3": Toggle based on light sensor.
- For value "4": Toggle based on both sensors.

## Blocks Implementation

The image below shows the code blocks that implement the application's functionality.
![image](https://github.com/DanielaPavlenco/Streetlight-Control-System/assets/101560755/4fbcc570-69c8-46bc-bece-fc9dd041054b)

### The interface of the application
![image](https://github.com/DanielaPavlenco/Streetlight-Control-System/assets/101560755/c2a7ed70-d021-42c8-8e9e-446224a8b948)

Through an Android application, we connect to the Bluetooth module. It transmits data to the Arduino board, which executes commands based on the values received through buttons. After creating the application, a .apk file is generated, which we install on the phone, or we scan the QR code using the MIT AI2 Companion app downloaded on the phone, and then install the application. The next step is pairing the phone with the Bluetooth module. Follow these steps:

1. Activate the Bluetooth function on the mobile phone.
2. Pair the two devices.
3. Start the application.
4. Connect the two devices.



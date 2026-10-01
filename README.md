# IoT Enabled Automatic Window Opening System

An IoT-based smart window automation system developed using ESP32,
DHT11 temperature sensor, MQ135 air-quality sensor, servo motor,
IR remote, and Blynk IoT platform.

## Project Overview

This project automates window opening based on environmental
conditions such as temperature and air quality.

The ESP32 continuously monitors the surrounding environment.
When the temperature or air-quality level exceeds the predefined
threshold, the servo motor automatically opens the window.

The system also supports remote monitoring and manual control
through the Blynk IoT platform and an IR remote.

## Features

- Automatic window opening based on temperature
- Air-quality monitoring
- ESP32-based control
- Blynk IoT remote monitoring
- Blynk manual control
- IR remote control
- Automatic and manual operating modes
- Servo-based window mechanism

## Hardware Used

- ESP32
- DHT11 Temperature Sensor
- MQ135 Air Quality Sensor
- Servo Motor
- IR Receiver
- IR Remote
- Power Supply

## Software & Technologies

- Arduino IDE
- Embedded C/C++
- ESP32
- Blynk IoT
- Wi-Fi
- Sensor interfacing
- Servo motor control

## Working Principle

1. The DHT11 sensor measures the surrounding temperature.
2. The MQ135 sensor measures the air-quality level.
3. The ESP32 processes the sensor readings.
4. If the temperature or air-quality value exceeds the
   predefined threshold, the servo motor opens the window.
5. When the environmental conditions return to normal,
   the window closes automatically.
6. The user can also control the window manually through
   Blynk or an IR remote.

## Blynk Controls

| Virtual Pin | Function |
|-------------|----------|
| V0 | Open Window |
| V1 | Close Window |
| V2 | Temperature |
| V3 | Auto / Manual Mode |
| V4 | Air Quality |

## Project Prototype

The project was implemented as a physical working prototype
using an ESP32, environmental sensors, servo motor and
IR remote control.

## Future Improvements

- Rain detection
- Humidity monitoring
- Window position feedback
- Limit switches
- Mobile notifications
- Automatic scheduling
- Improved air-quality calibration
- IoT data logging

## Author

**Tharun S**

Mechanical Engineering Student

### Areas of Interest

- Research & Development (R&D)
- Mechanical Design
- CAD
- Automotive Engineering
- Product Development
- Manufacturing

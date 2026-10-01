# IoT Enabled Automatic Window Opening System

![IoT Automatic Window Opening System](ce9075fd-1ba8-4087-8afd-7e5ab7931ed1.jpg)

An IoT-based smart window automation system developed using ESP32, DHT11 temperature sensor, MQ135 air-quality sensor, servo motor, IR remote, and Blynk IoT platform.

## 📌 Project Overview

The IoT Enabled Automatic Window Opening System is designed to automatically control a window based on environmental conditions.

The ESP32 continuously monitors temperature and air quality using the DHT11 and MQ135 sensors. When the temperature or air-quality level exceeds a predefined threshold, the servo motor automatically opens the window to improve ventilation.

The system also provides remote monitoring and manual control through the Blynk IoT platform and an IR remote.

## ✨ Features

- 🌡️ Temperature monitoring using DHT11
- 🌫️ Air-quality monitoring using MQ135
- 🪟 Automatic window opening based on environmental conditions
- ⚙️ Servo motor-based window control
- 📱 Remote monitoring through Blynk IoT
- 🎮 Manual control using IR remote
- 🔄 Automatic and manual operating modes
- 📡 ESP32-based IoT connectivity

## 🧰 Components Used

- ESP32 Development Board
- DHT11 Temperature and Humidity Sensor
- MQ135 Air Quality Sensor
- Servo Motor
- IR Receiver
- IR Remote
- Battery
- Connecting Wires
- Blynk IoT Platform

## 💻 Technologies Used

- C/C++
- Arduino IDE
- ESP32
- Blynk IoT
- IoT Sensors
- Embedded Systems
- Servo Motor Control

## ⚙️ Working Principle

1. The ESP32 initializes the sensors, servo motor, IR receiver, Wi-Fi, and Blynk connection.
2. The DHT11 sensor measures the surrounding temperature.
3. The MQ135 sensor monitors the air-quality level.
4. The ESP32 compares the sensor readings with predefined threshold values.
5. If the temperature or air-quality level exceeds the threshold, the servo motor opens the window.
6. If the environmental conditions return to the normal range, the system closes the window.
7. The Blynk IoT platform allows remote monitoring and manual control.
8. An IR remote can also be used for manual window control.

## 🔄 Operating Modes

### Automatic Mode

In automatic mode, the ESP32 controls the window according to temperature and air-quality readings.

```text
Temperature ≥ 30°C
        OR
Air Quality ≥ 600
        ↓
Window Opens

# IoT Enabled Automatic Window Opening System

An IoT-based smart window automation system developed using **ESP32, DHT11 temperature sensor, MQ135 air-quality sensor, servo motor, IR remote, and Blynk IoT platform**.

![Project Main View](./images/project-main.jpg)

---

## 📌 Project Overview

The **IoT Enabled Automatic Window Opening System** is designed to automatically control a window based on environmental conditions.

The ESP32 continuously monitors the surrounding temperature and air quality using the **DHT11** and **MQ135** sensors.

When the temperature or air-quality level exceeds a predefined threshold, the servo motor automatically opens the window to improve ventilation.

The system also provides **remote monitoring and manual control** through the **Blynk IoT platform** and an **IR remote**.

---

## ✨ Features

- 🌡️ Temperature monitoring using DHT11
- 🌫️ Air-quality monitoring using MQ135
- 🪟 Automatic window opening using a servo motor
- 📱 Remote monitoring using Blynk IoT
- 🎮 Manual control using IR remote
- 🔄 Automatic and manual operating modes
- 📊 Real-time sensor data monitoring
- ⚙️ ESP32-based control system

---

## 🛠️ Components Used

| Component | Purpose |
|---|---|
| ESP32 | Main microcontroller |
| DHT11 | Temperature measurement |
| MQ135 | Air-quality measurement |
| Servo Motor | Opens and closes the window |
| IR Receiver | Receives commands from IR remote |
| IR Remote | Manual window control |
| Blynk IoT | Remote monitoring and control |
| Wi-Fi | Internet connectivity |

---

## 🔌 Pin Configuration

| Component | ESP32 Pin |
|---|---|
| DHT11 | GPIO 4 |
| MQ135 | GPIO 34 |
| Servo Motor | GPIO 18 |
| IR Receiver | GPIO 15 |

---

## ⚙️ Working Principle

### 1. Environmental Monitoring

The ESP32 continuously reads:

- Temperature from the DHT11 sensor
- Air-quality value from the MQ135 sensor

### 2. Automatic Mode

In automatic mode, the system compares the sensor readings with predefined threshold values.

```text
Temperature >= 30°C
        OR
Air Quality >= 600
        ↓
Window Opens

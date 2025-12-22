# Technology Stack

## Core Technology
- **Hardware Platform:** ESP32 Development Board (e.g., ESP32-WROOM-32)
- **GSM Module:** SIM800L (connected via UART)
- **Programming Language:** C++
- **Framework:** Arduino Core for ESP32

## Libraries & Dependencies
- **GSM Management:** TinyGSM (Recommended for SIM800L compatibility and reliability)
- **Storage:** Preferences (Standard ESP32 library for persistent storage of whitelist/config)
- **JSON (Optional):** ArduinoJson (For potential config file parsing if SD/SPIFFS is used)

## Development Tools
- **IDE:** Visual Studio Code with PlatformIO (Recommended) or Arduino IDE
- **Serial Monitor:** Built-in IDE monitor or external tools (Putty/CoolTerm) for debugging AT commands

## Hardware Interface
- **UART:** Communication with SIM800L (RX/TX pins)
- **GPIO:** Relay control (Output), LED indicators (Output), Optional Button (Input)

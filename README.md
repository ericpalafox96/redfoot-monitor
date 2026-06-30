# 🐢 Rafa's Redfoot Monitor

An ESP32-based IoT habitat monitoring system designed for my Redfoot tortoise, **Rafa**.

The project monitors enclosure conditions in real time using multiple environmental sensors and presents the data on both a local OLED display and a Wi-Fi dashboard accessible from any device on the local network.

This project combines embedded systems, IoT, web development, and sensor integration into a practical smart habitat monitoring solution.

---

## Features

- 🌡 Ambient temperature monitoring
- 💧 Humidity monitoring
- ☀️ Basking spot temperature monitoring
- 🕒 Real-Time Clock (RTC)
- 📺 Local OLED display
- 🌐 Built-in Wi-Fi web dashboard
- 📱 Mobile-friendly interface
- 🔒 Secure Wi-Fi configuration using a local configuration file
- ⚡ ESP32-based architecture

---

## Current Dashboard

The web dashboard displays:

- Ambient Temperature
- Humidity
- Spot Temperature
- Current Time

The dashboard is hosted directly by the ESP32 and can be viewed from any device connected to the same Wi-Fi network.

Example:

```
🐢 Rafa's Redfoot Monitor

Air Temperature
80.0°F

Humidity
38%

Spot Temperature
79.2°F

6:15 PM
```

---

## OLED Display

The onboard OLED provides local monitoring without requiring Wi-Fi.

Displays:

- Ambient Temperature
- Humidity
- Spot Temperature
- Current Time

---

## Hardware

### Microcontroller

- ESP32 Dev Board

### Sensors

- BME280
  - Ambient Temperature
  - Humidity

- DS18B20 Waterproof Temperature Probe
  - Basking Spot Temperature

- DS3231 Real-Time Clock

### Display

- SSD1306 128x64 OLED Display

### Development Hardware

- Breadboard
- Jumper Wires
- USB-C Cable

---

## Repository Structure

```
redfoot_display/
│
├── redfoot_display.ino
├── config.example.h
├── .gitignore
├── README.md
│
└── tests/
    ├── esp32_test/
    ├── esp32_i2c_scanner/
    └── rtc_test/
```

---

## Wiring

### OLED Display

| OLED | ESP32 |
|------|-------|
| VCC | 3.3V |
| GND | GND |
| SDA | GPIO21 |
| SCL | GPIO22 |

---

### BME280

| BME280 | ESP32 |
|---------|--------|
| VCC | 3.3V |
| GND | GND |
| SDA | GPIO21 |
| SCL | GPIO22 |

---

### DS18B20

| DS18B20 | ESP32 |
|----------|--------|
| VCC | 3.3V |
| GND | GND |
| DATA | GPIO4 |

*Uses onboard 4.7kΩ pull-up resistor.*

---

### DS3231 RTC

| DS3231 | ESP32 |
|---------|--------|
| VCC | 3.3V |
| GND | GND |
| SDA | GPIO21 |
| SCL | GPIO22 |

---

## Software

### Arduino Libraries

- Adafruit SSD1306
- Adafruit GFX
- Adafruit BME280
- OneWire
- DallasTemperature
- RTClib
- WiFi
- WebServer

---

## Security

Wi-Fi credentials are **not stored in GitHub**.

The repository includes:

```
config.example.h
```

Create your own:

```
config.h
```

using the template below.

```cpp
#ifndef CONFIG_H
#define CONFIG_H

const char* WIFI_SSID = "YOUR_WIFI_NAME";
const char* WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";

#endif
```

The `config.h` file is ignored by Git using `.gitignore`.

---

## Roadmap

### Version 1

- [x] Arduino Uno prototype
- [x] OLED display
- [x] BME280 integration
- [x] DS18B20 integration

---

### Version 2

- [x] ESP32 migration
- [x] Wi-Fi dashboard
- [x] Real-Time Clock integration

---

### Planned Features

- [ ] Live dashboard updates (AJAX)
- [ ] Historical temperature & humidity graphs
- [ ] ESP32-CAM live video feed
- [ ] Dual DS18B20 support
- [ ] Data logging (CSV / SQLite)
- [ ] Push notifications
- [ ] Sensor health monitoring
- [ ] Custom PCB
- [ ] 3D printed enclosure
- [ ] Mobile application
- [ ] Cloud synchronization

---

## Future Vision

The long-term goal is to create a complete smart reptile habitat monitoring system featuring:

- Live environmental monitoring
- Historical analytics
- Camera streaming
- Mobile dashboard
- Remote notifications
- Automated habitat control
- Expandable sensor support

---

## Project Goals

This project was built to:

- Learn embedded systems
- Learn ESP32 development
- Explore IoT architecture
- Practice sensor integration
- Build practical engineering experience
- Create a useful monitoring system for my Redfoot tortoise

---

## Author

**Eric Palafox**

B.S. Computer Engineering  
California State University, Bakersfield

GitHub:
https://github.com/ericpalafox96

---

## License

This project is released under the MIT License.
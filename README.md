# 🌦️ ESP8266 Weather Forecast Display using OpenWeatherMap & OLED

This project uses an **ESP8266 NodeMCU** board to fetch real-time weather data from the **OpenWeatherMap API** and displays it on a **128x64 OLED screen (SSD1306)**. It shows temperature, humidity, and weather description in real-time.

[Temp: 32.5 C
Humidity: 78%
Weather: scattered clouds]   # this show on oled display of wheather data of your city

## 📸 Demo Preview

---

## 🛠 Hardware Required

| Component                | Quantity | Description                      |
|--------------------------|----------|----------------------------------|
| ESP8266 NodeMCU          | 1        | Microcontroller with WiFi       |
| SSD1306 OLED Display     | 1        | 128x64 resolution, I2C protocol |
| Jumper Wires             | Some     | For connection                  |
| Breadboard (optional)    | 1        | For prototyping                 |

---

## 🔌 Circuit Connections (I2C OLED)

| OLED Pin | ESP8266 Pin |
|----------|-------------|
| VCC      | 3.3V        |
| GND      | GND         |
| SDA      | D2 (GPIO4)  |
| SCL      | D1 (GPIO5)  |

---

## 📦 Libraries Used

Install these libraries via the Arduino Library Manager:

- [`ESP8266WiFi`](https://github.com/esp8266/Arduino)
- [`ESP8266HTTPClient`](https://github.com/esp8266/Arduino)
- [`ArduinoJson`](https://arduinojson.org/) *(for parsing JSON)*
- [`Adafruit_GFX`](https://github.com/adafruit/Adafruit-GFX-Library)
- [`Adafruit_SSD1306`](https://github.com/adafruit/Adafruit_SSD1306)

---

## 🌐 How to Get Your OpenWeatherMap API Key

1. Visit [OpenWeatherMap](https://openweathermap.org/api)
2. Create a free account
3. Generate an API key from the **API keys** section
4. Use the API key in the following URL format: (https://api.openweathermap.org/data/2.5/weather?q=YOUR_CITY&appid=YOUR_API_KEY&units=metric)

   
---

## 🧠 Code Overview

### Main Functionalities:
- Connects to a WiFi network
- Fetches weather data from OpenWeatherMap
- Parses temperature, humidity, and weather description
- Displays the information on the OLED

### Replace the following placeholders in the code:
```cpp
const char* ssid = "your_wifi_ssid";
const char* password = "your_wifi_password";
const char* url = "https://api.openweathermap.org/data/2.5/weather?q=YOUR_CITY&appid=YOUR_API_KEY&units=metric";




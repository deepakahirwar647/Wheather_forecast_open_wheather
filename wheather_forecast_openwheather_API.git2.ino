#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// WiFi Credentials
const char* ssid = "DK";  
const char* password = "your_wifi_password";  

// OpenWeatherMap API (Replace "ggggggg" with your actual API key)
const char* url = "your_open_wheather_url"
// OLED Display Settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


// Function to Connect WiFi
void setup_wifi() {
  Serial.print("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi!");
}

// Function to Fetch Weather Data
void fetch_weather() {
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;
    HTTPClient http;

    Serial.println("Requesting weather data from:");
    Serial.println(url);

    http.begin(client, url);
    int httpCode = http.GET();  // Send GET request

    Serial.print("HTTP Response Code: ");
    Serial.println(httpCode);

    // if (httpCode == HTTP_CODE_OK)
    if (httpCode > 0) {
      String payload = http.getString();
      Serial.println("Received data:");
      Serial.println(payload);

      // Parse JSON
      DynamicJsonDocument doc(1024);
      DeserializationError error = deserializeJson(doc, payload);

      if (error) {
        Serial.print("JSON Parsing Error: ");
        Serial.println(error.f_str());
      } else {
        float temperature = doc["main"]["temp"];
        int humidity = doc["main"]["humidity"];
        const char* weather = doc["weather"][0]["description"];

        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.println("°C");

        Serial.print("Humidity: ");
        Serial.print(humidity);
        Serial.println("%");

        Serial.print("Weather: ");
        Serial.println(weather);

        // Display Data on OLED
        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(0, 10);
        display.print("Temp: ");
        display.print(temperature);
        display.println(" C");

        display.print("Humidity: ");
        display.print(humidity);
        display.println("%");

        display.print("Weather: ");
        display.println(weather);

        display.display();
      }
    } else {
      Serial.println("Error fetching data. Check WiFi & API key.");
    }

    http.end();
  } else {
    Serial.println("WiFi Disconnected!");
  }
}

void setup() {
  Serial.begin(115200);
  setup_wifi();

  // OLED Display Initialization
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  
    Serial.println("SSD1306 allocation failed");
    for (;;);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("ESP8266 Weather");
  display.display();
}

void loop() {
  fetch_weather();
  delay(20000);  // Wait 5 minutes before next API call
}

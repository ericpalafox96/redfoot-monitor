#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_BME280.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "RTClib.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define SDA_PIN 21
#define SCL_PIN 22
#define ONE_WIRE_BUS 4

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
Adafruit_BME280 bme;
RTC_DS3231 rtc;

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature ds18b20(&oneWire);

void setup() {
  Serial.begin(115200);
  Wire.begin(SDA_PIN, SCL_PIN);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED failed");
    while (1);
  }

  if (!bme.begin(0x76)) {
    Serial.println("BME280 failed");
    while (1);
  }

  if (!rtc.begin()) {
    Serial.println("RTC failed");
    while (1);
  }

  ds18b20.begin();

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(18, 22);
  display.println("Rafa's Redfoot");
  display.setCursor(35, 36);
  display.println("Monitor");
  display.display();

  delay(2000);
}

void loop() {
  float airC = bme.readTemperature();
  float airF = airC * 9.0 / 5.0 + 32.0;
  float humidity = bme.readHumidity();

  ds18b20.requestTemperatures();
  float spotF = ds18b20.getTempFByIndex(0);

  DateTime now = rtc.now();

  int hour12 = now.hour() % 12;
  if (hour12 == 0) hour12 = 12;
  const char* ampm = now.hour() >= 12 ? "PM" : "AM";

  Serial.print("Air: ");
  Serial.print(airF, 1);
  Serial.print(" F | Hum: ");
  Serial.print(humidity, 1);
  Serial.print(" % | Spot: ");
  Serial.print(spotF, 1);
  Serial.print(" F | Time: ");
  Serial.print(hour12);
  Serial.print(":");
  if (now.minute() < 10) Serial.print("0");
  Serial.print(now.minute());
  Serial.print(" ");
  Serial.println(ampm);

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  display.setTextSize(2);
  display.setCursor(0, 0);
  display.print(airF, 1);
  display.print("F");

  display.setTextSize(1);
  display.setCursor(0, 25);
  display.print("Hum: ");
  display.print(humidity, 0);
  display.print("%");

  display.setCursor(0, 39);
  display.print("Spot: ");
  if (spotF < -100) {
    display.print("ERR");
  } else {
    display.print(spotF, 1);
    display.print("F");
  }

  display.drawLine(0, 52, 127, 52, SSD1306_WHITE);

  display.setCursor(0, 56);
  display.print("Rafa ");

  display.setCursor(72, 56);
  display.print(hour12);
  display.print(":");
  if (now.minute() < 10) display.print("0");
  display.print(now.minute());
  display.print(ampm);

  display.display();

  delay(2000);
}

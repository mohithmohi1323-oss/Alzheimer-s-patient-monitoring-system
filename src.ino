#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include "AdafruitIO_WiFi.h"
#include <TinyGPS++.h>
#include <HardwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <time.h>
#include <DHT.h>

// WiFi & Adafruit IO Credentials
#define WIFI_SSID "lol"
#define WIFI_PASS "password"
#define AIO_USERNAME "random_20"
#define AIO_KEY "aio_bqjs81Agr9EW8CqMvwS07nXAwfkQ"

// Initialize Adafruit IO
AdafruitIO_WiFi io(AIO_USERNAME, AIO_KEY, WIFI_SSID, WIFI_PASS);
AdafruitIO_Feed *latitudeFeed = io.feed("gps-latitude");
AdafruitIO_Feed *longitudeFeed = io.feed("gps-longitude");
AdafruitIO_Feed *reminderFeed = io.feed("reminder");
AdafruitIO_Feed *vibrationFeed = io.feed("vibration-status");
AdafruitIO_Feed *motionFeed = io.feed("motion-status");
AdafruitIO_Feed *temperatureFeed = io.feed("temperature");
AdafruitIO_Feed *soilMoistureFeed = io.feed("soil-moisture");

// Telegram
const char* botToken = "7756651890:AAG4Q03QsQg8LBpG9GL8hOzNEwDRp-2Rf0I";
const char* chatID = "1364359207";
WiFiClientSecure secured_client;
UniversalTelegramBot bot(botToken, secured_client);

// GPS
static const int RXPin = 16, TXPin = 17;
static const uint32_t GPSBaud = 4800;
TinyGPSPlus gps;
HardwareSerial ss(1);

// LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Sensors and Pins
#define BUZZER_PIN 25
#define VIBRATION_PIN 32
#define PIR_PIN 26
#define DHTPIN 33
#define DHTTYPE DHT11
#define SOIL_PIN 34
#define SOIL_THRESHOLD 2000
#define EMERGENCY_BUTTON_PIN 18

DHT dht(DHTPIN, DHTTYPE);
bool lastVibrationState = HIGH;
bool lastMotionState = LOW;
String lastSoilStatus = "";

// Default Reminders
struct Reminder {
  int hour;
  int minute;
  const char* message;
};

Reminder reminders[] = {
  {14,  03,"Take morning meds"},
  {12, 30, "Drink water"},
  {14, 0, "Afternoon walk"},
  {18, 0, "Evening meds"},
  {21, 0, "Bedtime reminder"}
};

// Time
struct tm timeinfo;
const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 19800;
const int   daylightOffset_sec = 0;

void checkDefaultReminder() {
  if (!getLocalTime(&timeinfo)) {
    Serial.println("Failed to obtain time");
    return;
  }
  int currentHour = timeinfo.tm_hour;
  int currentMinute = timeinfo.tm_min;
  for (Reminder r : reminders) {
    if (currentHour == r.hour && currentMinute == r.minute) {
      showReminder(r.message);
      break;
    }
  }
}

void scrollText(const char* text) {
  int len = strlen(text);
  if (len <= 16) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(text);
    return;
  }
  for (int i = 0; i < len - 15; i++) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(text + i);
    delay(400);
  }
}

void showReminder(const char* message) {
  Serial.print("Displaying Reminder: ");
  Serial.println(message);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Reminder:");
  scrollText(message);
  for (int i = 0; i < 5; i++) {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(1000);
    digitalWrite(BUZZER_PIN, LOW);
    delay(500);
  }
}

void reminderCallback(AdafruitIO_Data *data) {
  Serial.print("New Reminder: ");
  Serial.println(data->toChar());
  showReminder(data->toChar());
}

void setup() {
  Serial.begin(115200);
  ss.begin(GPSBaud, SERIAL_8N1, RXPin, TXPin);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Alzheimer's Sys");
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);
  pinMode(VIBRATION_PIN, INPUT);
  pinMode(PIR_PIN, INPUT);
  pinMode(SOIL_PIN, INPUT);
  pinMode(EMERGENCY_BUTTON_PIN, INPUT_PULLUP);
  dht.begin();

  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Connected!");

  secured_client.setInsecure();

  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  Serial.println("Time Synced");

  Serial.print("Connecting to Adafruit IO...");
  io.connect();
  reminderFeed->onMessage(reminderCallback);
  while (io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("Connected to Adafruit IO!");
  reminderFeed->get();
}

void loop() {
  io.run();

  // GPS
  while (ss.available() > 0) {
    gps.encode(ss.read());
    if (gps.location.isUpdated()) {
      float latitude = gps.location.lat();
      float longitude = gps.location.lng();
      Serial.print("Sending GPS Data - Lat: ");
      Serial.print(latitude, 6);
      Serial.print(" Lon: ");
      Serial.println(longitude, 6);
      latitudeFeed->save(latitude);
      longitudeFeed->save(longitude);
    }
  }

  // Vibration
  int currentVibrationState = digitalRead(VIBRATION_PIN);
  if (currentVibrationState != lastVibrationState) {
    if (currentVibrationState == LOW) {
      Serial.println("Idle");
      vibrationFeed->save("Idle");
    } else {
      Serial.println("Fall Detected");
      vibrationFeed->save("Fall Detected");
    }
    delay(25000);
    lastVibrationState = currentVibrationState;
  }

  // PIR
  int currentMotionState = digitalRead(PIR_PIN);
  if (currentMotionState != lastMotionState) {
    if (currentMotionState == HIGH) {
      Serial.println("Motion Detected!");
      motionFeed->save("Motion Detected");
    } else {
      Serial.println("Motion Stopped.");
      motionFeed->save("Motion Stopped");
    }
    lastMotionState = currentMotionState;
  }

  // Temperature
  static unsigned long lastTempCheck = 0;
  if (millis() - lastTempCheck > 60000) {
    float temperature = dht.readTemperature();
    if (!isnan(temperature)) {
      Serial.print("Temperature: ");
      Serial.println(temperature);
      temperatureFeed->save(temperature);
    } else {
      Serial.println("Failed to read from DHT sensor!");
    }
    lastTempCheck = millis();
  }

  // Soil Moisture
  int soilValue = analogRead(SOIL_PIN);
  String currentSoilStatus = (soilValue < SOIL_THRESHOLD) ? "NO Wet Detected" : " Wet Detected";
  if (currentSoilStatus != lastSoilStatus) {
    lastSoilStatus = currentSoilStatus;
    Serial.println(currentSoilStatus);
    soilMoistureFeed->save(currentSoilStatus);
  }

  // Reminder check
  static unsigned long lastReminderCheck = 0;
  if (millis() - lastReminderCheck > 60000) {
    checkDefaultReminder();
    lastReminderCheck = millis();
  }

  // Emergency button check
  if (digitalRead(EMERGENCY_BUTTON_PIN) == LOW) {
    String message = "Hey, I'm in emergency! Locate me ASAP!";
    bot.sendMessage(chatID, message, "");
    Serial.println("Telegram message sent: " + message);
   
    delay(1000);
  }

  delay(100);
}
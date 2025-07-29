# Alzheimer-s-patient-monitoring-system
Designed an IoT-based system to monitor Alzheimer's patients in real time, enabling location tracking, emergency alerts, &amp; hygiene monitoring. Aimed at improving patient safety &amp; reducing caregiver dependency. Future scope includes integrating Ai for behavior prediction &amp; mobile app support for enhanced remote care.

# 🧠 Alzheimer’s Patient Monitoring System

An IoT-powered smart healthcare solution designed to monitor Alzheimer's patients in real-time, detect falls, track location, and alert caregivers instantly. Developed using ESP32, multiple sensors, and integrated with Adafruit IO for cloud-based monitoring.

---

## 🧩 Project Structure

This system integrates various sensors with ESP32 to monitor:

- **Fall Detection** (Vibration Sensor)
- **Motion Activity** (PIR Sensor)
- **Moisture Detection** (Hygiene Monitoring)
- **Humidity Monitoring**
- **GPS Tracking**
- **Medication Reminders (LCD)**
- **Remote Alerts via Adafruit IO**

---

## 📌 Highlights

- 📍 **GPS-based tracking** to prevent patient wandering
- ⚠️ **Emergency alerts** sent to caregivers in real-time
- 🧼 **Moisture detection** for hygiene maintenance
- 🌡️ **Humidity monitoring** for environmental safety
- 📊 **Live data dashboards** using Adafruit IO
- 💡 **User-friendly LCD display** for local feedback

---

## 🛠️ Hardware Used

| Component            | Description                          |
|---------------------|--------------------------------------|
| ESP32               | Wi-Fi enabled microcontroller        |
| Vibration Sensor    | For fall detection                   |
| PIR Sensor          | Detects motion/activity              |
| Humidity Sensor     | Monitors room comfort level          |
| Moisture Sensor     | Detects wetness/incontinence         |
| GPS NEO-6M          | Tracks real-time location            |
| LCD Display         | Displays status and reminders        |
| Power Supply        | 5V regulated, with backup            |

---

## 🧑‍💻 Software Requirements

- Arduino IDE (ESP32 board support)
- Adafruit IO account (for cloud integration)
- Libraries:
  - `Adafruit_Sensor.h`
  - `DHT.h`
  - `Wire.h`
  - `WiFi.h`
  - `AdafruitIO_WiFi.h`
  - `TinyGPS++.h`

---

## 🧠 System Architecture

Patient 🧓
|
[Sensors]
↓
[ESP32 Microcontroller]
↓
[Adafruit IO + LCD]
↓
Caregiver 👨‍⚕️ receives alerts


---

## 🚀 Getting Started

1. **Install Arduino IDE**
2. **Add ESP32 board support**
3. **Install required libraries**
4. **Configure Wi-Fi & Adafruit IO keys in your code**
5. **Upload code to ESP32**
6. **Power the system and monitor data on Adafruit dashboard**

---

## 🖼️ Demonstration

> Videos of implementation, alerts on mobile, and LCD interface will be added here.

---

## 📊 Results

- ✅ Live alerts for fall/motion detected
- ✅ Reminders displayed on LCD
- ✅ Location updates streamed to Adafruit
- ✅ Emergency notifications sent via Internet

---

## 📚 Report & Documentation

Full project report is available in [`Final Report.pdf`](Final Report.pdf)

---

## 👥 Team Members

- Chandana N S – [4MN21EC007]
- Kaviya S – [4MN21EC015]
- Mohith M – [4MN21EC019]
- Manoj Kumar B S – [4MN22EC410]

**Guide:** Dr. M G Srinivasa, Associate Professor, ECE Dept., MIT Thandavapura

---

## 📄 License

This project is for academic research and educational purposes only.

---

## 📫 Contact

For queries or collaborations:  
**Mohith M** – mohithece@gmail.com  
Department of Electronics and Communication, MIT Thandavapura  


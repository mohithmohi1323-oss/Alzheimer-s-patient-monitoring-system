# Alzheimer-s-patient-monitoring-system
Designed an IoT-based system to monitor Alzheimer's patients in real time, enabling location tracking, emergency alerts, &amp; hygiene monitoring. Aimed at improving patient safety &amp; reducing caregiver dependency. Future scope includes integrating Ai for behavior prediction &amp; mobile app support for enhanced remote care.

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

![WhatsApp Image 2025-07-31 at 13 05 48_83c06095](https://github.com/user-attachments/assets/5e297487-debc-41dd-bb19-dea5ec66a7e5)
![WhatsApp Image 2025-07-31 at 13 12 39_e782ff04](https://github.com/user-attachments/assets/ceffcde1-16e4-45b2-b5d1-2c13963dbb97)
![WhatsApp Image 2025-07-31 at 13 05 49_a7585343](https://github.com/user-attachments/assets/e90ad9e7-352f-40e2-b699-cbd01ef72839)
![WhatsApp Image 2025-07-31 at 13 15 56_8a7b5d31](https://github.com/user-attachments/assets/aeddd3ba-eeb9-4272-af22-f4f68aa762f9)
---

## 📊 Results

- ✅ Live alerts for fall/motion detected
- ✅ Reminders displayed on LCD
- ✅ Location updates streamed to Adafruit
- ✅ Emergency notifications sent via Internet

https://drive.google.com/file/d/1EOTSm291mxv99GDFzT4qVXnImVzdJrAX/view?usp=drivesdk

https://drive.google.com/file/d/1EEgFGQBAil2jqxGg0W1yR23Uye4moyfx/view?usp=drivesdk

https://drive.google.com/file/d/1EOpY2xRHAP57YbSb9wyH2mvhu6WVU5rA/view?usp=drivesdk

https://drive.google.com/file/d/1FF1gsGtS4Bi-5xzbLPdyNwrL670sHhZN/view?usp=drivesdk


---

## 📚 Report & Documentation

Full project report is available in [`Final Report.pdf`](Final Report.pdf)

---

## 📄 License

This project is for academic research and educational purposes only.

---



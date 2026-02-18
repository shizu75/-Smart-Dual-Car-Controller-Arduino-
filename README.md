# 🚗 Smart Dual Car Controller (Arduino)

A **multi-mode Arduino robotic car** that supports:

- 📱 **Bluetooth manual control** (Android app: *BT Car Controller*)
- 🛣️ **Line following mode**
- 🔊 **Horn control**

The car automatically switches between autonomous modes and manual Bluetooth control based on sensor inputs.

---

## 📱 Android App

**App Name:** BT Car Controller  
**Platform:** Android (Google Play Store)

The app sends single-character commands via Bluetooth to control movement and horn.

---

## 🧠 Features

- Bluetooth-controlled driving
- Automatic line following
- Horn ON/OFF control
- PWM speed control
- Mode switching using sensors

---

## 🛠️ Hardware Required

- Arduino Uno / Nano  
- HC-05 Bluetooth Module  
- L293D / L298 Motor Driver  
- 2 × DC Motors + Chassis  
- IR Line Sensors (Left & Right)  
- Buzzer (Horn)  
- External battery supply  
- Jumper wires  

---

## 🔌 Pin Configuration

### Motor Driver
| Arduino Pin | Function |
|-----------|---------|
| 5 | ENA (Motor A Enable) |
| 6 | IN1 |
| 7 | IN2 |
| 9 | IN3 |
| 10 | IN4 |
| 8 | ENB (Motor B Enable) |

### Bluetooth (HC-05)
| Arduino Pin | HC-05 |
|-----------|-------|
| 3 | TX |
| 2 | RX |

### Sensors & Horn
| Arduino Pin | Component |
|-----------|----------|
| 12 | Right Line Sensor |
| 13 | Left Line Sensor |
| A4 | Line Following Mode Sensor |
| 4 | Horn (Buzzer) |

---

## 📡 Bluetooth Details

- **Module:** HC-05  
- **Baud Rate:** 9600  
- **Communication:** SoftwareSerial  
- **Default PIN:** `1234` or `0000`

---

## 🎮 Bluetooth Control Commands

| Command | Action |
|-------|-------|
| `F` | Move Forward |
| `B` | Move Backward |
| `L` | Turn Left |
| `R` | Turn Right |
| `S` | Stop |
| `Y` | Horn ON |
| `X` | Horn OFF |

Commands are case-insensitive. Newline characters are ignored.

---

## ⚙️ Working Logic

### Mode Selection
- **Line Sensor HIGH** → Line Following Mode
- **Otherwise** → Bluetooth Manual Control

### Line Following Behavior
- Both sensors detect line → Move forward
- Left detects line → Turn left
- Right detects line → Turn right
- No line detected → Stop

---

## ▶️ How to Use

1. Upload the code to Arduino
2. Power motors using external battery
3. Pair phone with HC-05
4. Open **BT Car Controller** app
5. Connect to Bluetooth module
6. Control manually or place car on line track

---

## 📂 File Structure

Smart-Bluetooth-Car/
│
├── smart_car.ino
└── README.md


---

## 🚀 Future Improvements

- Speed control from app
- ESP32 + WiFi camera
- Mobile app with mode selection

---

## 👤 Author

**Soban Saeed**  
Arduino • Embedded Systems • Robotics

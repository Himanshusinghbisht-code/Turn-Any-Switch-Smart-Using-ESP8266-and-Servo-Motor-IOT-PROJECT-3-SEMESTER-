# Turn Any Switch Smart Using ESP8266 + Servo Motor

This project demonstrates how to convert a normal electrical switch into a smart switch using *ESP8266 NodeMCU, **Blynk IoT, and a **9g Servo Motor*.  
The system allows remote ON/OFF control using your smartphone while the servo physically presses the manual switch.

---

## 🚀 Features

- Control switch ON/OFF using Blynk App  
- No modification inside electrical wiring  
- Uses ESP8266 WiFi IoT  
- Servo motor physically toggles the switch  
- Beginner-friendly and low-cost  
- Can be expanded with scheduling, automation, or voice control

---

## 🧩 Components Used

| Component Name | Quantity |
|----------------|----------|
| ESP8266 NodeMCU | 1 |
| SG90 Servo Motor (9g) | 1 |
| Jumper Wires | As required |
| USB Cable / 5V Adapter | 1 |
| Double-sided tape / Mounting base | 1 |
| Smartphone with Blynk App | 1 |

---

## ⚡ Circuit Connections (With Wire Colors + VIN)

### ### 🔌 Servo Motor Wire Colors
| Servo Wire | Color | Use |
|------------|--------|------|
| Brown | GND | Ground |
| Red | +5V | Power |
| Orange/Yellow | Signal | Control signal |

---

## 🔧 *Final Wiring (Correct & Recommended)*

### 1️⃣ *Servo Brown → NodeMCU GND*  
- Brown = GND  
- Connect to NodeMCU *GND*  
- Makes the circuit common-ground (important)

### 2️⃣ *Servo Red → NodeMCU VIN (5V)*  
- Red = +5V  
- Connect to *VIN pin*  
- VIN gives proper *5V* only when NodeMCU is powered through USB  
- Never use the 3.3V pin — servo will not move properly

### 3️⃣ *Servo Orange/Yellow → NodeMCU D4 (GPIO 2)*  
- Orange/Yellow = Signal  
- Connect to *D4*  
- Matches the Arduino code: servoPin = D4;

---

### 🧠 *Why VIN is Used Instead of 3.3V?*

- NodeMCU ka 3.3V *weak* hota hai, servo ko power nahi de sakta  
- VIN pin se *5V output* milta hai (USB se chalane par)  
- Servo motor 5V par stable & powerful rotate hota hai  

*Isiliye VIN = Best Choice ✔*

---

## 📱 Blynk App Setup

1. Install *Blynk IoT App*  
2. Create a *new template*  
3. Add a *Button widget*  
4. Set Datastream to *V1*  
5. Mode = *Switch*  
6. Copy your:  
   - Template ID  
   - Device Name  
   - Auth Token  

Paste these into the code.

---

## 💻 Arduino Code

```cpp
#define BLYNK_TEMPLATE_ID "YourTemplateID"
#define BLYNK_DEVICE_NAME "SmartSwitch"
#define BLYNK_AUTH_TOKEN "YourAuthToken"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

char ssid[] = "YourWiFiName";
char pass[] = "YourWiFiPassword";

Servo myservo;
int servoPin = D4;

BLYNK_WRITE(V1)
{
  int value = param.asInt();
  if (value == 1) {
    myservo.write(90);
    delay(700);
    myservo.write(0);
    delay(700);
  }
}

void setup()
{
  Serial.begin(115200);
  myservo.attach(servoPin);
  myservo.write(0);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{
  Blynk.run();
}

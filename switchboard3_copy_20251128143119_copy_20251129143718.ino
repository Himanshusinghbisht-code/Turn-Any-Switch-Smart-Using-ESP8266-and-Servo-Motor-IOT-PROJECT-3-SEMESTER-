#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL36jdEszwL"
#define BLYNK_TEMPLATE_NAME "Smart board3"
#define BLYNK_AUTH_TOKEN "iF-2xuchbUhNLhedn8cxpqyUvqxm2c4r"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

Servo servo;

int onPos = 0;      // ON position  
int offPos = 180;    // OFF position  

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Airtel_neer_3811";
char pass[] = "air56914";

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  servo.attach(D4);              // Servo permanently attach rakho
}

void loop() {
  Blynk.run();
}

BLYNK_WRITE(V0) {
  int value = param.asInt();
  Serial.println(value);

  if(value == 1){
    servo.write(onPos);           // 0 degree
  }
  else{
    servo.write(offPos);          // 180 degree
  }

  delay(500);
}
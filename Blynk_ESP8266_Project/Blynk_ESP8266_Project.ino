#define BLYNK_TEMPLATE_ID "TMPL6nNHNa2KT"
#define BLYNK_TEMPLATE_NAME "Mini Project"
#define BLYNK_AUTH_TOKEN "SOzKnlGunGDxiteMQQK86Oh0pCnO5tfA"

#include <DFRobot_DHT11.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "Pixel_TS";
char pass[] = "19680513";

#define DHT11_PIN 4
#define LED_PIN   5

BlynkTimer timer;
DFRobot_DHT11 dht;

bool workingStatus = false;
float settingValue = 0.;

BLYNK_WRITE(V1) {
  settingValue = param.asFloat();
}

void sendValues() {
  dht.read(DHT11_PIN);
  float t = dht.temperature;
  Blynk.virtualWrite(V2, t);
  if (t > settingValue) {
    workingStatus = true;
  } else {
    workingStatus = false;
  }
  Blynk.virtualWrite(V0, workingStatus);
  digitalWrite(LED_PIN, workingStatus);
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(5000, sendValues);
}

void loop() {
  Blynk.run();
  timer.run();
}

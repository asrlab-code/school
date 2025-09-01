#define BLYNK_TEMPLATE_ID "TMPL6h6wOA5QC"
#define BLYNK_TEMPLATE_NAME "Remote LED"
#define BLYNK_AUTH_TOKEN "cyGtUTBmUvvCZarOHT3Vzxbf-YAKqCwD"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "Pixel_TS";
char pass[] = "19680513";

BLYNK_WRITE(V0) {
  digitalWrite(LED_BUILTIN, !param.asInt());
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();
}
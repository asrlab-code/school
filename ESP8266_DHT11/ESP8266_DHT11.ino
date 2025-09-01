#include <DFRobot_DHT11.h>

#define DHT11_PIN 4

DFRobot_DHT11 dht;

void setup() {
  Serial.begin(9600);
}

void loop() {
  dht.read(DHT11_PIN);
  float h = dht.humidity;
  float t = dht.temperature;
  float f = t * 1.8 + 32;
  Serial.print("Humidity (%): ");
  Serial.println(h, 2);
  Serial.print("Temperature (C): ");
  Serial.println(t, 2);
  Serial.print("Temperature (F): ");
  Serial.println(f, 2);
  Serial.println();
  delay(5000);
}
#define LED_PIN 3
#define DELAY_TIME 1000

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  for (int d = 0; d <= 100; d += 25) {
    int analogValue = d * 255 / 100;
    analogWrite(LED_PIN, analogValue);
    delay(DELAY_TIME);
  }
}
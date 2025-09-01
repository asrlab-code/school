#include <SimpleTimer.h>

#define LED1 13
#define LED2 12

SimpleTimer timer;

void blink1() {
  digitalWrite(LED1, !digitalRead(LED1));
}

void blink2() {
  digitalWrite(LED2, !digitalRead(LED2));
}

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  timer.setInterval(250, blink1);
  timer.setInterval(100, blink2);
}

void loop() {
  timer.run();
}

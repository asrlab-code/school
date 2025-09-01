#define SW1    2
#define LED1   13
#define BUZZER 5
#define BLINK_DELAY 1000

unsigned long previousMillis = 0;
volatile bool buttonPressed = false;

void setup() {
  pinMode(SW1, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(SW1), onButtonPress, FALLING);
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= BLINK_DELAY) {
    previousMillis = currentMillis;
    digitalWrite(LED1, !digitalRead(LED1));
  }
  if (buttonPressed) {
    buttonPressed = false;
    tone(BUZZER, 1000, 250);
  }
}

void onButtonPress() {
  buttonPressed = true;
}
